# include "CRobotWidok.h"

CRobotWidok::CRobotWidok(QWidget *parent, CRobot *robot, int wielkoscRobota)
    : QWidget(parent)
{
    this->robot = robot;
    this->wielkoscRobota = wielkoscRobota;
    painter.setRenderHint(QPainter::Antialiasing);
    setFixedSize(wielkoscRobota, wielkoscRobota);
}

CRobotWidok::~CRobotWidok(){
}

void CRobotWidok::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 5, Qt::SolidLine));
    painter.setBrush(Qt::red);

    QPoint point1;
    QPoint point2;
    QPoint point3;

    if(robot->Orientacja() == 'G')
    {
        point1.setX(wielkoscRobota/2);
        point1.setY(0);
        point2.setX(0);
        point2.setY(wielkoscRobota);
        point3.setX(wielkoscRobota);
        point3.setY(wielkoscRobota);
    }
    else if(robot->Orientacja() == 'P')
    {
        point1.setX(wielkoscRobota);
        point1.setY(wielkoscRobota/2);
        point2.setX(0);
        point2.setY(0);
        point3.setX(0);
        point3.setY(wielkoscRobota);
    }
    else if(robot->Orientacja() == 'L')
    {
        point1.setX(0);
        point1.setY(wielkoscRobota/2);
        point2.setX(wielkoscRobota);
        point2.setY(0);
        point3.setX(wielkoscRobota);
        point3.setY(wielkoscRobota);
    }
    else if(robot->Orientacja() == 'D')
    {
        point1.setX(wielkoscRobota/2);
        point1.setY(wielkoscRobota);
        point2.setX(wielkoscRobota);
        point2.setY(0);
        point3.setX(0);
        point3.setY(0);
    }
    else
    {
        return;
    }
    painter.drawLine(point1, point2);
    painter.drawLine(point2, point3);
    painter.drawLine(point3, point1);

    this->setGeometry(robot->PolozenieX(), robot->PolozenieY(),wielkoscRobota,wielkoscRobota);

}
