#include <iostream>
#include <fstream>
#include <string>
#include <limits>

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

bool Proverka_bl() {
    int znachenie;
    while (true) {
        cin >> znachenie;
        if (cin.fail() || (znachenie != 0 && znachenie != 1)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка. Введите 0 или 1: ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return znachenie == 1;
        }
    }
}

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

    cout << "Введите статус трубы (0 - работает, 1 - в ремонте): ";
    pipe.remont = Proverka_bl();

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
        cout << "Труба не добавлена" << endl;
        return;
    }

    cout << "Труба " << endl;
    cout << "Название: " << pipe.name << endl;
    cout << "Длина: " << pipe.dlina_km << " км" << endl;
    cout << "Диаметр: " << pipe.diameter_mm << " мм" << endl;
    cout << "Статус: " << (pipe.remont ? "В ремонте" : "Работает") << endl;
    cout << endl;
}

void Pokaz_comp(const Compressor& cm) {
    if (cm.name.empty()) {
        cout << "Компрессорная станция не добавлена" << endl;
        return;
    }

    cout << "Компрессорная станция " << endl;
    cout << "Название: " << cm.name << endl;
    cout << "Всего цехов: " << cm.kol_cehov << endl;
    cout << "Работающих цехов: " << cm.vrabote << endl;
    cout << "Класс станции: " << cm.klass_stancii << endl;
    cout << endl;
}

void Vse_objects(const Truba& pipe, const Compressor& cm) {
    Pokaz_trubi(pipe);
    Pokaz_comp(cm);
}

void Izmenit_status(Truba& pipe) {
    if (pipe.name.empty()) {
        cout << "Труба не добавлена!" << endl;
        return;
    }

    cout << "Текущий статус: " << (pipe.remont ? "В ремонте" : "Работает") << endl;
    cout << "Введите новый статус (0 - работает, 1 - в ремонте): ";
    pipe.remont = Proverka_bl();
    cout << "Статус трубы изменен на: " << (pipe.remont ? "В ремонте" : "Работает") << endl;
}

void Zapustit_cehi(Compressor& cm) {
    if (cm.name.empty()) {
        cout << "Компрессорная станция не добавлена!" << endl;
        return;
    }

    int dostupno = cm.kol_cehov - cm.vrabote;
    if (dostupno == 0) {
        cout << "Все цехи уже работают!" << endl;
        return;
    }

    cout << "Доступно для запуска: " << dostupno << " цехов" << endl;
    cout << "Сколько цехов запустить? ";

    int zapuskaem = Proverka_in(1, dostupno);
    cm.vrabote += zapuskaem;

    cout << "Запущено " << zapuskaem << " цехов. Теперь работает: " << cm.vrabote << " цехов" << endl;
}

void Ostanovit_cehi(Compressor& cm) {
    if (cm.name.empty()) {
        cout << "Компрессорная станция не добавлена!" << endl;
        return;
    }

    if (cm.vrabote == 0) {
        cout << "Нет работающих цехов!" << endl;
        return;
    }

    cout << "Работает цехов: " << cm.vrabote << endl;
    cout << "Сколько цехов остановить? ";

    int ostanavlivaem = Proverka_in(1, cm.vrabote);
    cm.vrabote -= ostanavlivaem;

    cout << "Остановлено " << ostanavlivaem << " цехов. Теперь работает: " << cm.vrabote << " цехов" << endl;
}

void Sohranit_v_file(const Truba& pipe, const Compressor& cm) {
    ofstream file("labor1.txt");

    if (!file.is_open()) {
        cout << "Ошибка открытия файла для записи!" << endl;
        return;
    }

    file << "ТРУБА" << endl;
    file << pipe.name << endl;
    file << pipe.dlina_km << endl;
    file << pipe.diameter_mm << endl;
    file << pipe.remont << endl;

    file << "КС" << endl;
    file << cm.name << endl;
    file << cm.kol_cehov << endl;
    file << cm.vrabote << endl;
    file << cm.klass_stancii << endl;

    file.close();
    cout << "Данные успешно сохранены в файл!" << endl;
}

void Zagruzit_iz_file(Truba& pipe, Compressor& cm) {
    ifstream file("labor1.txt");

    if (!file.is_open()) {
        cout << "Файл данных не найден!" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line == "TRUBA") {
            getline(file, pipe.name);
            file >> pipe.dlina_km >> pipe.diameter_mm >> pipe.remont;
            file.ignore();
        }
        else if (line == "COMPRESSOR") {
            getline(file, cm.name);
            file >> cm.kol_cehov >> cm.vrabote >> cm.klass_stancii;
            file.ignore();
        }
    }

    file.close();
    cout << "Данные успешно загружены из файла!" << endl;
}

void menu() {
    Truba pipe = { "", 0.0f, 0, false };
    Compressor cm = { "", 0, 0, 0.0f };

    while (true) {
        cout << "Меню" << endl;
        cout << "1. Добавить трубу" << endl;
        cout << "2. Добавить КС" << endl;
        cout << "3. Просмотр всех объектов" << endl;
        cout << "4. Редактировать трубу" << endl;
        cout << "5. Редактировать КС" << endl;
        cout << "6. Сохранить данные" << endl;
        cout << "7. Загрузить данные" << endl;
        cout << "8. Выход" << endl;
        cout << "Выберите действие: ";

        int vibor = Proverka_in(1, 8);
        cout << endl;

        switch (vibor) {
        case 1:
            pipe = Vvodtrubi();
            cout << "Труба успешно добавлена!" << endl;
            break;

        case 2:
            cm = Vvodcomp();
            cout << "Компрессорная станция успешно добавлена!" << endl;
            break;

        case 3:
            Vse_objects(pipe, cm);
            break;

        case 4:
            Izmenit_status(pipe);
            break;

        case 5:
        {
            if (cm.name.empty()) {
                cout << "Сначала добавьте компрессорную станцию!" << endl;
                break;
            }

            cout << "1. Запустить цехи" << endl;
            cout << "2. Остановить цехи" << endl;
            cout << "Выберите действие: ";

            int podvibor = Proverka_in(1, 2);
            if (podvibor == 1) {
                Zapustit_cehi(cm);
            }
            else {
                Ostanovit_cehi(cm);
            }
            break;
        }

        case 6:
            Sohranit_v_file(pipe, cm);
            break;

        case 7:
            Zagruzit_iz_file(pipe, cm);
            break;

        case 8:
            cout << "Выход из программы!" << endl;
            return;
        }
    }
}

int main() {
    setlocale(LC_ALL, "RU");
    menu();
    return 0;
}