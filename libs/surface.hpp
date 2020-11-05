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
        Surface(const Surface &object);
        Surface(SurfaceType type);
        Surface(){};
        ~Surface(){};
        void prepareSurface();
        std::string printSurfaceType();
    };
}



#endif