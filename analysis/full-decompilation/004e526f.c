
void FUN_004e526f(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  FUN_004e532b(param_1,param_2,0,0);
  for (piVar3 = param_2; piVar3 < param_3; piVar3 = piVar3 + 1) {
    iVar1 = *piVar3;
    if (iVar1 < *param_1) {
      *piVar3 = *param_1;
      FUN_004e5372(param_1,0,(int)param_2 - (int)param_1 >> 2,iVar1);
    }
  }
  uVar2 = (int)param_2 - (int)param_1;
  while (4 < (int)(uVar2 & 0xfffffffc)) {
    FUN_004e53c4(param_1,param_2);
    uVar2 = (int)(param_2 + -1) - (int)param_1;
    param_2 = param_2 + -1;
  }
  return;
}

