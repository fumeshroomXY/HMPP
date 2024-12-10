#ifndef VIDEOCONFIG_H
#define VIDEOCONFIG_H

class VideoConfig
{

public:
	VideoConfig();

	void setResolution(char* "1920x1080");

	void setEncodingStandard(char* "H264");

	void setBitrate(int 2500);

	void setFrameRate(int frameRate);

	void setFrameRate(int 30);



private:
};
#endif //VIDEOCONFIG_H
