import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Rectangle {
    id: root
    property alias gridHandle: gridLayout
    property alias repeaterHandle: repeater
    signal circleClicked(int index)

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
            id: repeater
            model: 42
            Rectangle {
                width: recSize
                height: recSize
                radius: width * 0.5
                color: "white"
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        circleClicked(index)
                    }
                }
            }
        }
    }
}
