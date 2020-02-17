import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    id: root
    property int playerTurn: 1
    property int pad: 15
    visible: true
    width: 700
    height: 800
    title: qsTr("Hello World")
    Text {
        id: txtStatus
        property string orignalText: "Status: Progressing..."
        padding: pad
        font.pixelSize: 16
        text: orignalText
    }
    Text {

    }

    Button {
        id: btnClear
        //        padding: pad
        //        visible: false
        //        anchors.right: root.right
        anchors.right: parent.right
        Text {
            text: "Restart"
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 20
        }
        onClicked: {
            board.clear()
            console.log(txtStatus.orignalText)
            playerTurn = 1
            txtStatus.text = txtStatus.orignalText
            boardView.refresh(board.getMap1d())
        }
    }

    BoardView {
        id: boardView
        anchors.fill: parent
        anchors.topMargin: 100
        onColClicked: {
            console.info("Column ", col, " clicked!")
            if (board.getWinner() || board.getWinner() < 0) {
                console.log("Game over. Ignoring click...")
                return
            }

            console.log("Player ", playerTurn,
                        " tries to put chip on column ", col)
            if (!board.put(playerTurn, col)) {
                console.debug("Position occupied.")
            } else {
                playerTurn = playerTurn % 2 + 1
            }

            refresh(board.getMap1d())
            if (board.getWinner()) {
                var winnerName = board.getPlayerName()[board.getWinner()]
                console.log(winnerName + " won!")
                txtStatus.text = "Player " + winnerName + " won!!"
            } else if (board.getWinner() < 0) {
                console.log("Full!")
                txtStatus.text = "FULL!"
            }
        }
    }
}
