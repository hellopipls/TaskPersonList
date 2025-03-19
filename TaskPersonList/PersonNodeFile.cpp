#include "PersonNodeFile.h"


//=====������������ ��������� Marks=========
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

//����������
Marks::~Marks()
{
}


//--������� ������� ������. ��� ��������� ��� ������:   cout << markss  
ostream& operator<<(ostream& out, Marks& p)
{
	for (auto& n : p.v) {
		out << "\t" << n;
		out.width(3);
	}
	 out << "\t"<< p.averageMarks(); //������ ������-��������������	
	return out;
}


////////////////////////////////////////////////////////
// 
//===������������ ������ PersonNodeFile===========

PersonNodeFile::PersonNodeFile(  char f,  char s,  char th, int b, int co, int gr, Marks ma) : first_name{f}, second_name{s}, therd_name{th}, bearthDay{b}, cours{co}, group_number{gr}, markss{ma}
{
}



PersonNodeFile::PersonNodeFile()
{	
	*this->first_name = 0; //���������� ���������� first_name[0]='0';
	*this->second_name = 0;//���������� ���������� second_name[0]='0';
	*this->therd_name = 0; //���������� ���������� therd_name[0]='0';
	this->bearthDay = 0;
	this->cours = 0;
	this->group_number = 0;
	this->markss;
	this->count = 0;
}
//����������
PersonNodeFile::~PersonNodeFile(){}


//========�������===============================


//-���� �������� ������ ����� �������-----
void PersonNodeFile::getdata()
{
	count = 1;
	cout << endl;
	cout << endl;
	cout << "������� �������: "; cin >> first_name;
	cout << "������� ���: "; cin >> second_name;
	cout << "������� ��������: "; cin >> therd_name;
	cout << "������� ��� ��������: "; cin >> bearthDay;//�������� ��������������� ���� ��������
	cout << "������� ����� ������:"; cin >> group_number;
	addCours();  //�������� ����� � ��������� �� ������������ �����!	
	addMarks();  //��������� ������
	cout << endl;
}
 
//--- �������� ������ � �������------
void PersonNodeFile::putdata()
{
	cout << endl;
	cout << first_name << " ";
	cout << second_name << " ";
	cout << therd_name << " ";
	cout << "\n����: " << cours;
	cout << "��� ��������: " << bearthDay;
	cout << "������:" << group_number;
	cout << "\n������ �� 5-�� ���������:\n";
	cout << markss;
	cout << endl;
}

//////////////////////////////////////////
//----���� ������ �����: cours --------------
void PersonNodeFile::addCours()
{
	cout << "������� ��� ����: "; cin >> cours;
	if (cours > 4 || cours < 0) {
		count++;
		cout << "������� ������ ����. " << endl;
		cout << "����������, ������� ����� �� 1 �� 4-� " << endl;
		if (count == 4) {
			cout << "<������... �� �� ������ ....\n";
			cout << "�� ��������� ���� �� ���������!";
			return;
		}
		addCours(); //�������� (���� �... �� ����� ����� ����)
	}
	count = 1;
}

   //--�������� ����� �����---------------
int PersonNodeFile::getCours()
{
	return this->cours;
}


//////////////////////////////////////////////
 

//-- ���� ������---
void PersonNodeFile::addGroup(int g)
{
	this->group_number = g;
}

//-- �������� ����� ������---
int PersonNodeFile::getGroup()
{
	return this->group_number;
}



/////////////////////////////////////////
//--���� ������--------
void PersonNodeFile::addMarks()
{
	markss.v.clear();
	cout << "�������: "; cin >> markss.mark_Histori;
	markss.v.push_back(markss.mark_Histori);				 //<----vector-------
	cout << "���������: "; cin >> markss.mark_Philosophy;
	markss.v.push_back(markss.mark_Philosophy);				 //<----vector-------
	cout << "���-������: "; cin >> markss.mark_mathAnalysis;
	markss.v.push_back(markss.mark_mathAnalysis);			 //<----vector-------
	cout << "����������������: "; cin >> markss.mark_Programming;
	markss.v.push_back(markss.mark_Programming);			  //<-----vector------
	cout << "������: "; cin >> markss.mark_AlgoStructurDate;
	markss.v.push_back(markss.mark_AlgoStructurDate);	      //<-----vector------
	cout << "�������.�����.������: " << markss.averageMarks();	
}

//--�������� �������������������� ������-----
  
float PersonNodeFile::getMarks()
{		
	return markss.averageMarks();
}

//-������ ������ �������������� ������ ��������---
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


//====�����===========================

//--��� �������� ����� ��� ������ ������ (� ����� ������) ----
ofstream PersonNodeFile::funcFile(string path) //��� �����
{
	ofstream outfile(path, ofstream::app); //������� ����� � ������������� �������� 
	return outfile;
}



//--������ ������ � ����-----
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

 //----��������� ������ (��� char)  �� ����� � �������---------
 void PersonNodeFile::readCh(string path, int crs)
 {
	 fstream readMyfily;  //������� �����
	 readMyfily.open(path);

	 //�������� �������� ������� ����� (��� ��������!)
	 if (!readMyfily) {
		 cerr << "���������� ������� ������� ����\n"; exit(1);
	 }

	 cout << "\n-------------------------------------------";
	 cout << "\n"<<"  ��������: " << crs << "-�� �����";
	 cout << "\n-------------------------------------------" << endl;

	 int obj = 0; //��� �������� ������ (�������(� �����)+��������) � �����
	 char ch;

	 while (readMyfily.get(ch)) {//	get() ��� ������ �� ������ �������(�� ������)	
		 //���������� ������� get() �� ������ ��������� ��� int

		 cout.put(ch); //����� �� �������� 			
		 if (ch == 'n') { //���� ����������� ������� ������ �� ???
			 readMyfily.put(' '); //�������� ������
			 readMyfily << obj;  //����� ������ ����� ��������� obj
			 readMyfily.put(' '); //� �������� ������
		 }
		 obj++;
	 }
	 //readMyfily <<endl << obj << endl;
	 readMyfily.close();//������� �����
 }

 
