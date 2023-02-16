#include <iostream>
#include "A5-23110058.h"
#include <string.h>
void Booking::book(string location, int total_guests, string booking_d, string start_occ, string end_occ, int days, string name, string phone, string CNIC) {
	type = location;
	num_guests = total_guests;
	booking_date = booking_d;
	start_occupancy = start_occ;
	end_occupancy = end_occ;
	total_days_booked = days;
	bookers_name = name;
	bookers_CNIC = CNIC;
	bookers_phone = phone;
	status = "B";
}

void Booking::change_status() {
	if(status == "B") {
		status = "F";
	}
	else {
		status = "B";
	}
}

void Swat::init() {
	location = "Swat";
	type = "Suites";
	total_flats = 4;
	occupancy_per_flat = 4;
	available_flats = 4;
	rate_per_night = 10000;
}

void Gilgit::init() {
	location = "Gilgit";
	type = "Hotel";
	total_rooms = 10;
	occupancy_per_room = 2;
	rate_per_night = 4000;
}
Booking prompt_booking(string type) {
		Booking b;
		string book_date, start_occ, end_occ, name, phone, cnic;
		int total_days, total_guests;
		cout << "Enter your booking date:\n";
		cin >> book_date;
		cout << "Enter total_guests\n";
		cin >> total_guests;
		cout << "Enter your occupation start date\n";
		cin >> start_occ;
		cout << "Enter occupation end date\n";
		cin >> end_occ;
		cout << "Enter total days of stay\n";
		cin >> total_days;
		cout << "Enter your Name\n";
		cin >> name;
		cout << "Enter phone number\n";
		cin >> phone;
		cout << "Enter ID card number\n";
		cin >> cnic;
		b.book(type, total_guests, book_date, start_occ, end_occ, total_days, name, phone, cnic);
		return b;

}

bool check_date_between(string date, string start, string end) {
		int  day = atoi(date.substr(0,4).c_str());
		int  month = atoi(date.substr(4,2).c_str());
		int  year = atoi(date.substr(6,4).c_str());
		int start_day = atoi(start.substr(0,4).c_str());
		int start_month = atoi(start.substr(4,2).c_str());
		int start_year = atoi(start.substr(6,4).c_str());
		int end_day = atoi(end.substr(0,4).c_str());
		int end_month = atoi(end.substr(4,2).c_str());
		int end_year = atoi(end.substr(6,4).c_str());
		if(day >= start_day && day <= end_day && month >=start_month && month <=end_month && year >=start_year && year <=end_year) {
		
		return true;
	}
return false;
}

int main() {
Gilgit Gilgit;
Gilgit.init();
Swat Swat;
Swat.init();
while(1) {
cout << "Press 1 for Room Reservation" << endl;
cout << "Press 2 for Administrative Operations" << endl;
cout << "Press 3 to quit" << endl;

int input;
cin >> input;
if(input == 1) { //staff
	int options;
	cout << "Press 1 for Queries" << endl;
	cout << "Press 2 for Reservations" << endl;
	cout << "Press 3 to Checkout OR Cancel" << endl;
	cout << "Press 4 to Modify Reservation" << endl;
	cin >> options;
	if(options == 1) {				//Query
		string city;
		cout << "Enter 'S' to search in Swat or 'G' to search in Gilgit:\n";
		cin >> city;
		cout << "Enter your dates:\n";
		string date;
		cin >>date;
			if(city == "S" || city == "s") {
			int total_available = Swat.total_flats;
			for(int i = 0; i < Swat.current_bookings.size(); i++) {
				Booking b = Swat.current_bookings[i];
				if(check_date_between(date, b.start_occupancy, b.end_occupancy) == true) {
					total_available--;
				}
			}
			cout << "Total flats available on your given date are " << total_available;
		}
		else {
			int total_available = Gilgit.total_rooms;
			for(int i = 0; i < Gilgit.current_bookings.size(); i++) {
				Booking b = Gilgit.current_bookings[i];
				if(check_date_between(date, b.start_occupancy, b.end_occupancy) == true) {
					total_available--;
				}

			}
			cout << "Total rooms available on your given date are " << total_available << endl;
		}
	}
	else if (options == 2) {
		string city, date;
		cout << "Enter 'S' to reserve in Swat or 'G' to reserve in Gilgit:\n";
		cin >> city;
		cout << "Enter your reservation date\n";
		cin >> date;
		if(city == "S" || city == "s") {
		int total_available = Swat.total_flats;
			for(int i = 0; i < Swat.current_bookings.size(); i++) {
				Booking b = Swat.current_bookings[i];
				if(check_date_between(date, b.start_occupancy, b.end_occupancy) == true) {
					total_available--;
				}
			}
		if(total_available == 0) {					//add to waiting
				if(Swat.waiting_list.size() <=5) {
				Booking b = prompt_booking("Swat");
				Swat.waiting_list.push_back(b);
				}
				else {
					cout << "The waiting list is currently full";
				}
			}
		else if (total_available > 0) {
			Booking b = prompt_booking("Swat");
			b.number = total_available;
			cout <<total_available;
			Swat.current_bookings.push_back(b);
			}
		}
		else if(city == "G" || city == "g" ){
			int total_available = Gilgit.total_rooms;
			for(int i = 0; i < Gilgit.current_bookings.size(); i++) {
				Booking b = Gilgit.current_bookings[i];
				if(check_date_between(date, b.start_occupancy, b.end_occupancy) == true) {
					total_available--;
				}
			}
		if(total_available == 0) {					//add to waiting
				if(Gilgit.waiting_list.size() <=5) {
				Booking b = prompt_booking("Gilgit");
				Gilgit.waiting_list.push_back(b);
				}
				else {
					cout << "The waiting list is currently full";
				}
			}
		else if (total_available > 0) {
			Booking b = prompt_booking("Gilgit");
			b.number = total_available;
			cout <<total_available;
			Gilgit.current_bookings.push_back(b);
			}
		}
	}

	else if (options == 3) {
		string city, cnic;
		cout << "Enter S to checkout from flat or G to checkout from room:\n";
		cin >> city;
		cout << "Enter booker's cnic:\n";
		cin >> cnic;
		if(city == "s" || city == "S") {
			for(int i = 0; i < Swat.current_bookings.size(); i++) {
				Booking b = Swat.current_bookings[i];
				if(b.bookers_CNIC == cnic) {
					Swat.current_bookings.erase(Swat.current_bookings.begin()+ i);
				}
			}
		}
		else if (city == "g" || city == "G") {
				for(int i = 0; i < Gilgit.current_bookings.size(); i++) {
				Booking b = Gilgit.current_bookings[i];
				if(b.bookers_CNIC == cnic) {
					Gilgit.current_bookings.erase(Swat.current_bookings.begin()+ i);
				}
			}
		}

	}

	else if (options == 4) {
	string city, cnic;
	cout << "Enter S to modify flat reservation or G to modify room:\n";
	cin >> city;
	cout << "Enter booker's cnic for modification purpose:\n";
	cin >> cnic;
	if(city == "s" || city == "S") {	
			for(int i = 0; i < Swat.current_bookings.size(); i++) {
				Booking b = Swat.current_bookings[i];
				if(b.bookers_CNIC == cnic) {
					cout << "You will now be prompted to re-enter info for modification";
					Booking new_booking = prompt_booking("Swat");
					Swat.current_bookings[i] = new_booking;
				}
			}
		}
	else if (city == "g" || city == "G") {
		for(int i = 0; i < Gilgit.current_bookings.size(); i++) {
				Booking b = Gilgit.current_bookings[i];
				if(b.bookers_CNIC == cnic) {
					cout << "You will now be prompted to re-enter info for modification";
					Booking new_booking = prompt_booking("Gilgit");
					Gilgit.current_bookings[i] = new_booking;
				}
			}
		}
	}
	else {
		cout << "Please enter a valid option:\n";
		cin >> options;
	}
}

else if(input == 2) { //admin

	int options;
	cout << "Enter 1 for currently empty rooms/flats report" <<endl;
	cout << "Enter 2 for currently reserved rooms/flats report" <<endl;
	cout << "Enter 3 for waiting list report" <<endl;
	cout << "Enter 4 for income report" <<endl;
	cin >> options;
	

	if(options == 1) {
	cout << "REPORT OF CURRENTLY EMPTY FLATS IN SWAT" <<endl;
	vector <bool> flats;
	for(int b = 0; b < 4; b++) {
		flats.push_back(false);
	}
		for(int i = 0; i < Swat.current_bookings.size(); i++) {
			Booking b;
			b = Swat.current_bookings[i];
			cout <<b.number;
			flats[b.number-1] = true;
		}
		for (int k = 0; k < flats.size(); k++) {
			if(flats[k] == false) {
			cout << "Empty flat number is: " << k+1 <<endl;
			}
		}
	cout << "-------------------------------------------------" <<endl;
	cout << "REPORT OF CURRENTLY EMPTY ROOMS IN GILGIT" <<endl;
	vector <bool> rooms;
	for(int b = 0; b < 10; b++) {
		rooms.push_back(false);
	}
		for(int j = 0; j < Gilgit.current_bookings.size(); j++) {
			Booking b;
			b = Gilgit.current_bookings[j];
			rooms[b.number-1] = true;
		}
		for (int k = 0; k < rooms.size(); k++) {
			if(rooms[k] == false) {
			cout << "Empty room number is: " << k+1<<endl;
			}
		}
	cout << "-------------------------------------------------" <<endl;

	}
	else if(options == 2) {
		cout << "REPORT OF CURRENTLY RESERVED FLATS IN SWAT" <<endl;
		int total_in_flats = 0;
		for(int i = 0; i < Swat.current_bookings.size(); i++) {
			Booking b;
			b = Swat.current_bookings[i];
			cout << "Flat Number: " << b.number <<endl;
			cout << "Guests in flat: " << b.num_guests<< endl;
			total_in_flats = total_in_flats + b.num_guests;
			cout << "-------------------------------" <<endl;
		}
		cout << "Total guests in flats are: " << total_in_flats;
		cout << "-------------------------------" <<endl;
		cout << "REPORT OF CURRENTLY RESERVED ROOMS IN GILGIT" <<endl;
		int total_in_rooms =0;
		for(int j = 0; j < Gilgit.current_bookings.size(); j++) {
			Booking b;
			b = Gilgit.current_bookings[j];
			cout << "Room Number: " << b.number <<endl;
			cout << "Guests in room: " << b.num_guests<< endl;
			total_in_rooms = total_in_rooms + b.num_guests;
			cout << "-------------------------------" <<endl;
		}
		cout << "Total guests in rooms are: " << total_in_rooms;
		cout << "-------------------------------" <<endl;
		cout << "TOTAL GUESTS (GRAND TOTAL): " << total_in_rooms + total_in_flats << endl; 
	}
	else if (options == 3) {
		cout << "REPORT OF WAITLIST IN SWAT" <<endl;
		for(int i = 0; i < Swat.waiting_list.size(); i++) {
			Booking b;
			b = Swat.current_bookings[i]; 
			cout << "Booking Date: " << b.booking_date<< endl;
			cout << "Occupancy begins:" << b.start_occupancy<< endl;
			cout << "Occupancy ends:" << b.end_occupancy<< endl;
			cout << "Bookers Name: " << b.bookers_name<< endl;
			cout << "Bookers CNIC: " << b.bookers_CNIC<< endl;
			cout << "Bookers Phone: " << b.bookers_phone<< endl;
			cout << "Total Guests: " << b.num_guests<< endl;
			cout << "-------------------------------" <<endl;
		}
		cout << "REPORT OF WAITLIST IN GILGIT" <<endl;
		for(int j = 0; j < Gilgit.waiting_list.size(); j++) {
			Booking b;
			b = Gilgit.current_bookings[j]; 
			cout << "Booking Date: " << b.booking_date<< endl;
			cout << "Occupancy begins: " << b.start_occupancy<< endl;
			cout << "Occupancy ends: " << b.end_occupancy<< endl;
			cout << "Bookers Name: " << b.bookers_name<< endl;
			cout << "Bookers CNIC: " << b.bookers_CNIC<< endl;
			cout << "Bookers Phone: " << b.bookers_phone<< endl;
			cout << "Total Guests: " << b.num_guests<< endl;
			cout << "-------------------------------" <<endl;
		}
	}

	else if(options == 4) {
		cout << "INCOME REPORT SWAT" <<endl;
		int total_swat = 0;
		for(int i = 0; i < Swat.current_bookings.size(); i++) {
			Booking b;
			b = Swat.current_bookings[i];
			total_swat = total_swat + b.total_days_booked*Swat.rate_per_night;
		}
		cout << "Total income from Swat: " << "PKR "  << total_swat <<endl;   
		cout << "---------------------------"<< endl;
		cout << "INCOME REPORT GILGIT" <<endl;
		int total_gilgit = 0;
		for(int i = 0; i < Gilgit.current_bookings.size(); i++) {
			Booking b;
			b = Gilgit.current_bookings[i];
			total_gilgit = total_gilgit + b.total_days_booked*Gilgit.rate_per_night;
		}
		cout << "Total income from Gilgit: " << "PKR "  << total_gilgit <<endl; 
		cout << "---------------------------"<< endl;
		cout << "GRAND TOTAL";
		cout << "PKR: "<< total_gilgit+ total_swat<< endl;

	}


}
	else {
		break;
	}
}
return 0;
}