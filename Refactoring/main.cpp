#include <iostream>
#include "shape.h"

int main() {
    std::setlocale(LC_ALL, "RU");

    Shape square(Shape::SQUARE, { {0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0} });

    std::cout << "Before transformation:\n";
    std::cout << "Type: Square\n";
    std::cout << "Points:\n";
    for (int i = 0; i < square.getNumPoints(); ++i) {
        const Point& p = square[i];
        std::cout << "  (" << p.x << ", " << p.y << ", " << p.z << ")\n";
    }
    std::cout << "Volume: " << square.getVolume() << "\n";
    std::cout << "Square: " << square.getSquare() << "\n\n";

    // Преобразования
    square.shift(1, 1, 0);
    square.scaleX(2);
    square.scaleY(2);
    square.scaleZ(2);
    square.scale(2);

    std::cout << "After transformation:\n";
    std::cout << "Type: Square\n";
    std::cout << "Points:\n";
    for (int i = 0; i < square.getNumPoints(); ++i) {
        const Point& p = square[i];
        std::cout << "  (" << p.x << ", " << p.y << ", " << p.z << ")\n";
    }
    std::cout << "Volume: " << square.getVolume() << "\n";
    std::cout << "Square: " << square.getSquare() << "\n";

    return 0;
}
