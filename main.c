#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "structures.c"
#include "bill.c"
#include "functions.c"

int main()

{
	system("clear");
	int option;
	int cont;
	int seller;
	//int user;
	// allowedUsers();
	if ( allowedUsers() == 1)
	{
		logIn();
	if( strcmp(pass,"admin123") == 0 ){
		do{
			system("clear");
			if(option == 1){
				insertANewUser();
		 	}else if(option == 2){
		 		getAllUsers();
		 	}else if(option == 3){
				updateUser();
			}else if(option == 4){
				deleteUser();
			}else if(option == 5){
				activateAMeter();
			}else if(option == 6){
				deActivateAMeter();
			}else if(option == 7){
				registerNewMeter();
			}else if(option == 8){
				viewAvailableMeter();
			}


			printf("    Do you want to continue [1/0]  :");
			scanf("%d",&cont);
			if(cont == 0){
				option = -1;
			}else{
				system("clear");
				option = adminDashMenu();
			}
		}while(option != -1);
	}else{
		printf("Please Wait a moment ...\n");
	}


	}else if (allowedUsers() == 2)
	{
		logIn();
			if( strcmp(pass,"kalisa100") == 0 ){
		do{
			system("clear");
			if(seller == 1){
				sellElectricity();
			}else if (seller == 2)
			{
				viewUserReceipt();
			}else if (seller == 3)
			{
				allowedUsers();
			}


			printf("    Do you want to continue [1/0]  :");
			scanf("%d",&cont);
			if(cont == 0){
				seller = -1;
			}else{
				system("clear");
				seller = sellerDashMenu();
			}
		}while(seller != -1);
	}else{
		printf("Please Wait a moment ...\n");
	}
	}
	
	return 0;
}