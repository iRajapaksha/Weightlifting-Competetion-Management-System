#include <stdio.h>
#include <iostream>
#include <string>
#include <stdexcept>


#include "Data.h"
using namespace std;




int main()
{
    cout << "\n\t\t\t Weightlift Competition Managemant System \n\t\t\t ----------------------------------------\n" << endl;
     int totPlayers ;
     cout << "Enter total number of players (Maximum number of players are 24): " << endl;
     cin >> totPlayers;
     
    Player* player=new Player[totPlayers];

    string wclass1,wclass2;
    cout << "Enter the two competitive weight classes" << endl;
    cout << "\tWeight classes are:" << endl;
    cout << "\t\t\t 55 - Weight is below 55Kg" << endl;
    cout << "\t\t\t 61 - 55Kg<Weight<=61Kg" << endl;
    cout << "\t\t\t 67 - 61Kg<Weight<=67Kg" << endl;
    cout << "\t\t\t 73 - 67Kg<Weight<=73Kg" << endl;
    cout << "\t\t\t 81 - 73Kg<Weight<=81Kg" << endl;
    cout << "\t\t\t 89 - 81Kg<Weight<=89Kg" << endl;
    cout << "\t\t\t 96 - 89Kg<Weight<=96Kg" << endl;
    cout << "\t\t\t 102 - 96Kg<Weight<=102Kg" << endl;
    cin >> wclass1;
    int weightClass1 = stoi( wclass1);
    cin >> wclass2;
    int weightClass2 = stoi(wclass2);

   //player[0] = Player("TOM", "1", 1, 52, 58, 82);
   //player[1] = Player("JERRY", "2", 1, 65, 62, 76);
 
    //input data for each player
   cout << "---------------Registration--------------\n" << endl;
   for (int i = 0; i < totPlayers; i++) {
       cout << "Enter Name : ";
       cin >> player[i].name;
       cout << "Enter registration number: " << endl;
       cin >> player[i].regNo;
       cout << "Select faculty: \n\t1.Engineering \n\t2.Medicine \n\t3.Management \n\t4.Agriculture \n\t5.Fisheries \n\t6.Science" << endl;
       string fac;
       cin >> fac;
       int f = stoi(fac);
       player[i].faculty = player[i].selectFaculty(f);
       cout << "Enter body weight(Kg): ";
       cin >> player[i].weight;
       player[i].weightClass = player[i].selectWeightClass( player[i].weight);
       cout << "Enter first snatch attempt(Kg): ";
       cin >> player[i].snatchAttempt[0];
       cout << "Enter first clean and jerk attempt(Kg): ";
       cin >> player[i].cjkAttempt[0];
       cout << "\n\n\n" << endl;
   }


       //sorting

       quickSort(player, 0, totPlayers - 1);


       //print all the players

       cout << "\t----------------------Players registered for the competetion----------------------\n\n" << endl;
       cout << "\t Name  \t\t\tReg No \t\tTeam\t\tweight\t\tSnatch\t\tCJK " << endl;
       cout << "\n\n\t\t\t----------------------" << weightClass1 << "kg-------------------\n " << endl;
       printPlayers(player, weightClass1,totPlayers);
       cout << "\n\n\t\t\t----------------------" << weightClass2 << "kg-------------------\n " << endl;
       printPlayers(player, weightClass2,totPlayers);



       //Snatch scoring

       cout << "\n\nSnatch scoring" << endl;
       for (int j = 0; j < 3; j++) {
           for (int i = 0; i < totPlayers; i++) {
               cout << "Did " << player[i].name << " lift " << player[i].snatchAttempt[j] << " ? (y/n)" << endl;
               string s;
               cin >> s;
               int lift;

               if (s == "y") lift = 1;
               else lift = 0;

               setSnatchAttempt(player, i, j, lift);
           }
       }

       //CJK scoring
       cout << "\n\nCJK scoring" << endl;
       for (int j = 0; j < 3; j++) {
           for (int i = 0; i < totPlayers; i++) {
               cout << "Did " << player[i].name << " lift " << player[i].cjkAttempt[j] << " ? (y/n)" << endl;
               string s;
               cin >> s;
               int lift;

               if (s == "y") lift = 1;
               else lift = 0;

               setCleanAndJerkAttempt(player, i, j, lift);
           }
       }


       //find total lift
       findMaxLift(player,totPlayers);

       //result
       //print all the players
       cout << "\t\t----------------------Results----------------------\n" << endl;
       cout << "\t Name \t\tReg No \t\tTeam \t\tWeight\tSnatch\tCJK\tTotal\tPosition " << endl;
       cout << "\n\t\t----------------------" << weightClass1 << "kg-------------------\n " << endl;
       findPosition(player, weightClass1,totPlayers);
       cout << "\n\n\t\t----------------------" << weightClass2 << "kg-------------------\n " << endl;
       findPosition(player, weightClass2,totPlayers);

       
   }
   

