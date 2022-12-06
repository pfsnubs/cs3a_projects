#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#pragma once
using namespace std;

// parent Book class
class Book {
private:
    int code;        // int, id number of book
    string title;    // string name of book
    int available;   // int, # of available copies
    int rented;      // int, # of copies already rented
public:
    // Constructors
    Book(){};
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

    // Other functions
    void attemptToRent();
    void attemptToReturn();

    // ChildrenBook virtual functions
    virtual void setAge(int newAge){};
    virtual int getAge() { return 0; };

    // ComputerBook virtual functions
    virtual void setPublisher(int newPublisher){};
    virtual string getPublisher() { return ""; };

    // Novel virtual functions
    virtual void setPublishDate(int newPublishDate){};
    virtual int getPublishDate() { return 0; };

    // friend fxns
    friend ostream& operator << (ostream& os, const Book& b) {
        os << b.code << " " << b.title << " " << b.available << " " << b.rented;
        return os;
    }
};

class ChildrenBook : public Book {
private:
    int age;
public:
    // Constructors
    ChildrenBook() {};
    ChildrenBook(int code, string title, int age, int available, int rented)
        : Book(code, title, available, rented) {
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
    ComputerBook() {};
    ComputerBook(int code, string title, string publisher, int available, int rented)
        : Book(code, title, available, rented) {
        this->publisher = publisher;
    };

    // Mutators
    void setPublisher(int newPublisher) {
        publisher = newPublisher;
    };

    // Accessors
    string getPublisher() {
        return publisher;
    };
};

class Novel : public Book {
private:
    int publish_date;
public:
    // Constructors
    Novel() {};
    Novel(int code, string title, int publish_date, int available, int rented)
        :Book(code, title, available, rented) {
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