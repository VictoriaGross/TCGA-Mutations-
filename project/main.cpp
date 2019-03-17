#include <QtGui>

#include "widget.h"


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Widget wdg;
    wdg.show();

    return app.exec();
}

