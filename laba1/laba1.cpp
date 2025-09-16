#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

struct Truba {
	string name1;
	float dlina_km;
	int diameter_mm;
	bool remont;
};

struct Compressor {
	string name2;
	int kol_cehov;
	int vrabote;
	float klass_stanccii;
};

void menu() {
	while (true) {
		cout << "1. Добавить трубу" << endl;
		cout << "2. Добавить КС" << endl;
		cout << "3. Просмотр всех объектов" << endl;
		cout << "4. Редактировать трубу" << endl;
		cout << "5. Редактировать КС" << endl;
		cout << "6. Сохранить данные " << endl;
		cout << "7. Загрузить данные " << endl;
		cout << "8. Выход" << endl;
}

	int main() {
		setlocate(Truba, Compressor);
		menu();
		return 0;
	}

