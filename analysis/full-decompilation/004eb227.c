
undefined1 FUN_004eb227(undefined4 param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = FUN_004e988f(param_1);
  iVar3 = FUN_004e8d49(uVar2);
  if (iVar3 == 0) {
    return 0;
  }
  uVar1 = FUN_004e8a9a();
  if ((DAT_006f2a08 != 0) && (*(int *)(DAT_006f2a08 + 0xb0) != 0)) {
    FUN_004cee86(0x20000000);
  }
  return uVar1;
}

