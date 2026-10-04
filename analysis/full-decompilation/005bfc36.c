
int * __thiscall FUN_005bfc36(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = *param_1;
  uVar4 = param_3 - param_2 >> 1;
  uVar3 = param_1[1] - iVar1 >> 1;
  if (uVar3 < uVar4) {
    FUN_00636510(iVar1,param_2,uVar3 * 2);
    FUN_005bfcef(param_2 + (param_1[1] - *param_1 >> 1) * 2,param_3);
  }
  else {
    iVar2 = uVar4 * 2;
    FUN_00636510(iVar1,param_2,iVar2);
    FUN_005bd7f0(iVar2 + *param_1,param_1[1]);
  }
  return param_1;
}

