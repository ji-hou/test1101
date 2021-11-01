// data: 2021/09/21
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Mystack {
private:
	struct Node
	{
		char data;
		Node* next;
	};
public:
	Node* head; //ջ��ָ��
	int size; //ջ��С
	Mystack() {
		head = nullptr;
		size = 0;
	}; //��ʼ���ռ�
	~Mystack() {
		Node* q = new Node;
		while (head != nullptr) {
			q = head;
			head = head->next;
			delete q;
		}//��whileѭ������ջ�ռ�
	} //����ջ�ռ�
	void push(char elem) {
		Node* q = new Node; 
		q->data = elem; 
		q->next = head;
		head = q;
		size++;
	}; //��ջ
	void pop() {
		if (size <= 0) {
			cout << "False" << endl;
		}
		else {
			Node* q = new Node;
			char data; 
			q = head;
			data = head->data;
			head = head->next;
			delete q;
			size--; // cout << data << endl ; 
		} 
	} ;//��ջ
		};

bool Symbol_matching(string str) {
	Mystack stack;
	map<char, char> dic = {
	{'}','{'},
	{']','['},
	{')','('}
	};
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '{' or str[i] == '[' or str[i] == '(') {
			stack.push(str[i]);
		}
		else if (str[i] == '}' or str[i] == ']' or str[i] == ')') {
			if (stack.head->data != dic[str[i]]) {
				return false;
			}
			stack.pop();
		}
	}
	if (stack.size == 0) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	string str;
	bool R;
	getline(cin, str);
	R = Symbol_matching(str);
	cout << R << endl;
	return 0;
}