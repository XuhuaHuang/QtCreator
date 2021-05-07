#ifndef TABDIALOG_H
#define TABDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QTabWidget>
#include <QDialogButtonBox>
#include <QFileInfo>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QCheckBox>
#include <QListWidget>
#include <QDate>

class TabDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TabDialog(const QString& fileName, QWidget *parent = nullptr);
    ~TabDialog() {}

private:
    QTabWidget *tabWidget;
    QDialogButtonBox *buttonBox;
};

class GeneralTab : public QWidget
{
    Q_OBJECT

public:
    explicit GeneralTab(const QFileInfo &fileInfo, QWidget *parent = nullptr);
};

class PermissionsTab : public QWidget
{
    Q_OBJECT

public:
    explicit PermissionsTab(const QFileInfo &fileInfo, QWidget *parent = nullptr);
};

class ApplicationsTab : public QWidget
{
    Q_OBJECT

public:
    explicit ApplicationsTab(const QFileInfo &fileInfo, QWidget *parent = nullptr);
};

#endif // TABDIALOG_H
