/*****************************************************************
 * Program filename: wizard.cpp
 * Author:Temi
 * Date: 4/16/19
 * Description: This holds all my funtion prototypes
 * Input: none
 * Output: none
 ******************************************************************/
#include<iostream>
#include<cstring>
#include<string>

using namespace std;

struct wizard{
   string name;
   int id;
   string password;
   string position_title;
   float beard_length;
};

struct spellbook{
   string title;
   string author;
   int num_pages;
   int edition;
   int num_spells;
   float avg_success_rate;
   struct spell *s;
};
struct spell{
   string name;
   float success_rate;
   string effect;
};

int get_id(string *pass);
bool check_id(struct wizard *wiz_ar, int i, int num_wizards, string *pass);
spellbook *create_spellbook(int);
void get_spellbook_data(spellbook *, int, ifstream &);
spell * create_spells(int);
void get_spell_data(spell *, int, ifstream &);
void spellbook_pages(spellbook * spellbook_ar, int num_spellbook);
void sort_spell_effect(spell *s, int num_spells, spellbook *spellbook_ar, int num_spellbook, bool isStudent);
bool student_check(struct wizard *wiz_ar, int num_wizards);
void choose(spellbook * spellbook_ar, int num_spellbook, spell *s, int num_spells, bool isStudent);
void sort_success_rate(spellbook * spellbook_ar, int num_spellbook);
void delete_info(wizard ** wiz_ar, spellbook** spellbook_ar,int num_spellbook);
