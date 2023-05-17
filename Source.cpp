#define NOMINMAX
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#include <cctype>
#include <conio.h>
#include <iomanip>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <sstream>
using namespace std;
int main();
void vvostanovleniepass(int chislo);
void searchcityBUS(int& chislo);
void searchSuburbBUS(int& chislo);
void secretslovo(string& secrslo);
void provekapassword(string& password);
string proverkaprobelstopsbussity(string& slovo);
string priverkaprobeltime(string& slovo);
void tablica_city_bus();
void tablica_Suburd_bus();
void tablica_STOPScity(int& chislo);
void tablica_STOPSsuburn(int& chislo);
void tablica_STOPSindividyal_cityBUS();
void tablica_STOPSindividyal_SuburnBUS();
void menupolzovatel_osnovnoe();
void menuadmin_osnovnoe();
void menutext_osnovnoe();
void menutext_admin();
void menutext_polzovatel();
void menutext_dozapis();
void menutextvibor_registracii();
void menutextvibor_avtorizacii();
void menutextvibor_vvostanovleie_pass();
void text_individyal_zadanie_vibor();
void text_Sort();
void text_Sortcity_BUS();
void text_SortSuburn_Bus();
void menuvibor_registracii();
void menuvibor_avtorizacii();
void menuvibor_vvostanovleie_pass();
void registationpolzovatel();
void registrationadmin();
void avtorizacii_polzovatel();
void avtorizacii_admin();
void blokirovla_plzpvatelya();
void razblokirovka_polzovatel();
void tablicapolzovateley();
void addBUS();
void vibortext_addBUS();
void viborsearch_bus_konretno(int& ind);
void textsearch_bus_konretno();
void textdelete_bus();
void vibordelete_bus();
void vibor_dozapis();
void dozapis_city_bus();
void dozapis_Suburn_bus();
void individyal_zadanie_vibor(int &chislo);
void individyal_zadanie_cityBUS(int& chislo);
void individyal_zadanie_SuburnBUS(int& chislo);
void sortVIBOR(int& chislo);
void sortBUS_city(int &chislo);
void sortSuburn(int& chislo);
struct BUS {
	int numBUS;
	string nameSTOPS;
	string typeBUS;
	string time;
};
void secretslovo(string& secrslo) {
	cout << "Введите секретное слово в случаи восстановления пароля: ";
	getline(cin, secrslo);
	if (secrslo.empty() == true) {
		system("cls");
		cout << "Секретное слово не должено ничего!\n";
		secretslovo(secrslo);
	}
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
	char ch = _getch();
	while (ch != '\r') { // пока не нажата клавиша Enter
		if (ch == '\b') { // если нажата клавиша Backspace
			if (!password.empty()) { // и пароль не пустой
				cout << "\b \b"; // удаляем последний символ и двигаем курсор на место
				password.pop_back(); // удаляем последний символ из строки
			}
		}
		else {
			cout << "*"; // выводим звездочку вместо введенного символа
			password.push_back(ch); // добавляем символ в конец строки
		}
		ch = _getch(); // считываем следующий символ
	}
	cout << endl; // переводим строку после ввода пароля
	if (password.empty()) {
		system("cls");
		cout << "Пароль не должен содержать ничего!\n";
		password.clear();
		provekapassword(password);
	}
	if (password.find(' ') != string::npos) {
		system("cls");
		cout << "Пароль не должен содержать пробелов.\n";
		password.clear();
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
string proverkaprobelstopsbussity(string& slovo) {
	cout << "В случаи завершения окончания записи вообще, введите stop" << endl;
	cout << "Введите название остановки: ";
	getline(cin, slovo);
	if (slovo.empty() == true) {
		system("cls");
		cout << "Название остановки не должно содержать ничего!\n";
		proverkaprobelstopsbussity(slovo);
	}
	if (slovo.find(' ') != string::npos) {
		system("cls");
		cout << "Название остановки не должно содержать пробелов!" << endl;
		proverkaprobelstopsbussity(slovo);
	}
	if (slovo == "stop") {
		return slovo;
	}
	return "";
}
string priverkaprobeltime(string& slovo) {
	cout << "В случаи завершения окончания записи времени прибытия к остановке, введите end" << endl;
	cout << "Введите время прибытия к этой остановке: ";
	getline(cin, slovo);
	if (slovo.empty() == true) {
		system("cls");
		cout << "Время не должно содержать ничего!\n";
		priverkaprobeltime(slovo);
	}
	if (slovo.find(' ') != string::npos) {
		system("cls");
		cout << "Во времени не пишется пробел. Вот пример времени(13:00)!" << endl;
		priverkaprobeltime(slovo);
	}
	if (slovo == "end") {
		return slovo;
	}
	return "";
}
void menutext_osnovnoe() {
	cout << "\t\t\tМеню" << endl;
	cout << "1. Регистрация пользователя и администратора" << endl;
	cout << "2. Авторизация пользователя и администратора" << endl;
	cout << "3. Восстановление пароля" << endl;
	cout << "4. Выход из приложения" << endl;
	cout << "Ваш выбор: ";
}
void menutextvibor_registracii() {
	cout << "\t\t Меню" << endl;
	cout << "1. Зарегестрироваться пользователем" << endl;
	cout << "2. Зарегестрироваться администратором" << endl;
	cout << "3. Вернуться в меню" << endl;
	cout << "Ваш выбор: ";
}
void menutextvibor_avtorizacii() {
	cout << "\t\t Меню" << endl;
	cout << "1. Авторизоваться пользователем" << endl;
	cout << "2. Авторизоваться администратором" << endl;
	cout << "3. Вернуться в меню" << endl;
	cout << "Ваш выбор: ";
}
void menutextvibor_vvostanovleie_pass() {
	cout << "\t\t Меню" << endl;
	cout << "1. Ввостановить пароль администратору" << endl;
	cout << "2. Ввостановить пароль пользователю" << endl;
	cout << "3. Вернутся в меню" << endl;
	cout << "Ваш выбор: ";
}
void menutext_admin() {
	cout << "\t\t Меню" << endl;
	cout << "1. Вывести всех пользователей в таблицу" << endl;
	cout << "2. Заблокировать пользователя" << endl;
	cout << "3. Разблокировать пользователя" << endl;
	cout << "4. Добавить расписание" << endl;
	cout << "5. Просмотреть текущее расписание" << endl;
	cout << "6. Удаление расписания" << endl;
	cout << "7. Сделать дозапись текущего расписания автобусов" << endl;
	cout << "8. Сортировка по номеру автобуса" << endl;
	cout << "9. Вывести информацию об атобусах для прибытия в пункт назначения" << endl;
	cout << "10. Выйти из приложения" << endl;
	cout << "Ваш выбор: ";
}
void menutext_polzovatel() {
	cout << "\t\t Меню" << endl;
	cout << "1. Просмотреть текущее расписание" << endl;
	cout << "2. Сортировка по номеру автобуса" << endl;
	cout << "3. Вывести информацию об атобусах для прибытия в пункт назначения" << endl;
	cout << "4. Выйти из приложения" << endl;
	cout << "Ваш выбор: ";
}
void vibortext_addBUS() {
	cout << "\t\t Меню" << endl;
	cout << "Выберите тип автобуса который хотите добавить" << endl;
	cout << "1. Городской" << endl;
	cout << "2. Пригородный" << endl;
	cout << "3. Вернуться назад" << endl;
	cout << "Ваш выбор: ";
}
void textsearch_bus_konretno() {
	cout << "\t\t Меню" << endl;
	cout << "1. Посмотреть распиание городского автобуса" << endl;
	cout << "2. Посмотреть распиание пригородного автобуса" << endl;
	cout << "3. Вернуться назад" << endl;
	cout << "Ваш выбор: ";
}
void textdelete_bus() {
	cout << "\t\t Меню" << endl;
	cout << "1. Удалить расписание городского автобуса" << endl;
	cout << "2. Удалить расписание пригородного автобуса" << endl;
	cout << "3. Удалить текущую остановку городского автобуса" << endl;
	cout << "4. Удалить текущую остановку пригородного автобуса" << endl;
	cout << "5. Вернуться назад" << endl;
	cout << "Ваш выбор: ";
}
void menutext_dozapis() {
	cout << "\t\t Меню" << endl;
	cout << "1. Сделать дозапись остановок городского автобуса" << endl;
	cout << "2. Сделать дозапись остановок пригородного автобуса" << endl;
	cout << "3. Вернуться в меню" << endl;
	cout << "Ваш выбор: ";
}
void text_individyal_zadanie_vibor() {
	cout << "\t\t Меню" << endl;
	cout << "1. Вывести информацию об городских автобусах для прибытия в пункт назначения" << endl;
	cout << "2. Вывести информацию об пригородных автобусах для прибытия в пункт назначения" << endl;
	cout << "3. Вернуться назад" << endl;
	cout << "Ваш выбор: ";
}
void text_Sort() {
	cout << "\t\t Меню" << endl;
	cout << "1. Отсортировать и показать в таблице городские автобусы" << endl;
	cout << "2. Отсортировать и показать в таблице пригородные автобусы" << endl;
	cout << "3. Вернуться назад" << endl;
	cout << "Ваш выбор: ";
}
void text_Sortcity_BUS() {
	cout << "\t\t Меню" << endl;
	cout << "1. Отсортировать городские автобусы по возрастанию" << endl;
	cout << "2. Отсортировать городские автобусы по убыванию" << endl;
	cout << "3. Вернуться назад" << endl;
	cout << "Ваш выбор: ";
}
void text_SortSuburn_Bus() {
	cout << "\t\t Меню" << endl;
	cout << "1. Отсортировать пригородные автобусы по возрастанию" << endl;
	cout << "2. Отсортировать пригородные автобусы по убыванию" << endl;
	cout << "3. Вернуться назад" << endl;
	cout << "Ваш выбор: ";
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	menutext_osnovnoe();
	int chislo;
	while (!(cin >> chislo))
	{
		cin.clear();
		while (cin.get() != '\n') {
			system("cls");
			cout << "Неверный ввод. Повторите." << endl;
			menutext_osnovnoe();
		}
	}
	switch (chislo) {
	case 1: {
		system("cls");
		menuvibor_registracii();
		break;
	}
	case 2: {
		system("cls");
		menuvibor_avtorizacii();
		break;
	}
	case 3: {
		system("cls");
		menuvibor_vvostanovleie_pass();
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
void menuvibor_registracii() {
	int chislo;
	menutextvibor_registracii();
	while (!(cin >> chislo))
	{
		cin.clear();
		while (cin.get() != '\n') {
			system("cls");
			cout << "Неверный ввод. Повторите." << endl;
			menutextvibor_registracii();
		}
	}
	switch (chislo) {
	case 1: {
		system("cls");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		registationpolzovatel();
		break;
	}
	case 2: {
		system("cls");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		registrationadmin();
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
		menutextvibor_registracii();
		break;
	}
	}
}
void registationpolzovatel() {
	int ind = 0;
	string user, password, userproverka, secrslovo, proverka, status;
	cout << "Введите никнейм пользователя: ";
	getline(cin, user);
	if (user.empty() == true) {
		system("cls");
		cout << "Никнейм не должен содержать ничего!\n";
		registationpolzovatel();
	}
	if (user.find(' ') != string::npos) {
		system("cls");
		cout << "Никнейм не должен содержать пробелов.\n";
		registationpolzovatel();
	}
	else {
		ifstream filepol("userlogpass.txt");
		while (filepol >> userproverka || !filepol.eof()) {
			if (user == userproverka) {
				system("cls");
				cout << "Такой пользователь существует, введите другой никнейм" << endl;
				registationpolzovatel();
			}
		}
		filepol.close();
		provekapassword(password);
		secretslovo(secrslovo);
		status = "Активный";
		ofstream filepolz("userlogpass.txt", ios::app);
		filepolz << user << " " << password << " " << status << " " << secrslovo << endl;
		filepolz.close();
		system("cls");
		cout << "Регистрация прошла успешно, возвращаю вас в меню" << endl;
		main();
	}
}
void registrationadmin() {
	int ind = 0;
	string user, password, userproverka, secrslovo, proverka, status;
	cout << "Введите имя пользователя: ";
	getline(cin, user);
	if (user.empty() == true) {
		system("cls");
		cout << "Никнейм не должен содержать ничего!\n";
		registrationadmin();
	}
	if (user.find(' ') != string::npos) {
		system("cls");
		cout << "Никнейм не должен содержать пробелов.\n";
		registrationadmin();
	}
	else {
		ifstream filepol("userlogadmin.txt");
		while (filepol >> userproverka || !filepol.eof()) {
			if (user == userproverka) {
				system("cls");
				cout << "Такой пользователь существует, введите другой никнейм" << endl;
				registrationadmin();
			}
		}
		filepol.close();
		provekapassword(password);
		secretslovo(secrslovo);
		status = "Активный";
		ofstream filepolz("userlogadmin.txt", ios::app);
		filepolz << user << " " << password << " " << status << " " << secrslovo << endl;
		filepolz.close();
		system("cls");
		cout << "Регистрация прошла успешно, возвращаю вас в меню" << endl;
		main();
	}
}
void menuvibor_avtorizacii() {
	int chislo;
	menutextvibor_avtorizacii();
	while (!(cin >> chislo))
	{
		cin.clear();
		while (cin.get() != '\n') {
			system("cls");
			cout << "Неверный ввод. Повторите." << endl;
			menutextvibor_avtorizacii();;
		}
	}
	switch (chislo) {
	case 1: {
		system("cls");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		avtorizacii_polzovatel();
		break;
	}
	case 2: {
		system("cls");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		avtorizacii_admin();
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
		menuvibor_avtorizacii();
		break;
	}
	}
}
void avtorizacii_polzovatel() {
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
		avtorizacii_polzovatel();
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
		menupolzovatel_osnovnoe();
	}
	else {
		system("cls");
		cout << "Если вы забыли пароль, нажмите 0" << endl;
		avtorizacii_polzovatel();
	}
}
void avtorizacii_admin() {
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
		avtorizacii_admin();
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
		menuadmin_osnovnoe();
	}
	else {
		system("cls");
		cout << "Если вы забыли пароль, нажмите 0" << endl;
		avtorizacii_admin();
	}
}
void menuvibor_vvostanovleie_pass() {
	int chislo;
	menutextvibor_vvostanovleie_pass();
	while (!(cin >> chislo))
	{
		cin.clear();
		while (cin.get() != '\n') {
			system("cls");
			cout << "Неверный ввод. Повторите." << endl;
			menuvibor_vvostanovleie_pass();
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
		menuvibor_vvostanovleie_pass();
		break;
	}
	}
}
void menupolzovatel_osnovnoe() {
	int chislo, ind = 2;
	menutext_polzovatel();
	while (!(cin >> chislo))
	{
		cin.clear();
		while (cin.get() != '\n') {
			system("cls");
			cout << "Неверный ввод. Повторите." << endl;
			menutext_polzovatel();
		}
	}
	switch (chislo) {
	case 1: {
		system("cls");
		viborsearch_bus_konretno(ind);
		break;
	}
	case 2: {
		system("cls");
		sortVIBOR(ind);
		break;
	}
	case 3: {
		system("cls");
		individyal_zadanie_vibor(ind);
		break;
	}
	case 4: {
		system("cls");
		cout << "Благодарю за использование" << endl;
		exit(1);
		break;
	}
	default: {
		system("cls");
		cout << "Неверный ввод. Повторите." << endl;
		menupolzovatel_osnovnoe();
		break;
	}
	}
}
void menuadmin_osnovnoe() {
	int chislo, ind = 1;
	menutext_admin();
	while (!(cin >> chislo))
	{
		cin.clear();
		while (cin.get() != '\n') {
			system("cls");
			cout << "Неверный ввод. Повторите." << endl;
			menutext_admin();
		}
	}
	switch (chislo) {
	case 1: {
		tablicapolzovateley();
		system("pause");
		system("cls");
		menuadmin_osnovnoe();
		break;
	}
	case 2: {
		system("cls");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		blokirovla_plzpvatelya();
		break;
	}
	case 3: {
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		razblokirovka_polzovatel();
		break;
	}
	case 4: {
		system("cls");
		addBUS();
		break;
	}
	case 5: {
		system("cls");
		viborsearch_bus_konretno(ind);
		break;
	}
	case 6: {
		system("cls");
		vibordelete_bus();
		break;
	}
	case 7: {
		system("cls");
		vibor_dozapis();
		break;
	}
	case 8: {
		system("cls");
		sortVIBOR(ind);
		break;
	}
	case 9: {
		system("cls");
		individyal_zadanie_vibor(ind);
		break;
	}
	case 10: {
		system("cls");
		cout << "Благодарю за использование" << endl;
		exit(1);
		break;
	}
	default: {
		system("cls");
		cout << "Неверный ввод. Повторите." << endl;
		menuadmin_osnovnoe();
		break;
	}
	}
}
void blokirovla_plzpvatelya() {
	string login, pass, status, secretslovo, blocklogin;
	int userfound = 0;
	ifstream fin("userlogpass.txt");
	ofstream fout("temp.txt");
	tablicapolzovateley();
	cout << "Введите логин пользователя, которого нужно заблокировать: ";
	getline(cin, blocklogin);
	if (blocklogin.find(' ') != string::npos) {
		fin.close();
		fout.close();
		system("cls");
		cout << "Не вводите никнейм через пробел, попробуйте еще раз.\n";
		system("cls");
		blokirovla_plzpvatelya();
	}
	else {
		while (fin >> login >> pass >> status >> secretslovo) {
			if (status == "заблокирован" && login == blocklogin) {
				system("cls");
				fin.close();
				fout.close();
				cout << "Этот пользователь и так заблокирован" << endl;
				remove("temp.txt");
				menuadmin_osnovnoe();
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
			menuadmin_osnovnoe();
		}
		else {
			remove("temp.txt");
			system("cls");
			cout << "Пользователь " << blocklogin << " не найден" << endl;
			menuadmin_osnovnoe();
		}
	}
}
void razblokirovka_polzovatel() {
	string login, pass, status, secretslovo, blocklogin;
	int userfound = 0;
	ifstream fin("userlogpass.txt");
	ofstream fout("temp.txt");
	tablicapolzovateley();
	cout << "Введите логин пользователя, которого нужно разблокировать: ";
	getline(cin, blocklogin);
	if (blocklogin.find(' ') != string::npos) {
		fin.close();
		fout.close();
		system("cls");
		cout << "Не вводите никнейм через пробел, попробуйте еще раз.\n";
		system("cls");
		razblokirovka_polzovatel();
	}
	else {
		while (fin >> login >> pass >> status >> secretslovo) {
			if (status == "Активный" && login == blocklogin) {
				system("cls");
				fin.close();
				fout.close();
				cout << "Этот пользователь и так разблокирован" << endl;
				remove("temp.txt");
				menuadmin_osnovnoe();
			}
			if (login == blocklogin) {
				userfound = 1;
				status = "Активный";
			}
			fout << login << " " << pass << " " << status << " " << secretslovo << endl;
		}
		fin.close();
		fout.close();
		if (userfound == 1) {
			remove("userlogpass.txt");
			rename("temp.txt", "userlogpass.txt");
			system("cls");
			cout << "Пользователь " << blocklogin << " разблокирован" << endl;
			menuadmin_osnovnoe();
		}
		else {
			remove("temp.txt");
			system("cls");
			cout << "Пользователь " << blocklogin << " не найден" << endl;
			menuadmin_osnovnoe();
		}
	}
}
void tablicapolzovateley() {
	system("cls");
	string login, pass, secretslovo, status;
	ifstream tablica("userlogpass.txt");
	cout << "_______________________  Таблица  _________________________\n\n";
	int i = 1;
	while (tablica >> login >> pass >> status >> secretslovo) {
		cout << i << " Имя пользователя: " << login << " "  << "cтатус: " << status << endl;
		i++;
	}
	cout << "-----------------------------------------------------------\n\n";
	tablica.close();
}
void addBUS() {
	int chislo;
	vibortext_addBUS();
	while (!(cin >> chislo)) {
		cin.clear();
		while (cin.get() != '\n') {
			system("cls");
			cout << "Неверный ввод. Повторите." << endl;
			addBUS();
		}
	}
	switch (chislo) {
	case 1: {
		system("cls");
		string line;
		BUS* buses = new BUS[1];
		buses[0].typeBUS = "Городской";
		cout << "Укажите номер рейса: ";
		while (!(cin >> buses[0].numBUS)) {
			cin.clear();
			while (cin.get() != '\n') {
				system("cls");
				cout << "Номер рейса не может быть буквенный. Повторите попытку" << endl;
				cout << "Укажите номер рейса: ";
			}
		}
		bool exit = false;
		ifstream FILE("Автобус.txt");
		while (getline(FILE, line) && exit != true) {
			if (line.find("Автобус №" + to_string(buses[0].numBUS) + ".") != string::npos) {
				exit = true;
			}
		}
		FILE.close();
		if (exit == true) {
			system("cls");
			delete[] buses;
			cout << "Такой номер рейса уже существует" << endl;
			addBUS();
		}
		else {
			string kol;
			string stop1, stop2, stop3, stop4, stop5, stop6, stop7;
			ofstream file("Автобус.txt", ios::app);
			file << "Автобус №" << buses[0].numBUS << "." << endl;
			file << "Тип:" << ' ' << buses[0].typeBUS << endl;
			file << "Остановки:" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			while (1) {
				system("cls");
				kol = proverkaprobelstopsbussity(buses[0].nameSTOPS);
				if (kol == "stop") {
					break;
				}
				file << buses[0].nameSTOPS << endl;
				int chetcik = 0;
				while (1) {
					system("cls");
					kol = priverkaprobeltime(buses[0].time);
					if (kol == "end") {
						if (chetcik == 0) {
							file << "m" << ' ' << "m" << ' ' << "m" << ' ' << "m" << ' ' << "m" << ' ' << "m" << ' '<< "m";
							file << endl;
						}
						else if (chetcik == 1) {
							file << "g" << ' ' << "g" << ' ' << "g" << ' ' << "g" << ' ' << "g" << ' ' << "g";
							file << endl;
						}
						else if (chetcik == 2) {
							file << "g" << ' ' << "g" << ' ' << "g" << ' ' << "g" << ' ' << "g";
							file << endl;
						}
						else if (chetcik == 3) {
							file << "g" << ' ' << "g" << ' ' << "g" << ' ' << "g";
							file << endl;
						}
						else if (chetcik == 4) {
							file << "g" << ' ' << "g" << ' ' << "g";
							file << endl;
						}
						else if (chetcik == 5) {
							file << "g" << ' ' << "g";
							file << endl;
						}
						else if (chetcik == 6) {
							file << "g";
							file << endl;
						}
						break;
					}
					chetcik++;
					if (chetcik == 7) {
						chetcik = 0;
						file << buses[0].time << ";" << ' ';
						file << endl;
					}
					else {
						file << buses[0].time << ";" << ' ';
					}
				}
			}
			file << "end" << endl;
			file.close();
			delete[] buses;
			system("cls");
			cout << "Расписание добавлено успешно" << endl;
			menuadmin_osnovnoe();
		}
		break;
	}
	case 2: {
		system("cls");
		string line;
		BUS* buses = new BUS[1];
		buses[0].typeBUS = "Пригородный";
		cout << "Укажите номер рейса: ";
		while (!(cin >> buses[0].numBUS)) {
			cin.clear();
			while (cin.get() != '\n') {
				system("cls");
				cout << "Номер рейса не может быть буквенный. Повторите попытку" << endl;
				cout << "Укажите номер рейса: ";
			}
		}
		bool exit = false;
		ifstream FILE("Автобус.txt");
		while (getline(FILE, line) && exit != true) {
			if (line.find("Автобус №" + to_string(buses[0].numBUS) + ".") != string::npos) {
				exit = true;
			}
		}
		FILE.close();
		if (exit == true) {
			system("cls");
			delete[] buses;
			cout << "Такой номер рейса уже существует" << endl;
			addBUS();
		}
		else {
			string kol;
			string stop1, stop2, stop3, stop4, stop5, stop6, stop7;
			ofstream file("Автобус.txt", ios::app);
			file << "Автобус №" << buses[0].numBUS << "." << endl;
			file << "Тип:" << ' ' << buses[0].typeBUS << endl;
			file << "Остановки:" << endl;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			while (1) {
				system("cls");
				kol = proverkaprobelstopsbussity(buses[0].nameSTOPS);
				if (kol == "stop") {
					break;
				}
				file << buses[0].nameSTOPS << endl;
				int chetcik = 0;
				while (1) {
					system("cls");
					kol = priverkaprobeltime(buses[0].time);
					if (kol == "end") {
						if (chetcik == 0) {
							file << "m" << ' ' << "m" << ' ' << "m" << ' ' << "m" << ' ' << "m" << ' ' << "m" << ' ' << "m";
							file << endl;
						}
						else if (chetcik == 1) {
							file << "g" << ' ' << "g" << ' ' << "g" << ' ' << "g" << ' ' << "g" << ' ' << "g";
							file << endl;
						}
						else if (chetcik == 2) {
							file << "g" << ' ' << "g" << ' ' << "g" << ' ' << "g" << ' ' << "g";
							file << endl;
						}
						else if (chetcik == 3) {
							file << "g" << ' ' << "g" << ' ' << "g" << ' ' << "g";
							file << endl;
						}
						else if (chetcik == 4) {
							file << "g" << ' ' << "g" << ' ' << "g";
							file << endl;
						}
						else if (chetcik == 5) {
							file << "g" << ' ' << "g";
							file << endl;
						}
						else if (chetcik == 6) {
							file << "g";
							file << endl;
						}
						break;
					}
					chetcik++;
					if (chetcik == 7) {
						chetcik = 0;
						file << buses[0].time << ";" << ' ';
						file << endl;
					}
					else {
						file << buses[0].time << ";" << ' ';
					}
				}
			}
			file << "end" << endl;
			file.close();
			delete[] buses;
			system("cls");
			cout << "Расписание добавлено успешно" << endl;
			menuadmin_osnovnoe();
		}
		break;
	}
	case 3: {
		system("cls");
		menuadmin_osnovnoe();
		break;
	}
	default: {
		system("cls");
		cout << "Неккоректный ввод" << endl;
		addBUS();
	}
	}
}
void viborsearch_bus_konretno(int& ind){
	int chislo;
	textsearch_bus_konretno();
	while (!(cin >> chislo)) {
		cin.clear();
		while (cin.get() != '\n') {
			system("cls");
			cout << "Не вводите букву!" << endl;
			textsearch_bus_konretno();
		}
	}
	switch (chislo) {
	case 1: {
		system("cls");
		searchcityBUS(ind);
		break;
	}
	case 2: {
		system("cls");
		searchSuburbBUS(ind);
		break;
	}
	case 3: {
		if (ind == 1) {
			system("cls");
			menuadmin_osnovnoe();
			break;
		}
		else if (ind == 2) {
			system("cls");
			menupolzovatel_osnovnoe();
			break;
		}
	}
	default: {
		system("cls");
		cout << "Введите 1, 2 или 3" << endl;
		viborsearch_bus_konretno(ind);
	}
	}
}
void searchcityBUS(int& chislo) {
	int ind;
	string line, typeBUS, line1;
	tablica_city_bus();
	cout << "Введите номер автобуса из предложенных: ";
	while (!(cin >> ind)) {
		cin.clear();
		while (cin.get() != '\n') {
			system("cls");
			cout << "Номер автобуса не может состоять только из букв!" << endl;
			tablica_city_bus();
			cout << "Введите номер автобуса из предложенных: ";
		}
	}
	bool exit = false;
	ifstream FILE("Автобус.txt");
	while (getline(FILE, typeBUS) && exit != true) {
		if ((typeBUS.find("Автобус №" + to_string(ind) + ".") != string::npos)) {
			getline(FILE, line);
			if ((line.find("Тип: Городской") != string::npos)) {
				while (getline(FILE, line1)) {
					if (line1.find("end") != string::npos) {
						break;
					}
				}
				exit = true;
			}
		}
	}
	FILE.close();
	if (exit == true) {
		string nameBUS, type, stop0, stop1, time1, time2, time3, time4, time5, time6, time7;
		system("cls");
		ifstream FILE("Автобус.txt");
		cout << "Автобус №" << ind << endl;
		cout << "Остановки с временем прибытия: " << endl;
		while (getline(FILE, nameBUS)) {
			if (nameBUS.find("Автобус №" + to_string(ind) + ".") != string::npos) {
				getline(FILE, type);
				if (type.find("Тип: Городской") != string::npos) {
					getline(FILE, stop0);
					if (stop0.find("Остановки:") != string::npos) {
						while (FILE >> stop1) {
							if (stop1 == "end") {
								break;
							}
							cout << "\t Остановка: " << stop1 << endl;
							while (FILE >> time1 >> time2 >> time3 >> time4 >> time5 >> time6 >> time7) {
								if (time7 == "m" && time6 == "m" && time5 == "m" && time4 == "m" && time3 == "m" && time2 == "m" && time1 == "m") {
									break;
								}
								else if (time7 == "g" && time6 == "g" && time5 == "g" && time4 == "g" && time3 == "g" && time2 == "g") {
									cout << time1 << endl;
									break;
								}
								else if (time7 == "g" && time6 == "g" && time5 == "g" && time4 == "g" && time3 == "g") {
									cout << time1 << " " << time2 << endl;
									break;
								}
								else if (time7 == "g" && time6 == "g" && time5 == "g" && time4 == "g") {
									cout << time1 << " " << time2 << " " << time3 << endl;
									break;
								}
								else if (time7 == "g" && time6 == "g" && time5 == "g") {
									cout << time1 << " " << time2 << " " << time3 << " " << time4 << endl;
									break;
								}
								else if (time7 == "g" && time6 == "g") {
									cout << time1 << " " << time2 << " " << time3 << " " << time4 << " " << time5 << endl;
									break;
								}
								else if (time7 == "g") {
									cout << time1 << " " << time2 << " " << time3 << " " << time4 << " " << time5 << " " << time6 << endl;
									break;
								}
								cout << time1 << " " << time2 << " " << time3 << " " << time4 << " " << time5 << " " << time6 << " " << time7 << endl;
							}
						}
						break;
					}
				}
			}
		}
		FILE.close();
		system("pause");
		system("cls");
		if (chislo == 1) {
			menuadmin_osnovnoe();
		}
		else if (chislo == 2) {
			menupolzovatel_osnovnoe();
		}
	}
	else {
		system("cls");
		cout << "Такого в таблице нету, выберите из списка нужный вам автобус" << endl;
		searchcityBUS(chislo);
	}
}
void searchSuburbBUS(int& chislo) {
	int ind;
	string line, typeBUS, line1;
	tablica_Suburd_bus();
	cout << "Введите номер автобуса из предложенных: ";
	while (!(cin >> ind)) {
		cin.clear();
		while (cin.get() != '\n') {
			system("cls");
			cout << "Номер автобуса не может состоять только из букв!" << endl;
			tablica_Suburd_bus();
			cout << "Введите номер автобуса из предложенных: ";
		}
	}
	bool exit = false;
	ifstream FILE("Автобус.txt");
	while (getline(FILE, typeBUS) && exit != true) {
		if ((typeBUS.find("Автобус №" + to_string(ind) + ".") != string::npos)) {
			getline(FILE, line);
			if ((line.find("Тип: Пригородный") != string::npos)) {
				while (getline(FILE, line1)) {
					if (line1.find("end") != string::npos) {
						break;
					}
				}
				exit = true;
			}
		}
	}
	FILE.close();
	if (exit == true) {
		string nameBUS, type, stop0, stop1, time1, time2, time3, time4, time5, time6, time7;
		system("cls");
		ifstream FILE("Автобус.txt");
		cout << "Автобус №" << ind << endl;
		cout << "Остановки с временем прибытия: " << endl;
		while (getline(FILE, nameBUS)) {
			if (nameBUS.find("Автобус №" + to_string(ind) + ".") != string::npos) {
				getline(FILE, type);
				if (type.find("Тип: Пригородный") != string::npos) {
					getline(FILE, stop0);
					if (stop0.find("Остановки:") != string::npos) {
						while (FILE >> stop1) {
							if (stop1 == "end") {
								break;
							}
							cout << "\t Остановка: " << stop1 << endl;
							while (FILE >> time1 >> time2 >> time3 >> time4 >> time5 >> time6 >> time7) {
								if (time7 == "m" && time6 == "m" && time5 == "m" && time4 == "m" && time3 == "m" && time2 == "m" && time1 == "m") {
									break;
								}
								else if (time7 == "g" && time6 == "g" && time5 == "g" && time4 == "g" && time3 == "g" && time2 == "g") {
									cout << time1 << endl;
									break;
								}
								else if (time7 == "g" && time6 == "g" && time5 == "g" && time4 == "g" && time3 == "g") {
									cout << time1 << " " << time2 << endl;
									break;
								}
								else if (time7 == "g" && time6 == "g" && time5 == "g" && time4 == "g") {
									cout << time1 << " " << time2 << " " << time3 << endl;
									break;
								}
								else if (time7 == "g" && time6 == "g" && time5 == "g") {
									cout << time1 << " " << time2 << " " << time3 << " " << time4 << endl;
									break;
								}
								else if (time7 == "g" && time6 == "g") {
									cout << time1 << " " << time2 << " " << time3 << " " << time4 << " " << time5 << endl;
									break;
								}
								else if (time7 == "g") {
									cout << time1 << " " << time2 << " " << time3 << " " << time4 << " " << time5 << " " << time6 << endl;
									break;
								}
								cout << time1 << " " << time2 << " " << time3 << " " << time4 << " " << time5 << " " << time6 << " " << time7 << endl;
							}
						}
						break;
					}
				}
			}
		}
		FILE.close();
		system("pause");
		system("cls");
		if (chislo == 1) {
			menuadmin_osnovnoe();
		}
		else if (chislo == 2) {
			menupolzovatel_osnovnoe();
		}
	}
	else {
		system("cls");
		cout << "Такого в таблице нету, выберите из списка нужный вам автобус" << endl;
		searchSuburbBUS(chislo);
	}
}
void vibordelete_bus() {
	int chislo;
	textdelete_bus();
	while (!(cin >> chislo)) {
		cin.clear();
		if (cin.get() != '\n') {
			system("cls");
			cout << "Ошибка ввода!" << endl;
			textdelete_bus();
		}
	}
	switch (chislo) {
	case 1: {
		system("cls");
		int ind;
		string line, line1, typeBUS;
		tablica_city_bus();
		cout << "Выберите номер автобуса который хотите удалить: ";
		while (!(cin >> ind)) {
			cin.clear();
			if (cin.get() != '\n') {
				system("cls");
				cout << "Введите номер предложенный в таблиице!!!" << endl;
				tablica_city_bus();
				cout << "Выберите номер автобуса который хотите удалить: ";

			}
		}
		bool exit = false;
		ifstream FILE("Автобус.txt");
		while (getline(FILE, typeBUS) && exit != true) {
			if ((typeBUS.find("Автобус №" + to_string(ind) + ".") != string::npos)) {
				getline(FILE, line);
				if ((line.find("Тип: Городской") != string::npos)) {
					while (getline(FILE, line1)) {
						if (line1.find("end") != string::npos) {
							break;
						}
					}
					exit = true;
				}
			}
		}
		FILE.close();
		if (exit == true) {
			ifstream FILES("Автобус.txt");
			ofstream FILES1("file.txt", ios::app);
			while (getline(FILES, line)) {
				if ((line.find("Автобус №" + to_string(ind) + ".") != string::npos)) {
					getline(FILES, line);
					if (line.find("Тип: Городской") != string::npos) {
						while (getline(FILES, line1)) {
							if (line1.find("end") == string::npos) {
							}
							else {
								break;
							}
						}
					}
				}
				else {
					FILES1 << line << endl;
				}
			}
			FILES.close();
			FILES1.close();
			remove("Автобус.txt");
			rename("file.txt", "Автобус.txt");
			system("cls");
			cout << "Удаление произошло успешно" << endl;
			menuadmin_osnovnoe();
		}
		else {
			system("cls");
			cout << "Такого в таблице нету, попробуйте еще раз" << endl;
			vibordelete_bus();
		}
		break;
	}
	case 2: {
		system("cls");
		int ind;
		string line, line1, typeBUS;
		tablica_Suburd_bus();
		cout << "Выберите номер автобуса который хотите удалить: ";
		while (!(cin >> ind)) {
			cin.clear();
			if (cin.get() != '\n') {
				system("cls");
				cout << "Введите номер предложенный в таблиице!!!" << endl;
				tablica_Suburd_bus();
				cout << "Выберите номер автобуса который хотите удалить: ";

			}
		}
		bool exit = false;
		ifstream FILE("Автобус.txt");
		while (getline(FILE, typeBUS) && exit != true) {
			if ((typeBUS.find("Автобус №" + to_string(ind) + ".") != string::npos)) {
				getline(FILE, line);
				if ((line.find("Тип: Пригородный") != string::npos)) {
					while (getline(FILE, line1)) {
						if (line1.find("end") != string::npos) {
							break;
						}
					}
					exit = true;
				}
			}
		}
		FILE.close();
		if (exit == true) {
			ifstream FILES("Автобус.txt");
			ofstream FILES1("file.txt", ios::app);
			while (getline(FILES, line)) {
				if ((line.find("Автобус №" + to_string(ind) + ".") != string::npos)) {
					getline(FILES, line);
					if (line.find("Тип: Пригородный") != string::npos) {
						while (getline(FILES, line1)) {
							if (line1.find("end") == string::npos) {
							}
							else {
								break;
							}
						}
					}
				}
				else {
					FILES1 << line << endl;
				}
			}
			FILES.close();
			FILES1.close();
			remove("Автобус.txt");
			rename("file.txt", "Автобус.txt");
			system("cls");
			cout << "Удаление произошло успешно" << endl;
			menuadmin_osnovnoe();
		}
		else {
			system("cls");
			cout << "Такого в таблице нету, попробуйте еще раз" << endl;
			vibordelete_bus();
		}
		break;
	}
	case 3: {
		system("cls");
		int chislo;
		string stop, nameBUS, type, stop0, stop1, numBUS_proverka, stop_ydalenie;
		while (1) {
			tablica_city_bus();
			cout << "Введите номер автобуса: ";
			while (!(cin >> chislo)) {
				cin.clear();
				if (cin.get() != '\n') {
					system("cls");
					cout << "Неккоректный ввод" << endl;
					tablica_city_bus();
					cout << "Введите номер автобуса: ";
				}
			}
			int bus_proverka = 0;
			ifstream AVT("Автобус.txt");
			while (getline(AVT, numBUS_proverka)) {
				if(numBUS_proverka.find("Автобус №" + to_string(chislo) + ".")!=string::npos){
					bus_proverka = 1;
				}
			}
			if (bus_proverka == 1) {
				AVT.close();
				break;
			}
			else {
				AVT.close();
				system("cls");
				cout << "Такого автобуса нет в таблице, повторите ввод заново" << endl;
			}
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		while (1) {
			system("cls");
			tablica_STOPScity(chislo);
			while (1) {
				cout << "Введите автобусную остановку для удаления: ";
				getline(cin, stop);
				if (stop.find(" ") != string::npos) {
					system("cls");
					cout << "Введите без пробела, возвращаю вас в меню" << endl;
					vibordelete_bus();
				}
				string stop_proveerka;
				int proverka = 0;
				ifstream FILA("Автобус.txt");
				while (getline(FILA, stop_proveerka)) {
					if (stop_proveerka == stop) {
						proverka = 1;
						break;
					}
				}
				if (proverka == 1) {
					FILA.close();
					break;
				}
				else {
					FILA.close();
					system("cls");
					cout << "Такой остановки не существует, возвращаю вас обратно" << endl;
					vibordelete_bus();
				}
			}
			ifstream FILE("Автобус.txt");
			ofstream FILE1("temp.txt");
			while (getline(FILE, nameBUS)) {
				if (nameBUS.find("Автобус №" + to_string(chislo) + ".") != string::npos) {
					getline(FILE, type);
					if (type.find("Тип: Городской") != string::npos) {
						getline(FILE, stop0);
						if (stop0.find("Остановки:") != string::npos) {
							FILE1 << nameBUS << endl;
							FILE1 << type << endl;
							FILE1 << stop0 << endl;
							while (getline(FILE, stop1)) {
								if (stop1 == "end") {
									FILE1 << stop1 << endl;
									break;
								}
								if (stop1 == stop) {
									while (getline(FILE, stop_ydalenie)) {
										if ((stop_ydalenie.find("g") != string::npos) || (stop_ydalenie.find("m") != string::npos)) {
											break;
										}
									}
								}
								else {
									FILE1 << stop1 << endl;
								}
							}
						}
					}
				}
				else {
					FILE1 << nameBUS << endl;
				}
			}
			FILE.close();
			FILE1.close();
			remove("Автобус.txt");
			rename("temp.txt", "Автобус.txt");
			break;
		}
		system("cls");
		cout << "Удаление произошло успешно" << endl;
		menuadmin_osnovnoe();
		break;
	}
	case 4: {
		system("cls");
		int chislo;
		string stop, nameBUS, type, stop0, stop1, numBUS_proverka, stop_ydalenie;
		while (1) {
			tablica_Suburd_bus();
			cout << "Введите номер автобуса: ";
			while (!(cin >> chislo)) {
				cin.clear();
				if (cin.get() != '\n') {
					system("cls");
					cout << "Неккоректный ввод" << endl;
					tablica_Suburd_bus();
					cout << "Введите номер автобуса: ";
				}
			}
			int bus_proverka = 0;
			ifstream AVT("Автобус.txt");
			while (getline(AVT, numBUS_proverka)) {
				if (numBUS_proverka.find("Автобус №" + to_string(chislo) + ".") != string::npos) {
					bus_proverka = 1;
				}
			}
			if (bus_proverka == 1) {
				AVT.close();
				break;
			}
			else {
				AVT.close();
				system("cls");
				cout << "Такого автобуса нет в таблице, повторите ввод заново" << endl;
			}
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		while (1) {
			system("cls");
			tablica_STOPSsuburn(chislo);
			while (1) {
				cout << "Введите автобусную остановку для удаления: ";
				getline(cin, stop);
				if (stop.find(" ") != string::npos) {
					system("cls");
					cout << "Введите без пробела, возвращаю вас в меню" << endl;
					vibordelete_bus();
				}
				string stop_proveerka;
				int proverka = 0;
				ifstream FILA("Автобус.txt");
				while (getline(FILA, stop_proveerka)) {
					if (stop_proveerka == stop) {
						proverka = 1;
						break;
					}
				}
				if (proverka == 1) {
					FILA.close();
					break;
				}
				else {
					FILA.close();
					system("cls");
					cout << "Такой остановки не существует, возвращаю вас обратно" << endl;
					vibordelete_bus();
				}
			}
			ifstream FILE("Автобус.txt");
			ofstream FILE1("temp.txt");
			while (getline(FILE, nameBUS)) {
				if (nameBUS.find("Автобус №" + to_string(chislo) + ".") != string::npos) {
					getline(FILE, type);
					if (type.find("Тип: Пригородный") != string::npos) {
						getline(FILE, stop0);
						if (stop0.find("Остановки:") != string::npos) {
							FILE1 << nameBUS << endl;
							FILE1 << type << endl;
							FILE1 << stop0 << endl;
							while (getline(FILE, stop1)) {
								if (stop1 == "end") {
									FILE1 << stop1 << endl;
									break;
								}
								if (stop1 == stop) {
									while (getline(FILE, stop_ydalenie)) {
										if ((stop_ydalenie.find("g") != string::npos) || (stop_ydalenie.find("m") != string::npos)) {
											break;
										}
									}
								}
								else {
									FILE1 << stop1 << endl;
								}
							}
						}
					}
				}
				else {
					FILE1 << nameBUS << endl;
				}
			}
			FILE.close();
			FILE1.close();
			remove("Автобус.txt");
			rename("temp.txt", "Автобус.txt");
			break;
		}
		system("cls");
		cout << "Удаление произошло успешно" << endl;
		menuadmin_osnovnoe();
		break;
	}
	case 5: {
		system("cls");
		menuadmin_osnovnoe();
		break;
	}
	default: {
		system("cls");
		cout << "Неккоректный ввод" << endl;
		vibordelete_bus();
	}
	}
}
void vibor_dozapis() {
	int chislo;
	menutext_dozapis();
	while (!(cin >> chislo)) {
		cin.clear();
		if (cin.get() != '\n') {
			system("cls");
			cout << "Неккоректный ввод" << endl;
			menutext_dozapis();
		}
	}
	switch (chislo) {
	case 1: {
		system("cls");
		dozapis_city_bus();
		break;
	}
	case 2: {
		system("cls");
		dozapis_Suburn_bus();
		break;
	}
	case 3: {
		system("cls");
		menuadmin_osnovnoe();
		break;
	}
	default: {
		system("cls");
		cout << "Неккоректный ввод" << endl;
		menutext_dozapis();
		break;
	}
	}
}
void dozapis_city_bus() {
	int chislo = 0;
	tablica_city_bus();
	cout << "Выберите нужный вам автобус для дозаписи: ";
	while (!(cin >> chislo)) {
		cin.clear();
		if (cin.get() != '\n') {
			system("cls");
			cout << "Некорректный ввод" << endl;
			tablica_city_bus();
			cout << "Выберите нужный вам автобус для дозаписи: ";
		}
	}
	bool flag = false;
	string stroki;
	ifstream FILE("Автобус.txt");
	while (getline(FILE, stroki)) {
		if (stroki.find("Автобус №" + to_string(chislo) + ".") != string::npos) {
			flag = true;
		}
	}
	FILE.close();
	if (flag == true) {
		string numBUS, type, flag, stop0, slovo, time, stop1;
		ifstream FILE("Автобус.txt");
		ofstream FILA("temp.txt", ios::app);
		while (getline(FILE, numBUS)) {
			if (numBUS.find("Автобус №" + to_string(chislo) + ".")!=string::npos) {
				getline(FILE, type);
				if (type.find("Тип: Городской") != string::npos) {
					getline(FILE, stop0);
					if(stop0.find("Остановки:")!=string::npos){
						FILA << numBUS << endl;
						FILA << type << endl;
						FILA << stop0 << endl;
						while (getline(FILE, flag)) {
							if (flag.find("end") != string::npos) {
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								while (1) {
									system("cls");
									slovo = proverkaprobelstopsbussity(stop1);
									if (slovo == "stop") {
										break;
									}
									FILA << stop1 << endl;
									int chetcik = 0;
									while (1) {
										system("cls");
										slovo = priverkaprobeltime(time);
										if (slovo == "end") {
											if (chetcik == 0) {
												FILA << "m" << ' ' << "m" << ' ' << "m" << ' ' << "m" << ' ' << "m" << ' ' << "m" << ' ' << "m";
												FILA << endl;
											}
											else if (chetcik == 1) {
												FILA << "g" << ' ' << "g" << ' ' << "g" << ' ' << "g" << ' ' << "g" << ' ' << "g";
												FILA << endl;
											}
											else if (chetcik == 2) {
												FILA << "g" << ' ' << "g" << ' ' << "g" << ' ' << "g" << ' ' << "g";
												FILA << endl;
											}
											else if (chetcik == 3) {
												FILA << "g" << ' ' << "g" << ' ' << "g" << ' ' << "g";
												FILA << endl;
											}
											else if (chetcik == 4) {
												FILA << "g" << ' ' << "g" << ' ' << "g";
												FILA << endl;
											}
											else if (chetcik == 5) {
												FILA << "g" << ' ' << "g";
												FILA << endl;
											}
											else if (chetcik == 6) {
												FILA << "g";
												FILA << endl;
											}
											break;
										}
										chetcik++;
										if (chetcik == 7) {
											chetcik = 0;
											FILA << time << ";" << ' ';
											FILA << endl;
										}
										else {
											FILA << time << ";" << ' ';
										}
									}
								}
								FILA << "end" << endl;
								break;
							}
							else {
								FILA << flag << endl;
							}
						}
					}
					
				}
			}
			else {
				FILA << numBUS << endl;
			}
		}
		FILA.close();
		FILE.close();
		remove("Автобус.txt");
		rename("temp.txt", "Автобус.txt");
		system("cls");
		cout << "Добавление произошло успешно" << endl;
		menuadmin_osnovnoe();
	}
	else {
		system("cls");
		cout << "Такого автобуса нет в таблице, введите так как в таблице" << endl;
		dozapis_city_bus();
	}
}
void dozapis_Suburn_bus() {
	int chislo;
	tablica_Suburd_bus();
	cout << "Выберите нужный вам автобус для дозаписи: ";
	while (!(cin >> chislo)) {
		cin.clear();
		if (cin.get() != '\n') {
			system("cls");
			cout << "Неккоректный ввод" << endl;
			tablica_Suburd_bus();
			cout << "Выберите нужный вам автобус для дозаписи: ";
		}
	}
	bool flag = false;
	string stroki;
	ifstream FILE("Автобус.txt");
	while (getline(FILE, stroki)) {
		if (stroki.find("Автобус №" + to_string(chislo) + ".") != string::npos) {
			flag = true;
		}
	}
	FILE.close();
	if (flag == true) {
		string numBUS, type, flag, stop0, slovo, time, stop1;
		ifstream FILE("Автобус.txt");
		ofstream FILA("temp.txt", ios::app);
		while (getline(FILE, numBUS)) {
			if (numBUS.find("Автобус №" + to_string(chislo) + ".") != string::npos) {
				getline(FILE, type);
				if (type.find("Тип: Пригородный") != string::npos) {
					getline(FILE, stop0);
					if (stop0.find("Остановки:") != string::npos) {
						FILA << numBUS << endl;
						FILA << type << endl;
						FILA << stop0 << endl;
						while (getline(FILE, flag)) {
							if (flag.find("end") != string::npos) {
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								while (1) {
									system("cls");
									slovo = proverkaprobelstopsbussity(stop1);
									if (slovo == "stop") {
										break;
									}
									FILA << stop1 << endl;
									int chetcik = 0;
									while (1) {
										system("cls");
										slovo = priverkaprobeltime(time);
										if (slovo == "end") {
											if (chetcik == 0) {
												FILA << "m" << ' ' << "m" << ' ' << "m" << ' ' << "m" << ' ' << "m" << ' ' << "m" << ' ' << "m";
												FILA << endl;
											}
											else if (chetcik == 1) {
												FILA << "g" << ' ' << "g" << ' ' << "g" << ' ' << "g" << ' ' << "g" << ' ' << "g";
												FILA << endl;
											}
											else if (chetcik == 2) {
												FILA << "g" << ' ' << "g" << ' ' << "g" << ' ' << "g" << ' ' << "g";
												FILA << endl;
											}
											else if (chetcik == 3) {
												FILA << "g" << ' ' << "g" << ' ' << "g" << ' ' << "g";
												FILA << endl;
											}
											else if (chetcik == 4) {
												FILA << "g" << ' ' << "g" << ' ' << "g";
												FILA << endl;
											}
											else if (chetcik == 5) {
												FILA << "g" << ' ' << "g";
												FILA << endl;
											}
											else if (chetcik == 6) {
												FILA << "g";
												FILA << endl;
											}
											break;
										}
										chetcik++;
										if (chetcik == 7) {
											chetcik = 0;
											FILA << time << ";" << ' ';
											FILA << endl;
										}
										else {
											FILA << time << ";" << ' ';
										}
									}
								}
								FILA << "end" << endl;
								break;
							}
							else {
								FILA << flag << endl;
							}
						}
					}

				}
			}
			else {
				FILA << numBUS << endl;
			}
		}
		FILA.close();
		FILE.close();
		remove("Автобус.txt");
		rename("temp.txt", "Автобус.txt");
		system("cls");
		cout << "Добавление произошло успешно" << endl;
		menuadmin_osnovnoe();
	}
	else {
		system("cls");
		cout << "Такого автобуса нет в таблице, введите так как в таблице" << endl;
		dozapis_Suburn_bus();
	}
}
void individyal_zadanie_vibor(int& chislo) {
	int chislo1;
	text_individyal_zadanie_vibor();
	while (!(cin >> chislo1)) {
		cin.clear();
		if (cin.get() != '\n') {
			system("cls");
			cout << "Неккоректный ввод" << endl;
			text_individyal_zadanie_vibor();
		}
	}
	switch (chislo1) {
	case 1: {
		system("cls");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		individyal_zadanie_cityBUS(chislo);
		break;
	}
	case 2: {
		system("cls");
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		individyal_zadanie_SuburnBUS(chislo);
		break;
	}
	case 3: {
		if (chislo == 1) {
			system("cls");
			menuadmin_osnovnoe();
			break;
		}
		else {
			system("cls");
			menupolzovatel_osnovnoe();
			break;
		}
	}
	default: {
		system("cls");
		cout << "Неккоректный ввод" << endl;
		individyal_zadanie_vibor(chislo);
	}
	}
}
void individyal_zadanie_cityBUS(int& chislo) {
	string stop, stroki;
	while (1) {
		int ind1 = 0, ind2 = 0;
		tablica_STOPSindividyal_cityBUS();
		cout << "Ввведите остановку для прибытия: ";
		getline(cin, stop);
		if (stop.find(' ') != string::npos) {
			system("cls");
			cout << "Введите остановку без пробела!" << endl;
		}
		else {
			ind1 = 1;
		}
		if (stop.empty() == true) {
			system("cls");
			cout << "Остановка не должна содержать ничего!" << endl;
		}
		else {
			ind2 = 1;
		}
		if (ind1 == 1 && ind2 == 1) {
			break;
		}
	}
	bool flag = false;
	ifstream FILE("Автобус.txt");
	while (getline(FILE, stroki)) {
		if (stroki.find(stop) != string::npos) {
			flag = true;
			break;
		}
	}
	FILE.close();
	if (flag == true) {
		system("cls");
		string time1, time2;
		int number1, number;
		while (1) {
			while (1) {
				while (1) {
					cout << "Введите начало первого промежутка времени: ";
					getline(cin, time1);
					int ind1 = 0, ind2 = 0, ind3 = 0;
					if (time1.find(' ') != string::npos) {
						system("cls");
						cout << "Введите время без пробела!" << endl;
					}
					else {
						ind1 = 1;
					}
					if (time1.empty() == true) {
						system("cls");
						cout << "Время не должно содержать ничего!" << endl;
					}
					else {
						ind2 = 1;
					}
					istringstream iss(time1);
					iss >> number;
					if (number > 0) {
						ind3 = 1;
					}
					if ((ind1 == 1 && ind2 == 1) && ind3 == 1) {
						break;
					}
					else {
						system("cls");
					}
				}
				while (1) {
					cout << "Введите конец последнего промежутка времени: ";
					getline(cin, time2);
					int ind1 = 0, ind2 = 0, ind3 = 0;
					if (time2.find(' ') != string::npos) {
						system("cls");
						cout << "Введите время без пробела!" << endl;
					}
					else {
						ind1 = 1;
					}
					if (time2.empty() == true) {
						system("cls");
						cout << "Время не должно содержать ничего!" << endl;
					}
					else {
						ind2 = 1;
					}
					istringstream iss1(time2);
					iss1 >> number1;
					if (number1 > 0) {
						ind3 = 1;
					}
					if ((ind1 == 1 && ind2 == 1) && ind3 == 1) {
						break;
					}
					else {
						system("cls");
					}
				}
				if (number < number1) {
					break;
				}
				else {
					system("cls");
					cout << "Неккоректный ввод" << endl;
				}
			}
			bool flag1 = false;
			string numBUS, type, stop0, stop1, stroki;
			ifstream FILE("Автобус.txt");
			while (getline(FILE, numBUS)) {
				if (numBUS.find("Автобус №") != string::npos) {
					getline(FILE, type);
					if (type.find("Тип: Городской") != string::npos) {
						getline(FILE, stop0);
						if (stop0.find("Остановки:") != string::npos) {
							getline(FILE, stop1);
							if (stop1.find(stop) != string::npos) {
								while (getline(FILE, stroki)) {
									if (stroki == "end")
										break;
									stringstream ss(stroki);
									string hour_str;
									getline(ss, hour_str, ';');
									int hour = stoi(hour_str);
									if (hour >= stoi(time1) && hour <= stoi(time2)) {
										flag1 = true;
										break;
									}
								}
							}
						}
					}
				}
			}
			FILE.close();
			if (time1 == time2 || flag1 == false) {
				system("cls");
				cout << "Неккоректный ввод" << endl;
			}
			else{
				system("cls");
				cout << "____ Все автобусы которые прибывают к остановке: " << stop << " за промежуток времени: " << time1 << " - " << time2 << " _____" << endl;
				string numBUS, type, stop0, stop1, stroki;
				ifstream FILE("Автобус.txt");
				while (getline(FILE, numBUS)) {
					if (numBUS.find("Автобус №") != string::npos) {
						getline(FILE, type);
						if (type.find("Тип: Городской") != string::npos) {
							getline(FILE, stop0);
							if (stop0.find("Остановки:") != string::npos) {
								getline(FILE, stop1);
								if (stop1.find(stop) != string::npos) {
									while (getline(FILE, stroki)) {
										if (stroki == "end")
											break;
										stringstream ss(stroki);
										string hour_str;
										getline(ss, hour_str, ';');
										int hour = stoi(hour_str);
										if (hour >= stoi(time1) && hour <= stoi(time2)) {
											cout << numBUS << endl;
											break;
										}
									}
								}
							}
						}
					}
				}
				cout << "________________________________________________________________________________" << endl;
				FILE.close();
				system("pause");
				system("cls");
				if (chislo == 1) {
					menuadmin_osnovnoe();
				}
				else {
					menupolzovatel_osnovnoe();
				}
			}
		}
	}
	else {
		system("cls");
		cout << "Нет такой остановки" << endl;
		individyal_zadanie_vibor(chislo);
	}
}
void individyal_zadanie_SuburnBUS(int& chislo) {
	string stop, stroki;
	while (1) {
		int ind1 = 0, ind2 = 0;
		tablica_STOPSindividyal_SuburnBUS();
		cout << "Ввведите остановку для прибытия: ";
		getline(cin, stop);
		if (stop.find(' ') != string::npos) {
			system("cls");
			cout << "Введите остановку без пробела!" << endl;
		}
		else {
			ind1 = 1;
		}
		if (stop.empty() == true) {
			system("cls");
			cout << "Остановка не должна содержать ничего!" << endl;
		}
		else {
			ind2 = 1;
		}
		if (ind1 == 1 && ind2 == 1) {
			break;
		}
	}
	bool flag = false;
	ifstream FILE("Автобус.txt");
	while (getline(FILE, stroki)) {
		if (stroki.find(stop) != string::npos) {
			flag = true;
			break;
		}
	}
	FILE.close();
	if (flag == true) {
		system("cls");
		string time1, time2;
		int number1, number;
		while (1) {
			while (1) {
				while (1) {
					cout << "Введите начало первого промежутка времени: ";
					getline(cin, time1);
					int ind1 = 0, ind2 = 0, ind3 = 0;
					if (time1.find(' ') != string::npos) {
						system("cls");
						cout << "Введите время без пробела!" << endl;
					}
					else {
						ind1 = 1;
					}
					if (time1.empty() == true) {
						system("cls");
						cout << "Время не должно содержать ничего!" << endl;
					}
					else {
						ind2 = 1;
					}
					istringstream iss(time1);
					iss >> number;
					if (number > 0) {
						ind3 = 1;
					}
					if ((ind1 == 1 && ind2 == 1) && ind3 == 1) {
						break;
					}
					else {
						system("cls");
					}
				}
				while (1) {
					cout << "Введите конец последнего промежутка времени: ";
					getline(cin, time2);
					int ind1 = 0, ind2 = 0, ind3 = 0;
					if (time2.find(' ') != string::npos) {
						system("cls");
						cout << "Введите время без пробела!" << endl;
					}
					else {
						ind1 = 1;
					}
					if (time2.empty() == true) {
						system("cls");
						cout << "Время не должно содержать ничего!" << endl;
					}
					else {
						ind2 = 1;
					}
					istringstream iss1(time2);
					iss1 >> number1;
					if (number1 > 0) {
						ind3 = 1;
					}
					if ((ind1 == 1 && ind2 == 1) && ind3 == 1) {
						break;
					}
					else {
						system("cls");
					}
				}
				if (number < number1) {
					break;
				}
				else {
					system("cls");
					cout << "Неккоректный ввод" << endl;
				}
			}
			bool flag1 = false;
			string numBUS, type, stop0, stop1, stroki;
			ifstream FILE("Автобус.txt");
			while (getline(FILE, numBUS)) {
				if (numBUS.find("Автобус №") != string::npos) {
					getline(FILE, type);
					if (type.find("Тип: Пригородный") != string::npos) {
						getline(FILE, stop0);
						if (stop0.find("Остановки:") != string::npos) {
							getline(FILE, stop1);
							if (stop1.find(stop) != string::npos) {
								while (getline(FILE, stroki)) {
									if (stroki == "end")
										break;
									stringstream ss(stroki);
									string hour_str;
									getline(ss, hour_str, ';');
									int hour = stoi(hour_str);
									if (hour >= stoi(time1) && hour <= stoi(time2)) {
										flag1 = true;
										break;
									}
								}
							}
						}
					}
				}
			}
			FILE.close();
			if (time1 == time2 || flag1 == false) {
				system("cls");
				cout << "Неккоректный ввод" << endl;
			}
			else {
				system("cls");
				cout << "____ Все автобусы которые прибывают к остановке: " << stop << " за промежуток времени: " << time1 << " - " << time2 << " _____" << endl;
				string numBUS, type, stop0, stop1, stroki;
				ifstream FILE("Автобус.txt");
				while (getline(FILE, numBUS)) {
					if (numBUS.find("Автобус №") != string::npos) {
						getline(FILE, type);
						if (type.find("Тип: Пригородный") != string::npos) {
							getline(FILE, stop0);
							if (stop0.find("Остановки:") != string::npos) {
								getline(FILE, stop1);
								if (stop1.find(stop) != string::npos) {
									while (getline(FILE, stroki)) {
										if (stroki == "end")
											break;
										stringstream ss(stroki);
										string hour_str;
										getline(ss, hour_str, ';');
										int hour = stoi(hour_str);
										if (hour >= stoi(time1) && hour <= stoi(time2)) {
											cout << numBUS << endl;
											break;
										}
									}
								}
							}
						}
					}
				}
				cout << "________________________________________________________________________________" << endl;
				FILE.close();
				system("pause");
				system("cls");
				if (chislo == 1) {
					menuadmin_osnovnoe();
				}
				else {
					menupolzovatel_osnovnoe();
				}
			}
		}
	}
	else {
		system("cls");
		cout << "Нет такой остановки" << endl;
		individyal_zadanie_vibor(chislo);
	}
}
void sortVIBOR(int& chislo) {
	int ch;
	text_Sort();
	while (!(cin >> ch)) {
		cin.clear();
		if (cin.get() != '\n') {
			system("cls");
			cout << "Неккоректный ввод" << endl;
			text_Sort();
		}
	}
	switch (ch) {
	case 1: {
		system("cls");
		sortBUS_city(chislo);
		break;
	}
	case 2: {
		system("cls");
		sortSuburn(chislo);
		break;
	}
	case 3: {
		system("cls");
		if (chislo == 1) {
			menuadmin_osnovnoe();
		}
		else {
			menupolzovatel_osnovnoe();
		}
		break;
	}
	default: {
		system("cls");
		cout << "Неккоректный ввод" << endl;
		sortVIBOR(chislo);
	}
	}
}
void sortBUS_city(int& chislo) {
	int ch;
	text_Sortcity_BUS();
	while (!(cin >> ch)) {
		cin.clear();
		if (cin.get() != '\n') {
			system("cls");
			cout << "Неккоректный ввод" << endl;
			text_Sortcity_BUS();
		}
	}
	switch (ch) {
	case 1: {
		string numBUS, type;
		vector<int> number;
		ifstream FILE("Автобус.txt");
		while (getline(FILE, numBUS)) {
			if (numBUS.find("Автобус №") != string::npos) {
				getline(FILE, type);
				if (type.find("Тип: Городской") != string::npos) {
					if (!numBUS.empty() && numBUS.back() == '.') {
						numBUS.pop_back();
					}
					size_t startPos = numBUS.find_first_not_of("0123456789", numBUS.find("№"));
					if (startPos != string::npos) {
						string numberStr = numBUS.substr(numBUS.find("№") + 1, startPos - numBUS.find("№") - 1);
						int number1 = stoi(numberStr);
						number.push_back(number1);
					}
				}
			}
		}
		FILE.close();
		sort(number.begin(), number.end());
		system("cls");
		cout << "_______________________  Отсортированные городские автобусы по возрастанию  _________________________\n\n";
		for (size_t i = 0; i < number.size(); ++i) {
			cout << "Автобус №" << number[i] << endl;
		}
		cout << "----------------------------------------------------------------------------------\n\n";
		number.clear();
		number.shrink_to_fit();
		system("pause");
		system("cls");
		if (chislo == 1) {
			menuadmin_osnovnoe();
		}
		else {
			menupolzovatel_osnovnoe();
		}
		break;
	}
	case 2: {
			  string numBUS, type;
			  vector<int> number;
			  ifstream FILE("Автобус.txt");
			  while (getline(FILE, numBUS)) {
				  if (numBUS.find("Автобус №") != string::npos) {
					  getline(FILE, type);
					  if (type.find("Тип: Городской") != string::npos) {
						  if (!numBUS.empty() && numBUS.back() == '.') {
							  numBUS.pop_back();
						  }
						  size_t startPos = numBUS.find_first_not_of("0123456789", numBUS.find("№"));
						  if (startPos != string::npos) {
							  string numberStr = numBUS.substr(numBUS.find("№") + 1, startPos - numBUS.find("№") - 1);
							  int number1 = stoi(numberStr);
							  number.push_back(number1);
						  }
					  }
				  }
			  }
			  FILE.close();
			  sort(number.rbegin(), number.rend());
			  system("cls");
			  cout << "_______________________  Отсортированные городские автобусы по убыванию  _________________________\n\n";
			  for (size_t i = 0; i < number.size(); ++i) {
				  cout << "Автобус №" << number[i] << endl;
			  }
			  cout << "----------------------------------------------------------------------------------\n\n";
			  number.clear();
			  number.shrink_to_fit();
			  system("pause");
			  system("cls");
			  if (chislo == 1) {
				  menuadmin_osnovnoe();
			  }
			  else {
				  menupolzovatel_osnovnoe();
			  }
			  break;
	}
	case 3: {
		system("cls");
		sortVIBOR(chislo);
		break;
	}
	default: {
		system("cls");
		cout << "Неккоректный ввод" << endl;
		sortBUS_city(chislo);
		break;
	}
	}
}
void sortSuburn(int& chislo) {
	int ch;
	text_SortSuburn_Bus();
	while (!(cin >> ch)) {
		cin.clear();
		if (cin.get() != '\n') {
			system("cls");
			cout << "Неккоректный ввод" << endl;
			text_SortSuburn_Bus();
		}
	}
	switch (ch) {
	case 1: {
		string numBUS, type;
		vector<int> number;
		ifstream FILE("Автобус.txt");
		while (getline(FILE, numBUS)) {
			if (numBUS.find("Автобус №") != string::npos) {
				getline(FILE, type);
				if (type.find("Тип: Пригородный") != string::npos) {
					if (!numBUS.empty() && numBUS.back() == '.') {
						numBUS.pop_back();
					}
					size_t startPos = numBUS.find_first_not_of("0123456789", numBUS.find("№"));
					if (startPos != string::npos) {
						string numberStr = numBUS.substr(numBUS.find("№") + 1, startPos - numBUS.find("№") - 1);
						int number1 = stoi(numberStr);
						number.push_back(number1);
					}
				}
			}
		}
		FILE.close();
		sort(number.begin(), number.end());
		system("cls");
		cout << "_______________________  Отсортированные пригородные автобусы по возрастанию  _________________________\n\n";
		for (size_t i = 0; i < number.size(); ++i) {
			cout << "Автобус №" << number[i] << endl;
		}
		cout << "----------------------------------------------------------------------------------\n\n";
		number.clear();
		number.shrink_to_fit();
		system("pause");
		system("cls");
		if (chislo == 1) {
			menuadmin_osnovnoe();
		}
		else {
			menupolzovatel_osnovnoe();
		}
		break;
	}
	case 2: {
		string numBUS, type;
		vector<int> number;
		ifstream FILE("Автобус.txt");
		while (getline(FILE, numBUS)) {
			if (numBUS.find("Автобус №") != string::npos) {
				getline(FILE, type);
				if (type.find("Тип: Пригородный") != string::npos) {
					if (!numBUS.empty() && numBUS.back() == '.') {
						numBUS.pop_back();
					}
					size_t startPos = numBUS.find_first_not_of("0123456789", numBUS.find("№"));
					if (startPos != string::npos) {
						string numberStr = numBUS.substr(numBUS.find("№") + 1, startPos - numBUS.find("№") - 1);
						int number1 = stoi(numberStr);
						number.push_back(number1);
					}
				}
			}
		}
		FILE.close();
		sort(number.rbegin(), number.rend());
		system("cls");
		cout << "_______________________  Отсортированные приородные автобусы по убыванию  _________________________\n\n";
		for (size_t i = 0; i < number.size(); ++i) {
			cout << "Автобус №" << number[i] << endl;
		}
		cout << "----------------------------------------------------------------------------------\n\n";
		number.clear();
		number.shrink_to_fit();
		system("pause");
		system("cls");
		if (chislo == 1) {
			menuadmin_osnovnoe();
		}
		else {
			menupolzovatel_osnovnoe();
		}
		break;
	}
	case 3: {
		system("cls");
		sortVIBOR(chislo);
		break;
	}
	default: {
		system("cls");
		cout << "Неккоректный ввод" << endl;
		sortSuburn(chislo);
		break;
	}
	}
}
void tablica_city_bus() {
	string line, nameBUS, line1;
	ifstream FILE("Автобус.txt");
	cout << "_______________________  Доступные городские автобусы  _______________\n\n";
	while (getline(FILE, nameBUS)) {
		if (nameBUS.find("Автобус №") != string::npos) {
			getline(FILE, line);
			if (line.find("Тип: Городской") != string::npos) {
				while (getline(FILE, line1)) {
					if (line1.find("end") != string::npos) {
						break;
					}
				}
				cout << nameBUS << endl;
			}
		}
	}
	cout << "----------------------------------------------------------------------\n\n";
	FILE.close();
}
void tablica_Suburd_bus() {
	string line, nameBUS, line1;
	ifstream FILE("Автобус.txt");
	cout << "_______________________  Доступные пригородные автобусы  _______________\n\n";
	while (getline(FILE, nameBUS)) {
		if (nameBUS.find("Автобус №") != string::npos) {
			getline(FILE, line);
			if (line.find("Тип: Пригородный") != string::npos) {
				while (getline(FILE, line1)) {
					if (line1.find("end") != string::npos) {
						break;
					}
				}
				cout << nameBUS << endl;
			}
		}
	}
	cout << "----------------------------------------------------------------------\n\n";
	FILE.close();
}
void tablica_STOPScity(int &chislo) {
	ifstream file("Автобус.txt");
	string nameBUS, stop0, stop1, type, time;
	vector<string> stops;
	cout << "_______________________  Доступные автобусные остановки  _________________________\n\n";
	while (getline(file, nameBUS)) {
		if ((nameBUS.find("Автобус №" + to_string(chislo) + ".") != string::npos)) {
			getline(file, type);
			if ((type.find("Тип: Городской") != string::npos)) {
				getline(file, stop0);
				if (stop0.find("Остановки:") != string::npos) {
					while (file >> stop1) {
						if (stop1 == "end") {
							break;
						}
						if (find(stops.begin(), stops.end(), stop1) == stops.end()) {
							stops.push_back(stop1);
							cout << stop1 << endl;
						}
						while (getline(file, time)) {
							if ((time.find("g") != string::npos)||(time.find("m") != string::npos)) {
								break;
							}
						}
					}
				}
			}
		}
	}
	cout << "----------------------------------------------------------------------------------\n\n";
	stops.clear();
	stops.shrink_to_fit();
	file.close();
}
void tablica_STOPSsuburn(int& chislo) {
	ifstream file("Автобус.txt");
	string nameBUS, stop0, stop1, type, time;
	vector<string> stops;
	cout << "_______________________  Доступные автобусные остановки  _________________________\n\n";
	while (getline(file, nameBUS)) {
		if ((nameBUS.find("Автобус №" + to_string(chislo) + ".") != string::npos)) {
			getline(file, type);
			if ((type.find("Тип: Пригородный") != string::npos)) {
				getline(file, stop0);
				if (stop0.find("Остановки:") != string::npos) {
					while (file >> stop1) {
						if (stop1 == "end") {
							break;
						}
						if (find(stops.begin(), stops.end(), stop1) == stops.end()) {
							stops.push_back(stop1);
							cout << stop1 << endl;
						}
						while (getline(file, time)) {
							if ((time.find("g") != string::npos) || (time.find("m") != string::npos)) {
								break;
							}
						}
					}
				}
			}
		}
	}
	cout << "----------------------------------------------------------------------------------\n\n";
	stops.clear();
	stops.shrink_to_fit();
	file.close();
}
void tablica_STOPSindividyal_cityBUS() {
	ifstream file("Автобус.txt");
	string nameBUS, stop0, stop1, type, time;
	vector<string> stops;
	cout << "_______________________  Доступные автобусные остановки  _________________________\n\n";
	while (getline(file, nameBUS)) {
		if ((nameBUS.find("Автобус №") != string::npos)) {
			getline(file, type);
			if ((type.find("Тип: Городской") != string::npos)) {
				getline(file, stop0);
				if (stop0.find("Остановки:") != string::npos) {
					while (file >> stop1) {
						if (stop1 == "end") {
							break;
						}
						if (find(stops.begin(), stops.end(), stop1) == stops.end()) {
							stops.push_back(stop1);
							cout << stop1 << endl;
						}
						while (getline(file, time)) {
							if ((time.find("g") != string::npos) || (time.find("m") != string::npos)) {
								break;
							}
						}
					}
				}
			}
		}
	}
	cout << "----------------------------------------------------------------------------------\n\n";
	stops.clear();
	stops.shrink_to_fit();
	file.close();
}
void tablica_STOPSindividyal_SuburnBUS() {
	ifstream file("Автобус.txt");
	string nameBUS, stop0, stop1, type, time;
	vector<string> stops;
	cout << "_______________________  Доступные автобусные остановки  _________________________\n\n";
	while (getline(file, nameBUS)) {
		if ((nameBUS.find("Автобус №") != string::npos)) {
			getline(file, type);
			if ((type.find("Тип: Пригородный") != string::npos)) {
				getline(file, stop0);
				if (stop0.find("Остановки:") != string::npos) {
					while (file >> stop1) {
						if (stop1 == "end") {
							break;
						}
						if (find(stops.begin(), stops.end(), stop1) == stops.end()) {
							stops.push_back(stop1);
							cout << stop1 << endl;
						}
						while (getline(file, time)) {
							if ((time.find("g") != string::npos) || (time.find("m") != string::npos)) {
								break;
							}
						}
					}
				}
			}
		}
	}
	cout << "----------------------------------------------------------------------------------\n\n";
	stops.clear();
	stops.shrink_to_fit();
	file.close();
}
