
void __thiscall FUN_00455790(int *param_1,uint param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int **ppiVar3;
  int *local_8;
  
  if ((uint)(param_1[1] - *param_1) < param_2) {
    local_8 = param_1;
    FUN_004064df();
  }
  local_8 = (int *)((param_1[1] - *param_1) - param_2);
  ppiVar3 = &local_8;
  if (param_3 <= local_8) {
    ppiVar3 = &param_3;
  }
  piVar1 = *ppiVar3;
  iVar2 = *param_4;
  param_3 = (int *)param_4[1];
  if ((iVar2 - (int)param_3) - 2U <= (uint)((param_1[1] - *param_1) - (int)piVar1)) {
    FUN_004018ec();
  }
  FUN_00455881(*param_1 + param_2,(int)piVar1 + param_2 + *param_1,iVar2,param_3);
  return;
}

