typedef enum
{
 MOTOR_TEMP = 0,
 BATTERY_TEMP,
 BATTERY_SOC 
}Vehicle_Param;

typedef unsigned short VehicleId_type;

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

#define MAX_VEHICLE  10
