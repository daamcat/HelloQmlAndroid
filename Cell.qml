import QtQuick 2.0

Item
{
    id: container
    property alias cellColor: rectangle.color
    signal clicked(color cellColor)

    width: 70
    height: 40

    Rectangle
    {
        id: rectangle
        border.color: "white"
        anchors.fill: parent
    }

    MultiPointTouchArea // Is an invisible item that is used to track multiple touch points.
    {
        maximumTouchPoints: 1
        anchors.fill: parent
        onReleased: container.clicked(container.cellColor)
    }

}
