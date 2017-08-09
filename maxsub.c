#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int lengthOfLongestSubstring(char* s) {
   int i=0,j=0,max=1;
   char *cnt = (char *)malloc(256*sizeof(char));
   if(s[0]=='\0')
   {
       return 0;
   }

   while(*s!='\0')
   {
    i=0,j=0;
    memset(cnt,0,256);
    cnt[s[0]]=1;
    while(s[j+1]!='\0')
    {
        if(cnt[s[j+1]]!=0)
        {
            max = j-i+1>max?j-i+1:max;
            memset(cnt,0,256);
            j=j+1;
            i=j;
            cnt[s[j]]=1;
        }
        else
        {
            j=j+1;
            cnt[s[j]]=1;
            max = j-i+1>max?j-i+1:max;
        }
    }
    s++; 
   }
   free(cnt);
   return max;
}
int main()
{
   char *s = malloc(256);
   int ans;
   while(1)
   {
        scanf("%s",s);
        ans = lengthOfLongestSubstring(s);
        printf("%d",ans);
   }
    

}