#include<iostream>
using namespace std;

class Film {
private:
  int year;
  string producer;
  string title;
  int num_characters;
public:
Film() {
  cout << "Default constructor" << endl;
}
~Film() {
  cout << "destructor" << endl;
}
Film (string t, string p, int y, int n) : title(t), producer(p), year(y), num_characters(n) {}

  void setTitle(string t) {
    if (t.empty()) {
      cout << "Title can't be empty!" << endl
      << "Try again." << endl;
      exit(1); // Stop program
    } else {
      title = t;
      }
  }
  void setProducer(string p) {
    if (p.empty()) {
      cout << "Producer line can't be empty!" << endl
      << "Try again." << endl;
      exit(1);
    } else {
      producer = p;
      }
  }
  void setYear(int y) {
    year = y;
  }
  void setNumChars(int n) {
    num_characters = n;
  }
  void Result() {
    cout
    << "Title of movie: " << title << endl
    << "Producer: " << producer << endl
    << "Release year: " << year << endl
    << "Number of characters: " << num_characters << endl << endl;
  }
  void setData() {
    string TTitle;
    string PProducer;
    int YYear;
    int CChar;

    cout << endl << "Title of movie: " ; // Fight Club
    getline(cin, TTitle) ;
    if (TTitle == "Fight Club" || TTitle == "FC") {
      setTitle(TTitle);
    } else {
      cout << "Title line can't be empty " << endl;
      cout << "Actually, title of the movie is \"Fight Club\". Try again." << endl;
      exit(1);
    }
    cout << endl << "Producer: " ; // David Fincher
    getline(cin, PProducer) ;
    if (PProducer == "David Fincher") {
      setProducer(PProducer) ;
    } else {
      cout << "Producer of \"Fight Club\" is David Fincher. Try again." << endl;
      exit(1);
    }
    cout << endl << "Year: " ; // 1999
    cin >> YYear ;
    if (YYear == 1999) {
    setYear(YYear);
    } else {
      cout << "Error: \"Fight Club\" must have the release year 1999, try again." << endl;
      exit(1);
    }
    cout << "Number of characters: " ; // 3
    cin >> CChar ;
    if (CChar == 3) {
      setNumChars(CChar);
    } else {
      cout << "Error! There are only 3 characters. Try again." << endl;
      exit(1);
    }
  }
};

int main(void) {

Film Shrek("Shrek", "John Williams", 2001, 4);
cout << "MOVIE 1" << endl;
Shrek.Result(); //SHREK 1

cout << endl << "MOVIE 2" << endl;
Shrek.setTitle("Shrek 2"); Shrek.setYear(2004);
//Shrek.setProducer("John Williams")   ---> Без змін !
//Shrek.setNumChars("4")   ---> Без змін !
Shrek.Result(); //SHREK 2

cout << endl << "MOVIE 3 (Fight Club)" << endl;
/*Film FC("Fight Club", "David Fincher", 1999);
FC.Result();*/ // ЦЕЙ УРИВОК РОЗГЛЯДАВСЯ ПРИ УМОВІ, ЩО РУЧНИЙ ВВІД НЕ ПОТРІБЕН
Film FC;
FC.setData();
FC.Result();

  return 0;
}
