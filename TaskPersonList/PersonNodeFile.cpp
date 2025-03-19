#include "PersonNodeFile.h"


//=====конструкторы структуры Marks=========
Marks::Marks( int mark_Histori, int mark_Philosophy, int mark_mathAnalysis, int mark_Programming, int mark_AlgoStructurDate, float itog)
{	 
	this->mark_Histori = mark_Histori;
	this->mark_Philosophy = mark_Philosophy;
	this->mark_mathAnalysis = mark_mathAnalysis;
	this->mark_Programming=mark_Programming;
	this->mark_AlgoStructurDate=mark_AlgoStructurDate;
	this->itog=itog;	 
}

Marks::Marks()
{	 
	this->mark_Histori = 0;
	this->mark_Philosophy = 0;
	this->mark_mathAnalysis = 0;
	this->mark_Programming = 0;
	this->mark_AlgoStructurDate = 0;
	this->itog = 0;	
}

//деструктор
Marks::~Marks()
{
}


//--функция выводит ОЦЕНКИ. Она сработает при вызове:   cout << markss  
ostream& operator<<(ostream& out, Marks& p)
{
	for (auto& n : p.v) {
		out << "\t" << n;
		out.width(3);
	}
	 out << "\t"<< p.averageMarks(); //оценка средне-арифметическая	
	return out;
}


////////////////////////////////////////////////////////
// 
//===конструкторы класса PersonNodeFile===========

PersonNodeFile::PersonNodeFile(  char f,  char s,  char th, int b, int co, int gr, Marks ma) : first_name{f}, second_name{s}, therd_name{th}, bearthDay{b}, cours{co}, group_number{gr}, markss{ma}
{
}



PersonNodeFile::PersonNodeFile()
{	
	*this->first_name = 0; //Эквивалент инструкции first_name[0]='0';
	*this->second_name = 0;//Эквивалент инструкции second_name[0]='0';
	*this->therd_name = 0; //Эквивалент инструкции therd_name[0]='0';
	this->bearthDay = 0;
	this->cours = 0;
	this->group_number = 0;
	this->markss;
	this->count = 0;
}
//деструктор
PersonNodeFile::~PersonNodeFile(){}


//========функции===============================


//-ввод исходных данных через консоль-----
void PersonNodeFile::getdata()
{
	count = 1;
	cout << endl;
	cout << endl;
	cout << "Введите фамилию: "; cin >> first_name;
	cout << "Введите имя: "; cin >> second_name;
	cout << "Введите отчество: "; cin >> therd_name;
	cout << "введите ГОД рождения: "; cin >> bearthDay;//введение форматированной даты рождения
	cout << "Введите номер группы:"; cin >> group_number;
	addCours();  //введение курса с проверкой на корректность ввода!	
	addMarks();  //добавляем оценки
	cout << endl;
}
 
//--- просмотр данных в консоли------
void PersonNodeFile::putdata()
{
	cout << endl;
	cout << first_name << " ";
	cout << second_name << " ";
	cout << therd_name << " ";
	cout << "\nкурс: " << cours;
	cout << "ГОД рождения: " << bearthDay;
	cout << "группа:" << group_number;
	cout << "\nОЦЕНКИ по 5-ти предметам:\n";
	cout << markss;
	cout << endl;
}

//////////////////////////////////////////
//----ввод номера курса: cours --------------
void PersonNodeFile::addCours()
{
	cout << "Введите ваш курс: "; cin >> cours;
	if (cours > 4 || cours < 0) {
		count++;
		cout << "Неверно указан курс. " << endl;
		cout << "Пожалуйста, введите число от 1 до 4-х " << endl;
		if (count == 4) {
			cout << "<блииин... ну ты БОЛВАН ....\n";
			cout << "ИИ исключает тебя из института!";
			return;
		}
		addCours(); //рекурсия (пока Б... не введёт верно курс)
	}
	count = 1;
}

   //--получить номер Курса---------------
int PersonNodeFile::getCours()
{
	return this->cours;
}


//////////////////////////////////////////////
 

//-- ввод группы---
void PersonNodeFile::addGroup(int g)
{
	this->group_number = g;
}

//-- получить номер группы---
int PersonNodeFile::getGroup()
{
	return this->group_number;
}



/////////////////////////////////////////
//--ввод оценок--------
void PersonNodeFile::addMarks()
{
	markss.v.clear();
	cout << "история: "; cin >> markss.mark_Histori;
	markss.v.push_back(markss.mark_Histori);				 //<----vector-------
	cout << "философия: "; cin >> markss.mark_Philosophy;
	markss.v.push_back(markss.mark_Philosophy);				 //<----vector-------
	cout << "мат-анализ: "; cin >> markss.mark_mathAnalysis;
	markss.v.push_back(markss.mark_mathAnalysis);			 //<----vector-------
	cout << "программирование: "; cin >> markss.mark_Programming;
	markss.v.push_back(markss.mark_Programming);			  //<-----vector------
	cout << "алгосы: "; cin >> markss.mark_AlgoStructurDate;
	markss.v.push_back(markss.mark_AlgoStructurDate);	      //<-----vector------
	cout << "средняя.арифм.оценка: " << markss.averageMarks();	
}

//--получить среднеарифметическую оценку-----
  
float PersonNodeFile::getMarks()
{		
	return markss.averageMarks();
}

//-расчёт средне арифметической оценки студента---
float Marks::averageMarks()
{
	int i = 0;
	float sum = 0;

	for (auto& n : v) {
		sum = sum + n;
		++i;
	}
	itog = (float)sum / i;
	return itog;
}


//====файлы===========================

//--для создания файла для каждой группы (в самом начале) ----
ofstream PersonNodeFile::funcFile(string path) //имя файла
{
	ofstream outfile(path, ofstream::app); //открыли поток с влозможностью дозаписи 
	return outfile;
}



//--запись данных в файл-----
 void PersonNodeFile::write(ofstream& os)
{	
	os << endl;
	os.width(3);
	os << "\t" << first_name;
	os.width(7);
	os << "\t" << second_name;
	os.width(7);
	os << "\t" << therd_name << "\t";
	os.width(5);
	os << getCours();
	os.width(5);
	os << "\t" << bearthDay;
	os.width(5);
	os << "\t" << group_number;
	os.width(3);
	os << markss;
	os << endl;
}

 //----считываем данные (как char)  из файла в консоль---------
 void PersonNodeFile::readCh(string path, int crs)
 {
	 fstream readMyfily;  //открыла поток
	 readMyfily.open(path);

	 //добавили проверку наличия файла (так положено!)
	 if (!readMyfily) {
		 cerr << "Невозможно открыть входной файл\n"; exit(1);
	 }

	 cout << "\n-------------------------------------------";
	 cout << "\n"<<"  студенты: " << crs << "-го курса";
	 cout << "\n-------------------------------------------" << endl;

	 int obj = 0; //для подсчёта байтов (символы(и буквы)+пропуски) в файле
	 char ch;

	 while (readMyfily.get(ch)) {//	get() для чтения по одному символу(по буквам)	
		 //применение функции get() на выходе сохраняет тип int

		 cout.put(ch); //вывод на терминал 			
		 if (ch == 'n') { //если встречается перенос строки то ???
			 readMyfily.put(' '); //размести пробел
			 readMyfily << obj;  //впиши внутрь файла результат obj
			 readMyfily.put(' '); //и размести пробел
		 }
		 obj++;
	 }
	 //readMyfily <<endl << obj << endl;
	 readMyfily.close();//закрыла поток
 }

 
