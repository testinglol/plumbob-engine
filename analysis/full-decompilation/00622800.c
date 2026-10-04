
undefined4
FUN_00622800(int *param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
            int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (0 < param_7) {
    iVar1 = *param_1;
    iVar2 = param_1[1];
    iVar3 = param_1[2];
    param_3 = iVar3 * param_3;
    do {
      param_2 = param_2 + param_4;
      iVar4 = *(int *)(iVar1 + 0x18) * param_2;
      param_3 = param_3 + iVar3 * param_5;
      iVar4 = FUN_006227e0(((int)(iVar4 + (iVar4 >> 0x1f & 7U)) >> 3) + param_3 + iVar2,param_6);
      if (iVar4 != 0) {
        return 1;
      }
      param_7 = param_7 + -1;
    } while (0 < param_7);
  }
  return 0;
}

