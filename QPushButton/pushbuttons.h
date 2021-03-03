#ifndef PUSHBUTTONS_H
#define PUSHBUTTONS_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QIcon>
#include <QSize>

class pushbuttons : public QWidget
{
    Q_OBJECT

public:
    pushbuttons(QWidget *parent = 0);
    ~pushbuttons();

private slots:
    void btnClicked(void);

private:
    // 4 different kinds of button
    QPushButton *clickbtn, *togglebtn, *flatbtn, *iconbtn;

    // horizontal layout manager
    QHBoxLayout *hbox;
};
#endif // PUSHBUTTONS_H
