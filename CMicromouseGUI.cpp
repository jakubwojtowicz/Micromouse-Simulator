#include "CMicromouseGUI.h"

CMicromouseGUI::CMicromouseGUI(QWidget *parent, CLabirynt *labirynt, CRobot *robot) : QWidget (parent)
{
    //ustawienie parametrow okna glownego
    this->setWindowTitle("");
    this->setFixedSize(1024,620);
    this->setStyleSheet("background-color: lightGrey;");

    //ustawienie glownego layoutu
    mainLayout->setContentsMargins(20,20,20,20);
    this->setLayout(mainLayout);


    //zainicjowanie widoku labiryntu
    CLabiryntWidok *labiryntWidok = new CLabiryntWidok(this,labirynt,robot, 480,20);

    //zainicjowanie widoku labiryntu
    CLabiryntWidok *labiryntWidokRobota = new CLabiryntWidok(this,&robot->poznanyLabirynt,robot, 480,20, true);

    //ustawienie parametrow przycisku i napisow
    startButton->setFixedSize(150,40);
    resetButton->setFixedSize(150,40);
    resetAllButton->setFixedSize(150,40);
    generujButton->setFixedSize(150,40);
    QFont font = czas_napis->font();
    font.setPointSize(15);
    czas_napis->setFont(font);
    czas_wartosc->setFont(font);
    startButton->setFont(font);
    generujButton->setFont(font);
    resetButton->setFont(font);
    resetAllButton->setFont(font);
    font.setPointSize(15);
    podpisSymulacji->setFont(font);
    podpisWidokuRobota->setFont(font);


    //dodanie elementów do pomocniczych layoutow
    menuLeftLayout->addWidget(generujButton,0,Qt::AlignLeft);
    menuLeftLayout->addWidget(startButton,0, Qt::AlignLeft);

    menuRightLayout->addWidget(resetButton,0,Qt::AlignLeft);
    menuRightLayout->addWidget(resetAllButton,0,Qt::AlignLeft);
    menuRightLayout->addWidget(czas_napis,0,Qt::AlignRight);
    menuRightLayout->addWidget(czas_wartosc,0, Qt::AlignLeft);

    //dodanie elementów do głównego layoutu
    mainLayout->addWidget(podpisSymulacji,0,0,Qt::AlignTop);
    mainLayout->addWidget(podpisWidokuRobota,0,1,Qt::AlignTop);
    mainLayout->addWidget(labiryntWidok,1,0,Qt::AlignTop);
    mainLayout->addWidget(labiryntWidokRobota,1,1,Qt::AlignTop);
    mainLayout->addLayout(menuLeftLayout,2,0);
    mainLayout->addLayout(menuRightLayout,2,1, Qt::AlignLeft);

    this->show();
}

CMicromouseGUI::~CMicromouseGUI()
{

}
