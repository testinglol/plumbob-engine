
undefined4 * __thiscall
FUN_004227e6(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  
  FUN_0043194c(param_2,param_4);
  *param_1 = &PTR_FUN_00666c20;
  param_1[100] = param_3;
  param_1[99] = 0;
  if (param_3 != 0) {
    do {
      piVar1 = (int *)(param_3 + 0x18c);
      param_3 = *piVar1;
    } while (param_3 != 0);
    *piVar1 = (int)param_1;
  }
  param_1[0x6a] = 0;
  param_1[0x69] = 0;
  param_1[0x68] = 0;
  param_1[0x67] = 0;
  param_1[0x66] = 0;
  param_1[0x65] = 0;
  return param_1;
}

