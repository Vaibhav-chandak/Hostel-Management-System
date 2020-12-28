/////////////////////////////////// Student ///////////////////////////////
struct student
{
	char name[20];
	int id;
	char address[50];
	char ph_no[13];
	char course[10];
	char room_alloted[10];
	char parent_no[13];
	char password[20];
};
struct student s;

//////////////////////////////////// Staff /////////////////////////////////
struct staff
{
	char name[20];
	int id;
	char address[50];
	char ph_no[13];
	char room_alloted[10];
	char password[20];
};
struct staff staf;

//////////////////////////////////// Logbook ///////////////////////////////
struct log
{
	char name[20];
	char address[50];
	char ph_no[13];
	char date[12];
	char entry_time[10];
	char exit_time[10];
};
struct log l;

//////////////////////////////// Request Update ////////////////////////////
struct update
{
int id;
char update[200];
};
struct update u;
