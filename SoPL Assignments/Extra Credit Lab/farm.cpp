/*
 * Author: Omer Basar
 * Filename: farm.cpp
 * Version: 12/4/20
 * Lab: Extra credit - Extend Polymorphism
 */

// appropriate include statements
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

// abstract base class
class Animal
{
        protected:
            int weight;
        public:
            // pure virtual methods
            virtual void speak() = 0;
            virtual void setWeight(int) = 0;
            virtual int getWeight() = 0;
            virtual void play() =0;
            // virtual destructor
            virtual ~Animal() {}
};

// derived class
class Dog : public Animal
{
    public:
        // polymorphic implementation of speak
        virtual void speak() { cout << "Ruff!\n"; }
        // polymorphic implementation of setWeight
        virtual void setWeight(int tmp) { weight = tmp; }
        // polymorphic implementation of getWeight
        virtual int getWeight() { return weight; }
        // polymorphic implementation of play
        virtual void play() { cout << "RUN!\n"; }

};

// second derived class
class Cat : public Animal
{
    public:
        // polymorphic implementation of speak
        virtual void speak() { cout << "Meow!\n"; }
        // polymorphic implementation of setWeight
        virtual void setWeight(int tmp) { weight = tmp; }
        // polymorphic implementation of getWeight
        virtual int getWeight() { return weight; }
        // polymorphic implementation of play
        virtual void play() { cout << "CHASE!\n"; }
};

// third derived class
class Chicken : public Animal
{
    public:
        // polymorphic implementation of speak
        virtual void speak() { cout << "Cluck!\n"; }
        // polymorphic implementation of setWeight
        virtual void setWeight(int tmp) { weight = tmp; }
        // polymorphic implementation of getWeight
        virtual int getWeight() { return weight; }
        // polymorphic implementation of play
        virtual void play() { cout << "ATTEMPT TO FLY!\n"; }
};

// main lines of code that are executed
int main( int argc, char* args[] )
{
    // container of base class pointers
    vector<Animal*> barn;

    // init our rng
    // one second precision
    srand((unsigned)time(0) );
    const int RANDMAX = 100;

        Dog *max;
        Cat *murray;
        Chicken *mikela;

        max = new Dog();
        murray = new Cat();
        mikela = new Chicken();

    // dynamically allocate an Animal instance and add it to the container
    barn.push_back( new Dog() );
    barn.push_back( new Cat() );
    barn.push_back( new Chicken() );

    // iterate through each animal in ghe barn to perform the following operations
    for( vector<Animal*>::iterator i = barn.begin(); i != barn.end(); ++i )
    {
    	// invoke the setWeight method of each Animal in the container
        (*i)->setWeight((rand() % RANDMAX) + 1);
    }

    // iterate through each animal in ghe barn to perform the following operations
    for( vector<Animal*>::iterator i = barn.begin(); i != barn.end(); ++i )
    {
        // invoke the speak method of each Animal in the container
        (*i)->speak();
    }

    // iterate through each animal in ghe barn to perform the following operations
    for( vector<Animal*>::iterator i = barn.begin(); i != barn.end(); ++i )
    {
    	// invoke the getWeight method of each Animal in the container
        cout << (*i)->getWeight() << "\n";
    }

    // iterate through each animal in ghe barn to perform the following operations
    for( vector<Animal*>::iterator i = barn.begin(); i != barn.end(); ++i )
    {
        // invoke the play method of each Animal in the container
        (*i)->play();
    }

    // free the allocated memory from each animal entry
    for( vector<Animal*>::iterator i = barn.begin(); i != barn.end(); ++i )
    {
           delete *i;
    }

    // empty the container
    barn.clear();

    // upon success 
    return 0;
}
