
int * FUN_0041e9a2(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  iVar2 = *param_2;
  iVar3 = *param_3;
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

