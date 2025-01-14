int main() {
    int id = 101;
    std::string name = "Smith";
    std::string department = "Patrol";
    CameraController camera();
    camera.setPoliceInfo(id, name, department);
	    // Start recording
    camera.startRecording();

    // Stop recording
    camera.stopRecording();

    // Encrypt and store the video
    camera.encryptAndStoreVideo();
    
    return 0;

}
