#include <gtest/gtest.h>
#include "Vec_Collector.h"


TEST(VehicleCollectorTest, when_a_parameter_received_from_a_vehicle_should_update_aginst_vechile_id) 
{ 
 Vehicle_InputMsgConfig inputMsg = {1, MOTOR_TEMP, 23.5};
 Vehicle_StorageMsgConfig vehicleRecord;
 update_vehicle_information(&inputMsg, &vehicleRecord);
 EXPECT_NEAR(23.5, vehicleRecord.motorTempValue, 0.01);  
}

 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
