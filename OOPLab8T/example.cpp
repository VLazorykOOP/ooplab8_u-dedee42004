#include "example.h"
#include <string>
#include <iostream>
using namespace std;
namespace Fun {
    //  ôóíêö³ÿ - øàáëîí
    template <typename T>
    void Search(T A[], int n) {
        T max = A[0], min = A[0];
        int mi = 0, ma = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (A[i] > max) { max = A[i]; ma = i; }
            if (A[i] < min) { min = A[i]; mi = i; }
        }
        A[ma] = min;
        A[mi] = max;
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    //ñïåöèô³êàö³ÿ ôóíêö³¿ - øàáëîí äëÿ òèïó char*
    template<>  void Search(char* A[], int n)
    {
        char* max = A[0]; char* min = A[0];
        int mi = 0, ma = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (strcmp(max, A[i]) == 1) { max = A[i]; ma = i; }
            if (strcmp(A[i], min) == 1) { min = A[i]; mi = i; }
        }
        A[ma] = min;
        A[mi] = max;
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }

    int fmain()
    {
        cout << "template\n";
        int  a[10] = { 1,7,2,-1,0,11,7,2,8,0 };
        double t[10] = { 2,8,9.2,0.2,6.3,8.76,8.7,12,12.8,10 };
        char  s[10] = { 'a','u','c','p','s','b','z','s','s','t' };
        cout << "Int: " << endl;
        Search(a, 10);
        cout << "Double: " << endl;
        Search(t, 10);
        cout << "Char: " << endl;
        Search(s, 10);
        cout << "Char* " << endl;
        char* b[5] = { (char*)"zext",(char*)"bogaboga",(char*)"aabo",(char*)"texta",(char*)"sasha" };
        Search(b, 5);
        return 0;
    }
}
namespace Fun1 {
        //  ôóíêö³ÿ - øàáëîí
        template <typename T>
        void Sort(T arr[], int n)
        {
            T key;
            for (int i = 1; i < n; i++)
            {
                key = arr[i];
                int j = i - 1;
                while (j >= 0 && arr[j] > key)
                {
                    arr[j + 1] = arr[j];
                    j = j - 1;
                }
                arr[j + 1] = key;
            }
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

        //ñïåöèô³êàö³ÿ ôóíêö³¿ - øàáëîí äëÿ òèïó char*
    template<>  void Sort(char* arr[], int n)
    {
         char* key;
         for (int i = 1; i < n; i++) 
         {
                key = arr[i];
                int j = i - 1;
                while (j >= 0 && strcmp(arr[j], key) == 1)
                {
                    arr[j + 1] = arr[j];
                    j = j - 1;
                }
                arr[j + 1] = key;
         }
         for (int i = 0; i < n; i++)
         {
            cout << arr[i] << " ";
         }
         cout << endl;
    }

    int smain()
    {
		 cout << endl;
         cout << "Sorted template\n";
         int  a[10] = { 1,7,2,-1,0,11,7,2,8,0 };
         double t[10] = { 2,8,9.2,0.2,6.3,8.76,8.7,12,12.8,10 };
         char  s[10] = { 'a','u','c','p','s','b','z','s','s','t' };
         cout << "Int: " << endl;
         Sort(a, 10);
         cout << "Double: " << endl;
         Sort(t, 10);
         cout << "Char: " << endl;
         Sort(s, 10);
         cout << "Char* " << endl;
         char* b[5] = { (char*)"zext",(char*)"bogaboga",(char*)"aabo",(char*)"texta",(char*)"sasha" };
         Sort(b, 5);
         return 0;
    }
}
namespace Spus
{
	template<typename T>
	class List
	{
	public:
		List();
		~List();
		void pop_front();
		void push_back(T data);
		void clear();
		int GetSize() { return Size; }
		T& operator[](const int index);
		void push_front(T data);
		void insert(T data, int index);
		void removeAt(int index);
		void pop_back();
	private:

		template<typename T>
		class Node
		{
		public:
			Node* pNext;
			T data;
			Node(T data = T(), Node* pNext = nullptr)
			{
				this->data = data;
				this->pNext = pNext;
			}
		};
		int Size;
		Node<T>* head;
	};

	template<typename T>
	List<T>::List()
	{
		Size = 0;
		head = nullptr;
	}

	template<typename T>
	List<T>::~List()
	{
		clear();
	}

	template<typename T>
	void List<T>::push_front(T data)
	{
		head = new Node<T>(data, head);
		Size++;
	}

	template<typename T>
	void List<T>::push_back(T data)
	{
		if (head == nullptr)
		{
			head = new Node<T>(data);
		}
		else
		{
			Node<T>* current = this->head;
			while (current->pNext != nullptr)
			{
				current = current->pNext;
			}
			current->pNext = new Node<T>(data);
		}
		Size++;
	}

	template<typename T>
	void List<T>::clear()
	{
		while (Size)
		{
			pop_front();
		}
	}

	template<typename T>
	T& List<T>::operator[](const int index)
	{
		int counter = 0;
		Node<T>* current = this->head;
		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pNext;
			counter++;
		}
	}

	template<typename T>
	void List<T>::insert(T data, int index)
	{

		if (index == 0)
		{
			push_front(data);
		}
		else
		{
			Node<T>* previous = this->head;

			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->pNext;
			}
			Node<T>* newNode = new Node<T>(data, previous->pNext);
			previous->pNext = newNode;
			Size++;
		}
	}

	template<typename T>
	void List<T>::removeAt(int index)
	{
		if (index == 0)
		{
			pop_front();
		}
		else
		{
			Node<T>* previous = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->pNext;
			}
			Node<T>* toDelete = previous->pNext;
			previous->pNext = toDelete->pNext;
			delete toDelete;
			Size--;
		}
	}

	template<typename T>
	void List<T>::pop_front()
	{
		Node<T>* temp = head;
		head = head->pNext;
		delete temp;
		Size--;

	}

	template<typename T>
	void List<T>::pop_back()
	{
		removeAt(Size - 1);
	}
	int gmain()
	{
		setlocale(LC_ALL, "ukr");
		cout << endl << "Ñïèñîê: " << endl;
		List<int> lst;
		lst.push_front(5);
		lst.push_front(7);
		lst.push_front(101);
		lst.push_front(1);
		lst.push_front(15);
		lst.push_front(11);
		lst.push_front(10);
		lst.push_front(151);
		for (int i = 0; i < lst.GetSize(); i++)
		{
			cout << lst[i] << " ";
		}
		cout << endl << "pop_back + pop_front " << endl << endl;
		lst.pop_back();
		lst.pop_front();
		for (int i = 0; i < lst.GetSize(); i++)
		{
			cout << lst[i] << " ";
		}
		cout << endl << "remove: " << endl << endl;
		lst.removeAt(2);
		for (int i = 0; i < lst.GetSize(); i++)
		{
			cout << lst[i] <<" ";
		}
		cout << endl << "insert: " << endl << endl;
		lst.insert(65, 1);
		for (int i = 0; i < lst.GetSize(); i++)
		{
			cout << lst[i] << " ";
		}
		lst.clear();
		cout << endl<<endl << "String List:" << endl;
		List<string> lst1;
		lst1.push_front("apple");
		lst1.push_front("car");
		lst1.push_front("banana");
		lst1.push_front("people");
		lst1.push_front("earth");
		lst1.push_front("hostel");
		lst1.push_front("nana");
		lst1.push_front("uni");
		for (int i = 0; i < lst1.GetSize(); i++)
		{
			cout << lst1[i] << " ";
		}
		cout << endl << "pop_back + pop_front " << endl << endl;
		lst1.pop_back();
		lst1.pop_front();
		for (int i = 0; i < lst1.GetSize(); i++)
		{
			cout << lst1[i] << " ";
		}
		cout << endl << "remove: " << endl << endl;
		lst1.removeAt(2);
		for (int i = 0; i < lst1.GetSize(); i++)
		{
			cout << lst1[i] << " ";
		}
		cout << endl << "insert: " << endl << endl;
		lst1.insert("bonjur", 1);
		for (int i = 0; i < lst1.GetSize(); i++)
		{
			cout << lst1[i] << " ";
		}
		lst1.clear();
		return 0;
	}
}

void example()
{
    Fun::fmain();
    Fun1::smain();
	Spus::gmain();
}
