#include <bits/stdc++.h>
using namespace std;

class User {
public:
    string name;
    string email;

    User(const string& name, const string& email)
        : name(name), email(email) {}

    virtual void display() const {
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
    }
};

class AuctionParticipant : public User {
public:
    AuctionParticipant(const string& name, const string& email)
        : User(name, email) {}
    void display(){
        cout<<"This is a participant class object\n";
    }
};

class Auction {
private:
    string item;
    double highestBid1;
    double highestBid2;
    double highestBid3;
    AuctionParticipant* highestBidder1;
    AuctionParticipant* highestBidder2;
    AuctionParticipant* highestBidder3;

public:
    Auction()
        : highestBid1(0), highestBid2(0), highestBid3(0), highestBidder1(nullptr), highestBidder2(nullptr), highestBidder3(nullptr) {}

    /* const string& getItem() const {
        return item;
    } */

    double getHighestBid1() const {
        return highestBid1;
    }
    double getHighestBid2() const {
        return highestBid2;
    }
    double getHighestBid3() const {
        return highestBid3;
    }
    const AuctionParticipant* getHighestBidder1() const {
        return highestBidder1;
    }
    const AuctionParticipant* getHighestBidder2() const {
        return highestBidder2;
    }
    const AuctionParticipant* getHighestBidder3() const {
        return highestBidder3;
    }
    void placeBid1(AuctionParticipant* participant, double amount) {
        if (amount > highestBid1) {
            highestBid1 = amount;
            highestBidder1 = participant;
        }
    }
    void placeBid2(AuctionParticipant* participant, double amount) {
        if (amount > highestBid2) {
            highestBid2 = amount;
            highestBidder2 = participant;
        }
    }
    void placeBid3(AuctionParticipant* participant, double amount) {
        if (amount > highestBid3) {
            highestBid3 = amount;
            highestBidder3 = participant;
        }
    }
};

int main(){
    vector<AuctionParticipant*> users;
    // vector<Auction> auctions;

    Auction auctions;

    ifstream usersFile("users4.txt");
    if (!usersFile) {
        cerr << "Failed to open users.txt" << endl;
        return 1;
    }

    string name, email;
    double bid1,bid2,bid3;
    while (usersFile >> name >> email >> bid1>> bid2>> bid3) {
        AuctionParticipant* test = new AuctionParticipant(name, email);
        users.push_back(test);
        auctions.placeBid1(test, bid1);
        auctions.placeBid2(test, bid2);
        auctions.placeBid3(test, bid3);
    }
    cout << "=== Auction Summary ===\n" << endl;

        cout << "Item1: Artwork"  << endl;
        cout << "Highest Bid: " << auctions.getHighestBid1()<<"$" << endl;
        cout << "Highest Bidder: " << auctions.getHighestBidder1()->name << endl;
        cout <<"Email: "<<auctions.getHighestBidder1()->email <<endl;
        cout << "-------------------------" << endl<<endl;

        cout << "Item2: Luxury_Car"  << endl;
        cout << "Highest Bid: " << auctions.getHighestBid2()<<"$"  << endl;
        cout << "Highest Bidder: " << auctions.getHighestBidder2()->name << endl;
        cout <<"Email: "<<auctions.getHighestBidder2()->email <<endl;
        cout << "-------------------------" << endl<<endl;

        cout << "Item3: Relic"  << endl;
        cout << "Highest Bid: " << auctions.getHighestBid3()<<"$"  << endl;
        cout << "Highest Bidder: " << auctions.getHighestBidder3()->name << endl;
        cout <<"Email: "<<auctions.getHighestBidder3()->email <<endl;
        cout << "-------------------------" << endl<<endl;

}

