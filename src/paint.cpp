#include "../libs/paint.hpp"
#include <iostream>
#include <string.h>

namespace painting{
    WaterBasedPaint::WaterBasedPaint(const WaterBasedPaint &object):Paint(object){};
    NonWaterBasedPaint::NonWaterBasedPaint(const NonWaterBasedPaint &object):Paint(object), extender(object.extender + "-copyConstr"){};
    AcrylicPaint::AcrylicPaint(const AcrylicPaint &object):NonWaterBasedPaint(object){};
    OilPaint::OilPaint(const OilPaint &object):NonWaterBasedPaint(object), color(object.color + "-copyConstr"){};

    void NonWaterBasedPaint::addTopCoat(){std::cout << "Finished with a varnish coat." << std::endl;}

    NonWaterBasedPaint& NonWaterBasedPaint::operator=(const NonWaterBasedPaint &nwbp){
        this->extender = nwbp.extender + "-copyAssign";
        return *this;
    }

    OilPaint& OilPaint::operator=(const OilPaint &op){
        NonWaterBasedPaint::operator=(op);
        this->color = op.color + "-copyAssign";
        return *this;
    }

}