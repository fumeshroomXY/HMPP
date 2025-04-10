#include <string>
#include <fstream>

void VideoRecorder::writeMetadataHeader() {
    videoFileStream << "Metadata: \n";
    videoFileStream << "FrameRate: " << videoConfig.getFrameRate() << " fps\n";
    videoFileStream << "Resolution: " << videoConfig.getResolution() << "\n";
    videoFileStream << "Encoding: " << videoConfig.getEncodingStandard() << "\n";
    videoFileStream << "Bitrate: " << videoConfig.getBitrate() << " kbps";
    videoFileStream << "Timestamp: " << timeManager.getCurrentTimestamp() << "\n";
    std::cout << "Metadata header written to video file." << std::endl;
}

void VideoRecorder::embedTimestampAndGPS() {
    std::string timestamp = timeManager.getCurrentTimestamp();
    std::pair<double, double> gpsCoordinates = gpsModule.getCoordinates();

    videoFileStream << "Timestamp: " << timestamp << "\n";
    videoFileStream << "GPS Coordinates: [" << gpsCoordinates.first << " " << gpsCoordinates.second << "]\n";
}

void VideoRecorder::setupRecording() {
    int frameRate = videoConfig.getFrameRate();
    std::string resolution = videoConfig.getResolution();
    std::string encodingStandard = videoConfig.getEncodingStandard();
    int bitrate = videoConfig.getBitrate();

    std::cerr << "Setting up recording with Frame Rate: " << frameRate 
              << ", Resolution: " << resolution 
              << ", Encoding: " << encodingStandard
              << ", Bitrate: " << bitrate << " kbps" << std::endl;
}