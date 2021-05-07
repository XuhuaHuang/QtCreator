import QtQuick 2.15
import QtQuick.Controls 2.15
import QtGraphicalEffects 1.15

Button {
    id:goodOrBadBtn

    implicitWidth: 70
    implicitHeight: 60

    background: Rectangle {
        id:goodButton
        color: "#55aaff"

        Image {
            id: iconBtn
            source: "../images/good_button.svg"
            anchors.alignWhenCentered: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            height:25
            width:25
            fillMode: Image.PreserveAspectFit
        }

        ColorOverlay {
            anchors.fill: iconBtn
            source: iconBtn
            color: "#ffffff"
            antialiasing: false
        }
    }
}
