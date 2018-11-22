/* Copyright 2018 JIRo */

#ifndef HTML_GENERATOR_H
#define HTML_GENERATOR_H

#include <QObject>

#ifndef CHECK_MARK
#define CHECK_MARK(x) (x ? "&#10004;" : "  ")
#endif

class HtmlGenerator {
public:
    HtmlGenerator();
    //static QString setAnchor(QString text, QString href = NULL, QString name = NULL);
    //static QString addAddress(QString address);
    //static QString setBoldFont(QString text);
    //static QString setLargerFont(QString text);
    //static QString startBlockquote();
    //static QString endBlockquote();
    static QString startBody();//QString bgcolor = NULL
    static QString endBody();
    static QString addLineBreak();
    //    static QString dd();
    //    static QString div();
    //    static QString dl();
    //    static QString dt();
    //    static QString font();
    //    static QString head();
    //    static QString hr();
    //    static QString i();
    //    static QString kbd();
    //    static QString meta();
    //    static QString li();
    //    static QString nobr();
    //    static QString ol();
    //    static QString p();
    //    static QString pre();
    //    static QString s();
    //    static QString small();
    //    static QString span();
    //    static QString style();
    //    static QString sub();
    //    static QString sup();
    //    static QString table();
    //    static QString td();
    //    static QString th();
    //    static QString thead();
    //    static QString title();
    //    static QString tr();
    //    static QString tt();
    //    static QString u();
    //    static QString ul();
    static QString addImage(QString src, QString source = NULL, QString width = NULL, QString height = NULL);

    static QString addTitle(QString title, int level, QString  align = NULL, QString dir = NULL);
    static QString setHtmlStyle();

    static QString startTable(int border, QString width = NULL, QString height = NULL, QString bgcolor = NULL, QString cellspacing = NULL, QString cellpadding = NULL);
    static QString endtable();

    static QString addTableRow(QStringList string_list, QString type_cell);

    static QString addCheckableTableRow(int number, QString  title, bool checked);
};

#endif  // HTML_GENERATOR_H
