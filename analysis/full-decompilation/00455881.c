
undefined4 __thiscall
FUN_00455881(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  
  iVar1 = param_5 - param_4;
  if (param_3 - param_2 < iVar1) {
    iVar1 = (param_3 - param_2) + param_4;
    FUN_00636510(param_2,param_4,iVar1 - param_4);
    FUN_00455926(param_3,iVar1,param_5);
  }
  else {
    FUN_00636510(param_2,param_4,iVar1);
    FUN_004064ae(iVar1 + param_2,param_3);
  }
  return param_1;
}

