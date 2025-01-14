#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

class CameraController
{

public:
	void encryptAndStoreVideo(const std::string& filePath, std::string& videoData);

	void setVideoEncrypter(const VideoEncrypter& value){ videoEncrypter = value; }

	VideoEncrypter getVideoEncrypter() const { return videoEncrypter; }

	void setVideoStorage(const UNSPECIFIED& value){ videoStorage = value; }

	UNSPECIFIED getVideoStorage() const { return videoStorage; }



private:
	VideoEncrypter videoEncrypter;

	UNSPECIFIED videoStorage;

};
#endif //CAMERACONTROLLER_H
