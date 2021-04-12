/*****************************************************************//**
 * \file   filedialog.h
 * \brief  Create a simple QWidget application to open, edit and save
 *  a .txt file with
 *  QFileDialog::getOpenFileName()
 *  and QFileDialog::getSaveFileName() methods
 * 
 * \author Xuhua Huang
 * \date   April 2021
 *********************************************************************/

#ifndef FILEDIALOG_H
#define FILEDIALOG_H

#include <QWidget>
#include <QFileDialog>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

class FileDialog : public QWidget
{
    Q_OBJECT

public:
    FileDialog(QWidget *parent = nullptr);
    ~FileDialog();
public slots:
    void openBtnClicked(void);
    void saveBtnClicked(void);
private:
    // button to open and save a file
    QPushButton *openFileBtn, *saveFileBtn;
    // plain text editing field
    QPlainTextEdit *plnTxtEdt;

    QVBoxLayout *vbox;
    QHBoxLayout *btnHbox;
};
#endif // FILEDIALOG_H
