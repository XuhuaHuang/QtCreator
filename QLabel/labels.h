#ifndef LABELS_H
#define LABELS_H

#include <QWidget>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QPixmap>
#include <QString>

class labels : public QWidget
{
    Q_OBJECT

public:
    labels(QWidget *parent = 0);
    ~labels();

private slots:
    void dispHovlink(QString a);

private:
    QLabel *label1, *label2;
    QVBoxLayout *vbox;
    QPixmap *pic; // new concept
};
#endif // LABELS_H
