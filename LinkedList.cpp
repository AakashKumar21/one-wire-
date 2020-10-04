#include<bits/stdc++.h>

using namespace std;

class Node {

public:
	int data;
	Node* next;

	Node(int d)
	{
		data = d;
		next = NULL;
	}
};

Node* createLL() {

	Node* head = NULL;
	Node* tail = NULL;

	int n;
	cin >> n;

	while (n != 0)
	{
		int x;
		cin >> x;

		Node* newNode = new Node(x);

		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}

		else
		{
			tail->next = newNode;
			tail = tail->next;
		}

		--n;
	}

	return head;
}

Node* secondLastNode(Node* head)
{
	if (head == NULL)
		return NULL;

	if (head->next->next == NULL)
		return NULL;

	while (head->next->next)
		head = head->next;

	cout << "2nd Last Node: " << head->data << endl;

	return head;
}

Node* moveLastNodeFirst(Node* head)
{
	if (head == NULL || head->next == NULL)
		return NULL;

	Node* front = head;

	Node* prev = head;
	while (head->next)
	{
		prev = head;
		head = head->next;
	}

	head->next = front;
	prev->next = NULL;

	return head;
}

Node* reverseIterative(Node* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	Node* cur = head;
	Node* prev = NULL;

	Node* N;

	while (cur)
	{
		Node* N = cur->next;
		cur->next = prev;

		prev = cur;
		cur = N;
	}

	return cur;
}

void insertMiddle(Node* &head, int data, int pos)
{
	Node* newNode = new Node(data);

	if (pos == 1)
	{
		newNode->next = head;
		head = newNode;
		return;
	}

	else
	{
		Node* tempHead = head;

		for (int i = 1 ; i < pos - 1 ; i++)
		{
			if (tempHead->next == NULL)
			{
				cout << endl << "Out of bound";

				while (i != pos - 1)
				{
					tempHead->next = new Node(-1);
					tempHead = tempHead->next;
					i++;
				}

				tempHead->next = newNode;

				return;
			}
			tempHead = tempHead->next;
		}

		Node* leftNode = tempHead;
		Node* rightNode = tempHead->next;

		leftNode->next = newNode;
		newNode->next = rightNode;
	}


}

void deleteNode(Node* &head, int pos)
{
	Node* temp = head;

	if (pos == 1)
	{
		head = head->next;
		delete temp;
		return;
	}

	else
	{
		Node* prev = NULL;

		for (int i = 1 ; i < pos ; i++)
		{

			if (temp->next == NULL)
			{
				cout << endl << "Out of bound";
				return;
			}
			prev = temp;
			temp = temp->next;
		}

		Node* nextNode = temp->next;
		prev->next = nextNode;
		delete temp;
	}
}

int _searchRecursively(Node* head, int key, int& pos)
{
	if (head == NULL)
	{
		pos = -1;
		return (pos = -1);
	}

	if (head->data == key)
	{
		pos = pos + 1;
		return pos;
	}
	else
	{
		pos = pos + 1;
		return _searchRecursively(head->next, key, pos);
	}

}

int searchRecursively(Node* head, int key)
{
	int pos = 0;
	_searchRecursively(head, key, pos);
	return pos;
}

Node* reverseLL(Node* head)
{
	if (head->next == NULL)
		return head;

	Node* reverseLLNode = reverseLL(head->next);

	head->next->next = head;
	head->next = NULL;

	return reverseLLNode;
}

void printLL(Node* head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

void midPoint(Node* head)
{
	Node* slow = head;
	Node* fast = head;

	while (fast->next != NULL)
	{
		if (fast->next->next == NULL)
			break;

		slow = slow->next;
		fast = fast->next->next;

	}

	if (fast->next == NULL)
		cout << endl << "ODD " << slow->data;
	else
		cout << endl << "EVEN " << slow->data << " & " << slow->next->data;

}

void kthNodefromEnd(Node* head)
{
	Node* slow = head;
	Node* fast = head;

	cout << endl << "Enter k : ";
	int k;
	cin >> k;

	while (k - 1 != 0)
	{
		if (fast->next == NULL)
		{
			cout << endl << "ERROR: OUT OF BOUND";
			return;
		}

		fast = fast->next;
		--k;
	}

	while (fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}

	cout << "kthNodefromEnd is " << slow->data;
}

Node* mergeTwoSortedLinkedList(
    Node* head1,
    Node* head2)
{
	Node* head = new Node(-1);
	Node* tail = head;

	while (head1 != NULL && head2 != NULL)
	{
		if (head1->data < head2->data)
		{
			tail->next = head1;
			head1 = head1->next;
		}
		else
		{
			tail->next = head2;
			head2 = head2->next;
		}
		tail = tail->next;
	}

	if (head1 == NULL)
		tail->next = head2;
	else
		tail->next = head1;

	return head;
}

Node* swapPairsIterative(Node* head)
{
	Node* new_start = head->next;

	Node* p = head;
	Node* q;
	Node* temp;

	while (1)
	{
		//Assigning variables
		q = p->next;
		temp = q->next;

		//Manipulating pointers
		q->next = p;

		if (temp == NULL || temp->next == NULL)
		{
			p->next = temp;
			break;
		}
		p->next = temp->next;

		p = temp;
	}

	return new_start;
}

Node* swapPairsRecursive(Node* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	Node* rem = head->next->next;

	Node* newhead = head->next;

	head->next->next = head;

	head->next = swapPairsRecursive(rem);

	return newhead;
}

int count(Node* A)
{
	int count = 0;
	while (A != NULL)
		++count;

	return count;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);

	freopen("output.txt", "w", stdout);
#endif

	Node* head1 = createLL();

	midPoint(head1);

	// cout << "Head 1 : ";
	// printLL(head1);
	// cout << endl << "Head 2 : ";
	// printLL(head2);

	// cout << endl << "After merging Head :";
	// printLL(mergeTwoSortedLinkedList(head1, head2));

}
