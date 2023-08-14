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
        delegate: Piece {
            width: gridView.cellWidth - 2
            height: gridView.cellHeight - 2
            player: model.display
        }
    }
    // Row {
    //     id: clickableArea
    //     anchors.centerIn: parent
    //     Repeater {
    //         model: 7
    //         Rectangle {
    //             width: recSize + gridLayout.spacing
    //             height: root.height
    //             color: "transparent"
    //             border.color: "gray"
    //             border.width: 5

    //             MouseArea {
    //                 anchors.fill: parent
    //                 onClicked: {
    //                     colClicked(index + 1);
    //                 }
    //             }
    //         }
    //     }
    // }
}
