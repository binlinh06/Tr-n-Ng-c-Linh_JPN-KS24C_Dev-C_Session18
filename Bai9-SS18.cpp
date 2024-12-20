#include<stdio.h>
#include<string.h>
int main(){
	struct Dish{
		int ID;
		char Name[50];
		double Price;
	};
	
	struct Dish DishMenu[100]={
		{1,"Pho bo",30},
		{2,"Com rang",40},
		{3,"My Y",45},
		{4,"Pizza",150},
		{5,"Cua hoang de",1000},
		};
    int choice;
    int count=0;
    int size=5;
    int pos = size;
    char temp[50];
    char TimKiem[50];
    int found=0;
	do{
		
	    
		printf("\n");
		printf("====================MENU====================\n");
		printf("1.In ra gia tri cac phan tu co trong menu mon an.\n");
		printf("2.Them mot phan tu vao vi tri chi dinh.\n");
		printf("3.Sua mot phan tu o vi tri chi dinh\n");
		printf("4.Xoa mot phan tu o vi tri chi dinh.\n");
		printf("5.Sap xep cac phan tu.\n");
		printf("6.Tim kiem phan tu theo name nhap vao.\n");
		printf("7.Thoat\n");
		printf("Vui long lua chon:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				for(int i=0;i<size;i++){
					DishMenu[i].ID=i+1;
					printf("%d.",DishMenu[i].ID);
					printf("%s",DishMenu[i].Name);
					printf(":%.3lf",DishMenu[i].Price);
					printf("\n");
					count++;
					printf("\n");
				}
				break;
			
			case 2:
				DishMenu[size].ID=size+1;
				fflush(stdin);
				printf("Vui long nhap ten mon an:");
				fgets(DishMenu[size].Name,sizeof(DishMenu[size].Name),stdin);
				strtok(DishMenu[size].Name, "\n");
				printf("Vui long nhap gia tien:");
				scanf("%lf",&DishMenu[size].Price);
				size++;
				break;
			
			case 3:
                if (size <= 0) {
                    printf("Menu khong co mon an nao de sua!\n");
                } else {
                    printf("Nhap ten mon an moi:");
                        fflush(stdin);
                        fgets(DishMenu[pos].Name, sizeof(DishMenu[pos].Name), stdin);
				        strtok(DishMenu[pos].Name,"\n");
				        printf("Nhap gia tien moi:");
				        scanf("%lf",&DishMenu[size].Price);
				    }
                break;
            
            case 4:
            	if (size <= 0) {
                    printf("Menu khong co mon an nao de xoa!\n");
                }else{
                	size--;
				}
				break;
			case 5:
				for(int i=0;i<size-1;i++){
                for(int j=0; j<size-i-1;j++){
                        if (DishMenu[j].Price > DishMenu[j + 1].Price) {
                        	 struct Dish temp = DishMenu[j];
                                DishMenu[j] = DishMenu[j + 1];
                                DishMenu[j + 1] = temp;
                        }   
            		}
        		}
        		break;
        	case 6:
        		printf("Nhap mon an can tim:");
        		fflush(stdin);
        		fgets(TimKiem,sizeof(TimKiem),stdin);
        		strtok(TimKiem,"\n");
	        		for(int i=0;i<size;i++){
	        			if(strcasecmp(DishMenu[i].Name,TimKiem)==0){
	        				printf("%d.",DishMenu[i].ID);
							printf("%s",DishMenu[i].Name);
							printf(":%.3lf",DishMenu[i].Price);
							printf("\n");
							found=1;
						}
				    }
					if(!found){
						printf("Khong tim thay mon an ten '%s'.\n",TimKiem);	
					}
				break;
			case 7:
				printf("THOAT!!!!");
				break;
			default:
                printf("Lua chon khong hop le, vui long thu lai!\n");
		}
		
	}while(choice!=7);

return 0;
}

