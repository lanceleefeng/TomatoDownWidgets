
#include <QApplication>
#include <QMessageBox>


#include "init.h";
//#include "mainwindow.h"
#include "db.h"
#include "tomato.h"
#include "settingmodel.h"
//#include "testmodel.h"

static int uid = 1;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << "使用静态属性的name: " << Tomato::name;
    Init init;
    if(!init.succeed()){
        QMessageBox::critical(0, Tomato::name, QString("初始化失败"));
        //QMessageBox::critical(0, Tomato.name, QString("初始化失败"));
        //QMessageBox::critical(0, init.name, QString("初始化失败"));
        //QMessageBox::critical(0, name , QString("初始化失败"));
        return -1;
        //this->quit();

        //return;
    }

    BaseModel::uid = uid;

    Tomato w;
    if(!w.initiated){
        a.quit();
        return 10;
    }
    w.show();


    if(w.autoStart){
        w.startCountDown();
    }




    return a.exec();
}


