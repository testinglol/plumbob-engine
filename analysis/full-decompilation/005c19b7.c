
int FUN_005c19b7(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EBP;
  int iVar3;
  
  FUN_00634c24();
  FUN_005c1165(*(undefined4 *)(unaff_EBP + 0xc));
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005c17b6(unaff_EBP + -0x2c);
  iVar3 = *(int *)(unaff_EBP + -0x28) - *(int *)(unaff_EBP + -0x2c);
  uVar1 = FUN_004096c2();
  *(undefined4 *)(unaff_EBP + 0xc) = uVar1;
  do {
    iVar2 = FUN_00401f73();
    if (*(int *)(unaff_EBP + 0xc) == iVar2) {
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      iVar2 = 0;
LAB_005c1b17:
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return iVar2;
    }
    FUN_005c2efd(unaff_EBP + -0x38,*(undefined4 *)(unaff_EBP + 0xc));
    uVar1 = *(undefined4 *)(unaff_EBP + -0x38);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005b8e25(uVar1);
    iVar2 = FUN_005ba9e5(uVar1);
    if (iVar2 != 0) {
      FUN_00580a92(unaff_EBP + -0x14);
      while (*(int *)(unaff_EBP + -0x14) != 0) {
        FUN_005b86bd(*(int *)(unaff_EBP + -0x14) + 4);
        *(undefined1 *)(unaff_EBP + -4) = 2;
        iVar2 = *(int *)(unaff_EBP + -0x1c) - *(int *)(unaff_EBP + -0x20);
        if (iVar3 <= iVar2) {
          iVar2 = FUN_00646330(*(undefined4 *)(unaff_EBP + -0x2c),
                               (iVar2 - iVar3) + *(int *)(unaff_EBP + -0x20));
          if (iVar2 == 0) {
            FUN_005b870f(*(undefined4 *)(unaff_EBP + -0x20));
            *(undefined1 *)(unaff_EBP + -4) = 3;
            iVar2 = FUN_005c10b4(unaff_EBP + -0x38,unaff_EBP + -0x44,
                                 *(undefined4 *)(unaff_EBP + 0x10));
            *(undefined1 *)(unaff_EBP + -4) = 2;
            FUN_005b8770();
            if ((iVar2 != 0) && (iVar2 != 3)) {
              *(undefined1 *)(unaff_EBP + -4) = 1;
              FUN_005b8770();
              *(undefined1 *)(unaff_EBP + -4) = 0;
              FUN_005b8770();
              *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
              FUN_005b8770();
              goto LAB_005c1b17;
            }
          }
        }
        *(undefined1 *)(unaff_EBP + -4) = 1;
        FUN_005b8770();
        FUN_005bb2f8();
      }
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 0xc;
  } while( true );
}

