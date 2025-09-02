#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 100
#define N 10
void binary_addition(char *a,char *b,char *result)
{
int len=strlen(a);
int carry=0;
int i;
for(i=len-1;i>=0;i--){
int bit1=a[i]-'0';
int bit2=b[i]-'0';
int sum=bit1+bit2+carry;
result[i]=(sum%2)+'0';
carry=sum/2;
}
result[len]='\0';
if(carry==1){
char carry_str[MAX],temp[MAX];
for(i=0;i<len;i++)
carry_str[i]='0';
carry_str[len-1]='1';
carry_str[len]='\0';
strcpy(temp,result);
binary_addition(temp,carry_str,result);
}
}
void ones_complement(char *bin,char *comp){
int len=strlen(bin);
int i;
for(i=0;i<len;i++){
if(bin[i]=='1')
comp[i]='0';
else comp[i]='1';
}
comp[len]='\0';
}
int main(){
int n,i,len;
char data[N][MAX];
char sum[MAX],temp[MAX],checksum[MAX];
clrscr();
printf("enter the number of blocks in data:");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("enter data block %d:",i+1);
scanf("%s",data[i]);
}
len=strlen(data[0]);
strcpy(sum,data[0]);
for(i=1;i<n;i++){
binary_addition(sum,data[i],temp);
strcpy(sum,temp);
}
ones_complement(sum,checksum);
printf("\n Checksum :%s",checksum);
getch();
return 0;
}