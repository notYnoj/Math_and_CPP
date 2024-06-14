//Question: Given set X = {1,2,3...n} and y = {1,2,3}. Define a function such that when inputting x it maps every integer onto one from y
//a Function is called onto if it the range of the resulting set after inputting x = y;
//find a closed equation that gives the number onto functions

//intial observations: n = 1 and n=2 gives off 0 thus our final function must have zeros at n=1 and n=2
//second observations 3^n subsets from all functions
//now we're tasked to find the subsets such that f(x) intersects y = y
//this is defined as 3^n -(sets with 1 + sets with 2 + sets with 3) + sets with 1 + 2 sets with 2 and 3 + sets with 1 and 3  (principle of exclusion and inclusion)
//now this probelm can be redefined as sets with 1 - sets with 1 and without 2 ...
//this cancels out the other sets with 1
//leaves us with 3^n - sets with 1 and without 2...
//due to symmetry we get 3^n - 3(z)
//z = 2^n -1 (we have the choices between x and y [such that it doent include z] {for example choose between 1 and 3 so it doesnt include 2]}
//however we have to make sure to include 1 so we subtract by 1 (if we think of this as a tree where node->left represents choosing 1 and node->right represents choosing 3
//theres a path all the way to the right such that we include only 3 thus we subtract by that path
//this all verfied by the below code
//thanks linnrue for the question it was fun (also trust u did help!):D
#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int ans2 = 0;
vector<vector<int>> hold, one_twoo;
int one =0, two = 0, three = 0, one_two, one_three, two_three;
void dfs(int moves, vector<int>cur){
    if(moves == 0){
        ans2++;
        bool s1s = false;
        bool s2s = false;
        bool s3s = false;
        for(int i: cur){
            if(i == 1) s1s = true;
            if(i == 2) s2s = true;
            if(i == 3) s3s = true;
        }
        if(s1s) {
            one++;
            if(!s2s){
                one_twoo.push_back(cur);
                one_two++;
            }
            if(!s3s){
                one_three++;
            }
        }
        if(!s2s){
            two++;
            if(s3s){
                two_three++;
            }
        }
        if(s3s){
            three++;
        }
        if(s1s && s2s && s3s) {
            ans++;
            hold.push_back(cur);
        }
        return;
    }
    for(int i = 1; i<=3; i++){
        cur.push_back(i);
        dfs(moves-1, cur);
        cur.pop_back();
    }
}
int main(){
    dfs(9, {});
    for(auto i: one_twoo){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<"\n";
    }
    cout<<ans<<" ";
    cout<<ans2-one_three-one_two-two_three<<" ";
    cout<<one_two<<" "<<two_three<<" "<<one_three;
    //final equatiuon is 3^n  - 3*(2^n-1)
}
