# include "CRobotModel.h"
#include "qqueue.h"

using namespace std;

CRobot::CRobot()
{
    this->czujnikLewy = false;
    this->czujnikPrawy = false;
    this->czujnikPrzedni = false;
    //ustawienie domyslnej predkosci poruszania sie robota
    this->predkosc = 100;
    //ustawienie orientacji poczatkowej robota
    this->orientacja = 'G';
    //ustawienie polozenia poczatkowego robota
    this->polozenie.setX(0);
    this->polozenie.setY(15);
    //ustawienie celu robota
    this->cel.setX(8);
    this->cel.setY(8);

    //zapelnienie tablicy odleglosci za pomoca Manhattan Distances
    for(int i = 0; i < 16; i++)
    {
        for(int j =0; j< 16; j++)
        {
            int odleglosc = abs(i-cel.x()) + abs(j-cel.y());
            this->odleglosci[i][j] = odleglosc;
        }
    }

}
CRobot::~CRobot(){

}

void CRobot::clear()
{
    //zapelnienie tablicy odleglosci za pomoca Manhattan Distances
    for(int i = 0; i < 16; i++)
    {
        for(int j =0; j< 16; j++)
        {
            int odleglosc = abs(i-cel.x()) + abs(j-cel.y());
            this->odleglosci[i][j] = odleglosc;
        }
    }
    this->poznanyLabirynt.clear();
}

bool CRobot::CzujnikLewy(){
    return this->czujnikLewy;
}
bool CRobot::CzujnikPrawy(){
    return this->czujnikPrawy;
}
bool CRobot::CzujnikPrzedni(){
    return this->czujnikPrzedni;
}
int CRobot::PolozenieX(){
    return this->polozenie.x();
}
int CRobot::PolozenieY(){
    return this->polozenie.y();
}
char CRobot::Orientacja(){
    return this->orientacja;
}
int CRobot::Predkosc(){
    return this->predkosc;
}
void CRobot::ustawPredkosc(int predkosc){
    this->predkosc = predkosc;
}
void CRobot::ustawPozycje(int x, int y){
    this->polozenie.setX(x);
    this->polozenie.setY(y);
}
void CRobot::ustawOrientacje(char orientacja){
    this->orientacja = orientacja;
}

void CRobot::floodFill(){

    QQueue <QPoint> polaDoOdwiedzenia;
    polaDoOdwiedzenia.enqueue(this->polozenie);
    QPoint punktRozpatrywany;
    QPoint punktDoDodania;
    while(!polaDoOdwiedzenia.empty())
    {
        punktRozpatrywany = polaDoOdwiedzenia.dequeue();
        int minimumSasiadow = this->minimumSasiadow(punktRozpatrywany);
        if(this->odleglosci[punktRozpatrywany.y()][punktRozpatrywany.x()] < minimumSasiadow)
        {
            this->odleglosci[punktRozpatrywany.y()][punktRozpatrywany.x()] = minimumSasiadow +1;

            if(!this->poznanyLabirynt.labirynt[punktRozpatrywany.y()][punktRozpatrywany.x()].CzyScianaZGory())
            {
                punktDoDodania.setX(punktRozpatrywany.x());
                punktDoDodania.setY(punktRozpatrywany.y()-1);
                polaDoOdwiedzenia.enqueue(punktDoDodania);
            }
            if(!this->poznanyLabirynt.labirynt[punktRozpatrywany.y()][punktRozpatrywany.x()].CzyScianaZDolu())
            {
                punktDoDodania.setX(punktRozpatrywany.x());
                punktDoDodania.setY(punktRozpatrywany.y()+1);
                polaDoOdwiedzenia.enqueue(punktDoDodania);
            }
            if(!this->poznanyLabirynt.labirynt[punktRozpatrywany.y()][punktRozpatrywany.x()].CzyScianaZLewej())
            {
                punktDoDodania.setX(punktRozpatrywany.x()-1);
                punktDoDodania.setY(punktRozpatrywany.y());
                polaDoOdwiedzenia.enqueue(punktDoDodania);
            }
            if(!this->poznanyLabirynt.labirynt[punktRozpatrywany.y()][punktRozpatrywany.x()].CzyScianaZPrawej())
            {
                punktDoDodania.setX(punktRozpatrywany.x()+1);
                punktDoDodania.setY(punktRozpatrywany.y());
                polaDoOdwiedzenia.enqueue(punktDoDodania);
            }
        }
        else
        {
            continue;
        }
    }
}

int CRobot::minimumSasiadow(QPoint rozpatrywanyPunkt)
{
    int wartoscMinimalna = 1000;
    if(!this->poznanyLabirynt.labirynt[rozpatrywanyPunkt.y()][rozpatrywanyPunkt.x()].CzyScianaZGory())
    {
        if(this->odleglosci[rozpatrywanyPunkt.y()-1][rozpatrywanyPunkt.x()] < wartoscMinimalna)
        {
            wartoscMinimalna = this->odleglosci[rozpatrywanyPunkt.y()-1][rozpatrywanyPunkt.x()];
        }
    }
    if(!this->poznanyLabirynt.labirynt[rozpatrywanyPunkt.y()][rozpatrywanyPunkt.x()].CzyScianaZDolu())
    {
        if(this->odleglosci[rozpatrywanyPunkt.y()+1][rozpatrywanyPunkt.x()] < wartoscMinimalna)
        {
            wartoscMinimalna = this->odleglosci[rozpatrywanyPunkt.y()+1][rozpatrywanyPunkt.x()];
        }
    }
    if(!this->poznanyLabirynt.labirynt[rozpatrywanyPunkt.y()][rozpatrywanyPunkt.x()].CzyScianaZLewej())
    {
        if(this->odleglosci[rozpatrywanyPunkt.y()][rozpatrywanyPunkt.x()-1] < wartoscMinimalna)
        {
            wartoscMinimalna = this->odleglosci[rozpatrywanyPunkt.y()][rozpatrywanyPunkt.x()-1];
        }
    }
    if(!this->poznanyLabirynt.labirynt[rozpatrywanyPunkt.y()][rozpatrywanyPunkt.x()].CzyScianaZPrawej())
    {
        if(this->odleglosci[rozpatrywanyPunkt.y()][rozpatrywanyPunkt.x()+1] < wartoscMinimalna)
        {
            wartoscMinimalna = this->odleglosci[rozpatrywanyPunkt.y()][rozpatrywanyPunkt.x()+1];
        }
    }
    return wartoscMinimalna;
}

bool CRobot::czyWartoscPrzedMniejsza()
{
    switch(orientacja)
    {
        case 'G':
            if(this->odleglosci[this->PolozenieY()-1][this->PolozenieX()] < this->odleglosci[this->PolozenieY()][this->PolozenieX()])
            {
                return true;
            }
            else
            {
                return false;
            }
        case 'D':
            if(this->odleglosci[this->PolozenieY()+1][this->PolozenieX()] < this->odleglosci[this->PolozenieY()][this->PolozenieX()])
            {
                return true;
            }
            else
            {
                return false;
            }
        case 'L':
            if(this->odleglosci[this->PolozenieY()][this->PolozenieX()-1] < this->odleglosci[this->PolozenieY()][this->PolozenieX()])
            {
                return true;
            }
            else
            {
                return false;
            }
        case 'P':
            if(this->odleglosci[this->PolozenieY()][this->PolozenieX()+1] < this->odleglosci[this->PolozenieY()][this->PolozenieX()])
            {
                return true;
            }
            else
            {
                return false;
            }
    }
    return false;
}

bool CRobot::czyWartoscPoPrawejMniejsza()
{
    switch(orientacja)
    {
        case 'G':
            if(this->odleglosci[this->PolozenieY()][this->PolozenieX()+1] < this->odleglosci[this->PolozenieY()][this->PolozenieX()])
            {
                return true;
            }
            else
            {
                return false;
            }
        case 'D':
            if(this->odleglosci[this->PolozenieY()][this->PolozenieX()-1] < this->odleglosci[this->PolozenieY()][this->PolozenieX()])
            {
                return true;
            }
            else
            {
                return false;
            }
        case 'L':
            if(this->odleglosci[this->PolozenieY()-1][this->PolozenieX()] < this->odleglosci[this->PolozenieY()][this->PolozenieX()])
            {
                return true;
            }
            else
            {
                return false;
            }
        case 'P':
            if(this->odleglosci[this->PolozenieY()+1][this->PolozenieX()] < this->odleglosci[this->PolozenieY()][this->PolozenieX()])
            {
                return true;
            }
            else
            {
                return false;
            }
    }
    return false;
}


bool CRobot::czyWartoscPoLewejMniejsza()
{
    switch(orientacja)
    {
        case 'G':
            if(this->odleglosci[this->PolozenieY()][this->PolozenieX()-1] < this->odleglosci[this->PolozenieY()][this->PolozenieX()])
            {
                return true;
            }
            else
            {
                return false;
            }
        case 'D':
            if(this->odleglosci[this->PolozenieY()][this->PolozenieX()+1] < this->odleglosci[this->PolozenieY()][this->PolozenieX()])
            {
                return true;
            }
            else
            {
                return false;
            }
        case 'L':
            if(this->odleglosci[this->PolozenieY()+1][this->PolozenieX()] < this->odleglosci[this->PolozenieY()][this->PolozenieX()])
            {
                return true;
            }
            else
            {
                return false;
            }
        case 'P':
            if(this->odleglosci[this->PolozenieY()-1][this->PolozenieX()] < this->odleglosci[this->PolozenieY()][this->PolozenieX()])
            {
                return true;
            }
            else
            {
                return false;
            }
    }
    return false;
}

bool CRobot::czyWartoscZaMniejsza()
{
    switch(orientacja)
    {
        case 'G':
            if(this->odleglosci[this->PolozenieY()+1][this->PolozenieX()] < this->odleglosci[this->PolozenieY()][this->PolozenieX()])
            {
                return true;
            }
            else
            {
                return false;
            }
        case 'D':
            if(this->odleglosci[this->PolozenieY()-1][this->PolozenieX()] < this->odleglosci[this->PolozenieY()][this->PolozenieX()])
            {
                return true;
            }
            else
            {
                return false;
            }
        case 'L':
            if(this->odleglosci[this->PolozenieY()][this->PolozenieX()+1] < this->odleglosci[this->PolozenieY()][this->PolozenieX()])
            {
                return true;
            }
            else
            {
                return false;
            }
        case 'P':
            if(this->odleglosci[this->PolozenieY()][this->PolozenieX()-1] < this->odleglosci[this->PolozenieY()][this->PolozenieX()])
            {
                return true;
            }
            else
            {
                return false;
            }
    }
    return false;
}


void CRobot::obrot(char kierunek) {
    if(kierunek == 'P')
    {
        if(this->orientacja == 'G')
        {
            this->orientacja = 'P';
        }
        else if(this->orientacja == 'P')
        {
            this->orientacja = 'D';
        }
        else if(this->orientacja == 'D')
        {
            this->orientacja = 'L';
        }
        else if(this->orientacja == 'L')
        {
            this->orientacja = 'G';
        }
    }
    else if (kierunek == 'L')
    {
        if(this->orientacja == 'G')
        {
            this->orientacja = 'L';
        }
        else if(this->orientacja == 'L')
        {
            this->orientacja = 'D';
        }
        else if(this->orientacja == 'D')
        {
            this->orientacja = 'P';
        }
        else if(this->orientacja == 'P')
        {
            this->orientacja = 'G';
        }
    }
}

void CRobot::jazdaDoPrzodu()
{
    switch(orientacja)
    {
        case 'G':
            this->polozenie.setY(this->polozenie.y()-1);
            break;
        case 'D':
            this->polozenie.setY(this->polozenie.y()+1);
            break;
        case 'L':
            this->polozenie.setX(this->polozenie.x()-1);
            break;
        case 'P':
            this->polozenie.setX(this->polozenie.x()+1);
            break;
    }
}
void CRobot::pomiarCzujnikow(CPole *pole)
{
    this->czujnikLewy = false;
    this->czujnikPrawy = false;
    this->czujnikPrzedni = false;

    switch(orientacja)
    {
        case 'G':
            if(pole->CzyScianaZLewej())
            {
                this->czujnikLewy = true;
            }
            if(pole->CzyScianaZPrawej())
            {
                this->czujnikPrawy = true;
            }
            if(pole->CzyScianaZGory())
            {
                this->czujnikPrzedni = true;
            }
            break;
        case 'D':
            if(pole->CzyScianaZLewej())
            {
                this->czujnikPrawy = true;
            }
            if(pole->CzyScianaZPrawej())
            {
                this->czujnikLewy = true;
            }
            if(pole->CzyScianaZDolu())
            {
                this->czujnikPrzedni = true;
            }
            break;
        case 'L':
            if(pole->CzyScianaZLewej())
            {
                this->czujnikPrzedni = true;
            }
            if(pole->CzyScianaZGory())
            {
                this->czujnikPrawy = true;
            }
            if(pole->CzyScianaZDolu())
            {
                this->czujnikLewy = true;
            }
            break;
        case 'P':
            if(pole->CzyScianaZPrawej())
            {
                this->czujnikPrzedni = true;
            }
            if(pole->CzyScianaZGory())
            {
                this->czujnikLewy = true;
            }
            if(pole->CzyScianaZDolu())
            {
                this->czujnikPrawy = true;
            }
            break;
    }
}
