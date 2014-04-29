#include "Table.h"

Table* Table::copy = 0;

Table* Table::Copy(){
	if (copy == 0) {
		copy = new Table;
	}
	return copy;
}

