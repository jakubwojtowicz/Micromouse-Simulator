# include "CGeneratorLabiryntuModel.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void CGenerator::wygeneruj()
{
    //zainicjowanie labiryntu oraz macierzy
    inicjalizacjaLabiryntu();
    inicjalizacjaMacierzyOdwiedzin();
    //wylosowanie pozycji od której algorytm rozpocznie działanie
    losujPole();
    //dodanie pola do stosu
    stosOdwiedzonychPol.push(aktualnePole);
    //dopoki nie odwiedzono wszystkich pol
    while(czyPozostalyNieodwiedzonePola())
    {
        //pobranie sasiadow aktualnego pola, ktorzy nie są odwiedzeni
        pobierzNieodwiedzonychSasiadow();
        //jezeli lista sasiadow jest pusta
        if(listaSasiadow.empty())
        {
            //cofnięcie się do poprzedniego pola
            aktualnePole = stosOdwiedzonychPol.pop();
            continue;
        }
        //jezeli lista nie jest pusta
        else
        {
            int losowynumerSasiada = randomGenerator.bounded(listaSasiadow.size());
            //usuniecie sciany pomiedzy polami
            usunScianePomiedzyPolami(aktualnePole, listaSasiadow[losowynumerSasiada]);
            //dodanie pola do stosu
            stosOdwiedzonychPol.push(aktualnePole);
            //zmiana aktualnego pola
            aktualnePole.setX(listaSasiadow[losowynumerSasiada].x());
            aktualnePole.setY(listaSasiadow[losowynumerSasiada].y());
            //oznaczenie nowego pola jako odwiedzone
            macierzOdwiedzin[aktualnePole.y()][aktualnePole.x()] = true;
        }
    }

}

void CGenerator::inicjalizacjaLabiryntu()
{
    for(int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            this->labirynt[i][j].ustawSciany(true,true,true,true);
        }
    }
}

void CGenerator::inicjalizacjaMacierzyOdwiedzin()
{
    for(int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            this->macierzOdwiedzin[i][j] = false;
        }
    }
}

void CGenerator::losujPole()
{
    int losoweX = randomGenerator.bounded(16);
    int losoweY = randomGenerator.bounded(16);

    this->aktualnePole.setX(losoweX);
    this->aktualnePole.setY(losoweY);
    this->macierzOdwiedzin[losoweY][losoweX] = true;
}

bool CGenerator::czyPozostalyNieodwiedzonePola()
{
    for(int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            if(macierzOdwiedzin[i][j] == false)
            {
                return true;
            }
        }
    }
    return false;
}

void CGenerator::pobierzNieodwiedzonychSasiadow()
{
    //punkt do dodania
    QPoint punktDoDodania;

    //wyczysczenie listy
    listaSasiadow.clear();

    //sprawdzenie sasiada po lewej
    if(aktualnePole.x() - 1 >= 0)
    {
        if(macierzOdwiedzin[aktualnePole.y()][aktualnePole.x()-1] == false)
        {
            punktDoDodania.setX(aktualnePole.x()-1);
            punktDoDodania.setY(aktualnePole.y());
            listaSasiadow.append(punktDoDodania);
        }
    }
    //sprawdzenie sasiada po prawej
    if(aktualnePole.x() + 1 < 16)
    {
        if(macierzOdwiedzin[aktualnePole.y()][aktualnePole.x()+1] == false)
        {
            punktDoDodania.setX(aktualnePole.x()+1);
            punktDoDodania.setY(aktualnePole.y());
            listaSasiadow.append(punktDoDodania);
        }
    }
    //sprawdzenie sasiada z gory
    if(aktualnePole.y() - 1 >= 0)
    {
        if(macierzOdwiedzin[aktualnePole.y()-1][aktualnePole.x()] == false)
        {
            punktDoDodania.setX(aktualnePole.x());
            punktDoDodania.setY(aktualnePole.y()-1);
            listaSasiadow.append(punktDoDodania);
        }
    }
    //sprawdzenie sasiada z dolu
    if(aktualnePole.y() + 1 < 16)
    {
        if(macierzOdwiedzin[aktualnePole.y()+1][aktualnePole.x()] == false)
        {
            punktDoDodania.setX(aktualnePole.x());
            punktDoDodania.setY(aktualnePole.y()+1);
            listaSasiadow.append(punktDoDodania);
        }
    }
}

void CGenerator::usunScianePomiedzyPolami(QPoint aktualnePole, QPoint nowePole)
{
    //nowe pole znajduje się pod starym polem
    if (nowePole.y() > aktualnePole.y())
    {
        labirynt[aktualnePole.y()][aktualnePole.x()].usunScianeZDolu();
        labirynt[nowePole.y()][nowePole.x()].usunScianeZGory();
    }
    //nowe pole znajduje się nad starym polem
    else if (nowePole.y() < aktualnePole.y())
    {
        labirynt[aktualnePole.y()][aktualnePole.x()].usunScianeZGory();
        labirynt[nowePole.y()][nowePole.x()].usunScianeZDolu();
    }
    //nowe pole znajduje się po lewej stronie od starego pola
    else if (nowePole.x() < aktualnePole.x())
    {
        labirynt[aktualnePole.y()][aktualnePole.x()].usunScianeZLewej();
        labirynt[nowePole.y()][nowePole.x()].usunScianeZPrawej();
    }
    //nowe pole znajduje się po prawej stronie od starego pola
    else if (nowePole.x() > aktualnePole.x())
    {
        labirynt[aktualnePole.y()][aktualnePole.x()].usunScianeZPrawej();
        labirynt[nowePole.y()][nowePole.x()].usunScianeZLewej();
    }
}
