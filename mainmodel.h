#ifndef MAINMODEL_H
#define MAINMODEL_H

#include <QObject>
#include <QVector>
#include <QDebug>
#include <QTimer>
#include <ostream>
#include <math.h>

#include "tetrominoe.h"

class MainModel : public QObject
{
    Q_OBJECT
public:
    explicit MainModel(QObject *parent = nullptr);

    Block& getBlock(int x, int y);

    Tetrominoe *getTetrominoe() const;
    void setTetrominoe(Tetrominoe *newTetrominoe);

private :
    // QVector<QVector<Block*>> matrix;
    Block matrix[20][10];
    Tetrominoe* tetrominoe;

    QTimer timer;

public slots :
    void updateModel();
    void updateModelDebug();
    void timerDebug();
    void rotate(bool direction);
    void changeTetrominoeType();


signals:

    void modelUpdated();

};

#endif // MAINMODEL_H
