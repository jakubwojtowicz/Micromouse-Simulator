#ifndef CLABIRYNTWIDOK_H
#define CLABIRYNTWIDOK_H
#include <QWidget>
#include <QPainter>
#include "CLabiryntModel.h"
#include "CRobotModel.h"

//klasa służąca do narysowania widoku labiryntu
class CLabiryntWidok : public QWidget {
public:
    //konstruktor
    CLabiryntWidok(QWidget *parent = nullptr, CLabirynt *labirynt = new CLabirynt(), CRobot *robot = new CRobot(), int wielkoscLabiryntu = 480, int wielkoscRobota = 10, bool czyWidokRobota = false);

    ~CLabiryntWidok();

protected:
    //funkcja do rysowania
    void paintEvent(QPaintEvent *event) override;

private:
    QPainter painter();
    //labirynt do narysowania
    CLabirynt *labirynt;
    //robot do narysowania
    CRobot *robot;
    //wielkosc pojedynczej celi w pikselach
    int wielkoscPola;
    //wielkosc robota
    int wielkoscRobota;
    //metoda służąca do narysowania labiryntu
    void rysujLabirynt();
    //metoda służąca do narysowania robota w labiryncie
    void rysujRobota();
    //informacja czy widok z robota
    bool czyWidokRobota;

};


#endif // CLABIRYNTWIDOK_H
