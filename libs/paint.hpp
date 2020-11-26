#ifndef PAINT_H
#define PAINT_H
#include <iostream>

namespace painting{

    class Paint
    {
    public:
        Paint(){};
        virtual ~Paint(){};
    };

    class WaterBasedPaint: public Paint
    {
    public:
        WaterBasedPaint(){};
        WaterBasedPaint(const WaterBasedPaint &object);
        ~WaterBasedPaint(){};
    };

    class NonWaterBasedPaint: public Paint
    {
    private:
        std::string extender;
    public:
        NonWaterBasedPaint():extender("Extender Paint Medium"){};
        NonWaterBasedPaint(const NonWaterBasedPaint &object);
        NonWaterBasedPaint& operator=(const NonWaterBasedPaint &nwbp);
        ~NonWaterBasedPaint(){};
        void addTopCoat();
        void addExtender(){std::cout<<"Added "<< extender << ".\n";};
    };

    class AcrylicPaint: public NonWaterBasedPaint
    {
    public:
        AcrylicPaint(){};
        AcrylicPaint(const AcrylicPaint &object); 
        ~AcrylicPaint(){};
    };

    class OilPaint: public NonWaterBasedPaint
    {
    private:
        std::string color;
    public:
        OilPaint(){};
        OilPaint(std::string mycolor):color(mycolor){};
        OilPaint& operator=(const OilPaint &op);
        OilPaint(const OilPaint &object);
        ~OilPaint(){};
        void getColor(){std::cout<<"Color: "<< color << ".\n";};
    };
}


#endif