#include<iostream>
#include<fstream>
#include<string>
#include"student_db.h"
using namespace std;

student * create_student_db(int num_students){
   return new struct student[num_students];
}

void get_student_db_info(student* student_ar, int num_students, fstream& ifs){
   for(int i=0; i<num_students; i++){
      ifs >> student_ar[num_students].id; 
      ifs >> student_ar[num_students].last_name; 
      ifs >> student_ar[num_students].major; 
    }

}

void id_sort(student * student_ar, int num_students, ofstream& ofs){
   for(int i=0; i<num_students; i++){
      for(int c=0; c<num_students-1; c++){
	 if(student_ar[c].id > student_ar[c+1].id){
	    int swap = student_ar[c].id;
	    student_ar[c].id = student_ar[c+1].id;
	    student_ar[c+1].id = swap;
	 }
      
      }
   
   }
   for(int b=0; b<num_students; b++){
      ofs << student_ar[b].id << endl;
   }

}

void last_name_sort(student * student_ar, int num_students, ofstream& ofs){
   for(int i=0; i<num_students; i++){
      for(int c=0; c<num_students-1; c++){
	 if(student_ar[c].last_name > student_ar[c+1].last_name){
	    string swap = student_ar[c].last_name;
	    student_ar[c].last_name = student_ar[c+1].last_name;
	    student_ar[c+1].last_name = swap;
	 }
      
      }
   
   }
   for(int b=0; b<num_students; b++){
      ofs << student_ar[b].last_name << endl;
   }

}

void major_sort(student * student_ar, int num_students, ofstream& ofs){
   for(int i=0; i<num_students; i++){
      for(int c=0; c<num_students-1; c++){
	 if(student_ar[c].major > student_ar[c+1].major){
	    string swap = student_ar[c].major;
	    student_ar[c].major = student_ar[c+1].major;
	    student_ar[c+1].major = swap;
	 }
      
      }
   
   }
   for(int b=0; b<num_students; b++){
      ofs << student_ar[b].major << endl;
   }

}

void delete_student_db_info(student ** student_ar, int num_students){
   for(int i=0; i<num_students; i++){
      delete[](*student_ar);
   }
      delete[]*student_ar;





}
