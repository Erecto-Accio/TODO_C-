#include <iostream>
#include <vector>
using namespace std;

class TODO
{
	string todo_name;

public:
	TODO(string todo_name)
	{
		this->todo_name = todo_name;
	}

	string getTodo()
	{
		return todo_name;
	}
};

class TodoManager
{
private:
	vector<TODO> todo;

public:
	void createTodo()
	{
		string createdTodo;

		cout << "Enter your todo name: ";
		cin.ignore();
		getline(cin, createdTodo);

		TODO newTodo(createdTodo);

		todo.push_back(newTodo);
		cout << "\t\t\t\t\tt\t\t **** Todo created successfully ****" << endl;
		system("pause");
		system("cls");
	}

	void displayTodo()
	{
		if (todo.empty())
		{
			cout << "No todo's available. Add one" << endl;
			return;
		}
		for (int i = 0; i < todo.size(); i++)
		{
			cout << i + 1 << "." << todo[i].getTodo() << endl;
		}
	}

	void updateTodo()
	{

		if (todo.empty())
		{
			cout << "No todo's available. Add one" << endl;
			return;
		}

		int index;
		cout << "Enter the index of the todo you want to update: " << endl;
		cin >> index;

		if (index < 1 || index > todo.size())
		{
			cout << "Invalid Index." << endl;
			return;
		}
		string updatedTodo;
		cout << "Enter the updated todo name: ";
		cin.ignore();
		getline(cin, updatedTodo);

		todo[index - 1] = TODO(updatedTodo);

		cout << "\t\t\t\t\tt\t\t **** Todo updated successfully ****" << endl;
		system("pause");
		system("cls");
	}

	void deleteTodo()
	{
		if (todo.empty())
		{
			cout << "No todo found to be deleted" << endl;
			return;
		}

		int index;
		cout << "Enter the index of the todo: " << endl;
		cin.ignore();
		cin >> index;

		if (index < 1 || index > todo.size())
		{
			cout << "Invalid Index" << endl;
			return;
		}

		todo.erase(todo.begin() + index - 1);
		cout << "\t\t\t\t\tt\t\t **** Todo deleted successfully ****" << endl;
		system("pause");
		system("cls");
	}
};

int main()
{

	TodoManager todoManage;

	int choice;
	char decision;

	do
	{

		cout << "\n\n\t\t\t\t || Todo App || - made by Tousif Tasrik {{ IUS CSE BATCH - 14}}" << endl;
		cout << "\t\t\t\t 1. Create Todo" << endl;
		cout << "\t\t\t\t 2. Display Todo" << endl;
		cout << "\t\t\t\t 3. Update a Todo" << endl;
		cout << "\t\t\t\t 4. Delete a Todo" << endl;
		cout << "\t\t\t\t 5. Exit" << endl;
		cout << "Enter your choice: ";

		cin >> choice;
		switch (choice)
		{
		case 1:
			todoManage.createTodo();
			break;
		case 2:
			todoManage.displayTodo();
			break;
		case 3:
			todoManage.updateTodo();
			break;
		case 4:
			todoManage.deleteTodo();
			break;
		case 5:
			cout << "\t\t\t\t\t\t\aThank your for using todo app ||| GIVE IT A STAR IF YOU LIKE IT ||| <3" << endl;
			exit(0);
			break;
		default:
			cout << "Invalid Input" << endl;
			break;
		}

		cout << "\n\n Continue [ Y / N ]";
		cin >> decision;

		system("cls");
	} while (decision == 'y' || decision == 'Y');
}