#ifndef EMAFILTER_H
#define EMAFILTER_H

class EMAFilter
{
public:
    EMAFilter(double alpha) : alpha_(alpha), initialized_(false), lastValue_(0.0) {};

    void reInit(double alpha)
    {
        alpha_=alpha;
        initialized_=false;
        lastValue_=0.0;
    };

    double filter(double value)
    {
        if(!initialized_)
        {
            lastValue_ = value;
            initialized_ = true;
        }
        else
        {
            lastValue_ = alpha_ * value + (1-alpha_)* lastValue_;
        }
        return lastValue_;
    }
private:
    double alpha_;
    bool initialized_;
    double lastValue_;
};

#endif // EMAFILTER_H
