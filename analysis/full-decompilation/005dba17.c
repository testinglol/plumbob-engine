
int FUN_005dba17(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(param_2 + 8);
  iVar3 = *(int *)(param_3 + 8);
  if (iVar1 < iVar2) {
    if (iVar3 <= iVar2) {
      if (iVar3 <= iVar1) {
        return param_1;
      }
      return param_3;
    }
  }
  else {
    if (iVar1 < iVar3) {
      return param_1;
    }
    if (iVar2 < iVar3) {
      return param_3;
    }
  }
  return param_2;
}

