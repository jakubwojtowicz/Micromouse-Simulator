# include "CLabiryntModel.h"
using namespace std;

CLabirynt::CLabirynt(){
    //this->wygeneruj();
    for(int i = 0; i < wymiar; i++)
    {
        for(int j = 0; j<wymiar; j++)
        {
            labirynt[i][j].ustawSciany(false,false,false,false);
        }
    }
}

CLabirynt::~CLabirynt(){

}

int CLabirynt::Wymiar()
{
    return wymiar;
}

CPole* CLabirynt::pole(int i, int j){
    return &labirynt[i][j];
}

void CLabirynt::clear()
{
    for(int i = 0; i < wymiar; i++)
    {
        for(int j = 0; j<wymiar; j++)
        {
            labirynt[i][j].ustawSciany(false,false,false,false);
        }
    }
}

