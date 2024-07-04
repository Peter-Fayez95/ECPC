
struct line {
    pt v, p, q; T c;

    // From direction vector v and offset c
    line(pt v, T c): v(v), c(c) {}

    // From equation ax + by + c = 0
    line(T a, T b, T c): v{b,-a}, c(-c) {}

    // From two points P and Q
    line(pt p, pt q): v(q-p), c(cross(v,p)) {}

    array<T, 3> equation() {
        // get equation ax+by+c=0
        return {v.y, -v.x, c};
    }

    T side(pt p) {
        /*Check if point P is on which side of line
        P = (x, y)
        side(P) > 0 for positive side (i.e. ax + by - c > 0)
        */
        return cross(v,p)-c;
    }

    T dist(pt p) {
        /*distance between the line and point P*/
        return abs(side(p)) / abs(v);
    }
    T sqDist(pt p) {return side(p)*side(p) / (T)sq(v);}
    
    line perpThrough(pt p) {
        /*return the line perp to our line through point P*/
        return {p, p + perp(v)};
    }
    bool cmpProj(pt p, pt q) {
        /*Comparator to sort points along the line
        sort by the orthogonal projection on the line*/
        return dot(v,p) < dot(v,q);
    }
    line translate(pt t) {
        /*Translate the line by a vector t*/
        return {v, c + cross(v,t)};
    }
    line shiftLeft(T del) {
        /*Shift line to left by value delta*/
        return {v, c + del*abs(v)};
    }
    pt intersect(line l2) {
        /*find intersection point between line and l2*/

        T d = cross(v, l2.v);

        // angle between lines is zero
        if (d == 0) return {INF, INF};

        return (l2.v*c - v*l2.c) / d;

    }

    pt proj(pt p) {return p - perp(v)*side(p)/sq(v);}
    pt refl(pt p) {return p - 2.0*perp(v)*side(p)/sq(v);}

    pair<pt, pt> get_points() { 
        // extract any two points from this line
	pt p, q; 
        double a = -v.y, b = v.x; // ax + by = c
	if (sign(a) == 0) {
	    p = pt{0, c / b};
	    q = PT{1, c / b};
	}
	else if (sign(b) == 0) {
	    p = pt{c / a, 0};
	    q = pt{c / a, 1};
	}
	else {
	    p = pt{0, c / b};
	    q = pt{1, (c - a) / b};
	}
	return {p, q};
    }

};

line bisector(line l1, line l2, bool interior) {
    assert(cross(l1.v, l2.v) != 0); // l1 and l2 can't be parallel
    T sign = interior ? 1 : -1;
    pt v = l2.v/abs(l2.v) + l1.v/abs(l1.v) * sign;
    T c = l2.c/abs(l2.v) + l1.c/abs(l1.v) * sign;
    return line(v, c);
}
