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
    //void gen();

//protected:
    //void paintEvent(QPaintEvent *);

//signals:

public slots:
    void next(double x1,double y1,double x2,double y2,int iterations,double inf,double c_re,double c_im);//double X1 = -1, double Y1 = 1, double X2 = 1, double Y2 = -1, int iter = 25, double inf = 2);
};

#endif // ALG_H
