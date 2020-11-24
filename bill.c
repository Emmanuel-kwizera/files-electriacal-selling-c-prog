#include<stdio.h>
#include<stdlib.h>
#include<time.h>

static void sellElectricity(){
	float units;
	int meter;
	int money;
	int vat;


	struct User user;
	//struct Category category;

	FILE * endUser;
	printf("\tWelcome to Electricity Selling \n");
	printf("\t_______________________________________________________\n\n");
	printf("Enter user meter number:");
	scanf("%d",&meter);

	endUser = fopen("files/endUsers.dat","rb+");
	while(fread(&user,sizeof(struct User),1,endUser)){
		if (meter == user.user_meter)
		{
			printf("\n\n\tMeter number is for %s\n",user.user_name);

			printf("Enter the Amount of money(greater than 500):");
			scanf("%d",&money);
			if (money > 500)
			{
				if(strcmp(user.user_category,"Residential")==0){
                        units=money/89;
                        if(units<16){
                            vat=89;
                        }else if(units<50){
                            vat= 182;
                            units=money/182;
                        }
                        else{
                            vat=210;
                            units=money/210;
                        }
                    }
                    else if(strcmp(user.user_category,"Non_Residential")==0){
                        units=money/204;
                        if(units<100){
                            vat=204;
                        }else{
                            vat=222;
                            units=money/222;
                        }
                    }else if(strcmp(user.user_category,"Telecom_Towers")==0){
                    	units=money/185;
                    }else if(strcmp(user.user_category,"Water_Stations")==0){
                    	units=money/126;
                    }else if(strcmp(user.user_category,"Hotels")==0){
                    	units=money/126;
                    }else if(strcmp(user.user_category,"Health_Facilities")==0){
                    	units=money/192;
                    }else if(strcmp(user.user_category,"Broadcasters")==0){
                    	units=money/184;
                    }
			}

		}else{
		printf("Meter number does't exist...");
	}
	}
		int n = 0;
	FILE * reciepts;
	//FILE * userCate;

	struct Selling reciept;
	//struct Category category;

	reciepts = fopen("files/reciepts.dat","ab+");
	while(fread(&reciept,sizeof(struct Selling),1,reciepts)){
		n++;
	}
	fclose(reciepts);

	reciepts = fopen("files/reciepts.dat","ab+");
	reciept.reciept_id= n+1;
	srand(time(NULL));
	int token1;
	int token2;
	int token3;
	int token4;        
	for(int z=0;z<4;z++){
            reciept.token_num[z]=rand()%9999;
            if(reciept.token_num[z]<1000){
                reciept.token_num[z]+=1000;
            }
        }

	reciept.meter_number = user.user_meter;
	reciept.total_units = units;
	reciept.vat;
	reciept.total_amount = money;
	printf("\n\n\t\t\t\t__________________________________________________________\n");
    printf("\t\t\t\t|                      ESA RECIEPT                        |\n");
    printf("\t\t\t\t__________________________________________________________\n");
    printf("\t\t\t\t|                                                         \n");
    printf("\t\t\t\t|             RECIEPT\t#\t%d                 \n",reciept.reciept_id);
    //printf("\t\t\t\t*             DATE AND TIME :\t%s              \n",reci[extreci].igihe);
    printf("\t\t\t\t|             CUSTOMER INFORMATION                       \n");
    printf("\t\t\t\t|             Names    :        %s         \n",user.user_name);
    printf("\t\t\t\t|             Meter number:     %d         \n",user.user_meter);
	printf("\t\t\t\t*\t  ----------------------------------------\n");
    printf("\t\t\t\t*\t\t%d - %d - %d - %d               \n",reciept.token_num[0],reciept.token_num[1],
    								reciept.token_num[2],reciept.token_num[3]);
    printf("\t\t\t\t*\t  ----------------------------------------\n");
    printf("\t\t\t\t|             Total units:\t%.1f Kwh\n",reciept.total_units);
    // printf("\t\t\t\t|             TVA 18\t :\t%d RWF\n",reciept.vat);
    printf("\t\t\t\t|             Total price:\t%d RWF\n",reciept.total_amount );
    printf("\t\t\t\t***********************************************************\n");
    printf("\t\t\t\t*                      THANK YOU                          *\n");
    printf("\t\t\t\t***********************************************************\n");
    fwrite(&reciept,sizeof(struct Selling),1,reciepts);
	fclose(reciepts);
	fclose(endUser);
}


static void viewUserReceipt(){
	int meter;
	struct User user;
	struct Selling reciept;
	//struct Category category;
	FILE * endUser;
	FILE * reciepts;
	//FILE * userCate;

	printf("\tWelcome to Electricity Selling \n");
	printf("\t_______________________________________________________\n\n");
	printf("Enter user meter number:");
	scanf("%d",&meter);	
	endUser = fopen("files/endUsers.dat","rb+");
	while(fread(&user,sizeof(struct User),1,endUser)){
		if (meter == user.user_meter)
		{

	reciepts = fopen("files/reciepts.dat","rb+");
	while(fread(&reciept,sizeof(struct Selling),1,reciepts)){
	printf("\n\n\t\t\t\t__________________________________________________________\n");
    printf("\t\t\t\t|                      ESA RECIEPT                        |\n");
    printf("\t\t\t\t__________________________________________________________\n");
    printf("\t\t\t\t|                                                         \n");
    printf("\t\t\t\t|             RECIEPT\t#\t%d                 \n",reciept.reciept_id);
    //printf("\t\t\t\t*             DATE AND TIME :\t%s              \n",reci[extreci].igihe);
    printf("\t\t\t\t|             CUSTOMER INFORMATION                       \n");
    printf("\t\t\t\t|             Names    :        %s         \n",user.user_name);
    printf("\t\t\t\t|             Meter number:     %d         \n",user.user_meter);
	printf("\t\t\t\t*\t  ----------------------------------------\n");
    printf("\t\t\t\t*\t\t%d - %d - %d - %d               \n",reciept.token_num[0],reciept.token_num[1],
    								reciept.token_num[2],reciept.token_num[3]);
    printf("\t\t\t\t*\t  ----------------------------------------\n");
    printf("\t\t\t\t|             Total units:\t%.1f Kwh\n",reciept.total_units);
    // printf("\t\t\t\t|             TVA 18\t :\t%d RWF\n",reciept.vat);
    printf("\t\t\t\t|             Total price:\t%d RWF\n",reciept.total_amount );
    printf("\t\t\t\t***********************************************************\n");
    printf("\t\t\t\t*                      THANK YOU                          *\n");
    printf("\t\t\t\t***********************************************************\n");
	}
}
}

	fclose(reciepts);
	fclose(endUser);
}

