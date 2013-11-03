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

// nodes of the scenegraph

// XXX: CURRENTLY ONLY TORSO. INSERT OTHER BODY PARTS HERE.
//      SEE EXAMPLE BINARY cg1_ex1.exe (win32) and cg1_ex1 (linux).
//      EXPERIMENTATION IS ENCOURAGED. THE FINAL MODEL/SCENEGRAPH
//      NEED NOT BE IDENTICAL TO THE PROPOSED SOLUTION.

// XXX: EXTEND THE SCENEGRAPH i.e.
// Node *part1, *part2, *part3, etc...

// build the robot scenegraph
Node *buildRobot(){

	// torso attributes and initial position.
	// for parameters of constructor and their meanings,
	// see file node.h
	Node *torso = new Node(0.0f, 0.0f, 0.0f,
		200.0f, 300.0f, 100.0f,
		0.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f);
	
	Node *leftupperarm = new Node(-200.0f, 0.0f, 0.0f, 
		50.0f, 100.0f, 50.0f, 
		200.0f, 200.0f, 20.0f, 
		0.0f, 0.0f, 0.0f);
	leftupperarm->setParent(torso);
	// XXX: implement more body/robot/whatever parts here

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
