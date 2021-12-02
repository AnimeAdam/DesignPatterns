//The memento pattern is to store and restore the state of the component/object.
#include <iostream>
#include <vector>

using namespace std;

class BankAccount {
    int32_t         m_balance{ 0 };
    uint32_t        m_current{ 0 };

    struct Memento { //LOOK HERE
        int32_t m_balance;
        Memento(int32_t b) : m_balance(b) {}
    };
    vector<shared_ptr<const Memento>>   m_changes;

public:
    BankAccount(const int32_t b) : m_balance(b) {
        m_changes.emplace_back(make_shared<const Memento>(m_balance));
    }
    const shared_ptr<const Memento> deposit(int32_t amount) {
        m_balance += amount;
        m_changes.emplace_back(make_shared<const Memento>(m_balance));
        return m_changes[m_current++];
    }
    void restore(const shared_ptr<const Memento>& m) {
        if (m) {
            m_balance = m->m_balance;
            m_changes.push_back(m);
            m_current = m_changes.size() - 1;
        }
    }
    const shared_ptr<const Memento> undo() {
        if (m_current > 0) {
            m_balance = m_changes[--m_current]->m_balance;
            return m_changes[m_current];
        }
        return {};
    }
    const shared_ptr<const Memento> redo() {
        if ((m_current + 1) < m_changes.size()) {
            m_balance = m_changes[++m_current]->m_balance;
            return m_changes[m_current];
        }
        return {};
    }
    friend ostream& operator<<(ostream& os, const BankAccount& ac) {
        return os << "balance: " << ac.m_balance;
    }
};



int main() {
    BankAccount ba{ 100 };
    ba.deposit(50);
    ba.deposit(25);
    cout << ba << "\n"; // 175
    ba.undo();
    cout << "Undo 1: " << ba << "\n";
    ba.undo();
    cout << "Undo 2: " << ba << "\n";
    ba.redo();
    cout << "Redo 2: " << ba << "\n";
    return EXIT_SUCCESS;
}