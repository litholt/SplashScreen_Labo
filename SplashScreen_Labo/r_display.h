#ifndef R_DISPLAY_H
#define R_DISPLAY_H

#include "spl.h"
#include "r_manag.h"

class ResourceDisplay : public Observer{
public:
    explicit ResourceDisplay(ResourceManager *m, QWidget *parent= nullptr);

    virtual ~ResourceDisplay();

    virtual void attach()override ;
    virtual void detach()override ;
    virtual void update()override ;

private:
    ResourceManager*    m_subject;
    SplashScreen        m_splash;
};

#endif // R_DISPLAY_H
