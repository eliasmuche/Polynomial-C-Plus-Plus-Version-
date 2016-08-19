//Elias Muche 
//3/29/16
//Program 1:Polynomials
#include<iostream>
#include "polynomial.h"
#include <string>
using namespace std;


int main(){

////////////////////// Your Driver ////////////////////////

  cout<<"--------Start of your Driver--------"<<endl<<endl<<endl;
  Polynomial p1;

 

  p1.changeCoefficient( 1, 1 );

  p1.changeCoefficient( 4, 4 );

  p1.changeCoefficient( 2.2, 2 );

  p1.changeCoefficient( -3.8, 3 );

  cout << "p1 = " << p1 << endl;

 

  p1.changeCoefficient( 0, 2 );

  cout << "p1 = " << p1 << endl;

 

  Polynomial Yp2 = p1;

  Yp2.changeCoefficient( 9.5, 2 );

  cout << "p1 = " << p1 << endl;

  cout << "p2 = " << Yp2 << endl;

 

  Polynomial Yp3 = p1 + Yp2;

  cout << "p3 = " << Yp3 << endl;

  cout<<"-------End of your Driver--------"<<endl<<endl<<endl<<endl;



	
////////////////////// My Driver ///////////////////////
 cout<<"-------Start of my Driver--------"<<endl<<endl<<endl<<endl;
	//Testing default constructor
	Polynomial p;
	cout<<"After the default constructor, p is:    "<<p<<endl;
	
	//Testing changeCoefficient for inserting (I will be inserting negative terms as well as negative power terms in addition to normal terms)
	p.changeCoefficient(8,0);
    p.changeCoefficient(22,-2);
    p.changeCoefficient(-14,-11);
    p.changeCoefficient(-322,9);
    p.changeCoefficient(-1,-1);
    p.changeCoefficient(164,7);
    p.changeCoefficient(113,12);
    p.changeCoefficient(142,-13);
    cout<<"After adding terms, p is:    "<<p<<endl;

	//Testing degree()
	cout<<"the degree of p1 is:    "<<p.degree()<<endl;

	//Testing coefficient()
	cout<<"The coefficient of the 7th power term is:    "<<p.coefficient(7)<<endl;
	cout<<"The coefficient of the 9th power term is:    "<<p.coefficient(9)<<endl;
	cout<<"The coefficient of the -13th power term is:    "<<p.coefficient(-13)<<endl;
	cout<<"The coefficient of the 100th power term is:    "<<p.coefficient(100)<<endl;
	cout<<endl;
	
	//Testing the copy constructor
	Polynomial p2(p);
	cout<<"After using the copy constructor, p2 is:    "<<p2<<endl;

	//Testing ==
	cout<<"p==p2:    "<<(p==p2)<<endl;


	//Testing changeCoefficient for removing(First term, middle term, last term)
	p2.changeCoefficient(0,12);
	p2.changeCoefficient(0,-1);
	p2.changeCoefficient(0,-13);
	p2.changeCoefficient(0,5);
	cout<<"After removing some terms, p2 is:    "<<p2<<endl;

	//Testing changeCoefficient for changing coefficients
	p2.changeCoefficient(999,7);
	cout<<"After changing a coefficient of the power 7 term, p2 is:    "<<p2<<endl;

	//Testing the = operator
	Polynomial p3=p;
	cout<<"p1 is:    "<<p<<endl;
	cout<<"Polynomial p3=p is:    "<<p3<<endl;

	//Testing the != operator
	cout<<"p3!=p2:    "<<(p3!=p2)<<endl<<endl;
	
	//Testing +, -, += and -= using the same data to see if the results are the same
	Polynomial p4;
	p4.changeCoefficient(10,10);
	p4.changeCoefficient(77,94);
	p4.changeCoefficient(-43,12);
	p4.changeCoefficient(-164,7);
    cout<<"p+p4=    "<<(p+p4)<<endl<<endl;
	cout<<"p-p4=    "<<(p-p4)<<endl<<endl;
	cout<<"p+=p4 is:    "<<(p+=p4)<<endl<<endl;
	p-=p4;//to undo the += above
	cout<<"p-=p4 is:    "<<(p-=p4)<<endl<<endl;


	//More + and - testing 
	Polynomial p5;
	p5.changeCoefficient(4.5,10);
	p5.changeCoefficient(32,-2);
	p5.changeCoefficient(54.32,6);
	p5.changeCoefficient(98.9,1);
	p5.changeCoefficient(24.41,14);

	Polynomial p6;
	p6.changeCoefficient(4.5,10);
	p6.changeCoefficient(-32,-2);
	p6.changeCoefficient(43.15,22);
	p6.changeCoefficient(38.3,18);
	p6.changeCoefficient(24.41,14);

	Polynomial p7;
	p7.changeCoefficient(21.11,20);
	p7.changeCoefficient(-32,-82);
	p7.changeCoefficient(64.96,14);
	p7.changeCoefficient(32.24,77);
	p7.changeCoefficient(54.71,100);
	
	cout<<"p5 is:    "<<p5<<endl;
	cout<<"p6 is:    "<<p6<<endl;
	cout<<"p7 is:    "<<p7<<endl;


	cout<<"p5+p6 is:    "<<(p5+p6)<<endl;
	cout<<"p5+p7 is:    "<<(p5+p7)<<endl;
	cout<<"p7+p6 is:    "<<(p7+p6)<<endl;

	cout<<"p5-p6 is:    "<<(p5-p6)<<endl;
	cout<<"p5-p7 is:    "<<(p5-p7)<<endl;
	cout<<"p7-p6 is:    "<<(p7-p6)<<endl;

	cout<<"-------End of my Driver--------"<<endl<<endl<<endl<<endl;


///////End of my Driver//////////////
    return 0;

}