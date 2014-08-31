#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>
#include "dataStructure.h"

using namespace std;

int maxPoints(vector<Point> &points){
  if(points.size()<=2) return points.size();
  map<float, int> slopeAndCnt;
  Point p1, p2;
  float slope = 0.0;
  int maxN = 0, maxN_OneNode = 0, duplicate, vertical;
  for(int i = 0; i < points.size(); i++){
    p1 = points[i];
    slopeAndCnt.clear();
    maxN_OneNode = 0;
    vertical = 0;   // for slope vertical to x-axis, no value
    duplicate = 0;  // for duplicate anchor points.
    for(int j = 0; j < points.size(); j++){
      if(j==i) continue;
      p2 = points[j];
      //cout << "(" << p1.x << "," << p1.y << ")"<< "-->(" << p2.x << "," << p2.y << ")" << endl;
      if(p1.x == p2.x && p1.y == p2.y) {duplicate++; continue;}
      else if(p1.x == p2.x) {vertical++; continue;}
      slope = (p2.y - p1.y) * 1.0 /(p2.x - p1.x);
      slopeAndCnt[slope]++;
      maxN_OneNode = max(maxN_OneNode, slopeAndCnt[slope]);
      // cout << maxN << " " << maxN_OneNode <<" " << vertical << endl;
    }
    maxN = max(maxN, duplicate + max(maxN_OneNode, vertical));
    cout << maxN << endl;
    //    cout << "**************************" << endl;
  }
  return maxN + 1;  // add the anchor point itself
}

int main(){

  vector<Point> points;
  /*
  for(int i = 0; i < 200; i++){
    Point *p = new Point(rand()%100, rand()%100);
    points.push_back(*p);
  }
  */

  
  points.push_back(Point(1,1));
  points.push_back(Point(1,1));
  points.push_back(Point(2,2));
  points.push_back(Point(2,2));
  
  cout << maxPoints(points) << endl;

}
