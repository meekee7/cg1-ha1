/* ----------------------------------------------------------------
   name:           scenegraph.c
   purpose:        implementation of the scenegraph functions
   version:	   SKELETON CODE
   TODO:           traverse reset
   author:         katrin lang
   computer graphics
   tu berlin
   ------------------------------------------------------------- */

#include <iostream>
#ifdef __APPLE__ 
#include <GLUT/glut.h>
#elif _WIN32
#include "win32/glut.h"
#else
#include <GL/glut.h>
#endif

#include "scenegraph.h"

// without this line, 
// printline debugging won't work
using namespace std;

// this is our scenegraph
SceneGraph *sceneGraph;

SceneGraph::SceneGraph(Node *root) : root(root), selected(root) {
	selected->select();
}

SceneGraph::~SceneGraph(){
	clear(root);
}

// traverse and draw the scenegraph
// nothing to do here
// (see helper function)
void SceneGraph::traverse(){
	traverse(root);
}
void SceneGraph::selectiontraverse(){
	selectiontraverse(this->root);
}
// reset all rotations in the scenegraph
// nothing to do here
// (see helper function)
void SceneGraph::reset(){
	reset(root);
}

// navigation in tree
// (needed for node selection)
void SceneGraph::up(){
	if (selected->getParent() == NULL) return;
	selected->deselect();
	selected = selected->getParent();
	selected->select();
}
void SceneGraph::down(){
	if (selected->getChild() == NULL) return;
	selected->deselect();
	selected = selected->getChild();
	selected->select();
}
void SceneGraph::left(){
	if (selected->getPrevious() == NULL) return;
	selected->deselect();
	selected = selected->getPrevious();
	selected->select();
}
void SceneGraph::right(){
	if (selected->getNext() == NULL) return;
	selected->deselect();
	selected = selected->getNext();
	selected->select();
}

// increment / decrement rotation of selected node
void SceneGraph::rotate(float x, float y, float z){
	selected->rotate(x, y, z);
}

// traverse and draw the scenegraph from a given node
// XXX: NEEDS TO BE IMPLEMENTED
void SceneGraph::traverse(Node *node){

	if (node == NULL) return;

	// store current modelview (transformation) matrix
	// XXX

	// INSERT YOUR CODE HERE
	glPushMatrix();
	// END XXX

	// apply local transformation
	node->transform();
	// draw the current node
	node->draw();

	// continue concatenating transformations
	// if this node has children
	// XXX  

	SceneGraph::traverse(node->getChild()); //Null test at top already
	// INSERT YOUR CODE HERE

	// END XXX

	// after this scenegraph branch
	// restore previous transformation
	// XXX
	// INSERT YOUR CODE HERE
	glPopMatrix();
	// END XXX

	// and traverse possible siblings
	// XXX
	SceneGraph::traverse(node->getNext());
	// INSERT YOUR CODE HERE

	// END XXX
}

//Modified version of the traversion from above, different transformation and drawing is needed
void SceneGraph::selectiontraverse(Node *node){
	if (node == NULL) return;
	glPushMatrix();
	node->selectiontransform();
	node->selectdraw();
	SceneGraph::selectiontraverse(node->getChild());
	glPopMatrix();
	SceneGraph::selectiontraverse(node->getNext());
}

void SceneGraph::selectbyid(GLubyte id){
	this->selectbyid(this->root, id);
}

//Traverse the graph and look for the node with the id to select it
void SceneGraph::selectbyid(Node *node, GLubyte id){
	if (node == NULL)
		return;
	if (node->selectionid == id){
		this->selected->deselect(); //Like this, there is no deselection with a click into the void
		node->select(); //Because we only deselect when the node was found
		this->selected = node;
		return;
	}
	SceneGraph::selectbyid(node->child, id); //Recursively try to find the id in siblings and children
	SceneGraph::selectbyid(node->next, id); //Null test is done above
}

void SceneGraph::clear(Node *node){

	if (node == NULL) return;

	clear(node->getChild());
	clear(node->getNext());

	delete node;

}

// reset all rotations below a given node
// XXX: NEEDS TO BE IMPLEMENTED
void SceneGraph::reset(Node* node){

	// reset rotations
	// XXX
	if (node == NULL)
		return;

	node->rotx = 0.0f;
	node->roty = 0.0f;
	node->rotz = 0.0f;
	SceneGraph::reset(node->getChild()); //Recursively set all rotation vectors to zero
	SceneGraph::reset(node->getNext()); //Null test is done above
	// INSERT YOUR CODE HERE

	// END XXX
}
