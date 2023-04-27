#include <iostream>
#include <clocale>
#include <cwctype>
#include "network.h"
#include "profile.h"

  // Constructor, makes an empty network (numUsers = 0)
  Network::Network() {
    numUsers = 0; 
    for (int i = 0; i < MAX_USERS; i++) {
      for (int j= 0; j < MAX_USERS; j++) {
        following[i][j]=false; //sets all elements of the matrix following to false, so in empty network no one is following anyone.
      }
	  }
  }

  int Network::findID(std::string usrn) { // Looks up the ID of a specific profile by its username. 
    for (int i = 0; i < MAX_USERS; i++) {
      if (profiles[i].getUsername() == usrn) {
        return i; 
      }
    }
  return -1; 
  }

  // Attempts to sign up a new user with specified username and displayname
  // return true if the operation was successful, otherwise return false
  bool Network::addUser(std::string usrn, std::string dspn) {
    
    if (numUsers == MAX_USERS){ //Conditions: the array profiles is not full.
      return false;
    }
    
    for (int i = 0; i < usrn.size(); i++) { //Condition: Checks if the new username usrn is a non-empty alphanumeric string.
      while (!isalnum(usrn[i]))
      return false;
    }
  
    if (findID(usrn) != -1) { //Condition: There are no other users in the network with the same username.
        return false;
    }

    profiles[numUsers] = Profile(usrn, dspn); //adds username to profiles array 
    numUsers++; //increase number of users
    return true;
}

  // Make 'usrn1' follow 'usrn2' (if both usernames are in the network).
  // return true if success (if both usernames exist), otherwise return false
  bool Network::follow(std::string usrn1, std::string usrn2) {
    if (findID(usrn1) != -1 && findID(usrn2) != -1) { //if both usernames are found in profiles array 
      following[findID(usrn1)][findID(usrn2)] = true; // usrn1 is now following usrn2
      return true; 
    }
  return false; 
  }


  // Print Dot file (graphical representation of the network)
  void Network::printDot() {
    std::cout << "digraph {" << '\n'; 
    for (int i = 0; i < numUsers; i++) {
       std::cout << " " << "\"@" << profiles[i].getUsername() << "\"" << std::endl; //iterates through profile array and gets username
    }
    for (int i = 0; i < numUsers; i++) {
      for (int j = 0; j < numUsers; j++) {
        if (following[i][j] == true) { //if both users follow each other
            std::cout << " " << "\"@" << profiles[i].getUsername() << "\" -> \"@" << profiles[j].getUsername() << "\"" << std::endl;
        }
      }
    }
    std::cout << "}" << std::endl;
  }
