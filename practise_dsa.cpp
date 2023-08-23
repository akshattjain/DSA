#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    
    Node(int data)
    {
        this->data=data;
        this->next=nullptr;
    }
};
class MyLinkedList
{
    private:
        Node *head;
    
    public:
        MyLinkedList()
        {
            head=nullptr;
        }
        
        void printList()
        {
            if (head==nullptr)
            {
                return;
            }
            else
            {
                Node *currentNode=head;
                while(currentNode!=nullptr)
                {
                    cout<<currentNode->data << "->";
                    currentNode=currentNode->next;
                }
                cout<<"NUll"<<endl;
            }
        }
        int  search(int  data)
        {
            int position=1;
            Node *searchNode=head;
            while(searchNode!=nullptr)
            {
                if (searchNode->data==data)
                {
                    return position;
                    break;

                }
                searchNode=searchNode->next;
                position++;
            }
            return -1;
        }
        int size()
        {
            return 0;
        }
        void insertAtFirst(int data)
        {
            Node *newNode = new Node(data);
            if (head==nullptr)
            {
                newNode->next=nullptr;
            }
            else
            {
                newNode->next=head;
            }
            head=newNode;
        }
        void insertAtEnd(int data)
        {
            Node *lastNode = new Node(data);
            lastNode->next=nullptr;
            if(head==nullptr)
            {
                head=lastNode;
            }
            else
            {
                Node *temp=head;
                while(temp->next!=nullptr)
                {
                    temp=temp->next;
                }
                temp->next=lastNode;
            }
        }
        void insert(int data,int position)
        {
            
        }
};

int main ()
{
    MyLinkedList *myList = new MyLinkedList;
    myList->insertAtEnd(20);
    myList->insertAtFirst(10);
    myList->insertAtEnd(30);
    myList->insertAtFirst(0);
    cout << myList->search(30) << endl;
    myList->printList();
    cout << myList->size() << endl;
    return 0;
}