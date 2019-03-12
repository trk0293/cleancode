#include<stdio.h>
#include<stdlib.h>


//algo
char* algo(char* str){
char* str_b = str;
while(*str){
if((*str<0x5b)&&(*str>0x40))*str=*str|0x60;
str++;
}
return str_b;
}


//Driver program

int main(int argc, const char* argv[]){
char* str="Hello";
char* str_r=algo(str);
printf("%s",str_r);
return 0;
}
