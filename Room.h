//Room.cpp file
//Description: This class models rooms for a hotel
//Author: Aaryan Gupta

#ifndef ROOM_H
#define ROOM_H

using namespace std;

//this class models rooms for a hotel. A hotel can have rooms wiht different number of beds
//for example with 1 bed, 2 beds and 3 beds. 
class Room{

	public:

		//default contructor
		Room();

		//constructor that sets initial values.
		Room(string a, string b, string c,  int d);

		//copy constructor
		Room(const Room &r);

		//destrcutor
		~Room();

		//getter methods
		int getBeds();
		string getCheckin();
		string getCheckout();
		

	private:
		string customerID;
		string checkin;
		string checkout;
		int beds;
};

#endif
