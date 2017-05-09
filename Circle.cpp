//
// Created by linfeng wang on 04/05/2017.
//
#include <iostream>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "Circle.h"
#include <math.h>
using namespace cv;
using namespace std;

Point Circle::Circle_edge_point( Mat &img, double angle)
{
   for(int a=0;a<100;a++)
    p.x=CRadius*cos(angle)+Center.x;
    p.y=CRadius*sin(angle)+Center.y;
    //cout<<"angle value is:"<<angle<<endl;
    this->img_=img;
    update();
    return p;
}
void Circle::add_point(Point p) {
    points_.push_back(p);
}
void Circle::update(){
    for (std::vector<Point>::iterator it = points_.begin();it != points_.end(); ++it)
    {   cout<<*it<<endl;
        //cout<<"vector size is:"<<points_.size()<<endl;
        circle(img_,*it,10,Scalar(255,0,0), -1);}
        // this is bleu circle;
}

