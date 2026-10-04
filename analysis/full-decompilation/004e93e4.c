
uint FUN_004e93e4(void)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int unaff_EBP;
  int iVar4;
  
  FUN_00634c24();
  uVar2 = (DAT_006f264c - DAT_006f2648) / 0x44;
  if ((*(uint *)(unaff_EBP + 8) < uVar2) &&
     (iVar4 = *(int *)(unaff_EBP + 8) * 0x44 + DAT_006f2648, iVar4 != 0)) {
    if ((iVar4 == -0x14) || (*(char *)(iVar4 + 0x18) != '\0')) {
      FUN_004e8d99(*(undefined4 *)(unaff_EBP + 8),1,0);
    }
    if (iVar4 == -0x14) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_004096c2();
    }
    FUN_005a5e48(uVar3);
    cVar1 = FUN_005a5e72();
    if (cVar1 == '\0') {
      FUN_005c1719();
      *(undefined4 *)(unaff_EBP + -4) = 0;
      FUN_004e939c(iVar4,0x7d2,unaff_EBP + -0x10);
      cVar1 = FUN_005a5e72();
      if (cVar1 == '\0') {
        FUN_004e8d99(*(undefined4 *)(unaff_EBP + 8),1,1);
        if (iVar4 == -0x14) {
          uVar3 = 0;
        }
        else {
          uVar3 = FUN_004096c2();
        }
        FUN_005a5e48(uVar3);
      }
      else {
        FUN_004e8ada(0,unaff_EBP + -0x10);
        if (DAT_006f2658 != 0) {
          uVar3 = FUN_004096c2(DAT_006f2658,*(undefined4 *)(unaff_EBP + 0xc));
          FUN_004e71be(uVar3);
          FUN_004e8ada(1,*(undefined4 *)(unaff_EBP + 0xc));
        }
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005a5e09();
    }
    uVar2 = FUN_005a5e72();
  }
  else {
    uVar2 = uVar2 & 0xffffff00;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

