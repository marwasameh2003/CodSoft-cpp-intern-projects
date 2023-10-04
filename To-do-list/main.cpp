#include <iostream>
#include <vector>
using namespace std;

struct task
{
    string name;
    string status ;
    task()
    {
        status = "not done yet";
    }

};
class TasksHandler
{
private:
    vector<task> mytasks;
public:
    void addTask()
    {
        task newTask;
        cout<< "Enter task's name: ";
        cin>>newTask.name;
        mytasks.push_back(newTask);
    }
    void viewTasks()
    {
        if(mytasks.size()>0)
        {
             cout<< "    Task            Status";
        cout<< "\n_____________________________________________________________\n";
        for(int i = 0 ; i<mytasks.size(); i++)
        {
            cout<< i+1 <<"- "<<mytasks[i].name<< "   |   "<< mytasks[i].status<<endl;
        }
        cout<< "\n_____________________________________________________________\n";

        }
        else
        {
            cout<<"No tasks were added yet\n";
        }

    }
    void updateTask()
    {
        cout<< "Enter task's name you want to mark as completed: ";
        string name ;
        cin>>name;

        bool found = false;
        for(int i = 0 ; i<mytasks.size(); i++)
        {
            if (name == mytasks[i].name)
            {
                found = true;
                mytasks[i].status = "Completed";
                cout<<"Task is set to completed successfully\n";
            }
        }
        if(!found)
        {
            cout<<"sorry this task is not in your to do list, you can check the list to make sure\n";
        }
    }
    void removeTask()
    {
        cout<< "Enter task's name you want to remove: ";
        string name ;
        cin>>name;

         bool found = false;
        for(int i = 0 ; i<mytasks.size(); i++)
        {
            if (name == mytasks[i].name)
            {
                found = true;
                mytasks.erase(mytasks.begin()+i);
                cout<<"Task removed successfully!\n";
            }
        }
        if(!found)
        {
            cout<<"sorry this task is not in your to do list, you can check the list to make sure\n";
        }
    }
    int menu()
    {
        cout<<"Enter the number of operation you want \n";
        cout<<"1- View my tasks\n";
        cout<<"2- Add task\n";
        cout<<"3- Set task to completed\n";
        cout<<"4- Remove task\n";
        cout<<"5- Quit the program";
        int choice;
        cin>>choice;
        return choice;
    }
    void manager()
    {
        cout<<"Welcome to the To DO List Application:)\n";
        int choice;
        do
        {
            choice = menu();
            switch(choice)
            {
            case 1:
                viewTasks();
                break;
            case 2:
                addTask();
                break;
            case 3:
                updateTask();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                continue;
            default:
                cout<<"Sorry you entered an invalid choice, check the menu again\n";
            }

        }
        while(choice!= 5);
        cout<< "Thank you for using our application, see you soon!\n";
    }
};

int main()
{
    TasksHandler user1;
    user1.manager();
    return 0;
}
