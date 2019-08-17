/*
References:
[1]
http://doc.qt.io/qt-5/qml-tutorial2.html

*/

// FileDialog is a component. Normally the file name is the same as the name of component.[1]


import QtQuick 2.9 // Import QtQuick module.
import QtQuick.Dialogs 1.2

FileDialog
{
    id: fileDialog
    folder: shortcuts.music //"storage/emulated/0/Music"
    x: parent.x
    y: parent.y
    width: window.width
    height: window.height
    title: "Choose a file"
    onAccepted:
    {
    }
}
