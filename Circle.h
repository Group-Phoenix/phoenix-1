//
// Created by linfeng wang on 04/05/2017.
//

#ifndef TASK100_CIRCLE_H
#define TASK100_CIRCLE_H

#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
using namespace cv;
using namespace std;
class Circle {
public:
    Circle(const Point& Cpoint,float r)
            :Center(Cpoint),CRadius(r)
    {}
    Point Circle_edge_point(Mat &img_, double angle);
    //void Circle_color(cv::Scalar c);
    void add_point(Point p);
    //void drawCircleAge(Circle c);
    void update();

private:
    vector<Point>points_;
    Mat img_;
    Point Center,p;
    float CRadius;


};


#endif //TASK100_CIRCLE_H


