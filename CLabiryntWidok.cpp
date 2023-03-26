# include "CLabiryntWidok.h"
# include "CPoleModel.h"
#include "CRobotModel.h"


CLabiryntWidok::CLabiryntWidok(QWidget *parent, CLabirynt *labirynt, CRobot *robot, int wielkoscLabiryntu, int wielkoscRobota, bool czyWidokRobota)
    : QWidget(parent)
{
    this->labirynt = labirynt;
    this->robot = robot;
    this->wielkoscRobota = wielkoscRobota;
    this->wielkoscPola = wielkoscLabiryntu/labirynt->Wymiar();
    this->setFixedSize(wielkoscLabiryntu, wielkoscLabiryntu);
    //painter().setRenderHint(QPainter::Antialiasing);
    setFixedSize(wielkoscLabiryntu, wielkoscLabiryntu);
    this->setStyleSheet("background-color: lightGreen;");
    this->czyWidokRobota = czyWidokRobota;
}

CLabiryntWidok::~CLabiryntWidok(){
}


void CLabiryntWidok::paintEvent(QPaintEvent *event)
{
    rysujLabirynt();
    rysujRobota();
}

void CLabiryntWidok::rysujLabirynt()
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::darkGreen, 3, Qt::SolidLine));
    painter.setBrush(Qt::darkGreen);

    //dla wszystkich pól labiryntu
    for (int i = 0; i < labirynt->Wymiar(); i++) {
        for (int j = 0; j < labirynt->Wymiar(); j++) {
            int iprzeliczone = i * wielkoscPola;
            int jprzeliczone = j * wielkoscPola;

            //narysowanie scian labiryntu wokol pojedynczego pola
            if(labirynt->pole(i,j)->CzyScianaZGory())
            {
                painter.drawLine(jprzeliczone,iprzeliczone,jprzeliczone+wielkoscPola,iprzeliczone);
            }
            if(labirynt->pole(i,j)->CzyScianaZDolu())
            {
               painter.drawLine(jprzeliczone,iprzeliczone+wielkoscPola,jprzeliczone+wielkoscPola,iprzeliczone+wielkoscPola);
            }
            if(labirynt->pole(i,j)->CzyScianaZLewej())
            {
               painter.drawLine(jprzeliczone,iprzeliczone,jprzeliczone,iprzeliczone+wielkoscPola);
            }
            if(labirynt->pole(i,j)->CzyScianaZPrawej())
            {
               painter.drawLine(jprzeliczone+wielkoscPola,iprzeliczone,jprzeliczone+wielkoscPola,iprzeliczone+wielkoscPola);
            }
        }
    }

    if(czyWidokRobota)
    {
        painter.setPen(QPen(Qt::black, 20, Qt::SolidLine));
        painter.setBrush(Qt::darkGreen);
        for (int i = 0; i < labirynt->Wymiar(); i++) {
            for (int j = 0; j < labirynt->Wymiar(); j++) {
                QPoint punkt;
                punkt.setX(j*wielkoscPola + (wielkoscPola - 20)/2);
                punkt.setY(i*wielkoscPola + wielkoscPola/2);
                QString wartoscPola = QString::number(this->robot->odleglosci[i][j]);
                painter.drawText(punkt, wartoscPola);
            }
        }
    }


}

void CLabiryntWidok::rysujRobota()
{
    QPainter painter(this);


    //punkty obrysu robota
    QPoint point1;
    QPoint point2;
    QPoint point3;

    //przesunięcie robota w osiach X i Y oraz wyśrodkowanie w polu labiryntu
    int offset_X = robot->PolozenieX()*wielkoscPola+(wielkoscPola-wielkoscRobota)/2;
    int offset_y = robot->PolozenieY()*wielkoscPola+(wielkoscPola-wielkoscRobota)/2;

    //wyznaczenie punktów obrysu robota w zależności od orientacji
    if(robot->Orientacja() == 'G')
    {
        point1.setX(wielkoscRobota/2+offset_X);
        point1.setY(0+offset_y);
        point2.setX(0+offset_X);
        point2.setY(wielkoscRobota+offset_y);
        point3.setX(wielkoscRobota+offset_X);
        point3.setY(wielkoscRobota+offset_y);
    }
    else if(robot->Orientacja() == 'P')
    {
        point1.setX(wielkoscRobota+offset_X);
        point1.setY(wielkoscRobota/2+offset_y);
        point2.setX(0+offset_X);
        point2.setY(0+offset_y);
        point3.setX(0+offset_X);
        point3.setY(wielkoscRobota+offset_y);
    }
    else if(robot->Orientacja() == 'L')
    {
        point1.setX(0+offset_X);
        point1.setY(wielkoscRobota/2+offset_y);
        point2.setX(wielkoscRobota+offset_X);
        point2.setY(0+offset_y);
        point3.setX(wielkoscRobota+offset_X);
        point3.setY(wielkoscRobota+offset_y);
    }
    else if(robot->Orientacja() == 'D')
    {
        point1.setX(wielkoscRobota/2+offset_X);
        point1.setY(wielkoscRobota+offset_y);
        point2.setX(wielkoscRobota+offset_X);
        point2.setY(0+offset_y);
        point3.setX(0+offset_X);
        point3.setY(0+offset_y);
    }
    else
    {
        return;
    }

    //narysowanie kol robota
    painter.setPen(QPen(Qt::black, 10, Qt::SolidLine));
    painter.setBrush(Qt::black);
    painter.drawPoint(point2);
    painter.drawPoint(point3);
    painter.setPen(QPen(Qt::black, 5, Qt::SolidLine));
    painter.drawPoint(point1);

    //narysowanie linii reprezentujących robota
    painter.setPen(QPen(Qt::red, 4, Qt::SolidLine));
    painter.setBrush(Qt::red);
    QPolygonF triangle;
    triangle << point1 << point2 << point3;
    painter.drawPolygon(triangle);
}
