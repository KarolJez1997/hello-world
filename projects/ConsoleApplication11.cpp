// ConsoleApplication11.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <cctype>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

string linia;
string str[10], temp1;
int tablica[10] = { 1,3,2,6,7,4,9,8,5,10 };
fstream plik;
int licznik = 0;


void literki()
{
	plik.open("literki.txt", ios::in);

	if (plik.good() == false) cout << "Nie mozna otworzyc pliku!";


	while (!plik.eof())
	{
		getline(plik, linia);
		str[licznik] = linia;
		licznik++;
	}

	plik.close(); 
}

struct node {
	int data;

	struct node *leftChild;
	struct node *rightChild;
};

struct node *root = NULL;

void insert(int data) {
	struct node *tempNode = (struct node*) malloc(sizeof(struct node));
	struct node *current;
	struct node *parent;

	tempNode->data = data;
	tempNode->leftChild = NULL;
	tempNode->rightChild = NULL;

	
	if (root == NULL) {
		root = tempNode;
	}
	else {
		current = root;
		parent = NULL;

		while (1) {
			parent = current;

			
			if (data < parent->data) {
				current = current->leftChild;

				
				if (current == NULL) {
					parent->leftChild = tempNode;
					return;
				}
			}  
			else {
				current = current->rightChild;

				
				if (current == NULL) {
					parent->rightChild = tempNode;
					return;
				}
			}
		}
	}
}

struct node* search(int data) {
	struct node *current = root;
	printf("Sprawdzanie elementow: ");

	while (current->data != data) {
		if (current != NULL)
			cout << str[current->data] << " ";

		
		if (current->data > data) {
			current = current->leftChild;
		}
		
		else {
			current = current->rightChild;
		}

		
		if (current == NULL) {
			return NULL;
		}
	}

	return current;
}

void pre_order_traversal(struct node* root) {
	if (root != NULL) {
		cout << str[root->data-1] <<"."<< root->data << " ";
		pre_order_traversal(root->leftChild);
		pre_order_traversal(root->rightChild);
	}
}

void inorder_traversal(struct node* root) {
	if (root != NULL) {
		inorder_traversal(root->leftChild);
		cout << str[root->data-1] << "." << root->data << " ";
		inorder_traversal(root->rightChild);
	}
}

void post_order_traversal(struct node* root) {
	if (root != NULL) {
		post_order_traversal(root->leftChild);
		post_order_traversal(root->rightChild);
		cout << str[root->data-1] << "." << root->data << " ";
	}
}

int main() {
	literki();

	for (int i = 0; i < licznik-1; ++i)
		for (int j = i + 1; j < licznik; ++j)
		{
			if (str[i] > str[j])
			{
				temp1 = str[i];
				str[i] = str[j];
				str[j] = temp1;
			}
		}




	int i;
	

	for (i = 0; i < licznik; i++)
	{
		insert(tablica[i]);
	}

	i = 6;
	struct node * temp = search(i);

	if (temp != NULL) {
		printf("[%d] Element znaleziony.", temp->data);
		printf("\n");
	}
	else {
		printf("[ x ] Element nie znaleziony (%d).\n", i);
	}

	i = 8;
	temp = search(i);

	if (temp != NULL) {
		printf("[%d] Element znaleziony.", temp->data);
		printf("\n");
	}
	else {
		printf("[ x ] Element znaleziony (%d).\n", i);
	}
	
	printf("\n(Centrum,Lewo,Prawo): ");
	pre_order_traversal(root);

	printf("\n(Lewo,Centrum,Prawo): ");
	inorder_traversal(root);

	printf("\n(Lewo,Prawo,Centrum): ");
	post_order_traversal(root);
	_getch();
	return 0;
}