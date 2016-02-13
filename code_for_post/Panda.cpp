/*
 * =====================================================================================
 *
 *       Filename:  Panda.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年02月13日 12时14分14秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
using namespace std;

class ZooAnimal
{
	public:
		ZooAnimal() {cout << "ZooAnimal construct called!" << endl;}
};

class Bear : public ZooAnimal
{
	public:
		Bear() {cout << "Bear construct called!" << endl;}
};

class Endangered
{
	public:
		Endangered() {cout << "Endangered construct called!" << endl;}
};

class Panda : public Bear, public Endangered
{
	public:
		Panda() : Endangered()
		{cout << "Panda construct called!" << endl;}
};

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	Panda panda;

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
