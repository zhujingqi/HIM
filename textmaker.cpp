#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cout<<"Input string: ";
    getline(cin,s);
    int p=0;
    for(char ch:s)
	{
        int t=(unsigned char)ch;
        int d=t-p;
        if(d>0)for(int i=0;i<d;i++)cout<<"ha ";
        else for(int i=0;i<-d;i++)cout<<"he ";
        cout<<"hahe ";
        p=t;
    }
    cout<<endl;
    return 0;
}

