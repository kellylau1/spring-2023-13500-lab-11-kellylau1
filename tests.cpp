#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"

TEST_CASE("Task A: Profile") {
    Profile p1("marco", "Marco");    
    CHECK(p1.getUsername() == "marco");
    CHECK(p1.getFullName() == "Marco (@marco)");

    p1.setDisplayName("Marco Rossi");
    CHECK(p1.getUsername() == "marco");
    CHECK(p1.getFullName() == "Marco Rossi (@marco)");
    
    Profile p2("tarma1", "Tarma Roving");  
    CHECK(p2.getUsername() == "tarma1");
    CHECK(p2.getFullName() == "Tarma Roving (@tarma1)");  
}

TEST_CASE("Task B: Adding Users") {
    Network nw;
    CHECK(nw.addUser("mario", "Mario") == 1);
    CHECK(nw.addUser("luigi", "Luigi") == 1);
    CHECK(nw.addUser("mario", "Mario2") == 0);
    CHECK(nw.addUser("mario 2", "Mario2") == 0);
}

TEST_CASE("Task C: Following Others") {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");

    CHECK(nw.follow("mario", "luigi") == 1);
    CHECK(nw.follow("mario", "yoshi") == 1);
    CHECK(nw.follow("yoshi", "luigi") == 1);
    CHECK(nw.follow("wario", "Wario") == 0);
}
    


    