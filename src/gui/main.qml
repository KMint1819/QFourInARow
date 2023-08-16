import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

ApplicationWindow {
    id: root
    property int pad: 15
    visible: true
    width: 700
    height: 800
    title: qsTr("Hello World")

    Rectangle {
        anchors.fill: parent
        color: "white"
    }
    Text {
        id: txtStatus
        property string orignalText: "hello"
        padding: pad
        font.pixelSize: 16
        color: "black"
        text: orignalText
    }
    Button {
        id: btnClear
        anchors.right: parent.right
        width: 150
        height: 80
        Text {
            text: "Restart"
            anchors.fill: parent
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 20
        }
        onClicked: {
            console.info('Clear clicked!');
            boardModel.onRestart();
            boardView.isGameOver = false;
        }
    }

    BoardView {
        id: boardView
        anchors.fill: parent
        anchors.topMargin: 200
    }
}
