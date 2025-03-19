#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include<list> 
#include <string>
using namespace std;


class DataFileAnalis {    

public:
    DataFileAnalis();

public:  //�����������
    DataFileAnalis(
        string first_name,
        string second_name,
        string therd_name,
        int y,
        int cours,
        int group_number,
        int mark_Histori,
        int mark_Philosophy,
        int mark_mathAnalysis,
        int mark_Programming,
        int mark_AlgoStructurDate,
        float itog    //�������-��������������
    );

public:  //����������
    ~DataFileAnalis();

    string first_name;
    string second_name;
    string therd_name;
    int y;
    int cours;
    int group_number;
    int mark_Histori;
    int mark_Philosophy;
    int mark_mathAnalysis;
    int mark_Programming;
    int mark_AlgoStructurDate;
    float itog;



public:
    //------���������� �������-------------------
    float MaxMark(vector<DataFileAnalis>& v, int l);  //-----������������ ������� ���� � ������==
    float SrednMarkGrup(vector<DataFileAnalis>& v, int l); //----- ������� ���� �� ���� ������---
    int countBestSt(ofstream& ost, vector<DataFileAnalis>& v, int l, float max); //-----����� ������ ��������� --------
    int MaxYearStud(vector<DataFileAnalis>& v, int l);
    int MinYearStud(vector<DataFileAnalis>& v, int l);
    void readFile(string, int);  //������ � ��������� ������   
    void NewDanReadFile();  //������ � ��������� ������   
};