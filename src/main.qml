import QtQuick
import QtQuick.Controls

import Core

ApplicationWindow {
    title: qsTr("Hello World")
    width: 1200; height: 720
    visible: true

    QmlImage {
        anchors.centerIn: parent
        width: 64; height: 64
    }
}
