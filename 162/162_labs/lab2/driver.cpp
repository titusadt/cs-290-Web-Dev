#include<iostream>
#include<fstream>
#include"student_db.h"

using namespace std;

int main(int argc, char *argv[]){
   int num_students;
   struct student* student_ar;
   //std::ostream os;
   
   if(argc != 2){
      cout << "Incomplete command line arguments" << endl;
   }
   
   string student_filename = argv[1];
   fstream ifs;
   ifs.open(student_filename.c_str(), ifstream::in);
   if(!ifs.is_open()){
      cout << "Unable to open file" << endl;
      return 1;
   }
  
   ifs >> num_students; 
   
   string output_file = "new_file.txt";
   ofstream ofs;
   ofs.open(output_file.c_str(), ofstream::trunc);
   if(!ofs.is_open()){
      cout << "Unable to open file" << endl;
      return 1;
   }
   id_sort(student_ar, num_students, ofs);
   last_name_sort(student_ar, num_students, ofs);
   major_sort(student_ar, num_students, ofs);
   delete_student_db_info(&student_ar, num_students);


}
