#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

class CameraController
{

public:
	void encryptAndStoreVideo(const std::string& filePath, std::string& videoData);

	void setVideoEncrypter(const return& value){ videoEncrypter = value; }

	return getVideoEncrypter() const { return videoEncrypter; }

	void setVideoStorage(const return& value){ videoStorage = value; }

	return getVideoStorage() const { return videoStorage; }



private:
	return videoEncrypter;

	return videoStorage;

};
#endif //CAMERACONTROLLER_H
