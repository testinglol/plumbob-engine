
byte * FUN_0063c51f(byte *param_1,byte *param_2)

{
  byte *pbVar1;
  
  if (param_1 < param_2) {
    if (DAT_0070513c == 0) {
      param_2 = param_2 + -1;
    }
    else {
      FUN_0063d88b(0x19);
      pbVar1 = param_2 + -1;
      if ((*(byte *)((int)&DAT_00705240 + param_2[-1] + 1) & 4) == 0) {
        do {
          pbVar1 = pbVar1 + -1;
          if (pbVar1 < param_1) break;
        } while ((*(byte *)((int)&DAT_00705240 + *pbVar1 + 1) & 4) != 0);
        FUN_0063d8ec(0x19);
        param_2 = param_2 + (-1 - ((int)param_2 - (int)pbVar1 & 1U));
      }
      else {
        FUN_0063d8ec(0x19);
        param_2 = param_2 + -2;
      }
    }
  }
  else {
    param_2 = (byte *)0x0;
  }
  return param_2;
}

