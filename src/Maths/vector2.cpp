#include "../../library/Maths/vector2.h"

Vector2::Vector2() : x(0), y(0) {}
Vector2::Vector2(double x, double y) : x(x), y(y) {}

Vector2 Vector2::operator+(const Vector2& v) {
    return Vector2(x + v.x, y + v.y);
}

Vector2 Vector2::operator-(const Vector2& v) {
    return Vector2(x - v.x, y - v.y);
}

Vector2 Vector2::operator*(double scalar){
    return Vector2(x * scalar, y * scalar);
}

double Vector2::dot(const Vector2& v) {
    return x * v.x + y * v.y;
}

double Vector2::cross(const Vector2& v) {
    return x * v.y - y * v.x;
}

double Vector2::length(){
    return sqrt(x * x + y * y);
}

Vector2 Vector2::normalize() {
    if (x == 0 && y == 0){
        return Vector2(0, 0);
    }
    double magnitude = sqrt(x * x + y * y);
    return Vector2(x / magnitude, y / magnitude);
}      

Vector2 Vector2::rotate(double angle){
    double rad = angle * PI / 180;
    double newX = x * cos(rad) - y * sin(rad);
    double newY = x * sin(rad) + y * cos(rad);
    return Vector2(newX, newY);
}