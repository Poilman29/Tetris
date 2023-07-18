#include "mainmodel.h"

MainModel::MainModel(QObject *parent)
    : QObject{parent}
{
    tetrominoe = new Tetrominoe(TetrominoeType::T,this);
    this->tetrominoe->setRotationState(0);
    this->updateModel();
    //updateModelDebug();

    // timer.setInterval(500);
    // connect(&timer,&QTimer::timeout,this,&MainModel::timerDebug);
    // timer.start();
}

Block& MainModel::getBlock(int x, int y)
{
    return matrix[y][x];
}

Tetrominoe *MainModel::getTetrominoe() const
{
    return tetrominoe;
}

void MainModel::setTetrominoe(Tetrominoe *newTetrominoe)
{
    tetrominoe = newTetrominoe;
}



void MainModel::updateModel()
{
    int x= tetrominoe->getPosition().x();
    int y= tetrominoe->getPosition().y();

    //qInfo() << "x = " << x << " y = " << y;

    // TODO check if we can move the Tetromino or not
    //bool checkIfPossible = true;


    // Update Area with new Tetrominoe
    for(int i=y ; i<y+4 ; i++){
        for(int j=x ; j<x+4 ; j++){
            if (matrix[i][j].getIsVisible() && !tetrominoe->relativeMatrix[i-y][j-x].getIsVisible()){
                matrix[i][j].setBlock(false,false,tetrominoe->getType());
            }
            if (!matrix[i][j].getIsVisible() && tetrominoe->relativeMatrix[i-y][j-x].getIsVisible()){
                matrix[i][j].setBlock(true,true,tetrominoe->getType());
            }
        }
    }

    emit modelUpdated();
}

void MainModel::updateModelDebug()
{

    for(int i=0 ; i<20 ; i++){
        for(int j=0 ; j<10 ; j++){
            matrix[i][j].setBlock(true,true,TetrominoeType::None);
        }
    }
}

void MainModel::timerDebug()
{
    rotate(this->tetrominoe->getRotationState());
}

void MainModel::rotate(bool direction)
{
    int rotationState = this->tetrominoe->getRotationState();
    direction ?  rotationState++ : rotationState--;
    rotationState = (rotationState % 4) ;

    if(rotationState < 0){
        rotationState = rotationState * (-1);
    }
    qDebug() << "MainModel : rotation state = " <<rotationState;
    this->tetrominoe->setRotationState(rotationState);

//    if(rotationState == 0){
//        QPoint position = this->tetrominoe->getPosition();
//        int y = position.y();
//        y++;
//        position.setY(y);
//        this->tetrominoe->setPosition(position);
//    }


    this->updateModel();
}



void MainModel::changeTetrominoeType()
{
    int tetrominoeType = this->getTetrominoe()->getType();
    tetrominoeType++;
    tetrominoeType = (tetrominoeType % 6) ;
    this->tetrominoe->setType(static_cast<TetrominoeType>(tetrominoeType));


    this->updateModel();
}



