#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QRegExpValidator>

class lineEdit : public QWidget
{
    Q_OBJECT

public:
    lineEdit(QWidget *parent = nullptr);
    ~lineEdit();

public slots:
    // slots / functions working with QValidator(s)
    void intdata(void);
    void dbledata(void);
    void regexpdata(void);

private:

    // layout manager
    QHBoxLayout *hbox1, *hbox2, *hbox3, *hbox4;
    QVBoxLayout *vbox;

    // label, tecxt fields, and push buttons
    QLabel *intlbl, *dblelbl, *regexplbl, *output;
    QLineEdit *intledt, *dbleledt, *regexpledt;
    QPushButton *intbtn, *dblbtn, *regexpbtn;

    // QValidators
    QIntValidator *intv;
    QDoubleValidator *dblv;
    QRegExpValidator *regexpv;
};
#endif // LINEEDIT_H
