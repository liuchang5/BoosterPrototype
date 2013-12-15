#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPixmap>

class LCMainWidget : public QWidget
{
    Q_OBJECT

public:
    LCMainWidget(QWidget *parent = 0);
    ~LCMainWidget();

    bool Init();
    bool Uninit();

private:
    bool _InitAppearance();

};

#endif // MAINWIDGET_H
