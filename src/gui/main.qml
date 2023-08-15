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
    Text {
        id: txtStatus
        property string orignalText: "Status: Progressing..."
        padding: pad
        font.pixelSize: 16
        text: orignalText
    }
    Button {
        id: btnClear
        anchors.right: parent.right
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
        }
    }

    BoardView {
        id: boardView
        anchors.fill: parent
        anchors.topMargin: 200
    }
}
