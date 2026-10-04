
void __thiscall FUN_004df599(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = *param_1;
  iVar2 = param_3[1];
  iVar3 = *param_3;
  iVar4 = param_1[1];
  iVar5 = param_1[3];
  param_2[2] = param_1[2] + iVar3;
  param_2[1] = iVar4 + iVar2;
  *param_2 = iVar1 + iVar3;
  param_2[3] = iVar5 + iVar2;
  return;
}

