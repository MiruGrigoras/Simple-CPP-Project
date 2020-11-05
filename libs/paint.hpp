#ifndef PAINT_H
#define PAINT_H

namespace painting{

    class Paint
    {
    public:
        Paint(){};
        virtual ~Paint(){};
        virtual void addExtender() = 0;
    };

    class WaterBasedPaint: public Paint
    {
    public:
        WaterBasedPaint(){};
        WaterBasedPaint(const WaterBasedPaint &object);
        ~WaterBasedPaint(){};
        void addExtender();
    };

    class NonWaterBasedPaint: public Paint
    {
    public:
        NonWaterBasedPaint(){};
        NonWaterBasedPaint(const NonWaterBasedPaint &object);
        ~NonWaterBasedPaint(){};
        void addTopCoat();
    };

    class AcrylicPaint: public NonWaterBasedPaint
    {
    public:
        AcrylicPaint(){};
        AcrylicPaint(const AcrylicPaint &object); 
        ~AcrylicPaint(){};
        void addExtender();
    };

    class OilPaint: public NonWaterBasedPaint
    {
    public:
        OilPaint(){};
        OilPaint(const OilPaint &object);
        ~OilPaint(){};
        void addExtender();
    };
}


#endif