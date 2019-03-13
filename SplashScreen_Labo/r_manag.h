#ifndef RM_H
#define RM_H

#include "subject.h"
#include <QtCore/QString>
#include <QtCore/QFile>

//Resource manager

class ResourceManager : public Subject {

public:
    ResourceManager(const QString &folderName = "/");

    virtual ~ResourceManager();

    virtual void subscribe(Observer*o)override;
    virtual void unsubscribe(Observer*o)override;
    virtual void notify()const override;

    int getLevel() const;
    int getLevel2() const;

    bool isDone() const;

    const QString & getMessage() const;


    void addResource(const QString &resourcename, const QString &filename);

    void LoadResource();
private:
    QList<Observer*>                    m_observers;
    QList<QPair<QString,QString>>       m_resources; // store resourcename and destination file
    QList<QString>                      m_table;
    QString                             m_folderName;
    int                                 m_level;
    int                                 m_level2;
    QString                             part_number;
    int                                 new_file_level;
    int                                 compt;
    QString                             m_message;
    bool                                m_done;

    // private setMessage and setLevel ...
    void setMessage(const QString &message);
    void setLevel(int level);
    void setLevel2(int level2);
    void forLevel_2(const QString &name);
    void setDone(bool done);
    void CopyResource(const QPair<QString, QString> &data);
};
#endif // RM_H
