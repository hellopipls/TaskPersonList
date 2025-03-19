#include "DataFileAnalis.h"



///////////////////////////////////////////////

DataFileAnalis::DataFileAnalis()
{
	this->first_name = "0";
	this->second_name = "0";
	this->therd_name = "0";	
	this->y = 0;
	this->cours = 0;
	this->group_number = 0;
	this->mark_Histori = 0;
	this->mark_Philosophy = 0;
	this->mark_mathAnalysis = 0;
	this->mark_Programming = 0;
	this->mark_AlgoStructurDate = 0;
	this->itog = 0;
}

DataFileAnalis::DataFileAnalis(string first_name, string second_name, string therd_name, int y, int cours, int group_number, int mark_Histori, int mark_Philosophy, int mark_mathAnalysis, int mark_Programming, int mark_AlgoStructurDate, float itog)
{
	this->first_name= first_name;
	this->second_name=second_name;
	this->therd_name=therd_name;	
	this->y=y;
	this->cours= cours;
	this->group_number=group_number;
	this->mark_Histori=mark_Histori;
	this->mark_Philosophy=mark_Philosophy;
	this->mark_mathAnalysis=mark_mathAnalysis;
	this->mark_Programming=mark_Programming;
	this->mark_AlgoStructurDate=mark_AlgoStructurDate;
	this->itog=itog;
}

DataFileAnalis::~DataFileAnalis()
{
}

///////////////////////////////////////////////

//-----максимальный средний балл у группы==
float DataFileAnalis::MaxMark(vector<DataFileAnalis>& v, int l)
{
	float max = 0;
	for (int i = 0; i < l; ++i) {
		if (max <= v[i].itog) {
			max = v[i].itog;
		}
	}
	return max;
}

//----- средний балл по всей группе---
float DataFileAnalis::SrednMarkGrup(vector<DataFileAnalis>& v, int l)
{
	float sumI = 0;
	float sum = 0;
	for (int i = 0; i < l; ++i) {
		sum = sum + v[i].itog;
	}
	sumI = float(sum / l);
	return sumI;
}

//-----число лучших студентов по всем предметам--------
int DataFileAnalis::countBestSt(ofstream& ost, vector<DataFileAnalis>& v, int l, float max)
{
	int count = 0;
	ost << "лучший студент по всем предметам: ";
	for (int i = 0; i < l; ++i) {
		if (v[i].itog == max) {
			int ii = i + 1;
			count++;		
			ost << v[i].first_name <<" " << v[i].second_name <<"  ";
		}
	}
	ost << endl;	
	return count;
}

//---------------------------------------
int DataFileAnalis::MaxYearStud(vector<DataFileAnalis>& v, int l)
{	
	int tmp = 0;
	for (int i = 0; i < l; ++i) {
		if (tmp < v[i].y) {
			tmp = v[i].y;			
		}
	}
	return tmp;
}
//---------------------------------
int DataFileAnalis::MinYearStud(vector<DataFileAnalis>& v, int l)
{	
	int tmp = 2025; //допустим что максимальный год рождения = 2025
	for (int i = 0; i < l; ++i) {
		if (tmp > v[i].y) {
			tmp = v[i].y;
		}
	}
	return tmp;
}

//=======================
void DataFileAnalis::NewDanReadFile()
{
	string оnаmе = "resalt.txt";
	ofstream ost{ оnаmе, ofstream::app }; // ost записывает данные в файл опаmе
	if (!ost) {
		cerr << "Невозможно открыть входной файл\n";
		exit(1);
	}

	ost << "\n==========================================";
	ost << endl << " НОВЫЕ ДАННЫЕ по курсам " << endl;
	ost << "\n==========================================";

}




//==========чтение файла и обработка данных====================
void DataFileAnalis::readFile(string path, int cour)
{
	ifstream readMyfily;  //открыла поток
	readMyfily.open(path);

	//добавили проверку наличия файла (так положено!)
	if (!readMyfily) {
		cerr << "Невозможно открыть входной файл\n";
		exit(1);
	}

	string оnаmе = "resalt.txt";
	ofstream ost{ оnаmе, ofstream::app }; // ost записывает данные в файл опаmе
	if (!ost) {
		cerr << "Невозможно открыть входной файл\n";
		exit(1);
	}

	vector<DataFileAnalis> tempM; // Хранилище для считанных из файла данных 	
	 
	while (readMyfily >> first_name >> second_name >> therd_name >> y >> cours >> group_number >> mark_Histori >> mark_Philosophy >> mark_mathAnalysis >> mark_Programming >> mark_AlgoStructurDate >> itog) {
		tempM.push_back(DataFileAnalis{ first_name, second_name, therd_name, y, cours, group_number, mark_Histori, mark_Philosophy, mark_mathAnalysis, mark_Programming, mark_AlgoStructurDate, itog });
	}
	
	//найти самого старшего и самого младшего студента на курсе
	//-------------------------- 
	
	ost << "\nСТУДЕНТЫ  " << cour << "-го КУРСА.\n";
	int l = tempM.size();                 //число студентов на курсе (строк)  	
	float max = MaxMark(tempM, l);        //максимальный бал в группе
	float sumG = SrednMarkGrup(tempM, l); //средний бал по курсу
	int countBest = countBestSt(ost, tempM, l, max); //кол-во лучших студентов
	int MinStud = MinYearStud(tempM, l);  //младший возраст студента
	int MaxStud = MaxYearStud(tempM, l);  //старший возраст студента
	//-------------------------	
	ost << "самый старший студент " << MinStud << "  года рождения\n";
	ost << "самый младший студент " << MaxStud << "  года рождения\n";	
	ost << countBest <<" - студент имеет максимальный балл.\n";
	ost << "МАКСимальный балл по курсу: " << max << endl;
	ost << "СРЕДНИЙ балл по курсу:  " << sumG << "\n";
	ost << endl;

}



