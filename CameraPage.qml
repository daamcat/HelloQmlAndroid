import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtMultimedia 5.9 // For accessing camera

Dialog
{
    id: cameraP
    VideoOutput
    {
        source: camera
        fillMode: VideoOutput.PreserveAspectFit
        autoOrientation: true
        anchors.fill: parent
        Camera
        {
            id: camera
            deviceId: QtMultimedia.availableCameras[0].deviceId
            position: Camera.FrontFace

            // Ref: https://stackoverflow.com/questions/26802962/qml-camera-focus-doesnt-work
            imageProcessing.whiteBalanceMode: CameraImageProcessing.WhiteBalanceFlash
            exposure
            {
                exposureMode: Camera.ExposureAuto
            }
            focus
            {
                focusMode: Camera.FocusContinuous
                focusPointMode: Camera.FocusContinuous
            }

        }
    }
    RoundButton
    {
        id: roundButtonSaveImage
        x: parent.x + parent.width/2 - 50
        y: parent.y + parent.height*(0.8)
        width: 100
        height: 100
        radius: 50
        onClicked: camera.imageCapture.capture()
    }
}

