#include <iostream>
#include <string>
using namespace std;

void initializeArrays(string names[], int scores[], int size); 
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);
int indexofBiggest(const int list[], int startingIndex, int numItems);

// const int size = 5;
int main(){
    //declared arrays in main func
    // string names[size];
    // int scores[size];
    
    int size;
    cout<<"How many scores will you enter?: ";
    cin>>size;

    string *names;
    names = new string[size];

    int *scores;
    scores = new int[size];

    //functions to call
    initializeArrays(names, scores, size);
    sortData(names, scores, size);
    displayData(names, scores, size);

    delete [] names;
    delete [] scores;

}



/*Goal of this function is to collect data (player's name and
player's score). 
*/
void initializeArrays(string names[], int scores[], int size){
    for (int count = 1; count <= size; count++){
        cout<<"Enter the name for score #"<<count<<":"<<endl;
        cin>>names[count-1];
        cout<<"Enter the score for score #"<<count<<":"<<endl;
        cin>>scores[count-1];
     }    
}


/*
This function is used to sort both arrays. 

I created a func named indexofBiggest that lets me know the index value 
for the highest value in my array. 

I will then be able to use this to compare with the rest of my numbers
and swap the highest number (based on the index value) for both scores 
and names. 

*/
void sortData(string names[], int scores[], int size){
    for (int count = 0; count <= size - 1; count++){
        int indexValue = indexofBiggest(scores, count, size);
        swap(scores[indexValue], scores[count]);
        swap(names[indexValue], names[count]);
    }
}


/*
The goal of this function is to find the index value for the highest
number value in the array for scores. 
*/
int indexofBiggest(const int list[], int startingIndex, int numItems){
    int targetIndex = startingIndex;
    
    for (int count = startingIndex + 1; count < numItems; count++){
        if (list[count] > list[targetIndex]){
            targetIndex = count;
        }
    }
    return targetIndex;
}


/*This function will display the final list of names and scores, with 
players with the highest scores on top and the players with the lowest 
score on the bottom. 
*/
void displayData(const string names[], const int scores[], int size){
    //need to use pass by reference..... sortData !! 
    cout<<"Top Scorers:"<<endl;
    for (int count = 0; count <= size-1; count++){
        cout<<names[count]<<":"<<scores[count]<<endl;
    }
}

/*
Expecting Results:
Enter the name for score #1:
Ford
Enter the score for score #1:
40
Enter the name for score #2:
Adam
Enter the score for score #2:
100
Enter the name for score #3:
Carry
Enter the score for score #3:
70
Enter the name for score #4:
Beast
Enter the score for score #4:
80
Enter the name for score #5:
Daisy
Enter the score for score #5:
60
Top Scorers:
Adam:100
Beast:80
Carry:70
Daisy:60
Ford:40
*/
