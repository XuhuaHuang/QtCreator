#ifndef TABDIALOG_H
#define TABDIALOG_H

#include <QWidget>

class TabDialog : public QWidget
{
    Q_OBJECT

public:
    TabDialog(QWidget *parent = nullptr);
    ~TabDialog();
};
#endif // TABDIALOG_H
