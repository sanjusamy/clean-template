#include <gtest/gtest.h>
#include "Vec_Collector.h"


TEST(VitalsTest, when_a_parameter_received_from_a_vehicle_should_update_aginst_vechile_id) 
{ 
 Vehicle_InputMsgConfig inputMsg = {1, MOTOR_TEMP, 23.5};
 Update_Vehicle_param(&inputMsg, &vehicleStorage);
 EXPECT_NEAR(23.5, vehicleStorage.motorTempValue, 0.001);  
}

 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
