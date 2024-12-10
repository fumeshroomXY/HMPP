int main() {
    int id = 101;
    std::string name = "Smith";
    std::string department = "Patrol";
	CameraController camera = CameraController();
    camera.setPoliceInfo(id, name, department);

    camera.startRecording();


    camera.stopRecording();


    camera.encryptAndStoreVideo();
    
    return 0;

}