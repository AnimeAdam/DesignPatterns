//The command pattern only to create generic execute function held in other objects.

#include <vector>
#include <iostream>

using namespace std;

//The generic main class that holds all the information.
struct Command {
    virtual void execute() = 0;
};

//Main storage for data
struct BankAccount {
    int32_t     m_balance;
    void deposit(int32_t amount) { m_balance += amount; }
    void withdraw(int32_t amount) { m_balance -= amount; }
};

//A command that can execute and interact with the bankaccount.
struct BankAccountCommand : Command {
    enum class Action : bool { deposit, withdraw };
    BankAccount& m_ac;
    Action            m_action;
    int32_t           m_amount;
    BankAccountCommand(BankAccount& ac, Action a, int32_t amnt)
        : m_ac(ac), m_action(a), m_amount(amnt) {}
    //Overly simplfied versioin of this. Probably better to use a list.
    void execute() {
        (m_action == Action::deposit) ? m_ac.deposit(m_amount) : m_ac.withdraw(m_amount);
    }
};

int main() {
    BankAccount ba1{ 1000 };
    BankAccount ba2{ 1000 };
    vector<BankAccountCommand> commands{
        BankAccountCommand{ba1, BankAccountCommand::Action::withdraw, 200},
        BankAccountCommand{ba2, BankAccountCommand::Action::deposit, 200}
    };
    for (auto& cmd : commands)
        cmd.execute();

    cout << ba1.m_balance << endl;
    cout << ba2.m_balance << endl;
    return EXIT_SUCCESS;
}

//Replacement for the Command vector from eariler.
//template <typename T> class Queue
//{
//public:
//    Queue()
//    {
//        m_add = m_remove = 0;
//    }
//    void enque(T* c)
//    {
//        m_array[m_add] = c;
//        m_add = (m_add + 1) % SIZE;
//    }
//    T* deque()
//    {
//        int temp = m_remove;
//        m_remove = (m_remove + 1) % SIZE;
//        return m_array[temp];
//    }
//private:
//    enum
//    {
//        SIZE = 8
//    };
//    T* m_array[SIZE];
//    int m_add, m_remove;
//};