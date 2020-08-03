#include <gtest/gtest.h>

typedef enum
{
 MOTOR_TEMP = 0,
 BATTERY_TEMP,
 BATTERY_SOC 
}Vehicle_Param;

typedef VehicleId_type unsigned short;

typedef struct{
  VehicleId_type vehicleId;
  Vehicle_Param paramId;
  float paramValue; 
}Vehicle_InputMsgConfig;

typedef struct{
  VehicleId_type vehicleId;
  float motorTempValue; 
  float batteryTempValue;
  float batterySoc;
}Vehicle_StorageMsgConfig;




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
