#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int getRow(int pos,int numRows)
{
    int r;
    pos = pos%(2*numRows-2);
    r = pos>=numRows?2*numRows-2-pos:pos;
    return r;
}

char* convert(char* s, int numRows) {
    int n = strlen(s);
    if(n==0||numRows==1||n<=numRows)
    return s;
    char *r = malloc(n+1);
    const int len = n/(2*numRows-2)+1;
    char **p = malloc(numRows*sizeof(char *));
    char **q = malloc(numRows*sizeof(char *));;
    memset(r,0,n+1);
    for(int i=0;i<numRows;i++)
    {
        p[i]=malloc(2*len+1);
        q[i]=p[i];
        memset(p[i],0,2*len+1);
    }

    for(int i=0;i<n;i++)
    {
       int pos=i,row=0;
       q[getRow(i,numRows)][0]=s[i];
       q[getRow(i,numRows)]++;
    }

    for(int i=0;i<numRows;i++)
    {
        strcat(r,p[i]);
    }
    return r;
}

int main(int argc,char*argv[])
{
    int numRows=0;
    sscanf(argv[1],"%d",&numRows);
    char *line = convert(argv[2],numRows);
    printf("%s\n",line);
}