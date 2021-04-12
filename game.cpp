#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int askRows(){
    int ROW = 0;
    while (true) {
        cout << "Enter rows"<<endl;
        cin >> ROW;
        if (cin.fail()) {
            cin.clear(); cin.ignore();
            cout << "Try again" << endl;
        } else break;
    }
    return ROW;
}
int askColumns(){
    int COL = 0;
    while (true) {
        cout << "Enter columns"<<endl;
        cin >> COL ;
        if (cin.fail()) {
            cin.clear(); cin.ignore();
            cout << "Try again" << endl;
        } else break;
    }
    return COL;
}
int ask_cell(){
    int num = 2;
    while (true) {
        cout << "Enter cell's state:";
        cin >> num;
        if (cin.fail()) {
            cin.clear(); cin.ignore();
            cout << "Try again" << endl;
        } 
        else if(num != 1 && num != 0){
            cin.clear(); cin.ignore();
            cout << "Try again" << endl;
        }
        else break;
    }
    return num;
}
vector<vector<int> > initial(int Row, int Col){
    vector<vector<int> > vec;
  

    int cell = 0;
    cout << "Choose initial states for cells."<< endl;
    cout << "Cells work with 0 and 1"<< endl;
    for (int i = 0; i < Col; i++) {
        vector<int> v1;
        for (int j = 0; j < Row; j++) {
            cell = ask_cell();
            v1.push_back(cell);
        }
        cout << "Next row"<< endl;
        vec.push_back(v1);
    }
    return vec;
}
void print_vec(int Row,int Col,vector<vector<int> > board){
    for (uint8_t i = 0; i < board.size(); i++) {
        for (uint8_t j = 0; j < board[i].size(); j++){
            cout << board[i][j] << " ";
        
    }
    cout << endl;
}
}
int nextState(vector<vector<int>> board, int row, int col){
    int bor_st = 0;
}
}
int main()
{
    
    int Row = askRows();
    int Col = askColumns();
    vector<vector<int> > board = initial(Row,Col);
    
    print_vec(Row,Col,board);

    return 0;
}
