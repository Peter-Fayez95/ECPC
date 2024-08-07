#include <bits/stdc++.h>
using namespace std;
#define MOD %((int)1e9+7)
typedef double T;
typedef complex<T> pt;
#define x real()
#define y imag()
#define all(x) x.begin(), x.end()
#define INF 100000000
const T pi = 3.1415926535897;


T polar_angle(pt v) {
    // get polar angle of v [0, 2pi)
    T angle = arg(v);
    if (angle < 0) angle += 2 * pi;
    return angle;
}

pt translate(pt v, pt p) {return p + v;}

pt scale(pt c, T factor, pt p) {return c + (p - c) * factor;}

// rotate the vector by angle th
pt rot(pt p, T th) {return p * polar(1.0, th);}

// rotate by 90
pt perp(pt p) {return {-p.y, p.x};}


T sq(pt p) {return p.x * p.x + p.y * p.y;}

// dot product
T dot(pt v, pt w) {return (conj(v) * w).x;}

// distance between two points
T dist(pt a, pt b) {return sqrt(p2(abs(a.x - b.x)) + p2(abs(a.y - b.y)));}

// true if two vectors are perpendicular
bool isPerp(pt v, pt w) {return dot(v, w) == 0;}

T angle(pt v, pt w) {
    /*Value of angle between vector OV and OW*/

    // clamp ensures value is between -1 and 1.
    return acos(clamp(dot(v,w) / abs(v) / abs(w), -1.0, 1.0));
}

// cross product
T cross(pt v, pt w) {return (conj(v) * w).y;}

T orient(pt a, pt b, pt c) {
    /*Check the orientation of point C WRT vector AB */
    return cross(b - a,c - a);
}

bool inAngle(pt a, pt b, pt c, pt p) {
    /* Check if point P is inside angle <ABC> */
    assert(orient(a, b, c) != 0);
    if (orient(a, b, c) < 0) swap(b,c);
    return orient(a, b, p) >= 0 && orient(a,c,p) <= 0;
}

T orientedAngle(pt a, pt b, pt c) {
    /* Check the measure of angle formed by
    rotating from B to C CCW around A */
    if (orient(a, b, c) >= 0) return angle(b - a, c - a);
    else return 2 * pi - angle(b - a, c - a);
}


bool upper_half(pt p) {
    /*check if vector is in first two quadrants (i.e. upper half)*/
    
    // arg of (0, 0) is undefined
    assert(p.x != 0 || p.y !=0);

    return (p.y > 0 || (p.y == 0 && p.x < 0));
}

void polarSort(vector<pt> points) {
    /*Sort points by a ray rotating CCW*/
    sort(all(points), [](pt v, pt w) {
        return make_tuple(upper_half(v), 0) 
            < make_tuple(upper_half(w), cross(v, w));
    });
}
