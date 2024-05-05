#include "../../library/Maths/rectangle.h"

Rectangle::Rectangle() {
    x = y = u = v = w = h = 0;
}

Rectangle::Rectangle(double _x, double _y, double _u, double _v) {
    x = _x;
    y = _y;
    u = _u;
    v = _v;
    w = u - x;
    h = v - y;
}

bool Rectangle::inMap(double _x, double _y) const {
    return x <= _x && _x <= u && y <= _y && _y <= v;
}

const double eps = 1e-9;

int sign(double x) {
    if (x > eps) return 1;
    if (x < -eps) return -1;
    return 0;
}


bool lineIntersect(Vector2 A, Vector2 B, Vector2 C, Vector2 D) {
    int ABxAC = sign((B - A).cross(C - A));
    int ABxAD = sign((B - A).cross(D - A));
    int CDxCA = sign((D - C).cross(A - C));
    int CDxCB = sign((D - C).cross(B - C));
    if (ABxAC == 0 || ABxAD == 0 || CDxCA == 0 || CDxCB == 0) {
        if (ABxAC == 0 && sign((A - C).dot(B - C)) <= 0) return true;
        if (ABxAD == 0 && sign((A - D).dot(B - D)) <= 0) return true;
        if (CDxCA == 0 && sign((C - A).dot(D - A)) <= 0) return true;
        if (CDxCB == 0 && sign((C - B).dot(D - B)) <= 0) return true;
        return false;
    }
    return (ABxAC * ABxAD < 0 && CDxCA * CDxCB < 0);
}

double clamp(double n, double lower, double upper) {
    return std::max(lower, std::min(upper, n));
}

Vector2 Rectangle::getClosestPoint(Vector2 position) const {
    position.x = clamp(position.x, x * TILE_SIZE, (u + 1) * TILE_SIZE);
    position.y = clamp(position.y, y * TILE_SIZE, (v + 1) * TILE_SIZE);

    double dl = std::abs(position.x - x * TILE_SIZE);
    double dr = std::abs(position.x - (u + 1) * TILE_SIZE);
    double dt = std::abs(position.y - y * TILE_SIZE);
    double db = std::abs(position.y - (v + 1) * TILE_SIZE);

    double m = std::min({dl, dr, dt, db});

    if (m == dt) return {position.x, y * TILE_SIZE};
    if (m == db) return {position.x, (v + 1) * TILE_SIZE};
    if (m == dl) return {x * TILE_SIZE, position.y};
    return {(u + 1) * TILE_SIZE, position.y};
}

bool Rectangle::intersect(Vector2 pointA, Vector2 pointB) {
    // check 4 canh
    Vector2 topLeft = Vector2(x * TILE_SIZE, y * TILE_SIZE);
    Vector2 topRight = Vector2((u + 1) * TILE_SIZE, y * TILE_SIZE);
    Vector2 bottomLeft = Vector2(x * TILE_SIZE, (v + 1) * TILE_SIZE);
    Vector2 bottomRight = Vector2((u + 1) * TILE_SIZE, (v + 1) * TILE_SIZE);
    

    return lineIntersect(pointA, pointB, topLeft, topRight)
        || lineIntersect(pointA, pointB, topRight, bottomRight)
        || lineIntersect(pointA, pointB, bottomRight, bottomLeft)
        || lineIntersect(pointA, pointB, bottomLeft, topLeft); 
}

bool Rectangle::contain(Vector2 point) {
    return x * TILE_SIZE <= point.x && point.x <= (u + 1) * TILE_SIZE
        && y * TILE_SIZE <= point.y && point.y <= (v + 1) * TILE_SIZE;
}