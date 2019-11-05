#include "opencv2/core.hpp" // FOr basic matrix manipulation
#include "opencv2/highgui.hpp" // for interface handling
#include "opencv2/opencv.hpp" // For geometric operation such as resize
#include <iostream>
#include <zmq.hpp>
#include "ConvertImage.h"

using namespace std;
using namespace cv;





int main(){

    VideoCapture vc;
    String videoFile = "<Image name/Camera Url>";
    
    vc.open(videoFile);
    ImagemConverter imc = ImagemConverter();
    for(;;){
        Mat mat;
        vc >> mat; // get a new frame from camera
        
        string encoded = imc.mat2str(mat);
        //cout<<encoded<<endl;
        //cout<<encoded.length()<<endl;
        
        zmq::context_t context (1);
        zmq::socket_t socket (context, ZMQ_REQ);
        std::cout << "Connecting to hello world server…" << std::endl;
        socket.connect ("tcp://localhost:5500");
        std::cout << "Connected" << std::endl;

        long long  int lenn =  encoded.length();

        zmq::message_t request (lenn);
        const void * a = encoded.c_str();
        memcpy (request.data(), a,lenn );
        socket.send(request);
        
        //break;
    }
    // Release the camera or video cap
    vc.release(); 

}
