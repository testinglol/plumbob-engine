
void FUN_004b911d(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  
  for (; param_1 != param_2; param_1 = param_1 + 2) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
      iVar1 = param_1[1];
      param_3[1] = iVar1;
      if (iVar1 != 0) {
        *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;
      }
    }
    param_3 = param_3 + 2;
  }
  return;
}

