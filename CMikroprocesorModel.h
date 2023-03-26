#ifndef CFLOODFILL_H
#define CFLOODFILL_H
#include <QQueue>
#include "CLabiryntModel.h"
#include "CPoleModel.h"
#include "qpoint.h"

/*Klasa, która opisuje operacje wykonywanie przez mikrokontroler robota oraz jego zmienne*/
class CMikroprocesor
{
public:
    // metody, które wykonuje mikroprocesor umieszczony w robocie
    virtual void pomiarCzujnikow(CPole *pole);
    //metoda aktualizujaca macierz wartosci za pomocą algorytmu flood fill
    virtual void floodFill();
    //metoda powodująca poruszenie się robota o jedną pozycje
    virtual void jazdaDoPrzodu();
    //metoda realizujaca obrot robota w lewo lub w prawo
    virtual void obrot(char kierunek);
    //metoda sprawdzajaca czy wartosci pol wokol robota są mniejsze od aktualnej wartosci pola
    virtual bool czyWartoscPrzedMniejsza();
    virtual bool czyWartoscPoLewejMniejsza();
    virtual bool czyWartoscPoPrawejMniejsza();
    virtual bool czyWartoscZaMniejsza();
    //metoda obliczajaca minimum wartosci dostepnych pol dookola rozpatrywanego pola
    virtual int minimumSasiadow(QPoint rozpatrywanyPunkt);
    // macierz odleglosci punktów w labiryncie od punktu startowego
    int odleglosci[16][16];
    //labirynt, który jest zapisany w pamięci mikrokontrolera robota
    CLabirynt poznanyLabirynt;
    //cel robota
    QPoint cel;
    //metoda sluzaca do czyszczenia pamieci
    virtual void clear();


};

#endif // CFLOODFILL_H
