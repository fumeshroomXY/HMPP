#include "CameraController.h"


/* todo:	write algorithms for CameraController
*/


void CameraController::setPoliceInfo(int id, std::string name, std::string department){
/* todo:	CameraController::setPoliceInfo
*/

PolicemanInfo info(id, name, department);
this->policemanInfo = info;
}





bool CameraController::startRecording(){
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

void CameraController::stopRecording(){
/* todo:	CameraController::stopRecording
*/
}

void CameraController::encryptAndStoreVideo(){
/* todo:	CameraController::encryptAndStoreVideo
*/
}





void CameraController::configureVideoSettings(){
    VideoConfig* videoConfig = new VideoConfig();
    videoConfig.setFrameRate(30);
    videoConfig.setResolution("1920x1080");
    videoConfig.setEncodingStandard("H264"); 
    videoConfig.setBitrate(2500);  
this->videoConfig = videoConfig;     
}







void CameraController::getPolicemanInfo(){
/* todo:	CameraController::getPolicemanInfo
*/
}









