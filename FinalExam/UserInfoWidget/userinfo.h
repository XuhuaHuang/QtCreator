/*****************************************************************//**
 * \file   userinfo.h
 * \brief  file contains class declaration related to 
 * a Information Widget App
 * 
 * \author Xuhua Huang
 * \date   May 2021
 *********************************************************************/

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
#include <QApplication>

class UserInfo : public QWidget
{
    Q_OBJECT

public:
    UserInfo(QWidget *parent = nullptr);
    ~UserInfo();

public slots:
    // public slot invoked when the 'OK' push button is clicked
    void okbtnClicked();

private:
    /* Provate Functions Called in Constructor */
    // initialize label, line edit field, and combo box
    void initElements();
    // add elements to layout
    void setAppLayout();

    /* Elements */
    // label
    QLabel *firstNamelbl, *lastNamelbl, *stAddrlbl, *citylbl, *provlbl, *postlbl;
    // inlin etext editting field
    QLineEdit *firstNameedt, *lastNameedt, *stAddredt, *cityedt, *postedt;

    /* Provide Combo Box to Contain a List of Provinces */
    QComboBox *provcbb;
    const QStringList provStrList = {
        "AB", "BC", "MB", "NB", "NL", "NS", "NT", "NU", "ON", "PE", "QC", "SK", "YT"
    };
    /* Regular Expression to handle Postal Code */
    QRegExpValidator *postalcoderegexp;

    /* Read Only Result and Push Buttons */
    QTextEdit *readOnlyRst;
    QPushButton *okbtn, *quitbtn;

    /* Layout Manager */
    QGridLayout *lblEdtLayout; // contains labels and inline text editing field
    QHBoxLayout *provPsthbox;  // contains province combo box and postal code edit
    QHBoxLayout *btnhbox;      // contains 'OK' and 'QUIT' button
    QVBoxLayout *mainLayout;   // contains all layout managers
};
#endif // USERINFO_H
