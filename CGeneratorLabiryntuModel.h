#ifndef CGENERATORLABIRYNTUMODEL_H
#define CGENERATORLABIRYNTUMODEL_H
#include "CPoleModel.h"
#include "qpoint.h"
#include "qrandom.h"
#include "qstack.h"

/*Klasa służąca do generowania labiryntu 16x16*/

class CGenerator
{
public:
    //wygenerowany labirynt
    CPole labirynt [16][16];
    //metoda służąca do wygenerowania labiryntu
    void wygeneruj();


private:
    //macierz odwiedzin
    bool macierzOdwiedzin[16][16];
    //metody pomocniczne do algorytmu:
    void inicjalizacjaMacierzyOdwiedzin();
    void inicjalizacjaLabiryntu();
    bool czyPozostalyNieodwiedzonePola();
    void losujPole();
    void losujNieodwiedzonegoSasiada();
    void pobierzNieodwiedzonychSasiadow();
    void usunScianePomiedzyPolami(QPoint aktualnePole, QPoint nowePole);
    //pole aktualnie rozpatrywane przez algorytm
    QPoint aktualnePole;
    //stos do przechowywania odwiedzonych pól
    QStack<QPoint> stosOdwiedzonychPol;
    //lista sasiadow aktualnego pola
    QList <QPoint> listaSasiadow;
    //generator losowych pól
    QRandomGenerator randomGenerator;

};



#endif // CGENERATORLABIRYNTUMODEL_H
