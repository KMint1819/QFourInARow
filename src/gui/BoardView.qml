import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Rectangle {
    id: root
    color: "#0000CA"
    property int recSize: 60
    GridView {
        id: gridView
        anchors.fill: parent
        model: boardModel
        flow: GridView.RightToLeft

        delegate: Piece {
            width: gridView.cellWidth - 5
            height: gridView.cellHeight - 5
            player: model.display
        }
    }
    Button {
        onClicked: {
        }
    }
}
