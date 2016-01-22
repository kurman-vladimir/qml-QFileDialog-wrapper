import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import DialogsExtentions 1.0

ApplicationWindow {
    title: "File Save Dialog Sample"
    width: 640
    height: 480
    visible: true

    Text {
        id: resultedPathForSaving

        anchors.bottom: buttonShowDialog.top
        anchors.bottomMargin: 5
        anchors.horizontalCenter: buttonShowDialog.horizontalCenter
    }

    Rectangle {
        id: buttonShowDialog

        anchors.centerIn: parent

        color: "green"

        width: 50
        height: 50

        Text {
            anchors.centerIn: parent

            text: "Click me"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                fileSaveDialog.open()
            }
        }

        FileSaveDialog {
            id: fileSaveDialog
            title: "Select File"
            nameFilters: [ "Text files (*.txt)", "All files (*)" ]
            fileName: "default file name"
            onAccepted: {
                resultedPathForSaving.text = "File for saving is: " + fileSaveDialog.fileUrl
            }
            onRejected: {
                resultedPathForSaving.text = "Saving dialog was rejected"
            }
        }
    }
}
