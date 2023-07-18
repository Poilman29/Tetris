/**
 * MainView
 * @brief : The main view part of the MVC architecture
 * @author Olivier Wafflard
 * add new Up Button
 */


#include "mainview.h"
#include "ui_mainview.h"

MainView::MainView(MainModel *mainModel, QWidget *parent)
    : QWidget(parent),mainModel(mainModel)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    connect(mainModel,&MainModel::modelUpdated,this,&MainView::updateView);
}

MainView::~MainView()
{
    delete ui;
}

void MainView::updateView()
{
    //qInfo() << "updateView Called from modelUpdated";
    this->repaint();
}




void MainView::setBlockColor(QPainter &painter, Block &block)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    // qInfo() << "In set Color : tetrominoe type = " << block.tetrominoType();

    switch(block.tetrominoType()){
    case TetrominoeType::I :
        brush.setColor(Qt::cyan);
        painter.setBrush(brush);
        break;
    case TetrominoeType::O :
        brush.setColor(Qt::magenta);
        painter.setBrush(brush);
        break;

    case TetrominoeType::T :
        brush.setColor(Qt::yellow);
        painter.setBrush(brush);
        break;

    case TetrominoeType::L :
        // orange
        brush.setColor(QColor(245,173,66));
        painter.setBrush(brush);
        break;

    case TetrominoeType::J :
        brush.setColor(Qt::blue);
        painter.setBrush(brush);
        break;

    case TetrominoeType::Z :
        brush.setColor(Qt::green);
        painter.setBrush(brush);
        break;
    case TetrominoeType::S :
        brush.setColor(Qt::red);
        painter.setBrush(brush);
        break;
    default:
        brush.setColor(QColor(153,102,51,255));
        painter.setBrush(brush);
        qInfo() << "Unknown Tetrominoe Type";
    }
}

void MainView::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)

    //qInfo() << "paintEvent : " << QTime::currentTime().toString();
    int squareSize = 30;

    QPainter painter(this);

    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(2);

    painter.setPen(pen);

    QBrush brush(QColor(153,102,51,255));
    painter.setBrush(brush);

    // init

    for(int i=0 ; i<20 ; i++){
        for(int j=0 ; j<10 ; j++){
            if(mainModel->getBlock(j,i).getIsVisible()){
                setBlockColor(painter,mainModel->getBlock(j,i));
                painter.drawRect(QRect(20+(j*squareSize),20+(i*squareSize),squareSize,squareSize));
            }
        }
    }
}


void MainView::keyPressEvent(QKeyEvent *event)
{
    Tetrominoe* currentTetrominoe = this->mainModel->getTetrominoe();
    // int currentTetrominoeType = static_cast<int>(currentTetrominoe->getType());

    switch(event->key())
    {
    case Qt::Key_Left:
        this->mainModel->rotate(true);
        break;

    case Qt::Key_Right:
        this->mainModel->rotate(false);
        break;

    case Qt::Key_Down:
        this->mainModel->changeTetrominoeType();
        break;
    case Qt::Key_Up:
        this->mainModel->changeTetrominoeType();
        break;
    default :
        qDebug() << "Unknown key pressed" ;
    }
    updateView();
}
