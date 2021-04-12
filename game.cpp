#include <iostream>
#include <vector>
using namespace std;
  

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
vector<vector<int> > initial(int Row, int Col){
    vector<vector<int> > vec;
  
    // Elements to insert in column
    int num = 0;
  
    // Inserting elements into vector
    for (int i = 0; i < Col; i++) {
        vector<int> v1;
  
        for (int j = 0; j < Row; j++) {
            cin >> num;
            v1.push_back(num);
        }
        cout << "next row"<< endl;
        // Pushing back above 1D vector
        // to create the 2D vector
        vec.push_back(v1);
    }
    return vec;
}
void print_vec(int Row,int Col,vector<vector<int> > vec){
    for (uint8_t i = 0; i < vec.size(); i++) {
        for (uint8_t j = 0; j < vec[i].size(); j++){
            cout << vec[i][j] << " ";
        
    }
    cout << endl;
}
}
int main()
{
    
    int Row = askRows();
    int Col = askColumns();
    vector<vector<int> > vec = initial(Row,Col);
    
    // Displaying the 2D vector
    print_vec(Row,Col,vec);

    return 0;
}


