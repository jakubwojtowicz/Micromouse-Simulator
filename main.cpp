#include "CMicromouseKontroler.h"
#include "qapplication.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    CMicromouseKontroler kontroler;
    return app.exec();
}

