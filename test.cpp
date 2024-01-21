#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

class Date {
public:
	int year;
	int month;
	int day;
	Date(int year, int month, int day) {
		this->day = day;
		this->month = month;
		this->year = year;
	}

	Date operator&=(Date o){
		this->year = o.year;
		this->day = o.day;
		this->month = o.month;
	}
	Date(){}
};
class Person {
public:
	string name;
	string sex;
	Date birthday;
	bool lived=true;
	Person(string name, string sex, Date birthday) {
		this->birthday = birthday;
		this->name = name;
		this->sex = sex;
	}
	Person operator&=(Person o){
		this->birthday = o.birthday;
		this->name = o.name;
		this->lived = o.lived;
		this->sex = o.sex;
	}

	Person(){}
};
class Member {
public:
	Person person;
	Person* cp=NULL;
	Member* firstChild=NULL;
	Member* brother=NULL;
	Member(){}
};

Member* createMember()
{
	cout<<"请输入新加入成员的姓名，性别，出生年月日："<<endl;
	string name, sex; int year, month, day;
	cin>>name>>sex>>year>>month>>day;
	Date birthday(year,month,day);
	Person newPerson(name, sex, birthday);
	Member *Node = new Member;
	Node->person = newPerson;
	return Node;
}
void CreateTree(Member **Rroot) {
	Member *root = new Member();
    queue<Member*> q;
	cout<<"创建ROOT"<<endl;
    root = createMember();
	root->person.lived = false;
    q.push(root);

    while (!q.empty()) {
        Member* currentNode = q.front();
        q.pop();

        int flag = 0;
        cout << "当前节点：" << currentNode->person.name << endl;
        cout << "是否添加子节点(0/1):" << endl;
        cin >> flag;
        if (flag == 1) {
            Member* childNode = createMember();
            currentNode->firstChild = childNode;
            q.push(childNode);
        }

		while(flag == 1){
			cout << "是否添加兄弟节点(0/1):" << endl;
        	cin >> flag;
        	if (flag == 1) {
				Member* brotherNode = createMember();
				currentNode->brother = brotherNode;
				currentNode = currentNode->brother;
				q.push(brotherNode);
        	}
		}
    }
	*Rroot = root;
}


int main() {
	Member **root;
	CreateTree(root);
	cout<<(*root)->person.sex;


	return 0;
}