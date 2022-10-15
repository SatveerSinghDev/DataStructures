#include<iostream>
using namespace std;
int main()
{
int i,j;
int n;
while(n!=10)
{cout<<"1.CONJUNCTION\n";
cout<<"2.DISJUNCTION\n";
cout<<"3.EXCLUSIVE OR\n";
cout<<"4.CONDITIONAL\n";
cout<<"5.BI-CONDITIONAL\n";
cout<<"6.EXCLUSIVE NOR\n";
cout<<"7.NEGATION\n";
cout<<"8.NAND\n";
cout<<"9.NOR\n";
cout<<"10.Quit\n";
cout<<"Enter your choice:";
cin>>n;
switch(n)
{
case 1: cout<<"\nTruth table\n";
            cout<<"X"<<"  "<<"Y"<<"  "<<"X AND Y\n";
            for(i=0;i<=1;i++)
               for(j=0;j<=1;j++)
                     {
                         int p=(i&j);
                    if(p==0)
                        cout<<i<<"  "<<j<<"    "<<"0";
                    else
                        cout<<i<<"  "<<j<<"    "<<"1";
                    cout<<"\n";

                    }

            break;
    case 2:cout<<"\nTruth table\n";
            cout<<"X"<<"  "<<"Y"<<"  "<<"X OR Y\n";
            for(i=0;i<=1;i++)
               for(j=0;j<=1;j++)
                     {
                         int p=(i|j);
                    if(p==0)
                        cout<<i<<"  "<<j<<"    "<<"0";
                    else
                        cout<<i<<"  "<<j<<"    "<<"1";
                    cout<<"\n";

                    }
            break;
    case 3:cout<<"\nTruth table\n";
            cout<<"X"<<"  "<<"Y"<<"  "<<"X ^ Y\n";
            for(i=0;i<=1;i++)
               for(j=0;j<=1;j++)
                     {
                         int p=(i^j);
                    if(p==0)
                        cout<<i<<"  "<<j<<"    "<<"0";
                    else
                        cout<<i<<"  "<<j<<"    "<<"1";
                    cout<<"\n";

                    }
            break;
    case 4:cout<<"\nTruth table\n";
            cout<<"X"<<"  "<<"Y"<<"  "<<"X -> Y\n";
            for(i=0;i<=1;i++)
               for(j=0;j<=1;j++)
                     {
                         int p=(!i|j);
                    if(p==0)
                        cout<<i<<"  "<<j<<"    "<<"0";
                    else
                        cout<<i<<"  "<<j<<"    "<<"1";
                    cout<<"\n";

                    }
            break;
    case 5:cout<<"\nTruth table\n";
            cout<<"X"<<"  "<<"Y"<<"  "<<"X <-> Y\n";
            for(i=0;i<=1;i++)
               for(j=0;j<=1;j++)
                     {
                         int p=((!i|j)&&(!j|i));
                    if(p==0)
                        cout<<i<<"  "<<j<<"    "<<"0";
                    else
                        cout<<i<<"  "<<j<<"    "<<"1";
                    cout<<"\n";

                    }
            break;
    case 6:cout<<"\nTruth table\n";
            cout<<"X"<<"  "<<"Y"<<"  "<<"X EX-NOR Y\n";
            for(i=0;i<=1;i++)
               for(j=0;j<=1;j++)
                     {
                         int p=(!(i^j));
                    if(p==0)
                        cout<<i<<"  "<<j<<"     "<<"0";
                    else
                        cout<<i<<"  "<<j<<"     "<<"1";
                    cout<<"\n";

                    }
            break;
    case 7:cout<<"\nTruth table\n";
            cout<<"X"<<"  "<<"!X"<<"\n";
            for(i=0;i<=1;i++)
                     {
                         int p=(!i);
                    if(p==0)
                        cout<<i<<"   "<<"0";
                    else
                        cout<<i<<"   "<<"1";
                    cout<<"\n";

                    }
            break;
    case 8:cout<<"\nTruth table\n";
            cout<<"X"<<"  "<<"Y"<<"  "<<"X NAND Y\n";
            for(i=0;i<=1;i++)
               for(j=0;j<=1;j++)
                     {
                         int p=(!(i&j));
                    if(p==0)
                        cout<<i<<"  "<<j<<"    "<<"0";
                    else
                        cout<<i<<"  "<<j<<"    "<<"1";
                    cout<<"\n";

                    }
            break;
    case 9:cout<<"\nTruth table\n";
            cout<<"X"<<"  "<<"Y"<<"  "<<"X NOR Y\n";
            for(i=0;i<=1;i++)
               for(j=0;j<=1;j++)
                     {
                         int p=(!(i|j));
                    if(p==0)
                        cout<<i<<"  "<<j<<"    "<<"0";
                    else
                        cout<<i<<"  "<<j<<"    "<<"1";
                    cout<<"\n";

                    }
            break;
    case 10:cout<<"THANK YOU\n";
            break;
    default:cout<<"Wrong choice!!!!\nEnter again";
}
}
    return 0;
}
