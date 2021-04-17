#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int arr[a.length() + 1][b.length() + 1];
    for(int i = 0; i <= a.length(); i++){
        for(int j = 0; j <= b.length(); j++){
            arr[i][j] = 0;
        }
    }
    for(int i = 0; i <= a.length(); i++){
        arr[i][0] = i;
    }
    for(int i = 0; i <= b.length(); i++){
        arr[0][i] = i;
    }
    bool check;
    for(int i = 0; i < a.length(); i++){
        for(int j = 0; j < b.length(); j++){
            if(a[i] == b[j])
            check = false;
            else
            check = true;
            arr[i + 1][j + 1] = min(min(arr[i][j + 1] + 1,arr[i + 1][j] + 1),arr[i][j] + check);
        }
    }
    cout << arr[a.length()][b.length()];
}
