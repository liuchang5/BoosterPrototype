#ifndef LCLOG_H
#define LCLOG_H

#include <assert.h>
#include <qdebug.h>
#include <qstring.h>
#include <QFile>


#define LC_CHECK(Condition) \
do                          \
{                           \
    if (!Condition)         \
    {                       \
        qDebug()<<#Condition;\
        break;              \
    }                       \
}while(false)               \



bool LCLogInit();
bool LCLogUnint();
bool LCLogPrint(QString *qString);


#endif // LCLOG_H
