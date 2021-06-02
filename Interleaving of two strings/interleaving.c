#include<stdio.h> 
#define bool int 
#define true 1
#define false 0


    //Recursive approach (More time complexity, less space complexity)
    bool isInterleave(char * s1, char * s2, char * s3){
    if(!(*s1||*s2||*s3))
        return true;
    
    if(!(*s3))
        return false;
    
    return (*s1==*s3 && isInterleave(s1+1,s2,s3+1)) || (*s2==*s3 && isInterleave(s1,s2+1,s3+1));
}


int main()
{
    char *s1="aabcc",*s2="dbbca",*s3="aadbbcbcac";
    printf(((isInterleave(s1,s2,s3))?"true":"false"));
}