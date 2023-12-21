#include <iostream>
using namespace std;

int maxWidthOfVerticalArea(vector<vector<int>> &points)
{
    sort(points.begin(),points.end(),comp);
    int ans=0;
    for(unsigned int i=1;i<points.size();i++){
        ans = max(ans,points[i][0]-points[i-1][0]);
    }
    return ans;

}

bool comp(vector<int>&point1, vector<int>&point2){
    return point1[0]<point2[0];
}

int main()
{
    return 0;
}