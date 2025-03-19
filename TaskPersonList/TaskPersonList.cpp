#include "PersonNodeFile.h"  //занесение данных в файл
#include "DataFileAnalis.h"  //обработка данных
#include "PersonListSort.h"  //сортировка файла по имени

/*
  ЗАДАЧА
Дан список студентов.
  -фамилию, имя, отчество,
  -год рождения,
  -курс,
  -номер группы,
  -оценки по пяти предметам.

  ТРЕБУЕТСЯ
1) Упорядочите студентов по курсу, причем студенты одного курса расположить в алфавитном порядке.
2) Найдите средний балл каждого курса по всем предметам.
3) Определите самого старшего студента и самого младшего студента.
4) Для каждого курса найдите лучшего с точки зрения успеваемости студента.
*/




/////////////////////////////////
// для записи данных студента в файл через консоль
void InStudentFile() {
	PersonNodeFile study;
	int numder;
	cout << "какое количество студентов хотите ввести в программу?\n";
	cin >> numder;

	ofstream outfile; //объявила поток
	cout << "\n-------------------------------------------\n";
	//добавляем студентов
	for (int i = 0; i < numder; ++i) {
		study.getdata();

		//ввод данных через консоль и распределение их по файлам в зависимости от курса
		//всего четыре курса, значит будет 4-ре файла

		if (study.getCours() == 1) {
			string ras = ".txt";
			string path = "1" + ras;
			ofstream outfile = study.funcFile(path); //открыли поток
			study.write(outfile);
			outfile.close();
		}

	
		if (study.getCours() == 2) {
			string ras = ".txt";
			string path = "2" + ras;
			ofstream outfile = study.funcFile(path); //открыли поток
			study.write(outfile);
			outfile.close();
		}

		if (study.getCours() == 3) {
			string ras = ".txt";
			string path = "3" + ras;
			ofstream outfile = study.funcFile(path); //открыли поток
			study.write(outfile);
			outfile.close();
		}

		if (study.getCours() == 4) {
			string ras = ".txt";
			string path = "4" + ras;
			ofstream outfile = study.funcFile(path); //открыли поток
			study.write(outfile);
			outfile.close();
		}
	}

	//просмотр файлов в консоли
	study.readCh("1.txt", 1);
	study.readCh("2.txt", 2);
	study.readCh("3.txt", 3);
	study.readCh("4.txt", 4);


	//просмотр отсортированных файлов в консоли
	/*study.readCh("1sort.txt", 1);
	study.readCh("2sort.txt", 2);
	study.readCh("3sort.txt", 3);
	study.readCh("4sort.txt", 4);*/

}

/////////////////////////////////////////
//запуск обработки данных и чтение результата (по всем 4-м курсам)   
void WorkStudentFile() {
	DataFileAnalis datAnalF;
	datAnalF.NewDanReadFile();
	for (int i = 0; i < 4; ++i) {
		//====работа с файлами где списки отсортированы
		int ii = i + 1;
		string co = to_string(ii); // to_string() функция перевода int в string
		string ras = "sort.txt";
		string oname = co + ras;
		datAnalF.readFile(oname, i + 1); // ost записывает данные в файл опаmе
		

		//====работа с файлами где списки НЕ отсортированы =====
		//int ii = i + 1;
		//string co = to_string(ii); // to_string() функция перевода int в string
		//string ras = ".txt";
		//string path = co + ras;
		//datAnalF.readFile(path, i+1);
	}
	cout << "итоги анализа данных по курсам ищите в файле resalt.txt  !" << endl;
}


//////////////////////////////////////////
// сортировка списка по первому имени студента
// все 4-ре файла будут отсортированы
void PersListSort() {
	PersonListSort lstSort;
	for(int i = 0; i < 4; ++i){
		int ii = i + 1;
		string co = to_string(ii); // to_string() функция перевода int в string
		string ras = ".txt";
		string path = co + ras;
		lstSort.readForSort(path, i + 1);
	}
	cout << " файлы отсортированы ";
}


/////////////////////////////////////////

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "ИНСТРУКЦИЯ "
	    "\n1 - добавление сведений о работнике"
		"\n2 - просмотреть статистику по курсам"
		"\n3 - отсортировать списки студентов в файле"		 
		"\n0 - выход"
		"\nВаш выбор:  ";

	int up;
	cin >> up;
	 
	switch (up) {		
	case 1:
		 InStudentFile();    //запись данных и просмотр в консоли
	case 2:
		 WorkStudentFile(); //чтение файла и обработка данных
	case 3:
		 PersListSort();    //сортировка файла по первому имени

	case 0: exit(0); // выход
	default: cout << "\nНеизвестная команда";
	} // end switch
	return 0;
}

