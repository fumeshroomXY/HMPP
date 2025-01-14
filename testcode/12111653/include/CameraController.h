#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

class CameraController
{

public:
	void configureVideoSettings();

	void getPolicemanInfo();

	bool startRecording();

	void setConfigureVideoSettings(const UNSPECIFIED& value){ configureVideoSettings = value; }

	UNSPECIFIED getConfigureVideoSettings() const { return configureVideoSettings; }

	void setVideoConfig,(const UNSPECIFIED& value){ videoConfig, = value; }

	UNSPECIFIED getVideoConfig,() const { return videoConfig,; }

	void setGetPolicemanInfo(const UNSPECIFIED& value){ getPolicemanInfo = value; }

	UNSPECIFIED getGetPolicemanInfo() const { return getPolicemanInfo; }



private:
	UNSPECIFIED configureVideoSettings;

	UNSPECIFIED videoConfig,;

	UNSPECIFIED getPolicemanInfo;

};
#endif //CAMERACONTROLLER_H
