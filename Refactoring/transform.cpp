#include "transform.h"

Transform::Transform(const Shape& sh) : shape(sh) {}

Shape Transform::shift(int m, int n, int k) {
    for (int i = 0; i < shape.getNumPoints(); ++i) {
        shape[i].x += m;
        shape[i].y += n;
        shape[i].z += k;
    }
    return shape;
}

Shape Transform::scaleX(int a) {
    for (int i = 0; i < shape.getNumPoints(); ++i) {
        shape[i].x *= a;
    }
    return shape;
}

Shape Transform::scaleY(int d) {
    for (int i = 0; i < shape.getNumPoints(); ++i) {
        shape[i].y *= d;
    }
    return shape;
}

Shape Transform::scaleZ(int e) {
    for (int i = 0; i < shape.getNumPoints(); ++i) {
        shape[i].z *= e;
    }
    return shape;
}

Shape Transform::scale(int s) {
    for (int i = 0; i < shape.getNumPoints(); ++i) {
        shape[i].x /= s;
        shape[i].y /= s;
        shape[i].z /= s;
    }
    return shape;
}