
undefined4 __thiscall FUN_00404df6(int *param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 != -1) {
    iVar2 = FUN_004ea79e(param_2);
    sVar1 = *(short *)(iVar2 + 0xa2);
    iVar2 = (int)sVar1;
    if ((iVar2 != 0) && (-1 < iVar2)) {
      iVar3 = FUN_004ea79e(param_2);
      if ((int)*(short *)(iVar3 + 0xa0) < *(int *)(*param_1 + -4 + iVar2 * 4)) {
        iVar2 = FUN_004ea79e(param_2);
        *(short *)(iVar2 + 0xa2) = sVar1 + -1;
        return 1;
      }
    }
  }
  return 0;
}

