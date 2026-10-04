
undefined4 __thiscall
FUN_0059913f(int param_1,int *param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)(param_1 + 0x7c);
  *(undefined4 *)((int)param_2 + 0x78) = 0;
  iVar3 = *(int *)(param_1 + 0x80) - *piVar1 >> 2;
  param_7 = FUN_0059787c(param_1,param_3,param_4,param_5,param_6,param_7);
  iVar2 = 0;
  if (0 < iVar3) {
    param_2 = (int *)*piVar1;
    do {
      if (param_3 < *(int *)(*param_2 + 0x14)) break;
      param_2 = param_2 + 1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar3);
  }
  FUN_0059b142(*piVar1 + iVar2 * 4,&param_7);
  *(undefined4 *)(param_1 + 0x94) = 1;
  return param_7;
}

