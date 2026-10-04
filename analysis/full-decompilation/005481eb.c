
void __thiscall FUN_005481eb(int *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[1];
  iVar2 = *param_1;
  if ((uint)(iVar1 - iVar2) < param_2) {
    FUN_00548250((iVar2 - iVar1) + param_2,param_3);
  }
  else {
    FUN_004064ae(iVar2 + param_2,iVar1);
  }
  return;
}

