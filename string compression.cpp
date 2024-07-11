# include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int hash[26];
    for (int i = 0; i < s.size(); i++)
    {
        i++;
        int temp = 0;
        while(i<s.size() && s[i]>='0' && s[i]<='9'){
            temp = temp * 10 + s[i] - '0';
            i++;
        }
        i--;
        hash[s[i] - 'a'] += temp;
    }
    for (int i = 0; i < 26; i++){
        if(hash[i]!=0){
            char c = i + 'a';
            cout << c << " " << hash[i] << " ";
        }
    }
}