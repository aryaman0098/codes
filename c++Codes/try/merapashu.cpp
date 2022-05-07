//Including the necessary libraries
#include<bits/stdc++.h>

//Check std if anything undeclared found
using namespace std;

//Defining a macro for the number of villages
#define numVillages 16


//Function to generate input i.e randomly generates village positions and returns the values stored in an array
vector<long long> generateInput(){
    //Changing the seed everytime a new position is produced
    srand(time(0));
    //User defined lowerLimit and upperLimit for the village positions
    long long lowerLimit, upperLimit, position;
    //long longializing vector that would store the values of village positions
    vector<long long> villagePositions;
    //Input from the user
    cout<<"Enter the lower and upper limit (both inclusive) of the positions of the villages in space separated manner : ";
    cin>>lowerLimit>>upperLimit;
    //Genereating and displaying the village postions (generated randomly using rand() function)
    cout<<"\n\nThe positions of villages are :\n";
    for(long long i = 0; i < numVillages; i++){
        position = lowerLimit + rand() % (upperLimit - lowerLimit + 1);
        cout<<position<<", ";
        villagePositions.push_back(position);
    }
    cout<<"\n\n";
    return villagePositions;
}


//Function that calculates the cost of fuel according to the first condition
long long findTotalFuelCost1(vector<long long> villagePositions, long long positionForMela){
    long long totalFuelcost = 0;
    for(long long i = 0; i < numVillages; i++)
        //Taking the absolute value to prevent negative values
        totalFuelcost += abs(villagePositions[i] - positionForMela);
    return totalFuelcost;
}


//Function that calculates the cost of fuel according to the second condition
long long findTotalFuelCost2(vector<long long> villagePositions, long long positionForMela){
    long long totalFuelcost = 0;
    long long n;
    for(long long i = 0; i < numVillages; i++){
        //Taking the absolute value to prevent negative values
        n = abs(villagePositions[i] - positionForMela);
        //Since the cost fuel increases in the fashion 1,2,3,.. for each step, it boils down to sum of first n numbers
        totalFuelcost += n * (n + 1) / 2;
    }
    return totalFuelcost;
}


//Function that calculates the optimum position for pashu mela according to the first condition
long long findPositionForMela1(vector<long long> &villagePositions){
    //Sorting the values so that we can find the median
    sort(villagePositions.begin(),villagePositions.end());

    //The optimum position would be the median of the village positions (cases for even and odd number of villages)
    //For odd we are finding the value to the nearest integer
    if(numVillages % 2 != 0)
        return villagePositions[numVillages / 2];
    else{
        cout<<villagePositions[(numVillages - 1) / 2]<<endl;
        cout<<villagePositions[numVillages / 2]<<endl;
        double median = ((double)villagePositions[(numVillages - 1) / 2] + (double)villagePositions[numVillages / 2]) / 2;
        cout<<"Median is : "<<median<<endl;
        long long medianINT = round(median);
        return medianINT;
    }
}


//Function that calculates the optimum position for pashu mela according to the second condition
long long findPositionForMela2(vector<long long> villagePositions){
    double meanPosition = 0.0;
    //According to the second condition, the optimum polong long would either be the mean position calculated to the nearest integer
    //Calculating the mean of the positions of the villages
    for(long long i = 0; i < numVillages; i++)
        meanPosition += (double)villagePositions[i];
    meanPosition /= numVillages;
    cout<<"Mean is "<<meanPosition<<endl;
    long long ans = round(meanPosition);
    return ans;
}

//Tester function 1
void tester1(vector<long long> villagePositions){
    sort(villagePositions.begin(),villagePositions.end());
    long long min = villagePositions[0];
    long long max = villagePositions[numVillages - 1];
    long long distance;
    long long Min = LLONG_MAX;
    long long x;
    for(long long i = min; i <= max; i++){
        distance = 0;
        for(long long j = 0; j < numVillages; j++){
            distance += abs(i - villagePositions[j]);
        }
        if(Min > distance){
            Min = distance;
            x = i;
        }
        cout<<i<<" distance: "<<distance<<"\n\n";
    }
    cout<<"\n";
    cout<<"Min at "<<x<<" distance "<<Min<<"\n";
}
//Tester function 2
void tester2(vector<long long> villagePositions){
    sort(villagePositions.begin(),villagePositions.end());
    long long min = villagePositions[0];
    long long max = villagePositions[numVillages - 1];
    long long distance;
    long long Min = LLONG_MAX;
    long long x;
    long long n;
    double mean = 0.0;
    for(long long j = 0; j < numVillages; j++){
        mean += villagePositions[j];
    }
    mean /= numVillages;
    for(long long i = min; i <= max; i++){
        distance = 0;
        for(long long j = 0; j < numVillages; j++){
            n = abs(i - villagePositions[j]);
            distance += n * (n + 1) / 2;
        }
        if(distance < Min){
            Min = distance;
            x = i;
        }
        cout<<i<<" distance: "<<distance<<"\n\n";
    }
    cout<<"Mean is : "<<mean<<"\n";
    cout<<"Min at "<<x<<" distance "<<Min<<"\n";
}


//Driver function
int main(){
    //Generating the random input for village positions
    //vector<long long> villagePositions = generateInput();
    vector<long long> villagePositions;
    villagePositions.push_back(6);
    villagePositions.push_back(14);
    villagePositions.push_back(15);
    villagePositions.push_back(2);
    villagePositions.push_back(7);
    villagePositions.push_back(5);
    villagePositions.push_back(4);
    villagePositions.push_back(15);
    villagePositions.push_back(13);
    villagePositions.push_back(6);
    villagePositions.push_back(5);
    villagePositions.push_back(2);
    villagePositions.push_back(11);
    villagePositions.push_back(13);
    villagePositions.push_back(11);
    villagePositions.push_back(6);

    //Problem 1
    //Finding the optimum position
    long long positionForMela1= findPositionForMela1(villagePositions);
    cout<<"According to the first condition the Pashu Mela should be held at the position : "<<positionForMela1<<"\n";
    //Finding total fuel cost for the calculated optimum position
    long long totalFuelCost1 = findTotalFuelCost1(villagePositions, positionForMela1);
    cout<<"Total fuel cost for the mela would be : "<<totalFuelCost1<<"\n\n";

    cout<<"\n\n\n";
    tester1(villagePositions);
    cout<<"\n\n\n";

    //Problem 2
    //Finding the optimum position
    long long positionForMela2 = findPositionForMela2(villagePositions);
    cout<<"According to the second condition the Pashu Mela should be held at the position : "<<positionForMela2<<"\n";
    //Finding total fuel cost for the calculated optimum position
    long long totalFuelCost2 = findTotalFuelCost2(villagePositions, positionForMela2);
    cout<<"Total fuel cost for the mela would be : "<<totalFuelCost2<<"\n\n";
    

    cout<<"\n\n\n";
    tester2(villagePositions);

    return 0;
}
