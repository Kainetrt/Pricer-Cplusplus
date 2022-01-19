#pragma once
#include <iostream>
#include <vector>
#include <math.h>
#include "Option.h"
#include "BinaryTree.h"
#include <stdexcept>
#include <string>

class CRRPricer
{
public:
	CRRPricer(Option* option, int depth, double asset_price, double up, double down, double interest_rate);
	CRRPricer(Option*, int, double, double, double);
	CRRPricer(Option*, double, double, double);
	CRRPricer();
	void compute();
	double get(int, int);
	double operator()(bool = false);
	int factorial(int);
	double h(int, int);
	bool getExercise(int, int);
private:
	Option* option;
	int depth; //N depth of the tree
	double asset_price; // S0, beginning price
	double up; // U, up value
	double down; //D, down value
	double interest_rate; //Interest rate R
	bool closed_form;
	BinaryTree<double> tree;
	BinaryTree<bool> temp;
};

