import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Rectangle {
    id: root
    signal colClicked(int col)
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
        id: clickableArea
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
                        colClicked(index + 1)
                    }
                }
            }
        }
    }
    function refresh(map1d) {
        console.log("Refreshing with", map1d)
        for (var i = 0; i < 42; ++i) {
            if (map1d[i] === 1) {
                chipRepeater.itemAt(i).color = "red"
            } else if (map1d[i] === 2) {
                chipRepeater.itemAt(i).color = "yellow"
            } else {
                chipRepeater.itemAt(i).color = "white"
            }
        }
    }
}
