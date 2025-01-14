#include "VideoConfig.h"


/* todo:	write algorithms for VideoConfig
*/


bool CameraController::startRecording(){
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


void VideoConfig::getPolicemanInfo(){
/* todo:	VideoConfig::getPolicemanInfo
*/
}

