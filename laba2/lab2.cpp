#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <clocale>
using namespace std;

struct DatabaseInfo
{
	int id;
	string name;
	string mail;
};

class DatabaseClient
{
private:
	string server_address;
	bool connect;
	vector<DatabaseInfo> db;
	int id = 0;

public:
	DatabaseClient(string address) : server_address(address), connect(false) {
		cout << "Подключение к дб прошло успешно\n\n";
		connect = 1;
	};
	~DatabaseClient() {
		cout << "Отключение от дб прошло успешно\n";
		connect = 0;
	};

	void addData(string name, string mail) {
		if (connect) {
			id++;
			db.push_back({ id, name, mail });
			cout << "Добавлен пользователь с ID: " << id << "\n";
		}
		else cout << "Error: нет подключения к базе данных (addData)" << endl;

	};
	bool searchData(int id, DatabaseInfo info) {
		if (connect) {
			for (int i = 0; i < size(db); i++)
				if (id == db[i].id) {
					cout << "Найден пользователь с ID: " << id << "\n\n";
					return true;
				}
			cout << "Пользователь с ID " << id << " не найден." << '\n';
			return false;
		}
		else cout << "Error: нет подключения к базе данных (searchData)" << endl;
	};
	void deleteData(int id) {
		if (connect) {
			for (int i = 0; i < size(db); i++)
				if (id == db[i].id) {
					db.erase(db.begin() + i);
					cout << "Удален пользователь с ID: " << id << endl;
				}
		}
		else cout << "Error: нет подключения к базе данных (deleteData)" << endl;
	};

	string printName(int id) {
		if (connect) {
			for (int i = 0; i < size(db); i++)
				if (id == db[i].id) {
					return db[i].name;
				}
		}
	};
	string printMail(int id) {
		if (connect) {
			for (int i = 0; i < size(db); i++)
				if (id == db[i].id) {
					return db[i].mail;
				}
		}
	};
};

int main() {
	setlocale(LC_ALL, "RU");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
	DatabaseClient db("11.22.33.44");

	db.addData("Криштиану Роналду", "cr7@mail.ru");
	db.addData("Лионель Месси", "lm10@mail.ru");
	DatabaseInfo db_info;
	int id_to_search = 1;
	if (db.searchData(id_to_search, db_info))
		cout << "Результат поиска:\n" << "Имя: " << db.printName(id_to_search) << "\n" << "Почта: " << db.printMail(id_to_search) << "\n\n";
	db.deleteData(1);
	if (db.searchData(id_to_search, db_info))
		cout << "Результат поиска:\n" << "Имя: " << db.printName(id_to_search) << "\n" << "Почта: " << db.printMail(id_to_search) << "\n\n";
}
