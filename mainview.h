#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QWidget>
#include <QPainter>
#include <QDebug>
#include <QTime>
#include <QKeyEvent>

#include "mainmodel.h"
#include "tetrominoe.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class MainView : public QWidget
{
    Q_OBJECT

    MainModel* mainModel;

public:
    MainView(MainModel* mainModel, QWidget *parent = nullptr);
    ~MainView();

private:
    Ui::Widget *ui;

    void setBlockColor(QPainter &painter, Block &block);

public slots:

    void updateView();

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event) override;

    // QWidget interface
protected:
    virtual void keyPressEvent(QKeyEvent *event) override;
};
#endif // MAINVIEW_H
