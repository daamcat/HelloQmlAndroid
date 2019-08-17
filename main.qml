// Complete QML document: import + object declarations.

import QtQuick 2.9 // Import QtQuick module.
import QtQuick.Window 2.2
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.2 // For fileDialog

// Importing Cpp classes using type namespace specified when using qmlRegisterType()
import CppClasses 1.0
import QtQuick.Layouts 1.0

// Import QML files in a folder


ApplicationWindow // Root object
{
    id: window
    width: 500
    height: 500
    visible: true
    color: "cyan"
    title: qsTr("Hello World")

    SwipeView
    {
        id: swipeView
        currentIndex: 1
        anchors.fill: parent
        Item
        {
            id: item1
            Rectangle
            {
                id: rectangle
                width : window.width - 20;
                height: window.height - 20;
                x: 10
                y: 10
                border.color: "yellow"
                border.width: 5
                GridLayout
                {
                    id: gridLayoutWindow
                    rows: 3
                    columns: 3

                    Button // Child of Window
                    {
                        id: button
                        width: Window.width/4
                        height: Window.height/4
                        Layout.row: 1
                        Layout.column: 1
                        text: qsTr("Push me!")
                        onClicked:
                        {
                            fileDialog.open()
                        }
                    }
                    TextInput // Child of Window
                    {
                        id: textInput
                        text: qsTr("Write something!")
                        Layout.row: 2
                        Layout.column: 1
                        horizontalAlignment: Text.AlignHCenter
                        selectionColor: "#efeff2"
                    }

                    Button // Child of Window
                    {
                        id: buttonCloseApp
                        Layout.row: 3
                        Layout.column: 1
                        text: qsTr("Close")
                        onClicked: Qt.quit()
                    }

                    Grid
                    {
                        id: colorPicker
                        x: 80
                        anchors.bottom: window.bottom
                        anchors.bottomMargin: 4
                        rows: 2
                        columns: 2
                        spacing: 3
                        Cell
                        {
                            cellColor: "red"; onClicked: window.color = cellColor
                        }
                        Cell
                        {
                            cellColor: "green"; onClicked: window.color = cellColor
                        }
                        Cell
                        {
                            cellColor: "blue"; onClicked: cameraP.open()
                        }

                        Cell
                        {
                            cellColor: "black"; onClicked: window.color = cellColor
                        }

                    }

                }
            }
        }
        Item
        {
            id: item2
            CameraPage
            {
                id: cameraP2
                x: rectangle.x
                y: rectangle.y
                width: rectangle.width
                height: rectangle.height
            }

        }
    }

    PageIndicator
    {
        id: pageIndicator
        count: swipeView.count
        currentIndex: swipeView.currentIndex
        anchors.bottom: swipeView.bottom
        anchors.horizontalCenter: parent.horizontalCenter

        delegate: Rectangle
        {
            implicitWidth: 120
            implicitHeight: 120
            radius: width/2
            color: "#21be2b"
            opacity: index === pageIndicator.currentIndex ? 0.95 : pressed ? 0.7 : 0.45
            Behavior on opacity
            {
                        OpacityAnimator
                        {
                            duration: 100
                        }
            }

        }
    }






    CameraPage
    {
        id: cameraP
        x: rectangle.x
        y: rectangle.y
        width: rectangle.width
        height: rectangle.height
    }

    FileDialog
    {
        id: fileDialog
        folder: shortcuts.documents
        onAccepted:
        {
            shoppingList.filePath=fileUrl;
            textInput.text=shoppingList.tableContent;
        }
    }

    ShoppingList
    {
        id: shoppingList
    }

    Item
    {
        property bool isCameraAvailable: QtMultimedia.availableCameras.length > 0
    }





}
