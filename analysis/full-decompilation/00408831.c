
int FUN_00408831(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (param_2 - param_1) / 0x14;
  iVar2 = param_3;
  if (0 < iVar1) {
    do {
      iVar2 = param_3 + -0x14;
      FUN_00408207(param_2 + -0x14);
      iVar1 = iVar1 + -1;
      *(undefined4 *)(param_3 + -8) = *(undefined4 *)(param_2 + -8);
      *(undefined4 *)(param_3 + -4) = *(undefined4 *)(param_2 + -4);
      param_3 = iVar2;
      param_2 = param_2 + -0x14;
    } while (iVar1 != 0);
  }
  return iVar2;
}

