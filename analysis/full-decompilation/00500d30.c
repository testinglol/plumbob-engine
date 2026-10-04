
undefined4 FUN_00500d30(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int extraout_ECX;
  int unaff_EBP;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  
  FUN_00634c24();
  if (*(char *)(extraout_ECX + 0xe0) != '\0') {
    iVar5 = *(int *)(extraout_ECX + 0xd4);
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0x32;
    FUN_004d26ba(*(undefined4 *)(iVar5 + 0x54),unaff_EBP + -0x20,unaff_EBP + -0x1c);
    FUN_004cb21d(DAT_006f2c08 - *(int *)(unaff_EBP + -0x20),DAT_006f2c0c);
    FUN_004cb21d(DAT_006f2c00 - *(int *)(unaff_EBP + -0x20),DAT_006f2c04);
    piVar4 = &DAT_006f2ba0;
    *(undefined4 **)(unaff_EBP + -0x14) = &DAT_006f2ba0;
    while( true ) {
      FUN_004cb21d(*piVar4 - *(int *)(unaff_EBP + -0x20),piVar4[1]);
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 8;
      if (0x6f2bff < *(int *)(unaff_EBP + -0x14)) break;
      piVar4 = *(int **)(unaff_EBP + -0x14);
    }
    iVar5 = *(int *)(extraout_ECX + 0x128);
    iVar7 = *(int *)(extraout_ECX + 0x124);
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    iVar5 = iVar5 - iVar7 >> 2;
    FUN_0054821c(iVar5,unaff_EBP + -0xd);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uVar6 = FUN_005fd5b4(*(undefined4 *)(unaff_EBP + -0x34),iVar5,unaff_EBP + -0x14,
                         *(undefined4 *)(unaff_EBP + -0x18));
    *(undefined4 *)(unaff_EBP + -0x30) = uVar6;
    iVar5 = *(int *)(extraout_ECX + 0x128);
    uVar8 = 0;
    iVar7 = *(int *)(extraout_ECX + 0x124);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (iVar5 - iVar7 >> 2 != 0) {
      do {
        if (*(int *)(*(int *)(extraout_ECX + 0x124) + uVar8 * 4) != 0) {
          *(uint *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x34) + uVar8 * 4;
          uVar6 = FUN_00492d2c();
          **(undefined4 **)(unaff_EBP + -0x18) = uVar6;
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < (uint)(*(int *)(extraout_ECX + 0x128) - *(int *)(extraout_ECX + 0x124) >> 2))
      ;
    }
    piVar4 = (int *)(extraout_ECX + 0x158);
    iVar7 = *(int *)(extraout_ECX + 0x128) - *(int *)(extraout_ECX + 0x124) >> 2;
    iVar5 = *piVar4;
    *(int *)(unaff_EBP + -0x18) = iVar7;
    if (iVar7 <= iVar5) {
      piVar4 = (int *)(unaff_EBP + -0x18);
    }
    FUN_004ebf01(*(undefined4 *)(unaff_EBP + -0x34),*piVar4);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0048c4c9();
    FUN_004cb21d(0x222 - *(int *)(unaff_EBP + -0x20),0x1a);
    FUN_004cb21d((*(int *)(extraout_ECX + 0x84) - *(int *)(extraout_ECX + 0x7c)) + -0xe,0x1a);
    *(undefined1 *)(extraout_ECX + 0xe0) = 0;
  }
  if ((*(int *)(extraout_ECX + 0xdc) != 0) && (*(int **)(extraout_ECX + 0x5c) != (int *)0x0)) {
    cVar3 = (**(code **)(**(int **)(extraout_ECX + 0x5c) + 0x20))(0x10);
    if (cVar3 != '\0') {
      iVar5 = *(int *)(extraout_ECX + 0xdc);
      iVar7 = *(int *)(extraout_ECX + 0x20);
      iVar9 = *(int *)(iVar5 + 0x20);
      iVar1 = *(int *)(iVar5 + 0x1c);
      *(int *)(unaff_EBP + -0x4c) = iVar9;
      *(undefined4 *)(unaff_EBP + -0x58) = 0;
      *(undefined4 *)(unaff_EBP + -0x54) = 0;
      iVar2 = *(int *)(extraout_ECX + 0x1c);
      *(int *)(unaff_EBP + -0x44) = iVar7;
      *(int *)(unaff_EBP + -0x50) = iVar1;
      *(int *)(unaff_EBP + -0x3c) = iVar9 + iVar7;
      piVar4 = *(int **)(extraout_ECX + 0x5c);
      *(int *)(unaff_EBP + -0x48) = iVar2;
      *(int *)(unaff_EBP + -0x40) = iVar1 + iVar2;
      (**(code **)(*piVar4 + 0x9c))(iVar5,unaff_EBP + -0x58,unaff_EBP + -0x48,0);
      iVar5 = *(int *)(extraout_ECX + 0x17c);
      if (iVar5 != 0) {
        piVar4 = *(int **)(extraout_ECX + 0x5c);
        *(undefined4 *)(unaff_EBP + -0x20) = 0x31;
        *(undefined4 *)(unaff_EBP + -0x1c) = 6;
        uVar10 = 0;
        iVar1 = *piVar4;
        iVar7 = unaff_EBP + -0x20;
        iVar9 = unaff_EBP + -0x38;
        *(int *)(unaff_EBP + -0x18) = iVar5 + 0x14;
        FUN_004df599(unaff_EBP + -0x68,extraout_ECX + 0x1c);
        uVar6 = FUN_004df599(iVar9,iVar7);
        (**(code **)(iVar1 + 0x9c))
                  (*(undefined4 *)(extraout_ECX + 0x17c),*(undefined4 *)(unaff_EBP + -0x18),uVar6,
                   uVar10);
      }
      iVar5 = *(int *)(extraout_ECX + 0x180);
      if (iVar5 != 0) {
        *(undefined4 *)(unaff_EBP + -0x24) = 6;
        piVar4 = *(int **)(extraout_ECX + 0x5c);
        *(undefined4 *)(unaff_EBP + -0x28) = 0x13f;
        uVar10 = 0;
        iVar1 = *piVar4;
        iVar7 = unaff_EBP + -0x28;
        iVar9 = unaff_EBP + -0x78;
        FUN_004df599(unaff_EBP + -0x88,extraout_ECX + 0x1c);
        uVar6 = FUN_004df599(iVar9,iVar7);
        (**(code **)(iVar1 + 0x9c))(*(undefined4 *)(extraout_ECX + 0x180),iVar5 + 0x14,uVar6,uVar10)
        ;
      }
      (**(code **)(**(int **)(extraout_ECX + 0x5c) + 0x24))(0x10);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

