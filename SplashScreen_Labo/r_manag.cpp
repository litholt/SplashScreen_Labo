#include <QtCore/QString>
#include <QtCore/QFile>
#include <QtCore/QDir>
#include <QList>
#include <QtCore/QThread>
#include "r_manag.h"
#include "spl.h"

#define DELAY QThread::sleep(1)
// little delay

ResourceManager::ResourceManager(const QString &folderName)
    : m_level{0},m_level2{0}, m_folderName{folderName},
          m_message{"Init..."}, m_done{false} {
}

ResourceManager::~ResourceManager() {
    m_observers.clear();
}

void ResourceManager::subscribe(Observer *o) {
    m_observers.push_back(o);
}

void ResourceManager::unsubscribe(Observer *o) {
    m_observers.removeOne(o);
}

void ResourceManager::notify() const {
    for (auto itr:m_observers) {
        itr->update();
    }
}

int ResourceManager::getLevel() const {
    return m_level;
}
int ResourceManager::getLevel2() const {
    return m_level2;
}

void ResourceManager::setLevel(int level) {
    ResourceManager::m_level = level;
    notify();
}
void ResourceManager::setLevel2(int level2) {
    ResourceManager::m_level2 = level2;
    notify();
}

const QString &ResourceManager::getMessage() const {
    return m_message;
}

void ResourceManager::setMessage(const QString &message) {
    ResourceManager::m_message = message;
    notify();
}

bool ResourceManager::isDone() const {
    return m_done;
}

void ResourceManager::setDone(bool done) {
    ResourceManager::m_done = done;
    notify();
}

void ResourceManager::addResource(const QString &resourcename, const QString &filename) {
    // make_pair(...)
    m_resources.push_back({resourcename, filename});
    m_table.push_back(filename);
}

void ResourceManager::forLevel_2(const QString &name){

    compt = 0;
    while ((!m_table.isEmpty() && m_table[compt] != name)) {
        compt++ ;
    }
    if(name == m_table[compt]){

        setLevel2(compt*100/m_table.size());// reset second progressbar...
        new_file_level = compt*100/m_table.size();

        QString s = QString::number(compt + 1);
        QString c = QString::number(m_table.size());

        part_number =" ( " + s + " su " + c + " ) ";
    }
}

void ResourceManager::CopyResource(const QPair<QString, QString> &data) {

    forLevel_2(data.second); //control level and part of the 2nd bar

    QString msg = "LOADING " + data.second + part_number;
    QString newName = m_folderName + '/' + data.second;
    setMessage(msg);

    setLevel(0); // reset the progressbar...

    QFile inputFile(data.first); // Load the Qt resource
    QFile outputFile(newName); // Store the new file
    int size = static_cast<int>(inputFile.size()); // size file
    if (inputFile.exists()) {
        inputFile.open(QIODevice::ReadOnly);
        outputFile.open(QIODevice::WriteOnly);
        for (int i = 0; i < size; i++) {

            outputFile.write(inputFile.read(i)); // write a byte
            outputFile.seek(i);  // move to next byte to read
            inputFile.seek(i); // move to next byte to write

            setLevel(static_cast<int>((float) i / size * 100)); // Calcul pctage
            setLevel2(new_file_level + static_cast<int>((float) i / size * 100/3)); // Calcul pctage
        }
        inputFile.close();
        outputFile.close();
    }

    setLevel(100);
    if((compt + 1) == m_table.size()){
        setLevel2(100);
    }
}

void ResourceManager::LoadResource() {
    //DELAY;
    //setMessage("Creating folder " + m_folderName + "...");
    // create a new folder in the executable directory
    DELAY;
    if (!QDir().mkdir(m_folderName)) {
        //setMessage("Folder " + m_folderName + " already exist!");
    } else {
        setMessage("Folder created!");
    }
    DELAY;

    for (auto itr: m_resources) {
        CopyResource(itr); // copy added resource in the chosen folder with the same filename
        DELAY;
    }

    setDone(true);
}
