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
    void execute();
};

void Main::execute(){
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

int main(){
    Main m1;
    //Main m(m1);  -- cannot be done since the copy constructor is private
    //Main m=m1; --cannot be done since the copy assignment cosntructor is private
    Main m;
    m.execute();
    return 0;
}