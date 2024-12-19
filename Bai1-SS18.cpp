#include<stdio.h>
int main(){
	struct SinhVien{
		char name[20];
		int age;
		char phoneNumber[20];
	};
	
	struct SinhVien user01={"Tran Ngoc Linh",18,"0838169181"};
	struct SinhVien user02;
	
	printf("In thong tin Sinh Vien:\n");
	printf("%s\n",user01.name);
	printf("%d\n",user01.age);
	printf("%s\n",user01.phoneNumber);


return 0;
}

