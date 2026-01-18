#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<stack>
#include<map>
using namespace std;
vector<string> tok(const string &c){
    vector<string> t; string s; stringstream ss(c);
    while(ss>>s) t.push_back(s);
    return t;
}
int main(){
    vector<int> mem(30000,0);
    int p=0;
    string line;
    cout<<"Please input your Haha code:"<<endl;
    getline(cin,line);
    vector<string> code = tok(line);
    map<int,int> ls2e, le2s;
    stack<int> st;
    for(int i=0;i<code.size();++i){
        if(code[i]=="ho") st.push(i);
        else if(code[i]=="hoho"){
            if(st.empty()){cerr<<"ERROR: Mismatched 'hoho'"; return 1;}
            int s=st.top(); st.pop();
            ls2e[s]=i; le2s[i]=s;
        }
    }
    if(!st.empty()){cerr<<"ERROR: Mismatched 'ho'"; return 1;}
    map<int,int> lv;
    int glv=-1;
    for(int ip=0;ip<code.size();++ip){
        string c=code[ip];
        if(c=="ha") mem[p]++;
        else if(c=="he") mem[p]--;
        else if(c=="hah"){p++; if(p>=mem.size()) mem.push_back(0);}
        else if(c=="heh"){p--; if(p<0){cerr<<"ERROR: Pointer out of bounds"; return 1;}}
        else if(c=="haha") cout<<mem[p]<<" ";
        else if(c=="hahe") cout<<char(mem[p])<<" ";
        else if(c=="hehe"){int v; cin>>v; mem[p]=v;}
        else if(c=="hahaha") glv=mem[p];
        else if(c=="ho"){if(lv.find(ip)==lv.end()) lv[ip]=(glv!=-1?glv:1);}
        else if(c=="hoho"){int s=le2s[ip]; if(lv[s]>1){lv[s]--; ip=s;} else lv.erase(s);}
    }
    cout<<endl;
    cout<<"Press Enter to exit...";
    cin.get();
	cin.get();
    return 0;
}
/*
HIM (Haha In Mind) Coding Language Compiler
Developed by Jacky Zhu
Notes:
memory -> mem
ptr -> p
loop_start_to_end -> ls2e
loop_end_to_start -> le2s
loop_stack -> st
loop_var -> lv
global_loop_value -> glv
tokenize -> tok
Happy coding with HIM, programming that makes your mind laugh!
*/
