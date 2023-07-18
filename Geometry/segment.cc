bool inDisk(pt a, pt b, pt p) {
    // true if point p lies on circle whose radius is AB
    return dot(a-p, b-p) <= 0;
}

bool onSegment(pt a, pt b, pt p) {
    // true if point p lies on segment AB
    return orient(a,b,p) == 0 && inDisk(a,b,p);
}

bool properInter(pt a, pt b, pt c, pt d, pt &out) {
    //Checks for proper intersection of segment
    // AB and CD (one-point intersection)

    double oa = orient(c,d,a),
    ob = orient(c,d,b),
    oc = orient(a,b,c),
    od = orient(a,b,d);

    // Proper intersection exists iff opposite signs
    if (oa*ob < 0 && oc*od < 0) {
        out = (a*ob - b*oa) / (ob-oa);
        return 1;
    }
    return 0;
}

struct cmpX {
    bool operator()(pt a, pt b) {
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    }
};

set<pt,cmpX> inters(pt a, pt b, pt c, pt d) {
    // Checks all intersections of AB and CD
    pt out;
    
    // one-point intersection
    if (properInter(a,b,c,d,out)) return {out};

    set<pt,cmpX> st;
    if (onSegment(c,d,a)) st.insert(a);
    if (onSegment(c,d,b)) st.insert(b);
    if (onSegment(a,b,c)) st.insert(c);
    if (onSegment(a,b,d)) st.insert(d);
    return st;
}


double segPoint(pt a, pt b, pt p) {
    //distance between point P and segment AB
    if (a != b) {
        line l(a,b);

        // if closest to projection (between A, B) 
        // output distance to line
        if (l.cmpProj(a,p) && l.cmpProj(p,b)) 
            return l.dist(p); 
    }
    // otherwise distance to A or B
    return min(abs(p-a), abs(p-b)); 
}

double segSeg(pt a, pt b, pt c, pt d) {
    //distance between segment AB and segment CD
    pt dummy;
    if (properInter(a,b,c,d,dummy))
        return 0;
    return min({segPoint(a,b,c), segPoint(a,b,d),
                segPoint(c,d,a), segPoint(c,d,b)});
}