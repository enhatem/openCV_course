#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//////////////////// DRAW SHAPES AND TEXT  ////////////////////

int main(){

    // Blank Image
    Mat img(512,512, CV_8UC3, Scalar(255,255,255)); // creating a blank image with width and height = 512 pixels.
                               // 8 bit so each pixel can have a value between 0 and 255 (if unsigned). If it is signed, it will be from -127 to 127. And, 
                               // C3: 3 channels (BGR: Blue, Green, Red)
                               // Scalar: defines the color of the image
    
    // circle(img,Point(256,256),155,Scalar(0,69,255),10); // Circle with center (256,256), radius of 155 and thickness of 10
    circle(img, Point(256,256), 155, Scalar(0,69,255), FILLED); // Filled circle
    rectangle(img, Point(130,226), Point(382,286), Scalar(255, 255, 255), FILLED); // Instead of Point (for upper left) and Point (for lower right), we could have used the Rect object type just like we did in chapter 3, but in that case we would have to write the width and the height instead
    line(img, Point(130,296), Point(382,296), Scalar(255, 255, 255),2);

    putText(img,"Murtaza's Workshop", Point(137,262), FONT_HERSHEY_DUPLEX, 0.75, Scalar(0, 69, 255), 2);

    imshow("Image",img);


    waitKey(0);
    return 0;
}