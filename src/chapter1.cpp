#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//////////////////// IMPORTING IMAGES ////////////////////
// int main(){
//     string path = "Resources/glysa_pic.jpeg";
//     Mat img = imread(path); //Mat is a matrix data-type introduced by openCV to handle images
//     imshow("Image",img);
//     waitKey(0);
//     return 0;
// }


//////////////////// IMPORTING VIDEOS ////////////////////
// int main(){
//     string path = "Resources/test_video.mp4";
//     VideoCapture cap(path);
//     Mat img;

//     while(true){

//         cap.read(img);
//         imshow("Image",img);
//         waitKey(20);    
//     }
//     return 0;
// }

//////////////////// IMPORTING WEBCAM ////////////////////
int main(){


    VideoCapture cap(0); // Since I only have 1 camera on the Laptop, the ID is 0
    Mat img;


    while(true){

        cap.read(img);

        imshow("Image",img);
        waitKey(1);    
    }
    return 0;
}