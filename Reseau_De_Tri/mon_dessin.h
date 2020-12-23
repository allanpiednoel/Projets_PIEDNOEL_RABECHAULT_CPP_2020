#ifndef MYSCENE_H
#define MYSCENE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsScene>

class Mon_dessin : public QGraphicsScene
{
public:
    Mon_dessin(QObject * parent = nullptr);
    QPen ChangeColor(int value);
};

#endif // MYSCENE_H
