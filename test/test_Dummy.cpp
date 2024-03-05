#include <boost/test/unit_test.hpp>
#include <lidar_ouster/Dummy.hpp>

using namespace lidar_ouster;

BOOST_AUTO_TEST_CASE(it_should_not_crash_when_welcome_is_called)
{
    lidar_ouster::DummyClass dummy;
    dummy.welcome();
}
