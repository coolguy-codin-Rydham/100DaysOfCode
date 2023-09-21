class Solution {
public:

    void combination(vector<int>& arr, int target,int n,int sumNow,int index,vector<int>&ds,set<vector<int>>&ans){
        if(sumNow==target){
          ans.insert(ds);
        }
        if((sumNow>target)||(index==n)) return ;

        sumNow+=arr[index];
        ds.push_back(arr[index]);
        combination(arr,target,n,sumNow,index,ds,ans);
        sumNow-=arr[index];
        ds.pop_back();
        combination(arr,target,n,sumNow,index+1,ds,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        set<vector<int>>ans;
        vector<int>ds;
        combination(candidates,target,candidates.size(),0,0,ds,ans);
        vector<vector<int>>ansf(ans.begin(),ans.end());
        return ansf;
    }
};
