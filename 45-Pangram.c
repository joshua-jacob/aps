#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
    char str[n+1];
    int flag[26];
    scanf("%s",str);
    for(i=0;i<26;i++)
    flag[i]=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<26;j++)
        {
            if(str[i]=='A'+j)
            flag[j]=1;
            else if(str[i]=='a'+j)
            flag[j]=1;
        }
    }
    for(i=0;i<26;i++)
    {
        if(flag[i]==0)
        {
            printf("NO");
            exit(0);
        }
    }
    printf("YES");
    return 0;
}
