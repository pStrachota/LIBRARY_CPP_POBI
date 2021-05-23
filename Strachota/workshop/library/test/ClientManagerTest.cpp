#include <boost/test/unit_test.hpp>
#include "managers/ClientManager.h"
#include <memory>
#include "model/Bronze.h"
#include <functional>
#include "model/Address.h"

struct TestSuiteClientManagerFixture {

    ClientTypePtr testClientTypeBronze;
    AddressPtr testaddress3;

TestSuiteClientManagerFixture() {
    testClientTypeBronze = std::make_shared<Bronze>();
    testaddress3 = std::make_shared<Address>("London", "Rue Morgue", "13");
}

~TestSuiteClientManagerFixture() {
    }

    };

BOOST_FIXTURE_TEST_SUITE(TestSuiteClientManager, TestSuiteClientManagerFixture)

    BOOST_AUTO_TEST_CASE(findByPersonalIdTestPositiveTest) {
        clientManager c;
        ClientPtr client = c.registerClient("Piotr", "Strachota", "1", testaddress3, testClientTypeBronze);
        BOOST_TEST(client = c.getClient("1"));

}

    BOOST_AUTO_TEST_CASE(findByPersonalIdTestNegativeTest) {
        clientManager c;
        ClientPtr client = c.registerClient("Piotr", "Strachota", "1", testaddress3, testClientTypeBronze);
        ClientPtr client2 = c.registerClient("Robert", "Maklowicz", "1", testaddress3, testClientTypeBronze);
        BOOST_TEST(client == client2);
}


BOOST_AUTO_TEST_SUITE_END()