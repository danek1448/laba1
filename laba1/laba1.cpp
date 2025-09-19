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


void menu() {
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
	}
};



int main() {
    setlocale(LC_ALL, "RU");
    menu();
    return 0;
}