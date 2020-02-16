import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    property int playerTurn: 1

    visible: true
    width: 700
    height: 800
    title: qsTr("Hello World")

    BoardView {
        id: boardView
        anchors.fill: parent
        anchors.topMargin: 100
        onColClicked: {
            console.info("Column ", col, " clicked!")
            console.log("Player ", playerTurn,
                        " tries to put chip on column ", col)
            //            console.debug(board.put(playerTurn, col));
            //            board.getMap1d()
            if (!board.put(playerTurn, col)) {
                console.debug("Position occupied.")
            } else {
                playerTurn = playerTurn % 2 + 1
            }

            refresh(board.getMap1d())
        }
    }
}
