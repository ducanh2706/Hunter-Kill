// #include "../library/vector.h"

// Vector::Vector(): x(0), y(0) {}
// Vector::Vector(double _x, double _y): x(_x), y(_y) {}
// Vector::Vector(Vector &other): x(other.x), y(other.y) {}

// double Vector::getX() const {
//     return x;
// }

// double Vector::getY() const {
//     return y;
// }

// void Vector::setX(double _x) {
//     x = _x;
// }

// void Vector::setY(double _y) {
//     y = _y;
// }


// Vector Vector::operator+ (const Vector &other) const {
//         return Vector(x + other.x, y + other.y);
// }

// Vector Vector::operator- (const Vector &other) const {
//     return Vector(x - other.x, y - other.y);
// }

// Vector Vector::operator* (double k) const {
//     return Vector(x * k, y * k);
// }

// double Vector::dot(const Vector &other) const {
//     return x * other.x + y * other.y;
// }

// double Vector::cross(const Vector &other) const {
//     return x * other.y - y * other.x;
// }

// double Vector::length() const {
//     return sqrt(x * x + y * y);
// }

// double Vector::distance(const Vector &other) const {
//     return (*this - other).length();
// }

// Vector Vector::normalize() const {
//     double len = length();
//     return Vector(x / len, y / len);
// }

// Vector Vector::rotate(double angle) const {
//     return Vector(x * cos(angle) - y * sin(angle), x * sin(angle) + y * cos(angle));
// }