// CameraController.cpp
bool CameraController::startRecording(){
     // Configure video settings
    this->configureVideoSettings();

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


void CameraController::setPoliceInfo(PoliceID id, std::string name, std::string department){
    PolicemanInfo info(id, name, department);
    this->policemanInfo = info;
}