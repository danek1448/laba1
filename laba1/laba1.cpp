#include <iostream>   // Для ввода-вывода (cin, cout)
#include <fstream>    // Для работы с файлами (ifstream, ofstream)
#include <string>     // Для работы со строками (string)
#include <limits>     // Для numeric_limits (пределы числовых типов)

using namespace std;

struct Truba {
	string name;
	float dlina_km;
	int diameter_mm;
	bool remont;
};

struct Compressor {
	string name;
	int kol_cehov;
	int vrabote;
	float klass_stancii;
};

float Proverka_fl(float min_znach = 0.0f, float max_znach = numeric_limits<float>::max()) {
	float znachenie;
	while (true) {
		cin >> znachenie;
		if (cin.fail() || znachenie < min_znach || znachenie > max_znach) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Ошибка. Введите число от " << min_znach << " до " << max_znach << ": ";
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return znachenie;
		}
	}
}

int Proverka_in(int min_znach = 0, int max_znach = numeric_limits<int>::max()) {
	int znachenie;
	while (true) {
		cin >> znachenie;
		if (cin.fail() || znachenie < min_znach || znachenie > max_znach) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Ошибка. Введите число от " << min_znach << " до " << max_znach << ": ";
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			return znachenie;
		}
	}
}

Truba Vvodtrubi() {
	Truba pipe;
	cout << "Введите название трубы: ";
	getline(cin, pipe.name);

	cout << "Введите длину трубы(км): ";
	pipe.dlina_km = Proverka_fl(0.1f);

	cout << "Введите диаметр трубы(мм): ";
	pipe.diameter_mm = Proverka_in(1);

	pipe.remont = false;

	return pipe;
}

Compressor Vvodcomp() {
	Compressor cm;
	cout << "Введите название КС: ";
	getline(cin, cm.name);

	cout << "Введите общее количество цехов: ";
	cm.kol_cehov = Proverka_in(1);

	cout << "Введите количество работающих цехов: ";
	cm.vrabote = Proverka_in(0, cm.kol_cehov);

	cout << "Введите класс станции (0.0-5.0): ";
	cm.klass_stancii = Proverka_fl(0.0f, 5.0f);

	return cm;
}

void Pokaz_trubi(const Truba& pipe) {
	if (pipe.name.empty()) {
		cout << "Добавьте трубу!" << endl;
		return;
	}
	cout << "Труба" << endl;
	cout << "Название: " << pipe.name << endl;
	cout << "Длина: " << pipe.dlina_km << " км" << endl;
	cout << "Диаметр: " << pipe.diameter_mm << " мм" << endl;
	cout << "Статус: " << pipe.remont << "1 - работает, 0 - в ремонте" << endl;
	cout << endl;
}

void Pokaz_comp(const Compressor& cm) {
	if (cm.name.empty()) {
		cout << "Добавьте компрессорную станциию!" << endl;
		return;
	}
	cout << "Компрессорная станция" << endl;
	cout << "Название: " << cm.name << endl;
	cout << "Количество цехов: " << cm.kol_cehov << endl;
	cout << "Количество цехов в работе: " << cm.vrabote << endl;
	cout << "Класс компрессорной станции: " << cm.klass_stancii << endl;
	cout << endl;
}

void Vse_objects(const Truba& pipe, Compressor& cm) {
	Pokaz_trubi(pipe);
	Pokaz_comp(cm);
}


void menu() {
	Truba pipe;
	Compressor cm;
	while (true) {
		cout << "\n Меню \n";
		cout << "1. Добавить трубу" << endl;
		cout << "2. Добавить КС" << endl;
		cout << "3. Просмотр всех объектов" << endl;
		cout << "4. Редактировать трубу" << endl;
		cout << "5. Редактировать КС" << endl;
		cout << "6. Сохранить данные " << endl;
		cout << "7. Загрузить данные " << endl;
		cout << "8. Выход" << endl;

		int cifra = Proverka_in(1, 8);
		cout << endl;

		switch (cifra) {
		case 1:
			pipe = Vvodtrubi();
			break;

		case 2:
			cm = Vvodcomp();
			break;

		case 3:
			Vse_objects(pipe, cm);

		case 8:
			cout << "Выход из программы!" << endl;
			return;
		}
	}
};



int main() {
    setlocale(LC_ALL, "RU");
    menu();
    return 0;
}