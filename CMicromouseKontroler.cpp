#include "CMicromouseKontroler.h"
#include "qtimer.h"
#include <QObject>
#include "qdatetime.h"
#include <QRandomGenerator>

CMicromouseKontroler::CMicromouseKontroler()
{
    //utworzenie gui z labirynetem oraz robotem
    gui = new CMicromouseGUI(nullptr,&labirynt,&robot);
    connect(gui->startButton,SIGNAL(released()), this, SLOT(startRobota()));
    connect(gui->resetButton,SIGNAL(released()), this, SLOT(resetujPozycje()));
    connect(gui->generujButton,SIGNAL(released()), this, SLOT(generujLabirynt()));
    connect(gui->resetAllButton,SIGNAL(released()), this, SLOT(resetujPamiecRobota()));
}

CMicromouseKontroler::~CMicromouseKontroler()
{

}

void CMicromouseKontroler::resetujPamiecRobota()
{
    timer->stop();
    timer2->stop();
    this->robot.ustawPozycje(0,15);
    this->robot.ustawOrientacje('G');
    robot.clear();
    mierzonyCzas = QTime(0,0,0,0);
    gui->repaint();
}

void CMicromouseKontroler::resetujPozycje()
{
    timer->stop();
    timer2->stop();
    this->robot.ustawPozycje(0,15);
    this->robot.ustawOrientacje('G');
    mierzonyCzas = QTime(0,0,0,0);
    gui->repaint();
}

void CMicromouseKontroler::generujLabirynt()
{
    if(!timer->isActive())
    {
        this->labirynt.wygeneruj();
        gui->repaint();
    }
}

void CMicromouseKontroler::startRobota()
{
    if(true)
    {
        connect(timer, SIGNAL(timeout()), this , SLOT(wykonajKrok()));
        connect(timer2, SIGNAL(timeout()), this , SLOT(wyswietlCzas()));
        timer->start(robot.Predkosc());
        timer2->start(1);
    }
}

void CMicromouseKontroler::wykonajKrok()
{
    //jezeli robot jest u celu - > zakoncz
    if(robot.PolozenieX() == robot.cel.x() && robot.PolozenieY() == robot.cel.y())
    {
        timer->stop();
        timer2->stop();
        return;
    }
    //pomiar czujnikow odleglosc
    robot.pomiarCzujnikow(labirynt.pole(robot.PolozenieY(),robot.PolozenieX()));
    //zapisanie poznanych scian labiryntu
    robot.poznanyLabirynt.labirynt[robot.PolozenieY()][robot.PolozenieX()] = *labirynt.pole(robot.PolozenieY(), robot.PolozenieX());
    //sprawdzenie czy przed robotem nie ma sciany i wartosc macierzy wartosci jest mniejsza niz wartosc aktualna
    if(!robot.CzujnikPrzedni() && robot.czyWartoscPrzedMniejsza())
    {
        robot.jazdaDoPrzodu();
    }
    //sprawdzenie czy po lewej stronie nie ma sciany i wartosc macierzy wartosci jest mniejsza niz wartosc aktualna
    else if(!robot.CzujnikLewy() && robot.czyWartoscPoLewejMniejsza())
    {
        robot.obrot('L');
    }
    //sprawdzenie czy po prawej stronie nie ma sciany i wartosc macierzy wartosci jest mniejsza niz wartosc aktualnia
    else if(!robot.CzujnikPrawy() && robot.czyWartoscPoPrawejMniejsza())
    {
        robot.obrot('P');
    }
    //jezeli z kazdej strony sciana
    /*
    else if(robot.CzujnikPrawy() && robot.CzujnikLewy() && robot.CzujnikPrzedni())
    {
        robot.obrot('P');
        robot.obrot('P');
    }
    */
    //jezeli w zadna strone robot nie moze jechac
    else
    {
        //aktualizacja macierzy wartosci za pomoca algorytmu flood fill
        robot.floodFill();
        if(robot.czyWartoscZaMniejsza())
        {
            robot.obrot('P');
            robot.obrot('P');
        }
    }

    //aktualizacja widoku labiryntu i robota
    gui->repaint();
}

void CMicromouseKontroler:: wyswietlCzas()
{
    QTime nowyCzas = mierzonyCzas.addMSecs(2);
    QString text = nowyCzas.toString("hh:mm:ss.zzz");
    gui->czas_wartosc->setText(text);
    gui->czas_wartosc->show();
    mierzonyCzas = nowyCzas;
    gui->repaint();
}

