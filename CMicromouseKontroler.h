#ifndef CMICROMOUSEKONTROLER_H
#define CMICROMOUSEKONTROLER_H

#include "CLabiryntModel.h"
#include "CMicromouseGUI.h"
#include "CRobotModel.h"
#include "qdatetime.h"
#include "qtimer.h"

/*Metoda łącząca modele programu i widoki*/
class CMicromouseKontroler: public QObject
{
    Q_OBJECT
public:
    CMicromouseKontroler();
    ~CMicromouseKontroler();
public slots:
    //metoda służąca do wykonania kroku robota tzn. jazdy do przodu lub obrotu na podstawie algorytmu
    void wykonajKrok();
    //metoda obługująca naciśnięcie przycisku Start
    void startRobota();
    //metoda służąca do aktualizacji wyświetlania czasu
    void wyswietlCzas();
    //metoda służąca do wygenerowania labiryntu
    void generujLabirynt();
    //metoda służąca do resetu pozycji robota
    void resetujPozycje();
    //metoda służąca do resetu pamięci i pozycji robota
    void resetujPamiecRobota();
private:
    //utworzenie labiryntu oraz robota
    CLabirynt labirynt;
    CRobot robot;
    //utworzenie UI aplikacji
    CMicromouseGUI *gui;
    QTime mierzonyCzas = QTime(0,0,0,0);
    //ustawienie timera robota
    QTimer *timer = new QTimer(nullptr);
    //ustawienie timera czasomierza
    QTimer *timer2 = new QTimer(nullptr);


};



#endif // CMICROMOUSEKONTROLER_H
