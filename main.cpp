#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;

vector<int> num_list {};

void print_options()
{
    cout << "\nP - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;
}


void display_largest_num()
{
    if (num_list.empty())
        cout << "\n Unable to determine the largest number - list is empty" << endl;
    else
    {
        int largest_num = num_list.at(0);
        for (auto num: num_list)
        {
            if (num > largest_num)
                largest_num = num;
        }
        cout << '\n' << largest_num << endl;
    }
}


void display_smallest_num()
{
    if (num_list.empty())
        cout << "\n Unable to determine the smallest number - list is empty" << endl;
    else
    {
        int smallest_num = num_list.at(0);
        for (auto num: num_list)
        {
            if (num < smallest_num)
                smallest_num = num;
        }
        cout << '\n' << smallest_num << endl;
    }
}



void display_mean()
{
    if (num_list.empty())
        cout << "\n Unable to calculate the mean - no data." << endl;
    else
    {
        int sum {0};
        for (auto num: num_list)
            sum += num;
        
        const double average = static_cast<double>(sum) / num_list.size();
        cout << "\n" << average << endl;
    }
    

}


void print_numbers()
{
    if (num_list.empty())
        cout << "\n[] - the list is empty" << endl;
    else
    {
        cout << "[ ";
        for (auto num: num_list)
            cout << num << " ";
        cout << "]" << endl;
    }
}


void add_new_number()
{
    cout << "\nEnter number to add: ";
    int new_number {0};
    cin >> new_number;
    num_list.push_back(new_number);
    cout << new_number << " added." << endl;
}


void process_command(char command)
{
    switch (command)
    {
        case 'p':
            print_numbers();
            break;
        case 'a':
            add_new_number();
            break;
        case 'm':
            display_mean();
            break;
        case 's':
            display_smallest_num();
            break;
        case 'l':
            display_largest_num();
            break;
        default:
            cout << "Unknown Selection, please try again.";
            break;
    }
}


int main()
{
    cout.precision(4);
    char command {};
    while (true)
    {
        print_options();
        cin >> command;
        command = tolower(command);

        if (command == 'q')
        {
            cout << "\n Goodbye" << endl;
            break;
        }
        else process_command(command);
    }

}





 