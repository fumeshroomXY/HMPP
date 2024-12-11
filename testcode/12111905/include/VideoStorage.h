#ifndef VIDEOSTORAGE_H
#define VIDEOSTORAGE_H

class VideoStorage
{

public:
	void generateEncryptedFileName(std::string& filePath);

	void write(std::string encryptedData);



private:
};
#endif //VIDEOSTORAGE_H
