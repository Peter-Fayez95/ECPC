#include <bits/stdc++.h>
#include "points-vectors.cc"
#include "straight_line.cc"
using namespace std;

struct circle {
    // center - radius
    pt O; T r;
    
    circle() {}

    // from center and radius
    circle(pt O, T r): O(O), r(r) {}

    // circumcircle of triangle ABC
    circle(pt a, pt b, pt c) {
        b = b - a, c = c - a;
        assert(cross(b, c) != 0);
        O = a + perp(b * sq(c) - c * sq(b)) / cross(b, c) / 2.0;
        r = dist(O, a);
    }

    // Computes intersections of circle and line
    // places them in out and returns number of intersections
    int circleline(line l, pair<pt, pt> &out) {
        T h2 = r * r - l.sqDist(O);

        // the line touches the circle
        if (h2 >= 0) {
            pt p = l.proj(O); // point P

            // vector parallel to l, of length h
            pt h = l.v * sqrt(h2) / abs(l.v);

            out = {p - h, p + h};
        }
        return 1 + sgn(h2);
    }

    // Computes intersections of two circles
    // places them in out and returns number of intersections
    int circleCircle(pt o2, T r2, pair<pt, pt> &out) {
        pt d = o2 - O;
        T d2 = sq(d);
        // concentric circles
        if (d2 == 0) {assert(r != r2); return 0;}

        double pd = (d2 + r * r - r2 * r2) / 2;
        double h2 = r * r - pd * pd / d2;
        if (h2 >= 0) {
            pt p = O + d * pd / d2, h = perp(d) * sqrt(h2 / d2);
            out = {p - h, p + h};
        }
        return 1 + sgn(h2);
    }
};
