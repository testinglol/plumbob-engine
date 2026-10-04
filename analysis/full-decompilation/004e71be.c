
undefined1 FUN_004e71be(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char cVar6;
  undefined1 uVar7;
  void *pvVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  undefined4 extraout_ECX;
  int iVar12;
  int iVar13;
  int unaff_EBP;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  
  FUN_00634c24();
  uStack_68 = 100;
  *(undefined1 *)(unaff_EBP + -0xd) = 1;
  uStack_5c = 0x4e71d9;
  pvVar8 = operator_new(100);
  *(void **)(unaff_EBP + -0x14) = pvVar8;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar8 == (void *)0x0) {
    piVar9 = (int *)0x0;
  }
  else {
    piVar9 = (int *)FUN_005dfb13();
    uStack_68 = extraout_ECX;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (piVar9 != (int *)0x0) {
    iVar1 = *piVar9;
    uStack_5c = 0;
    uStack_60 = 0;
    *(undefined4 **)(unaff_EBP + -0x14) = &uStack_68;
    uStack_64 = uStack_68;
    FUN_00436a50(4);
    cVar6 = (**(code **)(iVar1 + 0xc))(DAT_006f2600 << 2,DAT_006f2604 * 3);
    if (cVar6 != '\0') {
      cVar6 = (*(code *)((undefined4 *)*piVar9)[8])(1);
      if (cVar6 != '\0') {
        uVar7 = (**(code **)(*piVar9 + 0x38))(DAT_006f2a64,0);
        uVar2 = DAT_006f2a64;
        *(undefined1 *)(unaff_EBP + -0xe) = uVar7;
        (**(code **)(*piVar9 + 0x68))(uVar2);
        (**(code **)(*piVar9 + 0x24))(1);
        if (*(char *)(unaff_EBP + -0xe) == '\0') {
          *(undefined1 *)(unaff_EBP + -0xd) = 0;
        }
      }
      cVar6 = (**(code **)(*piVar9 + 0x20))(0x10);
      if (cVar6 != '\0') {
        iVar1 = *(int *)(unaff_EBP + 0xc);
        uVar2 = *(undefined4 *)(iVar1 + 0x20);
        uVar3 = *(undefined4 *)(iVar1 + 0x14);
        uVar4 = *(undefined4 *)(iVar1 + 0x18);
        uVar5 = *(undefined4 *)(iVar1 + 0x1c);
        *(undefined4 *)(unaff_EBP + -0x48) = uVar2;
        *(undefined4 *)(unaff_EBP + -0x28) = uVar2;
        *(undefined4 *)(unaff_EBP + -0x54) = uVar3;
        *(undefined4 *)(unaff_EBP + -0x50) = uVar4;
        *(undefined4 *)(unaff_EBP + -0x4c) = uVar5;
        *(undefined4 *)(unaff_EBP + -0x34) = uVar3;
        *(undefined4 *)(unaff_EBP + -0x30) = uVar4;
        *(undefined4 *)(unaff_EBP + -0x2c) = uVar5;
        iVar12 = 3;
        do {
          cVar6 = (**(code **)(*piVar9 + 0x9c))(iVar1,unaff_EBP + -0x54,unaff_EBP + -0x34,0);
          if (cVar6 == '\0') {
            *(undefined1 *)(unaff_EBP + -0xd) = 0;
          }
          iVar10 = *(int *)(unaff_EBP + -0x48) - *(int *)(unaff_EBP + -0x50);
          *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + iVar10;
          *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + iVar10;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
        *(undefined4 *)(unaff_EBP + 0xc) = 0;
        iVar1 = *(int *)(unaff_EBP + 8);
        do {
          iVar12 = *(int *)(iVar1 + 0x14);
          uVar2 = *(undefined4 *)(iVar1 + 0x20);
          *(undefined4 *)(unaff_EBP + -0x20) = *(undefined4 *)(iVar1 + 0x18);
          iVar10 = *(int *)(iVar1 + 0x1c);
          *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
          *(int *)(unaff_EBP + -0x24) = iVar12;
          iVar11 = DAT_006f2610;
          iVar13 = 4;
          *(int *)(unaff_EBP + -0x1c) = (iVar10 - iVar12) / 3 + iVar12;
          iVar12 = DAT_006f2608;
          *(int *)(unaff_EBP + -0x44) = DAT_006f2608;
          iVar10 = DAT_006f260c;
          *(int *)(unaff_EBP + -0x3c) = iVar12 + iVar11;
          iVar12 = iVar10 + DAT_006f2614;
          iVar11 = DAT_006f2604 * *(int *)(unaff_EBP + 0xc);
          *(int *)(unaff_EBP + -0x40) = iVar10 + iVar11;
          *(int *)(unaff_EBP + -0x38) = iVar12 + iVar11;
          do {
            cVar6 = (**(code **)(*piVar9 + 0x9c))(iVar1,unaff_EBP + -0x24,unaff_EBP + -0x44,0);
            if (cVar6 == '\0') {
              *(undefined1 *)(unaff_EBP + -0xd) = 0;
            }
            iVar12 = DAT_006f2600;
            *(int *)(unaff_EBP + -0x44) = *(int *)(unaff_EBP + -0x44) + DAT_006f2600;
            *(int *)(unaff_EBP + -0x3c) = *(int *)(unaff_EBP + -0x3c) + iVar12;
            iVar13 = iVar13 + -1;
          } while (iVar13 != 0);
          iVar12 = *(int *)(unaff_EBP + -0x1c) - *(int *)(unaff_EBP + -0x24);
          *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + iVar12;
          *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + iVar12;
          *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
        } while (*(int *)(unaff_EBP + 0xc) < 3);
        (**(code **)(*piVar9 + 0x24))(0x10);
      }
      FUN_005a5e48(piVar9);
      uVar7 = *(undefined1 *)(unaff_EBP + -0xd);
      goto LAB_004e738c;
    }
    (**(code **)*piVar9)();
  }
  uVar7 = 0;
LAB_004e738c:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar7;
}

