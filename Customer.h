//Customer.h file
//Description: This class models the customers booking a room in a hotel.
//Author: Aaryan Gupta

#ifndef CUSTOMER_H
#define CUSTOMER_H
using namespace std;

//This class models the customers booking a room in a hotel.
class Customer{

	public:

		//constructor to set up the initial values.
		Customer(string a, string b, int c, int d, string x);

		//default constructor
		Customer();

		//copy constructor
		Customer(const Customer &cu);

		//destrcutor
		~Customer();

		//getter methods
		int getDuration();

		string getCheckinDate();

		string getCheckoutDate();

		int getBedsReq();

		string getcid();

	private:
		
		string checkinDate;
		string cid;
		int bedsReq;
		int duration;
		string checkoutDate;


};

#endif
