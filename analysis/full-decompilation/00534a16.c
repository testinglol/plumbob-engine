
int FUN_00534a16(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (param_2 - param_1) / 0x18;
  if (0 < iVar1) {
    do {
      iVar2 = iVar1 >> 1;
      if (*(int *)(param_1 + iVar2 * 0x18) < *param_3) {
        param_1 = param_1 + iVar2 * 0x18 + 0x18;
        iVar2 = iVar1 + (-1 - iVar2);
      }
      iVar1 = iVar2;
    } while (0 < iVar2);
  }
  return param_1;
}

