#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

class CameraController
{

public:
	void encryptAndStoreVideo(const std::string& filePath, std::string& videoData);

	void setVideoEncrypter(const UNSPECIFIED& value){ videoEncrypter = value; }

	UNSPECIFIED getVideoEncrypter() const { return videoEncrypter; }

	void setVideoStorage(const UNSPECIFIED& value){ videoStorage = value; }

	UNSPECIFIED getVideoStorage() const { return videoStorage; }



private:
	VideoEncrypter videoEncrypter;

	VideoStorage videoStorage;

};
#endif //CAMERACONTROLLER_H
