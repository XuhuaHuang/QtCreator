#ifndef CUSTOMSIGNAL_H
#define CUSTOMSIGNAL_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QString>

class customSignal : public QWidget
{
    Q_OBJECT

public:
    customSignal(QWidget *parent = nullptr);
    ~customSignal();

private slots:
    void changeLabelText(void); // custom slots
    void dispNumTimes(int); // custom slots

signals:
    void counterInc(int); // custom signal

private:
    QLabel *label;
    QVBoxLayout *vbox;
    QPushButton *button;

    int flag; // boolean flag
    int count; // cliked times
};

#endif // CUSTOMSIGNAL_H
