#include <iostream>
using namespace std;

#include "FaceBook.h"
#include "Friend.h"
#include "FanPage.h"

#define SIZE_OF_NAME 20

Friend* readFriend();
FanPage* readFanPage();
Status* readStatus();
const Date& readDate();
const Time& readTime();
const Board& readBoard();

int chooseEntity();

bool checkOption(int option);
bool checkOption2(int option);

/***************************************/

void main()
{
	FaceBook faceBook;
	int option;
	bool flag=true;

	while (flag)
	{
		cout << endl << "List of Options: " << endl
			<< "1. Add Entity to faceBook" << endl
			<< "2. Add status to specific Entity" << endl
			<< "3. Show specific Entity all status" << endl
			<< "4. Connect Entities" << endl
			<< "5. Show all faceBook Entities" << endl
			<< "6. Show specific Entities all Entities" << endl
			<< "7. Remove Fan From FanPage" << endl
			<< "8. Exit program" << endl
			<< "Choose option: ";
		do{
			cin >> option;
		} while (!checkOption(option));
	
		switch (option)
		{
			case 1:
			{
					  do{
						  cout << endl << "Choose: 1-Add Friend, 2-Add FanPage: ";
						  cin >> option;
					  } while (!checkOption2(option));

					  switch (option)
					  {
						  case 1:
						  {
								faceBook.addEntity(*readFriend());
								break;
						  }

						  case 2:
						  {
								faceBook.addEntity(*readFanPage());
								break;
						  }
					  }

				break;
			}
			case 2:
			{
				cout << "Choose Entity to add status ";
				int index = chooseEntity();
				try
				{
					cout << "Add status to: " << faceBook.getEntity(index)->get_Name() << endl;
					faceBook.getEntity(index)->addStatus(*readStatus());
				}
				catch (const char* msg)
				{
					cout << msg << endl;
				}
				break;
			}
			case 3:
			{
				cout << "Choose Entity to show all status ";
				int index = chooseEntity();
				try
				{
					cout << "All status of " << faceBook.getEntity(index)->get_Name() << endl;
					faceBook.getEntity(index)->print_allStatus();
				}

				catch (const char* msg)
				{
					cout << msg << endl;
				}
				break;
			}
			case 4:
			{
				cout << "Choose Entities to Connect ";
				cout <<endl <<"Choose first Entity ";
				int index1 = chooseEntity();
				cout << endl << "Choose second Entity ";
				int index2 = chooseEntity();

				try
				{
					faceBook.getEntity(index1)->ConnectEntities(*faceBook.getEntity(index2));
					cout << endl << faceBook.getEntity(index1)->get_Name() << " and " << faceBook.getEntity(index2)->get_Name() << " are now Connected" << endl;
				}

				catch (const char* msg)
				{
					cout << msg << endl;
				}
				break;
			}
			case 5:
			{
				cout << "List of faceBook Entities:" << endl << endl;
				faceBook.print_allEntities();
				break;
			}
			case 6:
			{
				cout << "Choose Entity to show all Entities ";
				int index = chooseEntity();

				try
				{
					cout << "All Entity connected to " << faceBook.getEntity(index)->get_Name() << endl;
					faceBook.getEntity(index)->print_allEntities();
				}

				catch (const char* msg)
				{
					cout << msg << endl;
				}
				break;
			}

			case 7:
			{
				 cout << endl << "Choose FanPage ";
				 int index1 = chooseEntity();
				 cout << endl << "Choose Friend to Remove from FanPage ";
				 int index2 = chooseEntity();
				 try
				 {
					 if (typeid(*faceBook.getEntity(index1)) == typeid(FanPage))
					 {
						 ((FanPage*)faceBook.getEntity(index1))->removeFriend(*faceBook.getEntity(index2));
						 cout << endl << faceBook.getEntity(index2)->get_Name() << " has been Removed from " << faceBook.getEntity(index1)->get_Name() << endl;
					 }
					 else
					 {
						 cout << "Choose FanPage" << endl;
					 }
					 
				 }
				 catch (const char* msg)
				 {
					 cout << msg << endl;
				 }

				 break;
			}

			case 8:
			{
				flag = false;
				cout << "Bye" << endl;
				break;
			}

		}

	}
	//system("pause");
}

/***************************************/
	
Status* readStatus()
{
	Date date = readDate();
	Time time = readTime();
	char content[SIZE_OF_NAME];
	cout << "Enter Content: ";
	cin >> content;
	int x;

	bool flag = false;
	while (!flag)
	{
		try
		{
			cout << "Enter type of status (0-Text, 1-Picture, 2-Video): ";
			cin >> x;

			return new Status(content, date, time, Status::eType(x));
			flag = true;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
	}
}

const Date& readDate()
{
	cout << "Date:" << endl;
	int year, month, day;

	bool flag = false;
	while (!flag)
	{
		try
		{
			cout << "Enter day: ";
			cin >> day;
			cout << "Enter month: ";
			cin >> month;
			cout << "Enter year: ";
			cin >> year;

			return Date(day, month, year);
			flag = true;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
	}
}

const Time& readTime()
{
	cout << "Time:" << endl;
	int hour, minutes;

	bool flag = false;
	while (!flag)
	{
		try
		{
			cout << "Enter hour: ";
			cin >> hour;
			cout << "Enter minutes: ";
			cin >> minutes;

			return Time(hour, minutes);
			flag = true;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
	}
}

const Board& readBoard()
{
	bool editByFriends;

	bool flag = false;
	while (!flag)
	{
		try
		{
			cout << "Can Board be editable by freinds? (0-false, 1-true): ";
			cin >> editByFriends;

			return Board(editByFriends);
			flag = true;
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
	}	
}

Friend* readFriend()
{
	char Name[SIZE_OF_NAME];
	cout << "Enter Name: ";
	cin >> Name;
	Date birthDate = readDate();
	Board board;
	board = readBoard();
	return new Friend(Name, birthDate, board);
}

FanPage* readFanPage()
{
	char Name[SIZE_OF_NAME];
	cout << "Enter Name: ";
	cin >> Name;
	Board board;
	board = readBoard();
	return new FanPage(Name, board);
}

int chooseEntity()
{
	int index;
	cout << "- Choose #: ";
	cin >> index;
	return index - 1;
}

bool checkOption(int option)
{
	if (option > 8 || option < 1)
	{
		cout << "choose valid option" << endl;
		return false;
	}
	return true;
}

bool checkOption2(int option)
{
	if (option != 1 && option != 2)
	{
		cout << "choose valid option" << endl;
		return false;
	}
	return true;
}