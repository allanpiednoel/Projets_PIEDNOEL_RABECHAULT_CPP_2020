#include "mon_dessin.h"
#include "mainwindow.h"

Mon_dessin::Mon_dessin(QObject *parent) : QGraphicsScene(parent)
{
    QPen black;
    black.setColor(Qt::black);
    black.setWidth(3);

    addLine(-200, 0, -50, 0,ChangeColor(MainWindow::listeValeur.value(0)));

    addLine(-200, 100, 50, 100,ChangeColor(MainWindow::listeValeur.value(1)));

    addLine(-200, 200, -50, 200, ChangeColor(MainWindow::listeValeur.value(2)));

    addLine(-200, 300, 50, 300, ChangeColor(MainWindow::listeValeur.value(3)));

// Pont 1 reliant les fils 0 et 2
    if(MainWindow::listeValeur.value(0) > MainWindow::listeValeur.value(2))
    {
// Si c'est le cas on ajoute un trait de couleur sur le grahique
        addLine(-50, 0, -50, 200,ChangeColor(MainWindow::listeValeur.value(0)));

        addLine(-50, 200,200, 200,ChangeColor(MainWindow::listeValeur.value(0)));

        addLine(-53, 0, -53, 200,ChangeColor(MainWindow::listeValeur.value(2)));

        addLine(-50, 0, 200, 0,ChangeColor(MainWindow::listeValeur.value(2)));

        MainWindow::listeValeur.swapItemsAt(0,2);

    }
    else
    {
// Sinon on ajoute le trait en noir
        addLine(-50, 0, -50, 200,black);

        addLine(-50, 0, 200, 0,ChangeColor(MainWindow::listeValeur.value(0)));

        addLine(-50, 200, 200, 200,ChangeColor(MainWindow::listeValeur.value(2)));

    }
// Pont 2 reliant les fils 1 et 3
    if(MainWindow::listeValeur.value(1) > MainWindow::listeValeur.value(3))
    {
// Si c'est le cas on ajoute un trait de couleur sur le grahique
        addLine(50, 100, 50, 300,ChangeColor(MainWindow::listeValeur.value(1)));

        addLine(50, 300, 200, 300, ChangeColor(MainWindow::listeValeur.value(1)));

        addLine(53, 100, 53, 300,ChangeColor(MainWindow::listeValeur.value(3)));

        addLine(50, 100, 200, 100,ChangeColor(MainWindow::listeValeur.value(3)));

        MainWindow::listeValeur.swapItemsAt(1,3);
    }
    else
    {
// Sinon on ajoute le trait en noir
        addLine(50, 100, 50, 300,black);

        addLine(50, 300, 200, 300, ChangeColor(MainWindow::listeValeur.value(3)));

        addLine(50, 100, 200, 100,ChangeColor(MainWindow::listeValeur.value(1)));

    }

// Pont 3 reliant les fils 0 et 1
    if(MainWindow::listeValeur.value(0) > MainWindow::listeValeur.value(1))

    {

        addLine(200, 0, 200, 100,ChangeColor(MainWindow::listeValeur.value(0)));

        addLine(200, 100, 300, 100,ChangeColor(MainWindow::listeValeur.value(0)));

        addLine(197, 0, 197, 100,ChangeColor(MainWindow::listeValeur.value(1)));

        addLine(200, 0, 350, 0,ChangeColor(MainWindow::listeValeur.value(1)));

        MainWindow::listeValeur.swapItemsAt(0,1);

    }


    else

    {

        addLine(200, 0, 200, 100,black);

        addLine(200, 100, 300, 100,ChangeColor(MainWindow::listeValeur.value(1)));

        addLine(200, 0, 350, 0,ChangeColor(MainWindow::listeValeur.value(0)));

    }

// Pont 4 reliant les fils 2 et 3
    if(MainWindow::listeValeur.value(2) > MainWindow::listeValeur.value(3))

    {

        addLine(200, 200, 200, 300,ChangeColor(MainWindow::listeValeur.value(2)));

        addLine(200, 300, 350, 300,ChangeColor(MainWindow::listeValeur.value(2)));

        addLine(197, 200, 197, 300,ChangeColor(MainWindow::listeValeur.value(3)));

        addLine(200, 200, 300, 200,ChangeColor(MainWindow::listeValeur.value(3)));

        MainWindow::listeValeur.swapItemsAt(2,3);

    }

    else

    {

        addLine(200, 200, 200, 300,black);

        addLine(200, 300, 350, 300,ChangeColor(MainWindow::listeValeur.value(3)));

        addLine(200, 200, 300, 200,ChangeColor(MainWindow::listeValeur.value(2)));

    }

// Pont 5 reliant les fils 1 et 2
    if(MainWindow::listeValeur.value(1) > MainWindow::listeValeur.value(2))

    {

        addLine(300, 100, 300, 200,ChangeColor(MainWindow::listeValeur.value(1)));

        addLine(300, 200, 350, 200,ChangeColor(MainWindow::listeValeur.value(1)));

        addLine(297, 100, 297, 200,ChangeColor(MainWindow::listeValeur.value(2)));

        addLine(300, 100, 350, 100,ChangeColor(MainWindow::listeValeur.value(2)));

        MainWindow::listeValeur.swapItemsAt(1,2);

    }


    else

    {

        addLine(300, 100, 300, 200,black);

        addLine(300, 200, 350, 200,ChangeColor(MainWindow::listeValeur.value(2)));

        addLine(300, 100, 350, 100,ChangeColor(MainWindow::listeValeur.value(1)));

    }

//création des carrées
    addRect(-56,-6,12,12,QPen(Qt::black), QBrush(Qt::SolidPattern));

    addRect(-56,194,12,12,QPen(Qt::black), QBrush(Qt::SolidPattern));

    addRect(46,96,12,12,QPen(Qt::black), QBrush(Qt::SolidPattern));

    addRect(46,296,12,12,QPen(Qt::black), QBrush(Qt::SolidPattern));


    addRect(194,-4,12,12,QPen(Qt::black), QBrush(Qt::SolidPattern));

    addRect(194,96,12,12,QPen(Qt::black), QBrush(Qt::SolidPattern));

    addRect(194,196,12,12,QPen(Qt::black), QBrush(Qt::SolidPattern));

    addRect(194,296,12,12,QPen(Qt::black), QBrush(Qt::SolidPattern));

    addRect(294,196,12,12,QPen(Qt::black), QBrush(Qt::SolidPattern));

    addRect(294,96,12,12,QPen(Qt::black), QBrush(Qt::SolidPattern));
}

QPen Mon_dessin::ChangeColor(int value)
{
    QPen pen;
    pen.setWidth(3);

    if (value == 1)
        pen.setColor(Qt::red);

    if (value == 2)
        pen.setColor(Qt::green);

    if (value == 3)
        pen.setColor(Qt::blue);

    if (value == 4)
        pen.setColor(Qt::yellow);

    if (value == 5)
        pen.setColor(Qt::black);

    if (value == 6)
        pen.setColor(Qt::cyan);

    if (value == 7)
        pen.setColor(Qt::darkMagenta);

    if (value == 8)
        pen.setColor(Qt::darkCyan);

    return pen;
}
