#include <iostream>
#include <fstream>
using namespace std;

class floor;

class object
{
    friend floor;
    private:
        int ob_row;
        int ob_col;
        char ob_type;
        //adjList adjlist;
    public:
        object(int r, int c, char tpye);
        ~object();

};

object::object(int r, int c, char type): ob_row(r), ob_col(c), ob_type(type) {};

object::~object()
{
    ob_row = 0;
    ob_col = 0;
    ob_type = '0';

};

class floor
{
    private:
        int row;
        int col;
        object ***map;
    public:
        floor(int r, int c);
        ~floor();
        void Add_Object(int r, int c, char type);
        void Print();
        char Show_Type(int i, int j);
};

floor::floor(int r, int c): row(r), col(c)
{
    map = new object** [row];
    for (int i = 0; i < row; i++) {
        map[i] = new object* [col];
    }
};

floor::~floor()
{
    for (int i = 0; i < row; i++) {
        delete map[i];
    }
    delete map;
};

void floor::Add_Object(int i, int j, char type)
{
    map[i][j] = new object (i, j, type);
};

void floor::Print()
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << map[i][j]->ob_type << " ";
        }
        cout << endl;
    }
};

char floor::Show_Type(int i, int j)
{
    return map[i][j]->ob_type;
};

int main(int argc, char *argv[])
{
    int row;
    int col;
    int battery;
    char object_type;

    ifstream infile;
    infile.open(argv[1]);

    // check if the data can be opened
    if (!infile.is_open()) {                                                    
        cout << "Caonnot open file!" << endl;
        return 0;
    }

    infile >> row >> col >> battery;
    cout << row << " " << col << " " << battery << endl;
    
    floor F(row, col);                                          // construct a floor

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            infile >> object_type;
            // check if the testcase is valid
            if (!(object_type == '0' || object_type == '1' || object_type == 'R')) {        
                cout << "invalid testcase parameter!" << endl;
                return 0;
            }
            F.Add_Object(i, j, object_type);            
        }
    }

    F.Print();

    ofstream outfile("108061201_proj2.path");
    if (outfile.is_open()) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                outfile << F.Show_Type(i, j) << "";
            }
            outfile << endl;
        }
        outfile.close();
    }


//    bool *visited;
//    visited = new bool [4];
//    fill(visited, visited + 4, true);
//    //visited[0] = true;
//
//    for (bool *i = visited; i < visited + 4; i++) {
//        cout << *i << " ";
//    }
//    cout << endl;

    return 0;
} 