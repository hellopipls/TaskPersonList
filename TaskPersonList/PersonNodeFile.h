#pragma once
#include <fstream>
#include <iostream> 
#include <vector>
#include <string> 
using namespace std;


const int LEN = 32;    // ������������ ����� �������

//===============================
struct Marks {   
    int mark_Histori;
    int mark_Philosophy;
    int mark_mathAnalysis;
    int mark_Programming;
    int mark_AlgoStructurDate;
    float itog;  
   
    
    //����������� 
    Marks(        
        int mark_Histori,
        int mark_Philosophy,
        int mark_mathAnalysis,
        int mark_Programming,
        int mark_AlgoStructurDate,
        float itog    //�������-��������������        
    ); 

    //����������� 
    Marks();
    //���������� 
    ~Marks();

    vector<int> v;    
    float averageMarks();    
    friend ostream& operator<< (ostream& out, Marks& p);
};


//======================================
class PersonNodeFile
{
public:
    char first_name[LEN]; //��������� ������; "�����" �� ������ �� ������� ���������
    char second_name[LEN];//��������� ������; "�����" �� ������ �� ������� ���������
    char therd_name[LEN]; //��������� ������; "�����" �� ������ �� ������� ���������
    int bearthDay;
    int cours;
    int group_number;
    Marks markss;
    int count;

public:
    //����������� 
    PersonNodeFile(
        char f,
        char s,
        char th,
        int b,
        int co,
        int gr,
        Marks ma
    );


    //����������� 
    PersonNodeFile();

    //���������� 
    ~PersonNodeFile();


    //------���������� �������-------------------
    void getdata(); //������ ������ ������ �������� ����� �������
    void addCours();
    void addMarks();
    float getMarks();
    int getGroup();
    void addGroup(int g);
    int getCours();
    void putdata(); //�������� ������ ������ �������� � �������    
    ofstream funcFile(string); //�������� ����� ��� ������ ������ �� ������   
    void write(ofstream&);      //������ ������ � ����
    void readCh(string, int);  //  ������ ������ ���  char
};




