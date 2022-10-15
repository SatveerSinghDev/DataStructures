#include<iostream>

using namespace std;
int Int=0;

int integer(char*str,int currentlength)
{
    int i=0;
    Int=0;
      if(currentlength==2)
                {
                   for(i=0;i<=currentlength;i++)
                    {
                         if(i==0)
                          Int=Int+(str[i]-'0')*100;
                         else if(i==1)
                          Int=Int+(str[i]-'0')*10;
                         else
                          Int=Int+(str[i]-'0');
                    }
                }
              else if(currentlength==1)
                {
                    for(i=0;i<=currentlength;i++)
                    {
                        if(i==0)
                          Int=Int+(str[i]-'0')*10;
                        else
                          Int=Int+(str[i]-'0');
                    }
                }
                else
                    Int=Int+(str[i]-'0');
           
              return(Int);
}

void binary(int q)
{   
   int num=0;
    char rev[8],temp;
    while(q!=0)
    {
      rev[num++]=q%2 + '0';
      q=q/2;
    }
    if(num!=1)
    {
    int start=0;
    int end=num-1;
    while(start<end)
    {
		temp=rev[start];
		rev[start]=rev[end];
		rev[end]=temp;
		start++;end--;
	}
  }
  for(int i=0;i<num;i++)
    cout<<rev[i];
    cout<<".";
}

int main()
{
    int i,j,a,x=0,l,currentlength=0;
    string str;
    char ch[3]={0,0,0};
    xy:
    cout<<"Enter the IP address :";
    cin>>str;
    l=str.length();
    //ERROR DETECTION
        for(j=0;j<l;j++)
    {
      if(str[j]=='.')
      {
         if(x==4)
          {
              for(i=0;i<x-1;i++)
                    {
                         if(i==0)
                          Int=Int+(ch[i]-'0')*100;
                         else if(i==1)
                          Int=Int+(ch[i]-'0')*10;
                         else
                          Int=Int+(ch[i]-'0');
                    }
                    if(Int>255)
                     {
						 cout<<Int;
						 cout<<"\n\t\tERROR!!!\nEnter a valid ip address\n";
						 goto xy;
		            }
		    }        		            
         x=0;
      }
      else
        { 
			ch[x]=str[j];
            x++;
        }  
    }
    
    cout<<"\nIP4 coverted to binary is: ";
  
    for(j=0;j<l;j++)
    {
      if(str[j]=='.')
      {
         currentlength=x-1;
         a=integer(ch,currentlength);
         binary(a);
         x=0;
      }
      else
        { ch[x]=str[j];
          x++;
        }  
    }
}


