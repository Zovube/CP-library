struct Point {
    ld x, y;
    Point(ld a, ld b) : x(a), y(b) {};
    ld dist(const Point &a) {
        return sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y));
    }
};

struct Line {
    ld A, B, C;
    Line(const Point &p1, const Point &p2) {
        A = p2.y - p1.y;
        B = p1.x - p2.x;
        C = -(A * p1.x + B * p1.y);
    }
    Point zero() {
        return Point(-C / A, 0);
    }
    bool onLineSegment(const Point &p1, const Point &p2, const Point &p3) {
        bool okX = (p1.x >= min(p2.x, p3.x) && p1.x <= max(p2.x, p3.x));
        bool okY = (p1.y >= min(p2.y, p3.y) && p1.y <= max(p2.y, p3.y));        
        return (A * p1.x + B * p1.y + C == 0) && okX && okY;
    }
};
