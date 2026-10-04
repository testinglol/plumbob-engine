
void FUN_004236d0(uint param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_2;
  iVar2 = *param_3;
  *param_3 = 0;
  *param_2 = 0;
  param_1 = param_1 & 7;
  if (param_1 == 0) {
    *param_2 = iVar1;
  }
  else {
    if (param_1 == 2) {
      *param_3 = iVar1;
      *param_2 = -iVar2;
      return;
    }
    if (param_1 != 4) {
      if (param_1 != 6) {
        return;
      }
      *param_2 = iVar2;
      *param_3 = -iVar1;
      return;
    }
    *param_2 = -iVar1;
    iVar2 = -iVar2;
  }
  *param_3 = iVar2;
  return;
}

