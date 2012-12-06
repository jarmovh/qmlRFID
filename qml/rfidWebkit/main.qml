import QtQuick 2.0
import QtWebKit 3.0

Rectangle {
    width: 640
    height: 480

    Connections {
        target: qIf;
        onUiSetTagText: {
            rfidTagText.text = text
        }
    }

    Rectangle {
        width: parent.width
        height: parent.height
        color: "#BABABA"
        x: 0
        y: 96

        WebView {
            id: rfidWebView
            url: "http://www.google.com"
            anchors.fill: parent
        }
    }

    Rectangle {
        id: messageConsoleRect
        width: parent.width
        height: 197
        x: 0
        y: 0
        color: "#222222"
        opacity: 0.8
        border.color: "#005500"
        border.width: 2

        ListView {
            id: logMessageListView
            anchors.fill: parent
            model: logMessageModel
            delegate: Text {
                x: 10
                font.bold: true
                text: modelData
                color: "#FFFFFF"
            }
            snapMode: ListView.SnapOneItem
            onModelChanged: positionViewAtEnd()
        }

    }

}
