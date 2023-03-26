#ifndef CPOLE_H
#define CPOLE_H

//klasa reprezentująca pojedyncze pole labiryntu
class CPole{
public:
    //konstruktor i destruktor
    CPole();
    ~CPole();
    //metoda do ustawienia scian
    void ustawSciany(bool czyScianaZGory, bool czyScianaZDolu, bool czyScianaZLewej, bool czyScianaZPrawej);
    //gettery
    bool CzyScianaZGory();
    bool CzyScianaZDolu();
    bool CzyScianaZLewej();
    bool CzyScianaZPrawej();
    bool CzyPoleSrodkowe();
    //settery
    void usunScianeZGory();
    void usunScianeZDolu();
    void usunScianeZLewej();
    void usunScianeZPrawej();

    void PoleSrodkowe();
private:
    //zmienne okreslajace sciany dookoła pola labiryntu
    bool czyScianaZGory;
    bool czyScianaZDolu;
    bool czyScianaZLewej;
    bool czyScianaZPrawej;
};


#endif // CPOLE_H
