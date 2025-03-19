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

//-----������������ ������� ���� � ������==
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

//----- ������� ���� �� ���� ������---
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

//-----����� ������ ��������� �� ���� ���������--------
int DataFileAnalis::countBestSt(ofstream& ost, vector<DataFileAnalis>& v, int l, float max)
{
	int count = 0;
	ost << "������ ������� �� ���� ���������: ";
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
	int tmp = 2025; //�������� ��� ������������ ��� �������� = 2025
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
	string �n�m� = "resalt.txt";
	ofstream ost{ �n�m�, ofstream::app }; // ost ���������� ������ � ���� ���m�
	if (!ost) {
		cerr << "���������� ������� ������� ����\n";
		exit(1);
	}

	ost << "\n==========================================";
	ost << endl << " ����� ������ �� ������ " << endl;
	ost << "\n==========================================";

}




//==========������ ����� � ��������� ������====================
void DataFileAnalis::readFile(string path, int cour)
{
	ifstream readMyfily;  //������� �����
	readMyfily.open(path);

	//�������� �������� ������� ����� (��� ��������!)
	if (!readMyfily) {
		cerr << "���������� ������� ������� ����\n";
		exit(1);
	}

	string �n�m� = "resalt.txt";
	ofstream ost{ �n�m�, ofstream::app }; // ost ���������� ������ � ���� ���m�
	if (!ost) {
		cerr << "���������� ������� ������� ����\n";
		exit(1);
	}

	vector<DataFileAnalis> tempM; // ��������� ��� ��������� �� ����� ������ 	
	 
	while (readMyfily >> first_name >> second_name >> therd_name >> y >> cours >> group_number >> mark_Histori >> mark_Philosophy >> mark_mathAnalysis >> mark_Programming >> mark_AlgoStructurDate >> itog) {
		tempM.push_back(DataFileAnalis{ first_name, second_name, therd_name, y, cours, group_number, mark_Histori, mark_Philosophy, mark_mathAnalysis, mark_Programming, mark_AlgoStructurDate, itog });
	}
	
	//����� ������ �������� � ������ �������� �������� �� �����
	//-------------------------- 
	
	ost << "\n��������  " << cour << "-�� �����.\n";
	int l = tempM.size();                 //����� ��������� �� ����� (�����)  	
	float max = MaxMark(tempM, l);        //������������ ��� � ������
	float sumG = SrednMarkGrup(tempM, l); //������� ��� �� �����
	int countBest = countBestSt(ost, tempM, l, max); //���-�� ������ ���������
	int MinStud = MinYearStud(tempM, l);  //������� ������� ��������
	int MaxStud = MaxYearStud(tempM, l);  //������� ������� ��������
	//-------------------------	
	ost << "����� ������� ������� " << MinStud << "  ���� ��������\n";
	ost << "����� ������� ������� " << MaxStud << "  ���� ��������\n";	
	ost << countBest <<" - ������� ����� ������������ ����.\n";
	ost << "������������ ���� �� �����: " << max << endl;
	ost << "������� ���� �� �����:  " << sumG << "\n";
	ost << endl;

}



