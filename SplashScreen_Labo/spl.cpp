#include <QtWidgets/QStyleOptionProgressBar>
#include "spl.h"

SplashScreen::SplashScreen(QWidget *parent) :
        QSplashScreen{parent,QPixmap{":/files/google.png"},
                      Qt::WindowTransparentForInput}, m_progress{0},m_progress2{0}
{
}
int SplashScreen::getProgress() const {
    return m_progress;
}
int SplashScreen::getProgress2() const {
    return m_progress2;
}
void SplashScreen::drawContents(QPainter *painter)
{
    QSplashScreen::drawContents(painter);

    // Progressbar Style ...
    QStyleOptionProgressBar pbstyle;
    pbstyle.initFrom(this);
    pbstyle.state = QStyle::State_Enabled;
    pbstyle.textVisible = false;
    pbstyle.minimum = 0;
    pbstyle.maximum = 100;
    pbstyle.progress = m_progress;
    pbstyle.invertedAppearance = false;
    pbstyle.text = QString("%1%").arg(m_progress);
    pbstyle.textVisible = true;
    QPoint point{350,510};
    pbstyle.rect = QRect(point,QSize{600,18});// Draw
    style()->drawControl(QStyle::CE_ProgressBar, &pbstyle, painter, this);

    QStyleOptionProgressBar pbstyle2;
    pbstyle2.initFrom(this);
    pbstyle2.state = QStyle::State_Enabled;
    pbstyle2.textVisible = false;
    pbstyle2.minimum = 0;
    pbstyle2.maximum = 100;
    pbstyle2.progress = m_progress2;
    pbstyle2.invertedAppearance = false;
    //pbstyle2.text = QString("%1%").arg(m_progress2);
    pbstyle2.text = (m_progress_control/*+" %1%"*/);//.arg(m_progress);
    pbstyle2.textVisible = true;
    QPoint point2{350,480};
    pbstyle2.rect = QRect(point2,QSize{600,18});
    style()->drawControl(QStyle::CE_ProgressBar, &pbstyle2, painter, this);
}

