//The mediator pattern is just an inbetween object/class 
//between other objects to add onto a list or some bullshit.

#include <iostream>
#include <vector>

using namespace std;

struct ChatRoom {
    virtual void broadcast(string from, string msg) = 0;
    virtual void message(string from, string to, string msg) = 0;
};

struct Person {
    string m_name;
    ChatRoom* m_room{ nullptr };
    vector<string> m_chat_log;
    Person(string n) : m_name(n) {}
    void say(string msg) const { m_room->broadcast(m_name, msg); }
    void pm(string to, string msg) const { m_room->message(m_name, to, msg); }
    void receive(string from, string msg) {
        string s{ from + ": \"" + msg + "\"" };
        cout << "[" << m_name << "'s chat session]" << s << "\n";
        m_chat_log.emplace_back(s);
    }
};

struct GoogleChat : ChatRoom
{
    vector<Person*> m_people;
    void broadcast(string from, string msg) {
        for (auto p : m_people)
            if (p->m_name != from)
                p->receive(from, msg);
    }
    void join(Person* p) {
        string join_msg = p->m_name + " joins the chat";
        broadcast("room", join_msg);
        p->m_room = this;
        m_people.push_back(p);
    }
    void message(string from, string to, string msg) {
        auto target = find_if(begin(m_people), end(m_people),
            [&](const Person* p) {
                return p->m_name == to;
            });
        if (target != end(m_people)) (*target)->receive(from, msg);
    }
};

int main() {
    GoogleChat room;
    Person john{ "John" };
    Person jane{ "Jane" };
    room.join(&john);
    room.join(&jane);
    john.say("hi room");
    jane.say("oh, hey john");
    Person simon{ "Simon" };
    room.join(&simon);
    simon.say("hi everyone!");
    jane.pm("Simon", "glad you found us, simon!");
    return EXIT_SUCCESS;
}