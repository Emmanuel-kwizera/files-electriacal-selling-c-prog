#include<stdio.h>
#include<stdlib.h>


struct User
{
    int user_id;
    char user_name[100];
    char user_ID_card_no[16];
    char Provience[100];
    char District[100];
    char emailOrTel[200];
    char user_category[30];
    int user_meter;
};


struct Category
{
    int category_id;
    char category_name[20];
};


struct Meter
{
    int meter_id;
    int meter_no;
    int meter_status;
    char cust_name[20];
    int meter_owned;
};

struct Customer
{
    int customer_id;
    char customer_name[100];
    char customer_ID_card_no[16];
    char customer_category[20];
    int meter_no;
};

struct Price
{
    int price_id;
    int category_id;
    int minimumm;
    int maximum;
    int price_amount;
};

struct Selling
{
    int reciept_id;
    int customer_name;
    int meter_number;
    float total_units;
    int token_num[6];
    int vat;
    int total_amount;
};

struct CustomerMeter
{
    int id;
    int customer_id;
    int meter_id;
};