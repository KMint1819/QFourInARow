import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Rectangle {
    id: root
    color: "#0000CA"
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
                        console.log(`Clicked: ${index}`);
                        boardModel.onPut(index);
                    }
                }
            }
        }
    }
    Connections {
        target: boardModel
        onGameOver: winner => {
            console.log(`winner: ${winner}`);
        }
    }
}
