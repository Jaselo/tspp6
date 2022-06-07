#include <iostream>
#include <string>
#include <time.h>
#include <windows.h>

using namespace std;

struct date {
	int tm_year, tm_mon, tm_mday;
};

class Database {
public:
	int id;
	string car, type_ind, plan;
	float cost;
	date idata;
	//void db_include();
	//void db_search(int id);
	//void db_remove(int id);
	
	Database* next = 0;
	Database* prev = 0;
};

class Client {
public:
	void Input_data(string car, string type_ind, string plan);
	void More_contr(date idata);
	void Cancel_contr(int id);
	//void request();
};

class Case_man {
	friend class Database;
	friend class Client;
public:
	void Create_contr(string car, string type_ind, string plan);
	void Update_data(date idata);
	void Rem_contr(int id);
};

class Check_man {
	friend class Database;
	friend class Client;
public:
	//int penalty(Database& db, bool access);
	bool Verify(Database& db);
	bool check_lim(Database& db, date idata);
};

//Инициализация первой элемента
Database* AddFirst(const Database& input) {
	Database* top = new Database;
	*top = input;
	top->next = 0;
	top->prev = NULL;
	return top;
}

//Инициализация последующих элементов
Database* AddCont(Database* end, const Database& input) {
	Database* temp = new Database;
	*temp = input;
	temp->next = 0;
	temp->prev = end;
	end->next = temp;
	end = temp;
	return end;
}

//БД
/*
void db_include(Database* temp) {
	if (!temp) {
		AddFirst(temp);
	}
	string filename;
	cout << " Введите название текстового файла" << endl;
	cin >> filename;
	filename = filename + ".txt";

	ofstream fout(filename, ios::_Nocreate | ios::app);
	if (!fout) {
		cout << "\033[3;31m Файл не существует, создайте файл \033[0m" << filename << endl;
	}
	while (temp) {
		fout << temp->id << endl;
		fout << temp->car << endl;
		fout << temp->type_ind << endl;
		fout << temp->plan << endl;
		fout << temp->cost << endl;
		fout << temp->idata << endl;
		temp = temp->next;
	}
	cout << "\033[32m Данные сохранены в файл \033[0m" << endl;
	fout.close();
}

void db_search(int id) {

}

void db_remove(int id, list* top, list* end) {
	int key = 0;
	if (!top)
		cout << "\033[3;31m Информация отсутствует \033[0m" << endl;
	else
		do {
			system("cls");
			key = PartMenu(3);
			switch (key) {
			case 1: {  //удаление элемента по ID
				system("cls");
				if (!top) {
					cout << "\033[3;31m Список пуст \033[0m" << endl;
				}
				else {
					list* temp = top;
					int deln;
					showfordell(top);
					cout << " Введите ID элемента для его удаления: " << endl;
					cin >> deln;
					if ((top->id == deln) && (!top->next)) {
						temp = top;
						delete (temp);
						temp = top = NULL;
						cout << "\033[43m Номер " << deln << " был удален \033[0m" << endl; //элемент, не номер
					}
					else  //удаление первого элемента
						if (top->id == deln) {
							temp = top;
							top = top->next;
							delete (temp);
							temp = top;
							cout << "\033[43m Номер " << deln << " был удален \033[0m" << endl; //элемент, не номер
						}
						else  //удаление последнего элемента
							if (end->id == deln) {
								temp = end;
								end = temp->prev;
								delete temp;
								end->next = NULL;
								cout << "\033[43m Номер " << deln << " был удален \033[0m" << endl; //элемент, не номер
							}
							else {  //удаление элемента внутри списка
								list* lemp = new list;
								lemp = top;
								temp = top->next;
								while (temp) {  //поиск по списку
									if (temp->id == deln) break;
									temp = temp->next;
									lemp = lemp->next;
								}
								if ((temp != NULL) && (temp->id == deln)) {
									lemp->next = temp->next;
									temp->next->prev = lemp;
									delete (temp);
									cout << "\033[43m Номер " << deln << " был удален \033[0m" << endl; //элемент, не номер
								}
								else cout << "\033[3;31m Номер не найден \033[0m" << endl; //элемент, не номер и \033[43m
							}
				}
			}break;

			case 2: {  //удаление всего списка
				system("cls");
				if (!top) {
					cout << "\033[3;31m Список пуст \033[0m" << endl;
				}
				else {
					list* temp = NULL;
					while (top) {
						temp = top;
						top = top->next;
						delete (temp);
						temp = NULL;
					}
					end = NULL;
					cout << "\033[43m Список был удален \033[0m" << endl;
				}
			}break;

			case 3: {  //Отменить удаление
				key = esc;
			}break;
			} if (key != esc) system("pause");
		} while (key != esc);
}

void db_show(list* top) {
	system("cls");
	if (!top)
		cout << "\033[3;31m Информация отсутствует \033[0m" << endl;
	else {
		int page = 0;
		char key;
		short flag = 1;
		list* temp = top;
		do {
			int count = 0;
			system("cls");
			cout << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "| ID | Шифр задания | Код отдела | ФИО програмиста | Общее время прохождения задания | Время центрального процессора | Процент процессорного времени |" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
			for (int i = 0; i < 10; i++) {
				if (temp) {
					cout << "|" << setw(3) << temp->id << " |" << setw(13) << temp->cipher << " |" << setw(11) << temp->code << " |" << setw(16) << temp->FIO << " |"
						<< setw(32) << temp->timecpu << " |" << setw(30) << temp->timez << " |" << setw(30) << temp->percent << " |" << endl;
					cout << "------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
					temp = temp->next;
					count++;
				}
				else {
					if (flag == 1) {
						cout << "\x1b[38;5;063m Нажмите Esc для выхода \033[0m" << endl << endl;
						flag = 0;
					}
					key = _getch();
					if (key == esc) return;
					if (key == aleft) {
						flag = 1;
						break;
					}
				}
			}
			do {
				key = _getch();
				if (key == esc) return;
				if ((key == aright) && (count == 10)) page++;
				else if ((key == aright) && (count != 10)) {
					break;
				}
				if (key == aleft && page == 1) break;
				if (key == aleft && count != 1) {
					page--;
					break;
				}
			} while (key != aright);

			if (key == aleft) {
				temp = top;
				for (int i = 0; i < page * 10 - 10; i++) {
					if (temp) temp = temp->next;
					else break;
				}
			}
		} while (key != esc);
	}
}
*/

void Input_data(string car, string type_ind, string plan) {

}

void More_contr(date idata) {

}

void Cancel_contr(int id) {

}

void Create_contr(string car, string type_ind, string plan) {

}

void Update_data(date idata) {

}

void Rem_contr(int id) {

}

/*bool penalty(Database& db, bool access) {
	if (access == true) {
		float peny;
		peny = db.cost;
		return true;
	} else return false;
}*/

bool Verify(Database& db) {
	bool flag = false;
	do {
		system("cls");
		printMenu();
		key = getKey();
		system("cls");
		switch (key) {

		case 1: {
			crds.input();
		}break;

		case 2: {
			crds.output();
		}break;

		case 3: {
			crds.output();
		}break;

		case 4: {
			crds.output();
		}break;

		case 5: {
			crds.output();
		}break;
		} if (key != 6) system("pause");
	} while (key != 6);
	return flag;
}

void verifymenu() {
	cout << 'Выберете денные для проверки: ' << endl;
	cout << "1 - Проверить все данные" << endl;
	cout << "2 - Перепроверка данных клиента" << endl;
	cout << "3 - Перерасчет оценки стоимости имущества" << endl;
	cout << "4 - " << endl;
	cout << "5 - " << endl;
}

//Проверка сроков контракта
bool check_lim(Database& db, date idata) {
	bool flag = false;
	date timenow = localtime(&tm_mday, &tm_mon, &tm_year);
	if (timenow.tm_year <= idata.tm_year) {
		if (timenow.tm_mon <= idata.tm_mon)
			if (timenow.tm_mday < idata.tm_mday)
				flag = true;
			else cout << 'Контракт просрочен на ' << timenow.tm_mday - idata.tm_mday << ' дней' << endl;
	}
	if (flag == false) {
		cout << 'Контракт просрочен и будет удален из списка' << endl;
		
	}
	return flag;
}

void printMenu() {
	cout << "Выход клавиша ESC" << endl;
	cout << "1 - Ввод координат" << endl;
	cout << "2 - Проверить совпадение пар координат" << endl;
	cout << "3 - Увеличить первую пару на случайное число" << endl;
	cout << "4 - Умножить координаты" << endl;
	cout << "5 - Сравнить координаты" << endl;
}

int getKey() {
	int key = 10;
	do {
		key = _getch();
		if (key == 49) key = 1; else
			if (key == 50) key = 2; else
				if (key == 51) key = 3; else
					if (key == 52) key = 4; else
						if (key == 53) key = 5; else
							if (key == 27) key = 6; else key = 10;
	} while (key == 10);
	return key;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int key;
	Client Client;
	Case_man ContractM;
	Check_man CheckM;
	Database DB;
	Database* top = 0, * end = 0;
	do {
		system("cls");
		printMenu();
		key = getKey();
		system("cls");
		switch (key) {

		case 1: {
			crds.input();
		}break;

		case 2: {
			crds.output();
		}break;

		case 3: {
			crds.output();
		}break;

		case 4: {
			crds.output();
		}break;

		case 5: {
			crds.output();
		}break;
		} if (key != 6) system("pause");
	} while (key != 6);
	return 0;
}