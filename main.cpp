
#include <iostream>
#include <string>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "opencv2/stitching.hpp"
#include <math.h>
#include "Circle.h"
using namespace cv;
using namespace std;

const double pi=3.14159265358;

struct data_struct{
    Mat* img;
    Circle * circle;
};
static void onChange(int pos,void* userinput);
//static void onMouse( int event, int x, int y, int, void* userInput);
int main() {
    //define a image;
    int pos=10;
    Point center_circle(400,400);
    Mat img(900,900,CV_8UC3,Scalar(255,255,255));
    cvNamedWindow("window",CV_WINDOW_AUTOSIZE);

    //instantiate an object of Circle
    Circle circle_o(center_circle,300.0);

    //instantiate an object of structure data
    data_struct data;
    data.circle=&circle_o;
    data.img=&img;

    createTrackbar("trackbar_circle","window",&pos,360,onChange,&data);
    circle(img, cv::Point( 400,400 ), 300.0, Scalar( 0, 0, 255 ), 1, 8 );
    // this is red circle
    imshow("window",img);

    cv::waitKey(0);
    cvDestroyWindow("window");
    return 0;
}
static void onChange(int current_position,void* userinput){
    //cast userinput to data_struct defined early;
    data_struct*data=(data_struct*)userinput;
    Mat image=data->img->clone();
    Circle *circle=data->circle;
    cout<<"current_position"<<current_position<<endl;

    Point p=circle->Circle_edge_point(image,((float)(current_position)/360)*2*pi);
    circle->add_point(p);
    cout<<"(current_position/360)*2*pi:="<<(current_position/360)*2*pi<<endl;
    // draw the point using a big circle;
    namedWindow("window");
    imshow("window",image);

}


