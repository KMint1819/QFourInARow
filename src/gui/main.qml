import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
//    visibility: "Maximized"
    width: 700
    height: 800
    title: qsTr("Hello World")
    BoardView {
        id: board
        anchors.fill: parent
        anchors.topMargin: 100
//        MouseArea{
//            anchors.fill:parent
//            onClicked: console.log(board.gridHandle.width)
//        }
    }
}
