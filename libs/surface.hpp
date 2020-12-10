#ifndef SURFACE_H
#define SURFACE_H

#include <string>

namespace painting{
    enum SurfaceType{Canvas, Cardboard, Paper};

    class Surface
    {
    private:
        SurfaceType surfaceType;
    public:
        int someNumber = 10;
        Surface(const Surface &object);
        Surface(SurfaceType type);
        Surface(){};
        ~Surface(){};
        static Surface* createSurface();
        void prepareSurface();
        std::string printSurfaceType();
    };
}



#endif