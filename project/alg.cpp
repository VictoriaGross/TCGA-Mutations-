#include "alg.h"
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include<QPainter>
using namespace std;
const double g = 9.81;


Alg::Alg(QWidget *parent) :
    QLabel(parent)
{
    this->setFixedSize(1000, 500);
}

double h(double x, double degree, double height, double velocity)
{
    if (degree != 0)
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

/* SLOTS */

void Alg::paint(double xmin, double xmax, double ymin, double ymax, double height, double velocity, double degree)
{
    int nx, ny, width = 500;
    nx = ceil(500 / (xmax - xmin));
    ny = ceil(500 / (ymax - ymin));
    double x, y;
    double i, j;
    QImage *img = new QImage(width, width, QImage::Format_ARGB32);
    img->fill(0xffffffff);
    for (i = 0; i < 500; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (floor(i / nx) * nx == i || floor((width - j) / ny) * ny == (width - j))
            {
                img->setPixel(i, j, 0x0f000ff0);
            }
            if (i == 0 || j == width - 1)
            {
                img->setPixel(i, j, 0xff000ff0);
            }
        }
    }
    for (i = 0; i < width; i+= 0.1)
    {
        x = i / nx;
        y = h(x, degree, height, velocity);
        img->setPixel(i,width - y * ny, 0xff000000);
    }
    this->setPixmap(QPixmap::fromImage(*img));
}

