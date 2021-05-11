#ifndef USERINFO_H
#define USERINFO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QRegExpValidator>
#include <QComboBox>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

class UserInfo : public QWidget
{
    Q_OBJECT

public:
    UserInfo(QWidget *parent = nullptr);
    ~UserInfo();

public slots:
    void okbtnClicked();

private:
    void initElements();
    void setAppLayout();

    QLabel *firstNamelbl, *lastNamelbl, *stAddrlbl, *citylbl, *provlbl, *postlbl;
    QLineEdit *firstNameedt, *lastNameedt, *stAddredt, *cityedt, *postedt;

    QComboBox *provcbb;
    const QStringList provStrList = {
        "AB", "BC", "MB", "NB", "NL", "NS", "NT", "NU", "ON", "PE", "QC", "SK", "YT"
    };
    QRegExpValidator *postalcoderegexp;

    QTextEdit *readOnlyRst;
    QPushButton *okbtn, *quitbtn;

    QGridLayout *lblEdtLayout;
    QHBoxLayout *provPsthbox;
    QHBoxLayout *btnhbox;
    QVBoxLayout *mainLayout;
};
#endif // USERINFO_H
