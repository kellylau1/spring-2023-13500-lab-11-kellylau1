#include <iostream>
#include "profile.h"


// Profile constructor for a user (initializing 
// private variables username=usrn, displayname=dspn)
Profile::Profile(std::string usrn, std::string dspn) {
    username = usrn; 
    displayname = dspn; 
}
// Default Profile constructor (username="", displayname="")
Profile::Profile() {
    username = ""; 
    displayname = "";
}
// Return username
std::string Profile::getUsername() {
    return username; 
}
// Return name in the format: "displayname (@username)"
std::string Profile::getFullName() {
    std::string result = displayname + " (@" + username + ")";
return result; 
}
// Change display name
void Profile::setDisplayName(std::string dspn) {
    displayname = dspn; 
}
