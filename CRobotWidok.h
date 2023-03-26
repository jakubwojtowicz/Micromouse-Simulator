#ifndef CROBOTWIDOK_H
#define CROBOTWIDOK_H
#include <QWidget>
#include <QPainter>
#include "CRobot.h"

//klasa służąca do narysowania widoku labiryntu
class CRobotWidok : public QWidget {
public:
    //konstruktor
    CRobotWidok(QWidget *parent = nullptr, CRobot *robot = new CRobot(), int wielkoscRobota = 50);
    //destruktor
    ~CRobotWidok();

protected:
    //funkcja do rysowania
    void paintEvent(QPaintEvent *event) override;

private:
    QPainter painter;
    //robot do narysowania
    CRobot *robot;
    //wielkosc robota
    int wielkoscRobota;
};


#endif // CROBOTWIDOK_H
