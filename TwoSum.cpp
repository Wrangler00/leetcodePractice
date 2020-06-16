//https://leetcode.com/problems/two-sum/

//cpp
class Solution {
public:
    int binsearch(vector<pair<int,int>>& n, int sz,int tt){
        int l=0,r = sz-1, mid;
        while(l<=r){
            mid = (l+r)/2;

            if(n[mid].first == tt){
                break;
            }

            if(n[mid].first<tt){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        
        return n[mid].first == tt?mid:-1;
    }
    
    vector<int> twoSum(vector<int>& n, int t) {
        int sz = n.size();
        vector<int> ans;
        
        vector<pair<int,int>> vc(sz);
        
        for(int i=0;i<sz;i++){
            vc[i] = make_pair(n[i],i);
        }
        
        sort(vc.begin(),vc.end());
        
        int last = sz-1;
        while(last>0){
            int rem = t-vc[last].first;
            int val = binsearch(vc,last,rem);
            if(val != -1){
                ans.push_back(vc[val].second);
                ans.push_back(vc[last].second);
                break;
            }else{
                --last;
            }
        }
        
        return ans;
    }
};
