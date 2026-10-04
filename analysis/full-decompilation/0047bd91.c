
void FUN_0047bd91(int *param_1,int *param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  
  if (param_3 == 0) {
    return;
  }
  param_4 = param_4 + -1;
  if (param_3 == 1) {
    iVar2 = *param_1;
    piVar1 = param_1;
    param_1 = param_2;
  }
  else {
    if (param_3 == 2) {
      *param_1 = param_4 - *param_1;
      *param_2 = param_4 - *param_2;
      return;
    }
    if (param_3 != 3) {
      return;
    }
    iVar2 = *param_2;
    piVar1 = param_2;
  }
  *piVar1 = param_4 - *param_1;
  *param_1 = iVar2;
  return;
}

