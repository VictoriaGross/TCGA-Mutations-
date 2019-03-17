#include "widget.h"
#include "alg.h"
#include "qlineedit.h"


double R;
double center_x, center_y;
double xmin, xmax, ymin, ymax, height, velocity, degree;

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
    //rubberBand = 0;

    QHBoxLayout *layout = new QHBoxLayout(this);
    QPushButton *drawBtn = new QPushButton("Go!", this);
    Alg *alg = new Alg(this);
    connect(drawBtn, SIGNAL(clicked()), this, SLOT(paint_slot()));
    connect(this, SIGNAL(paint_signal(double,double,double,double,double,double,double)), alg,
            SLOT(paint(double,double,double,double,double,double,double)));
    drawBtn->setGeometry(580, 270, 150, 30);
    layout->addWidget(alg);
    layout->addWidget(drawBtn);
    this->setLayout(layout);
    drawBtn->setGeometry(580, 300, 150, 30);

    qlbdata = new QLabel(this);
    qlbdata->setGeometry(580, 20, 150, 30);
    qlbdata->setStyleSheet("font: 16pt;");
    qlbdata->setText("The initial data:");

    qlbheight = new QLabel(this);
    qlbheight->setGeometry(590, 60, 100, 30);
    qlbheight->setStyleSheet("font: 12pt");
    qlbheight->setText("Height(m)");

    qlheight = new QLineEdit(this);
    qlheight->setGeometry(700, 60, 70, 30);
    qlheight->setStyleSheet("font: 12pt");
    qlheight->setText("10");

    qlbvelocity = new QLabel(this);
    qlbvelocity->setGeometry(590, 90, 100, 30);
    qlbvelocity->setStyleSheet("font: 12pt");
    qlbvelocity->setText("Velocity(m/s)");

    qlvelocity = new QLineEdit(this);
    qlvelocity->setGeometry(700, 90, 70, 30);
    qlvelocity->setStyleSheet("font: 12pt");
    qlvelocity->setText("10");

    qlbdegree = new QLabel(this);
    qlbdegree->setGeometry(590, 120, 100, 30);
    qlbdegree->setStyleSheet("font: 12pt");
    qlbdegree->setText("Angle(deg)");

    qldegree = new QLineEdit(this);
    qldegree->setGeometry(700, 120, 70, 30);
    qldegree->setStyleSheet("font: 12pt");
    qldegree->setText("0");

 //---------------------------------

    qlbscale = new QLabel(this);
    qlbscale->setGeometry(580, 160, 150, 30);
    qlbscale->setStyleSheet("font: 16pt;");
    qlbscale->setText("Scale:");

    qlbxmin = new QLabel(this);
    qlbxmin->setGeometry(590, 200, 70, 30);
    qlbxmin->setStyleSheet("font: 12pt");
    qlbxmin->setText("X_min");

    qlxmin = new QLineEdit(this);
    qlxmin->setGeometry(640, 200, 70, 30);
    qlxmin->setStyleSheet("font: 12pt");
    qlxmin->setText("0");

    qlbxmax = new QLabel(this);
    qlbxmax->setGeometry(730, 200, 70, 30);
    qlbxmax->setStyleSheet("font: 12pt");
    qlbxmax->setText("X_max");

    qlxmax = new QLineEdit(this);
    qlxmax->setGeometry(780, 200, 70, 30);
    qlxmax->setStyleSheet("font: 12pt");
    qlxmax->setText("10");

    qlbymin = new QLabel(this);
    qlbymin->setGeometry(590, 230, 70, 30);
    qlbymin->setStyleSheet("font: 12pt");
    qlbymin->setText("Y_min");

    qlymin = new QLineEdit(this);
    qlymin->setGeometry(640, 230, 70, 30);
    qlymin->setStyleSheet("font: 12pt");
    qlymin->setText("0");

    qlbymax = new QLabel(this);
    qlbymax->setGeometry(730, 230, 70, 30);
    qlbymax->setStyleSheet("font: 12pt");
    qlbymax->setText("Y_max");

    qlymax = new QLineEdit(this);
    qlymax->setGeometry(780, 230, 70, 30);
    qlymax->setStyleSheet("font: 12pt");
    qlymax->setText("10");

    qlbhmax = new QLabel(this);
    qlbhmax->setGeometry(580, 300, 150, 30);
    qlbhmax->setStyleSheet("font: 14pt");

    qlblmax = new QLabel(this);
    qlblmax->setGeometry(580, 330, 150, 30);
    qlblmax->setStyleSheet("font: 14pt");
    center_x = 0;
    center_y = 250;
    R = 30;
 }

double h1(double x, double degree, double height, double velocity)
{
    if (velocity == 0)
    {return height;}
    else if (degree != 0)
    {
        if (velocity != 0)
        {
            double tg = tan(degree);
            return -9.81 / (2 * velocity * velocity) * (tg * tg + 1) * x * x + tg * x + height;
        }
    }
    else
    {
        if (velocity != 0)
        {
            return -9.81 / (2 * velocity * velocity) * x * x + height;
        }
    }
    return 0;

}

double max_h1(double velocity, double height, double degree)
{
    if (degree <= 0) {return height;}
    else if (degree < 90) {
        double x0 = velocity * velocity * sin(2 * degree) / 2 / 9.81;
        return (h1(x0, degree, height, velocity));
    }
    else
    {
        return height + velocity * velocity / 2 / 9.81;
    }
}


double max_l1(double velocity, double height, double degree)
{
    if (degree == 90 || degree == -90)
    {
        return 0;
    }
    else
    {
        double tg = tan(degree);
        double a = height * 9.81 / velocity / velocity;
        double D = tg * tg * (1 + 2 * a) + 2 * a;
        double xm = (tg + sqrt(D)) * velocity * velocity / 9.81 / (tg * tg + 1);
        return xm;
    }
}

void Widget::paint_slot()
{
    xmin = qlxmin->text().toDouble(),
            xmax = qlxmax->text().toDouble(),
            ymin = qlymin->text().toDouble(),
            ymax = qlymax->text().toDouble(),
            height = qlheight->text().toDouble(),
            velocity = qlvelocity->text().toDouble(),
            degree = qldegree->text().toDouble();

    double max_h = max_h1(velocity, height, degree);
    double max_l = max_l1(velocity, height, degree);
    QString s1 = QString("Max height %1").arg(max_h);
    QString s2 = QString("Range %1").arg(max_l);
    qlbhmax->setText(s1);
    qlblmax->setText(s2);
    center_x = 0;
    center_y = 0;
    emit paint_signal(xmin, xmax, ymin, ymax, height, velocity, degree);
}

