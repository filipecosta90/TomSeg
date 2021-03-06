#ifndef SLICE_H
#define SLICE_H

#include "seed.h"

#include <vector>

class Slice
{
public:
    Slice();
    Slice(std::string filename);
    cv::Mat &getImg();
    void getHistogram(int histogram[]);
    void setSegmentationResult(cv::Mat& segmentationResult);
    void resetSegmentationResult();
    cv::Mat& getSegmentationResult();
    std::string getFilename();
    void setSeeds(const std::vector<Seed> &seeds );
    void addSeed(const Seed seed);
    void resetSeeds();
    int seedsNumber();
    std::vector<Seed> &getSeeds();
    bool containsSeedWithId(int seedId);
    void removeSeed(int seedPos);
    void crop(Point a, size_t width, size_t height);
    cv::Rect getRoiFromOriginal() const;

protected:
    cv::Mat img;
    cv::Mat segmentationResult;
    std::string filename;
    cv::Rect roiFromOriginal;
    std::vector<Seed> seeds;
};

#endif // SLICE_H
