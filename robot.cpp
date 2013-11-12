/* ----------------------------------------------------------------
   name:           robot.c
   purpose:        implementation of the scenegraph construction
   version:	   SKELETON CODE
   TODO:           buildRobot
   author:         katrin lang
   computer graphics
   tu berlin
   ------------------------------------------------------------- */

#include "robot.h"
#include "node.h"
// nodes of the scenegraph

// XXX: CURRENTLY ONLY TORSO. INSERT OTHER BODY PARTS HERE.
//      SEE EXAMPLE BINARY cg1_ex1.exe (win32) and cg1_ex1 (linux).
//      EXPERIMENTATION IS ENCOURAGED. THE FINAL MODEL/SCENEGRAPH
//      NEED NOT BE IDENTICAL TO THE PROPOSED SOLUTION.

// XXX: EXTEND THE SCENEGRAPH i.e.
// Node *part1, *part2, *part3, etc...

// build the robot scenegraph
Node *buildRobot(){

	unsigned char selectionid = 0;
	// torso attributes and initial position.
	// for parameters of constructor and their meanings,
	// see file node.h
	Node *torso = new Node(0.0f, 0.0f, 0.0f,
		200.0f, 300.0f, 100.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f);
	torso->selectionid = ++selectionid; //The selectionid is not in the constructor for no reason at all


	// XXX: implement more body/robot/whatever parts here

	Node *rightupperarm = new Node(160.0f, 50.0f, 0.0f,
		50.0f, 120.0f, 50.0f,
		0.0f, 80.0f, 0.0f,
		0.0f, 0.0f, 0.0f);
	rightupperarm->setParent(torso);
	rightupperarm->selectionid = ++selectionid;

	Node *rightlowerarm = new Node(0.0f, -120.0f, 0.0f,
		50.0f, 80.0f, 50.0f,
		0.0f, 50.0f, 0.0f,
		0.0f, 0.0f, 0.0f);
	rightlowerarm->setParent(rightupperarm);
	rightlowerarm->selectionid = ++selectionid;

	Node *righthand = new Node(0.0f, -100.0f, 0.0f,
		70.0f, 50.0f, 20.0f,
		0.0f, 50.0f, 0.0f,
		0.0f, 0.0f, 0.0f);
	righthand->setParent(rightlowerarm);
	righthand->selectionid = ++selectionid;

	Node *leftupperarm = new Node(-160.0f, 50.0f, 0.0f,
		50.0f, 120.0f, 50.0f,
		0.0f, 80.0f, 0.0f,
		0.0f, 0.0f, 0.0f);
	leftupperarm->setParent(torso);
	leftupperarm->selectionid = ++selectionid;

	Node *leftlowerarm = new Node(0.0f, -120.0f, 0.0f,
		50.0f, 80.0f, 50.0f,
		0.0f, 50.0f, 0.0f,
		0.0f, 0.0f, 0.0f);
	leftlowerarm->setParent(leftupperarm);
	leftlowerarm->selectionid = ++selectionid;

	Node *lefthand = new Node(0.0f, -100.0f, 0.0f,
		70.0f, 50.0f, 20.0f,
		0.0f, 50.0f, 0.0f,
		0.0f, 0.0f, 0.0f);
	lefthand->setParent(leftlowerarm);
	lefthand->selectionid = ++selectionid;

	Node *rightupperleg = new Node(50.0f, -250.0f, 0.0f,
		60.0f, 150.0f, 60.0f,
		0.0f, 80.0f, 0.0f,
		0.0f, 0.0f, 0.0f);
	rightupperleg->setParent(torso);
	rightupperleg->selectionid = ++selectionid;

	Node *rightlowerleg = new Node(0.0f, -150.0f, 0.0f,
		60.0f, 120.0f, 60.0f,
		0.0f, 70.0f, 0.0f,
		0.0f, 0.0f, 0.0f);
	rightlowerleg->setParent(rightupperleg);
	rightlowerleg->selectionid = ++selectionid;

	Node *rightfoot = new Node(0.0f, -100.0f, 25.0f,
		50.0f, 20.0f, 100.0f,
		0.0f, 0.0f, -25.0f,
		0.0f, 0.0f, 0.0f);
	rightfoot->setParent(rightlowerleg);
	rightfoot->selectionid = ++selectionid;

	Node *leftupperleg = new Node(-50.0f, -250.0f, 0.0f,
		60.0f, 150.0f, 60.0f,
		0.0f, 80.0f, 0.0f,
		0.0f, 0.0f, 0.0f);
	leftupperleg->setParent(torso);
	leftupperleg->selectionid = ++selectionid;

	Node *leftlowerleg = new Node(0.0f, -150.0f, 0.0f,
		60.0f, 120.0f, 60.0f,
		0.0f, 70.0f, 0.0f,
		0.0f, 0.0f, 0.0f);
	leftlowerleg->setParent(leftupperleg);
	leftlowerleg->selectionid = ++selectionid;

	Node *leftfoot = new Node(0.0f, -100.0f, 25.0f,
		50.0f, 20.0f, 100.0f,
		0.0f, 0.0f, -25.0f,
		0.0f, 0.0f, 0.0f);
	leftfoot->setParent(leftlowerleg);
	leftfoot->selectionid = ++selectionid;

	Node *head = new Node(0.0f, 250.0f, 0.0f,
		150.0f, 150.0f, 150.0f,
		0.0f, -100.0f, 0.0f,
		0.0f, 0.0f, 0.0f);
	head->setParent(torso);
	head->selectionid = ++selectionid;


	// INSERT YOUR CODE HERE

	// END XXX

	// finally, attach the robot/model parts
	// example: leftArm->setParent(torso), etc...
	// BUILD THE SCENEGRAPH

	// XXX: attach body parts here

	// INSERT YOUR CODE HERE

	// END XXX

	// return root node
	return torso;
}
