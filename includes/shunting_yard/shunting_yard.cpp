#include "shunting_yard.h"
using namespace std;

ShuntingYard::ShuntingYard(){
    _queue = Queue<Token*>();
    _stack = Stack<Token*>();
}

ShuntingYard::ShuntingYard(const Queue<Token*>& input_q){
    infix(input_q);
}

void ShuntingYard::infix(const Queue<Token*>& input_q){
    _queue = input_q;
    _stack = Stack<Token*>();
}

Queue<Token*> ShuntingYard::postfix(){ 
    return shunting_yard();
}

Queue<Token*> ShuntingYard::postfix(const Queue<Token*>& input_q){
    infix(input_q);
    return shunting_yard();
}

Queue<Token*> ShuntingYard::shunting_yard(){
    Queue<Token*> result;

    while (_queue.size() != 0){
        Token* w = _queue.pop();

        switch (w->TypeOf()){
            case TOKENSTR:
                result.push(w);
                break;

            case RELATIONAL:
                _stack.push(w);
                break;
            
            case LOGICAL:{
                while (_stack.size() != 0 && _stack.top()->TypeOf() != LPAREN && compare(_stack.top(), w))
                    result.push(_stack.pop());

                _stack.push(w);
                break;
            }

            case LPAREN:
                _stack.push(w);
                break;

            case RPAREN:
                while (_stack.top()->TypeOf() != LPAREN){
                    assert(_stack.size() != 0 && "There is a missing left parentheses!");
                    result.push(_stack.pop());
                }
                assert(_stack.top()->TypeOf() == LPAREN && "There isn't a left parentheses at the top of the stack!");
                _stack.pop();
                break;

            default:
                break;
        }
    }
    while (_stack.size() != 0){
        // assert(_stack.top()->TypeOf() != LPAREN && "There are mismatched parentheses!");
        result.push(_stack.pop());
    }
    return result;
}