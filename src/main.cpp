#include "../libs/surface.hpp"
#include "../libs/painter.hpp"
#include "../libs/paint.hpp"
#include "../libs/painting.hpp"
#include <iostream>

using namespace painting;

int main(){

    Surface canvas(Canvas);
    Surface paper(Paper);
    Surface cardboard(Cardboard);
    AcrylicPaint *ap;
    OilPaint *op;
    WaterBasedPaint *wp;
    Painting p1(0, canvas, ap, 50);
    Painting p2(1, paper, op, 100);
    Painter painter;
    painter.addPaintings(p1);
    painter.addPaintings(p2);
    painter.addPaintings(cardboard, wp, 150);
    //p1.paintThePainting();
    //p2.paintThePainting();
    painter.printPaintings();
    painter.sellPainting(2);
    painter.printPaintings();
    return 0;
}