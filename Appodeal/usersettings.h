#ifndef USERSETTINGS_H
#define USERSETTINGS_H

class QAndroidJniObject;

class UserSettings
{
public:
    UserSettings();
    enum class Gender {
        FEMALE, MALE, OTHER
    };

    virtual ~UserSettings();
    virtual void setAge (const int &age);
    virtual void setGender (const Gender &gender);
private:
    QAndroidJniObject* m_userSettings;

};

#endif // USERSETTINGS_H
