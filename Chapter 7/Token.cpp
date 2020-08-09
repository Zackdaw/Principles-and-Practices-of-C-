#include "Q1_Header.h"

Token::Token(char ch) :kind(ch), value(0) { }
Token::Token(char ch, double val) : kind(ch), value(val) { }
Token::Token(char ch, string n) : kind(ch), value(0), name(n) {}