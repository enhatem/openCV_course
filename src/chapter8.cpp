#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp> // Allows us to work with haarcascade files
#include <iostream>

using namespace std;
using namespace cv;

//////////////////// FACE DETECTION ////////////////////

// int main(){
//     string path = "Resources/test.png";
//     Mat img = imread(path); //Mat is a matrix data-type introduced by openCV to handle images
    
//     CascadeClassifier faceCascade;
//     faceCascade.load("Resources/haarcascade_frontalface_default.xml");

//     if (faceCascade.empty()){cout << "XML file not loaded" << endl;}

//     vector<Rect> faces;
//     faceCascade.detectMultiScale(img, faces,1.1,10);

//     for (int i=0; i<faces.size(); i++)
//     {
//         rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3); // Drawing the bounding box using the rectangle - boundRect[i].tl(): calls the top left point - boundRect[i].br(): calls the bottom right point
//     }

//     imshow("Image",img);
//     waitKey(0);
//     return 0;
// }

int main(){
    // string path = "Resources/test.png";
    // Mat img = imread(path); //Mat is a matrix data-type introduced by openCV to handle images
    
    VideoCapture cap(0); // Since I only have 1 camera on the Laptop, the ID is 0
    Mat img;

    CascadeClassifier faceCascade;
    faceCascade.load("Resources/haarcascade_frontalface_default.xml");

    if (faceCascade.empty()){cout << "XML file not loaded" << endl;}

    vector<Rect> faces;

    while(true){

        cap.read(img);

        faceCascade.detectMultiScale(img, faces,1.1,10);

        for (int i=0; i<faces.size(); i++)
        {
            rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3); // Drawing the bounding box using the rectangle - boundRect[i].tl(): calls the top left point - boundRect[i].br(): calls the bottom right point
        }

        imshow("Image",img);
        waitKey(1);
    }
    return 0;
}