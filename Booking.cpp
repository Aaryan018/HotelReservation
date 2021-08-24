//Booking.cpp file
//Description: This class models a hotel reservation system that books hotel rooms for customers.
//Author: Aaryan Gupta
//Creation Date: May 13, 2021

#include<iostream>
#include<fstream>
#include <stdexcept>
#include <string>
#include "Customer.h"
#include "Room.h"
#include "SLL.h"

using namespace std;

//current date	
static int currentDay = 1;
static int currentMonth = 1;
static int currentYear = 2018;

//number of customers serviced
static int customerServiced = 0;

//count to keep in check the rooms booked in the hotel
static int room1 = 100;
static int room2 = 50;
static int room3 = 30;


//this function returs true if the beds are available for the customer and false is no beds are available
bool bedsavailable(int bedsReq){

	int b = (1 * room1) + (2 * room2) + (3 * room3);

	if(b >= bedsReq){
		return true;
	}
	else{
		return false;
	}

}

//this function checks if the rooms are available with the current number of beds required by the customer.
//returns true if room is available and false if not.
bool roomAvailable(int i, int j, int k){

	if((room3 >= i) && (room2 >= j) && (room1 >= k)){
		return true;
	}
	else{
		return false;
	}

}


//this function books the rooms for the customer by creating nodes in the linked for the rooms booked. 
void finallyBookRoom(int i, int j, int k, Customer c, SLL<Room> list1, SLL<Room> list2, SLL<Room> list3){

	int x = i;
	int y = j;
	int z = k;

	while(x > 0){

		Room r(c.getcid(), c.getCheckinDate(), c.getCheckoutDate(), c.getBedsReq());
		list3.addLast(r);
		x--;

	}

	while(y > 0){

		Room r(c.getcid(), c.getCheckinDate(), c.getCheckoutDate(), c.getBedsReq());
		list2.addLast(r);	
		y--;

	}

	while(z > 0){

		Room r(c.getcid(), c.getCheckinDate(), c.getCheckoutDate(), c.getBedsReq());
		list1.addLast(r);
		z--;

	}

	//keeping check how many rooms are available in the hotel.
	room3 = room3 - i;
	room2 = room2 - j;
	room1 = room1 - k;


}


//this function generates different combination  which rooms can be booked by the customer based 
//on the number of beds required. 
void roomBook(Customer c, SLL<Room> list1, SLL<Room> list2, SLL<Room> list3){

	int n = c.getBedsReq();
	bool done = false;
	//cout << n;

	int i, j, k;
	int a, b;
	for(i = n/3; i >= 0; i--){

		a = n - (i*3);

		for(j = a/2; j >= 0; j--){
			k = a - (j * 2);
		
			if(roomAvailable(i, j, k)){
				finallyBookRoom(i, j, k, c, list1, list2, list3);
				customerServiced++;
				done = true;
				cout << customerServiced << endl;
				break;
			}

		}

		if(done == true){
				break;
		}

	}
		

}

//this function calculates the checkout date for customers by adding the current date to the duration of the stay. It returns
//a string that is the checkout date. 
string findCheckoutDate(int day, int month, int year, int duration){

	int sum = day + duration;
	int newDay = 0, newMonth = 0;

	if(sum > 28){
		if(month == 2){
			newDay = duration - 28 + day;
			newMonth = month + 1;
		}
		else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
			if(sum <= 31){
				newDay = day + duration;
				newMonth = month;
			}
			else if(sum > 31){
				newDay = duration - 31 + day;
				newMonth = month + 1;
			}
		}
		else if(month == 4 || month == 6 || month == 9 || month == 11){
			if(sum <= 30){
				newDay = day + duration;
				newMonth = month;
			}
			else if(sum > 30){
				newDay = duration - 30 + day;
				newMonth = month + 1;
			}
		}
	}
	else{
		newDay = day + duration;
		newMonth = month;
	}

	return to_string(newDay) + "/" + to_string(newMonth) + "/" + to_string(year);

}

//this function finds the new date based on the current date. As different months have different number of days, it uses a 
//combination of if else statements.
void todayNewDate(){

	if(currentMonth == 1 || currentMonth == 3 || currentMonth == 5 || currentMonth == 7 || currentMonth == 8 || currentMonth == 10 ||currentMonth == 12){
		if(currentDay == 31){
			currentDay = 1;
			currentMonth++;
		}
		else{
			currentDay++;
		}
	}
	else if(currentMonth == 4 || currentMonth == 6 || currentMonth == 9 || currentMonth == 11){
		if(currentDay == 30){
			currentDay = 1;
			currentMonth++;
		}
		else{
			currentDay++;
		}
	}
	else if(currentMonth == 2){
		if(currentDay == 28){
			currentDay = 1;
			currentMonth++;
		}
		else{
			currentDay++;
		}
	}

}


//this function updates the current date. The new date is requiered to compare it with the checkout date of the customers. 
void dateUpdate(string inDate){

	string today = to_string(currentDay) + "/" + to_string(currentMonth) + "/" + to_string(currentYear);

	if(today != inDate){

		todayNewDate();

	}
}


//this function empties the rooms of the hotel once the checkout date of customer is equal to the current date. 
void emptyRooms(SLL<Room> list1, SLL<Room> list2, SLL<Room> list3, string inDate){

	int a = 0;
	int b = 0;
	int c = 0;

	string today = to_string(currentDay) + "/" + to_string(currentMonth) + "/" + to_string(currentYear);


	for (Iterator<Room> itr = list1.begin();
	       	itr != list1.end(); ++itr) 
			if(itr.content().getCheckout() == inDate){
					
				list1.removeRoom(itr);
				c++;
			}


	

	for (Iterator<Room> itr = list2.begin();
	       	itr != list2.end(); ++itr) 
			if(itr.content().getCheckout() == inDate){
				list2.removeRoom(itr);
				b++;
			} 
		
	for (Iterator<Room> itr = list3.begin();
	       	itr != list3.end(); ++itr) 
			if(itr.content().getCheckout() == inDate){
				list3.removeRoom(itr);
				a++;
			} 
	
	
	
	room1 += c;
	room2 += b;
	room3 += a;


}

//main function initiates the program by reading the customer information from the Customers.txt file and calling various functions
//to book rooms in the hotel.
int main(){


	SLL<Room> list1;
	SLL<Room> list2;
	SLL<Room> list3;

	int i = 0;

	ifstream in;
	in.open("Customers.txt");

	if(in.is_open()){
		char y;
		string x; // helper variable
		string id;
		string checkin = "";
		string checkout = "";
		int beds;
		int duration;
		int day, month, year;

		while(!in.eof()){
			checkin = "";
			in >> day;
			in >> y;
			in >> month;
			in >> y;
			in >> year;

			getline(in, x, ' ');
			getline(in, id, ',');
			getline(in, x, ' ');

			in >> beds;
			getline(in, x, ' ');

			in >> duration;

			checkin += to_string(day) + "/" + to_string(month) + "/" + to_string(year);

			checkout = findCheckoutDate(day, month, year, duration);
			Customer c(checkin, id, beds, duration, checkout);

			dateUpdate(c.getCheckinDate());
			
			emptyRooms(list1, list2, list3, checkin);

			if(bedsavailable(beds)){

				roomBook(c, list1, list2, list3);

			}

			i++;
		}
	}

	cout << customerServiced << endl;


}