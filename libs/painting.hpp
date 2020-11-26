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
        Painting(){price = 50; index = 10;};
        ~Painting(){};
        Painting& operator=(const Painting& pnt);
        Painting& operator+=(const Painting pnt);
        void paintThePainting();
        void printPainting();
    };
}

#endif
