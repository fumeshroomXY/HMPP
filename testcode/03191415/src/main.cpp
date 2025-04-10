void System::init() {
    int id = 101;
    std::string name = "Smith";
    std::string department = "Patrol";
    camera.setPoliceInfo(id, name, department);
}



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
