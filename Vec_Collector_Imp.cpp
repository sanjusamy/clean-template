
#include "Vec_Collector.h"
#include <string.h>

Vehicle_StorageMsgConfig Vehicle_Info[MAX_VEHICLE] = {
  {1,0,0,0},
  {2,0,0,0},
  {3,0,0,0},
  {4,0,0,0},
  {5,0,0,0},
  {6,0,0,0},
  {7,0,0,0},
  {8,0,0,0},
  {9,0,0,0},
  {10,0,0,0},
};

void update_veh_param(unsigned short index,  const Vehicle_InputMsgConfig *inputMsg)   
{
  if(inputMsg->paramId == MOTOR_TEMP)
  {
    Vehicle_Info[index].motorTempValue = inputMsg->paramValue;
  }
  else if (inputMsg->paramId == BATTERY_TEMP)
  {
    Vehicle_Info[index].batteryTempValue = inputMsg->paramValue;
  }
  else 
  {
    Vehicle_Info[index].batterySoc = inputMsg->paramValue;
  }  
}

void update_vehicle_information(const Vehicle_InputMsgConfig *inputMsg, Vehicle_StorageMsgConfig *storage)
{
  unsigned short index=0;
  for(index=0; index < MAX_VEHICLE; index++)
  {
    if(inputMsg->vehicleId == Vehicle_Info[index].vehicleId)
    {
      update_veh_param(index,  inputMsg);
      break;            
    }
  }  
  memcpy(storage, &Vehicle_Info[index], sizeof(Vehicle_Info[0]));
}
