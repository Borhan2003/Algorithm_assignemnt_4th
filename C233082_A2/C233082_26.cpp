#include <iostream>
#include <algorithm>
using namespace std;

struct Point
{
    int x, y;
};

int dir(Point pi, Point pj, Point pk)
{

    return (pk.x - pi.x) * (pj.y - pi.y) - (pj.x - pi.x) * (pk.y - pi.y);
}
bool onSeg(Point pi, Point pj, Point pk)
{
    return min(pi.x, pj.x) <= pk.x && pk.x <= max(pi.x, pj.x) &&
           min(pi.y, pj.y) <= pk.y && pk.y <= max(pi.y, pj.y);
}

bool intersect(Point p1, Point p2, Point p3, Point p4)
{
    int d1 = dir(p3, p4, p1);
    int d2 = dir(p3, p4, p2);
    int d3 = dir(p1, p2, p3);
    int d4 = dir(p1, p2, p4);

    if ((d1 != d2) &&
        (d3 != d4))
        return true;

    if (d1 == 0 && onSeg(p3, p4, p1))
        return true;
    if (d2 == 0 && onSeg(p3, p4, p2))
        return true;
    if (d3 == 0 && onSeg(p1, p2, p3))
        return true;
    if (d4 == 0 && onSeg(p1, p2, p4))
        return true;

    return false;
}

int main()
{
    Point p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;

    if (intersect(p1, p2, p3, p4))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
