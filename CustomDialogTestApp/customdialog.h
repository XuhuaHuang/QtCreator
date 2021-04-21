/*****************************************************************//**
 * \file   customdialog.h
 * \brief  header file on class named "CustomDialog"
 * 
 * \author Xuhua Huang
 * \date   April 2021
 *********************************************************************/

#ifndef CUSTOMDIALOG_H
#define CUSTOMDIALOG_H

#include <QDialog>
#include <QSpinBox>
#include <QSlider>
#include <QLabel>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QDebug>

class CustomDialog : public QDialog
{
    Q_OBJECT

public:
    CustomDialog(QWidget *parent = nullptr);
    ~CustomDialog();
    int getDialogValue(void);

public slots:
    void updateDialogValue(int);

signals:
    void dialogValueChanged(int);

private:
    QSpinBox *spinbox;
    QSlider *slider;
    QLabel *label;
    QDialogButtonBox *dialogbtns;
    QVBoxLayout *vbox;
};
#endif // CUSTOMDIALOG_H
