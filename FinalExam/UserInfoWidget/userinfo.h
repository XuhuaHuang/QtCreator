#ifndef USERINFO_H
#define USERINFO_H

#include <QWidget>

class UserInfo : public QWidget
{
    Q_OBJECT

public:
    UserInfo(QWidget *parent = nullptr);
    ~UserInfo();
};
#endif // USERINFO_H
