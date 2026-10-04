
undefined4 FUN_0049b9e6(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_48 [64];
  undefined4 local_8;
  
  local_8 = 0;
  iVar2 = param_3;
  if ((*(int *)(param_2 + 0x40) == 1) || (iVar2 = param_2, *(int *)(param_3 + 0x40) == 1)) {
    FUN_005c36c0(iVar2);
  }
  else {
    uVar1 = FUN_00462c49(local_48,param_2,param_3);
    FUN_005c3650(uVar1);
  }
  return param_1;
}

