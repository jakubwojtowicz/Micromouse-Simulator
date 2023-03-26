#ifndef CLABIRYNT_H
#define CLABIRYNT_H

#include "CGeneratorLabiryntuModel.h"
#include "CPoleModel.h"
#include <string>

using namespace std;

//Klasa reprezentująca labirynt
class CLabirynt: public CGenerator
{
public:
    //konstruktor i destruktor
    CLabirynt();
    ~CLabirynt();
    //metoda zwracająca pole labiryntu
    CPole* pole(int i, int j);
    //metody zwracajaca ilosc wierszy i kolumn
    int Wymiar();
    //metoda sluzaca do czyszczenia labiryntu
    void clear();
private:
    //wymiar labiryntu
    int wymiar = 16;



};


#endif // CLABIRYNT_H
