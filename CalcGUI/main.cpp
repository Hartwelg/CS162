#include <QApplication>
#include "calcLayoutDialog.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    calcLayoutDialog theCalc;
    theCalc.show();

    return app.exec();
}
