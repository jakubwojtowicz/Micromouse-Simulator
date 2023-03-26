# include "CPoleModel.h"

CPole::CPole(){
    this->czyScianaZGory = false;
    this->czyScianaZDolu = false;
    this->czyScianaZLewej = false;
    this->czyScianaZPrawej = false;
}
CPole::~CPole(){

}

void CPole::ustawSciany(bool czyScianaZGory, bool czyScianaZDolu, bool czyScianaZLewej, bool czyScianaZPrawej){
    this->czyScianaZGory = czyScianaZGory;
    this->czyScianaZDolu = czyScianaZDolu;
    this->czyScianaZLewej = czyScianaZLewej;
    this->czyScianaZPrawej = czyScianaZPrawej;
}

bool CPole::CzyScianaZGory(){
    return czyScianaZGory;
}

bool CPole::CzyScianaZDolu(){
    return czyScianaZDolu;
}

bool CPole::CzyScianaZLewej(){
    return czyScianaZLewej;
}

bool CPole::CzyScianaZPrawej(){
    return czyScianaZPrawej;
}

void CPole:: usunScianeZGory()
{
    this->czyScianaZGory = false;
}
void CPole:: usunScianeZDolu()
{
    this->czyScianaZDolu = false;
}
void CPole :: usunScianeZLewej()
{
    this->czyScianaZLewej = false;
}
void CPole :: usunScianeZPrawej()
{
    this->czyScianaZPrawej = false;
}
