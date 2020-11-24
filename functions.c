#include<stdio.h>
#include<string.h>

/*========================================  main Display ========================================*/

char pass[100];

static int allowedUsers(){
	int cate_user;
	printf("\n\n\n\t       Welcome to the Electricity Selling Application !!!    \n");
	printf("\t_______________________________________________________\n\n");
	printf("\t\tShose your User category\n");
	printf("\t\t1. 
	Admin\n");
	printf("\t\t2. Seller/User\n");
	printf("\n\t_______________________________________________________\n\n");
	printf("\t\tEnter your User Category          :");
	scanf("%d",&cate_user);
	if(cate_user == 1){
		return 1;
	}else if(cate_user == 2){
		return 2;
	}
		// return cate_user;
}

static void logIn(){

	printf("\n\n\n\t       Welcome to the Electricity Selling Application !!!    \n");
	printf("\t_______________________________________________________\n\n");
	printf("\t\tEnter your Passcode           : ");
	scanf("%s",pass);
}

static int sellerDashMenu(){
	int seller_choice;
	printf("\t       Welcometo the admin pannel Here is menu \n"); 
	printf("\t_______________________________________________________\n\n\n");
	printf("\t     1. Sell Electricity \n");
	printf("\t     2. View Customer Receipt \n");
	printf("\t     3. Exit \n");
	printf("\n\n\t_______________________________________________________\n\n");
	printf("\t\t\t Enter your choice      : ");
	scanf("%d",&seller_choice);
	return seller_choice;
}

static int adminDashMenu(){
	int choice;
	printf("\t       Welcometo the admin pannel Here is menu \n"); 
	printf("\t_______________________________________________________\n\n\n");
	printf("\n\t    I.0 USER MANAGMENT   \n");
	printf("\t     1. Insert a new user \n");
	printf("\t     2. view users \n");
	printf("\t     3. Update user \n");
	printf("\t     4. Delete user \n");
	printf("\n\t    II.0 METER MANAGMENT   \n");
	printf("\t     5. Activate a meter \n");
	printf("\t     6. De-activate a meter \n");
	printf("\t     7. Register a new meter \n");
	printf("\t     8. View availabe meters \n");
	printf("\n\t    III.0 PRICING MANAGMENT   \n");
	// printf("\n\t    IV.0 REGISTRATION  \n");
	// printf("\t     7. Insert a new client \n");
	printf("\n\n\t_______________________________________________________\n\n");
	printf("\t\t\t Enter your choice      : ");
	scanf("%d",&choice);
	return choice;
}



/*========================================  admin actions ========================================*/
/*========================================  start users functions =================================*/
static int meter_gen(){
 	int x;

	FILE * metersFile;

	struct Meter meter;

	metersFile = fopen("files/meters.dat","rb");
	printf("Availabe meter numbers\n");
	while(fread(&meter,sizeof(struct Meter),1,metersFile)){
		if (meter.meter_status == 0)
		{
			printf("\t    Meter No         : %d \n",meter.meter_no);
			//x = meter.meter_no;
			printf("\n");
		}
	}
	fclose(metersFile);
	return 0;
}



static void insertANewUser(){
	int n = 0;
	FILE * endUser;
	//FILE * userCate;

	struct User user;
	//struct Category category;

	endUser = fopen("files/endUsers.dat","ab+");
	while(fread(&user,sizeof(struct User),1,endUser)){
		n++;
	}
	fclose(endUser);

	endUser = fopen("files/endUsers.dat","ab+");


	printf("%d\n", meter_gen());

	//char temp[100];
	user.user_id = n+1;
	printf("  Welcome to insert a new user   :-  \n\n");
	printf(" Customer on user id            : %d \n",user.user_id);
	printf(" Enter the user names         : ");
	scanf("%s",user.user_name);
	printf(" Enter the user National id no    : ");
	scanf("%s",user.user_ID_card_no);
	printf(" Enter the email or tel       : ");
	scanf("%s",user.emailOrTel);
	printf(" Enter the Provience          : ");
	scanf("%s",user.Provience);
	printf(" Enter the District           : ");
	scanf("%s",user.District);
	printf("\n");


	//userCate = fopen("files/endUsersCategory.dat","ab+");

	int choice_cate;

	printf("SELECT YOUR USER CATEGORY HERE:\n");
  	printf("\t1. Residential Area\n");
  	printf("\t2. Non Residential Area\n");
  	printf("\t3. Telecom Towers\n");
  	printf("\t4. Water Treatment plants and Water pumping stations\n");
  	printf("\t5. Hotels\n");
  	printf("\t6. Health Facilities\n");
  	printf("\t7. Broadcasters\n");

	printf("\n");
  	printf(" Enter the user category      : ");
  	scanf("%d",&choice_cate);
   	switch (choice_cate)
   	{
   	case 1:
     strcpy(user.user_category,"Residential");
     break;
        case 2:
     	strcpy(user.user_category,"Non_Residential");
     break;
        case 3:
     	strcpy(user.user_category,"Telecom_Towers");
     break;
        case 4:
     	strcpy(user.user_category,"Water_Stations");
     break;
        case 5:
    	 strcpy(user.user_category,"Hotels");
     break;
        case 6:
      	strcpy(user.user_category,"Health_Facilities");
     break;
        case 7:
    	strcpy(user.user_category,"Broadcasters");
     break;

     default:
     break;
   } 

	//fwrite(&category,sizeof(struct Category),1,userCate);
	// fclose(userCate);

  	printf(" Enter the user meter      : ");
  	scanf("%d",&user.user_meter);

	fwrite(&user,sizeof(struct User),1,endUser);

	fclose(endUser);

}


static void getAllUsers(){

	struct User user;
	//struct Category category;

	FILE * endUser;
	//FILE * userCate;

	endUser = fopen("files/endUsers.dat","rb+");

	printf("\n\n       HERE IS THE USERS OF YOUR SYSYTEM     \n\n");

	while(fread(&user,sizeof(struct User),1,endUser)){
		printf("\tUser id [%d] \n",user.user_id);
		printf("\t    User Name      : %s \n",user.user_name);
		printf("\t    User ID no     : %s \n",user.user_ID_card_no);
		printf("\t    User Provience : %s \n",user.Provience);
		printf("\t    User District  : %s \n",user.District);
		printf("\t    User email     : %s \n",user.emailOrTel);	

		//userCate = fopen("files/endUsersCategory.dat","rb+");
	//while(fread(&category,sizeof(struct Category),1,userCate)){
		printf("\t    User Category  : %s \n",user.user_category);
		printf("\t    User meter  no : %d \n",user.user_meter);
		printf("\n");
		//}
	//fclose(userCate);

	}
	fclose(endUser);

	printf("\n\n\n");

	

}

static void updateUser(){

}

static void deleteUser(){

}

/*========================================  end users functions =================================*/
static void registerNewMeter(){

	int n =0;

	FILE * metersFile;

	struct Meter meter;

	metersFile = fopen("files/meters.dat","ab+");
	while(fread(&meter,sizeof(struct Meter),1,metersFile)){
		n++;
	}
	fclose(metersFile);



	metersFile = fopen("files/meters.dat","ab");
	meter.meter_id = n+1;


	printf("  Welcome to register a new meter   :-  \n\n");
	printf(" Enter the meter id            : %d\n",meter.meter_id);

	printf(" Enter the meter meter number  : ");
	scanf("%d",&meter.meter_no);
	int temp;
	printf(" Is meter active  [1/0]        : ");
	scanf("%d",&meter.meter_status);

	meter.meter_owned = 0;

	fwrite(&meter,sizeof(struct Meter),1,metersFile);

	fclose(metersFile);

}



static void viewAvailableMeter(){
	FILE * metersFile;

	struct Meter meter;

	metersFile = fopen("files/meters.dat","rb");
	printf("\n\n       HERE IS THE METERS IN YOUR SYSTEM     \n\n");

	while(fread(&meter,sizeof(struct Meter),1,metersFile)){

		printf("\tMeter id [%d] \n",meter.meter_id);
		printf("\t    Meter No         : %d \n",meter.meter_no);
		if(meter.meter_status == 1){
			printf("\t    Active           : Yes \n");
		}else{
			printf("\t    Active           : No \n");
		}
		if(meter.meter_owned == 1){
			printf("\t    Owned            : Yes \n");
		}else{
			printf("\t    Owned            : No \n");
		}
		printf("\n");
	}
	printf("\n\n\n");


	fwrite(&meter,sizeof(struct Meter),1,metersFile);

	fclose(metersFile);
}


static void activateAMeter(){
	struct  Meter meter;
	int meter_no_temp;
	printf("\tEnter the meter number you want to activate  : ");
	scanf("%d",&meter_no_temp);
	FILE * metersFile;
	int temptest = 0;
	metersFile = fopen("files/meters.dat","rb+");
	while(fread(&meter,sizeof(struct Meter),1,metersFile)){
		if(meter.meter_no == meter_no_temp){
			meter.meter_status = 1;
			meter.meter_owned = 1;

			if(fwrite(&meter,sizeof(struct Meter),1,metersFile)){
				printf("   Successfully  Activated  \n");
			}else{
				printf("   Not Successfully  Activated  \n");
			}

			temptest++;
		}
	}
	printf("You have the meter no of this %d \n",temptest );
}




static void deActivateAMeter(){
	struct  Meter meter;
	int meter_no_temp;
	printf("\tEnter the meter number you want to de activate  : ");
	scanf("%d",&meter_no_temp);
	FILE *metersFile;
	// int temptest = 0;
	metersFile = fopen("files/meters.dat","ab+");
	while(fread(&meter,sizeof(struct Meter),1,metersFile)){
		printf("%d\n",meter.meter_no);
		if(meter.meter_no == meter_no_temp){
			meter.meter_status = 0;
			meter.meter_owned = 0;
		
			if(fwrite(&meter,sizeof(struct Meter),1,metersFile)){
				printf("   Successfully de Activated  \n");
			}else{
				printf("   Not Successfully de Activated  \n");
			}
			

			// temptest++;
		}
	}
	//printf("You have the meter no of this %d \n",temptest );
}


static void insertUsermet(){
	FILE * usermetersFile = fopen("meters.dat","ab+");
}

/*========================================  pricing functions =================================*/

// static void givePrices(){
// 	struct User user;
// 	struct Price price;

// 	FILE * endUser;
// 	int price_am;
// 	int kwh;

// 	endUser = fopen("files/endUsers.dat","rb+");
// 	while(fread(&user,sizeof(struct User),1,endUser)){
// 		if (strcpy(user.user_category,"Residential"))
// 		{
// 			if (price_am == 89)
// 			{
// 				kwh <=15;
// 			}
// 		}
		
// strcpy(user.user_category,"Non_Residential");
// strcpy(user.user_category,"Telecom_Towers");
// strcpy(user.user_category,"Water_Stations");
// strcpy(user.user_category,"Hotels");
// strcpy(user.user_category,"Health_Facilities");
// strcpy(user.user_category,"Broadcasters");
// 	}
// 	fclose(endUser);

// }
