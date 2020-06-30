/*Implement the “paint fill” function that one might see on many image editing programs. That is, given a screen (represented by a 2 dimensional array of Colors), a
point, and a new color, fill in the surrounding area until you hit a border of that color.’*/
#include <iostream>

using namespace std;
class Point
{
    private:
    int X;
    int Y;
    int colorCode;
    public:
    Point(int x, int y, int ccode)
    {
        X=x;Y=y;colorCode=ccode;
    }
    void fillColor(int ccode)
    {
        colorCode=ccode;
    }
   Point getNorth()
   {
       Point p(X,Y-1,0);
       return p;
   }
   getSouth()
   getEast()
   getWest()

}
void fillPaint(Point p,int ccode)
{

}
int main()
{
    int N,M;
    cout<<"Enter the X and Y of the point you want to color \n";
    cin>>N;
    cin>>M;
    int ccode;
    cout<<"Enter the color code\n";
    cin>>ccode;
    fillPaint(N,M,ccode);
    return 1;
}