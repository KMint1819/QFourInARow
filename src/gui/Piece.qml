import QtQuick 2.12
import QtQuick.Controls 2.12

Rectangle {
    id: root
    property var player: 0
    radius: width / 2

    color: {
        if (player == 1) {
            return "red";
        } else if (player == 2) {
            return "yellow";
        }
        return "white";
    }
}
