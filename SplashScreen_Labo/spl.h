#ifndef SPL_H
#define SPL_H

#include <QtCore/QDir>
#include <QtWidgets/QSplashScreen>
#include <QtWidgets/QProgressBar>
#include <QApplication>

class SplashScreen : public QSplashScreen {
Q_OBJECT

public:
    explicit SplashScreen(QWidget *parent);

    int getProgress() const;
    int getProgress2() const;

private:
    int m_progress;
    int m_progress2;
    QString m_progress_control;

public slots:

    void setMessage(const QString &message){
        m_progress_control = message.toLower();
        this->clearMessage();
        this->showMessage(message,Qt::AlignBottom,Qt::black);
    }
    void setProgress(const int value) {
        m_progress = value;
        if (m_progress >= 100) {
            m_progress = 100;
        }
        if (m_progress < 0)
            m_progress = 0;
        repaint();
        QApplication::processEvents();
    }
    void setProgress2(const int value) {
        m_progress2 = value;
        if (m_progress2 >= 100) {
            m_progress2 = 100;
        }
        if (m_progress2 < 0)
            m_progress2 = 0;
        repaint();
        QApplication::processEvents();
    }

protected:
    void drawContents(QPainter *painter);
};
#endif // SPL_H
