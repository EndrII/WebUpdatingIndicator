#ifndef PAGECOMPARATOR_H
#define PAGECOMPARATOR_H

#include <QObject>
#include <QString>
#include <background.h>
#include <QSet>
#include <QVector>
#include <QStringList>
#include <newpagemodel.h>


class PageComparator : public QObject
{
    Q_OBJECT
public:
    static const int FlagCourceCode = 1<<0;
    static const int FlagInOneFrame = 1<<1;

    explicit PageComparator(int a,int b,Background * Bg,QObject *parent = 0);
    virtual ~PageComparator();
    Background * bg;
    int id_a, id_b;
    NewPageItem page_a, page_b;
    QString filePrefix;
    QString fileDirPrefix;
    QStringList data;
    QStringList data_f[2];
    QList<int> dataFile;
    QList<int> closeTag[2];
    int pageWriteiterator=0;
    QSet<QString> openFile;
    void setNewPrefix();
    QStringList parseData(QString in);
    QStringList loadFile(NewPageItem id);
    QString generateIframe(int id, int flags);
    QString generateCombinationIframe(int flags);
    void writeTagBlock(QString & out, int file, int b, int e, QString before, QString after);
    int genCloseTag(int p);
public slots:
    void generate(int flags);
    void open();
    void load();
    void calculatePages(int id_a,int id_b);
};

#endif // PAGECOMPARATOR_H
