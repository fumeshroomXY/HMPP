// VideoRecorder.cpp
void VideoRecorder::startRecording(TimeManager* time, std::string gps, 
    VideoConfig* videoConfig, PolicemanInfo info){

/* todo: 1. get current configuration  */

//todo: 2. start recording

//todo: 3. embed important metadata like timestamp and GPS info.

//todo: 4. encode video

}


// 1. get current configuration
{
    if (recording) { 
        std::cerr << "Error: Recording is already in progress." << std::endl;
        return;
    }
    // todo: 1.1 configure video settings

    std::string timestamp = time->getCurrentTimestamp(); 
    currentVideoFilePath = "video_" + timestamp + ".mp4"; 
}

// 1.1 configure video settings
{
    videoConfig.setFrameRate(30);
    videoConfig.setResolution("1920x1080");
    videoConfig.setEncodingStandard("H264"); 
    videoConfig.setBitrate(2500); 
}


// 2. start recording
{
    // todo: 2.1 open video file stream
    recording = true;
}

// 2.1 open video file
{
    videoFileStream.open(currentVideoFilePath, std::ios::binary);
    if (!videoFileStream.is_open()) {
        std::cerr << "Error: Failed to open video file for recording." << std::endl;
        return;
    }
}

// 3. embed important metadata like timestamp and GPS info.
{
    writeMetadataHeader(timestamp, gps);
}
 
// 4. encode video
{
    // todo: 4.1 simulate video frame writing
}


// 4.1 simulate video frame writing
{
    for (int i = 0; i < 150; ++i) {
    // todo: 4.1.1 simulate 5 seconds of video at 30 fps 
    }
}

// 4.1.1 simulate 5 seconds of video at 30 fps
{
    if (!recording) break;
    embedTimestampAndGPS();
    videoFileStream << "VideoFrameData";
    std::this_thread::sleep_for(std::chrono::milliseconds(33));
}