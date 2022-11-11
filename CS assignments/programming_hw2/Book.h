#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// parent Book class
class Book {
private:     
    int code;       // int, id number of book
    string title;   // string name of book
    int available;  // int, # of available copies
    int rented      // int, # of copies already rented
public:
    // Constructors
    Book();
    Book(int code, string title, int available, int rented);

    // Mutators
    void setCodeID(int newID);
    void setBookName(string newName);
    void setAvailable(int newAvailable);
    void setRented(int newRented);

    // Accessors
    int getCodeID();
    string getBookName();
    int getAvailable();
    int getRented();
};


// derived classes

class ChildrenBook : public Book {
private:
    int age;
public:
    // Constructors
    ChildrenBook(int code, string title, int age, int available, int rented) 
        : Book(int code, string title, int available, int rented){
        this->age = age;
    };

    // Mutators
    void setAge(int newAge) {
        age = newAge;
    };

    // Accessors
    int getAge() {
        return age;
    };
};

class ComputerBook : public Book {
private:
    string publisher;
public:
    // Constructors
    ComputerBook(int code, string title, string publisher, int available, int rented) 
        : Book(int code, string title, int available, int rented) {
        this->publisher = publisher;
    };

    // Mutators
    void setPublisher(int newPublisher) {
        publisher = newPublisher;
    };

    // Accessors
    int getPublisher() {
        return publisher;
    };
};

class Novel : public Book {
private:
    int publish_date;
public:
    // Constructors
    Novel(int code, string title, int publish_date, int available, int rented) 
        :Book(int code, string title, int available, int rented){
        this->publish_date = publish_date;
    };

    // Mutators
    void setPublishDate(int newPublishDate) {
        publish_date = newPublishDate;
    };

    // Accessors
    int getPublishDate() {
        return publish_date;
    };
};