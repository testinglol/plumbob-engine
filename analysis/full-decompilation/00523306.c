
void FUN_00523306(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar2 = FUN_005f51ce();
  if (iVar2 != 0) {
    FUN_005a5e48(0);
    iVar2 = FUN_00523265();
    if (iVar2 != 0) {
      iVar2 = FUN_0042573e(iVar2);
      if (iVar2 != 0) {
        uVar3 = FUN_00401f73();
        iVar2 = FUN_004e988f(uVar3);
        if (iVar2 != -1) {
          FUN_005c1719();
          *(undefined4 *)(unaff_EBP + -4) = 0;
          cVar1 = FUN_004e93e4(iVar2,unaff_EBP + -0x10);
          if (cVar1 != '\0') {
            FUN_005a5e1c(unaff_EBP + -0x10);
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005a5e09();
        }
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

