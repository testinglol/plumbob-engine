
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_004e5685(int *param_1,uint *param_2)

{
  char cVar1;
  char cVar2;
  uint in_EAX;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if (DAT_006f25c0 == '\0') {
    DAT_006f25bc = DAT_006f0bcc;
    DAT_006f25b8 = DAT_006f0bbc;
    DAT_006f25b4 = DAT_006f0bd0;
    DAT_006f25b0 = DAT_006f0bd4;
    DAT_006f25a8 = _DAT_006f0bc0;
    DAT_006f25ac = _DAT_006f0bc4;
    DAT_006f25c4 = DAT_006f0080;
    DAT_006f25c0 = 1;
    DAT_006f25c8 = DAT_006f0084;
    DAT_006f0bcc = 0;
    DAT_006f0bbc = 0;
    DAT_006f0bd0 = 0;
    DAT_006f0bd4 = 0;
    local_14 = param_1[5];
    local_10 = param_1[6];
    local_c = param_1[7];
    local_8 = param_1[8];
    FUN_005de841(param_2,&local_14);
    if ((((local_24 == *param_2) && (local_24 = local_1c, local_1c == param_2[2])) &&
        (local_24 = local_20, local_20 == param_2[1])) &&
       (local_24 = local_18, local_18 == param_2[3])) {
      cVar1 = (**(code **)(*param_1 + 0x20))(0x40);
      local_24 = (**(code **)(*(int *)param_1[0x17] + 0x20))(0x40);
      cVar2 = (char)local_24;
      if (cVar1 != '\0') {
        if (cVar2 != '\0') {
          DAT_006f0bcc = (**(code **)(*param_1 + 0xcc))();
          DAT_006f0bbc = (**(code **)(*param_1 + 0xd0))();
          DAT_006f0bd0 = (**(code **)(*(int *)param_1[0x17] + 0xcc))();
          DAT_006f0bd4 = (**(code **)(*(int *)param_1[0x17] + 0xd0))();
          if ((DAT_006f0bd0 != 0) && (DAT_006f0bcc != 0)) {
            _DAT_006f0bc4 =
                 CONCAT22((short)param_2[2] - (short)*param_2,(short)param_2[3] - (short)param_2[1])
            ;
            DAT_006f0080 = 100;
            DAT_006f0084 = 100;
            _DAT_006f0bc0 = 0;
            DAT_006f0bcc = param_2[1] * DAT_006f0bbc + DAT_006f0bcc + *param_2 * 2;
            DAT_006f0bd0 = param_2[1] * DAT_006f0bd4 + DAT_006f0bd0 + *param_2 * 2;
            return 1;
          }
        }
        local_24 = (**(code **)(*param_1 + 0x24))(0x40);
      }
      if (cVar2 != '\0') {
        local_24 = (**(code **)(*(int *)param_1[0x17] + 0x24))(0x40);
      }
    }
    DAT_006f25c0 = '\0';
    in_EAX = local_24;
  }
  return in_EAX & 0xffffff00;
}

