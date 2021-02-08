#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QMainWindow>
#include <QMessageBox>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

class pushButton : public QWidget
{
    Q_OBJECT

public:
    pushButton(QWidget *parent = nullptr);
    ~pushButton();

public slots:
    void buttonPressed(void);

private:
    QVBoxLayout *vbox; // vertical layout manager
    QLabel *label;

    // show or hide message button
    QPushButton *button;

    // quit button
    QPushButton *quitButton;

    int flag; // variable used to toggle the information
};
#endif // PUSHBUTTON_H
