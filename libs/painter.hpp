
#define PAINTER_H

#include "../libs/painting.hpp"
#include <vector>

namespace painting{
    class Painter
    {
    private:
        int profits;
        int noOfPaintings;
        std::vector <Painting> paintingVector;
    public:
        Painter();
        Painter(const Painter &object);
        ~Painter(){};
        void addPaintings(Surface surface, Paint *paint, int price);
        void sellPainting(int i);
        void printPaintings();
        void addPaintings(Painting p);
    };
    
    
}

