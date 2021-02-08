#ifndef EVENTEXAMPLE_H
#define EVENTEXAMPLE_H

#include <QWidget>
#include <QMainWindow>
#include <QMessageBox>
#include <QKeyEvent>
#include <QString>

class eventExample : public QWidget
{
    Q_OBJECT

public:
    eventExample(QWidget *parent = nullptr);
    ~eventExample();

protected:
    // handle keyboard event for alphanumeric keys
    void keyPressEvent(QKeyEvent *event);

    // handle mouse event
    void mouseDoubleClickEvent(QMouseEvent *event);

    // show mouse event information
    void mouseClickedInfo(QString str);
};
#endif // EVENTEXEMPLE_H
