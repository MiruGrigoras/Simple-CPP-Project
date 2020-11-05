#ifndef PAINTINGS_H
#define PAINTINGS_H

#include "../libs/surface.hpp"
#include "../libs/paint.hpp"

namespace painting{
    class Painting
    {
    public:

        Surface surface;
        Paint *paint;
        int price; 
        int index;
        Painting(int index, Surface newSurface, Paint *newPaint, int price);
        Painting(const Painting &object);
        ~Painting(){};
        void paintThePainting();
        void printPainting();
    };
}

#endif
