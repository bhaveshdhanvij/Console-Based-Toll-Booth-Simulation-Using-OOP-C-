// Console-Based Toll Booth Simulation Using Object-Oriented Programming (C++)

#include<bits/stdc++.h>
using namespace std;

class Vehicle {
protected:              // Data Hiding
    string vehicleNumber;
    double tollPaid;

public:
    Vehicle(string number) {   // Constructor
        vehicleNumber = number;
        tollPaid = 0;
    }

    virtual double calculateToll() const = 0; // Pure virtual function

    string getNumber() const {
        return vehicleNumber;
    }

    double getTollPaid() const {
        return tollPaid;
    }

    virtual string getType() const = 0;

    virtual ~Vehicle() {}      // Virtual destructor
};

// Derived Classes (Inheritance + Polymorphism)
class Car : public Vehicle {
public:
    Car(string number) : Vehicle(number) {}

    double calculateToll() const override {
        return 50;
    }

    string getType() const override {
        return "Car";
    }
};

class Truck : public Vehicle {
public:
    Truck(string number) : Vehicle(number) {}

    double calculateToll() const override {
        return 100;
    }

    string getType() const override {
        return "Truck";
    }
};

class Bike : public Vehicle {
public:
    Bike(string number) : Vehicle(number) {}

    double calculateToll() const override {
        return 30;
    }

    string getType() const override {
        return "Bike";
    }
};

// TollBooth Class (Encapsulation)
class TollBooth {
private:
    vector<Vehicle*> vehicles;   // Stores vehicles
    double totalCollection;

public:
    TollBooth() {
        totalCollection = 0;
    }

    void addVehicle(Vehicle* v) {
        double toll = v->calculateToll(); // Runtime polymorphism
        totalCollection += toll;
        vehicles.push_back(v);
    }

    void displaySummary() const {
        cout << "\n--- Toll Booth Summary ---\n";
        cout << "Total Vehicles: " << vehicles.size() << endl;
        cout << "Total Collection: ₹" << totalCollection << endl;

        cout << "\nVehicle Details:\n";
        for (auto v : vehicles) {
            cout << v->getType()
                 << " | " << v->getNumber()
                 << " | Toll: ₹" << v->calculateToll() << endl;
        }
    }
};

int main() {
    TollBooth booth;
    int choice;

    while (true) {
        cout << "\n1.Car  2.Truck  3.Bike  0.Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 0) break;

        string number;
        cout << "Enter vehicle number: ";
        cin >> number;

        Vehicle* v = nullptr;

        if (choice == 1) v = new Car(number);
        else if (choice == 2) v = new Truck(number);
        else if (choice == 3) v = new Bike(number);
        else {
            cout << "Invalid choice\n";
            continue;
        }

        booth.addVehicle(v);
    }

    booth.displaySummary();

    return 0;
}
