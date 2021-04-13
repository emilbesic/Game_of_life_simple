#include <iostream>
#include <vector>
#include<unistd.h>
using namespace std;

const unsigned int microsecond = 1000000;

int askRows();
int askColumns();
int ask_cell();
vector <vector<int>> initialBoard(int Row, int Col);
void printBoard(vector <vector<int>> board);
vector <vector<int>> borders(int Row, int Col, vector <vector<int>> board);
vector <vector<int>> nextboard(int Row, int Col, vector <vector<int>> board);

int main() {


    cout << "Rules:" << endl;
    cout << "First you need to pick the boards's row and column amount" << endl;
    cout << "Then you fill the cells with zeroes or ones" << endl;
    cout << "You are then asked to input a command" << endl;
    cout << "Two commands: next and loop" << endl;
    cout << "next: does only one state of game of life" << endl;
    cout << "loop: loops the states infinitely" << endl;
    
    
    int Row = askRows();
    int Col = askColumns();

    vector <vector<int>> board = initialBoard(Row, Col);
    printBoard(board);
    vector <vector<int>> extraboard = borders(Row, Col, board);

    cout << "Command:";

    int loopcount = 0;
    string str;
    do {

        while (true) {
            cin >> str;
            if (str != "next" && str != "loop") {
                cin.clear();
                cin.ignore();
                cout << "Try again" << endl;
                cout << "Command:";
            } else {
                break;
            }
        }
        if (str == "next") {
            if (loopcount == 0) {
                extraboard = nextboard(Row, Col, extraboard);
                printBoard(extraboard);
                cout << "Command:";
            } else {
                extraboard = borders(Row, Col, extraboard);
                extraboard = nextboard(Row, Col, extraboard);
                printBoard(extraboard);
                cout << "Command:";
            }
            loopcount++;
        } else if (str == "loop") {
            while (1) {
                if (loopcount == 0) {
                    extraboard = nextboard(Row, Col, extraboard);
                    printBoard(extraboard);
                    cout <<endl;
                    usleep( microsecond);
                } else {
                    extraboard = borders(Row, Col, extraboard);
                    extraboard = nextboard(Row, Col, extraboard);
                    printBoard(extraboard);
                    cout <<endl;
                    usleep( microsecond);
                }
                loopcount++;
            }
        }
    } while (str == "next" || str == "loop");

    return 0;
}

// Asks user for Rows. Accepts only numbers.
int askRows() {
    int ROW = 0;
    while (true) {
        cout << "\nEnter row amount:" << endl;
        cin >> ROW;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Try again" << endl;
        } else break;
    }
    return ROW;
}

// Asks user for Columns. Accepts only numbers.
int askColumns() {
    int COL = 0;
    while (true) {
        cout << "Enter column amount:" << endl;
        cin >> COL;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Try again" << endl;
        } else break;
    }
    return COL;
}
// Asks user for Cell's state. Accepts only 1 and 0 . 
int ask_cell() {
    int num = 2;
    while (true) {
        cout << "Enter cell's state:";
        cin >> num;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Try again" << endl;
        } else if (num != 1 && num != 0) {
            cin.clear();
            cin.ignore();
            cout << "Try again" << endl;
        } else break;
    }
    return num;
}

// Generates the initialBoard state of the boards with chosen cells.
vector <vector<int>> initialBoard(int Row, int Col) {
    vector <vector<int>> vec;

    int cell = 0;
    cout << "Choose initialBoard states for cells." << endl;
    cout << "Cells work with 0 and 1" << endl;
    for (int i = 0; i < Row; i++) {
        vector <int> v1;
        cout << "Next row" << endl;
        for (int j = 0; j < Col; j++) {
            cell = ask_cell();
            v1.push_back(cell);
        }
        vec.push_back(v1);
    }
    return vec;
}
// Prints the states of the boards. Ones turn to ■ and zeroes to □
void printBoard(vector <vector<int>> board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 1) {
                cout << "■" << " ";
            } else if (board[i][j] == 0) {
                cout << "□" << " ";
            } else {
                cout << "X" << " ";
            }
        }
        cout << endl;
    }
}

// We generate borders with this function
vector <vector<int>> borders(int Row, int Col, vector <vector<int>> board) {

// We want to generate borders for the board, so that the the neighbours can be counted. Thus the -1 till row/column +1 loop iterations.
    vector <vector<int>> borderboard;
    int cell = 0;
    for (int i = -1; i < Row + 1; i++) {
        vector <int> v2;
        if (i < 0 || i == Row) {
            cell = 2;
        }
        for (int j = -1; j < Col + 1; j++) {
            if (i < 0 || i == Row || j < 0 || j == Col) {
                cell = 2;
            } else {
                cell = board[i][j];
            }
            v2.push_back(cell);

        }
        borderboard.push_back(v2);
    }
    return borderboard;
}

// Generates the next state of the board based on the rules.

vector <vector<int>> nextboard(int Row, int Col, vector <vector<int>> board) {
    
// The role of the first two for loops is to handle each cell of the board that are not the borders.  
// The other two for loops inside are used for handling the neigbour counting.
// Borders function was used to create one extra number on each border. We want to ignore those. This is why we start two first loops from one and end with size-1
// Since we have to count the neighbours, we have look through neigbours around the cell. 
// The reason why the third and fourth loop iterate from -1 to 1 is, because the neigbours are around the cell and so they are -1,-1 -1,0 -1,1 and so on.
    vector <vector<int>> next;
    int cell = 0;
    for (int i = 1; i < board.size() - 1; i++) {
        vector <int> v3;
        for (int j = 1; j < board[i].size() - 1; j++) {
            int alive = 0;

            for (int k = -1; k < 2; k++) {
                for (int l = -1; l < 2; l++) {
                    int x = i + k;
                    int y = j + l;
                    if (board[x][y] == 1) {
                        alive++;
                    }
                }
            }
// This is the part where we calculate the new states of the cells based on the game of life rules.
// Reason why we subtract one neighbour is, because the loops (previous) counted 9 cells with ones. 
// This means that the cell that we count neighbours of is also counted as one neighbour.
            if (board[i][j] == 1) {
                alive--;
            }
            if (board[i][j] == 1) {
                if (alive < 2 || alive > 3) {
                    cell = 0;
                } else if (alive == 2 || alive == 3) {
                    cell = 1;
                }
            } else if (board[i][j] == 0) {
                if (alive == 3) {
                    cell = 1;
                } else {
                    cell = 0;
                }
            }
            v3.push_back(cell);
        }
        next.push_back(v3);
    }
    return next;
}
