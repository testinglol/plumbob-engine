
undefined4 __thiscall FUN_0057c57e(int *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)*param_1;
  if (piVar3 != (int *)*param_1) {
    do {
      iVar1 = piVar3[2];
      iVar2 = FUN_0057c675(param_2);
      if (iVar2 != 0) {
        FUN_005d499c(iVar1);
        *param_4 = iVar2;
        return 1;
      }
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)*param_1);
  }
  return 0;
}

