#include<iostream>
#include<stack>
#include<vector>
using namespace std;


vector<int>nearestSmallestLeft(vector<int>&nums) {
    vector<int>ans(nums.size());
    stack<int>s;
    for(int i=0;i<nums.size();i++) {
        while(!s.empty() && (nums[s.top()] >= nums[i])) {
            s.pop();
        }
        if(s.empty())ans[i]=-1;
        else ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

vector<int>nearestSmallestRight(vector<int>&nums) {
    vector<int>ans(nums.size());
    stack<int>s;
    for(int i=nums.size()-1;i>=0;i--) {
        while(!s.empty() && (nums[s.top()] >= nums[i])) {
            s.pop();
        }
        if(s.empty())ans[i]=nums.size();
        else ans[i]=s.top();
        s.push(i);
    }
    return ans;
}
vector<vector<int>>convert(vector<vector<char>>&matrix) {
    vector<vector<int>>ans(matrix.size(),vector<int>(matrix[0].size(),0));
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            if(matrix[i][j]=='1')ans[i][j]=1;
        }
    }
    return ans;
}

vector<vector<int>>getPSArray(vector<vector<int>>nums) {
    for(int i=1;i<nums.size();i++){
        for(int j=0;j<nums[0].size();j++){
            if(nums[i][j]!=0)nums[i][j] = nums[i][j] + nums[i-1][j];
        }
    }
    return nums;
}

int calculateMaxArea(vector<vector<int>>&nums, int idx) {
    vector<int>NSR = nearestSmallestRight(nums[idx]);
    vector<int>NSL = nearestSmallestLeft(nums[idx]);
    int ans=0;
    for(int i=0;i<nums[0].size();i++){
        ans=max(ans,(NSR[i]-NSL[i]-1)*nums[idx][i]);
    }
    return ans;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    vector<vector<int>>nums=getPSArray(convert(matrix));
    int ans=0;
    for(int i=0;i<nums.size();i++) {
        ans=max(ans,calculateMaxArea(nums,i));
    }
    return ans;
}

// TC : O(N*M)
// SC : O(N*M)

int main() {

}