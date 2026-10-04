
undefined4 FUN_004e9692(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = FUN_004e8d49(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  if ((iVar2 == -0x24) || (*(char *)(iVar2 + 0x28) != '\0')) {
    FUN_004e8d99(param_1,2,0);
  }
  if (iVar2 == -0x24) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_004096c2();
  }
  FUN_005a5e48(uVar3);
  cVar1 = FUN_005a5e72();
  if (cVar1 == '\0') {
    FUN_004e939c(iVar2,0x7d4,param_2);
    cVar1 = FUN_005a5e72();
    if (cVar1 == '\0') {
      FUN_004e8d99(param_1,2,1);
      if (iVar2 == -0x24) {
        uVar3 = 0;
      }
      else {
        uVar3 = FUN_004096c2();
      }
      FUN_005a5e48(uVar3);
    }
    else {
      FUN_004e8ada(3,param_2);
    }
  }
  uVar3 = FUN_005a5e72();
  return uVar3;
}

