#include "../libs/painting.hpp"
#include "../libs/surface.hpp"
#include "../libs/paint.hpp"
#include <iostream>


namespace painting{
    Painting::Painting(int newIndex, Surface newSurface, Paint *newPaint, int newPrice):
    index(newIndex),
    price(newPrice),
    surface(newSurface),
    paint(newPaint)
    {
        //std::cout<<"Painting creation with custom constructor: " << newIndex << " "<< newSurface.printSurfaceType() << " "<< newPaint << " "<< newPrice<< std::endl;
    }


    Painting::Painting(const Painting &object):
        surface(object.surface),
        paint(object.paint),
        price(object.price),
        index(object.index){
            //std::cout<<"Painting creation with copy constructor: " << object.index << " "<< surface.printSurfaceType() << " "<< object.paint << " "<< object.price<< std::endl;
        }

    void Painting::paintThePainting(){
        surface.prepareSurface();
        paint->addExtender();
        std::cout << "Painting the painting. (Inception)" << std::endl;
    }

    void Painting::printPainting(){
        std::cout<< "Painting no. "<< this->index << " made on " << this->surface.printSurfaceType() << " which costs " << this->price << " euros" <<std::endl;
    }
}