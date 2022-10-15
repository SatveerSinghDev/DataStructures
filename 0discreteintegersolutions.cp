
#include<iostream>
# define MAX 10;
using namespace std;
int main()
{
int x[10];//variable used in the ques
int counter=0;
for(x[0]=0;x[0]<=10;x[0]++)
 for(x[1]=0;x[1]<=10;x[1]++)
  for(x[2]=0;x[2]<=10;x[2]++)
   for(x[3]=0;x[3]<=10;x[3]++)
    for(x[4]=0;x[4]<=10;x[4]++)
     for(x[5]=0;x[5]<=10;x[5]++)
      for(x[6]=0;x[6]<=10;x[6]++)
       for(x[7]=0;x[7]<=10;x[7]++)
        for(x[8]=0;x[8]<=10;x[8]++)
         for(x[9]=0;x[9]<=10;x[9]++)
           if(x[0]+x[1]+x[2]+x[3]+x[4]+x[5]+x[6]+x[7]+x[8]+x[9]==10)
           {
           counter++;
           cout<<counter<<"."<<x[0]<<","<<x[1]<<","<<x[2]<<","<<x[3]<<","<<x[4]<<","<<x[5]<<","<<x[6]<<","<<x[7]<<","<<x[8]<<","<<x[9]<<"\n";
           }
           return 1;
}           
