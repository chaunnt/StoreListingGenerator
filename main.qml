import QtQuick 2.9
import QtQuick.Controls 2.2

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Stack")
    TextField{
        width: 200
        height: 40
        anchors.bottom: btnGen.top
        anchors.bottomMargin: 10
        x: parent.width / 2 - width / 2
        placeholderText: "App name"
        onTextChanged: {
            appManager.appName = text
        }
    }

    Button{
        id:btnGen
        width: 100
        height: 40
        anchors.centerIn: parent
        text: qsTr("Generate")
        onClicked: {
            appManager.generateAndroidStoreImages()
        }
    }
}
