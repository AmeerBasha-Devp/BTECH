#include<stdio.h>
#include<conio.h>
#include<string.h>
char t[28],cs[28],g[28]; int N;
int a,c,b,e;
void XOR()
{
for(c=1;c<N;c++)
cs[c]=((cs[c]==g[c]?'0':'1'));
}
void crc()
{
int i;
for(i=0; i<N; i++) cs[i] = t[i];
for(i=N; i<a+N; i++) {
if(cs[0] == '1') XOR();
for(c=0; c<N-1; c++) cs[c] = cs[c+1];
cs[N-1] = t[i];
}
}
int main(){
int flag=0;
do{
printf("\n1.CRC12\n2.CRC16\n3.CRCCCIP\n4.Exit\n\n");
printf("enter your Option");
scanf("%d",&b);
switch (b){
case 1: strcpy(g,"1100000001111"); N=strlen(g);
	break;
case 2:strcpy(g,"11000000000000101"); N=strlen(g);
	break;
case 3:strcpy(g,"10001000000100001"); N=strlen(g);
	break;
case 4:return 0;
}
printf("enter data:");
scanf("%s",t);
printf("\n---------------\n");
printf("\n Generating Polynomials:%s",g);
a=strlen(t);
for(e=a;e<a+N-1;e++)
t[e]='0';
printf("\n---------------\n");
printf("Modified Data is:%s",t);
printf("\n---------------\n");
crc();
printf("crc code is:%s",cs);
for(e=a;e<a+N-1;e++)
t[e]=cs[e-a];
printf("\n---------------\n");
printf("\n final codeword is:%s",t);
printf("\n reciever side\n");
printf("\n Test Error Detection 0(yes)|1(no)?: ");
scanf("%d",&e);
if(e==0){
do{
printf("\n\tEnter the position where error is to be inserted:");
scanf("%d",&e);
}
while(e<1||e>a+N-1);
t[e-1]=(t[e-1]=='0')?'1':'0';
printf("\t Erroroneous Data:%s \n",t);
crc();
}
for(e=0;(e<N-1)&&(cs[e]!='1');e++);
if(e<N-1)
printf("error detected \n\n");
else
printf("\n no error detected \n\n");
printf("\n----------------\n");
}
while(flag!=1);
}
