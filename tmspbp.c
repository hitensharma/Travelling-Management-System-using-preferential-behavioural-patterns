#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

void filter(int s[]) //filtering system
{ FILE *flight = fopen("flightdb.csv","r");
  FILE *bus = fopen("busdb.csv","r");
  FILE *train = fopen("traindb.csv","r");
  
  
  
  char line[1000],source[20],dest[20],doj[10],dor[10],sd[30];
  int i=0;
  
  printf("Please enter date of journey (dd-mm-yyyy): ");
  scanf("%s", &doj);
  printf("Please enter Destination City: ");
  scanf("%s", &dest);
  printf("Please enter Source City: ");
  scanf("%s", &source);
  printf("Please enter return date (if none, then enter '00-00-00'): ");
  scanf("%s", &dor);
  sprintf(sd,"%s,%s",source,dest);
  if(s[8]==3)
  { 
   // create for loop to read Db line by line, search for source and destination cities
   if ( flight!= NULL )
               { FILE *test = fopen("test.csv","w"); 
			     int count=1;
			     while ( fgets ( line, 1000, flight ) != NULL ) 
                { 
				  if((strstr(line,sd)!=NULL) && (strstr(line,doj)!=NULL))
				    { 
				      
				      char *token = strtok(line, ",");
		              char *a[8];
		              for(i=0;i<8;i++)
		              { a[i]=token;
					    token=strtok(NULL,","); 
					  }
		              printf("\n\n%d.", count);
					  printf("\nSource: %s", a[0]);
                      printf("\nDestination: %s", a[1]);
					  printf("\nStops: %s", a[2]);
					  printf("\nDate of Journey: %s", a[3]);
					  printf("\nDeparture Time: %s", a[4]); 
					  printf("\nArrival Time: %s", a[5]);
					  printf("\nBrand: %s", a[6]);
					  printf("\nTicket Price: %s", a[7]);
                      count++;
					  fprintf(test,"%s,%s,%s,%s,%s,%s,%s,%s", a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7]);  
					}
                }
               fclose(test);
			   }
  FILE *test=fopen("test.csv","r");
  fseek(test,0,SEEK_SET);
  char b[10];
  int count=1;
  printf("\n Please Enter Your Preferred Company to travel with (eg. Indigo, SpiceJet, Air India etcetera):");
  char company[20];
  scanf("%s", company);
  while ( fgets ( line, 1000, test ) != NULL ) 
  { 
    int ydt=0, ybr=0;
    char *token = strtok(line, ",");
    char *a[8];
    for(i=0;i<8;i++)
    { a[i]=token;
	  if(i==6)
	  {
	  strcpy(b,token);
	  i++;
	  }
	  token=strtok(NULL,","); 
    }                                 
    int dt=atoi(a[4]);  //keep it as string
    int at=atoi(a[5]);
    int tp=atoi(a[7]);
   
    
    if((s[0]>s[1])&&(s[0]>s[2]))
         { if((dt>=601) && (dt<=1400))
			 { ydt=1;
			 }
		 }
    else if((s[1]>s[0])&&(s[1]>s[2]))
         { if((dt>=1401) && (dt<=2200))
			 { ydt=1;
			 }
   		 }
    else if((s[2]>s[0])&&(s[2]>s[1]))
         { if(((dt>=2201)&&(dt<=2359))||((dt>=0)&&(dt<=600)))
			 { ydt=1;
			 }
		 }
    
    
	
	if(strstr(b,company)!=NULL)
    	{ ybr=1;
		}
	
	if((ydt==1)&&(ybr==1))
	{ 
	  printf("\n\nThis seems to be the best option(s) according to the system\n");
	  printf("\n\n%d.", count);
					  printf("\nSource: %s", a[0]);
                      printf("\nDestination: %s", a[1]);
					  printf("\nStops: %s", a[2]);
					  printf("\nDate of Journey: %s", a[3]);
					  printf("\nDeparture Time: %s", a[4]); 
					  printf("\nArrival Time: %s", a[5]);
					  printf("\nBrand: %s", a[6]);
					  printf("\nTicket Price: %s", a[7]);
					  
	  count++; ybr=0;   
	}
	else if(((ydt==1)&&(ybr==0))||((ydt==0)&&(ybr==1)))
	{ 
	  printf("\n\nThis option does not satisfy your conditions. However, please have a look at it.");
	  
	  printf("\n\n%d.", count);
					  printf("\nSource: %s", a[0]);
                      printf("\nDestination: %s", a[1]);
					  printf("\nStops: %s", a[2]);
					  printf("\nDate of Journey: %s", a[3]);
					  printf("\nDeparture Time: %s", a[4]); 
					  printf("\nArrival Time: %s", a[5]);
					  printf("\nBrand: %s", a[6]);
					  printf("\nTicket Price: %s", a[7]);
	   count++;
	 } 
    
   
  }
 fclose(test);
 }         

else if(s[8]==1)
  { 
   // create for loop to read Db line by line, search for source and destination cities
   if ( bus!= NULL )
               { FILE *test2=fopen("test2.csv","w");
			     int count=1;
			     while ( fgets ( line, 1000, bus ) != NULL ) 
                { 
				  if((strstr(line,sd)!=NULL) && (strstr(line,doj)!=NULL))
				    { 
				      char *token = strtok(line, ",");
		              char *a[6];
		              for(i=0;i<6;i++)
		              { a[i]=token;
					    token=strtok(NULL,","); 
					  }
		              printf("\n\n%d.", count);
					  printf("\nSource: %s", a[0]);
                      printf("\nDestination: %s", a[1]);
					  printf("\nDate of Journey: %s", a[2]);
					  printf("\nDeparture Time: %s", a[3]); 
					  printf("\nTicket Price: %s", a[4]);
                      printf("\nBrand: %s", a[5]);
					  count++;
                      //fputs(line,test2);
					  fprintf(test2,"%s,%s,%s,%s,%s,%s", a[0],a[1],a[2],a[3],a[4],a[5]);  					
					}
                }
               fclose(test2);
			   }
  
  FILE *test2=fopen("test2.csv","r");
  fseek(test2,0,SEEK_SET);
  char b[10];
  int count=1, y3=0, y4=0;
  printf("\n Please Enter Your Preferred Bus Type to travel with (eg. VOLVO, AC JANRATH etcetera):");
  char btype[20];
  scanf("%s", btype);
  while ( fgets ( line, 1000, test2 ) != NULL ) 
  { int ydt=0, ybr=0;
    char *token = strtok(line, ",");
    char *a[6];
    for(i=0;i<6;i++)
    { a[i]=token;
	  if(i==5)
	  {
	  strcpy(b,token);
	  i++;
	  }
	  token=strtok(NULL,","); 
    }                                 
    int dt=atoi(a[3]);  //keep it as string
    
    int tp=atoi(a[4]);
   
    
    if((s[0]>s[1])&&(s[0]>s[2]))
         { if((dt>=601) && (dt<=1400))
			 { ydt=1;
			 }
		 }
    else if((s[1]>s[0])&&(s[1]>s[2]))
         { if((dt>=1401) && (dt<=2200))
			 { ydt=1;
			 }
   		 }
    else if((s[2]>s[0])&&(s[2]>s[1]))
         { if(((dt>=2201)&&(dt<=2359))||((dt>=0)&&(dt<=600)))
			 { ydt=1;
			 }
		 }
    
    
	
	if(strstr(b,btype)!=NULL)
    	{ ybr=1;
		}
	
	if((ydt==1)&&(ybr==1))
	{ 
	  printf("\n\nThis seems to be the best option(s) according to the system\n");
	  printf("\n\n%d.", count);
					  printf("\nSource: %s", a[0]);
                      printf("\nDestination: %s", a[1]);
					  printf("\nDate of Journey: %s", a[2]);
					  printf("\nDeparture Time: %s", a[3]); 
					
					  printf("\nBrand: %s", a[5]);
					  printf("\nTicket Price: %s", a[4]);
	  count++; ybr=0;   
	}
	else if(((ydt==1)&&(ybr==0))||((ydt==0)&&(ybr==1)))
	{ 
	  printf("\n\nThis option does not satisfy your conditions. However, please have a look at it.");
	  //printf("ydt: %d", ydt);
	  printf("\n\n%d.", count);
					  printf("\nSource: %s", a[0]);
                      printf("\nDestination: %s", a[1]);
					  
					  printf("\nDate of Journey: %s", a[2]);
					  printf("\nDeparture Time: %s", a[3]); 
					  
					  printf("\nBrand: %s", a[5]);
					  printf("\nTicket Price: %s", a[4]);
	   count++;
	 } 
    
   
  }
 fclose(test2);
  }
else if(s[8]==2)
	{ if ( train!= NULL )
               { 
			     int count=1;
			     FILE *test3=fopen("test3.csv","w");
				 while ( fgets ( line, 1000, train ) != NULL ) 
                { 
				  if((strstr(line,sd)!=NULL) && (strstr(line,doj)!=NULL))
				    { 
				      char *token = strtok(line, ",");
		              char *a[6];
		              for(i=0;i<6;i++)
		              { a[i]=token;
					    token=strtok(NULL,","); 
					  }
		              printf("\n\n%d.", count);
					  printf("\nSource: %s", a[0]);
                      printf("\nDestination: %s", a[1]);
					  printf("\nDate of Journey: %s", a[2]);
					  printf("\nDeparture Time: %s", a[3]); 
					  printf("\nTicket Price: %s", a[4]);
                      printf("\nType: %s", a[5]);
					  count++;
					  fprintf(test3,"%s,%s,%s,%s,%s,%s", a[0],a[1],a[2],a[3],a[4],a[5]);
					}
                }
               fclose(test3);
               
			   }
	FILE *test3=fopen("test3.csv","r");
  fseek(test3,0,SEEK_SET);
  char b[10];
  int count=1, y3=0, y4=0;
  printf("\n Please Enter Your Preferred Train Type to travel with (eg. 2AC, SLEEPER etcetera):");
  char ttype[20];
  scanf("%s", ttype);
  while ( fgets ( line, 1000, test3 ) != NULL ) 
  { //printf("\n\nreached function");
    int ydt=0, ybr=0;
    char *token = strtok(line, ",");
    char *a[6];
    for(i=0;i<6;i++)
    { a[i]=token;
	  if(i==5)
	  {
	  strcpy(b,token);
	  i++;
	  }
	  token=strtok(NULL,","); 
    }                                 
    int dt=atoi(a[3]);  //keep it as string
    
    int tp=atoi(a[4]);
   
    
    if((s[0]>s[1])&&(s[0]>s[2]))
         { if((dt>=601) && (dt<=1400))
			 { ydt=1;
			 }
		 }
    else if((s[1]>s[0])&&(s[1]>s[2]))
         { if((dt>=1401) && (dt<=2200))
			 { ydt=1;
			 }
   		 }
    else if((s[2]>s[0])&&(s[2]>s[1]))
         { if(((dt>=2201)&&(dt<=2359))||((dt>=0)&&(dt<=600)))
			 { ydt=1;
			 }
		 }
    
    
	
	if(strstr(b,ttype)!=NULL)
    	{ ybr=1;
		}
	
	if((ydt==1)&&(ybr==1))
	{ 
	  printf("\n\nThis seems to be the best option(s) according to the system\n");
	  printf("\n\n%d.", count);
					  printf("\nSource: %s", a[0]);
                      printf("\nDestination: %s", a[1]);
					  printf("\nDate of Journey: %s", a[2]);
					  printf("\nDeparture Time: %s", a[3]); 
					
					  printf("\nTrain Type: %s", a[5]);
					  printf("\nTrain Fare: %s", a[4]);
	  count++; ybr=0;   
	}
	else if(((ydt==1)&&(ybr==0))||((ydt==0)&&(ybr==1)))
	{ 
	  printf("\n\nThis option does not satisfy your conditions. However, please have a look at it.");
	  printf("ydt: %d", ydt);
	  printf("\n\n%d.", count);
					  printf("\nSource: %s", a[0]);
                      printf("\nDestination: %s", a[1]);
					  
					  printf("\nDate of Journey: %s", a[2]);
					  printf("\nDeparture Time: %s", a[3]); 
					  
					  printf("\nTrain Type: %s", a[5]);
					  printf("\nTrain Fare: %s", a[4]);
	   count++;
	 } 
    
   
  }
 fclose(test3);
}
fclose(bus);
fclose(flight);
fclose(train);
//fclose(test);
//fclose(test2);

}

struct Signup
{ char fname[20], lname[20], occupation[20], user[30], password[30];
  int age, priority[9];
  unsigned long long int cno;  /*issues with data not being properly written into .csv file
                                 Unsigned vaise daldiya*/
};

void sinput(struct Signup s)
{ int i;
  printf("Please enter your first name: ");
  scanf("%s", s.fname); 
  printf("Please enter your last name: ");
  scanf("%s", s.lname);
  printf("Please enter your occupation: ");
  scanf("%s", s.occupation);
  printf("Please enter your age: ");
  scanf("%d", &s.age);
  printf("Please enter your contact number: +91-");
  scanf("%lld", &s.cno);
  //printf("%lld",s.cno);
  printf("Please enter a username: ");
  scanf("%s", s.user);
  printf("Please enter a password: ");
  scanf("%s", s.password); 
  printf("According to your travel experience, state the priority (with '10' being the highest and '1' being the lowest) for the following conditions \n");
  printf("1. Travelling during the day (6am to 2pm): ");
  scanf("%d", &s.priority[0]);
  printf("2. Travelling during the evening (2pm to 10pm): ");
  scanf("%d", &s.priority[1]);
  printf("3. Travelling during the night (10pm to 2am): ");
  scanf("%d", &s.priority[2]);
  printf("4. Travelling Budget (the higher the priority, the greater the control you require over your budget): ");
  scanf("%d", &s.priority[3]);
  printf("5. Accommodation Budget: ");
  scanf("%d", &s.priority[4]);
  printf("6. Do you have a habit of travelling with a preferred brand or company ?: ");
  scanf("%d", &s.priority[5]);
  printf("7. How important is travel time to you ?: ");
  scanf("%d", &s.priority[6]);
  printf("8. Is the travel route important to you ?: ");
  scanf("%d", &s.priority[7]);
  printf("9. Do you have a preferred mode of transportation ? (Enter '1' Bus, '2' Train, '3' Flight): ");
  scanf("%d", &s.priority[8]);

  FILE *f = fopen("signup.csv", "a");   //preferred to manually create .csv file with headings first 
  fprintf(f,"\n%s,%s,%s,%s,%s,%d,%I64d,%d,%d,%d,%d,%d,%d,%d,%d,%d", s.user, s.password, s.fname, s.lname, s.occupation, s.age, s.cno, s.priority[0], s.priority[1], s.priority[2], s.priority[3], s.priority[4], s.priority[5], s.priority[6], s.priority[7], s.priority[8]);
  fclose(f); 
  //%I64d is used due to issues caused with Microsoft. It does not support standard %lld long long int
  
  /*(i=0; i<9; i++)
  { printf("%d", s.priority[i]);
    fprintf(f,"%d", s.priority[i]); }*/   //fprintf not storing loop data in .csv file
filter(s.priority);  
}

void login()
 { char line[1000];
   int i=0,j=0,k=0;
   FILE *p = fopen("signup.csv", "r");
   /*while ( fgets(line,1000,p)!=NULL ) 
    { printf("%s", line);} */
    fseek(p,0,SEEK_SET);
    char user[10]; char pass[10]; 
    printf("\nPlease enter your Username: ");
	scanf("%s", user);
	printf("Please enter your Password: ");
	scanf("%s", pass); 
	while ( fgets(line,1000,p)!=NULL ) 
    { 
	  if((strstr(line,user)!=NULL)&&(strstr(line,pass)!=NULL))
	  { k++;
	  	printf("\nWelcome\n\n");
	    int choi[9];
		char *token = strtok(line, ",");
		char *a[16];
		for(i=0;i<16;i++)
		{ a[i]=token;
		  if(i>6)
		  {//printf("%s\n",a[i]);
		   choi[i-7]=atoi(a[i]);
		  }
		  token=strtok(NULL,",");
    	}
		//for(i=0;i<9;i++)
		//{printf("%d", choi[i]);}
		filter(choi);
		break;
	  }
   }
    if(k==0)
    { printf("\nError: Please Try Again\n\n");
      login();
    }
	
	fclose(p);
}
 int main()
{ struct Signup s;
  printf("Do you wish to signup(1), login(2) or create a package(3) ? : ");
  int op;
  scanf("%d", &op);
  if(op==1)
  	{ sinput(s);
	}
  else if(op==2)
  	{ login(); 
	}
  else if(op==3)
  	{ package();
    } 
  return 0;
}

void package()
{ FILE *b=fopen("busdb.csv","r");
  FILE *f=fopen("flightdb.csv","r");
  FILE *t=fopen("traindb.csv","r");
  FILE *temp4=fopen("temp4.csv","w");
  
  char stop[10][20], line[1000], line2[1000], dest[20], doj[10][20], dor[20];
  printf("\nPlease enter your Source for your package: ");
  scanf("%s", stop[0]);
  
  printf("\nPlease enter your Destination: ");
  scanf("%s", dest);
  
  printf("\n Please enter the required number of stops (Should only be a maximum of 8 stops): ");
  int n, i;
  float x[10], budget; 
  scanf("%d", &n);
  
  printf("\n Please enter the stops in order\n");
  for(i=1; i<=n; i++)
  	{ printf("\n Enter Stop %d: ", i);
	  scanf("%s", stop[i]);   
    }
  strcpy(stop[n+1],dest);
  
  printf("\nEnter the respective departing dates/date of journey from each stop (dd-mm-yyyy)\n");
  
  for(i=0;i<n+1;i++)
  	{ printf("\nEnter the date you wish to depart from %s: ", stop[i]);
  	  scanf("%s", &doj[i]);
  	}
  
  printf("\nEnter a return date (dd-mm-yyyy): ");
  scanf("%s", dor);
  
  printf("\n Please enter Your Expected Budget: ");
  scanf("%f", &budget);
  
  FILE *temp1=fopen("temp1.csv","w");
  FILE *temp2=fopen("temp2.csv","w");
  FILE *temp3=fopen("temp3.csv","w");
  char sd[30];
  for(i=0; i<n+1; i++)
  	{ sprintf(sd,"%s,%s",stop[i],stop[i+1]);
	  int count=0, k; float totp=0;
	  fseek(f,0,SEEK_SET);
	  while(fgets(line,1000,f)!=NULL)
  	  	{   
			//FILE *temp1=fopen("temp1.csv","a");
			//printf("function 0 read");
			//for(i=0;i<=n+1;i++)
			 //printf("\n%s ",stop[i]);
			 //printf("\n%s", doj[i]);
		    //	}
			if((strstr(line,sd)!=NULL) && (strstr(line,doj[i])!=NULL))
			{ 	
			    char *token = strtok(line, ",");
		        char *a[8];
		        for(k=0;k<8;k++)
		      		{ 	a[k]=token;
				        token=strtok(NULL,","); 
					}
		        
				printf("\nSource: %s", a[0]);
                printf("\nDestination: %s", a[1]);
				printf("\nStops: %s", a[2]);
				printf("\nDate of Journey: %s", a[3]);
				printf("\nDeparture Time: %s", a[4]); 
				printf("\nArrival Time: %s", a[5]);
				printf("\nBrand: %s", a[6]);
				printf("\nTicket Price: %s", a[7]);
                count++;
				fprintf(temp1,"%s,%s,%s,%s,%s,%s,%s,%s", a[0],a[1],a[2],a[3],a[4],a[5],a[6],a[7]);        
			    count++; 
				int price=atoi(a[7]);
				totp+=price;    
			} 
		   // fclose(temp1);
		}

    while(fgets(line,1000,b)!=NULL)
  	  	{   //FILE *temp2=fopen("temp2.csv","a");
			
			if((strstr(line,sd)!=NULL) && (strstr(line,doj[i])!=NULL))
		  	{ 	
			    char *token = strtok(line, ",");
		        char *a[6];
		        for(k=0;k<6;k++)
		      		{ 	a[k]=token;
				        token=strtok(NULL,","); 
					}
		        
				printf("\nSource: %s", a[0]);
                printf("\nDestination: %s", a[1]);
				printf("\nDate of Journey: %s", a[2]);
				printf("\nDeparture Time: %s", a[3]); 
				printf("\nBrand: %s", a[5]);
				printf("\nTicket Price: %s", a[4]);
                count++;
				fprintf(temp2,"%s,%s,%s,%s,%s,%s", a[0],a[1],a[2],a[3],a[4],a[5]);     
	            int price=atoi(a[4]);
	            totp+=price;
			}
		    //fclose(temp2);
		}
      while(fgets(line,1000,t)!=NULL)
  	  	{   //FILE *temp3=fopen("temp3.csv","a");
			
			if((strstr(line,sd)!=NULL) && (strstr(line,doj[i])!=NULL))
		  	{ 	
			    char *token = strtok(line, ",");
		        char *a[6];
		        for(k=0;k<6;k++)
		      		{ 	a[k]=token;
				        token=strtok(NULL,","); 
					}
		        
				printf("\nSource: %s", a[0]);
                printf("\nDestination: %s", a[1]);
				printf("\nDate of Journey: %s", a[2]);
				printf("\nDeparture Time: %s", a[3]); 
				printf("\nTrain Type: %s", a[5]);
				printf("\nTrain Fare: %s", a[4]);
                count++;
				fprintf(temp3,"%s,%s,%s,%s,%s,%s", a[0],a[1],a[2],a[3],a[4],a[5]);     
	            int price=atoi(a[4]);
	            totp+=price;
			}
		    //fclose(temp3);
		}
        x[i]=(totp/count);
	      
    }
    
	fclose(temp1);
	fclose(temp2);
	fclose(temp3);
	int k=0,j=0;
	float totavg;
    for(i=0;i<n;i++)
    { totavg+=x[i];
	}
      char line3[1000];    
  for(i=0; i<n+1; i++)
  	{ int price=0, price2=0;
  	  
	  FILE *temp1=fopen("temp1.csv","r");
	  FILE *temp2=fopen("temp2.csv","r");
	  FILE *temp3=fopen("temp3.csv","r");
	  while(fgets(line,1000,temp1)!=NULL)  //for flights
  	  	{   
			strcpy(line3,line);
			//printf("function 0 read");
			//for(i=0;i<=n+1;i++)
			 //printf("\n%s ",stop[i]);
			 //printf("\n%s", doj[i]);
		    //	}
			if((strstr(line,stop[i])!=NULL) && (strstr(line,doj[i])!=NULL) && (strstr(line,stop[i+1])!=NULL))
			{ 	
			    char *token = strtok(line, ",");
		        char *a[8];
		        for(k=0;k<8;k++)
		      		{ 	a[k]=token;
				        token=strtok(NULL,","); 
					}
		        
			 
				price=atoi(a[7]);
				if((price>price2)&&(price<=((x[i]/totavg)*budget)))
				{ 
				  
				  price2=price;
				  strcpy(line2,line3);
				  
				}    
			} 
		    
		}

    while(fgets(line,1000,temp2)!=NULL)
  	  	{   
			strcpy(line3,line);
			if((strstr(line,stop[i])!=NULL) && (strstr(line,doj[i])!=NULL) && (strstr(line,stop[i+1])!=NULL))
		  	{ 	
			    char *token = strtok(line, ",");
		        char *a[6];
		        for(k=0;k<6;k++)
		      		{ 	a[k]=token;
				        token=strtok(NULL,","); 
					}
		        
			   
	            price=atoi(a[4]);
	            if((price>price2)&&(price<=((x[i]/totavg)*budget)))
				{ 
				  strcpy(line2,line3);
				  price2=price;
				  
				}  
			}
		    
		}
      while(fgets(line,1000,temp3)!=NULL)
  	  	{   
			strcpy(line3,line);
			if((strstr(line,stop[i])!=NULL) && (strstr(line,doj[i])!=NULL) && (strstr(line,stop[i+1])!=NULL))
		  	{ 	
			    char *token = strtok(line, ",");
		        char *a[6];
		        for(k=0;k<6;k++)
		      		{ 	a[k]=token;
				        token=strtok(NULL,","); 
					}
		        
			    
	            price=atoi(a[4]);
	            if((price>price2)&&(price<=((x[i]/totavg)*budget)))
				{ 
				  strcpy(line2,line3);
				  price2=price;
				  
				}  
			}
		    
		}
	fclose(temp1);
	fclose(temp2);
	fclose(temp3);	
    char *token = strtok(line2,",");
	char *g[6];
	
	for(j=0;j<6;j++)
	{ 	g[j]=token;
	    token=strtok(NULL,","); 
	}	      
    fprintf(temp4,"\n\n\n%s,%s,%s,%s,%s,%s", g[0],g[1],g[2],g[3],g[4],g[5]);
	
	}
  }



