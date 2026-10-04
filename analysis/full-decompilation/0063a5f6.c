
undefined4 FUN_0063a5f6(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  FUN_0063cedd(param_3);
  if ((*(byte *)(param_3 + 3) & 0x83) != 0) {
    __fclose_lk(param_3);
  }
  param_3[2] = 0;
  *param_3 = 0;
  param_3[3] = 0;
  param_3[1] = 0;
  uVar1 = FUN_00640fb6(param_1,param_2,0x40,param_3);
  FUN_0063cf2f(param_3);
  return uVar1;
}

