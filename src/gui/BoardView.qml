import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Rectangle {
    id: root
    property alias gridHandle: gridLayout
    property alias repeaterHandle: chipRepeater
    property alias columnHandle: clickable
    signal colClicked(int index)

    //        border.width: 50
    //        border.color: "#FFF4C1"
    color: "#0000CA"
    property int recSize: 60
    Grid {
        id: gridLayout
        anchors.centerIn: parent
        columns: 7
        spacing: 25
        Repeater {
            id: chipRepeater
            model: 42
            Rectangle {
                width: recSize
                height: recSize
                radius: width * 0.5
                color: "white"
            }
        }
    }
    Row {
        id: clickable
        anchors.centerIn: parent
        Repeater {
            model: 7
            Rectangle {
                width: recSize + gridLayout.spacing
                height: root.height
                color: "transparent"
                border.color: "gray"
                border.width: 5

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        colClicked(index)
                    }
                }
            }
        }
    }
}
