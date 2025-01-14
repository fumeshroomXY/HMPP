#include "CameraController.h"


/* todo:	write algorithms for CameraController
*/


CameraController::CameraController(){
/* todo:	CameraController::CameraController
*/
}

void CameraController::setPoliceInfo(int id, std::string name, std::string department){
PolicemanInfo info(id, name, department);
    this->policemanInfo = info;

}





void CameraController::startRecording(){
    this->configureVideoSettings();
VideoRecorder* videoRecorder = new VideoRecorder();
    if (videoRecorder) {
        videoRecorder->startRecording();
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



