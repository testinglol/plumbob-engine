
void __thiscall FUN_005bfb88(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_3 - param_2 >> 1;
  FUN_005bfbfb(iVar2 + 1);
  iVar1 = *param_1;
  iVar2 = iVar2 * 2;
  FUN_00635190(iVar1,param_2,iVar2);
  param_1[1] = iVar2 + iVar1;
  FUN_005bfb53();
  return;
}

