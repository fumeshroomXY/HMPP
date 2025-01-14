#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

class CameraController
{

public:
	void configureVideoSettings();

	bool startRecording();

	void getPolicemanInfo();

	void setVideoConfig(const VideoConfig*& value){ videoConfig = value; }

	VideoConfig* getVideoConfig() const { return videoConfig; }



private:
	VideoConfig* videoConfig;

};
#endif //CAMERACONTROLLER_H
