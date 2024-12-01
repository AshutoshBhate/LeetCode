/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

//Function to push an element into the queue.
void MyQueue :: push(int x)
{
    QueueNode* Temp = new QueueNode(x); 
    if (Temp == nullptr)
        cout << "Queue is Full" << endl;
    else
    {
        if (front == nullptr)
        {
            front = Temp;
            rear = Temp;
        } 
        else
        {
            rear->next = Temp;
            rear = Temp;
        }
    }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
    if(front == NULL)
    {
        return -1;
    }
    QueueNode* ptr = front;
    int poppedVal = front -> data;
    front = front -> next;
    delete(ptr);
    
    return poppedVal;
}