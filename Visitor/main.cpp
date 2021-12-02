//The vistor pattern is to define a new operation on a group of similar kind of objects or hierarchy.
//Basically extend a class/object with another one.


//IMPORTANT ADD THIS FOR LATEST VERSION OF C++
//Project → Properties → C/C++ → Command Line "std:c++latest"
#include <string>
#include <list>
#include <iostream>
#include <variant>

using namespace std;

struct Document {
    virtual void add_to_list(const string& line) = 0;
};
struct Markdown : Document {
    void add_to_list(const string& line) { m_content.push_back(line); }
    string          m_start = "* ";
    list<string>    m_content;
};
struct HTML : Document {
    void add_to_list(const string& line) { m_content.push_back(line); }
    string          m_start = "<li>";
    string          m_end = "</li>";
    list<string>    m_content;
};
/* ------------------------------------ Visitor ------------------------------------- */
struct DocumentPrinter {
    void operator()(Markdown& md) {
        for (auto&& item : md.m_content)
            cout << md.m_start << item << endl;
    }
    void operator()(HTML& hd) {
        cout << "<ul>" << endl;
        for (auto&& item : hd.m_content)
            cout << "\t" << hd.m_start << item << hd.m_end << endl;
        cout << "</ul>" << endl;
    }
};
/* ---------------------------------------------------------------------------------- */
//variant represents a type-safe 
//union(special class type that can hold only one of its non-static data members at a time.). 
using document = std::variant<Markdown, HTML>; 
int main() {
    HTML hd;
    hd.add_to_list("This is line");
    document d = hd;
    DocumentPrinter dp;
    std::visit(dp, d); //visit function calls the provided functor(fancy way of calling a function object where each overload has different code)
    return EXIT_SUCCESS;
}