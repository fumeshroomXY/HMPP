#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

class CameraController
{

public:
	void configureVideoSettings();

	void getPolicemanInfo();

	bool startRecording();

	void setVideoConfig(const UNSPECIFIED& value){ videoConfig = value; }

	UNSPECIFIED getVideoConfig() const { return videoConfig; }



private:
	UNSPECIFIED videoConfig;

};
#endif //CAMERACONTROLLER_H
