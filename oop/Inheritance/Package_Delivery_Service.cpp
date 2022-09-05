#include <iostream>
using namespace std;

class Customer {

};


class Shipment {

};

class Address {
    string name;
    string address;
    string city;
public:
    void SetName(const string &name) {
        this->name = name;
    }

    const string &GetName() const {
        return name;
    }

    void SetAddress(const string &address) {
        this->address = address;
    }

    const string &GetAddress() const {
        return address;
    }
    
    void SetCity(const string &city) {
        this->city = city;
    }

    const string &GetCity() const {
        return city;
    }
};

class Package {
    Address sender_address;
    Address reciever_address;
    double weight;
    double price;

public:
    Package(const Address &sender_address, const Address &reciever_address, double weight_kg, double price_per_kg) : 
        sender_address(sender_address), reciever_address(reciever_address), weight(weight_kg), price(price_per_kg) {            
        }

    double GetTotalCost() {
        return weight * price;
    }

    double GetWeight() const {
        return weight;
    }

    double GetPrice() const {
        return price;
    }

    void SetPrice(double price) {
        this->price = price;
    }

    void SetWeight(double weight) {
        this->weight = weight;
    }

    void SetReciverAddress(const Address &reciever_address) {
        this->reciever_address = reciever_address;
    }

    void SetSenderAddress(const Address &sender_address) {
        this->sender_address = sender_address;
    }

    const Address GetSenderAddress() const {
        return sender_address;
    }

    const Address GetRecieverAddress() const {
        return reciever_address;
    }
};

class TwoDayPackage: private Package {
    double fixed_fee;
public:
    double GetTotalCost() {
        return Package::GetTotalCost() + fixed_fee;
    }

    double GetFixedFee() const {
        return fixed_fee;
    }

    void SetFixedFee(double fixed_fee)  {
        this->fixed_fee = fixed_fee;
    }
};

class heavy_package: private Package {
    const double limit_kg = 100;
    double extra_price_per_kg;
public:

    double GetTotalCost() {
        double weight_per_kg = GetWeight();
        double fee = 0;
        if (weight_per_kg >= limit_kg) 
            fee = (weight_per_kg - limit_kg) * extra_price_per_kg;
        fee += Package::GetTotalCost();
        return fee;
    }
};



int main()
{


    return 0;
}

