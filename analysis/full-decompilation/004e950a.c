
undefined4 FUN_004e950a(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = FUN_004e8d49(param_1);
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    if (iVar3 == -0x3c) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_004096c2();
    }
    uVar1 = param_2;
    FUN_005a5e48(uVar4);
    cVar2 = FUN_005a5e72();
    if (cVar2 == '\0') {
      FUN_004e939c(iVar3,0x7d7,uVar1);
      cVar2 = FUN_005a5e72();
      if (cVar2 == '\0') {
        FUN_004e8d99(param_1,0x10,1);
        if (iVar3 == -0x3c) {
          uVar4 = 0;
        }
        else {
          uVar4 = FUN_004096c2();
        }
        FUN_005a5e48(uVar4);
      }
      else {
        FUN_004e8ada(6,uVar1);
      }
      cVar2 = FUN_005a5e72();
      if (cVar2 == '\0') {
        param_1 = 0;
        FUN_005a5631(0x11fa,&param_1,4);
        FUN_005a5e48(param_1);
        FUN_004e8ada(6,uVar1);
      }
    }
    uVar4 = FUN_005a5e72();
  }
  return uVar4;
}

