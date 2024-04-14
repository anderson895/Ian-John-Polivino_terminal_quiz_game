#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm> 

using namespace std;

// Function prototypes
void displayMenu();
void takeQuiz(const vector<vector<string>>& subject);
int calculateScore(const vector<vector<string>>& questions);

// Convert a string to lowercase
string toLower(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

int main() {
    vector<vector<vector<string>>> subjects = {
        // Subject 1: Mathematics
        {
            {"What is 2 + 2?", "A. 3", "B. 4", "C. 5", "B"},
            {"True or False: 10 is greater than 5.", "True"},
            {"What is the capital of France?", "Paris"},
            {"What is a prime number?", "3"}
        },
        // Subject 2: Science
        {
            {"What is the chemical symbol for water?", "A. H2O", "B. CO2", "C. O2", "A"},
            {"True or False: Water boils at 100 degrees Celsius.", "True"},
            {"What is the powerhouse of the cell?", "Mitochondria"},
            {"Which of the following is a noble gas?", "A. Helium", "B. Oxygen", "C. Carbon", "A"}
        },
        // Subject 3: History
        {
            {"Who wrote the 'I Have a Dream' speech?", "A. Martin Luther King Jr.", "B. Abraham Lincoln", "C. Nelson Mandela", "A"},
            {"True or False: The Statue of Liberty was a gift from France.", "True"},
            {"Who was the first president of the United States?", "George Washington"},
            {"Which of the following events happened first?", "A. American Revolution", "B. World War II", "C. Industrial Revolution", "A"}
        }
    };

    int totalScore = 0;
    int totalQuestions = 0;

    int choice;
    do {
        displayMenu();
        cin >> choice;
        if (choice >= 1 && choice <= subjects.size()) {
            takeQuiz(subjects[choice - 1]);
            totalScore += calculateScore(subjects[choice - 1]);
            totalQuestions += subjects[choice - 1].size();
        } else if (choice != 0) {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    if (totalQuestions > 0) {
        double averageScore = static_cast<double>(totalScore) / totalQuestions * 100;
        cout << "Average Score: " << fixed << setprecision(2) << averageScore << "%" << endl;
    } else {
        cout << "No quizzes were taken." << endl;
    }

    return 0;
}

// Display the menu
void displayMenu() {
    cout << "=== Subject Menu ===" << endl;
    cout << "1. Mathematics" << endl;
    cout << "2. Science" << endl;
    cout << "3. History" << endl;
    cout << "0. Exit" << endl;
    cout << "Choose a subject (0 to exit): ";
}

// Take the quiz for a subject
void takeQuiz(const vector<vector<string>>& subject) {
    for (size_t i = 0; i < subject.size(); ++i) {
        cout << subject[i][0] << endl;
        for (size_t j = 1; j < subject[i].size() - 1; ++j) {
            cout << subject[i][j] << endl;
        }
        string answer;
        cout << "Your answer: ";
        cin >> answer;

        // Convert both user's answer and correct answer to lowercase before comparing
        if (toLower(answer) == toLower(subject[i].back())) {
            cout << "Correct!" << endl;
        } else {
            cout << "Incorrect!" << endl;
        }
    }
}

// Calculate the score for a subject
int calculateScore(const vector<vector<string>>& questions) {
    int score = 0;
    for (size_t i = 0; i < questions.size(); ++i) {
        cout << questions[i][0] << endl;
        for (size_t j = 1; j < questions[i].size() - 1; ++j) {
            cout << questions[i][j] << endl;
        }
        string answer;
        cout << "Your answer: ";
        cin >> answer;

        // Convert both user's answer and correct answer to lowercase before comparing
        if (toLower(answer) == toLower(questions[i].back())) {
            score++;
        }
    }
    return score;
}
