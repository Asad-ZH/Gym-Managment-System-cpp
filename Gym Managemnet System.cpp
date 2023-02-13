

#include<iostream>
#include<conio.h>
#include<string>
#include<math.h>

using namespace std;

struct TrainerSchedule
{

	std::string Timing[7][7];

};

TrainerSchedule AddTSchedule();
//Defining new type for Personal Details
struct PersonalDetails
{
	std::string ID;
	std::string Password;
	bool IsAdmin;
};
//Defining new types for Time and std::string
typedef char Time[5];
struct MemberSchedule
{
	Time Timing[7];

};

MemberSchedule AddMSchedule(void)
{
	MemberSchedule MS;
	cout << "Monday:"; cin >> MS.Timing[0];
	cout << "Tuesday:"; cin >> MS.Timing[1];
	cout << "Wednesday:"; cin >> MS.Timing[2];
	cout << "Thursday:"; cin >> MS.Timing[3];
	cout << "Friday:"; cin >> MS.Timing[4];
	cout << "Saturday:"; cin >> MS.Timing[5];
	cout << "Sunday:"; cin >> MS.Timing[6];
	return MS;
}



int count_member = 0;
int count_trainer = 0;

//Class for storing ProfileData
class Profile
{
protected:
	PersonalDetails LoginDetails;
public:
	std::string Name;
	std::string Phone;
	std::string Address;

};

//function headers
void ShowTSchedule(TrainerSchedule Ts);
bool GetTrainerFromFile();
bool GetMemberFromFile();
void ShowMSchedule(MemberSchedule Ms);
void DeleteMember();
void DeleteTrainer();

class Trainer :public Profile
{
public:
	int Experience;
	int Salary;
	int Height;
	int weight;
	TrainerSchedule Schedule;


	//Default contructor manipulated for default input
	Trainer(){};
};

//Inherited class for Members
class Member :public Profile
{
public:
	double fee;
	MemberSchedule Schedule;
	std::string trainer;
};
Member *member_arr;
Trainer *trainer_arr;

Trainer t;
Member m;

void Add()              //Function to Add New Record in Data File
{

AddSelection:
	int choice;
	cout << "Choose from Below\n1.Add Trainer\n2.Add Member\n->";
	cin >> choice;
	if (choice == 1)
	{
		char ch = 'y';
		while (ch == 'y' || ch == 'Y'){
			cout << "\nEnter Trainer Name: ";
			cin >> trainer_arr[count_trainer].Name;
			cout << "Enter Trainer Height: ";
			cin >> trainer_arr[count_trainer].Height;
			cout << "Enter Trainer Address: ";
			cin >> trainer_arr[count_trainer].Address;
			cout << "Enter Trainer Experience: ";
			cin >> trainer_arr[count_trainer].Experience;
			cout << "Enter Trainer Phone: ";
			cin >> trainer_arr[count_trainer].Phone;
			cout << "Enter Trainer Salary: ";
			cin >> trainer_arr[count_trainer].Salary;
			cout << "Enter Trainer weight: ";
			cin >> trainer_arr[count_trainer].weight;
			cout << "\n\n::Trainer Schedule Insertion::";
			trainer_arr[count_trainer].Schedule = AddTSchedule();
			count_trainer++;
			cout << "Trainer Data Saved Successfully\n Want to Continue(Y/N).....";
			cin >> ch;
		}
	}
	else if (choice == 2)
	{
		char ch = 'y';
		while (ch == 'y' || ch == 'Y')
		{
			cout << "\nEnter Member name: ";
			cin >> member_arr[count_member].Name;
			cout << "\nEnter Member fee: ";
			cin >> member_arr[count_member].fee;
			cout << "\nEnter Member Address: ";
			cin >> member_arr[count_member].Address;
			cout << "\nEnter Member Phone: ";
			cin >> member_arr[count_member].Phone;
			cout << "\nEnter trainer name of member: ";
			cin >> member_arr[count_member].trainer;
			cout << "\n\n::Trainer Schedule Insertion::";
			trainer_arr[count_trainer].Schedule = AddTSchedule();
			count_member++;
			cout << "Member Data Saved successfully\nWant to Continue(Y/N).....";
			cin >> ch;
		}
	}
	else
	{
		cout << "Wrong choice:Try Again?(Y/N)";
		char c;
		cin >> c;
		if (c == 'Y' || c == 'y')goto AddSelection;

	}
}

void Schedule()
{
	int ch;
	cout << "Choose from Below\n1.Trainer Schedule\n2.Member Schedule\n->";
	cin >> ch;
	if (ch == 1)
	{
		if (GetTrainerFromFile())
			ShowTSchedule(t.Schedule);
	}
	else if (ch == 2)
	{
		if (GetMemberFromFile())
			ShowMSchedule(m.Schedule);
	}

	else
		cout << "Invalid Input.";

}
bool GetTrainerFromFile()
{
	string n;

	cout << "Enter Name of Trainer :";
	cin >> n;
	for (int i = 0; i < count_trainer; i++){
		if (trainer_arr[i].Name.compare(n) == 0)
			return true;
	}
	return false;
}
bool GetMemberFromFile()
{
	string n;
	bool found = false;
	cout << "Enter Name of Member:";
	cin >> n;
	for (int i = 0; i < count_trainer; i++){
		if (member_arr[i].Name.compare(n) == 0)
			return true;
	}
	return false;

}

void Delete()
{
	int ch;
	cout << "Choose from the options below.\n1.Delete Trainer\n2.Delete Member";
	cin >> ch;
	if (ch == 2)DeleteMember();
	else if (ch == 1)DeleteTrainer();
	else cout << "Wrong choice.";

}

void DeleteMember()		//Function to Delete Particular Record from Data File
{
	string n;
	int found = -1;
	cout << "Enter Name that should be Deleted :";
	cin >> n;
	for (int i = 0; i < count_member; i++){
		if (member_arr[i].Name.compare(n) == 0)
		{
			found = i;
			break;
		}
	}
	if (found >= 0)
	{
		int index = 0;
		for (int i = 0; i < count_member; i++){
			if (index != found){
				member_arr[index] = member_arr[i];
				index++;
			}
		}
		count_member = index;
		cout << "Member Successfully Deleted." << endl;
	}
	else
		cout << "\nMember not found with name " << n;
}//end of program
void DeleteTrainer()		//Function to Delete Particular Record from Data File
{
	string n;
	int found = -1;
	cout << "Enter Name that should be Deleted :";
	cin >> n;
	for (int i = 0; i < count_trainer; i++){
		if (trainer_arr[i].Name.compare(n) == 0)
		{
			found = i;
			break;
		}
	}
	if (found >= 0)
	{
		int index = 0;
		for (int i = 0; i < count_trainer; i++){
			if (index != found){
				trainer_arr[index] = trainer_arr[i];
				index++;
			}
		}
		count_trainer = index;
		cout << "Trainer Successfully Deleted." << endl;
	}
	else
		cout << "\nTrainer not found with name " << n;
}//end of program

void DisplayAllTrainer()		//Function to Display All Record from Data File
{
	if (count_trainer <= 0)
	{
		cout << "\nNo Trainer data to view!!";
		return;
	}
	for (int i = 0; i < count_trainer; i++){
		cout << "\n--------------------------------Trainers------------------------------------------";
		cout << "\n\tName\t\tPhone\t\tHeight\t\tWeight\t\tSalary";
		cout << "\n" << (i + 1) << "\t" << trainer_arr[i].Name << "\t\t"
			<< trainer_arr[i].Phone << "\t" << trainer_arr[i].Height
			<< "\t\t" << trainer_arr[i].weight << "\t\t" << trainer_arr[i].Salary;
	}

	cout << "\n---------------------------------------------------------------------------------";
}
void DisplayAllMember()		//Function to Display All Record from Data File
{
	if (count_member <= 0)
	{
		cout << "\nNo Member data to view!!";
		return;
	}
	for (int i = 0; i < count_member; i++){
		cout << "\n--------------------------------Members------------------------------------------";
		cout << "\n\tName\t\tPhone\t\tTrainer\t\tFee";
		cout << "\n" << (i + 1) << "\t" << member_arr[i].Name << "\t\t"
			<< member_arr[i].Phone << "\t" << member_arr[i].trainer << "\t\t" << member_arr[i].fee;
	}
	cout << "\n---------------------------------------------------------------------------------";
}



TrainerSchedule AddTSchedule(void)
{
	std::string DayNames[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	std::string Time[7] = { "1-2", "2-3", "3-4", "4-5", "5-6", "6-7" };
	TrainerSchedule TS;

	for (int i = 0; i<7; i++)
	{
		cout << "Schedule for " << DayNames[i] << endl;
		for (int j = 0; j<7; j++)
		{
			cout << Time[j];
			cin >> TS.Timing[i][j];
		}

	}

	return TS;
}
void ShowMSchedule(MemberSchedule Ms)
{
	cout << "\n----------------------Schedule-------------------";
	cout << "\nMon\tTue\tWed\tThu\tFri\tSat\tSun\n";
	for (int i = 0; i<7; i++)
		cout << member_arr[i].Schedule.Timing[i] << "\t";
	cout << "\n-------------------------------------------------";
}
void ShowTSchedule(TrainerSchedule Ts)
{
	std::string Times[7] = { "1-2", "2-3", "3-4", "4-5", "5-6", "6-7", "7-8" };
	cout << "\n\tMon\t\tTue\t\tWed\t\tThu\t\tFri\t\tSat\t\tSun\n";
	cout << "------------------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i<7; i++)
	{
		cout << Times[i] << "->\t";
		for (int j = 0; j<7; j++)
			cout << trainer_arr[i].Schedule.Timing[i][j]<< "\t\t";
		cout << "\n";
	}
	cout << "\n-----------------------------------------------------------------------------------------------------------------";

}

//Main Function
int main()
{

	member_arr = new Member[1000];
	trainer_arr = new Trainer[1000];

	int opt;

	while (true)
	{
		system("cls");
		cout << "\n\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t1.Add Schedule" << endl;
		cout << "\t\t\t2.Add New Record" << endl;
		cout << "\t\t\t3.Display Trainer Record " << endl;
		cout << "\t\t\t4.Display Member Record " << endl;
		cout << "\t\t\t5.Display Schedules " << endl;
		cout << "\t\t\t6.Delete  Record " << endl;
		cout << "\t\t\t7.Exit " << endl;
		cout << "\t\t\tEnter your Option : ";
		cin >> opt;
		switch (opt)
		{
		case 1:
		{
				  cout << "\n1.Trainer schedule\n2.Member Schedule";
				  cin >> opt;
				  if (opt == 1)
					  AddTSchedule();
				  else if (opt == 2)
					  AddMSchedule();

				  cout << "\nDisplay Main Menu" << endl;
				  _getch();
				  break;
		}
		case 2:
		{
				  Add();
				  cout << "\nDisplay Main Menu" << endl;
				  _getch();
				  break;
		}
		case 3:
		{
				  DisplayAllTrainer();
				  cout << "\nDisplay Main Menu" << endl;
				  _getch();
				  break;
		}
		case 4:
		{
				  DisplayAllMember();
				  cout << "\nDisplay Main Menu" << endl;
				  _getch();
				  break;
		}
		case 5:
		{
				  Schedule();
				  cout << "\nDisplay Main Menu" << endl;
				  _getch();
				  break;
		}
		case 6:
		{
				  Delete();
				  cout << "\nDisplay Main Menu" << endl;
				  _getch();
				  break;
		}
		case 7:
		{
				  exit(0);
		}

		default:
		{
				   cout << "Wrong Choice....Press Key For View the Main Menu";
				   _getch();
				   system("cls");
		}
		}
	}
}

//end of program

