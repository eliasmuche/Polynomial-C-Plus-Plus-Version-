//Elias Muche 
//3/29/16
//Program 1:Polynomials 
//I implemented this program to handle negative exponents in addition to the specification on canvas 
 
#pragma once                               
#include <iostream>
#include <string>
using namespace std;

//A Polynomial class

class Polynomial {
  //Ostream << overload 
  //prints out a polynomial object
  //Pre-conditions:p.head must not be null
  //Post-conditions:The poly param will not be changed after being printed 
  friend ostream& operator<<( ostream &output, const Polynomial& p );
  public:
  // Member functions

  //Helper method repeatidely calls remove 
  //Pre-conditions:head must not be null
  //Post-conditions:head will be remaining and there should be no terms 
  void clear();

  //Default constructor initializes the object
  //Pre-conditions:no preconditions
  //Post-condition: A monomial of 0x^0 is created (dummy header)
  Polynomial( );

  //Copy constructor creates a deep copy
  //Pre-conditions: head must not be null
  //Post-conditions: The terms of this and the param should match
  Polynomial( const Polynomial& p );
  
  //Destructor deallocates the links of the poly
  //Pre-conditions:there must be at least head to delete (it can't be null) 
  //Post-conditions:there should be no terms after the destructor is finished running
  ~Polynomial( );

  //Returns the value of the leading term's exponent
  //Pre-conditions:head must not be null
  //Post-conditions:a number will be returned 
  int degree( ) const;

  //Returns the coefficient that correspondes to the given power or 0 if there's no such term
  //Pre-conditions:head must not be null
  //Post-conditions:a value will always be returned (0 or the corresponding coefficient)
  double coefficient( const int power ) const; 
  
  //This method either changes the coefficient of a specified term, calls insert, or calls remove 
  //If The coeff param is 0, then the method attempts to delete the term
  //If the coeff param isn't 0, the method checks if the power already exists(it will then change the coeff)
  //If it didnt change the coeff, insert is called
  //The method returns the result of the private helper method it calls (true or false for deleting/inserting) or true if it changed a coeff 
  //Pre-conditions:head must not be null 
  //Post-conditions:a term will either be added, removed, or have the coefficient changed              
  bool changeCoefficient( const double newCoefficient, const int power );
                 
  // Arithmetic operators

  //+ overload takes two polynomials and creates another polynomial which will store the sum 
  //The sum is returned
  //Pre-conditions: The parameter must not have a head that is null 
  //Post-conditions: The lhs will be returned if the rhs is 0 otherwise the sum is returned
  Polynomial operator+( const Polynomial& p ) const;

  //- overload takes two polynomials and creates another polynomial which will store the difference 
  //The difference is returned
  //Pre-conditions: The parameter must not have a head that is null 
  //Post-conditions: The lhs will be returned if the rhs is 0 otherwise the difference is returned
  Polynomial operator-( const Polynomial& p ) const;

  // Boolean comparison operators

  //== overload 
  //Returns true if the terms each term matches with each term of the param. Returns false otherwise
  //Pre-conditions:there must be a head for this and the param
  //Post-conditions: true or false will be returned
  bool operator==( const Polynomial& p ) const;

  //!= overload 
  //Returns the negation of == (true if they're not equal and false if they are)
  //Pre-conditions:there must be a head for this and p 
  //Post-conditions:true or false will be returned
  bool operator!=( const Polynomial& p ) const;

  // Assignment operators

  //Assignemt= overload
  //Sets the terms of this to the same terms of p 
  //This is returned 
  //Pre-conditions:The parameter must have head initialized (even if there are no terms)
  //Post-conditions:this should have the exact same data(terms and term values) 
  Polynomial& operator=( const Polynomial& p );

  //+= overload takes two polynomials and modifies this to store the sum  
  //This is returned
  //Pre-conditions:the parameter must not have a head that is null 
  //Post-conditions:this will be returned (either unaltered or as the sum)
  Polynomial& operator+=( const Polynomial& p );

  //-= overload takes two polynomials and modifies this to store the difference  
  //This is returned
  //Pre-conditions:the parameter must not have a head that is null 
  //Post-conditions:this will be returned (either unaltered or as the difference)
  Polynomial& operator-=( const Polynomial& p );
 private:
  struct Term {     // a term on the sparce polynomial
    double coeff;   // the coefficient of each term
    int power;      // the degree of each term
    Term *prev;     // a pointer to the previous higher term
    Term *next;     // a pointer to the next lower term
  };
  int size;         // # terms in the sparce polynomial
  Term *head;       // a pointer to the doubly-linked circular list of
                    // sparce polynomial
  //This method inserts a new term with the params as values
  //Method returns true 
  //Pre-conditions:The term passed in should not be the dummy head 
  //Post-conditions:There will be a new term inserted
  bool insert( Term* prev, const double newCoefficient, const int power );

  //This method removes a specified term if it exists 
  //True is returned if a term is deleted otherwise false is returned
  //Pre-conditions:The param passed in should not the dummy head
  //Post-conditions:The poly should not be changed unless the specified term exists 
  bool remove( Term* pos );
  
};

