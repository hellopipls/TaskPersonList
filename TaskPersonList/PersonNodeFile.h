#pragma once
#include <fstream>
#include <iostream> 
#include <vector>
#include <string> 
using namespace std;


const int LEN = 32;    // Максимальная длина фамилий

//===============================
struct Marks {   
    int mark_Histori;
    int mark_Philosophy;
    int mark_mathAnalysis;
    int mark_Programming;
    int mark_AlgoStructurDate;
    float itog;  
   
    
    //Конструктор 
    Marks(        
        int mark_Histori,
        int mark_Philosophy,
        int mark_mathAnalysis,
        int mark_Programming,
        int mark_AlgoStructurDate,
        float itog    //средняя-арифметическая        
    ); 

    //КОНструктор 
    Marks();
    //ДЕструктор 
    ~Marks();

    vector<int> v;    
    float averageMarks();    
    friend ostream& operator<< (ostream& out, Marks& p);
};


//======================================
class PersonNodeFile
{
public:
    char first_name[LEN]; //Локальный массив; "живет" до выхода из области видимости
    char second_name[LEN];//Локальный массив; "живет" до выхода из области видимости
    char therd_name[LEN]; //Локальный массив; "живет" до выхода из области видимости
    int bearthDay;
    int cours;
    int group_number;
    Marks markss;
    int count;

public:
    //Конструктор 
    PersonNodeFile(
        char f,
        char s,
        char th,
        int b,
        int co,
        int gr,
        Marks ma
    );


    //Конструктор 
    PersonNodeFile();

    //Деструктор 
    ~PersonNodeFile();


    //------прототитпы функций-------------------
    void getdata(); //ввести данные одного студента через консоль
    void addCours();
    void addMarks();
    float getMarks();
    int getGroup();
    void addGroup(int g);
    int getCours();
    void putdata(); //просмотр данных одного студента в консоли    
    ofstream funcFile(string); //создание файла для записи данных по курсам   
    void write(ofstream&);      //запись данных в файл
    void readCh(string, int);  //  чтение данных как  char
};




