
void __thiscall FUN_004b45e2(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  for (iVar1 = 0x1d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

