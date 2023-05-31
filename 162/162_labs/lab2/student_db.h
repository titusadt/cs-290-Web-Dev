#include<iostream>
#include<string>

using namespace std;

struct student{
   int id;
   string last_name;
   string major;

};

student * create_student_db(int);
void get_student_db_info(student*, int, fstream&);
void delete_student_db_info(student **, int);
void id_sort(student * student_ar, int num_students, ofstream& ofs);
void last_name_sort(student * student_ar, int num_students, ofstream& ofs);
void major_sort(student * student_ar, int num_students, ofstream& ofs);
void delete_student_db_info(student **, int);
