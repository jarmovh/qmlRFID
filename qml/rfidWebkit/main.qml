import QtQuick 2.0

Rectangle {
    width: 360
    height: 360

    Connections {
        target: qIf;
        onUiSetTagText: {
            rfidTagText.text = text
        }
    }

    Rectangle {
        width: parent.width
        height: 64
        color: "#BABABA"
        x: 0
        y: 0
    }

    Rectangle {
        width: parent.width
        height: 32
        color: "#FFFFFF"
        x: 0
        y: 64

        Text {
            id: rfidTagText
            anchors {fill: parent}
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            text: "RFID TAG"
            font.pixelSize: 24
            font.bold: true
        }
    }

    Rectangle {
        width: parent.width
        height: 264
        color: "#BABABA"
        x: 0
        y: 96
    }
}
