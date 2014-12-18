import QtQuick 2.0

Rectangle {
    id: root
    width: 100
    height: 62
    x: 0;

    visible: false
    color: "#e2e5ea"

    property alias text: t.text
    //property alias text: t.text

    Text{
        id: t
        font.pixelSize: 15;
        x: 3; y: 4;
        textFormat: Text.RichText
    }
}
