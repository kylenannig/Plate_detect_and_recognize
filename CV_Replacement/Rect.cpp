#include "CV_Replacement.h"

Rect::Rect(int xCoordinate1, int yCoordinate1, int xCoordinate2, int yCoordinate2){
    x1 = xCoordinate1;
    y1 = yCoordinate1;
    x2 = xCoordinate2;
    y2 = yCoordinate2;
}

Rect::Rect(Coordinate Coord1, Coordinate Coord2){
    x1 = Coord1.x;
    y1 = Coord1.y;
    x2 = Coord2.x;
    y2 = Coord2.y;
}

Rect::~Rect(){

}