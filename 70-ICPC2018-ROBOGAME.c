// https://www.codechef.com/problems/ROBOGAME

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int a[55],l,i,j,x,m,n,count,flag;
    char s[55];
    long long int t,k;

    scanf("%lld",&t);
    for(k=0;k<t;k++)
    {
        scanf("%s",s);
        l=strlen(s);
        count=0;
        flag=0;


      for(i=0;i<l;i++)
      {
        if(s[i]!='.')
        {
            x=s[i]-'0';
            count=0;
            m=i-x;
            n=i+x;
            if(m<0)
                m=0;
            if(n>l-1)
                n=l-1;

            for(j=m;j<=n;j++)
            {
                if(i!=j && s[j]!='.')
                {
                        flag=1;
                        break;
                }

            }
            s[n]='0';
            s[m]='0';
        }
      }
    if(flag==0)
        printf("safe\n");
    else
        printf("unsafe\n");

    }

    return 0;
}
