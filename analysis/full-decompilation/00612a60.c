
void FUN_00612a60(double *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  double *pdVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  int local_20;
  double local_10;
  
  local_10 = 0.0;
  local_20 = 0;
  if (0 < param_2) {
    do {
      iVar2 = (param_2 + -1) / 2;
      iVar3 = 0;
      do {
        fVar4 = (float10)FUN_00612b70((double)(iVar3 - iVar2),(double)(local_20 - iVar2),param_3,
                                      param_4);
        iVar3 = iVar3 + 1;
        local_10 = (double)(fVar4 + (float10)local_10);
      } while (iVar3 < param_2);
      local_20 = local_20 + 1;
    } while (local_20 < param_2);
  }
  local_20 = 0;
  if (0 < param_2) {
    do {
      iVar2 = (param_2 + -1) / 2;
      iVar3 = 0;
      do {
        fVar4 = (float10)FUN_00612b70((double)(iVar3 - iVar2),(double)(local_20 - iVar2),param_3,
                                      param_4);
        pdVar1 = param_1 + 1;
        iVar3 = iVar3 + 1;
        *param_1 = (double)(fVar4 / (float10)local_10);
        param_1 = pdVar1;
      } while (iVar3 < param_2);
      local_20 = local_20 + 1;
    } while (local_20 < param_2);
  }
  return;
}

