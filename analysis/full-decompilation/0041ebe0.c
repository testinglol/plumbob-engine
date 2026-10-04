
void FUN_0041ebe0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  iVar1 = param_1[-2];
  piVar3 = param_1 + -2;
  while (piVar2 = piVar3, param_2 < iVar1) {
    *param_1 = *piVar2;
    param_1[1] = piVar2[1];
    piVar3 = piVar2 + -2;
    param_1 = piVar2;
    iVar1 = piVar2[-2];
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}

