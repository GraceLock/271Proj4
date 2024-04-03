all: test usecase

test: test_bst.cpp BST.h BST.cpp element.h element.cpp 
		g++ -o test test_bst.cpp BST.cpp element.cpp 

usecase: usecase.cpp BST.h BST.cpp element.h element.cpp main.cpp
		g++ -o usecase usecase.cpp BST.cpp element.cpp main.cpp


