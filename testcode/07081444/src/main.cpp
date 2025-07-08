#include <string>
#include <fstream>

int main() {
    int id = 101;
    std::string name = "Smith";
    std::string department = "Patrol";
    CameraController camera(timeManager, gpsModule);
    camera.setPoliceInfo(id, name, department);


    // Create configuration settings for 60fps, 1080p resolution, H264 encoding
    VideoConfig config;
    config.setFrameRate(60);
    config.setResolution("1920x1080");
    config.setEncodingStandard("H264");
    config.setBitrate(3000); 

    std::cout << "Initiating video recording..." << std::endl;
    cameraController.startRecording();

    std::this_thread::sleep_for(std::chrono::seconds(5));

    cameraController.stopRecording();
    std::cout << "Video recording process completed." << std::endl;
    camera.encryptAndStoreVideo();
    
    return 0;
}

class CameraController {
public:
    CameraController();
    void startRecording();
    void stopRecording();
    void encryptAndStoreVideo(const std::string& filePath, std::string& videoData);

private:
    TimeManager timeManager;
    GPSModule gpsModule;
    VideoRecorder videoRecorder;
    VideoConfig videoConfig;
    EncryptionModule encryptionModule;
    StorageManager storageManager;
    bool isRecording;
    
    void configureVideoSettings();
};

CameraController::CameraController(TimeManager& timeManager, GPSModule& gpsModule)
    : timeManager(timeManager), gpsModule(gpsModule), videoRecorder(nullptr) {}
    
void CameraController::setPoliceInfo(int id, std::string name, std::string department){
PolicemanInfo info(id, name, department);
    this->policemanInfo = info;
}


void CameraController::configureVideoSettings() {
    videoConfig.setFrameRate(30);                 // 30 fps
    videoConfig.setResolution("1920x1080");       // Full HD
    videoConfig.setEncodingStandard("H264");      // H.264 encoding
    videoConfig.setBitrate(2500);                 // 2500 kbps
}


void CameraController::startRecording() {
    configureVideoSettings();

    videoRecorder = std::make_unique<VideoRecorder>(timeManager, gpsModule, videoConfig);

    if (videoRecorder) {
        std::cout << "Starting video recording..." << std::endl;
        videoRecorder->startRecording();
        std::cout << "Recording started successfully." << std::endl;
    } else {
        std::cerr << "Error: VideoRecorder instance could not be created." << std::endl;
    }
}

void CameraController::stopRecording() {
    if (videoRecorder && videoRecorder->getCurrentVideoFilePath().empty() == false) {
        std::cout << "Stopping video recording..." << std::endl;
        videoRecorder->stopRecording();
        std::cout << "Recording stopped. File saved at: " << videoRecorder->getCurrentVideoFilePath() << std::endl;
    } else {
        std::cerr << "Error: No active recording to stop." << std::endl;
    }
}

void CameraController::encryptAndStoreVideo(const std::string& filePath, std::string& videoData){
    std::string encryptedData = this->encryptionModule.encrypt(videoData);

    std::string encryptedFilePath = this->storageManager.generateEncryptedFileName(filePath);

    this->storageManager.write(encryptedData);

}


class TimeManager {
public:
    TimeManager();
    std::string getCurrentTimestamp();
    void setTimeZone(const std::string& timeZone);
    std::string getTimeZone() const;

private:
    std::string currentTimeZone;
};

class GPSModule {
public:
    GPSModule();
    std::string getCurrentLocation();
    void updateGPSInfo();

private:
    double latitude;
    double longitude;
};


class VideoRecorder {
public:
    VideoRecorder(TimeManager& timeManager, GPSModule& gpsModule, const VideoConfig& config);
    
    void startRecording();
    void stopRecording();
    bool isRecording() const;
    void embedMetadata(const std::string& metadata);
    std::string getCurrentVideoFilePath() const;

private:
    TimeManager& timeManager;
    GPSModule& gpsModule;
    VideoConfig videoConfig;  // Configuration for the recording
    std::ofstream videoFile;
    std::string currentVideoFilePath;
    bool recording;

    void setupRecording();
    void writeMetadataHeader();
    void embedTimestampAndGPS();
};

VideoRecorder::VideoRecorder(TimeManager& timeManager, GPSModule& gpsModule, const VideoConfig& config)
    : timeManager(timeManager), gpsModule(gpsModule), videoConfig(config), recording(false) {}

VideoRecorder::~VideoRecorder() {
    if (recording) {
        stopRecording();
    }
}

void VideoRecorder::startRecording() {
    if (recording) {
        std::cerr << "Error: Recording is already in progress." << std::endl;
        return;
    }

    std::string timestamp = timeManager.getCurrentTimestamp();
    currentVideoFilePath = "video_" + timestamp + ".mp4";

    videoFileStream.open(currentVideoFilePath, std::ios::binary);
    if (!videoFileStream.is_open()) {
        std::cerr << "Error: Failed to open video file for recording." << std::endl;
        return;
    }

    writeMetadataHeader();

    recording = true;
    std::cout << "Recording started. Saving to: " << currentVideoFilePath << std::endl;

    for (int i = 0; i < 150; ++i) { 
        if (!recording) break; 
        embedTimestampAndGPS(); 
        videoFileStream << "VideoFrameData"; 
        std::this_thread::sleep_for(std::chrono::milliseconds(33)); // Simulate 30 fps (1000/30 ? 33 ms)
    }

}

void VideoRecorder::stopRecording() {
    if (!recording) {
        std::cerr << "Error: No ongoing recording to stop." << std::endl;
        return;
    }

    videoFileStream.close();
    recording = false;
    std::cout << "Recording stopped. File saved at: " << currentVideoFilePath << std::endl;
}