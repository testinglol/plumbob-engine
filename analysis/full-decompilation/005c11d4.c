
void __thiscall FUN_005c11d4(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = param_1[1];
  param_1[1] = iVar1 + 1;
  *param_2 = *param_1;
  param_2[1] = iVar1;
  return;
}

