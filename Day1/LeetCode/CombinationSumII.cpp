class Solution {
public:
void combinationSum(vector<int> &arr, int target, vector<int> &ds, vector<vector<int>> &ans, int index)
    {
        if(target==0){
            ans.push_back(ds);
            return ;
        }

        for(int i=index;i<arr.size();i++){
            if(i>index && arr[i]==arr[i-1]){
                continue;
            }

            if(arr[i]>target){
                break;
            }
            ds.push_back(arr[i]);
            combinationSum(arr,target-arr[i],ds,ans,i+1);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        combinationSum(candidates,target,ds,ans,0);
        return ans;
    }
};
