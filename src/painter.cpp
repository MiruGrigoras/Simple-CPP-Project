#ifndef PAINTER_H
#define PAINTER_H

#include "../libs/painting.hpp"
#include "../libs/paint.hpp"
#include "../libs/surface.hpp"
#include "../libs/painter.hpp"
#include <vector>
#include <iostream>

namespace painting{

    Painter::Painter(): paintingVector({}),
    noOfPaintings(0),
    profits(0){ }

    Painter::Painter(const Painter &object): 
    paintingVector(object.paintingVector), 
    profits(object.profits),
    noOfPaintings(object.noOfPaintings){
    }

    void Painter::addPaintings(Painting p){
        std::cout<<"Adding paintings: " << p.index << " "<< p.surface.printSurfaceType() << " "<< p.paint << " "<< p.price<< std::endl;
        if(noOfPaintings < 10){
            paintingVector.push_back(p);
            noOfPaintings ++;
        }
        else{
            std::cout<< "You cannot add more paintings." <<std::endl;
        }
        
    }

    void Painter::addPaintings(Surface surface, Paint *paint, int price){
        std::cout<<price<<std::endl;
        if(noOfPaintings < 10){
            Painting p(noOfPaintings, surface, paint, price);
            paintingVector.push_back(p);
            noOfPaintings ++;
        }
        else{
            std::cout<< "You cannot add more paintings." <<std::endl;
        }
        
    }
    void Painter::sellPainting(int index){
        if(paintingVector.empty() == false ){
            std::vector<Painting>::iterator i;
            int count = 0;
            for (i = paintingVector.begin(); i!= paintingVector.end(); i++){
                if(count == index){
                    profits += i->price;
                    i = paintingVector.erase(i);
                    noOfPaintings--;
                    break;
                }
                else{
                    count++;
                }
            }
        }
        else{
            std::cout<< "There are no more paintings to sell." <<std::endl;
        }
    }

    void Painter::printPaintings(){
        std::cout << "The painter has " << this->noOfPaintings << " paintings and profits "<<this->profits<<std::endl;
        for (auto it: this->paintingVector){
            it.printPainting();
        }
    }
    
}

#endif