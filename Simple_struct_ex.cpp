#include <iostream>
using namespace std;

struct Point {
	int xpos;
	int ypos;

    void MovePos(int x, int y){
        xpos += x;
        ypos += y;
        return;
    }// Coordinate movement of points
    void AddPoint(const Point &pos) {
        xpos += pos.xpos;
        ypos += pos.ypos;
        return; 

        
    }// Coordinate increase of points
    void ShowPosition(){
        cout << "[" << xpos << "," << ypos << "]" << endl;

    }// Output current x, y coordinate information
};



int main(void) {
    Point pos1 = { 12, 4 };
    Point pos2 = { 20, 30 };

    pos1.MovePos(-7, 10);
    pos1.ShowPosition();		//Print [5, 14]

    pos1.AddPoint(pos2);
    pos1.ShowPosition();		//Print [25, 44]

    return 0;
}
