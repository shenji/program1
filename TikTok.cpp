#include <iostream>
using namespace std;

int main() {
    
    int nVideos, nLikes, nFollowers;

    
    cout << "Enter the number of videos: ";
    cin >> nVideos;

    cout << "Enter the number of likes: ";
    cin >> nLikes;

    cout << "Enter the number of followers: ";
    cin >> nFollowers;

    
    double engagement_rate = static_cast<double>(nLikes) / nVideos / nFollowers * 100;

    
    double revenue = 0.002 * nFollowers + (0.7 * engagement_rate);

    
    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "The total revenue estimate per video is: $" << revenue << std::endl;

    return 0;
}
