#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>

using namespace std;


int askRows(){
    int ROW = 0;
    while (true) {
        cout << "Enter row amount:"<<endl;
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
        cout << "Enter column amount:"<<endl;
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
    for (int i = 0; i < Row; i++) {
        vector<int> v1;
        cout << "Next row"<< endl;
        for (int j = 0; j < Col; j++) {
            cell = ask_cell();
            v1.push_back(cell);
        }
        vec.push_back(v1);
    }
    return vec;
}
void print_vec(vector<vector<int> > board){
    for (uint8_t i = 0; i < board.size(); i++) {
        for (uint8_t j = 0; j < board[i].size(); j++){
            cout << board[i][j] << " ";
    }
    cout << endl;
    }
}
vector<vector<int> > nextboard(int Row, int Col, vector<vector<int> > board){
    vector<vector<int> > next;
 
    int cell = 0;
    for (int i = 1; i < board.size()-1; i++) {
        vector<int> v3;
        for (int j = 1; j < board[i].size()-1; j++) {
            int alive = 0;
            
            for (int k = -1; k < 2; k++) {
                for (int l = -1; l < 2; l++) {
                    int x = i + k;
                    int y = j + l;
                    if(board[x][y] == 1){
                        alive++;
                    }
                }
            }
            
            if(board[i][j] == 1){
                        alive--;
            }
            //cout << alive << endl;
            if(board[i][j] == 1){
                if(alive < 2 || alive > 3){
                    cell = 0;
                }
                else if(alive == 2 || alive == 3){
                    cell = 1;
                }
            }
            else if(board[i][j] == 0){
                if(alive == 3){
                    cell = 1;
                }
                else{
                    cell = 0;
                }
            }
            v3.push_back(cell);
        }
        next.push_back(v3);
    }
    return next;
}
vector<vector<int> > extranum(int Row, int Col, vector<vector<int> > board){
    vector<vector<int> > extraboard;

    int cell = 0;
    for (int i = -1; i < Row+1; i++) {
        vector<int> v2;
            if(i < 0 || i == Row){
                cell = 2;
            }
        for (int j = -1; j < Col+1; j++) {
            if(i < 0 || i == Row || j < 0 || j == Col ){
                cell = 2;
            }
            else{
                cell = board[i][j];
            }
            v2.push_back(cell);
            
        }
        extraboard.push_back(v2);
    }
    return extraboard;
}
int main()
{
    
    int Row = askRows();
    int Col = askColumns();
    
    vector<vector<int> > board = initial(Row,Col);
    print_vec(board);
    vector<vector<int> > extraboard = extranum(Row,Col,board);
    cout << "--------------------------------\n";
    
    int loopcount = 0;
    while(1){
        
    if(loopcount==0){    
    extraboard = nextboard(Row, Col, extraboard);
    print_vec(extraboard);
    cout << "--------------------------------\n";
    }
    else {
    extraboard = extranum(Row,Col,extraboard);
    extraboard = nextboard(Row, Col, extraboard);
    print_vec(extraboard);
    cout << "--------------------------------\n";
    }
    loopcount++;
    
    }
    return 0;
}
