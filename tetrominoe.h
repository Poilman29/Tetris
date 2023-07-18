#ifndef TETROMINOE_H
#define TETROMINOE_H

#include <QObject>
#include <QDebug>
//#include <QVector>
#include <QPoint>



//enum TetrominoeType{
//    I,O,T,L,J,Z,S,None
//};

//struct Block{

//    bool m_isVisible = false;
//    bool m_isCurrentTetrominoe = false;

//    TetrominoeType m_tetrominoType = None;

//public:
//    bool getIsVisible() const;
//    void setIsVisible(bool newIsVisible);

//    bool isCurrentTetrominoe() const;
//    void setIsCurrentTetrominoe(bool newIsCurrentTetrominoe);

//    void setBlock(bool isVisible, bool isCurrentTetrominoe);
//};

#include "block.h"


class Tetrominoe : public QObject
{
    Q_OBJECT

    TetrominoeType type;
    int rotationState ; // todo use char (only 4 states)
    QPoint position;

public:
    explicit Tetrominoe(TetrominoeType type, QObject *parent = nullptr);

    void updateRelativeMatrix();

    QPoint getPosition() const;
    bool setPosition(QPoint newPosition);

    int getRotationState() const;
    void setRotationState(int newRotationState);

    Block relativeMatrix[4][4];

    TetrominoeType getType() const;
    void setType(TetrominoeType newType);



    // TODO
    // bool relativeMatrixBool[4][4];
    // QList<Block> blockList;

    // bool moveTetrominoe(direction)


signals:

};

#endif // TETROMINOE_H
