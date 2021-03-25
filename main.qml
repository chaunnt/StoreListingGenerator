import QtQuick 2.9
import QtQuick.Controls 2.2

ApplicationWindow {
    id: window
    visible: true
    width: 640
    height: 480
    title: qsTr("Stack")
    property string patternName: "Pattern1"
    ListModel {
        id: imageModeList
    }
    Component.onCompleted: {
        updateImageModelList()
    }
    function updateImageModelList() {
        imageModeList.clear()
        imageModeList.append({
                                 imageSrc: "qrc:/Patterns/" + patternName + "/Daydream3604096x4096.png",
                                 imageName: "Daydream3604096x4096",
                                 outputSize:"4096x4096"
                             })
        imageModeList.append({
                                 imageSrc: "qrc:/Patterns/" + patternName + "/FeatureGraphic1024x500.png",
                                 imageName: "FeatureGraphic1024x500",
                                 outputSize:"1024x500"
                             })
        imageModeList.append({
                                 imageSrc: "qrc:/Patterns/" + patternName + "/PromoGraphic180x120.png",
                                 imageName: "PromoGraphic180x120",
                                 outputSize:"180x120"
                             })
        imageModeList.append({
                                 imageSrc: "qrc:/Patterns/" + patternName + "/ScreenShot1600x900.png",
                                 imageName: "ScreenShot1600x900",
                                 outputSize:"1600x900"
                             })
        imageModeList.append({
                                 imageSrc: "qrc:/Patterns/" + patternName + "/TVBanner1280x720.png",
                                 imageName: "TVBanner1280x720",
                                 outputSize:"1280x720"
                             })
        console.log(imageModeList.length)
    }

    Row {
        width: parent.width
        spacing: 5
        Column {
            id: colInfo
            width: parent.width / 2
            height: implicitHeight
            spacing: 10
            TextField {
                id: txtPatternName
                width: 200
                height: 40
                x: parent.width / 2 - width / 2
                placeholderText: "Pattern name"
                text: patternName
            }
            TextField{
                width: 200
                height: 40
                x: parent.width / 2 - width / 2
                placeholderText: "App name"
                onTextChanged: {
                    appManager.appName = text
                }
            }
            TextField{
                width: 200
                height: 40
                x: parent.width / 2 - width / 2
                placeholderText: "Slogan 1"
                onTextChanged: {
                    appManager.appName = text
                }
            }
            TextField{
                width: 200
                height: 40
                x: parent.width / 2 - width / 2
                placeholderText: "Slogan 2"
                onTextChanged: {
                    appManager.appName = text
                }
            }
            TextField{
                width: 200
                height: 40
                x: parent.width / 2 - width / 2
                placeholderText: "Slogan 3"
                onTextChanged: {
                    appManager.appName = text
                }
            }
            TextField{
                width: 200
                height: 40
                x: parent.width / 2 - width / 2
                placeholderText: "Slogan 4"
                onTextChanged: {
                    appManager.appName = text
                }
            }
            Button{
                id:btnView
                width: 100
                height: 40
                text: qsTr("View")
                onClicked: {
                    patternName = txtPatternName.text
                    updateImageModelList()
                }
            }
            Button{
                id:btnGen
                width: 100
                height: 40
                text: qsTr("Generate")
                onClicked: {
                    appManager.generateAndroidStoreImages()
                }
            }
        }
        Rectangle {
            height: window.height
            width: 1
            color: "lightgray"
        }

        Flickable {
            width: 300
            height: 600
            contentHeight: colPreviewAndroid.implicitHeight * 1.2
            Column {
                id: colPreviewAndroid
                width: 300
                height: implicitHeight
                spacing: 20
                Text {
                    text: qsTr("Android Marketing")
                }
                Repeater {
                    id: rptImgList
                    model: imageModeList
                    delegate: Item {
                        width: 300
                        height: image.height + txtName.height + 20
                        Text {
                            id: txtName
                            text: qsTr(imageName)
                        }
                        PromotionImage {
                            id: image
                            holderSrc: imageSrc
                            holderName: imageName
                            output: outputSize
                            width: parent.width
                            anchors.top: txtName.bottom
                            anchors.topMargin: 5
                        }
                        Rectangle {
                            width: parent.width / 2
                            height: 2
                            color: "lightgray"
                            anchors.horizontalCenter: parent.horizontalCenter
                            anchors.bottom: parent.bottom
                        }
                    }
                }
            }
        }
    }
}
