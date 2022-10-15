#include<iostream>
#include<string.h>
using namespace std;
int main()
{
char per[30];
int n,i,j;
cout<<"Enter the digit\n";
cin>>per[i];
for(i=0;i<strlen(per);i++)
{
    cout<<per[i];
    for(j=0;j<strlen(per);j++)
    {
    if(i!=j)
    cout<<per[j];
    }
    cout<<endl;
}
return 0;
}
