#include <iostream>
#include <string>
using namespace std;

// constant value initialization
const int NUM_OF_QUESTIONS = 8;
const string TOKEN = "aimarmln";
const string INDENT = "   ";

// data structure to store quiz data
struct QuizData {
  string question;
  string choices[4];
  char correctAnswer;
};

// quiz data
QuizData questions[NUM_OF_QUESTIONS] = {
  {
    "1. How do we print \"hello world\" in C++?",
    {
      "a. print(\"hello world\")",
      "b. console.log(\"hello world\");",
      "c. cout << \"hello world\";",
      "d. <h1>hello world</h1>"
    },
    'c'
  },
  {
    "2. How do we pronounce \"cout\" and \"cin\"?",
    {
      "a. kawt and kin",
      "b. si out and si in",
      "c. cowt and cin",
      "d. ce out and ce in"
    },
    'b'
  },
  {
    "3. What is the area of the trapezium above?",
    {
      "a. 80",
      "b. 110",
      "c. 130",
      "d. 120"
    },
    'a'
  },
  {
    "4. Who is the CEO of Google?",
    {
      "a. Jhonny G. Plate",
      "b. Elon Musk",
      "c. Sundar Pichai",
      "d. Mark Zuckerberg"
    },
    'c'
  },
  {
    "5. What does HTML stand for in web development?",
    {
      "a. High Text Markup Language",
      "b. Hyperlink Text Markup Language",
      "c. High Tech Markup Language",
      "d. Hyper Text Markup Language",
    },
    'd'
  },
  {
    "6. who will win the boxing match between Elon Musk and Mark Zuckerberg",
    {
      "a. Elon Musk",
      "b. Mark Zuckerberg",
      "c. Draw",
      "d. Won't happen"
    },
    'd'
  },
  {
    "7. What programming language does this program use?",
    {
      "a. C++",
      "b. Java",
      "c. Python",
      "d. Javascript"
    },
    'a'
  },
  {
    "8. Does AI will take over the world?",
    {
      "a. Yes",
      "b. Probably yes",
      "c. No",
      "d. Probably no"
    },
    'c'
  }
};

// store player answer
string playerAnswer[NUM_OF_QUESTIONS];

// aimarmln label
void label() {
  cout << "==============================\n";
  cout << "=====    simple  quiz    =====\n";
  cout << "=====    by  aimarmln    =====\n";
  cout << "==============================\n";
}

// validate the quiz token
void validateQuizToken() {
  string inputToken;

  cout << "insert token : "; cin >> inputToken;
  while (inputToken != TOKEN) {
    cout << "your token does not match!\n";
    cout << "insert token : "; cin >> inputToken;
  }
}

// display trapezium pattern for question 3
void displayTrapz() {
  for (int i = 1; i <= 5; i++) {
    cout << INDENT;
    for (int j = 1; j <= 10; j++) 
      cout << '*';
    for (int k = 1; k <= i; k++) 
      cout << "**";
    cout << endl;
  }
}

// validate player answer (must between A >= player answer => D)
bool validatePlayerAns(string playerAnswer) {
  char answer = toupper(playerAnswer[0]);
  if ((playerAnswer.length() == 1) && (answer >= 'A' && answer <= 'D')) {
    return true;
  }
  return false;
}

// validate yes or no (must be Y or N)
bool validateYesOrNo(string playerInput) {
  char input = toupper(playerInput[0]);
  if ((playerInput.length() == 1) && (input == 'Y' || input == 'N')) {
    return true;
  }
  return false;
}

// run the quiz
void runQuiz() {
  for (int i = 0; i < NUM_OF_QUESTIONS; i++) {
    if (i == 2) {
      displayTrapz();
    }

    cout << questions[i].question << endl;
    for (int j = 0; j < 4; j ++) {
      cout << INDENT << questions[i].choices[j] << endl;
    }

    cout << "\nyour answer: \n";
    cin >> playerAnswer[i];
    while (!validatePlayerAns(playerAnswer[i])) {
      cout << "your answer: (please input a, b, c, or d!)\n";
      cin >> playerAnswer[i];
    }

    system("cls");
  }
}

// calculate player's score
float getScore() {
  float count = 0;
  for (int i = 0; i < NUM_OF_QUESTIONS; i++) {
    if (playerAnswer[i][0] == questions[i].correctAnswer) {
      count++;
    }
  }
  return (count / NUM_OF_QUESTIONS) * 100;
}

// get player's achievement index
string getIndex() {
  float score = getScore();

  if (score > 90) return "A (excellent, keep it up!)";
  else if ( score > 60) return "B (good work!)";
  else return "C (get better next time!)";
}

// get choice index of an answer
int getChoiceIndex(char playerAnswer) {
  char answer = toupper(playerAnswer);
  
  if (answer == 'A') return 0;
  else if (answer == 'B') return 1;
  else if (answer == 'C') return 2;
  else if (answer == 'D') return 3;
}

// get the quiz choice
string getQuizChoice(int questionIdx, int choiceIdx) {
  return questions[questionIdx].choices[choiceIdx];
}

// display summary of quiz results
void summary() {
  int count = 0;

  for (int i = 0; i < NUM_OF_QUESTIONS; i++) {
    string result;
    if (playerAnswer[i][0] == questions[i].correctAnswer) {
      result = "(correct)";
      count++;
    } else {
      result = "(false)";
    }

    string correctChoice = getQuizChoice(i, getChoiceIndex(questions[i].correctAnswer));
    string playerChoice = getQuizChoice(i, getChoiceIndex(playerAnswer[i][0]));

    if (i == 2) displayTrapz();
    cout << questions[i].question << endl;
    cout << INDENT << "correct answer : " << correctChoice << endl;
    cout << INDENT << "your answer    : " << playerChoice << " " << result << endl << endl;
  }

  (count == 0) ?
    cout << "you did not answer a single question correctly!\n\n" :
    cout << "you answered " << count << " of " << NUM_OF_QUESTIONS << " questions correctly!\n\n";
}

// main function
int main() {
  string playAgain;

  label();
  validateQuizToken();
  system("cls");

  do {
    runQuiz();

    cout << "score : " << getScore() << endl;
    cout << "index : " << getIndex() << endl;
    cout << "\nsummary : \n\n"; summary();
    
    do {
      cout << "wanna play again? (y/n) : ";
      cin >> playAgain;
    } while (!validateYesOrNo(playAgain));

    if (toupper(playAgain[0]) == 'N') {
      system("cls");
      cout << "have a nice day!\n";
      break;
    } else {
      system("cls");
    }
  } while (toupper(playAgain[0]) == 'Y');

  return 0;
}
