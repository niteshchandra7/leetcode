#include<iostream>
#include<vector>
using namespace std;


int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(),tokens.end());
    int first = 0;
    int last = tokens.size()-1;
    int maxScore=0;
    int currScore=0;
    while(first<=last) {
        if(tokens[first] <= power) {
            currScore++;
            maxScore = max(maxScore,currScore);
            power -= tokens[first++];
        } else {
            if (currScore==0) break;
            currScore--;
            power += tokens[last--];
        }
    }
    return maxScore;
}

int main() {

}
/*

[100,200,300,400], power = 200
score = 0

*/
