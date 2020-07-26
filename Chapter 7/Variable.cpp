#include "C7_Header.h"

Variable::Variable(string n, double v) :name(n), value(v), constant(false) { }
Variable::Variable(string n, double v, bool c) : name(n), value(v), constant(c) { }