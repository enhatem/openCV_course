#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//////////////////// COLOR DETECTION ////////////////////
int main(){

    Mat imgHSV, mask;
    int hmin = 0, smin = 0, vmin = 0;   // values found earlier
    int hmax = 179, smax = 255, vmax = 255;  // values found earlier - A track bar will be created to directly change these values and find the color
    
    string path = "Resources/shapes.png";
    Mat img = imread(path); //Mat is a matrix data-type introduced by openCV to handle images
    
    // Converting the image to HSV (Hue Saturation Value) space because it will be much easier to find the color that way
    cvtColor(img, imgHSV, COLOR_BGR2HSV); 

    namedWindow("Trackbars",(640,200)); // created the window for trackbar
    createTrackbar("Hue Min", "Trackbars", &hmin, 179); // The maximum value for Hue is 180
    createTrackbar("Hue Max", "Trackbars", &hmax, 179); // The maximum value for Hue is 180
    createTrackbar("Sat Min", "Trackbars", &smin, 255); // The maximum value for Hue is 180
    createTrackbar("Sat Max", "Trackbars", &smax, 255); // The maximum value for Hue is 180
    createTrackbar("Val Min", "Trackbars", &vmin, 255); // The maximum value for Hue is 180
    createTrackbar("Val Max", "Trackbars", &vmax, 255); // The maximum value for Hue is 180

    while (true) { // When we create trackbars, we must use while loops

        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);

        // Once converted, we will use the inRange function to find the color 
        inRange(imgHSV, lower, upper, mask); // mask is out new image

        imshow("Image",img);
        imshow("Image HSV",imgHSV);
        imshow("Image Mask",mask);

        waitKey(1);
    }

    return 0; 
}
