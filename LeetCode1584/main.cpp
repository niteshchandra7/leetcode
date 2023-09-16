#include<iostream>
#include<vector>
using namespace std;

int main(){
    //vector<vector<int>>points={{0,0},{2,2},{3,10},{5,2},{7,0}};
    vector<vector<int>>points={{3,12},{-2,5},{-4,1}};
    int getMinCost(vector<vector<int>>&points);
    cout << getMinCost(points);
    return 0;
}

int getMinCost(vector<vector<int>>&points){
    vector<vector<unsigned int>> getWeightedEdgeList(vector<vector<int>>&points);
    unsigned int getComponentID(vector<unsigned int>&componentVector, int idx);
    bool comp(vector<unsigned int>&a, vector<unsigned int>&b);
    unsigned int cost = 0;
    vector<vector<unsigned int>>g = getWeightedEdgeList(points);
    vector<unsigned int>compVector(points.size());
    for(unsigned int i=0;i<compVector.size();i++)compVector[i]=i;  
    sort(g.begin(),g.end(),comp);
    for(unsigned int i=0;i<g.size();i++){
        unsigned int u = g[i][0];
        unsigned int v = g[i][1];
        unsigned int compU = getComponentID(compVector,u);
        unsigned int compV = getComponentID(compVector,v);
        if(compU==compV)continue;
        cost+=g[i][2];
        compVector[max(compU,compV)] = min(compU,compV);
    }
    return cost;
}

vector<vector<unsigned int>> getWeightedEdgeList(vector<vector<int>>&points){
    vector<vector<unsigned>>g;
    for(unsigned int u=0;u<points.size();u++){
        for(unsigned int v=u+1;v<points.size();v++){
            unsigned w = abs(points[u][0]-points[v][0]) + abs(points[u][1]-points[v][1]);
            g.push_back({u,v,w});
        }
    }
    return g;
}

bool comp(vector<unsigned >&a, vector<unsigned int>&b){
    return a[2]<b[2];
}

unsigned int getComponentID(vector<unsigned int>&componentVector, int idx){
    if(componentVector[idx]==idx)return idx;
    componentVector[idx] = getComponentID(componentVector,componentVector[idx]);
    return componentVector[idx];
}

