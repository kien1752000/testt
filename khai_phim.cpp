#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e4+1;
int a[MAX], b[MAX];
int n, m;
int S[MAX][MAX];

void input(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
}

void solve(){
    for(int i = 0; i <= n; i++) S[i][0] = 0;
    for(int i = 0; i <= m; i++) S[0][i] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j]) S[i][j] = max(S[i][j], S[i-1][j-1] + 1);
            else S[i][j] = max(S[i-1][j], S[i][j-1]);
        }
    }
    cout << S[n][m] << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    input();
    solve();
    return 0;
}
