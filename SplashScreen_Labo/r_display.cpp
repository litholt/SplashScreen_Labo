#include "r_display.h"

ResourceDisplay::ResourceDisplay(ResourceManager *m, QWidget *parent) : m_subject{m}, m_splash{parent} {
    m_splash.setAttribute(Qt::WA_QuitOnClose);
    attach();
}

void ResourceDisplay::attach() {
    m_subject->subscribe(this);
    m_splash.show();
    update();
}

void ResourceDisplay::detach() {
    m_subject->unsubscribe(this);

    QMetaObject::invokeMethod(&m_splash, "close", Qt::QueuedConnection);
}

void ResourceDisplay::update() { // Observer...
    if(m_splash.getProgress() != m_subject->getLevel()){
        m_splash.setProgress(m_subject->getLevel());
    }
    if(m_splash.getProgress2() != m_subject->getLevel2()){
        m_splash.setProgress2(m_subject->getLevel2());
    }
    if(m_splash.message() != m_subject->getMessage()){
        m_splash.setMessage(m_subject->getMessage());
    }
    if(m_subject->isDone()){
        detach();
    }
}

ResourceDisplay::~ResourceDisplay() {
    detach();
}
