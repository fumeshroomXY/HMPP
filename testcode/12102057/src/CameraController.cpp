#include "CameraController.h"


/* todo:	write algorithms for CameraController
*/
bool CameraController::startRecording(){
     // Configure video settings
    this->configureVideoSettings();
VideoRecorder* videoRecorder = new VideoRecorder();
    if (videoRecorder) {
        videoRecorder->startRecording();
return true;
    } else {
        return false;    
    }
}


void CameraController::configureVideoSettings(){
/* todo:	CameraController::configureVideoSettings
*/
}

bool CameraController::startRecording(){
/* todo:	CameraController::startRecording
*/
}

