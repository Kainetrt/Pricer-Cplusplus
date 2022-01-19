#include <iostream>
#include <vector>
#include <math.h>
#include <random>
#pragma once

template <class T>
class BinaryTree
{
public:
	int _depth;
	BinaryTree();
	void setDepth(int);
	void setNode(int, int, T);
	T getNode(int, int);
	void display();
	void DisplayAesthetic();

private:
	std::vector<std::vector<T>> _tree;
};

template <class T>
BinaryTree<T>::BinaryTree()
{
}

template <class T>
void BinaryTree<T>::setDepth(int taille)
{
	this->_depth = taille + 1;

	//initialisation of the length of the matrix

	std::vector<std::vector<T> > matrice = this->_tree;
	matrice.resize(taille + 1);

	for (int i = 0; i < taille + 1; i++)
	{
		matrice[i].resize(taille + 1);
	}
	this->_tree = matrice;
}

template <class T>
void BinaryTree<T>::setNode(int row, int column, T value)
{
	this->_tree[column][row] = value;
}

template <class T>
T BinaryTree<T>::getNode(int row, int column)
{
	return this->_tree[column][row];
}

template <class T>
void BinaryTree<T>::display()
{
	for (int n = 0; n <= this->_depth - 1; n++)
	{
		for (int i = 0; i <= n; i++)
		{
			std::cout << this->_tree[i][n] << " ";
		}
		std::cout << "" << std::endl;
	}
	std::cout << "" << std::endl;
}

template <class T>
void BinaryTree<T>::DisplayAesthetic()
{
	std::string space = " /\ \\";
	std::string space2;

	for (int i = 0; i <= 2 * this->_depth; i++)
	{
		space2 += " ";
	}

	std::string space3 = space2;

	space2 = space2 + "  ";

	for (int n = 0; n < this->_depth; n++)
	{
		std::cout << space2;
		for (int i = 0; i <= n; i++)
		{
			std::cout << this->_tree[n][i] << "   ";
		}

		std::cout << "" << std::endl;

		std::cout << space3 + space;
		space3.pop_back();
		space3.pop_back();
		space = space + " /\ \\";

		std::cout << "" << std::endl;

		space2.pop_back();
		space2.pop_back();

	}

	for (int i = 0; i <= this->_depth - 1; i++)
	{
		std::cout << "   ";
		std::cout << this->_tree[this->_depth - 1][i];
	}
}
