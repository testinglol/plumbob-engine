
undefined4 __thiscall FUN_005d4796(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  for (iVar1 = 0x14; param_1 = param_1 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_2 = *param_1;
    param_2 = param_2 + 1;
  }
  return 0;
}

