#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

class CameraController
{

public:
	bool startRecording();

	void encryptAndStoreVideo(const std::string& filePath, std::string& videoData);



private:
};
#endif //CAMERACONTROLLER_H
