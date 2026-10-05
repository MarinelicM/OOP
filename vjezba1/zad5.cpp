#include <iostream>
#include <cmath>
using namespace std;
struct point
{
    double x, y;
};
//pokazivaci
void move_by(point* p, double dx, double dy)
{
    p->x += dx;
    p->y += dy;
}

double dist(const point* a, const point* b)
{
    double dx = b->x - a->x;
    double dy = b->y - a->y;

    return sqrt(dx * dx + dy * dy);
}
//reference
void move_by(point& p, double dx, double dy)
{
    p.x += dx;
    p.y += dy;
}

double dist(const point& a, const point& b)
{
    double dx = b.x - a.x;
    double dy = b.y - a.y;

    return sqrt(dx * dx + dy * dy);
}

int main()
{
    point p = {3, 4};
    move_by(&p, 4, -2);
    cout << "Tocka nakon pomicanja: ";
    cout << p.x << ", " << p.y << endl;
    point a = {4, 0};
    point b = {7, 2};
    cout << "Udaljenost pomocu pointera: ";
    cout << dist(&a, &b) << endl;
    cout << "Udaljenost pomocu referenci: ";
    cout << dist(a, b) << endl;
    point points[5] =
    {
        {3, 4},
        {1, 1},
        {5, 2},
        {-2, 3},
        {0.5, 0.5}
    };

    point ishodiste = {0, 0};
    int min = 0;

    for (int i = 1; i < 5; i++)
    {
        if (dist(points[i], ishodiste) < dist(points[min], ishodiste))
        {
            min = i;
        }
    }
    cout << "Tocka najbliza ishodistu je:(" << points[min].x << ", " << points[min].y << ")" << endl;
}