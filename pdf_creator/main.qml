/* Copyright 2018 JIRo */

import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Controls 2.4
import QtQuick.Dialogs 1.2

Page {
  id: window1
  visible: true
  width: 900
  height: 800
  title: qsTr("Diver Visual Inspection Report for Rigid Riser")

  Text {
    y: 20
    anchors.horizontalCenter: parent.horizontalCenter
    text: qsTr("Report for the elastomer surface")
    font.pixelSize: 30
  }

  Rectangle {
    id: register
    x: 30
    y: 70
    width: 320
    height: 450
    border.width: 1

    Text {
      x: 10
      y: 10
      text: qsTr("Visual Inspection Report")
      font.bold: true
    }

    Text {
      x: 30
      y: 40
      text: qsTr("Installation:")
    }

    TextField {
      id: installation
      x: 120
      y: 34
      width: 160
      height: 30
    }

    Text {
      x: 30
      y: 80
      text: qsTr("Location:")
    }

    TextField {
      id: location
      x: 120
      y: 74
      width: 160
      height: 30
    }

    Text {
      x: 30
      y: 120
      text: qsTr("Riser number:")
    }

    SpinBox {
      id: riserNumber
      x: 130
      y: 110
      scale: 0.7
    }

    Text {
      x: 30
      y: 160
      text: qsTr("Date of inspection:")
    }

    Calendar {
      id: date
      locale: Qt.locale("en")
      x: 30
      y: 185
    }
  }

  Page {
    id: pictureView
    x: 375
    y: 70
    width: 500
    height: 450

    header: ToolBar {
      ToolButton {
        text: "Open Image"
        onPressed: fileDialog.open()
      }
    }

    Rectangle{
      anchors.fill: parent
      color: "#ffffff"
      radius: 1
      border.width: 1
    }

    FileDialog {
      id: fileDialog
      onAccepted: {
        image.source = fileDialog.fileUrl
      }
    }

    Image {
      id: image
      width: parent.width - 4
      anchors.centerIn: parent
      height: parent.height - 4
      fillMode: Image.PreserveAspectFit
    }
  }

  Text {
    x: 35
    y: 525
    width: 80
    height: 20
    text: qsTr("Occurrences:")
    font.bold: true
  }

  Rectangle{
    anchors.horizontalCenter: parent.horizontalCenter
    y: 552
    width: 840
    height: 80
    color: "#ffffff"
    radius: 1
    border.width: 1

    Grid {
      id: intens
      width: 840
      height: 80
      rows: 2
      columns: 5

      CheckBox {
        id: mechanicalDemage
        text: qsTr("Mechanical damage")
      }

      CheckBox {
        id: scrap
        text: qsTr("Presence of scrap")
      }


      CheckBox {
        id: lossMaterial
        text: qsTr("Loss of material")
      }

      CheckBox {
        id: cut
        text: qsTr("Cut")
      }

      CheckBox {
        id: bulge
        text: qsTr("Bulge")
      }

      CheckBox {
        id: gouge
        text: qsTr("Gouge")
      }

      CheckBox {
        id: extrusion
        text: qsTr("Extrusion")
      }

      CheckBox {
        id: crack
        text: qsTr("Crack")
      }

      CheckBox {
        id: exosedMetal
        text: qsTr("Exosed metal")
      }

      CheckBox {
        id: crazing
        text: qsTr("Crazing")
      }
    }
  }

  Text {
    x: 35
    y: 640
    width: 80
    height: 20
    text: qsTr("Comments:")
    font.bold: true
  }

  Rectangle{
    id: rect
    anchors.horizontalCenter: parent.horizontalCenter
    y: 664
    width: 840
    height: 80
    color: "#ffffff"
    radius: 1
    border.width: 1

    ScrollView {
      id: view
      anchors.fill: parent

      TextArea {
        id: comments
        height: view.height
        width: view.width
        placeholderText: "Type your comments here"
      }
    }
  }

  Button {
    id: createPdf
    x: 755
    y: 750
    width: 115
    height: 30
    text: qsTr("Create PDF")
    onClicked: {
      pdf.setInstallation(installation.text.toString());
      pdf.setLocation(location.text.toString());
      pdf.setDate(Qt.formatDateTime(date.selectedDate, "MMMM dd, yyyy"));
      pdf.setImage(image.source);
      pdf.setComments(comments.text.toString());
      pdf.setRiserNumber(riserNumber.value);
      pdf.setScrap(scrap.checkState);
      pdf.setMechanicalDemage(mechanicalDemage.checkState);
      pdf.setLossMaterial(lossMaterial.checkState);
      pdf.setCut(cut.checkState);
      pdf.setBulge(bulge.checkState);
      pdf.setGouge(gouge.checkState);
      pdf.setExtrusion(extrusion.checkState);
      pdf.setCrack(crack.checkState);
      pdf.setExosedMetal(exosedMetal.checkState);
      pdf.setCrazing(crazing.checkState);
      pdf.createPdf("Inspection Visual Report.pdf");
    }
  }
}
