#ifndef A5_H
#define A5_H
#include <vector>
#include <string>
using namespace std;
class Occupancy {
	public:
	bool booked;
	string booking_date;
	int booked_days;
	string start_occupancy;
	string end_occupancy;
};


class Booking {
	public:
	string booking_date;
	int booking_day;
	int booking_month;
	int booking_year;
	string start_occupancy;
	string end_occupancy;
	int total_days_booked;
	string bookers_name;
	string bookers_CNIC;
	string bookers_phone;
	int num_guests;
	string type;
	string status;
	void book(string type, int total_guests, string booking_date, string start_occupancy, string end_occupancy, int days, string bookers_name, string bookers_phone, string bookers_CNIC);
	void change_status();
	int number;
};  

class Accomodation 
{
public: 
	vector <Booking> current_bookings;
	vector <Booking> waiting_list;
};

class Swat: public Accomodation {
public:
	string location;
	string type;
	int total_flats;
	int occupancy_per_flat;
	int available_flats;
	int rate_per_night;
	void init();
};

class Gilgit : public Accomodation {
public:
	string location;
	string type;
	int total_rooms;
	int occupancy_per_room;
	int rate_per_night;
	void init();
};

#endif