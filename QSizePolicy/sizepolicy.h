#ifndef SIZEPOLICY_H
#define SIZEPOLICY_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>

class sizePolicy : public QWidget
{
    Q_OBJECT

public:
    sizePolicy(QWidget *parent = nullptr);
    ~sizePolicy();
// public slots:
private:
    QVBoxLayout *vbox;
    QPushButton *btn1, *btn2;
};
#endif // SIZEPOLICY_H
