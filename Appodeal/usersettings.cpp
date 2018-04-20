#if (__ANDROID_API__ >= 9)

#include "QAndroidJniObject"
#include <QPA/QPlatformNativeInterface.h>
#include <QApplication>
#include "usersettings.h"

UserSettings::UserSettings()
    : m_userSettings(0)
{
    QPlatformNativeInterface* interface = QApplication::platformNativeInterface();
    jobject activity = (jobject)interface->nativeResourceForIntegration("QtActivity");
    if (activity)
    {
        m_userSettings = new QAndroidJniObject(activity);
    }

}

UserSettings::~UserSettings()
{
    if (m_userSettings)
    {
        delete m_userSettings;
    }
}

void UserSettings::setAge(const int &age)
{
    m_userSettings->callMethod<void>("setAge", "(I)V", age);
}

void UserSettings::setGender(const Gender &gender)
{
     m_userSettings->callMethod<void>("setGender", "(I)V",  gender);
}

#endif
