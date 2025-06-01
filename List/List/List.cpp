#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#define DEBUG
//#define DEBUGo

using namespace std;

class ToDoList {
private:
	

	
	vector<string> list;
	
	vector<int> int_statusTask; // 0 incomplete, 1 complete, 2 in progress
	vector<string> status;


	bool minusID(int id) {
		id++;
		if (id > list.size()) {
			cout << "\nYou dont have task with number " << id << endl;
			system("pause");
			return false;
		}
		else return true;
	}
	int num;




public:

	ToDoList() {

		ifstream size("size.txt");
		size >> num;

		string num1;

		ifstream idData("idData.txt");
		while (idData >> num1)
			status.push_back(num1);

#ifdef DEBUGo
		//example
		ifstream ifs(file_name);
		int n;
		while (ifs >> n)
			v.push_back(n);
#endif // DEBUG



		ifstream data("data.txt");
		
		while(getline(data, num1)) // read line
			list.push_back(num1);

		data.close();	
		idData.close();
		size.close();


#ifdef DEBUGo
			void wczytajZPliku() {
			ifstream plik("data.txt"); // Otwiera plik do odczytu
			if (!plik) {
				cout << "Nie można otworzyć pliku do odczytu! Ustawienia domyślne.\n";
				return;
			}
			// Wczytuje dane z pliku

			plik >> b10 >> b20 >> b50 >> b100 >> b200;
			plik >> gr1 >> gr2 >> gr5 >> gr10 >> gr20 >> gr50;
			plik >> m5 >> m10 >> m25;

			plik.close();
		}
#endif // DEBUG
	}
	
	// copy constructor for future
	ToDoList(const string&other) {

	}



	void showTask() {
		if (list.size() == 0) {
			cout << "You dont have notes yet -_- " << endl << endl;
		}

		for (int i = 0; i < list.size(); i++) {
			cout << (i+1) << ") " << list[i] << "\t[" << status[i] << "]" << endl << endl;
		}
	}

	void writeTask(string newNote) {

		list.push_back(newNote);

		status.push_back("Incomplete");
	
	
		saveData();
		
	}

	void deleteTask(int id) {

		if (!minusID(id)) return;

		list.erase(list.begin() + id);
		status.erase(status.begin() + id);

		cout << "\nDeleted note by number " << id + 1 << endl;
		system("pause");

	}

	
	void changeTask(int id, string newNote) {
		
		if (!minusID(id)) return;

		list[id] = newNote;
	}
	
	void SetStatusTask(int currentStatus, int id) {


		if (!minusID(id)) return;

		switch (currentStatus)
		{

		case 0:
			status[id] = "Incomplete";
			break;
		case 1:
			status[id] = "Complete";
			break;
		case 2:
			status[id] = "Inprogress";
			break;
		default:
			break;
		}

		saveData();
	

	}

	void saveData() {
		num = list.size();

		ofstream idData("idData.txt");
		ofstream data("data.txt");
		ofstream size("size.txt");

		// save status
		
		int i = 0;
		while (i != num) {
			idData << status[i] << endl;
			i++;
		}

		i = 0;

		//save notes

		while (i != num) {
			data << list[i] << endl;
			i++;
		}

		//save sizeof

		size << num;

		data.close();
		idData.close();
		size.close();

	}

	~ToDoList() {
		void saveData();
	}
	

};

void showMenu() {
	cout << "[1] - Write something new; [2] - Delete note; \n[3] - Change smth about note; [4] -  Set status;[5] - Exit\n";
}

int main(int argc, char* argv[]) {

	int inputStatus = 0; string newNote;
	int deleteID; 	int choice;

	ToDoList diary;
	do {
		cout << "\tSimple TODO list" << endl << endl;

		

		diary.showTask();
		showMenu();

		cout << "\nInput: ";  cin >> choice;
		switch (choice)
		{
		case 1:

			cin.ignore();
			cout << "Write something - "; getline(cin, newNote);
			cout << endl;
			diary.writeTask(newNote);
#ifdef DEBUG
			system("cls");
#endif // DEBUG

			
			break;
		case 2:

			cin.ignore();
			cout << "Whick task do you want to delete(by number): "; cin >> deleteID;
			diary.deleteTask(deleteID - 1);
#ifdef DEBUG
			system("cls");
#endif // DEBUG
			break;
		case 3:
		
		
			cout << "\nWhich task do you want to change(select by number): "; cin >> deleteID; // второй раз юзаю для экономии памяти
			cin.ignore();
			cout << "What will you write?: "; getline(cin, newNote);
			diary.changeTask(deleteID-1, newNote);
#ifdef DEBUG
			system("cls");
#endif // DEBUG
			break;
		case 4:

			cout << "For which of your tasks you want to change status(selecet by number): "; cin >> deleteID;
			cout << "\n0 - Incomplete; 1 - Complete; 2 - In progress\nWhat status will you set: "; cin >> inputStatus;
			diary.SetStatusTask(inputStatus, deleteID-1);
#ifdef DEBUG
			system("cls");
#endif // DEBUG
			break;
		default:
			break;
		}
	} while (choice != 5);

	diary.saveData();
	return 0;
}