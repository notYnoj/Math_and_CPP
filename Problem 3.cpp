#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int l = 0;
void dfs(int n, vector<int> cur){
    if(n == 0){
        l++;
        for(int i = 0; i<cur.size(); i++){
            cout<<cur[i]<<" ";
            if(i%2){
                ans+=(-cur[i]);
                assert(-cur[i]<0);
            }else{
                ans+=(cur[i]);
                assert(cur[i]>0);
            }
        }
        cout<<"\n";
    }else{
        cur.push_back(n);
        dfs(n-1, cur);
        cur.pop_back();
        dfs(n-1, cur);
    }

}
int main(){
  // 7*combos where it is (n*2^n-1 <-general answer formula)
    dfs(7, {});
  //dfs proves it but its simple to think of it like a dp question! js move ur startning node over!
    cout<<ans<<" "<<l;
}
