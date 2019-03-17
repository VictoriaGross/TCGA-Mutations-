#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include<QLabel>
#include<qrubberband>
#include "alg.h"


#include "iostream"

class Widget : public QWidget
{
    Q_OBJECT
    QLabel *qlbdata, *qlbscale;

    QLabel *qlbheight, *qlbvelocity, *qlbdegree;
    QLineEdit *qlheight, *qlvelocity, *qldegree;

    QLabel *qlbxmin, *qlbxmax, *qlbymin, *qlbymax;
    QLineEdit *qlxmin, *qlxmax, *qlymin, *qlymax;

    QLabel *qlbhmax, *qlblmax;
    QLineEdit *qlhmax, *qllmax;

    double X1,  xmax, ymin, ymax, height, velocity, degree;
public:
    explicit Widget(QWidget *parent = 0);
signals:
    void paint_signal(double xmin,double xmax,double ymin,double ymax, double height, double velocity, double degree);

public slots:

    void paint_slot();

};

#endif // WIDGET_H
