#include "CameraController.h"


/* todo:	write algorithms for CameraController
*/


bool CameraController::startRecording(){
/* todo:	CameraController::startRecording
*/
}

void CameraController::encryptAndStoreVideo(const std::string& filePath, std::string& videoData) {

    // Encrypt the video data
	VideoEncrypter videoEncrypter();
    std::string encryptedData = videoEncrypter.encrypt(videoData);

    // Generate encrypted file name
	VideoStorage videoStorage();
    std::string encryptedFilePath = videoStorage.generateEncryptedFileName(filePath);

    videoStorage.write(encryptedData);
}




void CameraController::encryptAndStoreVideo(const std::string& filePath, std::string& videoData){
/* todo:	CameraController::encryptAndStoreVideo
*/
}







