#include "../libs/surface.hpp"
#include "../libs/painter.hpp"
#include "../libs/paint.hpp"
#include "../libs/painting.hpp"
#include <iostream>

using namespace painting;

class NoCopyItem
{
private:
   NoCopyItem(const NoCopyItem &);
   NoCopyItem& operator=(const NoCopyItem &);
public:
    NoCopyItem(){};
    ~NoCopyItem(){};
};

class Main : private NoCopyItem
{
private:
   Main(const Main &){};
   Main& operator=(const Main &);
public:
    Main(){};
    ~Main(){};
    void execute1();
    void execute2();
};

void Main::execute1(){
    Surface canvas(Canvas);
    Surface paper(Paper);
    Surface cardboard(Cardboard);
    AcrylicPaint *ap;
    OilPaint *op;
    WaterBasedPaint *wp;
    Painting p1(0, canvas, ap, 50); //creat cu constructorul special
    Painting p2(p1);  //creat cu copy constructor
    Painting p3(1, paper, op, 100);
    Painting p4(2, canvas, op, 200);
    Painting p5 = p4;  //creat cu assignment operator
    Painter painter;
    std::cout<<std::endl<< "Adding all the paintings: " << std::endl;
    painter.addPaintings(p2);
    painter.addPaintings(p3);
    painter.addPaintings(p5);
    painter.addPaintings(cardboard, wp, 150);

    std::cout<<std::endl<< "Painter's painting list: " << std::endl;
    painter.printPaintings();
    painter.sellPainting(2);


    std::cout<<std::endl<< "After selling painting no. 2: " << std::endl;
    painter.printPaintings();
    painter.sellPainting(0);

    std::cout<<std::endl<< "After selling painting no. 0: " << std::endl;
    painter.printPaintings();
}

void Main::execute2(){
    Surface canvas(Canvas);
    Surface paper(Paper);
    Surface cardboard(Cardboard);
    AcrylicPaint *ap;
    OilPaint *op;
    WaterBasedPaint *wp;
    
    Painting p1(0, canvas, op, 100);
    Painting p2, p3, p4, p5;

    std::cout<< "P1 before assignation: " << &p1 << " " << p1.surface.printSurfaceType() << " " << p1.paint << " " << p1.price << " " << p1.index << std::endl;
    std::cout<< "P2 before assignation: " << &p2 << " " << p2.surface.printSurfaceType() << " " << p2.paint << " " << p2.price << " " << p2.index << std::endl;
    std::cout<< "P3 before assignation: " << &p3 << " " << p3.surface.printSurfaceType() << " " << p3.paint << " " << p3.price << " " << p3.index << std::endl;
    p3 = p2 = p1;
    std::cout<< std::endl<< "P1 after 1st assignation: " << &p1 << " " << p1.surface.printSurfaceType() << " " << p1.paint << " " << p1.price << " " << p1.index << std::endl;
    std::cout<< "P2 after 1st assignation: " << &p2 << " " << p2.surface.printSurfaceType() << " " << p2.paint << " " << p2.price << " " << p2.index << std::endl;
    std::cout<< "P3 after 1st assignation: " << &p3 << " " << p3.surface.printSurfaceType() << " " << p3.paint << " " << p3.price << " " << p3.index << std::endl;
    
    p5 += p4 += p3;
    std::cout<< std::endl<< "P3 after 2nd assignation: " << &p3 << " " << p3.surface.printSurfaceType() << " " << p3.paint << " " << p3.price << " " << p3.index << std::endl;
    std::cout<< "P4 after 2nd assignation: " << &p4 << " " << p4.surface.printSurfaceType() << " " << p4.paint << " " << p4.price << " " << p4.index << std::endl;
    std::cout<< "P5 after 2nd assignation: " << &p5 << " " << p5.surface.printSurfaceType() << " " << p5.paint << " " << p5.price << " " << p5.index << std::endl;
    
    

}

int main(){
    Main m1;
    //Main m(m1);  -- cannot be done since the copy constructor is private
    //Main m=m1; --cannot be done since the copy assignment cosntructor is private
    Main m;
    m.execute2();
    return 0;
}