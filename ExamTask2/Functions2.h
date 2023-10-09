#pragma once
using namespace std;

void AddSong(); //Функция лоя добавление песни
void DisplaySong(int num); //Функция для отображение каталога
void DeleteSong(int num); //Функция для удаление 
void EditSong(int num);//Функция для редактирование
void FindSongsByAuthor(string author);//Функция для нахождение по имени автора
void FindSongsByWord(string word);//Функция для нахождение по слову
void menu();//Меню