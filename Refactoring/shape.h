#pragma once
#include <vector>

struct Point {
    int x, y, z;
};

class Shape {
public:
    enum Type { LINE, SQUARE, CUBE, CIRCLE, CYLINDER };

    Shape(Type t, const std::vector<Point>& points);
    Shape(Type t, const Point& p1, const Point& p2, const Point& p3, const Point& p4,
        const Point& p5, const Point& p6, const Point& p7, const Point& p8);
    Shape(Type t, const Point& center, double R, double H);

    virtual ~Shape() = default;

    Type getType() const { return type; }
    int getNumPoints() const { return points.size(); }
    const Point& operator[](int i) const { return points[i]; }
    Point& operator[](int i) { return points[i]; }
    double getVolume() const { return volume; }
    double getSquare() const { return square; }

    virtual void shift(int m, int n, int k);
    virtual void scaleX(int a);
    virtual void scaleY(int d);
    virtual void scaleZ(int e);
    virtual void scale(int s);

protected:
    Type type;
    std::vector<Point> points;
    double volume;
    double square;

    void calculateVolumeAndSquare();
};

class Line : public Shape {
public:
    Line(const Point& p1, const Point& p2);
};

class Rectangle : public Shape {
public:
    Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
};

class Circle : public Shape {
public:
    Circle(const Point& center, double R);
};

class Cylinder : public Shape {
public:
    Cylinder(const Point& center, double R, double H);
};

