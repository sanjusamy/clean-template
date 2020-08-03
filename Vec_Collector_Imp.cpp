
#include "Vec_Collector.h"

Vehicle_StorageMsgConfig Vehicle_Info[MAX_VEHICLE];

update_veh_param(unsigned short index,  const Vehicle_InputMsgConfig *inputMsg)   
{
  if(inputMsg->paramId == MOTOR_TEMP)
  {
    Vehicle_Info[index].motorTempValue = inputMsg->paramValue;
  }
  else if (inputMsg->paramId == BATTERY_TEMP)
  {
    Vehicle_Info[index].batteryTempValue = inputMsg->paramValue;
  }
  else if ((inputMsg->paramId == BATTERY_SOC))
  {
    Vehicle_Info[index].batterySoc = inputMsg->paramValue;
  }
  else
  {
  }
}

void update_vehicle_information(const Vehicle_InputMsgConfig *inputMsg, Vehicle_StorageMsgConfig *storage)
{
  unsigned short index=0;
  for(index=0; index < MAX_VEHICLE; index++)
  {
    if(inputMsg.vehicleId == Vehicle_Info[index].vehicleId)
    {
      update_veh_param(index,  inputMsg);
      break;            
    }
  }  
  storage = Vehicle_Info[index];
}
