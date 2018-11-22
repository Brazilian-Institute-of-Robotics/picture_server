/* Copyright 2018 JIRo */

#ifndef PDF_GENERATOR_H
#define PDF_GENERATOR_H

#include <QObject>
#include <QtCore>
#include <QPrinter>
#include <QTextDocument>
#include <QDebug>

class PdfGenerator : public QObject {
    Q_OBJECT

public:
    PdfGenerator();
    Q_INVOKABLE void createPdf(QString filename);
    Q_INVOKABLE void setInstallation(QString installation);
    Q_INVOKABLE void setLocation(QString location);
    Q_INVOKABLE void setDate(QString date);
    Q_INVOKABLE void setImage(QString image);
    Q_INVOKABLE void setComments(QString comments);
    Q_INVOKABLE void setRiserNumber(int riser_number);
    Q_INVOKABLE void setScrap(int scrap);
    Q_INVOKABLE void setMechanicalDemage(int mechanical_demage);
    Q_INVOKABLE void setLossMaterial(int loss_material);
    Q_INVOKABLE void setCut(int cut);
    Q_INVOKABLE void setBulge(int bulge);
    Q_INVOKABLE void setGouge(int gouge);
    Q_INVOKABLE void setExtrusion(int extrusion);
    Q_INVOKABLE void setCrack(int crack);
    Q_INVOKABLE void setExosedMetal(int exosed_metal);
    Q_INVOKABLE void setCrazing(int crazing);


    QString createPdf();
    QString getInstallation();
    QString getLocation();
    QString getDate();
    QString getImage();
    QString getComments();
    int getRiserNumber();
    int getScrap();
    int getMechanicalDemage();
    int getLossMaterial();
    int getCut();
    int getBulge();
    int getGouge();
    int getExtrusion();
    int getCrack();
    int getExosedMetal();
    int getCrazing();

private:
    QString installation_;
    QString  location_;
    QString  date_;
    QString image_;
    QString comments_;
    int riser_number_;
    int occurrences_;
    int scrap_;
    int mechanical_demage_;
    int loss_material_;
    int cut_;
    int bulge_;
    int gouge_;
    int extrusion_;
    int crack_;
    int exosed_metal_;
    int crazing_;
};

#endif  // PDF_GENERATOR_H
