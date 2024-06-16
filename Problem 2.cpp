#include <bits/stdc++.h>
using namespace std;
//dp!
//this question entails finding how many possible layouts of 00, 01, 10, 11 tiles where the and of all any two "squares" != 3
//thus i use a simple bitmask dp thought process
int main(){
    int dp[10][4]; //choose 10 to be any number, im simply choosing 10 for sake of verifying
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i<4; i++){
        dp[0][i] = 1;
    }
  //each mask only makes a square with hte previous one, (this ensures no squares all around)
  //js check for each n (row) iterate over the masks and add!
  //final TC comes out to be mask^2*n. if we consider mask^2 to be the constant 16 then its o(n)
    for(int i = 1; i<10; i++){
        for(int mask = 0; mask<4; mask++){
            for(int new_mask = 0; new_mask <4; new_mask ++){
                if(mask == 3 && new_mask == 3) continue; //makes a square
                dp[i][mask] += dp[i-1][new_mask];
            }
        }
    }
    int ans = 0; 
    //819, 216
    for(int i = 0; i<4; i++) ans+=dp[4][i]; //we can have any of the final masks to be good
    cout<<ans;
  //linnrues math proof of dp[n] = 3(dp[n-2]+dp[n-1])!
  //consider this as a tree
  //if doing so we can quickly see that for every node except (2 whites) we get 4 possibel nodes and for white we get 3
  //for every #4 we get (4^2-1 (the 4 original options - the one where we get WW+WW)) combos and for every 3 we get 3*4 = 12combos
  //now lets find a generalization -> 12(4*an-2 [this is becuz this generates all an-1] -an-1 [subtract by teh goood ones gives us all bad ones, since every 3 correspodnds to 1 bad one gives us what we want!]) +
  //15*(an-2 (total) - 3s which we got above), when we simplify this we get 3(dp[n-2]+dp[n-1]) amazing!
}
