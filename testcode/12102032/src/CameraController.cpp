#include "CameraController.h"


/* todo:	write algorithms for CameraController
*/
bool CameraController::startRecording() {
     // Configure video settings
    this->configureVideoSettings();
VideoRecorder* videoRecorder = new VideoRecorder();
    if (videoRecorder) {
TimeManager* timeManager = new TimeManager();
GpsInfo* gpsInfo = new GpsInfo();
std::string time = timeManager->getCurrentTimestamp();
std::string gps = gpsInfo->getCurrentLocation();
        videoRecorder->startRecording(time, gps, this->videoConfig);
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

