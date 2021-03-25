import QtQuick 2.0

Rectangle {
    id: imageHolder
    property string holderName: "IMAGE NAME"
    property string holderSrc: ""
    property string output: "512x512"
    height: patternImage.height
    Image {
        id: patternImage
        source: holderSrc
        width: parent.width
        fillMode: Image.PreserveAspectFit
    }
    Text {
        text: appManager.appName
        fontSizeMode: Text.Fit
        minimumPixelSize: 10
        font.pixelSize: 72
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        width: parent.width
        height: logoImage.height / 4
        color: "black"
        font.bold: true
        anchors.bottom: logoImage.top
    }
    Image {
        id: logoImage
        source: "qrc:/Patterns/Logo512x512.png"
        width: parent.width / 4
        fillMode: Image.PreserveAspectFit
        anchors.centerIn: parent
    }
    Component.onCompleted: {
        imageHolder.grabToImage(function(result) {
            console.log(result.saveToFile(holderName + ".png"));
        },
        Qt.size(output.split("x")[0] * 1, output.split("x")[1] * 1));
    }
}
