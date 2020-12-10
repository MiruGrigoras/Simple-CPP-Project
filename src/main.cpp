#include "../libs/surface.hpp"
#include "../libs/painter.hpp"
#include "../libs/paint.hpp"
#include "../libs/painting.hpp"
#include <iostream>
#include <memory>

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
    int someNumber  = 5;
    static Main* createMain(){return new Main();}
    void execute1();
    void execute2();
    void execute3();
};


int main(){
    //Main m;
    //Main m1;
    //Main m(m1);  -- cannot be done since the copy constructor is private
    //Main m=m1; --cannot be done since the copy assignment cosntructor is private
    //m.execute2();
    
    std::auto_ptr<Main> m(Main::createMain());
    std::cout << "Before copy constr for auto_ptr m: " << m->someNumber << " which is located: " << &m << '\n';
    std::auto_ptr<Main> m1(m);
    //std::cout << "After copy constr for auto_ptr m: " << m->someNumber << " which is located: " << &m << '\n';   --this wont work because the pointer is now null
    std::cout << "After copy constr for auto_ptr m1: " << m1->someNumber << " which is located: " << &m1<< '\n';
    m1->execute3();
    return 0;
}


void Main::execute3(){
	std::shared_ptr<Surface> s1(Surface::createSurface());
    std::cout << "Before copy constr for shared_ptr s1: " << s1->someNumber << " which is located: " << &s1 << '\n';
    std::shared_ptr<Surface> s2(s1);
    std::cout << "After copy constr for shared_ptr s1: " << s1->someNumber << " which is located: " << &s1 << '\n';
    std::cout << "After copy constr for shared_ptr s2: " << s2->someNumber << " which is located: " << &s2 << '\n';
    
}

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
    OilPaint op1("blue"), op3, *op4;

    std::cout<< "Op1: \n";
    op1.addExtender();
    op1.getColor();

    std::cout<< "\nOp2: \n";
    OilPaint op2(op1);
    op2.addExtender();
    op2.getColor();

    std::cout<< "\nOp3: \n";
    op3=op2;
    op3.addExtender();
    op3.getColor();
    
    Painting p1(0, canvas, op4, 100);
    Painting p2, p3, p4, p5;

    std::cout<< std::endl<< "P1 before assignation: " << &p1 << " " << p1.surface.printSurfaceType() << " " << p1.paint << " " << p1.price << " " << p1.index << std::endl;
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




