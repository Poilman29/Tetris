/**
 * Tetris personal Project
 *
 * v0.2 : Rotate a particular Tetrominoe
 *
 * 2022/06/28
 *
 * Olivier Wafflard
 *
 * No Copyright
 *
 */



#include "mainview.h"
#include "mainmodel.h"

#include <QApplication>
#include <QScopedPointer>
#include <QDebug>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainModel model;
    MainView w(&model);
    w.show();
    return a.exec();
}
