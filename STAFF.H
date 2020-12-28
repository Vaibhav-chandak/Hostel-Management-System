void Staff();
void ViewStaffPersonal();
void SearchStaffThird();
void PreviousStaff();

FILE *fp;
int id,i;
char password[20];

//////////////////////////// Staff Login ////////////////////////////////////
void StaffLogin()
{
	int c=219;
	clrscr();
	gotoxy(20,6);
	for(i=0;i<40;i++)
	printf("%c",c);
	gotoxy(20,7);
	printf("%c%c                                    %c%c",c,c,c,c);
	gotoxy(20,8);
	printf("%c%c Enter Id:                          %c%c",c,c,c,c);
	gotoxy(20,9);
	printf("%c%c Enter Password:                    %c%c",c,c,c,c);
	gotoxy(20,10);
	printf("%c%c                                    %c%c",c,c,c,c);
	gotoxy(20,11);
	for(i=0;i<40;i++)
	printf("%c",c);
	gotoxy(33,8);
	scanf("%d",&id);
	gotoxy(39,9);
	Password();
	fp=fopen("STAFF.DAT","rb");
	while(fread(&staf,sizeof(staf),1,fp)>0)
	{
		if(id==staf.id && (strcmp(password,staf.password)==0))
		{
			gotoxy(23,10);
			printf("Login Successful...");
			delay(600);
			Staff();
		}
		else
			flag=0;
	}
	fclose(fp);
	if(flag==0)
	{   gotoxy(23,10);
		printf("Login Falied!\n");
		delay(1000);
		exit(0);
	}
}

///////////////////////////////// Main Staff Function ////////////////////////
void Staff()
{
	char choose;
DISP:
	clrscr();
	Header();
	printf("                                 Staff Login");
	Line();
	printf("\n1-View your profile\n");
	printf("2-Request update in profile\n");
	printf("3-Search staff contact\n");
	printf("4-Exit\n");
	printf("Choose any one\n");
	scanf("%s",&choose);
	switch(choose)
	{
		case '1':ViewStaffPersonal();

		case '2':RequestUpdate();
				 PreviousStaff();

		case '3':SearchStaffThird();

		case '4':exit(0);

		default :printf("Invalid Option!\n");
			 delay(500);
			 goto DISP;
	}
}

///////////////////////////// Staff Personal Details ////////////////////////
void ViewStaffPersonal()
{
	clrscr();
	Header();
	printf("                                 View Profile");
	Line();
	fp=fopen("STAFF.DAT","rb");
	while(fread(&staf,sizeof(staf),1,fp)>0)
	{
		if(staf.id==id)
		{
			printf("\nStaff Details:-");
			printf("\nId:  %d",staf.id);
			printf("\nName:%s",staf.name);
			printf("\nAddress:%s",staf.address);
			printf("\nPhone number:%s",staf.ph_no);
			printf("\nAlloted Room:%s",staf.room_alloted);
			printf("\nPassword:%s",staf.password);
			printf("\n========\n");
		}
	}
	fclose(fp);
	PreviousStaff();
}

//////////////////////////// Search Staff Second ////////////////////////////
void SearchStaffThird()
{
	clrscr();
	Header();
	printf("                                 Search Staff");
	Line();
	printf("\nEnter Id to search Staff contact details:-");
	scanf("%d",&id);
	fp=fopen("STAFF.DAT","rb");
	while(fread(&staf,sizeof(staf),1,fp)>0)
	{
		if(id==staf.id)
		{
			printf("\nStaff Contact Details:-");
			printf("\nId=  %d",staf.id);
			printf("\nName=%s",staf.name);
			printf("\nPhone number=%s",staf.ph_no);
			printf("\nAlloted Room=%s\n",staf.room_alloted);
			PreviousStaff();
		}
	}
	fclose(fp);
	printf("Record not found!\n");
	PreviousStaff();
}

/////////////////////////////////// Main Menu ///////////////////////////////
void PreviousStaff()
{
	printf("\nEnter 1 to Exit or 9 to goto Main Menu\n");
	scanf("%s",&choose);
	switch(choose)
	{
		case '1':exit(0);

		case '9':Staff();

		default :PreviousStaff();
	}
}