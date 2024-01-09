#include <stdlib.h>
#include <sys/time.h>
#include <iostream>
#include <string>
using namespace std;
// function prototypes
int senseDistance();
void getSensors( int sensors[] );
void printSensors( int sensors[], string labels[] );
int furthest( int sensors[] );
// main function
int main() {
int sensors[4]; // array of four distance sensors
string labels[4]; // array of labels for each sensor
int dir; // indicates which direction to go next

srand( time( NULL )); // initialize the random number generator

labels[0] = "North"; // initialize the sensor labels
labels[1] = "West";
labels[2] = "South";
labels[3] = "East";

for (int i = 0; i < 5; i++ ) 
{ // simulate 5 moves by the robot
    getSensors( sensors ); // get values for all the sensors
    printSensors( sensors, labels ); // print out the sensor values
    dir = furthest( sensors ); // find the direction that is furthest from an obstacle
    cout<<"============="<<endl;
    cout << " Moving " << labels[dir] << endl; // ‘‘go’s
    cout<<"=============";
    cout<<endl;
    cout<<endl;
}
} // end of main()

int senseDistance()
{
    return rand() % 101;
}
void getSensors( int sensors[] )
{
    for (int i = 0; i < 4; i++)
    {
         sensors[i] = senseDistance();
    }
}
void printSensors( int sensors[], string labels[] )
{
    for (int i = 0; i < 4; i++)
    {
        cout<<labels[i]<<" = "<<sensors[i]<<endl;
    }
}
int furthest( int sensors[] )
{
    int max = 0, maxIndex;
    for (int i = 0; i < 4; i++)
    {
        if (sensors[i] > max)
        {
            max = sensors[i];
            maxIndex= i;
        }
    }

    return maxIndex;
}