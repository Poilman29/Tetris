#include "tetrominoe.h"



Tetrominoe::Tetrominoe(TetrominoeType type, QObject *parent)
    : QObject{parent},type{type}
{
    position = QPoint(5,7);

    rotationState = 0;
    updateRelativeMatrix();
}


TetrominoeType Tetrominoe::getType() const
{
    return type;
}

void Tetrominoe::setType(TetrominoeType newType)
{
    type = newType;
}

int Tetrominoe::getRotationState() const
{
    return rotationState;
}

void Tetrominoe::setRotationState(int newRotationState)
{
    // qDebug() << "tetrominoe : " << static_cast<int>(this->getType()) << " rotate from " << this->getRotationState() << " to ";
    rotationState = newRotationState;
    updateRelativeMatrix();
}


QPoint Tetrominoe::getPosition() const
{
    return position;
}

bool Tetrominoe::setPosition(QPoint newPosition)
{
    if( (newPosition.x() > 20) && (newPosition.x() <0) ){
        //qInfo()  << " new Tetrominoe in x = " <<  newPosition.x() << " is not allowed" ;
        return false;
    }else if(newPosition.y() < 0){
        //qInfo()  << " new Tetrominoe in y = " <<  newPosition.y() << " is not allowed" ;
        return false;
    }
    position = newPosition;
    return true;
}


void Tetrominoe::updateRelativeMatrix()
{
    for (int i=0 ; i<4 ; i++){
        for (int j=0 ; j<4 ; j++){
            relativeMatrix[j][i].setIsVisible(false);
        }
    }

    switch(this->type){
    case TetrominoeType::I :
        switch(this->rotationState%2) {
        case 0:
            relativeMatrix[1][0].setBlock(true,true,type);
            relativeMatrix[1][1].setBlock(true,true,type);
            relativeMatrix[1][2].setBlock(true,true,type);
            relativeMatrix[1][3].setBlock(true,true,type);
            break;
        case 1:
            relativeMatrix[0][1].setBlock(true,true,type);
            relativeMatrix[1][1].setBlock(true,true,type);
            relativeMatrix[2][1].setBlock(true,true,type);
            relativeMatrix[3][1].setBlock(true,true,type);
            break;

        }
        break;
    case TetrominoeType::O :
        relativeMatrix[0][0].setBlock(true,true,type);
        relativeMatrix[1][0].setBlock(true,true,type);
        relativeMatrix[0][1].setBlock(true,true,type);
        relativeMatrix[1][1].setBlock(true,true,type);
        break;

    case TetrominoeType::T :
        switch(this->rotationState) {
        case 0:
            relativeMatrix[0][0].setBlock(true,true,type);
            relativeMatrix[0][1].setBlock(true,true,type);
            relativeMatrix[0][2].setBlock(true,true,type);
            relativeMatrix[1][1].setBlock(true,true,type);
            break;
        case 1:
            relativeMatrix[0][1].setBlock(true,true,type);
            relativeMatrix[1][0].setBlock(true,true,type);
            relativeMatrix[1][1].setBlock(true,true,type);
            relativeMatrix[2][1].setBlock(true,true,type);
            break;
        case 2:
            relativeMatrix[0][1].setBlock(true,true,type);
            relativeMatrix[1][0].setBlock(true,true,type);
            relativeMatrix[1][1].setBlock(true,true,type);
            relativeMatrix[1][2].setBlock(true,true,type);
            break;
        case 3:
            relativeMatrix[0][1].setBlock(true,true,type);
            relativeMatrix[1][1].setBlock(true,true,type);
            relativeMatrix[1][2].setBlock(true,true,type);
            relativeMatrix[2][1].setBlock(true,true,type);
            break;
        default:
            qInfo() << "TetrominoeType::O : False rotation type";
        }

        break;

    case TetrominoeType::L :

        switch(this->rotationState) {
        case 0:
            relativeMatrix[0][1].setBlock(true,true,type);
            relativeMatrix[0][2].setBlock(true,true,type);
            relativeMatrix[0][3].setBlock(true,true,type);
            relativeMatrix[1][1].setBlock(true,true,type);
            break;
        case 1:
            relativeMatrix[0][1].setBlock(true,true,type);
            relativeMatrix[0][2].setBlock(true,true,type);
            relativeMatrix[1][2].setBlock(true,true,type);
            relativeMatrix[2][2].setBlock(true,true,type);
            break;
        case 2:
            relativeMatrix[0][2].setBlock(true,true,type);
            relativeMatrix[1][0].setBlock(true,true,type);
            relativeMatrix[1][1].setBlock(true,true,type);
            relativeMatrix[1][2].setBlock(true,true,type);
            break;
        case 3:
            relativeMatrix[0][1].setBlock(true,true,type);
            relativeMatrix[1][1].setBlock(true,true,type);
            relativeMatrix[2][1].setBlock(true,true,type);
            relativeMatrix[2][2].setBlock(true,true,type);
            break;
        default:
            qInfo() << "TetrominoeType::L : False rotation type";
        }

        break;

    case TetrominoeType::J :

        break;

    case TetrominoeType::Z :

        break;
    case TetrominoeType::S :

        break;
    default:

        qInfo() << "Unknown Tetrominoe Type";
    }
}

