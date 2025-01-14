#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

class CameraController
{

public:
	void setPoliceInfo(int id, std::string name, std::string department);

	void stopRecording();

	void encryptAndStoreVideo();

	bool startRecording();

	void configureVideoSettings();

	void getPolicemanInfo();

	void setPolicemanInfo(const PolicemanInfo& value){ policemanInfo = value; }

	void setVideoConfig(const VideoConfig*& value){ videoConfig = value; }

	VideoConfig* getVideoConfig() const { return videoConfig; }



private:
	PolicemanInfo policemanInfo;

	VideoConfig* videoConfig;

};
#endif //CAMERACONTROLLER_H
