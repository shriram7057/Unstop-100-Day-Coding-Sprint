#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

vector<string> find_repeated_substrings(string& s) {
   vector<string>ans;
   map<string,int>m;
   int n=s.size();
   for(int i=0;i<=n-10;i++){
    string p;
    for(int j=i;j<i+10;j++){
        p.push_back(s[j]);
    }
    m[p]++;
   }
   set<string>q;
    for(int i=0;i<=n-10;i++){
    string p;
    for(int j=i;j<i+10;j++){
        p.push_back(s[j]);
    }
    if(m[p]>1 && q.find(p)==q.end()){
        q.insert(p);
        ans.push_back(p);
    }
   }
   return ans;
}

int main() {
    string s;
cin>>s;
    
    // Call user logic function and print the output
    vector<string> result = find_repeated_substrings(s);
    for (auto &substring : result) {
        cout << substring << " ";
    }
    cout<<endl;
    return 0;
}