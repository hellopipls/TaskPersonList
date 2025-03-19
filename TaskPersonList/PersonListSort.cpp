#include "PersonListSort.h"


//-------------------------------
PersonListSort::PersonListSort()
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



//---------------------------
PersonListSort::PersonListSort(string first_name, string second_name, string therd_name, int y, int cours, int group_number, int mark_Histori, int mark_Philosophy, int mark_mathAnalysis, int mark_Programming, int mark_AlgoStructurDate, float itog)
{
	this->first_name = first_name;
	this->second_name = second_name;
	this->therd_name = therd_name;
	this->y = y;
	this->cours = cours;
	this->group_number = group_number;
	this->mark_Histori = mark_Histori;
	this->mark_Philosophy = mark_Philosophy;
	this->mark_mathAnalysis = mark_mathAnalysis;
	this->mark_Programming = mark_Programming;
	this->mark_AlgoStructurDate = mark_AlgoStructurDate;
	this->itog = itog;
}


//-------------------------------

PersonListSort::PersonListSort(string first_name) : first_name{ first_name }{}

//-------------------------------
PersonListSort::~PersonListSort()
{
}





//---сортировка всего списка ---------------------------
void PersonListSort::sortList(list<string>& lst,  ofstream& os, vector<PersonListSort>& v, int l)
{	
	
	for (auto it = lst.cbegin(); it != lst.cend(); ++it) {	
		for (int i = 0; i < l; ++i) {
			if (v[i].first_name == *it) {
				os << endl;
				os.width(3);
				os << "\t" << v[i].first_name;
				os.width(7);
				os << "\t" << v[i].second_name;
				os.width(7);
				os << "\t" << v[i].therd_name << "\t";
				os.width(10);				
				os << "\t" << v[i].cours;
				os.width(10);
				os << "\t" << v[i].y;
				os.width(5);
				os << "\t" << v[i].group_number;
				os.width(5);
				os << "\t" << v[i].mark_Histori;
				os.width(3);
				os << "\t" << v[i].mark_Philosophy;
				os.width(3);
				os << "\t" << v[i].mark_mathAnalysis;
				os.width(3);
				os << "\t" << v[i].mark_Programming;
				os.width(3);
				os << "\t" << v[i].mark_AlgoStructurDate;
				os.width(3);
				os << "\t" << v[i].itog;
				os << endl;				
				break;
			}			
		}
	} 
}


//-------------------------------
void PersonListSort::readForSort(string path, int cour)
{
	ifstream readMyfily;  //открыла поток
	readMyfily.open(path);

	//добавили проверку наличия файла (так положено!)
	if (!readMyfily) {
		cerr << "Невозможно открыть входной файл\n";
		exit(1);
	}
 	
	//=================
	//создаю новый файл (поток)
	int ii = cour;
	string co = to_string(ii); // to_string() функция перевода int в string
	string ras = "sort.txt";
	string оnаmе = co + ras; 
	ofstream ost{оnаmе}; // ost записывает данные в файл опаmе
	if (!ost) {
		cerr << "Невозможно открыть входной файл\n";
		exit(1);
	}

	//=======================
	 vector<PersonListSort> tempM; // Хранилище для считаных данных из файла данных 	
	 list<string> ListStr; //хранилище для списка первых имён

	 //читаю файл и заношу данные в вектор и кое-что в список LIST
	 while (readMyfily >> first_name >> second_name >> therd_name >> y >> cours >> group_number >> mark_Histori >> mark_Philosophy >> mark_mathAnalysis >> mark_Programming >> mark_AlgoStructurDate >> itog) {
		 tempM.push_back(PersonListSort{ first_name, second_name, therd_name, y, cours, group_number, mark_Histori, mark_Philosophy, mark_mathAnalysis, mark_Programming, mark_AlgoStructurDate, itog });
		 ListStr.push_back(first_name);
	 } 
	 
	 int l = tempM.size();	 //длина вектора
	 ListStr.sort();         //отсортированы первые имена
	 
	 sortList(ListStr, ost, tempM, l); //функция по сортировке всего списка
	 
}

