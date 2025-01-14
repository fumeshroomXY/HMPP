#include "PolicemanInfo.h"


/* todo:	write algorithms for PolicemanInfo
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


void PolicemanInfo::configureVideoSettings(){
/* todo:	PolicemanInfo::configureVideoSettings
*/
}

