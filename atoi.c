#include<stdio.h>
int if_digit(char);
int atoi_str(const char*);
int main(){
	char s[200];
	printf("enter the string:\n");
	scanf("%[^\n]",s);
	printf("%d\n",atoi_str(s));
	return 0;
}
int if_digit(char ch){
	if(ch>='0' && ch<='9')
		return 1;
	else
		return 0;
}
int atoi_str(const char *p){
	int i=0,sign=1,digit,result=0;
	while(p[i]==' ' || p[i]=='\t')
		i++;
	if(p[i]=='-'){
		sign=-1;
		i++;
	}
	else if(p[i]=='+'){
		sign=1;
		i++;
	}
	while(if_digit(p[i])){
		digit=p[i]-'0';
		result=result*10+digit;
		i++;
	}
	return result*sign;
}

