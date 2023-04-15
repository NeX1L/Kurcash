#define NOMINMAX
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <Windows.h>
using namespace std;
void menu1();
void menu2();
void menu3();
void menupozovatel();
void menuadmin();
void secretslovo(string& secrslo);
void provekapassword(string& password);
void menuosnova();
void menuregistration();
void menuregistrationfilepol();
void menuregistrationfileadmin();
void menuavyorizaciya();
void menuavyorizaciyafilepol();
void menuavyorizaciyafileadmin();
void menuvvostanovlenie();
void vvostanovleniepass(int chislo);
void menuadmina1();
void blockpolzovatel();
void razblockpolzovatel();
void tablicapol();
void tablicazblock();
void tablicarazblock();
void NUMBER_bus();
void kol_stops();
void addBus();
void viewBus();
using namespace std;
const int MAX_BUSES = 10;
const int MAX_STOPS = 30;
struct BUS {
	int numberBUS;
	string stops[MAX_STOPS];
	string times1[MAX_STOPS];
	string times2[MAX_STOPS];
	int numStops;
};
int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int chislo;
	menuosnova();
	while (!(cin >> chislo))
	{
		cin.clear();
		while (cin.get() != '\n'); {
			system("cls");
			cout << "Неверный ввод. Повторите." << endl;
			menuosnova();
		}
	}
	switch (chislo) {
	case 1: {
		system("cls");
		menu1();
		break;
	}
	case 2: {
		system("cls");
		menu2();
		break;
	}
	case 3: {
		system("cls");
		menu3();
		break;
	}
	case 4: {
		system("cls");
		cout << "Благодарим за использовние!" << endl;
		exit(0);
		break;
	}
	default: {
		system("cls");
		cout << "Неверный ввод. Повторите." << endl;
		main();
		break;
	}
	}
}
void menuosnova() {
	cout << "\t\t\tМеню" << endl;
	cout << "1. Регистрация пользователя и администратора" << endl;
	cout << "2. Авторизация пользователя и администратора" << endl;
	cout << "3. Восстановление пароля" << endl;
	cout << "4. Выход из приложения" << endl;
	cout << "Ваш выбор: ";
}
void menuregistration() {
	cout << "1. Зарегестрироваться пользователем" << endl;
	cout << "2. Зарегестрироваться администратором" << endl;
	cout << "3. Вернуться в меню" << endl;
	cout << "Ваш выбор: ";
}
void menuavyorizaciya() {
	cout << "1. Авторизоваться пользователем" << endl;
	cout << "2. Авторизоваться администратором" << endl;
	cout << "3. Вернуться в меню" << endl;
	cout << "Ваш выбор: ";
}
void menuvvostanovlenie() {
	cout << "1. Ввостановить пароль администратору" << endl;
	cout << "2. Ввостановить пароль пользователю" << endl;
	cout << "3. Вернутся в меню" << endl;
	cout << "Ваш выбор: ";
}
void menuadmina1() {
	cout << "1. Вывести всех пользователей в таблицу" << endl;
	cout << "2. Заблокировать пользователя" << endl;
	cout << "3. Разблокировать пользователя" << endl;
	cout << "4. Добавить расписание" << endl;
	cout << "5. Просмотреть конкретное расписание" << endl;
}
void menu1() {
	setlocale(LC_ALL, "rus");
	int chislo;
	menuregistration();
	while (!(cin >> chislo))
	{
		cin.clear();
		while (cin.get() != '\n'); {
			system("cls");
			cout << "Неверный ввод. Повторите." << endl;
			menuregistration();
		}
	}
	switch (chislo) {
	case 1: {
		system("cls");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		menuregistrationfilepol();
		break;
	}
	case 2: {
		system("cls");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		menuregistrationfileadmin();
		break;
	}
	case 3: {
		system("cls");
		main();
		break;
	}
	default: {
		system("cls");
		cout << "Неверный ввод. Повторите." << endl;
		menu1();
		break;
	}
	}
}
void menu2() {
	setlocale(LC_ALL, "rus");
	int chislo;
	menuavyorizaciya();
	while (!(cin >> chislo))
	{
		cin.clear();
		while (cin.get() != '\n'); {
			system("cls");
			cout << "Неверный ввод. Повторите." << endl;
			menuavyorizaciya();
		}
	}
	switch (chislo) {
	case 1: {
		system("cls");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		menuavyorizaciyafilepol();
		break;
	}
	case 2: {
		system("cls");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		menuavyorizaciyafileadmin();
		break;
	}
	case 3: {
		system("cls");
		main();
		break;
	}
	default: {
		system("cls");
		cout << "Неверный ввод. Повторите." << endl;
		menu1();
		break;
	}
	}
}
void menu3() {
	setlocale(LC_ALL, "rus");
	int chislo;
	menuvvostanovlenie();
	while (!(cin >> chislo))
	{
		cin.clear();
		while (cin.get() != '\n'); {
			system("cls");
			cout << "Неверный ввод. Повторите." << endl;
			menuvvostanovlenie();
		}
	}
	switch (chislo) {
	case 1: {
		system("cls");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		int ind = 2;
		vvostanovleniepass(ind);
		break;
	}
	case 2: {
		system("cls");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		int ind = 1;
		vvostanovleniepass(ind);
		break;
	}
	case 3: {
		system("cls");
		main();
		break;
	}
	default: {
		system("cls");
		cout << "Неверный ввод. Повторите." << endl;
		menu3();
		break;
	}
	}
}
void menuregistrationfilepol() {
	setlocale(LC_ALL, "rus");
	int ind = 0;
	string user, password, userproverka, secrslovo, proverka, status;
	cout << "Введите имя пользователя: ";
	getline(cin, user);
	if (user.find(' ') != string::npos) {
		system("cls");
		cout << "Никнейм не должен содержать пробелов.\n";
		menuregistrationfilepol();
	}
	else {
		ifstream filepol("userlogpass.txt");
		while (filepol >> userproverka || !filepol.eof()) {
			if (user == userproverka) {
				system("cls");
				cout << "Такой пользователь существует, введите другой никнейм" << endl;
				menuregistrationfilepol();
			}
		}
		filepol.close();
		provekapassword(password);
		secretslovo(secrslovo);
		status = "g";
		ofstream filepolz("userlogpass.txt", ios::app);
		filepolz << user << " " << password << " " << status << " " << secrslovo << endl;
		filepolz.close();
		system("cls");
		cout << "Регистрация прошла успешно, возвращаю вас в меню" << endl;
		main();

	}
}
void secretslovo(string& secrslo) {
	cout << "Введите секретное слово в случаи восстановления пароля: ";
	getline(cin, secrslo);
	if (secrslo.find(' ') != string::npos) {
		system("cls");
		cout << "Секретное слово не должено содержать пробелов.\n";
		secretslovo(secrslo);
	}
	else {
		system("cls");
	}
}
void provekapassword(string& password) {
	cout << "Введите пароль: ";
	getline(cin, password);
	if (password.find(' ') != string::npos) {
		system("cls");
		cout << "Пароль не должен содержать пробелов.\n";
		provekapassword(password);
	}
}
void vvostanovleniepass(int chislo) {
	if (chislo == 2) {
		int number = 0, ind = 0;
		string username, secretslovo, password, username1, secretslovo1, status;
		cout << "Введите ваше имя пользователя: ";
		getline(cin, username);
		if (username.find(' ') != string::npos) {
			system("cls");
			cout << "Никнейм не должен содержать пробелов, делайте ввод заново\n";
			number = 2;
			vvostanovleniepass(number);
		}
		cout << "Введите секреткное слово которое вы указывали при регитсрации: ";
		getline(cin, secretslovo);
		if (secretslovo.find(' ') != string::npos) {
			system("cls");
			cout << "Секретное слово не должно содержать пробелов, делайте ввод заново\n";
			number = 2;
			vvostanovleniepass(number);
		}
		ifstream FILE("userlogadmin.txt");
		while (!FILE.eof()) {
			FILE >> username1 >> password >> status >> secretslovo1;
			if (username == username1 && secretslovo == secretslovo1) {
				ind = 1;
				break;
			}
		}
		FILE.close();
		if (ind != 0) {
			system("cls");
			cout << "Вот ваш пароль: " << password << endl;
			main();
		}
		else {
			system("cls");
			cout << "Не могу вас найти, возвращаю в меню" << endl;
			main();
		}
	}
	else {
		int number = 0, ind = 0;
		string username, secretslovo, password, username1, secretslovo1, status;
		cout << "Введите ваше имя пользователя: ";
		getline(cin, username);
		if (username.find(' ') != string::npos) {
			system("cls");
			cout << "Никнейм не должен содержать пробелов, делайте ввод заново\n";
			number = 2;
			vvostanovleniepass(number);
		}
		cout << "Введите секреткное слово которое вы указывали при регитсрации: ";
		getline(cin, secretslovo);
		if (secretslovo.find(' ') != string::npos) {
			system("cls");
			cout << "Секретное слово не должно содержать пробелов, делайте ввод заново\n";
			number = 2;
			vvostanovleniepass(number);
		}
		ifstream FILE("userlogpass.txt");
		while (!FILE.eof()) {
			FILE >> username1 >> password >> status >> secretslovo1;
			if (username == username1 && secretslovo == secretslovo1) {
				ind = 1;
				break;
			}
		}
		FILE.close();
		if (ind != 0) {
			system("cls");
			cout << "Вот ваш пароль: " << password << endl;
			main();
		}
		else {
			system("cls");
			cout << "Не могу вас найти, возвращаю в меню" << endl;
			main();
		}
	}
}
void menuregistrationfileadmin() {
	setlocale(LC_ALL, "rus");
	int ind = 0;
	string user, password, userproverka, secrslovo, proverka, status;
	cout << "Введите имя пользователя: ";
	getline(cin, user);
	if (user.find(' ') != string::npos) {
		system("cls");
		cout << "Никнейм не должен содержать пробелов.\n";
		menuregistrationfileadmin();
	}
	else {
		ifstream filepol("userlogadmin.txt");
		while (filepol >> userproverka || !filepol.eof()) {
			if (user == userproverka) {
				system("cls");
				cout << "Такой пользователь существует, введите другой никнейм" << endl;
				menuregistrationfileadmin();
			}
		}
		filepol.close();
		provekapassword(password);
		secretslovo(secrslovo);
		status = "g";
		ofstream filepolz("userlogadmin.txt", ios::app);
		filepolz << user << " " << password << " " << status << " " << secrslovo << endl;
		filepolz.close();
		system("cls");
		cout << "Регистрация прошла успешно, возвращаю вас в меню" << endl;
		main();

	}
}
void menuavyorizaciyafilepol() {
	setlocale(LC_ALL, "rus");
	int ind = 0, number = 0;
	string user, password, USer, PASSword, slovo, status;
	cout << "Введите имя пользователя: ";
	getline(cin, user);
	if (user == "0") {
		system("cls");
		number = 1;
		vvostanovleniepass(number);
	}
	if (user.find(' ') != string::npos) {
		system("cls");
		cout << "Не вводите никнейм через пробел, попробуйте еще раз.\n";
		menuavyorizaciyafilepol();
	}
	else {
		provekapassword(password);
		ifstream fileavt("userlogpass.txt");
		while (!fileavt.eof()) {
			fileavt >> USer >> PASSword >> status >> slovo;
			if (user == USer && PASSword == password) {
				ind = 1;
				break;
			}
		}
		fileavt.close();
	}
	if (status == "заблокирован") {
		system("cls");
		cout << "Ваш профиль заблокирован!" << endl;
		main();
	}
	if (ind == 1) {
		system("cls");
		cout << "Добро пожаловать!" << endl;
		void menupozovatel();
	}
	else {
		system("cls");
		cout << "Если вы забыли пароль, нажмите 0" << endl;
		menuavyorizaciyafilepol();
	}
}
void menuavyorizaciyafileadmin() {
	setlocale(LC_ALL, "rus");
	int ind = 0, number = 0;
	string user, password, USer, PASSword, slovo, status;
	cout << "Введите имя администратора: ";
	getline(cin, user);
	if (user == "0") {
		system("cls");
		number = 2;
		vvostanovleniepass(number);
	}
	if (user.find(' ') != string::npos) {
		system("cls");
		cout << "Не вводите никнейм через пробел, попробуйте еще раз.\n";
		menuavyorizaciyafileadmin();
	}
	else {
		provekapassword(password);
		ifstream fileavt("userlogadmin.txt");
		while (!fileavt.eof()) {
			fileavt >> USer >> PASSword >> status >> slovo;
			if (user == USer && PASSword == password) {
				ind = 1;
				break;
			}
		}
		fileavt.close();
	}
	if (ind == 1) {
		system("cls");
		cout << "Добро пожаловать!" << endl;
		menuadmin();
	}
	else {
		system("cls");
		cout << "Если вы забыли пароль, нажмите 0" << endl;
		menuavyorizaciyafileadmin();
	}
}
void menupozovatel() {
	main();
}
void menuadmin() {
	setlocale(LC_ALL, "rus");
	int chislo;
	menuadmina1();
	while (!(cin >> chislo))
	{
		cin.clear();
		while (cin.get() != '\n'); {
			system("cls");
			cout << "Неверный ввод. Повторите." << endl;
			menuadmina1();
		}
	}
	switch (chislo) {
	case 1: {
		tablicapol();
		menuadmin();
		break;
	}
	case 2: {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		blockpolzovatel();
		break;
	}
	case 3: {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		razblockpolzovatel();
		break;
	}
	case 4: {
		system("cls");
		addBus();
		break;
	}
	case 5: {
		system("cls");
		viewBus();
		break;
	}
	default: {
		system("cls");
		cout << "Неверный ввод. Повторите." << endl;
		menuadmin();
		break;
	}
	}
}
void blockpolzovatel() {
	system("cls");
	string login, pass, status, secretslovo, blocklogin;
	int userfound = 0;
	ifstream fin("userlogpass.txt");
	ofstream fout("temp.txt");
	tablicarazblock();
	cout << "Введите логин пользователя, которого нужно заблокировать: ";
	getline(cin, blocklogin);
	if (blocklogin.find(' ') != string::npos) {
		fin.close();
		fout.close();
		system("cls");
		cout << "Не вводите никнейм через пробел, попробуйте еще раз.\n";
		Sleep(3000);
		blockpolzovatel();
	}
	else {
		while (fin >> login >> pass >> status >> secretslovo) {
			if (status == "заблокирован" && login == blocklogin) {
				system("cls");
				cout << "Этот пользователь заблокирован" << endl;
				remove("temp.txt");
				menuadmin();
			}
			if (login == blocklogin) {
				userfound = 1;
				status = "заблокирован";
			}
			fout << login << " " << pass << " " << status << " " << secretslovo << endl;
		}
		fin.close();
		fout.close();
		if (userfound == 1) {
			remove("userlogpass.txt");
			rename("temp.txt", "userlogpass.txt");
			system("cls");
			cout << "Пользователь " << blocklogin << " заблокирован" << endl;
			menuadmin();
		}
		else {
			remove("temp.txt");
			system("cls");
			cout << "Пользователь " << blocklogin << " не найден" << endl;
			menuadmin();
		}
	}
}
void tablicapol() {
	system("cls");
	string login, pass, secretslovo, status;
	ifstream tablica("userlogpass.txt");
	cout << "_______________________  Таблица  _________________________\n\n";
	int i = 1;
	while (tablica >> login >> pass >> status >> secretslovo) {
		cout << i << " Имя пользователя: " << login << endl;
		i++;
	}
	cout << "-----------------------------------------------------------\n\n";
	tablica.close();
}
void tablicazblock() {
	system("cls");
	string login, pass, secretslovo, status;
	ifstream tablica("userlogpass.txt");
	cout << "_______________________  Таблица  _________________________\n\n";
	int i = 1;
	while (tablica >> login >> pass >> status >> secretslovo) {
		if (status == "заблокирован") {
			cout << i << " Имя пользователя: " << login << endl;
			i++;
		}
	}
	cout << "-----------------------------------------------------------\n\n";
	tablica.close();
}
void tablicarazblock() {
	system("cls");
	string login, pass, secretslovo, status;
	ifstream tablica("userlogpass.txt");
	cout << "_______________________  Таблица  _________________________\n\n";
	int i = 1;
	while (tablica >> login >> pass >> status >> secretslovo) {
		if (status == "g") {
			cout << i << " Имя пользователя: " << login << endl;
			i++;
		}
	}
	cout << "-----------------------------------------------------------\n\n";
	tablica.close();
}
void razblockpolzovatel() {
	system("cls");
	string login, pass, status, secretslovo, razblocklogin;
	int userfound = 0;
	ifstream fin("userlogpass.txt");
	ofstream fout("temp.txt");
	tablicazblock();
	cout << "Введите логин пользователя, которого нужно раблокировать: ";
	getline(cin, razblocklogin);
	if (razblocklogin.find(' ') != string::npos) {
		fin.close();
		fout.close();
		system("cls");
		cout << "Не вводите никнейм через пробел, попробуйте еще раз.\n";
		Sleep(3000);
		razblockpolzovatel();
	}
	else {
		while (fin >> login >> pass >> status >> secretslovo) {
			if (login == razblocklogin) {
				userfound = 1;
				status = "g";
			}
			fout << login << " " << pass << " " << status << " " << secretslovo << endl;
		}
		fin.close();
		fout.close();
		if (userfound == 1) {
			remove("userlogpass.txt");
			rename("temp.txt", "userlogpass.txt");
			system("cls");
			cout << "Пользователь " << razblocklogin << " раблокирован" << endl;
			menuadmin();
		}
		else {
			remove("temp.txt");
			system("cls");
			cout << "Пользователь " << razblocklogin << " не найден" << endl;
			menuadmin();
		}
	}
}
void NUMBER_bus() {
	cout << "Введите номер рейса: ";
}
void kol_stops() {
	cout << "Введите количество остановок (максимум " << MAX_STOPS << " по городу" << "): ";
}
void type_avt() {
	cout << "Выберите тип автобуса: " << endl;
	cout << "1. Городской" << endl;
	cout << "2. Пригородный" << endl;
	cout << "Ваш выбор: ";
}
void addBus() {
	int chislo, ind = 0;
	BUS* buses = new BUS[1];
	string line;
	ofstream file("Автобусы.txt", ios::app);
	ifstream infile("Автобусы.txt");
	NUMBER_bus();
	while (!(cin >> buses[0].numberBUS))
	{
		cin.clear();
		while (cin.get() != '\n'); {
			system("cls");
			cout << "Неверный ввод. Повторите." << endl;
			NUMBER_bus();
		}
	}
	bool exists = false;
	while (getline(infile, line) && exists != true) {
		if (line.find("Автобус №" + to_string(buses[0].numberBUS)) != string::npos) {
			system("cls");
			exists = true;
			cout << "Расписание Автобус №" << buses[0].numberBUS << " уже существует" << endl;
			break;
		}
	}
	infile.close();
	if (exists == true) {
		delete[] buses;
		file.close();
		menuadmin();
	}
	type_avt();
	while (!(cin >> chislo))
	{
		cin.clear();
		while (cin.get() != '\n'); {
			system("cls");
			cout << "Неверный ввод. Повторите." << endl;
			type_avt();
		}
	}
	switch (chislo) {
	case 1: {
		system("cls");
		file << "Автобус №" << buses[0].numberBUS << endl;
		kol_stops();
		while (!(cin >> buses[0].numStops))
		{
			cin.clear();
			while (cin.get() != '\n'); {
				system("cls");
				cout << "Неверный ввод. Повторите." << endl;
				kol_stops();
			}
		}
		string type;
		type = "Городской";
		file << "Тип:" << endl;
		file << type << endl;
		for (int i = 0; i < buses[0].numStops; i++) {
			cout << "Введите название остановки " << i + 1 << ": ";
			cin >> buses[0].stops[i];
			cout << "Введите время прибытия к остановке" << i + 1 << ": ";
			cin >> buses[0].times2[i];
			cout << "Введите время отправления с остановки " << i + 1 << ": ";
			cin >> buses[0].times1[i];
		}
		file << "Остановки:" << endl;
		for (int i = 0; i < buses[0].numStops; i++) {
			file << buses[0].stops[i] << " к " << buses[0].times2[i] << " c " << buses[0].times1[i] << endl;
		}
		delete[] buses;
		file << endl;
		file.close();
		system("cls");
		cout << "Расписание добавлено" << endl;
		menuadmin();
		break;

	}
	case 2: {
		system("cls");
		file << "Автобус №" << buses[0].numberBUS << endl;
		string type, stops, time1, time2;
		type = "Пригородный";
		file << "Тип:" << endl;
		file << type << endl;
		cout << "Введите название остановки: ";
		cin >> buses[0].stops[0];
		cout << "Введите время прибытия к остановке: ";
		cin >> buses[0].times2[0];
		cout << "Введите время отправления с остановки: ";
		cin >> buses[0].times1[0];
		cout << "Введите название пункта прибытия: ";
		cin >> stops;
		cout << "Введите время прибытия к пункту назначения: ";
		cin >> time1;
		cout << "Введите время отправления с пункта назначения: ";
		cin >> time2;
		file << "Остановки:" << endl;
		file << buses[0].stops[0] << " к " << buses[0].times2[0] << " c " << buses[0].times1[0] << endl;
		file << stops << " к " << time1 << " c " << time2 << endl;
		delete[] buses;
		file << endl;
		file.close();
		system("cls");
		cout << "Расписание добавлено" << endl;
		menuadmin();
		break;
	}
	default: {
		system("cls");
		cout << "Неверный ввод. Повторите." << endl;
		break;
	}
	}
}
void viewBus() {
	ifstream infile("Автобусы.txt");
	int busNumber;
	cout << "Введите номер автобуса: ";
	cin >> busNumber;
	system("cls");
	bool found = false;
	string line;
	while (getline(infile, line)) {
		if (line.find("Автобус №" + to_string(busNumber)) != string::npos) {
			found = true;
			cout << line << endl;
			while (getline(infile, line) && line != "") {
				cout << line << endl;
			}
			break;
		}
	}
	infile.close();
	menuadmin();
	if (!found) {
		infile.close();
		cout << "Автобус №" << busNumber << " не найдено" << endl;
		menuadmin();
	}
}