#include<iostream>
using namespace std;
 int step = 0;
 void ToHanoi(int n,char source,char Aux,char Dest)
 {
   if(n==1)
   {
     step++;
     cout<<"step-"<<step<<".Move Disk"<<n<<" from peg"<<source<<"to peg"<<Dest<<endl;
     return;
    }
    ToHanoi(n-1,source,Dest,Aux);
    step++;
    cout<<"step-"<<step<<".Move Disk"<<n<<"from peg"<<source<<"to peg"<<Dest<<endl;
    ToHanoi(n-1,Aux,source,Dest);
 }
 int main()
 {
 int n;
 cout<<"enter no of disks:";
 cin>>n;
 ToHanoi(n,'A','B','C');
 return 1;
}
