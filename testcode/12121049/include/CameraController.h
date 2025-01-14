#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

class CameraController
{

public:
	CameraController();

	void setPoliceInfo(int id, std::string name, std::string department);

	void startRecording();

	void stopRecording();

	void encryptAndStoreVideo();

	void configureVideoSettings();

	void setPolicemanInfo(const UNSPECIFIED& value){ policemanInfo = value; }

	UNSPECIFIED getPolicemanInfo() const { return policemanInfo; }

	void setVideoConfig(const UNSPECIFIED& value){ videoConfig = value; }

	UNSPECIFIED getVideoConfig() const { return videoConfig; }



private:
	UNSPECIFIED policemanInfo;

	UNSPECIFIED videoConfig;

};
#endif //CAMERACONTROLLER_H
