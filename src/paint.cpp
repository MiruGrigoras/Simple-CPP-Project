#include "../libs/paint.hpp"
#include <iostream>
#include <string.h>

namespace painting{
    WaterBasedPaint::WaterBasedPaint(const WaterBasedPaint &object):Paint(object){};
    NonWaterBasedPaint::NonWaterBasedPaint(const NonWaterBasedPaint &object):Paint(object), extender(object.extender){};
    AcrylicPaint::AcrylicPaint(const AcrylicPaint &object):NonWaterBasedPaint(object){};
    OilPaint::OilPaint(const OilPaint &object):NonWaterBasedPaint(object), color(object.color){};

    void NonWaterBasedPaint::addTopCoat(){std::cout << "Finished with a varnish coat." << std::endl;}

    NonWaterBasedPaint& NonWaterBasedPaint::operator=(const NonWaterBasedPaint &nwbp){
        NonWaterBasedPaint temp(nwbp);
        this->extender = temp.extender;
        return *this;
    }

    OilPaint& OilPaint::operator=(const OilPaint &op){
        OilPaint temp(op);
        NonWaterBasedPaint::operator=(temp);
        this->color = temp.color;
        return *this;
    }

}