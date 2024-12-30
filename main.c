#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "functions.h"
int main(int argc, char *argv[]) {
	int choice,Choice1;
	int length =0;
	Student students[100];
	do{
		displayMenu();
		scanf("%d",&Choice1);
		getchar();
		switch(Choice1){
			case 1:
				loginAdmin();
				chooseYourRole(&choice,students,&length);
				break;
			case 2: 			
    			printfStudent(students,&length);
    			break;
    		case 3:
				break; 
    		case 0:
    			end();
    			break;
			default:
				printf("Lua chon khong hop le. Vui long chon lai\n");
				break;
		}
	}while(Choice1!=0);
	return 0;
}
