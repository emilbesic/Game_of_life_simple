#include <iostream>
#include <vector>
using namespace std;
  
// Defining the rows and columns of
// vector of vectors

  
int main()
{
    
    int ROW = 0;
    int COL = 0;
    cout << "Rows"<<endl;
    cin >> ROW ;
    cout << "Columns"<<endl;
    cin >> COL ;
    
    // Initializing the vector of vectors
    vector<vector<int> > vec;
  
    // Elements to insert in column
    int num = 0;
  
    // Inserting elements into vector
    for (int i = 0; i < COL; i++) {
        vector<int> v1;
  
        for (int j = 0; j < ROW; j++) {
            cin >> num;
            v1.push_back(num);
        }
        cout << "next"<< endl;
        // Pushing back above 1D vector
        // to create the 2D vector
        vec.push_back(v1);
    }
  
    // Displaying the 2D vector
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++){
            cout << vec[i][j] << " ";
        
    }
    cout << endl;
    }
    return 0;
}

