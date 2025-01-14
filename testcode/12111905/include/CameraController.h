#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

class CameraController
{

public:
	void encryptAndStoreVideo(const std::string& filePath, std::string& videoData);

	void setVideoEncrypter(const VideoEncrypter& value){ videoEncrypter = value; }

	VideoEncrypter getVideoEncrypter() const { return videoEncrypter; }

	void setVideoStorage(const VideoStorage& value){ videoStorage = value; }

	VideoStorage getVideoStorage() const { return videoStorage; }



private:
	VideoEncrypter videoEncrypter;

	VideoStorage videoStorage;

};
#endif //CAMERACONTROLLER_H
