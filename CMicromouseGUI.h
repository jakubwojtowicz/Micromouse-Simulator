#ifndef CMICROMOUSEGUI_H
#define CMICROMOUSEGUI_H
#include "CLabiryntModel.h"
#include "CRobotModel.h"
#include "qlabel.h"
#include "qpushbutton.h"
#include "qwidget.h"
#include "CLabiryntWidok.h"
#include <QApplication>
#include <QVBoxLayout>
#include "QLineEdit"


//Klasa stanowiąca interfejs aplikacji.
class CMicromouseGUI: public QWidget
{
    Q_OBJECT
public:
    //konstruktor i destruktor
    CMicromouseGUI (QWidget *parent = nullptr, CLabirynt *labirynt = new CLabirynt(), CRobot *robot = new CRobot());
    ~CMicromouseGUI ();
    //przycisk startujący jazdę robota
    QPushButton *startButton = new QPushButton("Start");
    //przycisk do wygenerowanie labiryntu
    QPushButton *generujButton = new QPushButton("Generuj");
    //przycisk do resetowania pozycji robota
    QPushButton *resetButton = new QPushButton("Resetuj pozycje");
    //przycisk do resetowania calego przebiegu
    QPushButton *resetAllButton = new QPushButton("Resetuj pamięć");
    //label do wyswietlania uplynietego czasu podczas przejazdu robota
    QLabel *czas_wartosc = new QLabel("00:00:00");

private:

    //napisy do wyświetlania czasu przejazdu
    QLabel *czas_napis = new QLabel("Czas: ");
    //labirynt i robot do wyswietlenia
    CLabirynt *labirynt;
    CRobot *robot;
    //widok labiryntu
    CLabiryntWidok labiryntWidok;
    //głowny layout aplikacji
    QGridLayout *mainLayout = new QGridLayout(this);
    //layout elementów do sterowania aplikacją po lewej stronie ekranu
    QHBoxLayout *menuLeftLayout = new QHBoxLayout();
    //layout elemntow do sterowania aplikacja po prawej stronie ekranu
    QHBoxLayout *menuRightLayout = new QHBoxLayout();
    //labele glownych podpisow
    QLabel *podpisSymulacji = new QLabel("Widok z zewnątrz: ");
    QLabel *podpisWidokuRobota = new QLabel("Pamięć robota: ");

};

#endif // CMICROMOUSEGUI_H
