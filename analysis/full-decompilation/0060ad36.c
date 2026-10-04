
undefined4 FUN_0060ad36(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *local_1c [2];
  char local_14;
  char *local_8;
  
  local_8 = (char *)FUN_004096c2();
  iVar3 = 0;
  iVar1 = FUN_005d49d6();
  while ((iVar1 != 0 && (FUN_0060980f(local_1c,local_8,iVar1), local_1c[0] != (char *)0x0))) {
    local_8 = local_8 + (int)local_1c[0];
    iVar1 = iVar1 - (int)local_1c[0];
    if (local_14 == '&') {
      if (*local_8 != '&') {
        FUN_0060a98a(param_1,iVar3 + param_2,param_3,local_1c,0);
      }
    }
    else if (local_14 != '\n') {
      iVar2 = FUN_0060a98a(param_1,iVar3 + param_2,param_3,local_1c,0);
      iVar3 = iVar3 + iVar2;
    }
  }
  return 1;
}

