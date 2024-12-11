#include "VideoEncrypter.h"


/* todo:	write algorithms for VideoEncrypter
*/
void CameraController::encryptAndStoreVideo(const std::string& filePath, std::string& videoData){

    // Encrypt the video data
    std::string encryptedData = this->videoEncrypter.encrypt(videoData);

    // Generate encrypted file name
    std::string encryptedFilePath = this->videoStorage.generateEncryptedFileName(filePath);

    this->videoStorage.write(encryptedData);

}


