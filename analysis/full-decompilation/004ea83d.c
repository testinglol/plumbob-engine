
undefined4 FUN_004ea83d(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_004ea79e(param_1);
  if ((iVar1 != 0) && (*(short *)(iVar1 + 0x70) != 0)) {
    uVar2 = FUN_00404ccb((int)*(short *)(iVar1 + 0x70));
    return uVar2;
  }
  return 0;
}

