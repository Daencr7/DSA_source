#include <bits/stdc++.h>
using namespace std;
#define el cout<<"\n"
#define pb push_back
#define FOR0(i,n) for(ll i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<=n;i++)
#define ll long long


int n, k;
int arr[20];


int used[1000];

int total = 0;
int target;
bool check = false;
void Try(int subSum, int cnt) {
    if(check) return;
    if(subSum == target) {
        cnt++;
        subSum = 0;
    }
    if(cnt == k){
        check = true;
        return;
    }

    for(int i = 0; i < n; i++){
        if(!used[i] && subSum + arr[i] <= target){
            used[i] = true;
            Try(subSum + arr[i], cnt);
            used[i] = false;
        }
    }

}
   
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> k;
    // Try(1);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        total += arr[i];    
    }
    sort(arr, arr+n, greater<int>());
    if(total % k != 0 || n < k){
        cout << "0"; return 0;
    }
    if(k == 1){
        cout << "1"; return 0;
    }
    target = total / k;
    Try(0,0);
    if(check) cout << "1";
    else cout <<"0";




}
