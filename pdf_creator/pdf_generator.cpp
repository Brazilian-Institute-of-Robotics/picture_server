/* Copyright 2018 JIRo */

#include <pdf_generator.h>
#include <html_generator.h>

PdfGenerator::PdfGenerator() {
}

void PdfGenerator::createPdf(QString filename) {
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(QDir::homePath() + QDir::separator() +  filename);
    printer.setFullPage(true);

    //    QFile file("index.html");
    //    if (!file.open(QFile::ReadOnly | QFile::Text)) return;
    //    QTextStream in(&file);
    //    QString html = QString(in.readAll());

    QString html;
    html += HtmlGenerator::setHtmlStyle();
    html += HtmlGenerator::startBody();
    html += HtmlGenerator::addTitle("Visual Inspection Report for Rigid Riser", 3 , "center");

    html += HtmlGenerator::startTable(0, "100%");
    html += HtmlGenerator::addTableRow({"INSTALLATION:", "LOCATION:", "RISER NUMBER:", "DATE OF INSPECTION:"}, "th");
    html += HtmlGenerator::addTableRow({this->getInstallation(), this->getLocation(), QString::number(this->getRiserNumber()), this->getDate()}, "td");
    html += HtmlGenerator::endtable();

    html += HtmlGenerator::addLineBreak();
    html += HtmlGenerator::addTitle("FLEXJOINT COVER RUBBER", 3 , "center");

    html += HtmlGenerator::startTable(0, "100%");
    html += HtmlGenerator::addTableRow({HtmlGenerator::addImage(this->getImage(), NULL, "300") + HtmlGenerator::addLineBreak() + this->getComments()}, "td");
    html += HtmlGenerator::endtable();

    html += HtmlGenerator::addLineBreak();
    html += HtmlGenerator::startTable(0, "100%");
    html += HtmlGenerator::addCheckableTableRow(1, "Mechanical damage", this->getMechanicalDemage());
    html += HtmlGenerator::addCheckableTableRow(2, "Presence of scrap", this->getScrap());
    html += HtmlGenerator::addCheckableTableRow(3, "Loss of material", this->getLossMaterial());
    html += HtmlGenerator::addCheckableTableRow(4, "Bulge", this->getBulge());
    html += HtmlGenerator::addCheckableTableRow(5, "Extdusion", this->getExtrusion());
    html += HtmlGenerator::addCheckableTableRow(6, "Exposed metal", this->getExosedMetal());
    html += HtmlGenerator::addCheckableTableRow(7, "Cut", this->getCut());
    html += HtmlGenerator::addCheckableTableRow(8, "Gouge", this->getGouge());
    html += HtmlGenerator::addCheckableTableRow(9, "Crack", this->getCrack());
    html += HtmlGenerator::addCheckableTableRow(10, "Crazing", this->getCrazing());
    html += HtmlGenerator::endtable();

    html += HtmlGenerator::endBody();

    QTextDocument document;
    document.setHtml(html);
    document.setDefaultStyleSheet(html);
    document.print(&printer);
}

void PdfGenerator::setInstallation(QString installation) {
    this->installation_ = installation;
}

void PdfGenerator::setLocation(QString location) {
    this->location_ = location;
}

void PdfGenerator::setDate(QString date) {
    this->date_ = date;
}

void PdfGenerator::setImage(QString image) {
    this->image_ = image;
}

void PdfGenerator::setComments(QString comments) {
    this->comments_ = comments;
}

void PdfGenerator::setRiserNumber(int riser_number) {
    this->riser_number_ = riser_number;
}

void PdfGenerator::setScrap(int scrap) {
    this->scrap_ = scrap;
}

void PdfGenerator::setMechanicalDemage(int mechanical_demage) {
    this->mechanical_demage_ = mechanical_demage;
}

void PdfGenerator::setLossMaterial(int loss_material) {
    this->loss_material_ = loss_material;
}

void PdfGenerator::setCut(int cut) {
    this->cut_ = cut;
}

void PdfGenerator::setBulge(int bulge) {
    this->bulge_ = bulge;
}

void PdfGenerator::setGouge(int gouge) {
    this->gouge_ = gouge;
}

void PdfGenerator::setExtrusion(int extrusion) {
    this->extrusion_ = extrusion;
}

void PdfGenerator::setCrack(int crack) {
    this->crack_ = crack;
}

void PdfGenerator::setExosedMetal(int exosed_metal) {
    this->exosed_metal_ = exosed_metal;
}

void PdfGenerator::setCrazing(int crazing) {
    this->crazing_ = crazing;
}

QString PdfGenerator::getInstallation() {
    return this->installation_;
}

QString PdfGenerator::getLocation() {
    return this->location_;
}

QString PdfGenerator::getDate() {
    return this->date_;
}

QString PdfGenerator::getImage() {
    return this->image_;
}

QString PdfGenerator::getComments() {
    return this->comments_;
}

int PdfGenerator::getRiserNumber() {
    return this->riser_number_;
}

int PdfGenerator::getScrap() {
    return this->scrap_;
}

int PdfGenerator::getMechanicalDemage() {
    return this->mechanical_demage_;
}

int PdfGenerator::getLossMaterial() {
    return this->loss_material_;
}

int PdfGenerator::getCut() {
    return this->cut_;
}

int PdfGenerator::getBulge() {
    return this->bulge_;
}

int PdfGenerator::getGouge() {
    return this->gouge_;
}

int PdfGenerator::getExtrusion() {
    return this->extrusion_;
}

int PdfGenerator::getCrack() {
    return this->crack_;
}

int PdfGenerator::getExosedMetal() {
    return this->exosed_metal_;
}

int PdfGenerator::getCrazing() {
    return this->crazing_;
}
