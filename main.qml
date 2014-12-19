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
    color: "white"

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
        x: (root.width - width) / 2; y: 100;z:51;
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
            word.text = re.bd_get_word_name();
            dispresult.text = " ";

            var p = re.bd_get_part_num();
            var i,j;
            var hei = 15;
            for(i = 0; i < p; i++){
                var m = re.bd_get_means_num(i);
                dispresult.text += re.bd_get_parts(i) + " ";
                for(j = 0; j < m; j++){
                    if(m !== (j + 1))
                        dispresult.text += re.bd_get_means(i,j)  + ", ";
                    else
                        dispresult.text += re.bd_get_means(i,j);
                }
                dispresult.text += "<br>";
                //
            }

            dispresult.height = hei * (i) + 4*i + 8;
            dispresult.visible = true;
        }

    }

    Rectangle{
        x:0; z:50;y:input.y+ input.height;
        width: root.width; height: root.height - (input.y+ input.height);
        //color: "grey"

        Text {
            id: word
            x: input.x - 30; y:20; z: 51//y: input.y + input.height + 20;
            font.bold: true
            font.pixelSize: 30
            text: qsTr("")
            //anchors.centerIn: parent
        }

        Rectangle{
            id: line
            width: root.width - 20; height: 2;
            x: (root.width - width )/2; y: word.y + word.height + 10;
            color: "green"
        }

        DisplayArea{
            id: dispresult
            width: root.width - 20; height: 32;
            x: (root.width - width )/2; y: line.y + 15;

        }

        Text {
            id: result
            x: input.x - 30; y: input.y + 20;
            text: qsTr(" ")
            //anchors.centerIn: parent
        }
    }
}
