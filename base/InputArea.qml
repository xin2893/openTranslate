import QtQuick 2.0

Rectangle {
    id: input

    property alias inputtext: input_area.text
    property alias echomode: input_area.echoMode
    //property string inputimage: ""
    signal focusChanged
    signal enterChanged
    border.color : "#e2e5ea"
    border.width : 2
    //opacity: 0
    radius: 5
    clip: true

    TextInput {
        id: input_area
        x: -4
        y: parent.height * 0.25
        width: parent.width
        height: parent.height
        color: "#768194"
        selectionColor: "blue"
        selectByMouse: true
        autoScroll: false
        cursorVisible: false
        //wrapMode: TextInput.Wrap
        //echoMode:
        maximumLength: 32
        horizontalAlignment:TextInput.AlignRight
        font.pixelSize: parent.width > parent.height ? parent.height * .5:
                                                       parent.width * .5;

        onFocusChanged: {
            cursorVisible: true
            input.focusChanged();
            //input.border.color = "#e2e5ea"
        }
        onTextChanged: {
            console.log("text: " + text)
        }
        onCursorVisibleChanged: {
            if(cursorVisible == true){
                //console.log("cursor true")
                border.color = "grey"
            }else{
                //console.log("cursor false")
                border.color = "#e2e5ea"
            }
        }
        onAccepted: {
            //console.log("fffff")
            input.enterChanged();
        }
    }
}
