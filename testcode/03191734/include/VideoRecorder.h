#ifndef VIDEORECORDER_H
#define VIDEORECORDER_H

class VideoRecorder
{

public:
	VideoRecorder();

	void startRecording(std::string time, std::string gps, VideoConfig* videoConfig, PolicemanInfo info);



private:
};
#endif //VIDEORECORDER_H
