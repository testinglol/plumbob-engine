
undefined4 FUN_0042dea1(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_0042debc(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  *(uint *)(iVar1 + 0x138) = *(uint *)(iVar1 + 0x138) & 0xfffffff7;
  return 1;
}

