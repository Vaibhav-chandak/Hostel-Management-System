void Student();
void ViewStudentPersonal();
void RequestUpdate();
void SearchStaffSecond();
void PreviousStudent();
void Password();

FILE *fp;
int id,i;
char password[20];

void StudentLogin()
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
	fp=fopen("STD.DAT","rb");
	while(fread(&s,sizeof(s),1,fp)>0)
	{
		if(id==s.id && (strcmp(password,s.password)==0))
		{
			gotoxy(23,10);
			printf("Login Successful...");
			delay(800);
			Student();
		}
		else
			flag=0;
	}
	fclose(fp);
	if(flag==0)
	{
		gotoxy(23,10);
		printf("Login Failed!\n");
		delay(1000);
		exit(0);
	}
}

///////////////////////////////// Main Student ////////////////////////////
void Student()
{
	char choose;
DISP:
	clrscr();
	Header();
	printf("                                 Student Login");
	Line();
	printf("\n1-View your profile\n");
	printf("2-Request update in profile\n");
	printf("3-Search staff contact\n");
	printf("4-Exit\n");
	printf("Choose any one\n");
	scanf("%s",&choose);
	switch(choose)
	{
		case '1':ViewStudentPersonal();

		case '2':RequestUpdate();
				 PreviousStudent();

		case '3':SearchStaffSecond();

		case '4':exit(0);

		default :printf("Invalid Option!\n");
				 delay(500);
				 goto DISP;
	}
}

//////////////////////////// View Persoanl Details Student //////////////////
void ViewStudentPersonal()
{
	clrscr();
	Header();
	printf("                                 View Profile");
	Line();
	fp=fopen("STD.DAT","rb");
	while(fread(&s,sizeof(s),1,fp)>0)
	{
		if(id==s.id)
		{
		printf("\nYour Details:-");
		printf("\nId:   %d",s.id);
		printf("\nName: %s",s.name);
		printf("\nAddress: %s",s.address);
		printf("\nPhone number: %s",s.ph_no);
		printf("\nCourse: %s",s.course);
		printf("\nRoom Alloted: %s",s.room_alloted);
		printf("\nParent Number: %s",s.parent_no);
		printf("\nPassword: %s",s.password);
		printf("\n========\n");
		PreviousStudent();
		}
	}
	fclose(fp);
}

//////////////////////////// Request Update Student /////////////////////////
void RequestUpdate()
{
	clrscr();
	Header();
	printf("                                 Request Update");
	Line();
	fp=fopen("UPDATE.DAT","rb");
	while(fread(&u,sizeof(u),1,fp)>0)
	if(u.id==id)
	{
		printf("\nYour previous update request is pending, you can only do one request at a time!\n");
		PreviousStudent();
	}
	printf("\nEnter your update request within 150 words:-\n");
	u.id=id;
	fflush(stdin);
	gets(u.update);
	fp=fopen("UPDATE.DAT","ab");
	fwrite(&u,sizeof(u),1,fp);
	fclose(fp);
}

//////////////////////////// Search Staff Second ////////////////////////////
void SearchStaffSecond()
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
			PreviousStudent();
		}
	}
	fclose(fp);
	printf("Record not found!\n");
	PreviousStudent();
}

/////////////////////////////////// Main Menu ///////////////////////////////
void PreviousStudent()
{
	printf("\nEnter 1 to Exit or 9 to goto Main Menu\n");
	scanf("%s",&choose);
	switch(choose)
	{
		case '1':exit(0);

		case '9':Student();

		default :PreviousStudent();
	}
}
