#ifndef SLIDERS_H
#define SLIDERS_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QSlider>
#include <QString>

class sliders : public QWidget
{
    Q_OBJECT

public:
    sliders(QWidget *parent = nullptr);
    ~sliders();
    void updateBackgroundColor(void);

public slots:
    void setRed(int);
    void setGreen(int);
    void setBlue(int);
    void setOpacity(int);

private:

    // label representing Red, Green, Blue
    QLabel *rlabel, *glabel, *blabel, *olabel;

    // layout manager
    QHBoxLayout *hbox;
    QVBoxLayout *labelvbox, *slidervbox, *spinboxvbox;

    // spinbox, slider for each colorr
    QSpinBox *rspinbox, *gspinbox, *bspinbox, *ospinbox;
    QSlider *rslider, *gslider, *bslider, *oslider;
    QPalette pal;
    QColor color;

    // int variables to match each label, spinbox, and slider
    int red, green, blue, opacity;
};
#endif // SLIDERS_H
