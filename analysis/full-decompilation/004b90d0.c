
void FUN_004b90d0(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    iVar1 = param_2[1];
    param_1[1] = iVar1;
    if (iVar1 != 0) {
      *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + 1;
    }
  }
  return;
}

