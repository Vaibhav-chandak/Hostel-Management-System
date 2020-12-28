#include "STRUCTURE.h"

void ManageStudent();
void AddStudent();
void ViewStudent();
void DeleteStudent();
void ModifyStudent();
void SearchStudent();

void ManageStaff();
void AddStaff();
void ViewStaff();
void DeleteStaff();
void ModifyStaff();
void SearchStaff();

void LogBook();
void AddLog();
void ViewLog();
void SearchLog();

void ManageUpdate();
void ViewUpdate();
void DeleteUpdate();

void Previous();
void RecordExist();
void Header();
void Line();

FILE *fp,*fp1;
int flag,temp_id;
char choose;

void Admin()
{
DISP:
	clrscr();
	Header();
	printf("                                 Admin Login");
	Line();
	printf("\n1-Manage Students\n");
	printf("2-Manage Staff\n");
	printf("3-Manage Logbook\n");
	printf("4-Manage Update Requests\n");
	printf("5-Exit\n");
	printf("Choose any one\n");
	fflush(stdin);
	scanf("%s",&choose);
	switch(choose)
	{
	case '1':ManageStudent();

	case '2':ManageStaff();

	case '3':LogBook();

	case '4':ManageUpdate();

	case '5':exit(0);

	default :printf("Invalid Option!\n");
			 delay(	500);
			 goto DISP;
	}
}

/////////////////////////////////// Student ////////////////////////////////
void ManageStudent()
{
DISP:
	clrscr();
	Header();
	printf("                                 Manage Student");
	Line();
	printf("\n1-Add Student Details\n");
	printf("2-View Student Details\n");
	printf("3-Delete Student Details\n");
	printf("4-Modify Student Details\n");
	printf("5-Search Student Details\n");
	printf("6-Exit\n");
	printf("Choose any one\n");
	scanf("%s",&choose);
	switch(choose)
	{
	case '1': AddStudent();

	case '2': ViewStudent();

	case '3': DeleteStudent();

	case '4': ModifyStudent();

	case '5': SearchStudent();

	case '6': exit(0);

	default :
		printf("Invalid Option!\n");
		delay(500);
		goto DISP;
	}
}
//////////////////////////// Add Student ////////////////////////////////////
void AddStudent()
{
	clrscr();
	Header();
	printf("                                 Add Student");
	Line();
	fp=fopen("STD.DAT","rb");
	printf("Enter Student id:");
	scanf("%d",&temp_id);
	while(fread(&s,sizeof(s),1,fp)>0)
	{
		if(temp_id==s.id)
		{
			printf("\nRecord Already Exist!\n");
			Previous();
		}
	}
	fclose(fp);
	fp=fopen("STD.DAT","ab");
	s.id=temp_id;
	printf("Enter Name:");
	fflush(stdin);
	gets(s.name);
	printf("Enter Address:");
	fflush(stdin);
	gets(s.address);
	printf("Enter Phone number:");
	fflush(stdin);
	gets(s.ph_no);
	printf("Enter Course:");
	fflush(stdin);
	gets(s.course);
	printf("Enter Room Alloted:");
	fflush(stdin);
	gets(s.room_alloted);
	printf("Enter Parent's Number:");
	fflush(stdin);
	gets(s.parent_no);
	printf("Enter Password:");
	fflush(stdin);
	gets(s.password);
	fwrite(&s,sizeof(s),1,fp);
	fclose(fp);
	printf("\nStudent Added....");
	Previous();
}
//////////////////////////// View Student ///////////////////////////////////
void ViewStudent()
{
	clrscr();
	Header();
	printf("                                 View Student");
	Line();
	fp=fopen("STD.DAT","rb");
	while(fread(&s,sizeof(s),1,fp)>0)
	{
		printf("\nId:   %d",s.id);
		printf("\nName: %s",s.name);
		printf("\nAddress: %s",s.address);
		printf("\nPhone number: %s",s.ph_no);
		printf("\nCourse: %s",s.course);
		printf("\nRoom Alloted: %s",s.room_alloted);
		printf("\nParent Number: %s",s.parent_no);
		printf("\nPassword: %s",s.password);
		printf("\n======\n");
		getch();
	}
	fclose(fp);
	Previous();
}
/////////////////////////// Delete Student //////////////////////////////////
void DeleteStudent()
{
	int counter1=0,counter2=0;
	clrscr();
	Header();
	printf("                                 Delete Student");
	Line();
	printf("\nEnter Student Id to delete data: ");
	scanf("%d",&temp_id);
	fp=fopen("STD.DAT","rb");
	fp1=fopen("TEMP.DAT","wb");
	while(fread(&s,sizeof(s),1,fp)>0)
	{
		counter1++;
		if(s.id!=temp_id)
		{
			fwrite(&s,sizeof(s),1,fp1);
		}
	}
	fclose(fp1);
	fclose(fp);
	remove("STD.DAT");
	rename("TEMP.DAT","STD.DAT");
	fp=fopen("STD.DAT","rb");
	while(fread(&s,sizeof(s),1,fp)>0)
		counter2++;
	fclose(fp);
	if(counter1>counter2)
	printf("Record Deleted...\n");
	else
	printf("Record not found!\n");
	Previous();
}
//////////////////////////// Modify Student /////////////////////////////////
void ModifyStudent()
{
	clrscr();
	Header();
	printf("                                 Modify Student");
	Line();
	printf("\nEnter Id to modify data:-");
	scanf("%d",&temp_id);
	fp=fopen("STD.DAT","rb+");
	while(fread(&s,sizeof(s),1,fp)>0)
	{
		if(temp_id==s.id)
		{
			s.id=temp_id;
			printf("Enter new Name:");
			fflush(stdin);
			gets(s.name);
			printf("Enter new Address:");
			fflush(stdin);
			gets(s.address);
			printf("Enter new Phone number:");
			fflush(stdin);
			gets(s.ph_no);
			printf("Enter new Course:");
			fflush(stdin);
			gets(s.course);
			printf("Enter new Room Alloted:");
			fflush(stdin);
			gets(s.room_alloted);
			printf("Enter new Parent's Number:");
			fflush(stdin);
			gets(s.parent_no);
			printf("Enter new Password:");
			fflush(stdin);
			gets(s.password);
			fseek(fp,-(long)sizeof(s),1);
			fwrite(&s,sizeof(s),1,fp);
			printf("\nRecord Modified\n");
			fclose(fp);
			Previous();
		}
	}
	fclose(fp);
	printf("Record not found!\n");
	Previous();
}
//////////////////////////// Search Student /////////////////////////////////
void SearchStudent()
{
	clrscr();
	Header();
	printf("                                 Search Student");
	Line();
	printf("\nEnter Id to search Student details:");
	scanf("%d",&temp_id);
	fp=fopen("STD.DAT","rb");
	while(fread(&s,sizeof(s),1,fp)>0)
	{
		if(temp_id==s.id)
		{
		printf("\nStudent Details:-");
		printf("\nId:   %d",s.id);
		printf("\nName: %s",s.name);
		printf("\nAddress: %s",s.address);
		printf("\nPhone number: %s",s.ph_no);
		printf("\nCourse: %s",s.course);
		printf("\nRoom Alloted: %s",s.room_alloted);
		printf("\nParent Number: %s",s.parent_no);
		printf("\nPassword: %s",s.password);
		printf("\n=======\n");
		Previous();
		}
	}
	fclose(fp);
	printf("Record Not Found!\n");
	Previous();
}


////////////////////////////////// Staff ///////////////////////////////////
void ManageStaff()
{
DISP:
	clrscr();
	Header();
	printf("                                 Manage Staff");
	Line();
	printf("\n1-Add Staff Details\n");
	printf("2-View Staff Details\n");
	printf("3-Delete Staff Details\n");
	printf("4-Modify Staff Details\n");
	printf("5-Search Staff Details\n");
	printf("6-Exit\n");
	printf("Choose any one!\n");
	scanf("%s",&choose);
	switch(choose)
	{
	case '1': AddStaff();

	case '2': ViewStaff();

	case '3': DeleteStaff();

	case '4': ModifyStaff();

	case '5': SearchStaff();

	case '6': exit(0);

	default :
		printf("Invalid Option!\n");
		delay(500);
		goto DISP;
	}
}
/////////////////////////////// Add Staff ///////////////////////////////////
void AddStaff()
{
	clrscr();
	Header();
	printf("                                 Add Staff");
	Line();
	printf("\nEnter Staff Id:");
	scanf("%d",&temp_id);
	fp=fopen("STAFF.DAT","rb");
	while(fread(&staf,sizeof(staf),1,fp)>0)
	{
		if(temp_id==staf.id)
		{
			printf("\nRecord Already Exist!\n");
			Previous();
		}
	}
	fclose(fp);
	staf.id=temp_id;
	printf("Enter Staff Name:");
	fflush(stdin);
	scanf("%s",&staf.name);
	printf("Enter Address:");
	fflush(stdin);
	gets(staf.address);
	printf("Enter Phone Number:");
	fflush(stdin);
	gets(staf.ph_no);
	printf("Enter Room Alloted:");
	fflush(stdin);
	gets(staf.room_alloted);
	fp=fopen("STAFF.DAT","ab");
	printf("Enter Password:");
	fflush(stdin);
	gets(staf.password);
	fwrite(&staf,sizeof(staf),1,fp);
	fclose(fp);
	printf("\nStaff added...\n");
	Previous();
}
/////////////////////////////// View Staff //////////////////////////////////
void ViewStaff()
{
	clrscr();
	Header();
	printf("                                 View Staff");
	Line();
	fp=fopen("STAFF.DAT","rb");
	while(fread(&staf,sizeof(staf),1,fp)>0)
	{
		printf("\nStaff Details:-");
		printf("\nId:  %d",staf.id);
		printf("\nName:%s",staf.name);
		printf("\nAddress:%s",staf.address);
		printf("\nPhone number:%s",staf.ph_no);
		printf("\nAlloted Room:%s",staf.room_alloted);
		printf("\nPassword:%s",staf.password);
		printf("\n=======\n");
		getch();
	}
	fclose(fp);
	Previous();
}

////////////////////////////// Delete Staff /////////////////////////////////
void DeleteStaff()
{
	int counter1=0,counter2=0;
	clrscr();
	Header();
	printf("                                 Delete Staff");
	Line();
	printf("\nEnter Staff Id to delete data:");
	scanf("%d",&temp_id);
	fp=fopen("STAFF.DAT","rb");
	fp1=fopen("TEMP.DAT","wb");
	while(fread(&staf,sizeof(staf),1,fp)>0)
	{
		counter1++;
		if(temp_id!=staf.id)
		fwrite(&staf,sizeof(staf),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	remove("STAFF.DAT");
	rename("TEMP.DAT","STAFF.DAT");
	fp=fopen("STAFF.DAT","rb");
	while(fread(&staf,sizeof(staf),1,fp)>0)
	counter2++;
	fclose(fp);
	if(counter1>counter2)
	printf("Record Deleted...\n");
	else
	printf("Record not found!\n");
	Previous();
}

/////////////////////////////// Modify Staff ////////////////////////////////
void ModifyStaff()
{
	clrscr();
	Header();
	printf("                                 Modify Staff");
	Line();
	printf("\nEnter Staff Id to modify data:-");
	scanf("%d",&temp_id);
	fp=fopen("STAFF.DAT","rb+");
	while(fread(&staf,sizeof(staf),1,fp)>0)
	{
		if(temp_id==staf.id)
		{
			staf.id=temp_id;
			printf("Enter new Name:");
			fflush(stdin);
			gets(staf.name);
			printf("Enter new Address:");
			fflush(stdin);
			gets(staf.address);
			printf("Enter new Phone number:");
			fflush(stdin);
			gets(staf.ph_no);
			printf("Enter new Room Alloted:");
			fflush(stdin);
			gets(staf.room_alloted);
			printf("Enter new Password:");
			fflush(stdin);
			gets(staf.password);
			fseek(fp,-(long)sizeof(staf),1);
			fwrite(&staf,sizeof(staf),1,fp);
			printf("\nRecord Modified\n");
			fclose(fp);
			Previous();
		}
	}
	fclose(fp);
	printf("Record not found!\n");
	Previous();
}

/////////////////////////////// Search Staff ////////////////////////////////
void SearchStaff()
{
	clrscr();
	Header();
	printf("                                 Search Staff");
	Line();
	printf("\nEnter Id to search Staff details:-");
	scanf("%d",&temp_id);
	fp=fopen("STAFF.DAT","rb");
	while(fread(&staf,sizeof(staf),1,fp)>0)
	{
		if(temp_id==staf.id)
		{
			printf("\nStaff Details:-");
			printf("\nId=  %d",staf.id);
			printf("\nName=%s",staf.name);
			printf("\nAddress=%s",staf.address);
			printf("\nPhone number=%s",staf.ph_no);
			printf("\nAlloted Room=%s",staf.room_alloted);
			printf("\nPassword=%s",staf.password);
			printf("\n======\n");
			Previous();
		}
	}
	fclose(fp);
	printf("Record not found!\n");
	Previous();
}


/////////////////////////////// Log Book ////////////////////////////////////
void LogBook()
{
DISP:
	clrscr();
	Header();
	printf("                                 Manage Logbook");
	Line();
	printf("\n1-Add Log Data\n");
	printf("2-View Log Data\n");
	printf("3-Search Log Data\n");
	printf("4-Exit\n");
	printf("Choose any one!\n");
	scanf("%s",&choose);
	switch(choose)
	{
	case '1': AddLog();

	case '2': ViewLog();

	case '3': SearchLog();

	case '4': exit(0);

	default :
		printf("Invalid Option!\n");
		delay(500);
		goto DISP;
	}
}

//////////////////////////////// Add Log ////////////////////////////////////
void AddLog()
{
	clrscr();
	Header();
	printf("                                 Add Log");
	Line();
	fp=fopen("LOG.DAT","ab");
	printf("\nEnter Visitor's Name:");
	scanf("%s",&l.name);
	printf("Enter Address:");
	fflush(stdin);
	gets(l.address);
	printf("Enter Phone Number:");
	fflush(stdin);
	gets(l.ph_no);
	printf("Enter Date:");
	fflush(stdin);
	gets(l.date);
	printf("Enter Entry Time:");
	fflush(stdin);
	gets(l.entry_time);
	printf("Enter Exit Time:");
	fflush(stdin);
	gets(l.exit_time);
	printf("\nLog Succesfully Added...\n");
	fwrite(&l,sizeof(l),1,fp);
	fclose(fp);
	Previous();
}

//////////////////////////////// View Log ///////////////////////////////////
void ViewLog()
{
	clrscr();
	Header();
	printf("                                 View Log");
	Line();
	fp=fopen("LOG.DAT","rb");
	while(fread(&l,sizeof(l),1,fp)>0)
	{
		printf("\nVisitor's Details:-");
		printf("\nName:  %s",l.name);
		printf("\nAddress:  %s",l.address);
		printf("\nPhone number:  %s",l.ph_no);
		printf("\nDate:  %s",l.date);
		printf("\nEntry Time:  %s",l.entry_time);
		printf("\nExit Time:  %s",l.exit_time);
		printf("\n======\n");
		getch();
	}
	fclose(fp);
	Previous();
}

//////////////////////////////// Search Log /////////////////////////////////
void SearchLog()
{
	char temp_date[12];
	clrscr();
	Header();
	printf("                                 Search Log");
	Line();
	printf("\nEnter date to search record:");
	fflush(stdin);
	gets(temp_date);
	fp=fopen("LOG.DAT","rb");
	while(fread(&l,sizeof(l),1,fp)>0)
	{
		if(strcmp(temp_date,l.date)==0)
		{
			printf("\nVisitor's Details:-");
			printf("\nName:  %s",l.name);
			printf("\nAddress:  %s",l.address);
			printf("\nPhone number:  %s",l.ph_no);
			printf("\nDate:  %s",l.date);
			printf("\nEntry Time:  %s",l.entry_time);
			printf("\nExit Time:  %s\n",l.exit_time);
			getch();
			flag=1;
		}
	}
	fclose(fp);
	if(flag==1)
	{
		flag=0;
		Previous();
	}
	printf("Record not found!\n");
	Previous();
}

///////////////////////////// Manage Updates ////////////////////////////////
void ManageUpdate()
{
DISP:
	clrscr();
	Header();
	printf("                                 Manage Update");
	Line();
	printf("\n1-View Update Requests\n");
	printf("2-Delete Update Requests\n");
	printf("3-Exit\n");
	printf("Enter your choice\n");
	scanf("%s",&choose);
	switch(choose)
	{
		case '1':ViewUpdate();

		case '2':DeleteUpdate();

		case '3':exit(0);

		default :
			printf("Invalid Option!\n");
			delay(500);
			goto DISP;
	}
}

/////////////////////////////// View Update /////////////////////////////////
void ViewUpdate()
{
	int counter=1;
	clrscr();
	Header();
	printf("                                 Check Update Request");
	Line();
	printf("\nUpdates Requested:-\n");
	fp=fopen("UPDATE.DAT","rb");
	while(fread(&u,sizeof(u),1,fp)>0)
	{
		printf("\n%d)",counter);
		counter++;
		printf(" Id = %d requested:-\n",u.id);
		puts(u.update);
		getch();
	}
	fclose(fp);
	Previous();
}

////////////////////////////// Delete Update ////////////////////////////////
void DeleteUpdate()
{
	int counter1=0,counter2=0;
	clrscr();
	Header();
	printf("                                 Delete Update Request");
	Line();
	printf("\nEnter Id to delete update request:");
	scanf("%d",&temp_id);
	fp=fopen("UPDATE.DAT","rb");
	fp1=fopen("TEMP.DAT","wb");
	while(fread(&u,sizeof(u),1,fp)>0)
	{
		counter1++;
		if(temp_id!=u.id)
		fwrite(&u,sizeof(u),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	remove("UPDATE.DAT");
	rename("TEMP.DAT","UPDATE.DAT");
	fp=fopen("UPDATE.DAT","rb");
	while(fread(&u,sizeof(u),1,fp)>0)
	counter2++;
	fclose(fp);
	if(counter1>counter2)
	printf("Update request Deleted...\n");
	else
	printf("Update request not found!\n");
	Previous();
}

//////////////////////////////// Previous ///////////////////////////////////
void Previous()
{
	printf("\nEnter 1 to Exit or 9 to goto Main Menu\n");
	scanf("%s",&choose);
	switch(choose)
	{
		case '1':exit(0);

		case '9':Admin();

		default :Previous();
	}
}

//////////////////////////////// Header ////////////////////////////////////
void Header()
{
	printf("\n*******************************************************************************\n");
	printf("                            Hostel Management System");
	printf("\n===============================================================================\n");
}

/////////////////////////////// Line /////////////////////////////////////////
void Line()
{
	printf("\n*******************************************************************************\n");
}