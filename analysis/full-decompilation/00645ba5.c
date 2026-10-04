
undefined4 FUN_00645ba5(byte *param_1,byte *param_2)

{
  undefined4 uVar1;
  
  if (DAT_0070513c != 0) {
    FUN_0063d88b(0x19);
    for (; (param_1 <= param_2 && (*param_1 != 0)); param_1 = param_1 + 1) {
      if ((*(byte *)((int)&DAT_00705240 + *param_1 + 1) & 4) != 0) {
        param_1 = param_1 + 1;
        if (param_1 == param_2) {
          uVar1 = 0xffffffff;
LAB_00645be9:
          FUN_0063d8ec(0x19);
          return uVar1;
        }
        if (*param_1 == 0) {
          uVar1 = 0;
          goto LAB_00645be9;
        }
      }
    }
    FUN_0063d8ec(0x19);
  }
  return 0;
}

