#define ENTER 13
#define TAB 9
#define BKSP 8
#define SPACE 32

void AdminLogin();
void StaffLogin();

int i=0;
char c=219,password[20];

void login()
{
	char choose;
	textbackground(BLACK);
	clrscr();
	textcolor(WHITE);
	for(i=2;i<=78;i++)
	{
	gotoxy(25,12);
	cprintf("Welcome to Hostel Management System");
	gotoxy(i,20);
	cprintf("%c",c);
	}
	_setcursortype(_NOCURSOR);
	textcolor(GREEN);
	gotoxy(2,20);
	for(i=0;i<=76;i++)
	{
	cprintf("%c",c);
	delay(30);
	}
	_setcursortype(_NORMALCURSOR);
	textcolor(WHITE);
	clrscr();
DISP:
	gotoxy(20,6);
	for(i=0;i<40;i++)
	cprintf("%c",c);
	gotoxy(20,7);
	printf("%c%c                                    %c%c",c,c,c,c);
	gotoxy(20,8);
	printf("%c%c            Please Login            %c%c",c,c,c,c);
	gotoxy(20,9);
	printf("%c%c                                    %c%c",c,c,c,c);
	gotoxy(20,10);
	printf("%c%c 1-Admin Login                      %c%c",c,c,c,c);
	gotoxy(20,11);
	printf("%c%c 2-Staff Login                      %c%c",c,c,c,c);
	gotoxy(20,12);
	printf("%c%c 3-Student Login                    %c%c",c,c,c,c);
	gotoxy(20,13);
	printf("%c%c 4-Exit                             %c%c",c,c,c,c);
	gotoxy(20,14);
	printf("%c%c                                    %c%c",c,c,c,c);
	gotoxy(20,15);
	printf("%c%c Choose any one:                    %c%c",c,c,c,c);
	gotoxy(20,16);
	printf("%c%c                                    %c%c",c,c,c,c);
	gotoxy(20,17);
	for(i=0;i<40;i++)
	printf("%c",c);
	gotoxy(39,15);
	scanf("%s",&choose);
	switch(choose)
	{
	case '1':AdminLogin();

	case '2':StaffLogin();

	case '3':StudentLogin();

	case '4':exit(0);

	default :gotoxy(22,16);
		 printf(" Invalid Option! Please Login Again");
		 delay(500);
		 goto DISP;
	}
}

////////////////////////////// Admin Login /////////////////////////////////
void AdminLogin()
{
	char username[20];
	clrscr();
	gotoxy(20,6);
	for(i=0;i<40;i++)
	printf("%c",c);
	gotoxy(20,7);
	printf("%c%c                                    %c%c",c,c,c,c);
	gotoxy(20,8);
	printf("%c%c Enter Username:                    %c%c",c,c,c,c);
	gotoxy(20,9);
	printf("%c%c Enter Password:                    %c%c",c,c,c,c);
	gotoxy(20,10);
	printf("%c%c                                    %c%c",c,c,c,c);
	gotoxy(20,11);
	for(i=0;i<40;i++)
	printf("%c",c);
	gotoxy(39,8);
	scanf("%s",&username);
	gotoxy(39,9);
	Password();
	if(strcmp(username,"Admin")==0 && strcmp(password,"Admin")==0)
	{
		gotoxy(23,10);
		printf("Login Successful...");
		delay(800);
		Admin();
	}
	else
	{
		gotoxy(23,10);
		printf("Login Falied!");
		delay(600);
		exit(0);
	}
}

/////////////////////////////////// Password ////////////////////////////////
void Password()
{
	int i=0;
	char temp2;
	while(1)
	{
		temp2=getch();
		if(temp2==ENTER)
		{
			password[i]='\0';
			break;
		}
		else if(temp2==BKSP)
		{
			if(i>0)
			{
				i--;
				printf("\b \b");
			}
		}
		else if(temp2==TAB||temp2==SPACE)
		{
			continue;
		}
		else
		{
			password[i]=temp2;
			i++;
			printf("*");
		}
		}
}