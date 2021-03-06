#include "LCMainWidget.h"
#include <assert.h>
#include <QPalette>
#include <QApplication>
#include <QScreen>
#include "LCLog.h"

LCMainWidget::LCMainWidget(QWidget *parent)
    : QWidget(parent)
{

}

LCMainWidget::~LCMainWidget()
{

}

bool LCMainWidget::Init()
{
    bool bRetCode = false;
    do
    {
        bRetCode = _InitAppearance();
        bRetCode = false;
        LC_CHECK(bRetCode);
        // if (!bRetCode) break;


        //bRetCode = _InitSignal();



        bRetCode = true;
    }while(0);

    return bRetCode;
}

bool LCMainWidget::Uninit()
{
    bool bRetCode = false;

    do
    {


        bRetCode = true;
    }while(0);

    return bRetCode;
}



bool LCMainWidget::_InitAppearance()
{
    int bRetCode = false;

    do
    {
        QPixmap  BGPixmap;
        QPalette MainWidgetPalette;

        // Load Backgroud Pixmap
        bRetCode = BGPixmap.load(
            "d:\\OpenSource\\MyGithub\\BoosterPrototype\\BoosterPrototype\\frame.png"
        );
        if(!bRetCode) break;

        // Set window style
        this->setWindowOpacity(1);
        //this->setAttribute(Qt::WA_TranslucentBackground);
        this->setWindowFlags(Qt::FramelessWindowHint);


        // Set main widget size
        this->setGeometry(BGPixmap.rect());

        // Set main widget pos
        int nScreenWidth  = QApplication::primaryScreen()->geometry().width();
        int nScreenHeight = QApplication::primaryScreen()->geometry().height();
        this->move(nScreenWidth/2 - width()/2, nScreenHeight/2 - height()/2);

        // Set backgound
        MainWidgetPalette.setBrush(
            backgroundRole(),
            QBrush(BGPixmap)
        );

        setPalette(MainWidgetPalette);

        bRetCode = true;
    }while(0);

    return bRetCode;
}

