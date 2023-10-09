#include <iostream>
#include "Functions2.h"
#include <string>
using namespace std;

const int MAX_SONGS = 10;


struct Music {
    string title;
    string author;
    int year;
    string lyrics;
};

// Массив для хранение песень
Music Catalog[MAX_SONGS];

// Переменная для отслеживания текущего количества песен в каталоге
int songCount = 0;


// Функция для добавления песни в каталог
void AddSong() {
    if (songCount < MAX_SONGS) {
        Music song;
        cout << "Введите название песни " << endl;
        cin.ignore();
        getline(cin, song.title);
        cout << "Введите автора песни " << endl;
        getline(cin, song.author);
        cout << "Введите год создания песни " << endl;
        cin >> song.year;
        cin.ignore();
        cout << "Введите текст песни " << endl;
        getline(cin, song.lyrics);

        Catalog[songCount] = song;
        songCount++; 
        cout << "Песня успешно добавлена в каталог " << endl;
        cout << endl;
    }
    else {
        cerr << "Каталог песен заполнен \n"; //В случае если в хранилище не может превышать кол-во песень
    }
}

// Функция для отображения текста песни
void DisplaySong(int num) {
    if (num >= 0 && num < songCount) {
        cout << "==============================================" << endl;
        cout << "Название  " << Catalog[num].title << endl; //Отображение название
        cout << "==============================================" << endl;
        cout << "Автор " << Catalog[num].author << endl;    //Отображение Автора
        cout << "==============================================" << endl;
        cout << "Год " << Catalog[num].year << endl;        //Отображение года
        cout << "==============================================" << endl;
        cout << "Текст \n" << Catalog[num].lyrics << endl;   //Отображение текста
        cout << "==============================================" << endl;
    }
    else {
        cerr << "Песня не найдена \n"; //В случае если не найдена
        cerr << endl;
    }
    
}

// Функция для удаления текста песни
void DeleteSong(int num) {
    if (num >= 0 && num < songCount) {
        for (int i = num; i < songCount - 1; i++) {
            Catalog[i] = Catalog[i + 1];
        }
        songCount--;
        cout << "Песня удалена " << endl;  
        cout << endl;
    }
    else {
        cerr << "Песня не найдена " << endl;
        cerr << endl;
    }
    
}

// Функция для изменения текста песни
void EditSong(int num) {
    if (num >= 0 && num < songCount) {
        Music& song = Catalog[num];
        cout << "Введите новое название песни " << endl;
        cin >> song.title;
        cout << "Введите нового автора песни " << endl;
        cin >> song.author;
        cout << "Введите новый год создания песни " << endl;
        cin >> song.year;
        cout << "Введите новый текст песни " << endl;
        cin >> song.lyrics;
        cout << "Песня изменена " << endl;
        cout << endl;
    }
    else {
        cerr << "Песня не найдена " << endl;
        cerr << endl;
    }
}

// Функция для поиска и отображения всех песен одного автора
void FindSongsByAuthor(string author) {
    bool found = false;
    for (int i = 0; i < songCount; i++) {
        if (Catalog[i].author == author) {
            DisplaySong(i);
            found = true;
            cout << endl;
        }
    }
    if (!found) {
        cerr << "Не найдены " << endl;
        cerr << endl;
    }
}

// Функция для поиска и отображения всех песен, содержащих указанное слово
void FindSongsByWord(string word) {
    bool found = false;
    for (int i = 0; i < songCount; i++) {
        if (found = Catalog[i].lyrics.find(word) != -1) {
            DisplaySong(i);
            found = true;
            cout << endl;
        }
    }
    if (!found) {
        cerr << "Песня не найдена! " << endl;
        cerr << endl;
    }
   
}

void menu()
{
    int choice = 0;

    do {     
        cout << "Добро пожаловать \\o/  в программу каталог песень! " << endl;
        cout << "==================================================" << endl;
        cout << "1. Добавить песню " << endl;
        cout << "==============================" << endl;
        cout << "2. Отобразить песню " << endl;
        cout << "==============================" << endl;
        cout << "3. Удалить песню " << endl;
        cout << "==============================" << endl;
        cout << "4. Изменить песню " << endl;
        cout << "==============================" << endl;
        cout << "5. Поиск песен по автору " << endl;
        cout << "==============================" << endl;
        cout << "6. Поиск песен по слову " << endl;
        cout << "==============================" << endl;
        cout << "7. Выход " << endl;
        cout << endl;
        cout << "Выберите ";
        cin >> choice;

        switch (choice) {
        case 1:
        {
            AddSong();
            break;
        }
        case 2:
        {
            int Num;
            cout << "Введите номер песни ";
            cin >> Num;
            DisplaySong(Num);
            break;
        }
        case 3:
        {
            int NumDelete;
            cout << "Введите номер песни для удаления ";
            cin >> NumDelete;
            DeleteSong(NumDelete);
            break;
        }
        case 4:
        {
            int NumEdit;
            cout << "Введите номер песни для редактирования ";
            cin >> NumEdit;
            EditSong(NumEdit);
            break;
        }
        case 5:
        {
            string author;
            cout << "Введите имя автора: ";
            cin >> author;
            FindSongsByAuthor(author);
            break;
        }
        case 6:
        {
            string word;
            cout << "Введите слово для поиска ";
            cin >> word;
            FindSongsByWord(word);
            break;
        }
        case 7:
        {
            break; // Выход из программы
        }
        default:
        {
            cerr << "Ошибка выберите другой номер ";
            break;
        }
        }
    } while (choice != 7);

  
}
