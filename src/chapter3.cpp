#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//////////////////// RESIZE AND CROP IMAGES  ////////////////////

int main(){
    string path = "Resources/test.png";
    Mat img = imread(path); //Mat is a matrix data-type introduced by openCV to handle images
    Mat imgResize, imgCrop;

    cout << img.size() << std::endl;

    //resize(img,imgResize,Size(640,480)); // using a specific size will change the aspect ration
    resize(img,imgResize,Size(),0.5, 0.5); // this will scale the image and keep the same aspect ratio

    Rect roi(200,100,300,300); //x,y,width and height
    imgCrop = img(roi);

    imshow("Image",img);
    imshow("Image Resize",imgResize);
    imshow("Image Crop",imgCrop);

    waitKey(0);
    return 0;
}