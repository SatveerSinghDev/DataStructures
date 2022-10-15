#include<iostream>
using namespace std;
int step=0;
void hanoi(int n,char source,char aux, char dest)
{
    if(n==1)
    {
    step++;
    cout<<"Step-"<<step<<". Move disk "<<n<<" from peg "<<source<<" to peg "<<dest<<"\n";
    return;
    }
    hanoi(n-1,source,dest,aux);
    step++;
    cout<<"Step-"<<step<<". Move disk "<<n<<" from peg "<<source<<" to peg "<<dest<<"\n";
    hanoi(n-1,aux,source,dest);
}
int main()
{
int n;
cout<<"Enter number of disks:";
cin>>n;
hanoi(n,'A','B','C');
return 1;
}
