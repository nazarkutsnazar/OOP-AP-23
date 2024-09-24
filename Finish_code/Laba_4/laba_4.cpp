#include<iostream>
using namespace std;

class Movie_1   //Оголошення класу Movie_1
{
public:
  string name , producer ; //Oppenheimer ; Charles Roven
  int year;  //2023

  void print_1()
  {
    cout << "Name: " << name << "\n\nProducer: " << producer << "\n\nYear: " << year << endl;
  }
};

class Movie_2     //Оголошення класу Movie_2
{
public:
  string name , genre , country ; // Friends ; Comedy ; USA
  string producer_name ; // David
  string producer_lastname ; //Cranke
  string producer_name_n_lastname ; // David + " " + Cranke == David Cranke
  int episodes;  //236
  int year;  //1994

  void enter_print()
  {

    cout << "Name: " ; // Friends
    cin >> name ;

    cout << "\nProducer: \n1) Name: " ;
    cin >> producer_name ;           // David
    cout << "\n2) Lastname: " ;
    cin >> producer_lastname ;         //Cranke
    
    producer_name_n_lastname = producer_name + " " + producer_lastname ;  // David Cranke

    cout << endl << "Genre: " ; //Comedy
    cin >> genre ;

    cout << endl << "Country: " ; //USA
    cin >> country ;

    cout << "\nEpisodes: " ; //236
    cin >> episodes ;

    cout << "\nYear: " ; //1994
    cin >> year ;

  }

  void print_2()
  {

    cout << "Name: " << name <<"\n" << "Producer: " ;
    cout << producer_name_n_lastname << "\n" ;
    cout << "Genre: " << genre << "\n" ;
    cout << "Country: " << country << "\n" ;
    cout << "Episodes: " << episodes << "\n" ;
    cout << "Year: " << year << "\n" ;
  }
};

////////////////////////////____MAIN____/////////////////////////////////////////

int main(void)
{
system ("clear"); // Очищає термінал

cout << "----------MOVIE 1----------\n" ;
  Movie_1 Thriller {"Oppenheimer" , "Charles Roven" , 2023 };

Thriller.print_1();


cout << "\n\n" <<  "----------MOVIE 2----------\n" ;
  //Movie_2 Comedy {"Friends" , "David Crane" , "Comedy" , "USA" , 236 , 1994};

Movie_2 Comedy {};
Comedy.enter_print();

cout <<"\n\n" << "----------MOVIE 2 RESULT----------\n" ;
  Comedy.print_2();


  return 0;
}
