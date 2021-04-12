
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool is_integer(float k)
{
  return std::floor(k) == k;
}

int askRows(){
    int ROW = 0;
    cout << "Rows"<<endl;
    cin >> ROW;
    return ROW;
}
int askColumns(){
    int COL = 0;
    cout << "Columns"<<endl;
    cin >> COL ;
    return COL;
}
int change_one_zero(int num){
    if(num >= 1){
        num = 1;
    }
    else if(num <= 0){
        num = 0;
    }
    return num;
}
vector<vector<int> > initial(int Row, int Col){
    vector<vector<int> > vec;
  

    int num = 0;
    int cell = 0;
    cout << "Choose initial states for cells."<< endl;
    cout << "Cells work with zeroes and ones"<< endl;
    cout << "Under zero changes to 0 and over 1 changes to 1"<< endl<< "\n";  
    for (int i = 0; i < Col; i++) {
        vector<int> v1;
        for (int j = 0; j < Row; j++) {
            cin >> num;
            cell = change_one_zero(num);
            v1.push_back(cell);
        }
        cout << "next row"<< endl;
        // Pushing back above 1D vector
        // to create the 2D vector
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
int main()
{
    
    int Row = askRows();
    int Col = askColumns();
    vector<vector<int> > board = initial(Row,Col);
    
    // Displaying the 2D vector
    print_vec(Row,Col,board);

    return 0;
}
