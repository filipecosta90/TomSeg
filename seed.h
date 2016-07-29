#ifndef SEED_H
#define SEED_H

#include <opencv2/core/core.hpp>

#include "region.h"
#include "point.h"

static cv::RNG rng(12345);
static int nextId = 0;

class Seed : public Region
{
public:
    int id;
    float average, relativeStdDev;
    cv::Scalar color;

    Seed(cv::Mat& img, Point a, Point b): Region(img, a, b) {
        this->id = nextId++;
        this->average = this->getAverageIntensity();

        // if stdDev is lower than 1: relativeStdDev = 1; else: relativeStdDev = stdDev
        this->relativeStdDev = fmax( this->getStandardDeviation(this->average), 1.0f );
        this->color = cv::Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );

//        std::cout << "Average: " << this->average << std::endl;
//        std::cout << "StdDev.: " << this->stdDev << std::endl;
    }

    void draw(cv::Mat img) {

        cv::Point a( this->a.x, this->a.y );
        cv::Point b( this->b.x, this->b.y );

        cv::rectangle(img, a, b, this->color, 3);
    }
};

#endif // SEED_H
