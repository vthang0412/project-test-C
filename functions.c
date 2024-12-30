#include <stdio.h>
#include <string.h>
#include "functions.h"
#include <stdlib.h>
// logic ham
// Menu Ten He Thong
void displayMenu(void){
	printf("\n***Student Management System Using C***\n");
	printf("CHOOSE YOUR ROLE\n");
	printf("===================\n");
	printf("[1]: Admin.\n");
	printf("[2]: Student.\n");
	printf("[3]: Teacher.\n");
	printf("[0]: Exit.\n");
	printf("===================\n");
	printf("Enter The Choice: ");
}
// Menu Admin
void menuAdmin(void){
	printf("\n***Student Management System Using C***\n");
	printf("		Menu\n");
	printf("=================================\n");
	printf("[1]: Students management.\n");
	printf("[2]: ClassRooms managemment.\n");
	printf("[3]: Teacher management.\n");
	printf("[4]: User Guideline.\n");
	printf("[5]: About Us.\n");
	printf("[0]: Menu \n");
	printf("Enter The Choice: ");
}
// Menu Student
void menuStudent(void){
	printf("\n***Student Management System Using C***\n");
	printf("		Student Menu\n");
	printf("==============================\n");
	printf("[1]: Add a new students.\n");
	printf("[2]: Show all students.\n");
	printf("[3]: Search a students.\n");
	printf("[4]: Edit a students.\n");
	printf("[5]: Delete a student.\n");
	printf("[6]: Sort Students By Name.\n") ;
	printf("[0]: Menu.\n");
	printf("Enter The Choice: ");
}
// Menu chon che do
void chooseYourRole(int *choice,Student students[], int *length) {
	do{
		int n;
		menuStudent();
		scanf("%d",choice);
		getchar();
		switch(*choice){
			case 1:
                inputStudent(students,length);
                break;
			case 2:	
				printfStudent(students,length);
				break;
			case 3:
				printf("3\n");
				break;
			case 4: 
				editStudent(students, length);
				break;
			case 5: 
				deleteStudent(students, length);
				break;
			case 6:
				break; 
			case 0: 
				
				break;
			default:
				printf("Lua chon khong hop le. Vui long chon lai.\n");
				break;
		}	
	}while(*choice!=0);
}
// Ham In Student
void printfStudent(Student students[], int *length) {
    if (*length == 0) {
        printf("\nNo students in the list.\n");
        return;
    }
    printf("\t----------***All Students***----------\n");
    printf("|==========|====================|========================|====================|============|\n");
    printf("|    ID    |        Name        |          Email         |        Phone       |  NO.Course |\n");
    printf("|==========|====================|========================|====================|============|\n");
	int i;
    for (i = 0; i < *length; i++) {
        printf("| %-8d | %-18s | %-22s | %-18s | %-10d |\n", 
               students[i].id, 
               students[i].name, 
               students[i].email, 
               students[i].phone, 
               students[i].courses);
        printf("|==========|====================|========================|====================|============|\n");
    }
    printf("\t \t---------------------\n");
}

void end(){
	printf("=========Thank You=========\n");
	printf("=========See You Soon======\n");
}
void inputStudent(Student students[], int *length) {
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    getchar();  
	int i; 
    for (i = 0; i < n; i++) {
        printf("Nhap thong tin cho sinh vien %d\n", i + 1);
        int id;
        // Kiem tra ID trung
        do {
            printf("Nhap ID sinh vien: ");
            scanf("%d", &id);
            getchar();  // Xoa ky tu newline
            int isDuplicate = 0;
            int j; 
            for (j = 0; j < *length; j++) {
                if (students[j].id == id) {
                    printf("\nID %d da ton tai. Vui long nhap ID moi.\n", id);
                    isDuplicate = 1;
                    break;
                }
            }
            if (!isDuplicate) break;
        } while (1);

        students[*length].id = id;

        // Nhap thong tin sinh vien
        void inputString(char *field, const char *prompt, int (*validate)(const char *)) {
            do {
                printf("%s", prompt);
                fgets(field, sizeof(students[*length].name), stdin);
                field[strcspn(field, "\n")] = '\0';  
                if (validate(field)) break;
            } while (1);
        }

        // Kiem tra ten
        int validateName(const char *name) {
        	int j; 
            for (j = 0; name[j]; j++) {
                if (!isalpha(name[j]) && !isspace(name[j])) {
                    printf("Ten khong hop le. Vui long chi su dung chu cai va dau cach.\n");
                    return 0;
                }
            }
            return 1;
        }
        inputString(students[*length].name, "Nhap ten sinh vien: ", validateName);

        // Kiem tra email
        int validateEmail(const char *email) {
            char *at = strchr(email, '@');
            char *dot = strrchr(email, '.');
            if (!at || !dot || at > dot) {
                printf("Dinh dang email khong hop le.\n");
                return 0;
            }
            return 1;
        }
        inputString(students[*length].email, "Nhap email sinh vien: ", validateEmail);

        // Kiem tra so dien thoai
        int validatePhone(const char *phone) {
            int len = strlen(phone);
            if (len < 10 || len > 11) {
                printf("So dien thoai phai co tu 10 den 11 chu so.\n");
                return 0;
            }
            int j; 
            for (j = 0; j < len; j++) {
                if (!isdigit(phone[j])) {
                    printf("So dien thoai chi duoc chua chu so.\n");
                    return 0;
                }
            }
            return 1;
        }
        inputString(students[*length].phone, "Nhap so dien thoai sinh vien: ", validatePhone);

        // Nhap so luong khoa hoc
        printf("Nhap khoa hoc cho sinh vien: ");
        scanf("%d", &students[*length].courses);
        getchar();  
        (*length)++;  
    }
}

void editStudent(Student students[], int *length) {
    if (*length == 0) {
        printf("Danh sach sinh vien hien dang trong. Khong co gi de sua.\n");
        return;
    }
    int id;
    printf("Nhap ID sinh vien muon sua: ");
    scanf("%d", &id);
    getchar();  
    
    // Tim sinh vien de sua 
    int found = -1;
    int i; 
    for (i = 0; i < *length; i++) {
        if (students[i].id == id) {
            found = i;
            break;
        }
    }
    if (found == -1) {
        printf("Khong tim thay sinh vien voi ID: %d\n", id);
        return;
    }

    // Hien thi thong tin hien tai cua sinh vien
    printf("\nThong tin hien tai cua sinh vien:\n");
    printf("ID: %d\n", students[found].id);
    printf("Ho Va Ten: %s\n", students[found].name);
    printf("So Dien Thoai: %s\n", students[found].phone);
    printf("Email: %s\n", students[found].email);
    char input[100];
    int valid;
    // Nhap ten moi
    do {
        printf("Ho Va Ten (Nhap so 0 de bo qua): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "0") == 0) break;
        valid = 1;
        int i;
        for (i = 0; input[i]; i++) {
            if (!isalpha(input[i]) && !isspace(input[i])) {
                valid = 0;
                printf("Ten khong hop le. Vui long nhap lai (chi chu va khoang trang).\n");
                break;
            }
        }
        if (valid) strcpy(students[found].name, input);
    } while (!valid);

    // Nhap so dien thoai moi
    do {
        printf("So Dien Thoai (Nhap so 0 de bo qua): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "0") == 0) break;
        valid = 1;
        int len = strlen(input);
        if (len < 10 || len > 11) {
            valid = 0;
            printf("So dien thoai khong hop le. Vui long nhap lai (do dai 10-11 ky tu).\n");
        } else {
        	int i;
            for (i = 0; i < len; i++) {
                if (!isdigit(input[i])) {
                    valid = 0;
                    printf("So dien thoai chi duoc chua so. Vui long nhap lai.\n");
                    break;
                }
            }
        }
        // Kiem tra so dien thoai co bi trung khong
        if (valid) {
        	int i;
            for (i = 0; i < *length; i++) {
                if (i != found && strcmp(students[i].phone, input) == 0) {
                    valid = 0;
                    printf("So dien thoai %s da ton tai. Vui long nhap so dien thoai khac.\n", input);
                    break;
                }
            }
        }

        if (valid) strcpy(students[found].phone, input);
    } while (!valid);

    // Nhap email moi 
    do {
        printf("Nhap Email (Nhap so 0 de bo qua): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';
        if (strcmp(input, "0") == 0) break;
        valid = 1;
        char *at = strchr(input, '@');
        char *dot = strrchr(input, '.');
        if (!at || !dot || at > dot) {
            valid = 0;
            printf("Email khong hop le. Vui long nhap lai (dinh dang x@y.z).\n");
        }

        //Kiem tra email co bi trung khong
        if (valid) {
        	int i;
            for (i = 0; i < *length; i++) {
                if (i != found && strcmp(students[i].email, input) == 0) {
                    valid = 0;
                    printf("Email %s da ton tai. Vui long nhap email khac.\n", input);
                    break;
                }
            }
        }
        if (valid) strcpy(students[found].email, input);
    } while (!valid);
    printf("Thong tin sinh vien da duoc cap nhat.\n");
}
void loginAdmin() {
    char email[50];  
    const char correctEmail[] = "vthang041206@gmail.com";  
    const char correctPassword[] = "123456";  
    char password[50]; 

    while (1) {
        printf("**** STORE MANAGEMENT **** \n");
        printf("\n\t    LOGIC \n");
        printf("Nhap Email: ");
        fgets(email, 50, stdin);
        email[strcspn(email, "\n")] = '\0'; 
        printf("Nhap Mat Khau: ");
        fgets(password, 50, stdin);
        password[strcspn(password, "\n")] = '\0'; 
        if (strcmp(email, correctEmail) == 0 && strcmp(password, correctPassword) == 0) {
            printf("Dang nhap thanh cong.\n");
            break;
        } else {
            printf("Email hoac mat khau sai, vui long nhap lai.\n");
        }
    }
}
void deleteStudent(Student students[], int *length) {
    int id, i, found = -1;

    // Nh?p ID sinh viên mu?n xóa
    printf("Nhap ID sinh vien muon xoa: ");
    scanf("%d", &id);

    // T?m sinh viên có ID trong danh sách
    for (i = 0; i < *length; i++) {
        if (students[i].id == id) {
            found = i;
            break;
        }
    }

    // N?u không t?m th?y sinh viên
    if (found == -1) {
        printf("Khong tim thay sinh vien voi ID: %d\n", id);
        return;
    }

    // Hi?n th? thông tin sinh viên c?n xóa
    printf("\nThong tin sinh vien can xoa:\n");
    printf("ID: %d\n", students[found].id);
    printf("Ho Va Ten: %s\n", students[found].name);
    printf("Email: %s\n", students[found].email);
    printf("So Dien Thoai: %s\n", students[found].phone);
    printf("So Khoa Hoc: %d\n", students[found].courses);

    // Yêu c?u xác nh?n xóa
    char confirm;
    printf("\nBan co chac chan muon xoa sinh vien nay (y/n)? ");
    getchar();  // Ð?c k? t? dý th?a t? buffer
    scanf("%c", &confirm);

    if (confirm == 'y' || confirm == 'Y') {
        // Xóa sinh viên
        for (i = found; i < *length - 1; i++) {
            students[i] = students[i + 1];  // D?ch chuy?n ph?n t?
        }
        (*length)--;  // Gi?m chi?u dài danh sách
        printf("Sinh vien da duoc xoa thanh cong.\n");
    } else {
        printf("Huy thao tac xoa sinh vien.\n");
    }
}





