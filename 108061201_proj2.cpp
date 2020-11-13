#include <iostream>
#include <fstream>
using namespace std;
#include <stack>
#include <queue>
#include <vector>
#include <list>


// forward declaration
class AdjNode;
class AdjList;
class Queue;
class Stack;
class Object;
class Floor;

////////////////////////////////////////////////////////////////////////////
/*
                Node definition start
*/
////////////////////////////////////////////////////////////////////////////

/*
template <class T>
class Node
{
    friend class Queue<T>;
    friend class Stack<T>;
    private:
        T value;
        Node<T>* next;
    public:
        Node(const T& x) : value(x), next(nullptr) {};
        ~Node(){};
};
*/

class AdjNode                       // element of adjlist, which store r and c
{
    friend AdjList;
    friend Queue;
    friend Stack;
    //friend class floor;
    private:
        int r;
        int c;
        AdjNode* next;
    public:
        AdjNode() : r(0), c(0), next(nullptr) {};
        AdjNode(int r1, int c1) : r(r1), c(c1), next(nullptr) {};
        ~AdjNode(){};
};
////////////////////////////////////////////////////////////////////////////
/*
                Node definition end
*/
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
/*
                AdjList definition start
*/
////////////////////////////////////////////////////////////////////////////
class AdjList
{
    private:
        AdjNode* first;
        AdjNode* last;
    public:
        AdjList() : first(nullptr), last(nullptr) {};
        ~AdjList(){};
};

////////////////////////////////////////////////////////////////////////////
/*
                AdjList definition end
*/
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
/*
                Queue definition start
*/
////////////////////////////////////////////////////////////////////////////

class Queue
{
    private:
        AdjNode* first;
        AdjNode* last;
        int capacity;
    public:
        Queue() : first(nullptr), last(nullptr), capacity(0){};
        ~Queue(){};        
        void Push(int r1, int c1)
        {
            AdjNode* newnode = new AdjNode(r1, c1);
            if (IsEmpty()) {
                first = newnode;
                last = newnode;
            }
            else {
                last->next = newnode;
                last = newnode;
            }
            capacity++;
        };        
        void Pop()
        {
            if (IsEmpty()) {
                throw "The queue is empty, there is no element to Pop().";
                return;
            }
            AdjNode* deletenode = first;
            first = first->next;
            delete deletenode;
            capacity--;
        };
        bool IsEmpty() const
        {
            return (first == nullptr && last == nullptr);
        };
        /*
        T& Front() const
        {
            if (IsEmpty())
                throw "The queue is empty, there is no front.";
            else
                return first->value;
        };
        T& Rear() const
        {
            if (IsEmpty())
                throw "The queue is empty, there is no rear.";
            else
                return last->value;
        };
        */
        void Show()
        {
            AdjNode* currentnode = first;
            cout << "Front" << endl;
            while (currentnode != nullptr) {
                cout << "(r, c) : " << currentnode->r << currentnode->c << endl;
                currentnode = currentnode->next;
            }
            cout << "Rear" << endl;

        };
};

////////////////////////////////////////////////////////////////////////////
/*
                Queue definition end
*/
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
/*
                Stack definition start
*/
////////////////////////////////////////////////////////////////////////////

class Stack
{
    private:
        AdjNode* top;
        int capacity;
    public:
        Stack()
        {
            top = nullptr;
            capacity = 0;
        };
        ~Stack(){};
        void Push(int r1, int c1)
        {
            AdjNode* newnode = new AdjNode(r1, c1);
            if (!IsEmpty()) newnode->next = top;
            top = newnode;
            capacity++;

        };
        void Pop()
        {
            if (IsEmpty()) {
                throw "The stack is empty, there is no element to Pop().";
                return;
            }
            AdjNode* deletenode = top;
            top = top->next;
            delete deletenode;
            capacity--;
        };
        bool IsEmpty() const
        {
            return (top == nullptr);
        };
        /*
        T& Top() const
        {
            return top->value;
        };
        */
        void Show()
        {
            AdjNode* currentnode = top;
            cout << "Top" << endl;
            while (currentnode != nullptr) {
                cout << "(r, c) : " << currentnode->r << currentnode->c << endl;
                currentnode = currentnode->next;
            }
            cout << "End" << endl;
        };
};

////////////////////////////////////////////////////////////////////////////
/*
                Stack definition end
*/
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
/*
                object definition start
*/
////////////////////////////////////////////////////////////////////////////

class Object
{
    friend Floor;
    private:
        int ob_row;
        int ob_col;
        char ob_type;
        int distance_to_R;
        AdjList adjlist;
        //AdjNode parent;
    public:
        Object(int r, int c, char type, int d = 0): ob_row(r), ob_col(c), ob_type(type), distance_to_R(d) {};
        Object(){};
        ~Object(){};
        int Row()
        {
            return ob_row;
        };
        int Col()
        {
            return ob_col;
        };
        char Type()
        {
            return ob_type;
        };
        int Distance_to_R()
        {
            return distance_to_R;
        };

};

////////////////////////////////////////////////////////////////////////////
/*
                Object definition end
*/
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
/*
                Floor definition start
*/
////////////////////////////////////////////////////////////////////////////














/*
class object
{
    private:
        AdjList adjlist;    // an adjlist with element adjnodes
        int distance_to_R;
        int ob_r;
        int ob_c;
        char ob_type;
        //adjnode parent;

}

class AdjList
{
    private:
        AdjList* first;
        AdjList* last;
    public:
        AdjList()
        {
            first = nullptr;
            last = nullptr;
        };
        ~AdjList();

};
class AdjNode                       // element of adjlist, which store r and c
{
    friend class AdjList;
    //friend class floor;
    private:
        int r;
        int c;
        AdjNode* next;
    public:
        AdjNode()
        {
            r = 0;
            c = 0;
            next = nullptr;
        };
        AdjNode(int r, int c)
        {
            r = r;
            c = c;
            next = nullptr;
        };
        ~AdjNode(){};
}
*/
















class Floor
{
    private:
        int row;            // the total row of the floor
        int col;            // the total col of the floor
        int battery;        // battery of the floor clean robot
        bool** visited;
        
        Object R;
        Object*** map;      // a matirx that store the pointer of the object

        Stack NotVisit;
        Queue AnsList;
    public:
        Floor(int r, int c, int b);
        ~Floor();
        void Add_Object(int r, int c, char type);
        void Print();
        char Show_Type(int i, int j);
};

Floor::Floor(int r, int c, int b): row(r), col(c), battery(b)
{
    map = new Object** [row];
    for (int i = 0; i < row; i++) {
        map[i] = new Object* [col];
    }
};

Floor::~Floor()
{
    for (int i = 0; i < row; i++) {
        delete map[i];
    }
    delete map;
};

void Floor::Add_Object(int i, int j, char type)
{
    map[i][j] = new Object(i, j, type);
};

void Floor::Print()
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << map[i][j]->ob_type;
        }
        cout << endl;
    }
};

char Floor::Show_Type(int i, int j)
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
    
    Floor F(row, col, battery);                                          // construct a floor

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