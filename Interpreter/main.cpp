//The Interpretor pattern translate one thing into another

//Easy to understand in concept, FUCKING ANNOYING TO IMPLEMENT >:[

#include <string>
#include <iostream>
#include <vector>

using namespace std;

// LEXING EXAMPLE
// Lexing is is the process of converting a sequence of characters 
// (such as in a computer program or web page) into a sequence of tokens 
// (strings with an assigned and thus identified meaning).
struct Token {
    enum Type { integer, plus, minus, lparen, rparen };
    Type        m_type;
    string      m_text;
    Token(Type typ, const string& txt) : m_type(typ), m_text(txt) {}
    friend ostream& operator<<(ostream& os, const Token& o) { return os << "`" << o.m_text << "`"; }
};
vector<Token> lex(const string& input) {
    vector<Token>   result;
    for (auto curr = begin(input); curr != end(input); ++curr) {
        switch (*curr) {
        case '+': result.emplace_back(Token::plus, "+"); break;
        case '-': result.emplace_back(Token::minus, "-"); break;
        case '(': result.emplace_back(Token::lparen, "("); break;
        case ')': result.emplace_back(Token::rparen, ")"); break;
        default: // number
            auto first_not_digit = find_if(curr, end(input), [](auto c) {
                return !isdigit(c);
                });
            string integer = string(curr, first_not_digit);
            result.emplace_back(Token::integer, integer);
            curr = --first_not_digit;
        }
    }
    return result;
}
int main() {
    auto tokens = lex("(13-4)-(12+1)");
    for (auto& t : tokens)
        cout << t << " ";    // Output: `(` `13` `-` `4` `)` `-` `(` `12` `+` `1` `)`
    return EXIT_SUCCESS;
}

// PARSING EXAMPLE
// Parsing is process of analyzing a string of symbols, 
// either in natural language, computer languages or data structures, 
// conforming to the rules of a formal grammar.
// 
//struct Element {
//    virtual int eval() const = 0;
//};
//struct Integer : Element {
//    int   m_value;
//    explicit Integer(const int v) : m_value(v) {}
//    int eval() const { return m_value; }
//};
//struct BinaryOperation : Element {
//    enum Type { addition, subtraction }   m_type;
//    shared_ptr<Element>                   m_lhs, m_rhs;
//    int eval() const {
//        if (m_type == addition) return m_lhs->eval() + m_rhs->eval();
//        return m_lhs->eval() - m_rhs->eval();
//    }
//};
//shared_ptr<Element> parse(const vector<Token>& tokens) {
//    auto result = make_unique<BinaryOperation>();
//    for (auto curr_token = begin(tokens); curr_token != end(tokens); ++curr_token) {
//        switch (curr_token->m_type) {
//            /* ----------------- Normal Expression ----------------- */
//        case Token::integer:
//            if (!result->m_lhs) result->m_lhs = make_shared<Integer>(stoi(curr_token->m_text));
//            else result->m_rhs = make_shared<Integer>(stoi(curr_token->m_text));
//            break;
//        case Token::plus: result->m_type = BinaryOperation::addition; break;
//        case Token::minus: result->m_type = BinaryOperation::subtraction; break;
//            /* ----------------------------------------------------- */
//            /* ------------------- Sub Expression ------------------ */
//        case Token::lparen:
//            auto rparen = find_if(curr_token, end(tokens), [](auto& token) {
//                return token.m_type == Token::rparen;
//                });
//            vector<Token>   subexpression(curr_token + 1, rparen);
//            if (!result->m_lhs) result->m_lhs = parse(subexpression);
//            else result->m_rhs = parse(subexpression);
//            curr_token = rparen;
//            break;
//            /* ----------------------------------------------------- */
//        }
//    }
//    return result;
//}
//int main() {
//    string expression{ "(13-4)-(12+1)" };
//    auto tokens = lex(expression);
//    auto parsed = parse(tokens);
//    cout << expression << " = " << parsed->eval() << endl; // Output: (13-4)-(12+1) = -4
//    return EXIT_SUCCESS;
//}