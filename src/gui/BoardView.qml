import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Rectangle {
    id: root
    color: "#0000CA"
    property bool isGameOver: false
    GridView {
        id: gridView
        anchors.fill: parent
        model: boardModel
        cellWidth: gridView.width / 7
        cellHeight: gridView.height / 6
        verticalLayoutDirection: GridView.BottomToTop

        delegate: Piece {
            width: gridView.cellWidth - 8
            height: gridView.cellHeight - 8
            player: model.display
        }
    }
    RowLayout {
        anchors.fill: parent
        Repeater {
            model: 7
            Rectangle {
                Layout.fillHeight: true
                Layout.fillWidth: true
                color: "transparent"
                MouseArea {
                    id: mouseArea
                    anchors.fill: parent
                    onClicked: {
                        if (root.isGameOver) {
                            console.log("Game is over");
                            return;
                        }
                        console.log(`Clicked: ${index}`);
                        boardModel.onPut(index);
                    }
                }
            }
        }
    }
    Dialog {
        id: dialog
        modal: true // Make the dialog modal
        visible: false
        property int winner: 0

        width: 600
        height: 400

        Button {
            anchors.fill: parent
            background: Rectangle {
                color: "pink"
            }
            Text {
                anchors.centerIn: parent
                text: `${dialog.winner} wins. Click to restart.`
                color: "black"
                font.pixelSize: 18
            }
            onClicked: {
                boardModel.onRestart();
                dialog.close();
                root.isGameOver = false;
            }
        }
    }
    Connections {
        target: boardModel
        onGameOver: winner => {
            console.log(`winner: ${winner}`);
            dialog.winner = winner;
            dialog.open();
            isGameOver = true;
        }
    }
}
