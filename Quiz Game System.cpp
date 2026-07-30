#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Question {
    string question;
    string options[4];
    char answer;
};

struct Player {
    string name;
    int score;
};

vector<Question> questions = {
    {
        "What is the capital of Pakistan?",
        {"a) Lahore", "b) Karachi", "c) Islamabad", "d) Peshawar"},
        'c'
    },

    {
        "Which data structure works on FIFO?",
        {"a) Stack", "b) Queue", "c) Tree", "d) Graph"},
        'b'
    },

    {
        "Which search is faster on sorted data?",
        {"a) Linear Search", "b) Binary Search", "c) Bubble Sort", "d) Queue"},
        'b'
    },

    {
        "Which data structure uses LIFO?",
        {"a) Queue", "b) Array", "c) Stack", "d) Tree"},
        'c'
    }
};

vector<Player> leaderboard;

void bubbleSort() {
    int n = leaderboard.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (leaderboard[j].score < leaderboard[j + 1].score) {
                swap(leaderboard[j], leaderboard[j + 1]);
            }
        }
    }
}

void searchPlayer() {

    string name;
    bool found = false;

    cout << "\nEnter player name: ";
    cin >> name;

    for (int i = 0; i < leaderboard.size(); i++) {

        if (leaderboard[i].name == name) {

            cout << "\nPlayer Found!" << endl;
            cout << "Name: " << leaderboard[i].name << endl;
            cout << "Score: " << leaderboard[i].score << endl;

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nPlayer not found!" << endl;
    }
}

void startQuiz() {

    string name;
    int score = 0;
    char answer;

    cout << "\n===== QUIZ STARTED =====\n";

    cout << "Enter your name: ";
    cin >> name;

    for (int i = 0; i < questions.size(); i++) {

        cout << "\n" << questions[i].question << endl;

        for (int j = 0; j < 4; j++) {
            cout << questions[i].options[j] << endl;
        }

        cout << "Enter answer (a/b/c/d): ";
        cin >> answer;

        if (tolower(answer) == questions[i].answer) {

            cout << "Correct Answer!" << endl;
            score++;
        }

        else {
            cout << "Wrong Answer!" << endl;
        }
    }

    cout << "\nFinal Score: " << score << endl;

    leaderboard.push_back({name, score});
}

void showLeaderboard() {

    if (leaderboard.empty()) {

        cout << "\nNo scores available.\n";
        return;
    }

    bubbleSort();

    cout << "\n===== LEADERBOARD =====\n";

    for (int i = 0; i < leaderboard.size(); i++) {

        cout << i + 1 << ". "
             << leaderboard[i].name
             << " - "
             << leaderboard[i].score
             << endl;
    }
}

int main() {

    int choice;

    while (true) {

        cout << "\n===== SMART QUIZ GAME SYSTEM =====" << endl;

        cout << "1. Start Quiz" << endl;
        cout << "2. View Leaderboard" << endl;
        cout << "3. Search Player" << endl;
        cout << "4. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                startQuiz();
                break;

            case 2:
                showLeaderboard();
                break;

            case 3:
                searchPlayer();
                break;

            case 4:
                cout << "\nThank You For Using Quiz System!" << endl;
                return 0;

            default:
                cout << "\nInvalid Choice!" << endl;
        }
    }

    return 0;
}