#define _USE_MATH_DEFINES
#include "shape.h"
#include <cmath>

Shape::Shape(Type t, const std::vector<Point>& pts) : type(t), points(pts) {
    calculateVolumeAndSquare();
}

Shape::Shape(Type t, const Point& p1, const Point& p2, const Point& p3, const Point& p4,
    const Point& p5, const Point& p6, const Point& p7, const Point& p8) : type(t) {
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);
    points.push_back(p5);
    points.push_back(p6);
    points.push_back(p7);
    points.push_back(p8);
    calculateVolumeAndSquare();
}

Shape::Shape(Type t, const Point& center, double R, double H) : type(t) {
    points.push_back(center);
    if (t == CIRCLE || t == CYLINDER) {
        points[0].z = 0;
    }
    if (t == CYLINDER) {
        Point top_center = { center.x, center.y, H };
        points.push_back(top_center);
        Point bottom_center = { center.x, center.y, 0 };
        points.push_back(bottom_center);
    }
    calculateVolumeAndSquare();
}

void Shape::shift(int m, int n, int k) {
    for (int i = 0; i < points.size(); ++i) {
        points[i].x += m;
        points[i].y += n;
        points[i].z += k;
    }
}

void Shape::scaleX(int a) {
    for (int i = 0; i < points.size(); ++i) {
        points[i].x *= a;
    }
}

void Shape::scaleY(int d) {
    for (int i = 0; i < points.size(); ++i) {
        points[i].y *= d;
    }
}

void Shape::scaleZ(int e) {
    for (int i = 0; i < points.size(); ++i) {
        points[i].z *= e;
    }
}

void Shape::scale(int s) {
    for (int i = 0; i < points.size(); ++i) {
        points[i].x /= s;
        points[i].y /= s;
        points[i].z /= s;
    }
}

void Shape::calculateVolumeAndSquare() {
    if (type == LINE || type == SQUARE) {
        volume = 0;
    }
    else {
        
        double a = abs(points[0].x - points[1].x);
        double b = abs(points[0].y - points[1].y);
        double c = abs(points[0].z - points[1].z);
        square = 2 * (a * b + a * c + b * c);
        volume = a * b * c;
    }
}
