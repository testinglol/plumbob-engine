
void __thiscall FUN_004c9496(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  if ((param_2 + 2 != *(undefined4 **)(param_1 + 4)) &&
     (iVar1 = (int)*(undefined4 **)(param_1 + 4) - (int)(param_2 + 2) >> 3, 0 < iVar1)) {
    do {
      *param_2 = param_2[2];
      iVar1 = iVar1 + -1;
      param_2[1] = param_2[3];
      param_2 = param_2 + 2;
    } while (iVar1 != 0);
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -8;
  return;
}

