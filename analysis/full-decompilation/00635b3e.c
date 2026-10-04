
int FUN_00635b3e(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)param_1 - *(int *)(*(int *)(*param_1 + -4) + 4);
  iVar1 = *(int *)(*(int *)(*param_1 + -4) + 8);
  if (iVar1 != 0) {
    iVar2 = iVar2 + *(int *)((int)param_1 - iVar1);
  }
  return iVar2;
}

