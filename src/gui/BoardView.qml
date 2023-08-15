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
        flow: GridView.BottomToTop
        cellWidth: gridView.width / 7
        cellHeight: gridView.height / 6

        delegate: Piece {
            width: gridView.cellWidth - 5
            height: gridView.cellHeight - 5
            player: model.display
        }
    }
    Button {
        onClicked: {
            console.log(`gridView size: ${gridView.width}x${gridView.height}`);
        }
    }
}
