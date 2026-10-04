
undefined4 * __thiscall
FUN_00458419(undefined4 *param_1,undefined4 param_2,int param_3,undefined1 param_4)

{
  undefined4 uVar1;
  
  param_1[1] = 0;
  param_1[7] = 0;
  *param_1 = param_2;
  *(undefined1 *)(param_1 + 2) = param_4;
  uVar1 = 0;
  if (param_3 != 0) {
    uVar1 = FUN_0043532b();
  }
  param_1[1] = uVar1;
  return param_1;
}

