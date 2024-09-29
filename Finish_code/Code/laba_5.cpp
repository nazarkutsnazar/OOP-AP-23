#include <iostream>
using namespace std;

class Movie
{
private:
  string name , producer ;
  int year ;
public:
  Movie () // Конструктор
  {
  string name = "Unknown";
  string producer = "???";
  int year =  2000 ;
  }

  Movie (string name , string producer , int year) //Конструктор з параметрами
  {
    setName  (name);
    setProducer  (producer);
    setYear  (year);
  }

    ~Movie()    // Деструктор
    {
        cout << "Фільм: " << name << " видалений" << endl;
    }
  void setName (string n)
  {
    name = n ;
  }

  void setProducer (string p)
  {
    producer = p ;
  }

  void setYear (int y)
  {
    year = y;
  }

  void ReleaseYear (int year)
  {
    if (year > 1900 && year <= 2024)
      this->year = year ;

    else  cout << "Помилка, такого року не може бути. " << endl;
  }

  void print_info ()
  {
    cout << "Name: " << name << endl ;
    cout << "Producer: " << producer << endl ;
    cout << "Year: " << year << endl ;
  }

  int get_info_year ()
  {
    return year ;
  }

};

////////////////////////////____MAIN____///////////////////////////
int main (void)
{

Movie Movie_1 {} ;
Movie Movie_2 {"Barby" , "David_Heyman" , 2023};


cout << "Інформація про фільм 1" << endl ;
Movie_1.print_info();

cout << "Інформація про фільм 2" << endl;
Movie_2.print_info();

cout << "\nЗміна даних до фільму 1" << endl;
Movie_1.setName("Berserk");
Movie_1.setProducer("Naohito_Takahashi") ;
Movie_1.setYear(1997);

cout << "\nОновлена Інформація" << endl;
Movie_1.print_info();
  return 0;
}
