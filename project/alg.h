#ifndef ALG_H
#define ALG_H

#include <QLabel>
#include <QImage>
#include <QPainter>
#include <QtGui>

class Alg : public QLabel
{
    Q_OBJECT
public:
    explicit Alg(QWidget *parent = 0);

public slots:
    void paint(double xmin,double xmax,double ymin,double ymax, double height, double velocity, double degree);
};

#endif
