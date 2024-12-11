#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

class CameraController
{

public:
	CameraController();

	void setPoliceInfo(int id, std::string name, std::string department);

	void stopRecording();

	void encryptAndStoreVideo();

	bool startRecording();

	void configureVideoSettings();

	void setPolicemanInfo(const PolicemanInfo& value){ policemanInfo = value; }

	PolicemanInfo getPolicemanInfo() const { return policemanInfo; }

	void setVideoConfig(const VideoConfig*& value){ videoConfig = value; }

	VideoConfig* getVideoConfig() const { return videoConfig; }



private:
	PolicemanInfo policemanInfo;

	VideoConfig* videoConfig;

};
#endif //CAMERACONTROLLER_H
