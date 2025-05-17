#include <iostream>
#include <string>
using namespace std;

class User {
	string name;
	string cnic;
	string email;
	string password;

public:
	User(string n = "", string c = "", string e = "", string p = "") {
		name = n;
		cnic = c;
		email = e;
		password = p;
	}

	void registerUser(string n = "", string c = "", string e = "", string p = "") {
		name = n;
		cnic = c;
		email = e;
		password = p;
	}

	bool authenticateUser(string e = "", string p = "") {
		return email == e && password == p;
	}

	void profile() {
		cout << "Name:\t" << name << endl;
		cout << "CNIC:\t" << cnic << endl;
		cout << "Email:\t" << email << endl;
		cout << "Password:\t" << password << endl;
	}

	void setname(string n) {
		name = n;
	}

	void setcnic(string c) {
		cnic = c;
	}

	void setemail(string e) {
		email = e;
	}

	void setpassword(string p) {
		password = p;
	}
};

class Product {
	string name;
	string description;
	string category;
	bool availability;
	float price;
	float amount;

public:
	Product() {}

	Product(string n, float p, string d, string c, bool a, float am)
		: name(n), price(p), description(d), category(c), availability(a), amount(am) {}

	void setProduct(string n, float p, string d, string c, bool a, float am) {
		name = n;
		price = p;
		description = d;
		category = c;
		availability = a;
		amount = am;
	}

	void getProduct() {
		cout << "Product Name: " << name << endl;
		cout << "Price: " << price << endl;
		cout << "Description: " << description << endl;
		cout << "Availability: " << (availability ? "Available" : "Not available") << endl;
		cout << "Category: " << category << endl;
	}

	void updateProduct(string newName, float newPrice, string newDescription, bool newAvailability, string newCategory) {
		name = newName;
		price = newPrice;
		description = newDescription;
		availability = newAvailability;
		category = newCategory;
	}
};

int main() {
	cout << "\t\t\t\t***********************************************************\n";
	cout << "\t\t\t\t ******************\tWELCOME TO\t******************\n";
	cout << "\t\t\t\t  *****************\tONLINE STORE\t*****************\n";
	cout << "\t\t\t\t   ****************\tSIMULATION\t****************\n";
	cout << "\t\t\t\t    ***************************************************\n";

	int n = 0, l = 0;
	User u;

	// User login and sign up
	while (1) {
		cout << "press '1' to signup" << endl;
		cout << "press '2' to Login" << endl;
		cout << "press '9' to exit" << endl;
		cin >> n;

		if (n == 1) {
			cout << "\nenter user Name: ";
			string name;
			cin >> name;
			cout << "\nenter user CNIC: ";
			string cnic;
			cin >> cnic;
			cout << "\nenter user Email: ";
			string email;
			cin >> email;
			cout << "\nenter user Password: ";
			string password;
			cin >> password;
			u.registerUser(name, cnic, email, password);
			name = "";
			password = "";
			cnic = "";
			email = "";
		}
		else if (n == 2) {
			while (1) {
				cout << "\nEnter Email: ";
				string email;
				cin >> email;
				cout << "\nEnter Password: ";
				string password;
				cin >> password;
				if (u.authenticateUser(email, password)) {
					cout << "-----------------------------------\n";
					cout << "Successfully logged in" << endl;
					cout << "-----------------------------------\n";
					l = 1;
					break;
				}
				else {
					cout << "-----------------------------------\n";
					cout << "email or password is wrong try again" << endl;
					cout << "-----------------------------------\n";
				}
			}
			break;
		}
		else if (n == 9) {
			break;
		}
		else {
			cout << "-----------------------------------\n";
			cout << "wrong entry try again" << endl;
			cout << "-----------------------------------\n";
		}
	}

	if (l == 1) {
		string n, d, c;
		bool ava;
		float price, a;
		cout << "\nenter the amount of products you want: ";
		int amount = 0;
		cin >> amount;

		Product* p = new Product[amount];
		for (int i = 0; i < amount; i++) {
			cout << "\nenter name of product: ";
			cin >> n;
			cout << "\nenter price of product: ";
			cin >> price;
			cout << "\nenter description of product: ";
			cin >> d;
			cout << "\nenter category of product: ";
			cin >> c;
			cout << "\nenter availability status of product (0 for not available, 1 for available): ";
			cin >> ava;
			cout << "\nenter amount of product: ";
			cin >> a;
			p[i].setProduct(n, price, d, c, ava, a);

			cout << "product saved successfully" << endl;
			cout << "-----------------------------------\n";
		}
		u.profile();
		for (int i = 0; i < amount; i++) {
			cout << "\n\n\n";
			p[i].getProduct();
			cout << "-----------------------------------\n";
		}

		delete[] p;
	}
}
