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


    //menu
    Rectangle{
        x:0;y:0;z:102; width: root.width;height: 40;
        opacity: 0
        MouseArea{
            id:tm_mouse
            hoverEnabled: true
            anchors.fill: parent
            onEntered: {
                //console.log("d")
                topmenu.state = "display";
            }
            onExited: {
                //console.log("exit")
                topmenu.state = "hidden";
            }
        }
    }

    Rectangle{
        id:topmenu
        x:0;y:-40;z:103;
        width: root.width;height: 40;
        color: "green";

        Rectangle{
            id: dictory
            x:parent.width /2 - 80;
            //y:10;
            width: 40;height: parent.height ;
            color: "green"
            //opacity: 0.1
            gradient:Gradient {
                GradientStop { position: 0.0; color: "green" }
                GradientStop { position: 1.0; color: "green" }
            }

            Text {
                y:8;
                font.pixelSize: topmenu.height / 2;
                text: qsTr("词典")
            }
            MouseArea{
                anchors.fill: parent;
                onClicked: {
                    tran.visible = true;
                    tr.visible = false;
                    dd.setDictoryFlag();

                }
                onPressed: {
                    parent.gradient.stops[0].color = "white";
                }

                onReleased: {
                    parent.gradient.stops[0].color = "green";
                }
            }
        }
        Rectangle{
            id: transl
            x:parent.width /2 + 80;
            //y:10;
            width: 40;height: parent.height;
            color: "green"
            //opacity: 0.1
            gradient:Gradient {
                GradientStop { position: 0.0; color: "green" }
                GradientStop { position: 1.0; color: "green" }
            }
            Text {
                y:8;
                font.pixelSize: topmenu.height / 2;
                text: qsTr("翻译")
            }
            MouseArea{
                anchors.fill: parent;
                onClicked: {
                    tran.visible = false;
                    tr.visible = true;
                    dd.setTranslateFlag();
                }
                onPressed: {
                    parent.gradient.stops[0].color = "white";
                }

                onReleased: {
                    parent.gradient.stops[0].color = "green";
                }
            }
        }

        states: [
            State {
                name: "display"; //when: tm_mouse.pressed
                PropertyChanges { target: topmenu; x: 0; y: 0 }
            },
            State {
                name: "hidden";
                PropertyChanges { target: topmenu; x: 0; y: -40 }
            }
        ]
        transitions: [
            Transition {
                NumberAnimation { properties: "x,y"; easing.type: Easing.InOutQuad }
                from: "display"; to: "hidden"

            },
            Transition {
                from: "hidden"
                to: "display"
                NumberAnimation { properties: "x,y"; easing.type: Easing.InOutQuad }
            }
        ]
    }


    menuBar: MenuBar {
        Menu {
            title: qsTr("File")
            MenuItem {
                text: qsTr("Exit")
                onTriggered: Qt.quit();
            }
        }
    }

    //dictory
    Rectangle {
        id:tran
        x:0;y:0;
        width: root.width;height: root.height;
        //opacity: 0

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

        Rectangle{
            id: trans_display
            x:0; z:50;y:input.y+ input.height;
            width: root.width; height: root.height - (input.y+ input.height);
            //color: "grey"

            Text {
                id: word
                x: input.x - 30; y:20; z: 51//y: input.y + input.height + 20;
                font.bold: true
                font.pixelSize: 30
                text: qsTr("")
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

    //translate
    Rectangle{
        id:tr
        x:0;y:0;z:50;
        width: root.width;height: root.height;
        focus: true;
        visible: false;
        TextEditArea{
            id:trinput
            width: 480;height: 160;
            x:(root.width - width )/2 -20 ;y:50;

        }
        Rectangle{
            id: trbtn
            x:trinput.x + trinput.width + 10; y:trinput.y
            width: 50; height: trinput.height;
            color: "green"
            MouseArea{
                anchors.fill: parent;
                onClicked: {
                    //console.log("dddd")
                    //troutput.inputtext = trinput.inputtext;
                    dd.transSendParagraph(trinput.inputtext, "en", "zh");
                }
            }
        }

        Rectangle{
            id: trdisp
            x:0; y: trinput.y + trinput.height + 20;z:51;
            width: root.width; height: root.height;
            //color: "grey"


            Rectangle{
                id: trline
                width: root.width - 20; height: 2;
                x: (root.width - width )/2; y: 10 ;z:52;
                color: "green"
            }

            TextEditArea{
                id:troutput
                width: 480;height: 160;
                x:(root.width - width )/2  ;y:50;
                readonly: true
                format: TextEdit.RichText
            }
        }
    }

    Translate{
        id: dd
        result: BaiduAPIDictResult{
            id:re

        }

        onDataPostReady:{
            //console.log("test:"+ rtext)
            if(!dd.checkTrFlag()){
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
            }else{
                console.log("get trans");
                var tnum = re.get_trans_num();
                console.log("tnum: " + tnum)
                var j = 0;
                for (j = 0; j < tnum; j++){
                    troutput.inputtext = "src: ";
                    troutput.inputtext += re.get_trans_src(j);
                    troutput.inputtext += "<br>dst: "
                    troutput.inputtext += re.get_trans_dst(j);
                }
            }
        }

    }


}
