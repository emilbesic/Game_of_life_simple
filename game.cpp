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
int count_neighbours(vector<vector<int> > board){
    int alive = 0;
    for (uint8_t i = -1; i < 2; i++) {
        for (uint8_t j = -1; j < 2; j++) {
            if(board[i][j] == 1){
                alive++;
            }
        }
    }
    return alive;
}
vector<vector<int> > nextboard(int Row, int Col, vector<vector<int> > board){
    vector<vector<int> > next;
 
    int cell = 0;
    for (int i = 1; i < Col+1; i++) {
        vector<int> v2;
        for (int j = 1; j < Row+1; j++) {
            int neighbour = 0;
            neighbour = count_neighbours(board);
            if(board[i][j] == 1){
                if(neighbour < 2 || neighbour > 3){
                    cell = 1;
                }
                else if(neighbour == 2 || neighbour == 3){
                    cell = 0;
                }
            }
            else if(board[i][j] == 0){
                if(neighbour == 3){
                    cell = 0;
                }
            }
            v2.push_back(cell);
        }
        next.push_back(v2);
    }
    return next;
}
vector<vector<int> > extrazero(int Row, int Col, vector<vector<int> > board){
    vector<vector<int> > zeroboard;

    int cell = 0;
    for (int i = -1; i < Row+1; i++) {
        vector<int> v2;
            if(i < 0 || i == Row){
                cell = 0;
            }
        for (int j = -1; j < Col+1; j++) {
            if(i < 0 || i == Row || j < 0 || j == Col ){
                cell = 0;
            }
            else{
                cell = board[i][j];
            }
            v2.push_back(cell);
            
        }
        zeroboard.push_back(v2);
    }
    return zeroboard;
}
int main()
{
    
    int Row = askRows();
    int Col = askColumns();
    vector<vector<int> > board = initial(Row,Col);
    
    print_vec(board);
    cout << "--------------------------------\n";
    vector<vector<int> > extraboard = extrazero(Row,Col,board);
    print_vec(extraboard);
    cout << "--------------------------------\n";
    /*vector<vector<int> > newboard = nextboard(Row, Col, extraboard);
    print_vec(newboard);*/
    return 0;
}
