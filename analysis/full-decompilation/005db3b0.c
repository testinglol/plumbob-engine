
void __thiscall FUN_005db3b0(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  if ((param_2 + 4 != *(undefined4 **)(param_1 + 4)) &&
     (iVar1 = (int)*(undefined4 **)(param_1 + 4) - (int)(param_2 + 4) >> 4, 0 < iVar1)) {
    do {
      iVar1 = iVar1 + -1;
      *param_2 = param_2[4];
      param_2[1] = param_2[5];
      param_2[2] = param_2[6];
      param_2[3] = param_2[7];
      param_2 = param_2 + 4;
    } while (iVar1 != 0);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -0x10;
  return;
}

