#include <QTextStream>
#include <qDebug>
#include <QTime>
#include <QDateTime>
#include <assert.h>
#include <QFile>

static QFile *g_pLogFile = NULL;

void _LCMessageHandler(
    QtMsgType type,
    const QMessageLogContext &context,
    const QString &msg
)
{
    QString TypeString;
    switch (type) {
    // Debug
    case QtDebugMsg:
        TypeString = QString("Debug:");
        break;

    // Warning
    case QtWarningMsg:
        TypeString = QString("Warning:");
        break;

    // Err
    case QtCriticalMsg:
        TypeString = QString("Critical:");
        break;

    // Faltal
    case QtFatalMsg:
        TypeString = QString("Fatal:");
        abort();
    }

    QString OutputString;
    OutputString = QString("%1 %2:%3:%4_%5:%6:%7 [%8][%9][%10]{msg:%11}")
            .arg(TypeString)

            .arg(QDateTime::currentDateTime().date().year())
            .arg(QDateTime::currentDateTime().date().month())
            .arg(QDateTime::currentDateTime().date().day())

            .arg(QDateTime::currentDateTime().time().hour())
            .arg(QDateTime::currentDateTime().time().minute())
            .arg(QDateTime::currentDateTime().time().second())

            .arg(QString::number(context.line))
            .arg(context.file)
            .arg(context.function)
            .arg(msg);


    QTextStream LogFileStream(g_pLogFile);
    LogFileStream << OutputString << endl;
    LogFileStream.flush();

    QTextStream StdoutStream(stdout);
    StdoutStream << OutputString << endl;
    StdoutStream.flush();
}


bool LCLogUnint()
{
    bool bRetCode = false;
    do
    {
        assert(g_pLogFile == NULL);
        if (g_pLogFile) break;

        g_pLogFile->close();
        bRetCode = true;
    }while(0);

    return bRetCode;
}


bool LCLogInit()
{
    bool bRetCode = false;

    do
    {
        assert(g_pLogFile == NULL);
        if (g_pLogFile) break;

        QString LogFileName;
        LogFileName = QString("%2_%3_%4_%5_%6_%7.LCLog")
                .arg(QDateTime::currentDateTime().date().year())
                .arg(QDateTime::currentDateTime().date().month())
                .arg(QDateTime::currentDateTime().date().day())

                .arg(QDateTime::currentDateTime().time().hour())
                .arg(QDateTime::currentDateTime().time().minute())
                .arg(QDateTime::currentDateTime().time().second());

        g_pLogFile = new QFile(LogFileName);
        bRetCode = g_pLogFile->open(QIODevice::WriteOnly | QIODevice::Append);

        assert(bRetCode);
        if (!bRetCode) break;

        // Register message handle.
        qInstallMessageHandler(_LCMessageHandler);

        bRetCode = true;
    }while(0);

    if (bRetCode)
        qDebug()<< "Init LC LOG Succeed";

    return bRetCode;
}
