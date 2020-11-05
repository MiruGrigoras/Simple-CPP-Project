#include "../libs/paint.hpp"
#include <iostream>

namespace painting{
    WaterBasedPaint::WaterBasedPaint(const WaterBasedPaint &object):Paint(object){};
    NonWaterBasedPaint::NonWaterBasedPaint(const NonWaterBasedPaint &object):Paint(object){};
    AcrylicPaint::AcrylicPaint(const AcrylicPaint &object):NonWaterBasedPaint(object){};
    OilPaint::OilPaint(const OilPaint &object):NonWaterBasedPaint(object){};

    void WaterBasedPaint::addExtender(){std::cout << "Added water." << std::endl;}
    void AcrylicPaint::addExtender(){std::cout << "Added Extender Paint Medium." << std::endl;}
    void OilPaint::addExtender(){std::cout << "Added canola oil." << std::endl;}
    void NonWaterBasedPaint::addTopCoat(){std::cout << "Finished with a varnish coat." << std::endl;}
}