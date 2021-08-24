//Customer.cpp file
//Description: This program implements the class in Customer.h file
//Author: Aaryan Gupta


#include<iostream>
#include "Customer.h"
using namespace std;

//constructor to set up the initial values.
Customer::Customer(string a, string b, int c, int d, string x){
	checkinDate = a;
	cid = b;
	bedsReq = c;
	duration = d;
	checkoutDate = x;
}

//default constructor
Customer::Customer(){
	checkinDate = "";
	cid = "";
	bedsReq = 0;
	duration = 0;
	checkoutDate = "";
}

//copy constuctor
Customer::Customer(const Customer &cu){

	checkinDate = cu.checkinDate;
	cid = cu.cid;
	bedsReq = cu.bedsReq;
	duration = cu.duration;
	checkoutDate = cu.checkoutDate;

}

//destructor
Customer::~Customer(){

}

//getter methods of the class.

int Customer::getDuration(){
	return duration;
}

string Customer::getCheckinDate(){

	return checkinDate;

}

string Customer::getCheckoutDate(){

	return checkoutDate;

}

string Customer::getcid(){

	return cid;

}

int Customer::getBedsReq(){
	return bedsReq;
}
