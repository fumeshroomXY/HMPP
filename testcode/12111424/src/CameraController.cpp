#include "CameraController.h"


/* todo:	write algorithms for CameraController
*/

bool CameraController::startRecording() {
     // Configure video settings
    configureVideoSettings();

    VideoRecorder* videoRecorder = new VideoRecorder();
    if (videoRecorder) {
TimeManager* timeManager = new TimeManager();
GpsInfo* gpsInfo = new GpsInfo();
std::string time = timeManager->getCurrentTimestamp();
std::string gps = gpsInfo->getCurrentLocation();
        videoRecorder->startRecording(time, gps, this->videoConfig, this->getPolicemanInfo());
return true;
    } else {
        return false;    
    }

}



void CameraController::getPolicemanInfo(){
/* todo:	CameraController::getPolicemanInfo
*/
}

bool CameraController::startRecording(){
/* todo:	CameraController::startRecording
*/
}

