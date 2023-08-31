#ifndef MOVINGAVERAGEFILTER_H
#define MOVINGAVERAGEFILTER_H

#include <vector>

class MovingAverageFilter
{
public:
    MovingAverageFilter(int windowSize) : windowSize_(windowSize), initialized_(false), sum_(0.0) {};

    void reInit(int windowSize)
    {
        windowSize_ = windowSize;
        initialized_ = false;
        sum_ = 0.0;
        buffer_.clear();
    };

    double filter(double value)
    {
        if (!initialized_) {
            buffer_.resize(windowSize_, value);
            sum_ = windowSize_ * value;
            initialized_ = true;
        } else {
            sum_ -= buffer_[currentIndex_];
            buffer_[currentIndex_] = value;
            sum_ += value;
            currentIndex_ = (currentIndex_ + 1) % windowSize_;
        }
        return sum_ / windowSize_;
    }

private:
    int windowSize_;
    bool initialized_;
    std::vector<double> buffer_;
    int currentIndex_ = 0;
    double sum_;
};

#endif // MOVINGAVERAGEFILTER_H
