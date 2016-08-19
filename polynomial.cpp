//Elias Muche 
//3/29/16
//Program 1:Polynomials 

#include "polynomial.h"
#include <iostream>
#include <string>
using namespace std;

//Ostream << overload 
//prints out a polynomial object
//Pre-conditions:p.head must not be null
//Post-conditions:The poly param will not be changed after being printed 
ostream& operator<<( ostream &output, const Polynomial& p ){
   bool minus=false;//will determine if a minus sign is printed 
   bool constant=false;//to handle constant term printing (to print at the end)
   double constCoeff=0.0;//will save the value of the constant term 
   int constPower=0;//the power of the constant term
   if (p.head==NULL||p.size==0){//if there are no terms or if there are problems with the param
       output<<"0"<<endl;//print 0 and stop 
	   return output; 
	}
	Polynomial:: Term *traverse;
	traverse=p.head->next;//otherwise create a temp term
	if(traverse->power==0){//if the first term is a constant term (this means negative power terms follow it)
		constant=true;//remember it 
		constCoeff=traverse->coeff;//save the value so we can print at the end
	}
	else if(traverse->power==1){//if the first term has a 1 power then print coeffx 
	    if(traverse->coeff==1){//if the coefficient is 1 
		output<<"x";//just print x
	    }
	    else{
	        output<<traverse->coeff<<"x";//otheriwse print coeffx       
	    } 
	}
	else if(traverse->power==-1){//if the first term has a -1 power 
	    output<<traverse->coeff<<"/x";//print coeff/x
	}
	else if(traverse->power<1){//if the first term has a negative power
	    output<<traverse->coeff<<"/x^"<<(traverse->power)*(-1);//print coeff/x^power 
	}
	else{//for powers>1 
	    if(traverse->coeff==1){//if the coeff is 1 
	        output<<"x^"<<traverse->power;//just print x 
   	    }
	    else{//coeff is not 1
	        output<<traverse->coeff<<"x^"<<traverse->power;//print coeffx^power  
	    }
	}
	if(traverse->next==p.head){//if theres only one term then stop
	    output<<endl;
	    traverse=NULL;//for memory leaks
	    delete traverse;//for memory leaks
	    return output;
	}
	if(traverse->next->coeff<0 && traverse->next->power!=0){//if the first term wasn't constant and the next term's coeff is negative 
	    output<<" - ";//print a -
		minus=true;
	}
	else if(traverse->next->coeff>0 && traverse->next->power!=0){//if the first term wasn't a constant and the next terms' coeff is positive
		output<<" + ";//othwerise print a +
	}
	traverse=traverse->next;//move on to the next term 
	
	    
	while(traverse!=p.head){//while we haven't reached the end of the polynomial 
	    if(traverse->power==0){//if the term is constant 
	       constant=true;//remember it 
		   constCoeff=traverse->coeff;//save the value so we can print it at the end
	    }
	    else if(traverse->power==1){//if the power is 1 
			if(traverse->coeff==1){//if the coeff is 1 
		    	output<<"x";//just print x
			}
			else{
	        	output<<traverse->coeff<<"x";//print coeffx
			}
	    }
	    else if(traverse->power==-1){//if the power is -1
	        if(minus==false){//if we didn't print a minus the term before this 
				output<<traverse->coeff<<"/x";//print coeff/x 
			}   
			else{//if we did print a minus sign the term before this
			    output<<(traverse->coeff)*(-1)<<"/x";//print coeff/x but flip the sign of coeff
			}
	    }
	    
	    else if(traverse->power<1){//if the power<1 
		    if(minus==false){//if we didn't print a minus the term before this 	
				output<<traverse->coeff<<"/x^"<<(traverse->power)*(-1);//print coeff/x^power 
			}
			else{//if we did print a minus sign the term before this 
				output<<(traverse->coeff)*(-1)<<"/x^"<<(traverse->power)*(-1);//print coeff/x^power but flip the sign of coeff
			}
	    }
	    else{//if the power>1
	        if(traverse->coeff==1){//if coeff is 1
		    	output<<"x^"<<traverse->power;//just print x^power
			}
			else{//coeff is not 1 
		    	if(minus==false){//if we didn't print a minus sign the term before this 
					output<<traverse->coeff<<"x^"<<traverse->power;//print coeffx^power
				}
				else{//if we did print a minus sign the term before this 
					output<<(traverse->coeff)*(-1)<<"x^"<<traverse->power;//print coeffx^power but flip the sign of coeff
				}
			}
	    }
	    
	    if(traverse->next==p.head){//if that term was the last one 
	    	if(constant==true){//if we ran into a constant term along the way 
		    	if(constCoeff<0){//if the coeff was negative 
					output<<" - "<<(constCoeff)*(-1);//print a minus sign and coeff(sign is flipped)
				}
				else{//if the coeff was positive
				    output<<" + "<<constCoeff;//print the value
				}
			}
		//now we return after taking care of memory leaks
			output<<endl;
	   	    traverse=NULL;//for memory leaks 
	    	delete traverse;//for memory leaks 
	    	return output;
	   
	    }
		//at this point the previous term was not the last 
		if(traverse->next->coeff>0 && traverse->next->power!=0){//if the next term isn't constant and the coeff is positive 
	    	output<<" + ";//print a +
			minus=false;//remember that we printed a plus sign
		}
		else if(traverse->next->coeff<0 && traverse->next->power!=0){//if the next term isn't constant and the coeff is negative
			output<<" - ";//print a -
			minus=true;//remember that we printed a minus sign
		}
	    traverse=traverse->next;//go on to the next term
	}
	traverse=NULL;//for memory leaks
	delete traverse;//for memory leaks
	return output;

}




//Default constructor initializes the object
//Pre-conditions:no preconditions
//Post-condition: A monomial of 0x^0 is created (dummy header)
Polynomial::Polynomial(){
	head=new Term;//create a dummy head 
	head->next=head;//circular 
	head->prev=head;//circular
	head->power=0;//initialize 
	head->coeff=0.0;//initialize 
	size=0;//initialize 
}

//Copy constructor creates a deep copy
//Pre-conditions: head must not be null
//Post-conditions: The terms of this and the param should match
Polynomial::Polynomial(const Polynomial &poly){
	
	head=new Term;//initialize 	
    head->next=head;//circular 
    head->prev=head;//circular
    head->power=0;//initialize 
    head->coeff=0.0;//initialize 
    size=0;//intitialize 
    *this=poly;//use the = assignment
	
}

//Destructor deallocates the links of the poly
//Pre-conditions:there must be at least head to delete (it can't be null) 
//Post-conditions:there should be no terms after the destructor is finished running 
Polynomial::~Polynomial(){
    clear();//remove all the terms 
    delete head;//remove head 
    head=NULL;//for memory leaks 
}

//Returns the value of the leading term's exponent
//Pre-conditions:head must not be null
//Post-conditions:a number will be returned 
int Polynomial::degree()const{
	return (size==0)? 0:head->next->power;//return head->next's power or 0 if there are no terms
}

//Returns the coefficient that correspondes to the given power or 0 if there's no such term
//Pre-conditions:head must not be null
//Post-conditions:a value will always be returned (0 or the corresponding coefficient)
double Polynomial::coefficient(const int power)const{
	Term *traverse=head->next;//create a traversal node 
	while(traverse!=head){//while the end hasn't been reached 
	    if(traverse->power==power){//if the current term's exponent is the one we're looking for 
	        return traverse->coeff;//return the corresponding coeff 
	    }
	    traverse=traverse->next;//otherwise move on to the next term;
	}
	
	return 0.0;//the end has been reached so there's no such term 
}

//This method either changes the coefficient of a specified term, calls insert, or calls remove 
//If The coeff param is 0, then the method attempts to delete the term
//If the coeff param isn't 0, the method checks if the power already exists(it will then change the coeff)
//If it didnt change the coeff, insert is called
//The method returns the result of the private helper method it calls (true or false for deleting/inserting) or true if it changed a coeff 
//Pre-conditions:head must not be null 
//Post-conditions:a term will either be added, removed, or have the coefficient changed 
bool Polynomial:: changeCoefficient(const double newCoefficient, const int power ){
	if(newCoefficient==0){//if the coeff is changed to 0 
	    Term *pos=new Term;//create a temp term 
	    pos->coeff=0.0;//set the coeff value 
	    pos->power=power;//set the power value 
	    bool removeTerm=remove(pos);//attempt to remove the term that contains these values 
	    delete pos;//for memory leaks 
	    pos=NULL;//for memory leaks 
	    return removeTerm;
	}
	Term *traversal=head->next;//create a traversal term
	while(traversal!=head){//while the end hasn't been reached 
	    if(traversal->power==power){//if the current term has the same power as the param 
  	        traversal->coeff=newCoefficient;//just change the coeff and return 
			traversal=NULL;//for memory leaks 
			delete traversal;//for memory leaks 
			return true;
		
        }
	    traversal=traversal->next;//otherwise advance to the next term
	}
	//at this point the term doesnt currently exist 
	traversal=NULL;//for memory leaks
	delete traversal;//for memory leaks 

 if(size==0){//adding the first term is a special case 
	    head->next=new Term;//create a new term that is linked to head
	    head->next->coeff=newCoefficient;//set the coefficient 
	    head->next->power=power;//set the power
	    head->prev=head->next;//link the prev of head with the new term 
            
	    head->next->prev=head;//link the new term with head 
	    head->next->next=head;//link the new term with head going the other way
	
			    
	    size++;//increment the size
	    return true;
	}
	else if(size==1){//for a poly of 1 term 
	 	if(head->next->power>power ){//if prev has a higher power 
	        Term *newTerm=new Term;//create a new term 
		    newTerm->coeff=newCoefficient;//set the value
		    newTerm->power=power;//set the value 

		    newTerm->next=head;//place the new term to the right of prev 
		    newTerm->prev=head->next;//place the new term to the right of prev 
		
		    newTerm->next->prev=newTerm;//link back		
		    newTerm->prev->next=newTerm;//link back
		
		    size++;//increment the size 
		    newTerm=NULL;//for memory leaks 
		    delete newTerm;//for memory leaks 
		    return true;
	        }
	
	        else{//if prev has a lower power 
	            Term *newTerm=new Term;//create a new term
		    newTerm->coeff=newCoefficient;//set the value 
		    newTerm->power=power;//set the value 

		    newTerm->next=head->next;//place the new term to the left of prev 
		    newTerm->prev=head;//place the new term to the left of prev

		    newTerm->next->prev=newTerm;//link back 
		    newTerm->prev->next=newTerm;//link back 
		
		    size++;//increment the size 
		    newTerm=NULL;//for memory leaks 
		    delete newTerm;//for memory leaks 
		    return true;
	        }
	
	}
	return insert(head->next,newCoefficient,power);//if we didnt remove or change a coeff then insert the term
	
}

//+ overload takes two polynomials and creates another polynomial which will store the sum 
//The sum is returned
//Pre-conditions: The parameter must not have a head that is null 
//Post-conditions: The lhs will be returned if the rhs is 0 otherwise the sum is returned
Polynomial Polynomial::operator+(const Polynomial& p)const{
	Polynomial sum(*this);//let this be the current sum 
	Polynomial p2(p);//create a copy of the param

	Term *traverseSum;//create a traversal term for sum 
	Term *traversep2=p2.head->next;//create a traverseal term for p2 
	bool exists=false;//for terms with powers present both in sum and p2 (to combine like terms)
	
	while(traversep2!=p2.head){//for every term in p2 
		exists=false;//assume the term doesn't exist in both poly's 
		traverseSum=sum.head->next;//start at the first term of sum 
		while(traverseSum!=sum.head){//for every term in sum 
			if(traversep2->power==traverseSum->power){//if the current term has common powers in both sum and p2 
			    sum.changeCoefficient(traverseSum->coeff+traversep2->coeff,traverseSum->power);//combine like terms 
				exists=true;//remember that we combined 
			}
			traverseSum=traverseSum->next;//move on to the next term
		}
		//the inner loop finished
		if(!exists){//if we didn't combine like terms 
			 sum.changeCoefficient(traversep2->coeff,traversep2->power);//add p2's term 
		}
		traversep2=traversep2->next;//move on to the next term of p2 
	}

	return sum;
	
}

//- overload takes two polynomials and creates another polynomial which will store the difference 
//The difference is returned
//Pre-conditions: The parameter must not have a head that is null 
//Post-conditions: The lhs will be returned if the rhs is 0 otherwise the difference is returned
Polynomial Polynomial::operator-(const Polynomial &p)const{
	Polynomial negativeSum(p);//create a copy of p
	Term *traverse=negativeSum.head->next;//start at the first term 
	while(traverse!=negativeSum.head){//for every term 
	    negativeSum.changeCoefficient(traverse->coeff*(-1),traverse->power);//flip the sign of coeff 
		traverse=traverse->next;//move on to the next term 
	}
	return (*this+negativeSum);//now call +
}

//Assignemt= overload
//Sets the terms of this to the same terms of p 
//This is returned 
//Pre-conditions:The parameter must have head initialized (even if there are no terms)
//Post-conditions:this should have the exact same data(terms and term values) 
Polynomial& Polynomial::operator=(const Polynomial& p){
	clear();//remove all existing terms
	if(p.size==0){//we are done if there are no terms to add
	    return *this; 
	}
	Term *traverse=p.head->next;//otherwise create a traversal node
	while(traverse!=p.head){//while the end hasnt been reached 
	    changeCoefficient(traverse->coeff,traverse->power);//add p's term
	    traverse=traverse->next;//move on to the next term 
	}
	traverse=NULL;//for memory leaks 
	delete traverse;//for memory leaks 
	return *this;
}
//+= overload takes two polynomials and modifies this to store the sum  
//This is returned
//Pre-conditions:the parameter must not have a head that is null 
//Post-conditions:this will be returned (either unaltered or as the sum)
Polynomial& Polynomial::operator+=(const Polynomial& p){
	return (*this=(*this + p));//use the = and + operators separately 
}

//-= overload takes two polynomials and modifies this to store the difference  
//This is returned
//Pre-conditions:the parameter must not have a head that is null 
//Post-conditions:this will be returned (either unaltered or as the difference)
Polynomial& Polynomial::operator-=(const Polynomial& p){
	return (*this=(*this - p));//use the = and - operators separately 
}

//== overload 
//Returns true if the terms each term matches with each term of the param. Returns false otherwise
//Pre-conditions:there must be a head for this and the param
//Post-conditions: true or false will be returned
bool Polynomial::operator==(const Polynomial& p)const{
	if(size!=p.size){//if the sizes differ 
	    return false;//return false immediately 
	}
	Term *traverse=head->next;//create a traversal term for this 
	Term *traverseP=p.head->next;//create a traversal term for p 
	while(traverse!=head){//while the end hasn't been reached 
	    if(traverse->power!=traverseP->power && traverse->coeff!=traverseP->coeff){//if the current term has a different value 
			traverse=NULL;//for memory leaks 
			delete traverse;//for memory leaks 
			traverseP=NULL;//for memory leaks 
			delete traverseP;//for memory leaks
	        return false;//return false 
	    }
	    traverse=traverse->next;//otherwise move right 
	    traverseP=traverseP->next;//otherwise move right 
	}
	traverse=NULL;//for memory leaks 
	delete traverse;//for memory leaks 
	traverseP=NULL;//for memory leaks 
	delete traverseP;//for memory leaks
	return true;//at this point we havent returned false so they are equal
}

//!= overload 
//Returns the negation of == (true if they're not equal and false if they are)
//Pre-conditions:there must be a head for this and p 
//Post-conditions:true or false will be returned
bool Polynomial:: operator!=(const Polynomial &p)const{
	return !(*this==p );//return the negation of ==
}

	
//This method inserts a new term with the params as values
//Method returns true 
//Pre-conditions:The term passed in should not be the dummy head 
//Post-conditions:There will be a new term inserted
bool Polynomial:: insert( Term* prev, const double newCoefficient, const int power ){
   	bool wentBack=false;//will track if we moved left 
	bool wentForward=false;//will track if we moved right
	Term *lastPrev=prev;//will remember the last term
	while(prev!=head){//while prev is not head 
	    if(prev->power>power){//if prev's power is bigger 
			if(wentBack==true){//and we have already moved left
				//place a new term after prev 
				Term *newTerm=new Term;//create a new term
				newTerm->coeff=newCoefficient;//set the value 
				newTerm->power=power;//set the value 

				newTerm->next=prev->next;//place the new term to the right of prev 
				newTerm->prev=prev;//place the new term to the right of prev

				newTerm->next->prev=newTerm;//link back 
				newTerm->prev->next=newTerm;//link back 
		
				size++;//increment the size 
				newTerm=NULL;//for memory leaks 
				delete newTerm;//for memory leaks 
				lastPrev=NULL;//for memory leaks 
				delete lastPrev;//for memory leaks
				return true;
			}
			lastPrev=prev;//save the last prev in case we reach the end after moving 
			prev=prev->next;//move right 
			wentForward=true;//remember that we moved right
		}
		else{//if prev's power is smaller 
			if(wentForward==true){//if we already moved forward 
				//place a new term before prev
				Term *newTerm=new Term;//create a new term
				newTerm->coeff=newCoefficient;//set the value 
				newTerm->power=power;//set the value 

				newTerm->next=prev;//place the new term to the left of prev
				newTerm->prev=prev->prev;//place the new term to the left of prev

				newTerm->next->prev=newTerm;//link back 
				newTerm->prev->next=newTerm;//link back 
		
				size++;//increment the size 
				newTerm=NULL;//for memory leaks 
				delete newTerm;//for memory leaks 
				lastPrev=NULL;//for memory leaks 
				delete lastPrev;//for memory leaks
				return true;
			}
			lastPrev=prev;//save the last prev in case we reach the end after moving 
			prev=prev->prev;//move left 
			wentBack=true ;//remember that we moved left 

		}
	        
	}   
	//if we reach this point, that means we are either at the first or last term
	if(lastPrev->next==head ){//if we're at the last term 
		//add a new last term
    	Term *newTerm=new Term;//create a new term
		newTerm->coeff=newCoefficient;//set the value 
		newTerm->power=power;//set the value 

		newTerm->next=head;//place the new term to the left of head 
		newTerm->prev=head->prev;//place the new term to the left of head

		newTerm->next->prev=newTerm;//link back 
		newTerm->prev->next=newTerm;//link back 
		
		size++;//increment the size 
		newTerm=NULL;//for memory leaks 
		delete newTerm;//for memory leaks 
		lastPrev=NULL;//for memory leaks 
		delete lastPrev;//for memory leaks
		return true;

     
	}
	else if(lastPrev->prev==head){//if we're at the first term
		//place a new term before the first term 
    	Term *newTerm=new Term;//create a new term
		newTerm->coeff=newCoefficient;//set the value 
		newTerm->power=power;//set the value 

		newTerm->next=head->next;//place the new term to the left of last prev 
		newTerm->prev=head;//place the new term to the left of last prev

		newTerm->next->prev=newTerm;//link back 
		newTerm->prev->next=newTerm;//link back 
		
		size++;//increment the size 
		newTerm=NULL;//for memory leaks 
		delete newTerm;//for memory leaks
		lastPrev=NULL;//for memory leaks 
		delete lastPrev;//for memory leaks
		return true;
				
	}
	
	    
}


//This method removes a specified term if it exists 
//True is returned if a term is deleted otherwise false is returned
//Pre-conditions:The param passed in should not the dummy head
//Post-conditions:The poly should not be changed unless the specified term exists 
bool Polynomial:: remove( Term* pos ){
	Term *traverse=head->next;//a term that will traverse through the poly
	if(size==0){//do nothing if there are no terms 
	    traverse=NULL;//for memory leaks
	    ///////delete traverse;//for memory leaks
	    return false;
	}  
	else if(size==1){//special case: if there's only 1 term
	    if(pos->power==traverse->power){//and the value is the value we want to delete
			Term *temp=head->next;
			head->next=head;//delink 
			head->prev=head;//delink
		    head->next->prev=head;
			head->prev->next=head;
			delete temp;
			
			size--;//decrement the size 
			traverse=NULL;//for memory leaks 
			//////delete traverse;//for memory leaks 
	        return true;
	    }
	    else{//the current term does not contain the correct value so stop
			traverse=NULL;//for memory leaks 
			/////delete traverse;//for memory leaks 
	        return false;
	    }
	}
	else{//for sizes>1 
	    while(traverse->power!=pos->power){//while the curr term doesnt contain the right value 
            if(traverse==head){//if we're back at the beginning stop 
		    	traverse=NULL;//for memory leaks 
		    	///////delete traverse;//for memory leaks
		    	return false;
			}
			traverse=traverse->next;//move right one term
	    }
	    //at this point we have reached the right term so delete it 
		
	    traverse->prev->next=traverse->next;//link prev with next 
	    traverse->next->prev=traverse->prev;///link next with prev 
	
	    delete traverse;//delete the node 
	    traverse=NULL;//for memory leaks 
	    size--;//decrement the size
	    return true;
	}
	
}

//Helper method repeatidely calls remove 
//Pre-conditions:head must not be null
//Post-conditions:head will be remaining and there should be no terms 
void Polynomial::clear(){
    if(size==0){//do nothing if there are no terms 
        return;
    }
    else if(size==1){//if there's 1 term 
        remove(head->next);//delete it 
		return;
    }
    Term *traverse=head->next->next;//start at the second term 
    while(traverse!=head){//for every term 
        remove(traverse->prev);//delete the term before traverse 
		traverse=traverse->next;
    }
	remove(traverse->prev);//delete the last term
}




