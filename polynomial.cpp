#include <iostream>
using namespace std;

struct Node
{
    Node *next;
    int coeff;
    int power; 

    Node(int coeff, int power)
    {
        this->coeff=coeff;
        this->power=power;
        next=nullptr;
    }

};
class polynomial
{
    Node *head;

    public:
        polynomial ()
        {
            head =nullptr;
        }

        void read()
        {
            int terms;
            cout<<"Enter no of terms ";
            cin>>terms;

            int power , coeff;
            for(int i=0;i<terms;i++)
            {
                cout<<"Enter power ";
                cin>>power;

                cout<<"Enter coeff";
                cin>>coeff;
                }
            insert (coeff , power);
        }
        void insert(int coeff , int power)
        {
            Node *new_node=new Node(coeff , power);

            if(head=nullptr)
            {
                head=new_node;
            }

            else
            {
                Node *curr=head;
                Node *prev=nullptr;
                
                while(curr && curr->power > power)
                {
                    prev=curr;
                    curr=curr->next;

                }
                
            }
        }
        

        
};