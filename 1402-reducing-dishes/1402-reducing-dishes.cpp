class Solution {
private:
    vector<vector<int>>dp;
    int solve(int i,int j,vector<int>& s){
        if(i>=s.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=max(solve(i+1,j+1,s)+s[i]*j,solve(i+1,j,s));
    }
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        dp.clear();
        dp.resize(satisfaction.size()+4,vector<int>(satisfaction.size()+4,-1));
        sort(satisfaction.begin(),satisfaction.end());
        return solve(0,1,satisfaction);
    }
};