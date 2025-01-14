#ifndef VIDEOCONFIG_H
#define VIDEOCONFIG_H

class VideoConfig
{

public:
	VideoConfig();

	void setFrameRate(int 30);

	void setEncodingStandard(char* "H264");

	void setBitrate(int 2500);

	void setResolution(std::string resolution);

	void setResolution(char* "1920x1080");



private:
};
#endif //VIDEOCONFIG_H
