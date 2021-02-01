#ifndef HELLOGUI_H
#define HELLOGUI_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

class helloGUI : public QWidget
{
    Q_OBJECT

public:

    // constructor includes a null pointer
    helloGUI(QWidget *parent = nullptr);

    // destructor
    ~helloGUI();

private:

    // label
    QLabel *label;

    // layout manager
    QVBoxLayout *vbox;

    void showHyperlink(QLabel *label);
};

#endif // HELLOGUI_H
