#include <iostream>
using namespace std;
int mayanUnitsToDays(int kin, int unial, int tun, int katun, int baktun, int pictun){ 
        return kin * 1 +
               unial * 20 +
               tun * 360 +
               katun * 7200 +
               pictun * 2880000;
    }
void daysToMayanUnits(int days, int &kin, int &unial, int &tun, int &katun, int &baktun, int &pictun){
    pictun = days / 2880000 ;
    days %= 2880000;
    baktun = days / 144000;
    days %= 144000;
    katun = days / 7200; 
    days %= 7200;
    tun = days / 360;
    days %= 360;
    unial = days / 20;
    days %= 20;
    kin = days;
}

int main() {
    int num;
        cout 
        << "Menu" << endl 
        << "----"
         << endl << "1. Convert Mayan time units to days"
         << endl << "2. Convert days to Mayan time units"
         << endl << "3. Exit"
         << endl << "Your choice? ";
        cin >> num;
    if (num == 1){
        int ki, un, tu, ka, ba, pi; 
     cout << "Number of kin? ";
     cin >> ki;

     cout << "Number of unial? ";
     cin >> un;

     cout << "Number of tun? ";
     cin >> tu;

     cout << "Number of katun? ";
     cin >> ka;

     cout << "Number of baktun? ";
     cin >> ba;

     cout << "Number of pictun? ";
     cin >> pi;
     cout << "This set of time units represents: " << mayanUnitsToDays(ki, un, tu, ka, ba, pi) << "days" << endl;
    }

    else if(num == 2){
     int days, kin, unial, tun, katun, baktun, pictun;
     cout << "Enter the number of days: ";
     cin >> days;
     daysToMayanUnits(days, kin, unial, tun, katun, baktun, pictun);
     cout << "The conversion is: "
     << endl << kin    << " kin"
     << endl << unial  << " unial"
     << endl << tun    << " tun"
     << endl << katun  << " katun"
     << endl << baktun << " baktun"
     << endl << pictun << " pictun"
     <<endl;
    }
    else{
       cout << "Exiting..." << endl;
    }
   

}
