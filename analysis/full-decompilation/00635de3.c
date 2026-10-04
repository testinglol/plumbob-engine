
int FUN_00635de3(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = param_2[1];
  if (-1 < iVar1) {
    iVar2 = iVar1 + *(int *)(*(int *)(iVar1 + param_1) + param_2[2]);
  }
  return *param_2 + iVar2;
}

