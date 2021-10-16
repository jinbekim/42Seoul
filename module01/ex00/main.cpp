#include "Pony.hpp"

static void	ponyOnTheHeap(){
	Pony	*heap1;
	Pony	*heap2;

	heap1 = new Pony("Heap1"); // Pony *heap = new Pony("Heap");
	heap2 = new Pony("Heap2"); // Pony *heap = new Pony("Heap");
	heap1->intro();
	heap1->address();
	heap2->intro();
	heap2->address();
	delete heap1;
	delete heap2;
}
static void	ponyOnTheStack(){
	Pony stack1("Stack1"); // Pony stack = Pony("Stack");
	Pony stack2("Stack2"); // Pony stack = Pony("Stack");

	stack1.intro();
	stack1.address();
	stack2.intro();
	stack2.address();
}

int	main(void)
{
	std::cout << "--------------HEAP---------------" << std::endl;
	ponyOnTheHeap();
	std::cout << "---------------------------------" << std::endl;
	std::cout << "--------------STACK--------------" << std::endl;
	ponyOnTheStack();
	std::cout << "---------------------------------" << std::endl;
	return (0);
}
