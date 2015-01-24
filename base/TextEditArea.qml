import QtQuick 2.0


Rectangle {
    id: input
    width: 240;height: 240;
    property alias inputtext: edit.text
    property alias readonly: edit.readOnly
    property alias format: edit.textFormat
    //property string inputimage: ""
    signal focusChanged
    signal enterChanged
    border.color : "#e2e5ea"
    border.width : 2
    //opacity: 0
    radius: 5
    clip: true
    Flickable {
         id: flick

         x:1;
         width: parent.width; height: parent.height;
         contentWidth: edit.paintedWidth
         contentHeight: edit.paintedHeight
         clip: true


         function ensureVisible(r)
         {
             if (contentX >= r.x)
                 contentX = r.x;
             else if (contentX+width <= r.x+r.width)
                 contentX = r.x+r.width-width;
             if (contentY >= r.y)
                 contentY = r.y;
             else if (contentY+height <= r.y+r.height)
                 contentY = r.y+r.height-height;
         }

         TextEdit {
             id: edit
             x:parent.x + 2;
             y:parent.y + 2;
             width: flick.width
             height: flick.height
             focus: true
             color: "#768194"
             selectionColor: "blue"
             selectByMouse: true
             cursorVisible: true

             //textFormat: TextEdit.RichText
             wrapMode: TextEdit.Wrap
             onCursorRectangleChanged: flick.ensureVisible(cursorRectangle)

             onFocusChanged: {
                 cursorVisible: true
                 input.focusChanged();
                 //input.border.color = "#e2e5ea"

             }
             onTextChanged: {
                 //console.log("text: " + text)
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
         }
     }
   /* TextEdit {
        id: input_area
        x: -4
        y: parent.height * 0.25
        width: parent.width
        height: parent.height
        color: "#768194"
        selectionColor: "blue"
        selectByMouse: true
        cursorVisible: true
        focus: true
        //wrapMode: TextInput.Wrap

        horizontalAlignment:TextInput.AlignRight
        font.pixelSize: parent.width > parent.height ? parent.height * .5:
                                                       parent.width * .5;

        onFocusChanged: {
            cursorVisible: true
            input.focusChanged();
            input.border.color = "#e2e5ea"
        }
        onTextChanged: {
            //console.log("text: " + text)
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

    }*/
}





