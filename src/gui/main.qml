import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    property int playerTurn: 0

    visible: true
    width: 700
    height: 800
    title: qsTr("Hello World")

    signal putSignal(var column)

    BoardView {
        id: board
        anchors.fill: parent
        anchors.topMargin: 100
        onColClicked: {
            console.debug("Column ", index, " clicked!");
            putSignal(index);
        }
    }
}
