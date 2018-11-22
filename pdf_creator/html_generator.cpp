/* Copyright 2018 JIRo */

#include <QDebug>

#include <html_generator.h>

HtmlGenerator::HtmlGenerator() {
}


QString HtmlGenerator::setHtmlStyle() {
    return QString("<style type=\"text/css\">"
                    "table td, table th { font-size:small; text-align:center; padding:4px; }"
                    "table th {color:white; background-color:#0066cc; }"
                    "table th.attributes {background-color:#4d94ff; }"
                    "table th.checkable {text-align:left; color:black; background-color:#f2f2f2;} </style>");
}


QString HtmlGenerator::startBody() {
    return QString("<body>");
}


QString HtmlGenerator::endBody() {
    return QString("</body>");
}


QString HtmlGenerator::addLineBreak() {
    return QString("<br>");
}


QString HtmlGenerator::startTable(int border, QString width, QString height, QString bgcolor, QString cellspacing, QString cellpadding) {
    return QString("<table border=%1 width=\"%2\" height=\"%3\" bgcolor=\"%4\" cellspacing=\"%5\" cellpadding=\"%6\" >").arg(
                QString::number(border),
                width,
                height,
                bgcolor,
                cellspacing,
                cellpadding);
}


QString HtmlGenerator::endtable() {
    return QString("</table>");
}


QString HtmlGenerator::addTitle(QString title, int level, QString  align, QString dir) {
    return QString("<h%1 align=\"%2\" dir=\"%3\">%4</h%5>").arg(
                QString::number(level),
                align,
                dir,
                title,
                QString::number(level));
}


QString HtmlGenerator::addCheckableTableRow(int number, QString  title, bool checked) {
    return QString("<tr><td>%1</td><th class=attributes>%2</th><td>%3</td><th class=checkable>Yes</th><td>%4</td><th class=checkable>No</th></tr>").arg(
                QString::number(number),
                title,
                CHECK_MARK(checked),
                CHECK_MARK(!checked) );
}


QString HtmlGenerator::addTableRow(QStringList string_list, QString type_cell) {
    QString str("<tr>");

    for (int i = 0; i < string_list.size(); ++i) {
        str += QString("<%1> %2 </%3>").arg(
                    type_cell,
                    string_list.at(i),
                    type_cell);
    }

    str +=  "</tr>";
    return str;
}


QString HtmlGenerator::addImage(QString src, QString source, QString width, QString height) {
    return QString("<img src=\"%1\" source=\"%2\" width=\"%3\" height=\"%4\">").arg(
                src,
                source,
                width,
                height);
}
