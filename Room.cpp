//Room.cpp file
//Description: This progam implements the class in Room.h file.
//Author: Aaryan Gupta
//Creation Date: May 22, 2021

#include<iostream>
#include "Room.h"
using namespace std;

//default constructor
Room::Room(){

	customerID = "";
	checkin = "";
	checkout = "";
	beds = 0;
}

//constructor to set the initial values
Room::Room(string a, string b, string c,  int d){

	customerID = a;
	checkin = b;
	checkout = c;
	beds = d;
}


Room::Room(const Room &r){

	customerID = r.customerID;
	checkin = r.checkin;
	checkout = r.checkout;
	beds = r.beds;

}

//destrcutor
Room::~Room(){

}


//getter method
int Room::getBeds(){

	return beds;

}

//getter method
string Room::getCheckin(){

	return checkin;

}


//getter method
string Room::getCheckout(){

	return checkout;

}

