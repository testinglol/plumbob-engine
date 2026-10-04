
void FUN_0062ea80(uint param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x3f800000;
  }
  else {
    if ((param_1 & 1) == 0) {
      *(undefined4 *)(param_4 + param_3 * 4) = 0x3f800000;
      *(undefined4 *)(param_4 + 0x900 + param_3 * 4) =
           *(undefined4 *)(&DAT_00685a34 + ((param_1 >> 1) + param_2 * 0x20) * 4);
      return;
    }
    uVar1 = *(undefined4 *)(&DAT_00685a34 + ((param_1 + 1 >> 1) + param_2 * 0x20) * 4);
  }
  *(undefined4 *)(param_4 + param_3 * 4) = uVar1;
  *(undefined4 *)(param_4 + 0x900 + param_3 * 4) = 0x3f800000;
  return;
}

