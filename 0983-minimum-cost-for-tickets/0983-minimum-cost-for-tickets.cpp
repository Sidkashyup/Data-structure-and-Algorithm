class Solution {
public:

    int mincostTickets(vector<int>& days, vector<int>& costs) {
    
        int n=days.size();
        vector<int> dp(n+1,0);

        for(int ind=n-1;ind>=0;ind--){
            
            int Day1=costs[0]+dp[ind+1];
            int i;
            for(i=ind;i<n;i++){
                if(days[i]>=days[ind]+7){
                    break;
                }
            }
            int Day7=costs[1]+dp[i];
            int j;
            for(j=ind;j<n;j++){
                if(days[j]>=days[ind]+30){
                    break;
                }
            }
            int Day30=costs[2]+dp[j];

            dp[ind]=min(Day1,min(Day7,Day30));

        }

        return dp[0];
        
    }
};