
int * __thiscall FUN_00431779(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *param_1;
  uVar2 = param_3 - param_2;
  if ((uint)(param_1[1] - iVar1) < uVar2) {
    FUN_00636510(iVar1,param_2,param_1[1] - iVar1);
    FUN_00412d8a((param_1[1] - *param_1) + param_2,param_3);
  }
  else {
    FUN_00636510(iVar1,param_2,uVar2);
    FUN_004064ae(*param_1 + uVar2,param_1[1]);
  }
  return param_1;
}

