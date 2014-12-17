import QtQuick 2.2
import QtQuick.Controls 1.1
import "base"
import Translate 1.0
import BaiduAPIDictResult 1.0

ApplicationWindow {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    InputArea{
        id: input
        width: 360; height: 40;
        x: (root.width - width) / 2;
        inputtext: "search"
        focus: true;

        onEnterChanged: {
            console.log(input.inputtext)
            dd.dictSendWord(input.inputtext, "en", "zh");

        }

    }

    Translate{
        id: dd
        result: BaiduAPIDictResult{
            id:re
        }

        onDataPostReady:{
            //console.log("test:"+ rtext)
            te.text = re.bd_get_means(0,0) ;
        }

    }

    Text {
        id: te
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }
}
