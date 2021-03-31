import QtQuick 2.0
import QtGraphicalEffects 1.0

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
        opacity: appManager.noBackground ? 1 : 0
    }

    Image {
        id: logoImage
        source: "qrc:/Patterns/Logo512x512.png"
        width: patternImage.width / 4
        fillMode: Image.PreserveAspectFit
        anchors.centerIn: parent
    }
    function generateImage() {
        imageHolder.grabToImage(function(result) {
            console.log(result.saveToFile("out_" + holderName + ".png"));
        },
        Qt.size(output.split("x")[0] * 1, output.split("x")[1] * 1));
    }
}
