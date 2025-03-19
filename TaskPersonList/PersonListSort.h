#pragma once
#include <fstream>
#include <iostream> 
#include <vector>
#include <string> 
#include<list> 
using namespace std;




class PersonListSort
{
public:
    PersonListSort();
public:
    PersonListSort(
        string first_name
    );

public:  //�����������
    PersonListSort(
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
    ~PersonListSort();

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



   
    void readForSort(string, int);   
    void sortList(list<string>& lst, ofstream& os, vector<PersonListSort>& v, int l); //����������� ������ ����� �� ������� �����
};


