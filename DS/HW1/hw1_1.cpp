#include <iostream>

using namespace std;


template <typename T>
struct Link
{
    T data;
    Link *next;
};

template <typename T>
class Queue
{
private:
    Link<T> *head, *tail;

public:
    Queue();
    ~Queue();
    void push(T data);
    T pop();
    bool empty() { return head == NULL; }
};

template <typename T>
Queue<T>::Queue()
{
    head = NULL;
    tail = NULL;
}

template <typename T>
Queue<T>::~Queue()
{
    while (!empty())
    {
        pop();
    }
}
template <typename T>

void Queue<T>::push(T data)
{
    if (head == NULL)
    {
        head = new Link<T>;
        head->data = data;
        head->next = NULL;
        tail = head;
    }
    else
    {
        tail->next = new Link<T>;
        tail = tail->next;
        tail->data = data;
        tail->next = NULL;
    }
}
template <typename T>

T Queue<T>::pop()
{
    Link<T> *p = head;
    T r = p->data;
    head = p->next;
    free(p);
    return r;
}

struct Node
{
    int y, x;
    Node(){};
    Node(int y, int x) : y(y), x(x){};
};

int main()
{
    bool debug = true;
    debug = false;
    
    int r, c;
    while (cin >> r >> c)
    {
        char maze[r][c];
        int step_map[r][c];
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> maze[i][j];
                step_map[i][j] = -1;
            }
        }

        // find start & end
        int start_x, start_y, end_y, end_x;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (maze[i][j] == '.')
                {
                    start_x = j;
                    start_y = i;
                }
                if (maze[i][j] == '@')
                {
                    end_y = i;
                    end_x = j;
                    maze[i][j] = '*';
                }
            }
        }

        // BFS
        Queue<Node> nodes;
        nodes.push(Node(start_y, start_x));
        step_map[start_y][start_x] = 0;

        while (!nodes.empty())
        {
            Node node = nodes.pop();
            int step = step_map[node.y][node.x] + 1;

            // up
            if (node.y > 0)
            {
                if (maze[node.y - 1][node.x] == '*' && step_map[node.y - 1][node.x] == -1)
                {
                    // push into queue
                    nodes.push(Node(node.y - 1, node.x));
                    // set step
                    step_map[node.y - 1][node.x] = step;
                }
            }
            // down
            if (node.y < r - 1)
            {
                if (maze[node.y + 1][node.x] == '*' && step_map[node.y + 1][node.x] == -1)
                {
                    // push into queue
                    nodes.push(Node(node.y + 1, node.x));
                    // set step
                    step_map[node.y + 1][node.x] = step;
                }
            }
            // left
            if (node.x > 0)
            {
                if (maze[node.y][node.x - 1] == '*' && step_map[node.y][node.x - 1] == -1)
                {
                    // push into queue
                    nodes.push(Node(node.y, node.x - 1));
                    // set step
                    step_map[node.y][node.x - 1] = step;
                }
            }
            // right
            if (node.x < c - 1)
            {
                if (maze[node.y][node.x + 1] == '*' && step_map[node.y][node.x + 1] == -1)
                {
                    // push into queue
                    nodes.push(Node(node.y, node.x + 1));
                    // set step
                    step_map[node.y][node.x + 1] = step;
                }
            }
        }

        // return result
        cout << step_map[end_y][end_x] << endl;
        if (debug)
        {
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    cout << step_map[i][j];
                }
                cout << endl;
            }
        }
    }
}