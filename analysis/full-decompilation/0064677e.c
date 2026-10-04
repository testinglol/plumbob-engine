
undefined4 FUN_0064677e(byte *param_1,byte *param_2)

{
  byte *pbVar1;
  undefined4 uVar2;
  
  if (DAT_0070513c != 0) {
    FUN_0063d88b(0x19);
    while ((param_1 <= param_2 && (*param_1 != 0))) {
      pbVar1 = param_1;
      if ((*(byte *)((int)&DAT_00705240 + *param_1 + 1) & 4) != 0) {
        pbVar1 = param_1 + 1;
        if (param_1 == param_2) {
          uVar2 = 0xffffffff;
LAB_006467c4:
          FUN_0063d8ec(0x19);
          return uVar2;
        }
        if (*pbVar1 == 0) {
          uVar2 = 0;
          goto LAB_006467c4;
        }
      }
      param_1 = pbVar1 + 1;
    }
    FUN_0063d8ec(0x19);
  }
  return 0;
}

