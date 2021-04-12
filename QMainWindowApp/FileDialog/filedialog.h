/*****************************************************************//**
 * \file   filedialog.h
 * \brief  
 * 
 * \author Xuhua Huang
 * \date   April 2021
 *********************************************************************/

#ifndef FILEDIALOG_H
#define FILEDIALOG_H

#include <QWidget>

class FileDialog : public QWidget
{
    Q_OBJECT

public:
    FileDialog(QWidget *parent = nullptr);
    ~FileDialog();
};
#endif // FILEDIALOG_H
