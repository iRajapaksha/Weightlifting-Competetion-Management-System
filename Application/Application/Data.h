#pragma
#include <iostream>
using namespace std;

class Player {

public:
    string name;
    string regNo;
    string faculty;
    double weight;
    double snatchAttempt[3];
    double cjkAttempt[3];
    double maxSnatch;
    double maxCjk;
    double total;
    int position;

    int weightClass;

    Player()
    {

    }

    Player(string Name, string Regno, int Faculty, double Weight, double Snatch, double Cjk)
    {
        name = Name;
        regNo = Regno;
        faculty = selectFaculty(Faculty);
        weight = Weight;
        weightClass = selectWeightClass(weight);
        snatchAttempt[0] = Snatch;
        cjkAttempt[0] = Cjk;
    }

    int selectWeightClass(double weight) {

        if (30 < weight && weight <= 55) {
            return 55;
        }
        else if (55 < weight && weight <= 61) {
            return 61;
        }
        else if (61 < weight && weight <= 67) {
            return 67;

        }
        else if (67 < weight && weight <= 73) {
            return 73;

        }
        else if (73 < weight && weight <= 81) {
            return 81;

        }
        else if (81 < weight && weight <= 89) {
            return 89;

        }
        else if (89 < weight && weight <= 96) {
            return 96;

        }
        else if (96 < weight && weight <= 102) {
            return 102;

        }
        else if (102 < weight) {
            return 103;

        }


    }

    string selectFaculty(int num) {
        switch (num)
        {
        case 1: return "ENG"; break;
        case 2: return "MED"; break;
        case 3: return "MNG"; break;
        case 4: return "AGR"; break;
        case 5: return "SCI"; break;
        case 6: return "FMS"; break;
        default:
            break;
        }
    }
};



void quickSortMax(Player* arr, int left, int right) {
    int i = left;
    int j = right;
    double pivot = arr[(left + right) / 2].total;

    while (i <= j) {
        while (arr[i].total < pivot) {
            i++;
        }
        while (arr[j].total > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (left < j) {
        quickSortMax(arr, left, j);
    }
    if (i < right) {
        quickSortMax(arr, i, right);
    }
}

void selectionSort(Player arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].total > arr[maxIndex].total) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            Player temp = arr[i];
            arr[i] = arr[maxIndex];
            arr[maxIndex] = temp;
        }
    }
}


//To sort names 
void quickSort(Player* arr, int left, int right) {
    int i = left;
    int j = right;
    string pivot = arr[(left + right) / 2].name;

    while (i <= j) {
        while (arr[i].name < pivot) {
            i++;
        }
        while (arr[j].name > pivot) {
            j--;
        }
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (left < j) {
        quickSort(arr, left, j);
    }
    if (i < right) {
        quickSort(arr, i, right);
    }
}

void setCleanAndJerkAttempt(Player* player, int num, int attempt, int i) {
    if (i == 1) {
        if (attempt < 2) {
            cout << "Enter next attempt: " << endl;
            string s;
            cin >> s;
            double weight = stoi(s);
            player[num].cjkAttempt[attempt + 1] = weight;
        }
    }
    else {
        player[num].cjkAttempt[attempt + 1] = player[num].cjkAttempt[attempt];
        player[num].cjkAttempt[attempt] = NULL;
    }
}

void setSnatchAttempt(Player* player, int num, int attempt, int i) {

    if (i == 1) {
        if (attempt < 2) {
            cout << "Enter next attempt: " << endl;
            string s;
            cin >> s;
            double weight = stoi(s);
            player[num].snatchAttempt[attempt + 1] = weight;
        }
    }
    else {
        player[num].snatchAttempt[attempt + 1] = player[num].snatchAttempt[attempt];
        player[num].snatchAttempt[attempt] = NULL;
    }
}

void findMaxLift(Player* player, int totPlayers) {
    for (int i = 0; i < totPlayers; i++) {
        double max1 = player[i].snatchAttempt[0];
        for (int j = 1; j < 3; j++) {
            if (player[i].snatchAttempt[j] > max1) max1 = player[i].snatchAttempt[j];
        }
        player[i].maxSnatch = max1;

        double max2 = player[i].cjkAttempt[0];
        for (int j = 1; j < 3; j++) {
            if (player[i].cjkAttempt[j] > max2) max2 = player[i].cjkAttempt[j];
        }
        player[i].maxCjk = max2;

        double tot = max1 + max2;
        player[i].total = tot;
    }
}

void findPosition(Player* player, int wc1, int totPlayers) {
    Player* temp1 = new Player[totPlayers];
    for (int i = 0; i < totPlayers; i++) {
        if (player[i].weightClass == wc1) {
            temp1[i] = player[i];
        }

    }
    selectionSort(temp1, totPlayers);
    for (int i = 0; i < totPlayers; i++) {
        temp1[i].position = i + 1;
    }
    for (int i = 0; i < totPlayers; i++) {
        if (temp1[i].weightClass == wc1) {
            cout << "\t" << temp1[i].name << "\t\t" << temp1[i].regNo << "\t\t"
                << temp1[i].faculty << "\t\t" << temp1[i].weight << "\t" << temp1[i].maxSnatch
                << "\t" << temp1[i].maxCjk << "\t" << temp1[i].total << "\t" << temp1[i].position << endl;
        }

    }

}


void printPlayers(Player* player, int weight, int totPlayers) {
    for (int i = 0; i < totPlayers; i++) {
        if (player[i].weightClass == weight) {
            cout << "\t" << player[i].name << "\t\t\t" << player[i].regNo << "\t\t"
                << player[i].faculty << "\t\t" << player[i].weight << "\t\t" << player[i].snatchAttempt[0]
                << "\t\t" << player[i].cjkAttempt[0] << endl;

        }

    }
}
