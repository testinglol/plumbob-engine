
void __thiscall FUN_005db2f2(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  if ((param_2 + 1 != *(undefined4 **)(param_1 + 4)) &&
     (iVar1 = (int)*(undefined4 **)(param_1 + 4) - (int)(param_2 + 1) >> 2, 0 < iVar1)) {
    do {
      *param_2 = param_2[1];
      iVar1 = iVar1 + -1;
      param_2 = param_2 + 1;
    } while (iVar1 != 0);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -4;
  return;
}

