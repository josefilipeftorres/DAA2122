#include <iostream>
#include <list>
#include <climits>
using namespace std;

#define MAX 255
#define INC 4
#define CLOUD '#'
#define AIRP 'A'
#define EMPTY '.'

int rows, cols;
char m[MAX][MAX];
bool visited[MAX][MAX];
int distMin[MAX][MAX];

int incx[INC] = {-1, 1, 0, 0};
int incy[INC] = { 0, 0,-1, 1};

int nAirports;

class Point {
public:
    int x;
    int y;
    int dist;

    Point(int x, int y, int dist) {
        this->x = x;
        this->y = y;
        this->dist = dist;
    }
};

void bfs(){
    list<Point*> q;
    list<int> result;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (m[i][j] == AIRP) nAirports++;
            if (m[i][j] == CLOUD) {
                Point *u = new Point(i,j,0);
                q.push_back(u);
                visited[i][j] = true;
                distMin[i][j] = 0;
            }
        }
    }

    while (!q.empty()) {
        Point *u = q.front(); q.pop_front();

        for (int k = 0; k < INC; k++) {
            int xp2 = u->x + incx[k];
            int yp2 = u->y + incy[k];
            if (xp2 >= 0 && xp2 < rows && yp2 >= 0 && yp2 < cols && !visited[xp2][yp2]) {
                Point *w = new Point(xp2,yp2, u->dist+1);
                q.push_back(w);
                distMin[xp2][yp2] = w->dist + 1;
                visited[xp2][yp2] = true;

                if (m[xp2][yp2] == AIRP) 
                    result.push_back(u->dist+1);
            }
        }
    }

    int min = INT_MAX;
    int max = 0;

    for (int t : result) {
        if (t > max) max = t;
        if (t < min) min = t;
    }
    printf("%d %d\n", min, max);
}

int main() {
    cin >> rows >> cols;

    for (int i = 0; i < rows; i++)
        cin >> m[i];
    
    bfs();
    
    return 0;
}