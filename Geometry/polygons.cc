
vector<pt> points, seq;
pt translation;

// polygon area: O(n)
void polygon_area() {
    T tot = 0;
    n = points.size();
    for (int i=0; i<n; i++) {
        tot+= cross(points[i], points[(i+1)%n]);
    }
    cout <<  abs(tot)/2.0 << "\n";
}

// Pick's theorem
int pick_area(int a, int b) {
    // a:  number of integer points inside the polygon
    // b:  number of integer points on the polygon boundary
    return a + b/2 - 1;
}

bool isConvex(vector<pt> points) {
    /*check if polygon is convex*/
    bool hasPos = 0, hasNeg = 0;
    int n = points.size();
    for (int i=0; i<n; i++) {
        int o = orient(points[i], points[(i+1)%n], points[(i+2)%n]);
        if (o > 0) hasPos=1;
        else if (o < 0) hasNeg=1;
    }
    return !(hasPos && hasNeg);
}


int sgn(ll x) { 
    return x > 0 ? 1 : (x == 0 ? 0 : -1); 
}

void prepare(vector<pt> &points) {
    n = points.size();

    // get minimum point
    int pos = min_element(points.begin(), points.end(), cmpX());
    
    // make p0 the minimum point
    rotate(points.begin(), points.begin() + pos, points.end());

    n--;

    // compute all vectors {p0, pi} after translating p0 to (0,0)
    // save them in seq
    seq.resize(n);
    for (int i = 0; i < n; i++)
        seq[i] = points[i + 1] - points[0];

    // translation point = p0
    translation = points[0];
}

// check if point in triangle abc
bool pointInTriangle(pt a, pt b, pt c, pt p) {
    ll s1 = abs(cross(b-a, c-a));
    ll s2 = abs(cross(a-p, b-p)) + abs(cross(b-p, c-p)) + abs(cross(c-p, a-p));
    return s1 == s2;
}

// check if point is in polygon O(log n)
bool point_in_polygon(pt point) {
    // translate according to p0
    point = point - translation;
    
    if (cross(seq[0], point) != 1 &&
            sgn(cross(seq[0], point)) != sgn(cross(seq[0], seq[n - 1])))
        return false;
    if (cross(seq[n-1], point) != 0 &&
            sgn(cross(seq[n-1], point)) != sgn(cross(seq[n-1], seq[0])))
        return false;

    if (cross(seq[0], point) == 0)
        return seq[0].sq() >= point.sq();

    int l = 0, r = n - 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int pos = mid;
        if (cross(seq[pos], point) >= 0)
            l = mid;
        else
            r = mid;
    }
    int pos = l;
    return pointInTriangle(seq[pos], seq[pos + 1], pt{0, 0}, point);

} 