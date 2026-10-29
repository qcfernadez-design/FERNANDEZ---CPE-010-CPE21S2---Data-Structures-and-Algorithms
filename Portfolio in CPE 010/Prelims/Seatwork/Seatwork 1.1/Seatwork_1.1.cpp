using namespace std;
#include <iostream>

int main () {
  
  // To store values of quiz scores
  int ScoreOne;
  int ScoreTwo;
  int ScoreThree;
  float Average;

  cout <<"Welcome please choose one of the following options: " <<endl;
  
  // The section that takes the values of the quiz scores and stores them
  cout <<"Please enter the score of quiz 1: ";
  cin >> ScoreOne;
  cout <<"Please enter the score of quiz 2: ";
  cin >> ScoreTwo;
  cout <<"Please enter the score of quiz 3: ";
  cin >> ScoreThree;
  
  //Calculates the average of the quiz scores
  Average = (ScoreOne + ScoreTwo + ScoreThree)/3;
  
  //Displays the quiz scores
  cout << Average;
  
  return 0;
}

