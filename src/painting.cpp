#include "../libs/painting.hpp"
#include "../libs/surface.hpp"
#include "../libs/paint.hpp"
#include <iostream>


namespace painting{
    Painting::Painting(int newIndex, Surface newSurface, Paint *newPaint, int newPrice)
    {
        index = newIndex;
        surface = newSurface;
        paint = newPaint;
        price = newPrice;
    }

    Painting::Painting(const Painting &object){}

    void Painting::paintThePainting(){
        surface.prepareSurface();
        paint->addExtender();
        std::cout << "Painting the painting. (Inception)" << std::endl;
    }

    void Painting::printPainting(){
        std::cout<< "Painting no. "<< this->index << " made on " << this->surface.printSurfaceType() << " which costs " << this->price << " euros" <<std::endl;
    }
}