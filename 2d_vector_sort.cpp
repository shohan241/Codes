#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
bool cmp(vector<int>a, vector<int>b){
   return a[0] < b[0];
}

void sortkoro(vector<vector<int>>&a){
   int r, c;
   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         if(a[i][j] == 1){
            r = i, c = j;
            break;
         }
      }
   }

   swap(a[0], a[r]);
   for(int i = 0; i < n; i++){
      swap(a[i][0], a[i][c]);
   }

   sort(a.begin(), a.end(), cmp);
   vector<vector<int>>transpose(m, vector<int>(n));

   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         transpose[j][i] = a[i][j];
      }
   }
   sort(transpose.begin(), transpose.end(), cmp);

   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
         a[i][j] = transpose[j][i];
      }
   }   
}

void solve() {
   cin >> n >> m;
   vector<vector<int>>a(n, vector<int>(m));
   for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++) cin >> a[i][j];
   }
   sortkoro(a);
}

int main() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

   ll t = 1;
   cin >> t; 

   for (ll tc = 1; tc <= t; tc++) {
      // cout << "Case " << tc << ": ";
      solve();
   }
}
