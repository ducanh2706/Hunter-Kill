#ifndef _RECTANGLE__H
#define _RECTANGLE__H


class Rectangle {
public:
    double x, y;
    double u, v;
    double w, h;

    Rectangle();
    Rectangle(double _x, double _y, double _u, double _v);

    bool inMap(double _x, double _y) const;
};

#endif