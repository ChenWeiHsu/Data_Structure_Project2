#include <iostream>
#include <fstream>
#include <time.h>
#include <chrono>
using namespace std;
/*
#include <stack>
#include <queue>
#include <vector>
#include <list>
*/

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
    //friend AdjList;
    friend Queue;
    friend Stack;
    friend Floor;
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
/*
class AdjList
{
    private:
        AdjNode* first;
        AdjNode* last;
    public:
        AdjList() : first(nullptr), last(nullptr) {};
        ~AdjList(){};
        void Add_Node(int r1, int c1)
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
        };
        bool IsEmpty()
        {
            return (first == nullptr && last == nullptr);
        };
};
*/
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
    friend Object;
    friend Floor;
    //friend AdjNode;
    private:
        AdjNode* first;
        AdjNode* last;
        int capacity;
    public:
        Queue() : first(nullptr), last(nullptr), capacity(0) {};
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
        void Push(AdjNode& n)
        {
            AdjNode* newnode = &n;
            if (IsEmpty()) {
                first = newnode;
                last = newnode;
            }
            else {
                last->next = newnode;
                last = newnode;
            }
            capacity++;
        }
        void Pop()
        {
            if (IsEmpty())
                throw "The queue is empty, there is no element to Pop().";
            AdjNode* deletenode = first;
            first = first->next;
            if (first == nullptr) last = nullptr;
            delete deletenode;
            capacity--;
        };
        bool IsEmpty() const
        {
            return (first == nullptr && last == nullptr);
        };
        AdjNode& Front() const
        {
            if (IsEmpty())
                throw "The queue is empty, there is no front";
            else
                return *first;
        };
        AdjNode& Rear() const
        {
            if (IsEmpty())
                throw "The queue is empty, there is no front";
            else
                return *last;
        };
        void Show()
        {
            AdjNode* curnode = first;
            cout << endl;
            cout << "---QUEUE.Show() QUEUE.Show() QUEUE.Show()---" << endl;
            cout << "Front" << endl;
            if (first == nullptr) cout << "first is null" << endl;
            else {
                cout << "first is not null" << endl;
                cout << "first stores " << "(" << first->r << ", " << first->c << ")" << endl;
            }
            
            while (curnode != nullptr) {
                cout << "(r, c) : " << curnode->r << curnode->c << endl;
                curnode = curnode->next;
            }

            cout << "Rear" << endl;
            if (last == nullptr) cout << "last is null" << endl;
            else {
                cout << "last is not null" << endl;
                cout << "last stores " << "(" << last->r << ", " << last->c << ")" << endl;
            }
            cout << "---QUEUE.Show() QUEUE.Show() QUEUE.Show()---" << endl;
            cout << endl;
        };
        int ShowSize()
        {
            return capacity;
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
        Stack() : top(nullptr), capacity(0) {};
        ~Stack(){};
        void Push(int r1, int c1)
        {
            AdjNode* newnode = new AdjNode(r1, c1);
            if (!IsEmpty()) newnode->next = top;
            top = newnode;
            capacity++;

        };
        void Push(AdjNode& n)
        {
            AdjNode* newnode = &n;
            if (!IsEmpty()) newnode->next = top;
            top =  newnode;
            capacity++;
        };
        void Pop()
        {
            if (IsEmpty())
                throw "The stack is empty, there is no element to Pop().";

            AdjNode* deletenode = top;
            top = top->next;
            delete deletenode;
            capacity--;
        };
        bool IsEmpty() const
        {
            return (top == nullptr);
        };
        AdjNode& Top() const
        {
            if (IsEmpty())
                throw "The stack is empty, there is no top";
            else
                return *top;
        };
        void Show()
        {
            AdjNode* curnode = top;
            cout << endl;
            cout << "---STACK.Show() STACK.Show() STACK.Show()---" << endl;
            cout << "Top" << endl;
            while (curnode != nullptr) {
                cout << "(r, c) : " << curnode->r << " " << curnode->c << endl;
                curnode = curnode->next;
            }
            cout << "---STACK.Show() STACK.Show() STACK.Show()---" << endl;
            cout << endl;
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
        Queue adjlist;
    public:
        Object(int r, int c, char type, int d = -1) : ob_row(r), ob_col(c), ob_type(type), distance_to_R(d) {};
        Object() : ob_row(0), ob_col(0), ob_type('1'), distance_to_R(-1) {};
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
        int original_battery;
        int steps;
        bool** visited;
        
        AdjNode R;
        AdjNode currentnode;
        Object*** map;      // a matirx that store the pointer of the object

        Queue ans;

        //Stack NotVisit;
        //Queue AnsList;
    public:
        Floor(int r, int c, int b);
        ~Floor();
        void Add_Object(int r, int c, char type);
        void Print();
        char Show_Type(int i, int j);
        void Set_Graph();
        void Set_DTR();
        //void Map_DTR(int i, int j);
        void DFS();
        bool Whole_Floor_Viewed();
        void Return_R();
        int Show_Steps();
        void Output();
        int ShowSize(){
            return ans.ShowSize();
        }
};

Floor::Floor(int r, int c, int b): row(r), col(c), battery(b), original_battery(b), steps(0)
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

int Floor::Show_Steps()
{
    return steps - 1;
}
/*
void Floor::Map_DTR(int i, int j)
{
    cout << map[i][j]->distance_to_R << endl;
};
*/
bool Floor::Whole_Floor_Viewed()
{
    bool b = true;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (map[i][j]->ob_type == '0' && visited[i][j] == false) b = false;
        }
    }
    return b;
};

void Floor::Set_Graph()
{
    // set AdjNode R
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (map[i][j]->ob_type == 'R') {
                map[i][j]->distance_to_R = 0;
                R.r = i;
                R.c = j;
            }
        }
    }    

    // set adjlist
    for (int i = 1; i < row - 1; i++) {
        for (int j = 1; j < col - 1; j++) {            
            if (map[i][j]->ob_type != '1') {
                if (map[i - 1][j]->ob_type != '1')
                    map[i][j]->adjlist.Push(i - 1, j);      // up
                if (map[i][j + 1]->ob_type != '1')
                    map[i][j]->adjlist.Push(i, j + 1);      // right
                if (map[i + 1][j]->ob_type != '1')
                    map[i][j]->adjlist.Push(i + 1, j);      // down
                if (map[i][j - 1]->ob_type != '1')
                    map[i][j]->adjlist.Push(i, j - 1);      // left
            }
        }
    }

    // set surrounding adjlist(if R is on the surrounding)
    for (int j = 0; j < col; j++) {
        if (map[0][j]->ob_type == '0')
            throw "Boundary cannot be 0";
        if (map[0][j]->ob_type != '1' && map[1][j]->ob_type != '1')
            map[0][j]->adjlist.Push(1, j);                      // down

        if (map[row - 1][j]->ob_type == '0')
            throw "Boundary cannot be 0";
        if (map[row - 1][j]->ob_type != '1' && map[row - 2][j]->ob_type != '1')
            map[row - 1][j]->adjlist.Push(row - 2, j);          // up
    }

    for (int i = 0; i < row; i++) {
        if (map[i][0]->ob_type == '0')
            throw "Boundary cannot be 0";
        if (map[i][0]->ob_type != '1' && map[i][1]->ob_type != '1')
            map[i][0]->adjlist.Push(i, 1);                      // right
        
        if (map[i][col - 1]->ob_type == '0')
            throw "Boundary cannot be 0";
        if (map[i][col - 1]->ob_type != '1' && map[i][col - 2]->ob_type != '1')
            map[i][col - 1]->adjlist.Push(i, col - 2);          // left
    }


/*    
    // print adjlist
    cout << "---Set_Graph Set_Graph Set_Graph---" << endl;
    cout << endl << "-----------------" << endl;
    for (int i = 0; i <row; i++) {
        for (int j = 0; j < col; j++) {
            cout << "(i, j, type): " << map[i][j]->ob_row << map[i][j]->ob_col << map[i][j]->ob_type << endl;
            cout << "AdjList: ";
            if (map[i][j]->adjlist.IsEmpty()) cout << "None";
            for (AdjNode* curnode = map[i][j]->adjlist.first; curnode != nullptr; curnode = curnode->next) {
                cout << "(" << curnode->r << ", " << curnode->c << ") ";
            }
            cout << endl << "-----------------" << endl;
        }
    }
    cout << "---Set_Graph Set_Graph Set_Graph---" << endl;
*/

};

// set distance_to_R
void Floor::Set_DTR()
{
    // new visited[][]
    visited = new bool* [row];
    for (int i = 0; i < row; i++) {
        visited[i] = new bool [col];
    }

    // initialize visited[][]
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            visited[i][j] = false;
        }
    }

    // set object's distance_to_R
    Queue q;
    AdjNode current_adjnode;
    q.Push(R);
    visited[R.r][R.c] = true;
    while (!q.IsEmpty()) {
        current_adjnode = q.Front();
        
        //cout << "current_adjnode (r, c): (" << current_adjnode.r << ", " << current_adjnode.c << ")" << endl;
        //q.Show();
        q.Pop();
        //cout << "current_adjnode (r, c): (" << current_adjnode.r << ", " << current_adjnode.c << ")" << endl;
        //q.Show();
        for (AdjNode* adjnode = map[current_adjnode.r][current_adjnode.c]->adjlist.first; adjnode != nullptr; adjnode = adjnode->next) {
            if (!visited[adjnode->r][adjnode->c]) {
                q.Push(adjnode->r, adjnode->c);
                visited[adjnode->r][adjnode->c] = true;
                map[adjnode->r][adjnode->c]->distance_to_R = map[current_adjnode.r][current_adjnode.c]->distance_to_R + 1;
            }
        }
    }

    // print distance_to_R in matrix
    cout << endl << "distance_to_R :"<< endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%3d ", map[i][j]->distance_to_R);
        }
        cout << endl;
    }
    cout << endl;

    // delete visited[][]
    for (int i = 0; i < row; i++) {
        delete [] visited[i];
    }
    delete [] visited;
};

void Floor::DFS()
{
    // new visited[][]
    visited = new bool* [row];
    for (int i = 0; i < row; i++) {
        visited[i] = new bool [col];
    }

    // initialize visited[][]
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            visited[i][j] = false;
        }
    }

    Stack s;
    Stack pass;
    bool all_listnode_viewed = true;

    s.Push(R);
    while (!s.IsEmpty()) {
        currentnode = s.Top();
        s.Pop();
        //cout << currentnode.r << " " << currentnode.c << endl;
        if (!visited[currentnode.r][currentnode.c]) {
            visited[currentnode.r][currentnode.c] = true;
            cout << "-----------------------------"  << endl;
            cout << "Now Floor Cleaning Robot is on (" << currentnode.r << ", " << currentnode.c << ")" << endl;
            ans.Push(currentnode.r, currentnode.c);
            cout << "battery : " << battery << endl;
            cout << "steps : " << steps << endl;
            
            if (battery == map[currentnode.r][currentnode.c]->distance_to_R + 1 || battery == map[currentnode.r][currentnode.c]->distance_to_R) {
                cout << "---BACK TO RECHARGE!!!---" << endl;
                Return_R();
            }

            
            pass.Push(currentnode.r, currentnode.c);
            // push adjlist node that hasn't been viewed, if all adjnodes viewed, then no adjlist
            for (AdjNode* curnode = map[currentnode.r][currentnode.c]->adjlist.first; curnode != nullptr; curnode = curnode->next) {
                if (!visited[curnode->r][curnode->c]) {
                    s.Push(curnode->r, curnode->c);
                    all_listnode_viewed = false;
                }
            }

            // if no unviewed adjlist node, go back
            if (all_listnode_viewed) {
                if (Whole_Floor_Viewed())
                    Return_R();
                else {
                    pass.Pop();
                    //cout << pass.Top().r << " " << pass.Top().c << "line 664" << endl;
                    //cout << s.Top().r << " " << s.Top().c << "line 665" << endl;

                    while ((abs(pass.Top().r - s.Top().r) + abs(pass.Top().c - s.Top().c)) != 1) {
                        currentnode.r = pass.Top().r;
                        currentnode.c = pass.Top().c;

                        //cout << pass.Top().r << " " << pass.Top().c << "line 671" << endl;
                        //cout << currentnode.r << " " << currentnode.c << "line 672" << endl;

                        cout << "-----------------------------"  << endl;
                        cout << "Now Floor Cleaning Robot is on (" << currentnode.r << ", " << currentnode.c << ")" << endl;
                        ans.Push(currentnode.r, currentnode.c);
                        //outfile << currentnode.r << " " << currentnode.c << endl;
                        cout << "battery : " << battery << endl;
                        cout << "steps : " << steps << endl;                    
                        battery--;
                        steps++;
                        pass.Pop();
                        //cout << "battery : " << battery << endl;
                        //cout << "Now Floor Cleaning Robot is on (" << currentnode.r << ", " << currentnode.c << ")" << endl;
                        
                        //if (battery <= map[currentnode.r][currentnode.c]->distance_to_R + 1) {
                        if (battery == map[currentnode.r][currentnode.c]->distance_to_R + 1 || battery == map[currentnode.r][currentnode.c]->distance_to_R) {
                            cout << "---BACK TO RECHARGE!!!---" << endl;
                            Return_R();
                        }
                    }
                    currentnode.r = pass.Top().r;
                    currentnode.c = pass.Top().c;
                    cout << "-----------------------------"  << endl;
                    cout << "Now Floor Cleaning Robot is on (" << currentnode.r << ", " << currentnode.c << ")" << endl;
                    ans.Push(currentnode.r, currentnode.c);
                    //outfile << currentnode.r << " " << currentnode.c << endl;
                    cout << "battery : " << battery << endl;
                    cout << "steps : " << steps << endl;
                    battery--;
                    steps++;
                    if (battery == map[currentnode.r][currentnode.c]->distance_to_R + 1 || battery == map[currentnode.r][currentnode.c]->distance_to_R) {
                        cout << "---BACK TO RECHARGE!!!---" << endl;
                        Return_R();
                    }
                }
            }
            all_listnode_viewed = true;
            battery--;
            steps++;
        }
    }

    // delete visited[][]
    for (int i = 0; i < row; i++) {
        delete [] visited[i];
    }
    delete [] visited;
};

void Floor::Return_R()
{
    int temp_row;
    int temp_col;
    Stack return_pass;
    // find the distance is minus one and go
    return_pass.Push(currentnode.r, currentnode.c);
    while (!(currentnode.r == R.r && currentnode.c == R.c)) {
        for (AdjNode* nextnode = map[currentnode.r][currentnode.c]->adjlist.first; nextnode != nullptr; nextnode = nextnode->next) {
            if (map[nextnode->r][nextnode->c]->distance_to_R == map[currentnode.r][currentnode.c]->distance_to_R - 1) {
                temp_row = nextnode->r;
                temp_col = nextnode->c;            
            }
        }
        currentnode.r = temp_row;
        currentnode.c = temp_col;
        battery--;
        steps++;
        cout << "-----------------------------"  << endl;
        cout << "Now Floor Cleaning Robot is on (" << currentnode.r << ", " << currentnode.c << ")" << endl;
        ans.Push(currentnode.r, currentnode.c);
        //outfile << currentnode.r << " " << currentnode.c << endl;
        cout << "battery : " << battery << endl;
        cout << "steps : " << steps << endl;
        return_pass.Push(currentnode.r, currentnode.c);
    }

    if (!Whole_Floor_Viewed()) {
        return_pass.Pop();
        battery = original_battery;

        while (!return_pass.IsEmpty()) {
            currentnode.r = return_pass.Top().r;
            currentnode.c = return_pass.Top().c;
            battery--;
            steps++;
            cout << "-----------------------------"  << endl;
            cout << "Now Floor Cleaning Robot is on (" << currentnode.r << ", " << currentnode.c << ")" << endl;
            ans.Push(currentnode.r, currentnode.c);
            //outfile << currentnode.r << " " << currentnode.c << endl;
            cout << "battery : " << battery << endl;
            cout << "steps : " << steps << endl;
            return_pass.Pop();
        }
    }
};

void Floor::Output()
{
    ofstream outfile("108061201_proj2.path");
    if (outfile.is_open()) {
        outfile << Show_Steps() << endl;
        for (; !ans.IsEmpty(); ans.Pop()) {
            outfile << ans.Front().r << " " << ans.Front().c << endl;        
        }
    }
    else
        cout << "Cannot open output file!" << endl;
    outfile.close();
};
/*
void Floor::GoTO(int dest_row, int dest_col)
{

};
*/
////////////////////////////////////////////////////////////////////////////
/*
                Floor definition start
*/
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
/*
                main program start
*/
////////////////////////////////////////////////////////////////////////////
int main(int argc, char *argv[])
{
    int row;
    int col;
    long battery;
    char object_type;
    clock_t start = clock();

    ifstream infile;
    infile.open(argv[1]);

    // check if the data can be opened
    if (!infile.is_open()) {
        cout << "Cannot open input file!" << endl;
        return 0;
    }

    infile >> row >> col >> battery;
    if (row > 1000) {
        cout << "Row exceed 1000" << endl;
        return 0;
    }
    if (col > 1000) {
        cout << "Col exceed 1000" << endl;
        return 0;
    }
    cout << "row: " << row << "   " << "col: " << col << "   " << "battery: " << battery << endl;

    Floor F(row, col, (int)battery);            // construct a floor

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            infile >> object_type;
            // check if the testcase is valid
            if (!(object_type == '0' || object_type == '1' || object_type == 'R')) {        
                cout << object_type << endl;
                cout << "Battery exceed maximum or Invalid testcase parameter!" << endl;
                return 0;
            }
            F.Add_Object(i, j, object_type);            
        }
    }
    infile.close();

    //F.Print();
    F.Set_Graph();
    F.Set_DTR();
    F.DFS();
    cout << F.ShowSize() << endl;
    F.Output();
    
    //OUTPUT FILE


//    bool *visited;
//    visited = new bool [4];
//    fill(visited, visited + 4, true);
//    //visited[0] = true;
//
//    for (bool *i = visited; i < visited + 4; i++) {
//        cout << *i << " ";
//    }
//    cout << endl;

    clock_t end = clock();
    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time: " << time_taken << endl;
    return 0;
}