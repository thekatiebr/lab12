/*

	Katherine (Katie) Brown and Duane Vick
	CSC 2111 Lab 12
	https://github.com/kebrown46/lab12

*/
#include "BinarySearchTree.h"
#include "BinaryTreeIterator.h"
#include "ListArray.h"
using CSC2110::ListArray;
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
#include "CD.h"
using CSC2110::CD;

#include <iostream>
using namespace std;

void deleteCDs(ListArray<CD>* list)
{
   ListArrayIterator<CD>* iter = list->iterator();

   while(iter->hasNext())
   {
      CD* cd = iter->next();
      delete cd;
   }

   delete iter;
}

int main(int argc, char** argv)
{
   //the unsorted ListArray of cds
   const char* cd;
   if(argc >= 2) cd = argv[1];
   else
   {
	   cd = "cds.txt";
   }
   ListArray<CD>* cds = CD::readCDs(cd);
   int numItems = cds->size();
   cout << numItems << endl;
   cout << endl;
	
   //test the binary search tree
   //insert all of the cds
   ListArrayIterator<CD>* iter = cds->iterator();
   BinarySearchTree<CD>* bst = new BinarySearchTree<CD>(&CD::compare_items, &CD::compare_keys);
   while(iter->hasNext())
   {
      CD* cd = iter->next();
      bst->insert(cd);
   }
   delete iter;
   
   int h = bst->getHeight();
   cout << "Height: " << h << endl;
   
   bool bal = bst->isBalanced();
	if(bal) cout << "Balanced\n";
	else{
		cout << "Not Balanced\n";
	}

   BinaryTreeIterator<CD>* bst_iter = bst->iterator();
   bst_iter->setInorder();  //takes a snapshot of the data
   while(bst_iter->hasNext())
   {
      CD* cd = bst_iter->next();
      cd->displayCD();
   }
   delete bst_iter;

   //DO THIS
   //display the height of the binary search tree (not minimum height)
   //display whether the binary search tree is balanced (should not be balanced)


	h = bst->getHeight();
   cout << h << endl;
   
   bal = bst->isBalanced();
	if(bal) cout << "Balanced\n";
	else{
		cout << "Not Balanced\n";
	}


   //create a minimum height binary search tree

   BinarySearchTree<CD>* min_bst = bst->minimize();

   bst_iter = min_bst->iterator();

   //make sure that an inorder traversal gives sorted order
   bst_iter->setInorder();  //takes a snapshot of the data
  
   while(bst_iter->hasNext())
   {
      CD* cd = bst_iter->next();
      cd->displayCD();
	 
   }
   delete bst_iter;

   //DO THIS
   //display the height of the binary search tree (should be minimum height)
   //display whether the binary search tree is balanced (should be balanced)

h = min_bst->getHeight();
   cout << h << endl;
   
   bal = min_bst->isBalanced();
  
	if(bal) cout << "Balanced\n";
	else{
		cout << "Not Balanced\n";
	}

   //create a complete binary search tree
 
   BinarySearchTree<CD>* complete_bst = bst->minimizeComplete();
 
   delete bst;

   //make sure that an inorder traversal gives sorted order
   bst_iter = complete_bst->iterator();
   bst_iter->setInorder();  //takes a snapshot of the data
   while(bst_iter->hasNext())
   {
      CD* cd = bst_iter->next();
      cd->displayCD();

   }
   delete bst_iter;

   //DO THIS
   //display the height of the complete binary search tree (should be minimum height)
   //display whether the binary search tree is balanced (should be balanced)

	h = complete_bst->getHeight();
   cout << h << endl;
   
   bal = complete_bst->isBalanced();
	if(bal) cout << "Balanced\n";
	else{
		cout << "Not Balanced\n";
	}

   delete complete_bst;

   deleteCDs(cds);
   delete cds;
   return 0;
}
