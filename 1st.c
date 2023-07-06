#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

         // structures

struct addproduct
{
char name[100];
char code[100];
float price;
};

struct billing
{
char code[100];
char icode[100];
char name[100];
int amount;
float price;
float finalamount;
};

      // main

int main(){
    struct addproduct addproduct;
    struct billing billing;
    printf("\t\t\twelcome to Customer billing system\t\t\t\n");
    printf("1.generate bill.\n");
    printf("2.see bills.\n");
    printf("3.see product list.\n");
    printf("4.Add product.\n");
    printf("5.remove product.\n");

    //declaration of variable

    int input,tem,count=0,product=0;
    float finalamount;
    char end[]="exit";
    

FILE *fptr,*fptr2;

    scanf("%d",&input);
    scanf("%c",&tem);
    switch (input)
    {
             //generate bill

    case 1:
    system("cls");
        generatebill:
    printf("----------------BILL GENRATE----------------\n");
    printf("Enter code of product and quantity of product\n");
      while(1){
    printf("Enter product code:-");
    scanf("%s",&billing.icode);
      scanf("%c",&tem);
    if(strcmp(billing.icode,end)==0){
        break;
    }
    else
    {
    printf("Enter quantity of product:-");
    scanf("%d",&billing.amount);
        fptr=fopen("productlist.txt","r");
      
        while(fscanf(fptr,"%f",&billing.price)!=EOF)
        {
        fscanf(fptr,"%s %s %f",&billing.code,&billing.name,&billing.price);
        if(strcmp(billing.icode,billing.code)==0)
        {
            billing.finalamount=billing.amount*billing.price;
             fptr2=fopen("billing.txt","a");
             fprintf(fptr2,"%s\t%s\t%.3f\t%.3f\n",billing.code,billing.name,billing.price,billing.finalamount);
             fclose(fptr2);
            
            break;
        } 
        }
                 fclose(fptr);
    }

    }
        //printing bill

    printf("Enter \"1\" for genret bill or \"2\" for exit:-");
    //veriable diclaration
    float finalbill=0.0; 
    int billdisition;
    scanf("%d",&billdisition);
    scanf("%c",&tem);
    if(billdisition==1)
    {
        fptr=fopen("billing.txt","r");
        while(fscanf(fptr,"%f",&billing.finalamount)!=EOF){
        fscanf(fptr,"%s\t%s\t%f\t%f\n",&billing.code,&billing.name,&billing.price,&billing.finalamount);
        printf("%s\t%s\t%f\t--->\t%f\n",billing.code,billing.name,billing.price,billing.finalamount);

        finalbill=finalbill+billing.finalamount;
        }
        printf("\ntotal =%f\n",finalbill);
        fclose(fptr);
    }
     printf("press first digit of statement to perticullar site :\n");
                    printf("1.generate bill.\n");
                    printf("2.see bills.\n");
                    printf("3.see product list.\n");
                    printf("4.Add product.\n");
                    printf("5.remove product.\n");
                    printf("6.Finish program\n");
                    scanf("%d",&count);
                 if(count==1){
                         goto generatebill;
                 }
                 else if(count==2){
                         goto seebills;
                 }
                  else if(count==3){
                         goto seeproductlist;                    
                 }
                  else if(count==4){
                        goto Addproduct;                    
                 }                 
                  else if(count==5){
                         goto removeproduct;                    
                 }
                  else if(count==6){
                        goto finish;                    
                 }      
        break;

                               //see bills
    case 2:
        system("cls");
    seebills:
        break;
                            //see product list
    case 3:
            seeproductlist:
        system("cls");
        fptr=fopen("productlist.txt","r");
        while(fscanf(fptr,"%f",&addproduct.price)!=EOF){
        fscanf(fptr,"%s %s %f",&addproduct.code,&addproduct.name,&addproduct.price);
        printf("%s\t%s\t%.3f\n",addproduct.code,addproduct.name,addproduct.price);
        }
        fclose(fptr);
                    printf("press first digit of statement to perticullar site :\n");
                    printf("1.generate bill.\n");
                    printf("2.see bills.\n");
                    printf("3.see product list.\n");
                    printf("4.Add product.\n");
                    printf("5.remove product.\n");
                    printf("6.Finish program\n");
                    scanf("%d",&count);
                 if(count==1){
                         goto generatebill;
                 }
                 else if(count==2){
                         goto seebills;
                 }
                  else if(count==3){
                         goto seeproductlist;                    
                 }
                  else if(count==4){
                        goto Addproduct;
                 }                 
                  else if(count==5){
                         goto removeproduct;   
                 }
                  else if(count==6){
                        goto finish;  
                 }      
        break;
                                    //Add product.
    case 4:
    Addproduct:
    fptr=fopen("productlist.txt","a");
        system("cls");
        for (int i=0;;i++)
        {
            printf("Enter product code-"); 
            scanf("%[^\n]s",addproduct.code);
                  scanf("%c",&tem);
            printf("enter product name:-");
            scanf("%[^\n]s",addproduct.name);
              scanf("%c",&tem);
            printf("Enter price:-");
            scanf("%f",&addproduct.price);
            fprintf(fptr,"%s\t%s\t%.3f\n",addproduct.code,addproduct.name,addproduct.price);
            product++;
            printf("press \"1\" for continue entry  or  press \"2\" for exit:-");
            scanf("%d",&count);
            scanf("%c",&tem);
            if(count==2)
            {
                printf("Product added succesfully\n");
                printf("Exit from addproduct\n");
                fclose(fptr);
                printf("press first digit of statement to perticullar site :\n");
                 printf("1.generate bill.\n");
                 printf("2.see bills.\n");
                 printf("3.see product list.\n");
                 printf("4.Add product.\n");
                 printf("5.remove product.\n");
                printf("6.Finish program\n");
                 scanf("%d",&count);
                 if(count==1){
                         goto generatebill;
                 }
                 else if(count==2){
                         goto seebills;
                 }
                  else if(count==3){
                         goto seeproductlist;
                 }
                  else if(count==4){
                        goto Addproduct;
                 }                 
                  else if(count==5){
                         goto removeproduct;
                 }
                  else if(count==6){
                        goto finish;
                 }                
                break;
            }
        }
        break;

                                //remove product.
    case 5:
        system("cls");
        removeproduct:
        break;
        
                       //default

    default:
        system("cls");
    printf("input valid statement");
    break;
    }

    finish:
    printf("\nthank you for using");
    
    return 0;
}
