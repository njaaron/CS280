#include "lex.h"
using namespace std;
LexItem id_or_kw(const string& lexeme, int linenum){
    if(lexeme == "WRITELN"){
        return LexItem(WRITELN, lexeme, linenum);
    }
    else if(lexeme == "IF"){
        return LexItem(IF, lexeme, linenum);
    }
    else if(lexeme == "ELSE"){
        return LexItem(ELSE, lexeme, linenum);
    }
    char firstChar = lexeme[0];
    if(firstChar == '$'){
        return LexItem(NIDENT, lexeme, linenum);
    }
    else if(firstChar == '@'){
        return LexItem(SIDENT, lexeme, linenum);
    }
    else{
        return LexItem(IDENT, lexeme, linenum);
    }
}
ostream& operator<<(ostream& out, const LexItem& tok) {
    Token t = tok.GetToken();
    if(t == IDENT){
        LexItem lex = id_or_kw(tok.GetLexeme(), tok.GetLinenum());
        t = lex.GetToken();
    }
    switch(t) {
        case WRITELN: 
            out << "WRITELN: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl; 
            break;
        case IF: 
            out << "IF: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl; 
            break;
        case ELSE: 
            out << "ELSE: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl; 
            break;
        case IDENT: 
            out << "IDENTIFIER: " << tok.GetLexeme() << " at Line " << tok.GetLinenum() << endl; 
            break;
        case NIDENT: 
            out << "NIDENT: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl; 
            break;
        case SIDENT: 
            out << "SIDENT: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl; 
            break;
        case ICONST: 
            out << "ICONST: (" << tok.GetLexeme() << ") at Line " << tok.GetLinenum() << endl; 
            break;
        case RCONST:
            out << "RCONST: (" << tok.GetLexeme() << ") at Line " << tok.GetLinenum() << endl;
            break;
        case SCONST:
            out << "SCONST: \'" << tok.GetLexeme() << "\' at Line " << tok.GetLinenum() << endl;
            break;
        case PLUS:
            out << "PLUS: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        case MINUS:
            out << "MINUS: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        case MULT:
            out << "MULT: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        case DIV:
            out << "DIV: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        case EXPONENT:
            out << "EXPONENT: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        case ASSOP:
            out << "ASSOP: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        case NEQ:
            out << "NEQ: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        case NGTHAN:
            out << "NGTHAN: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        case NLTHAN:
            out << "NLTHAN: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        case CAT:
            out << "CAT: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        case SREPEAT:
            out << "SREPEAT: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        case SEQ:
            out << "SEQ: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        case SLTHAN:
            out << "SLTHAN: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        case SGTHAN:
            out << "SGTHAN: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        case COMMA:
            out << "COMMA: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        case SEMICOL:
            out << "SEMICOL: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        case LPAREN:
            out << "LPAREN: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        case RPAREN:
            out << "RPAREN: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        case LBRACES:
            out << "LBRACES: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        case RBRACES:
            out << "RBRACES: \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        case ERR:
            out << "Error: : \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum() << endl;
            break;
        default: 
            out << tok.GetToken() << ": \"" << tok.GetLexeme() << "\" at Line " << tok.GetLinenum(); 
            break;
    }
    return out;
}
