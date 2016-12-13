//
// Created by nevo on 03/12/16.
//

#include <gtest/gtest.h>
#include "../../src/taxi/Cab.h"
#include "../../src/tripOperations/Driver.h"

class DriverTest : public ::testing::Test {
protected:
    Point *start;
    Point *destination;
    Node* location;
    Node* endLocation;
    Passenger *pass;
    Driver* d;

    virtual void SetUp() {
        start = new Point(3, 3);
        destination = new Point(4, 3);
        location = new Node(start);
        endLocation = new Node(destination);
        pass = new Passenger(start, destination);
        d = new Driver(305,40,MartialStatues::WIDOWED,7);
    }

    virtual void TearDown() {
        delete (location);
        delete (endLocation);
        delete (pass);
        delete (d);
    }
};

/**
 * check getId method.
 */
TEST_F(DriverTest, getId) {
    ASSERT_TRUE(d->getId() == 305);
}

/**
 * check setId method.
 */
TEST_F(DriverTest, setId ) {
    d->setId(200);
    ASSERT_TRUE(d->getId() == 200);
}

/**
 * check getAge method.
 */
TEST_F(DriverTest, getAge) {
    ASSERT_TRUE(d->getAge() == 40);
}

/**
 * check setAge method.
 */
TEST_F(DriverTest, setAge) {
    d->setId(35);
    ASSERT_TRUE(d->getId() == 35);
}

/**
 * check getStatus method.
 */
TEST_F(DriverTest, getStatus) {
    ASSERT_TRUE(d->getStatus() == MartialStatues::WIDOWED);
}

/**
 * check setStatus method.
 */
TEST_F(DriverTest, setStatus) {
    d->setStatus(MartialStatues::SINGLE);
    ASSERT_TRUE(d->getStatus() == MartialStatues::SINGLE);
}

/**
 * check getExperience method.
 */
TEST_F(DriverTest, getExperience) {
    ASSERT_TRUE(d->getExperience() == 7);
}

/**
 * check setExperience method.
 */
TEST_F(DriverTest, setExperience) {
    d->setExperience(8);
    ASSERT_TRUE(d->getExperience() == 8);
}

/**
 * check getAndSetTi method.
 */
TEST_F(DriverTest, getAndSetTi) {
    Passenger p1(start,destination),p2(start,destination),p3(start,destination);
    Passenger* pass1 = &p1;
    Passenger* pass2 = &p2;
    Passenger* pass3 = &p3;
    Passenger* p[3] = {pass1,pass2,pass3};
    TripInfo ti1(300,start,destination,3,p,100);
    TripInfo ti2(300,start,destination,3,p,100);
    ASSERT_TRUE(ti1 == ti2);
    d->setTi(&ti1);
    EXPECT_TRUE(*d->getTi() == ti2);
}


/**
 * check getAndSetCab method.
 */
TEST_F(DriverTest, getAndSetCab) {
    Cab cab1(300,Color::GREEN,CarManufacture::TESLA,50 ,4453523 ,location);
    Cab cab2(300,Color::GREEN,CarManufacture::TESLA,50 ,4453523 ,location);
    ASSERT_TRUE(cab1 == cab2);
    d->setCab(&cab1);
    EXPECT_TRUE(*d->getCab() == cab2);
}

/**
 * check getSatisfaction method.
 */
TEST_F(DriverTest, getSatisfaction) {
    Satisfaction sat;
    sat.update(5);
    sat.update(7);
    d->updateSatisfaction(5);
    d->updateSatisfaction(7);
    ASSERT_TRUE(d->getSatisfaction()->getAverage() == sat.getAverage());
}

/**
 * check update method.
 */
TEST_F(DriverTest, update) {
    Satisfaction sat;
    sat.update(5);
    sat.update(7);
    d->updateSatisfaction(5);
    d->updateSatisfaction(7);
    ASSERT_TRUE(d->getSatisfaction()->getAverage() == sat.getAverage());
}

/**
 * check moveOneStep method.
 * compares expected location after moveOneStep and the real location.
 */
TEST_F(DriverTest, moveOneStep) {
    Passenger* p[1] = {pass};
    TripInfo ti(300,start,destination,3,p,100);
    Cab cab(300,Color::GREEN,CarManufacture::TESLA,50 ,4453523 ,location);
    d->setCab(&cab);
    d->moveOneStep();
    ASSERT_TRUE(*(cab.getLocation()) == *endLocation);
}

/**
 * check equality method.
 * compares 2 identical drivers.
 */
TEST_F(DriverTest, equality) {
    Driver d1(305,40,MartialStatues::WIDOWED,7);
    Driver d2(305,40,MartialStatues::WIDOWED,7);
    ASSERT_TRUE(d1 == d2);
}

/**
 * check notEquality method.
 * compares 2 not identical drivers.
 */
TEST_F(DriverTest, notEquality) {
    Driver d1(305,40,MartialStatues::WIDOWED,7);
    Driver d2(302,40,MartialStatues::WIDOWED,7);
    ASSERT_TRUE(d1 != d2);
}