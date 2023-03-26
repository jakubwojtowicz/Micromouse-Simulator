#ifndef CROBOT_H
#define CROBOT_H

#include <string>
#include "CMikroprocesorModel.h"
#include "CPoleModel.h"

using namespace std;

/*Klasa reprezentująca robota pokonującego labirynt*/
class CRobot: public CMikroprocesor
{
public:
    //konstruktor i destruktor
    CRobot();
    ~CRobot();
    void obrot(char kierunek) override;
    void jazdaDoPrzodu() override;
    void pomiarCzujnikow(CPole *pole) override;
    void floodFill() override;
    bool czyWartoscPrzedMniejsza() override;
    bool czyWartoscPoPrawejMniejsza() override;
    bool czyWartoscPoLewejMniejsza() override;
    bool czyWartoscZaMniejsza() override;
    int minimumSasiadow(QPoint rozpatrywanyPunkt) override;
    void clear() override;

    //gettery
    int PolozenieX();
    int PolozenieY();
    bool CzujnikPrzedni();
    bool CzujnikLewy();
    bool CzujnikPrawy();
    char Orientacja();
    int Predkosc();
    //metoda służąca do ustawienia predkosci robota
    void ustawPredkosc(int predkosc);
    void ustawPozycje(int x, int y);
    void ustawOrientacje(char orientacja);




private:
    bool czujnikPrzedni;
    bool czujnikLewy;
    bool czujnikPrawy;
    //wspołrzędne położenia robota w labiryncie
    QPoint polozenie;
    //orientacja robota (G - góra, D - dół , P - prawo, L - lewo)
    char orientacja;
    //predkosc poruszania sie robota
    int predkosc;


};

#endif // CROBOT_H
