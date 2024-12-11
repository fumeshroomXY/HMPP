#ifndef VIDEOENCRYPTER_H
#define VIDEOENCRYPTER_H

class VideoEncrypter
{

public:
	void setVideoEncrypter(const UNSPECIFIED& value){ videoEncrypter = value; }

	UNSPECIFIED getVideoEncrypter() const { return videoEncrypter; }

	void setVideoStorage(const UNSPECIFIED& value){ videoStorage = value; }

	UNSPECIFIED getVideoStorage() const { return videoStorage; }



private:
	UNSPECIFIED videoEncrypter;

	UNSPECIFIED videoStorage;

};
#endif //VIDEOENCRYPTER_H
