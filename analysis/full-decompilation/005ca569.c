
undefined1 FUN_005ca569(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_5;
  
  iVar2 = 0;
  iVar3 = 0x7fffffff;
  local_5 = 0;
  do {
    iVar1 = FUN_005ca52e(param_1,param_2);
    if (iVar1 < iVar3) {
      local_5 = (undefined1)iVar2;
      iVar3 = iVar1;
    }
    iVar2 = iVar2 + 1;
    param_2 = param_2 + 4;
  } while (iVar2 < 0x100);
  return local_5;
}

