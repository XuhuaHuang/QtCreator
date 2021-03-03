#ifndef GROUPBOX_H
#define GROUPBOX_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QRadioButton>
#include <QCheckBox>
#include <QMessageBox>

class groupbox : public QWidget
{
    Q_OBJECT

public:
    groupbox(QWidget *parent = nullptr);
    ~groupbox();

public slots:
    void radioBtnStnChanged(bool);
    void chkBxStnChanged(bool);
    void groupBxChanged(bool);

private:
    bool comedy, action, horror;

    QGroupBox *groupBox1, *groupBox2;
    QVBoxLayout *vbox1, *vbox2;
    QGridLayout *grid;

    QRadioButton *radio1, *radio2, *radio3;
    QCheckBox *checkBox1, *checkBox2, *checkBox3;
};
#endif // GROUPBOX_H
