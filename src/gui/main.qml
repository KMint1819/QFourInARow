import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    property int playerTurn: 0

    visible: true
    width: 700
    height: 800
    title: qsTr("Hello World")

    BoardView {
        id: board
        anchors.fill: parent
        anchors.topMargin: 100
        onCircleClicked: {
            console.log(index, " clicked!")
            var color_player = playerTurn ? "Red" : "Yellow"
            repeaterHandle.itemAt(index).color = color_player
            playerTurn = !playerTurn
        }
    }
}
