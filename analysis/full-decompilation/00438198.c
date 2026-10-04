
void FUN_00438198(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  char cVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  byte bVar9;
  short sVar10;
  undefined4 extraout_ECX;
  int iVar11;
  int unaff_EBP;
  int iVar12;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x50) = 0x7fffffff;
  *(undefined4 *)(unaff_EBP + -0x4c) = 0x7fffffff;
  *(undefined4 *)(unaff_EBP + -0x48) = 0x80000000;
  *(undefined4 *)(unaff_EBP + -0x44) = 0x80000000;
  iVar5 = FUN_00492d2c();
  if (iVar5 == 1) goto LAB_00438550;
  iVar5 = *(int *)(iVar1 + 0x20);
  iVar12 = *(int *)(unaff_EBP + 0x10);
  *(int *)(unaff_EBP + -0x14) = 3 - iVar5;
  bVar9 = (byte)iVar5;
  *(int *)(unaff_EBP + -0x18) = *(int *)(iVar1 + 0x10) - (8 << (bVar9 & 0x1f)) / 2;
  *(int *)(unaff_EBP + 0xc) = 1 << (bVar9 + 1 & 0x1f);
  iVar5 = __ftol();
  iVar5 = ((4 << ((byte)*(undefined4 *)(iVar1 + 0x20) & 0x1f)) - iVar5) + *(int *)(iVar1 + 0x14);
  *(int *)(unaff_EBP + -0x1c) = iVar5;
  uVar3 = FUN_004b46de();
  *(undefined1 *)(unaff_EBP + -0x28) = uVar3;
  FUN_004b46e2(1);
  if (*(int *)(iVar12 + 0x2c) != 0) {
    puVar6 = (undefined4 *)
             FUN_004c8ec9(unaff_EBP + -0x24,*(int *)(iVar12 + 0x2c),
                          *(undefined4 *)(unaff_EBP + -0x14));
    uVar7 = *(undefined4 *)(iVar12 + 0x2c);
    uVar2 = puVar6[1];
    *(undefined4 *)(unaff_EBP + -0x30) = *puVar6;
    puVar6 = (undefined4 *)
             FUN_004c7387(unaff_EBP + -0x40,uVar7,*(undefined4 *)(unaff_EBP + -0x14),
                          *(undefined4 *)(unaff_EBP + -0x18),iVar5 - (short)uVar2,0,iVar1,1);
    *(undefined4 *)(unaff_EBP + -0x60) = *puVar6;
    *(undefined4 *)(unaff_EBP + -0x5c) = puVar6[1];
    *(undefined4 *)(unaff_EBP + -0x58) = puVar6[2];
    *(undefined4 *)(unaff_EBP + -0x54) = puVar6[3];
    FUN_004b46b5(unaff_EBP + -0x50,unaff_EBP + -0x60);
    iVar12 = *(int *)(unaff_EBP + 0x10);
    iVar5 = *(int *)(unaff_EBP + -0x1c);
  }
  iVar8 = *(int *)(iVar12 + 0x14);
  if (iVar8 == -1) {
    iVar11 = *(int *)(iVar12 + 0x18);
    *(int *)(unaff_EBP + 0xc) = iVar11;
  }
  else {
    *(undefined4 *)(unaff_EBP + 0xc) = 0;
    iVar11 = *(int *)(unaff_EBP + 0xc);
  }
  if (iVar11 == 0) {
    if (iVar8 == -1) {
      *(undefined4 *)(unaff_EBP + 0xc) = 0;
    }
    else {
      *(undefined4 *)(unaff_EBP + 0xc) = *(undefined4 *)(iVar12 + 0x18);
    }
    if ((*(int *)(unaff_EBP + 0xc) != 0) && (sVar10 = (short)iVar8, sVar10 != 0)) {
      *(int *)(unaff_EBP + -0x10) = (int)sVar10;
      iVar8 = FUN_004c8f58((int)sVar10);
      if ((iVar8 != 0) &&
         (sVar10 = (short)*(undefined4 *)(unaff_EBP + -0x14) +
                   (short)*(undefined4 *)(iVar12 + 0x20) * 3, -1 < sVar10)) {
        iVar11 = (int)sVar10;
        *(int *)(unaff_EBP + -0x20) = iVar11;
        if (iVar11 < iVar8) {
          puVar6 = (undefined4 *)
                   FUN_004c8ec9(unaff_EBP + -0x38,*(undefined4 *)(unaff_EBP + -0x10),iVar11);
          uVar7 = puVar6[1];
          *(undefined4 *)(unaff_EBP + -0x30) = *puVar6;
          puVar6 = (undefined4 *)
                   FUN_004c7387(unaff_EBP + -0x40,*(undefined4 *)(unaff_EBP + -0x10),
                                *(undefined4 *)(unaff_EBP + -0x20),
                                *(undefined4 *)(unaff_EBP + -0x18),iVar5 - (short)uVar7,0,iVar1,1);
          *(undefined4 *)(unaff_EBP + -0x60) = *puVar6;
          *(undefined4 *)(unaff_EBP + -0x5c) = puVar6[1];
          *(undefined4 *)(unaff_EBP + -0x58) = puVar6[2];
          *(undefined4 *)(unaff_EBP + -0x54) = puVar6[3];
          FUN_004b46b5(unaff_EBP + -0x50,unaff_EBP + -0x60);
          iVar12 = *(int *)(unaff_EBP + 0x10);
          iVar5 = *(int *)(unaff_EBP + -0x1c);
        }
      }
    }
  }
  else {
    if (*(short *)(*(int *)(iVar11 + 0x60) + 0x12) == 2) {
      FUN_005c1719();
      *(undefined4 *)(unaff_EBP + -4) = 0;
      uVar7 = FUN_0045741b();
      uVar7 = FUN_004e988f(uVar7);
      *(undefined4 *)(unaff_EBP + 0xc) = uVar7;
      uVar7 = FUN_00492d2c(unaff_EBP + 0x10,0);
      cVar4 = FUN_004e9299(*(undefined4 *)(unaff_EBP + 0xc),uVar7);
      if (cVar4 == '\0') {
        FUN_005a5e48(0);
        FUN_004b048c(iVar1);
        uVar7 = FUN_00492d2c(*(int *)(unaff_EBP + -0x10) + 0x124,1);
        FUN_004e9299(*(undefined4 *)(unaff_EBP + 0xc),uVar7);
        FUN_004b0367(0,iVar1);
      }
      else {
        FUN_005a5e1c(unaff_EBP + 0x10);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
LAB_004383ab:
      FUN_005a5e09();
    }
    else {
      iVar8 = *(int *)(iVar11 + 0x84);
      *(int *)(unaff_EBP + 0xc) = iVar8;
      if (iVar8 != 0) {
        FUN_005c1719();
        iVar8 = unaff_EBP + 0x10;
        *(undefined4 *)(unaff_EBP + -4) = 1;
        uVar7 = FUN_00492d2c(iVar8);
        cVar4 = FUN_004cc832(uVar7,iVar8);
        if (cVar4 != '\0') {
          FUN_005a5e1c(unaff_EBP + 0x10);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        goto LAB_004383ab;
      }
    }
    *(int *)(unaff_EBP + 0x10) = *(int *)(unaff_EBP + -0x10) + 0x124;
    cVar4 = FUN_005a5e72();
    if (cVar4 != '\0') {
      *(undefined4 *)(unaff_EBP + -0x24) = 0x20;
      *(undefined4 *)(unaff_EBP + -0x20) = 0xffffffdc;
      iVar8 = FUN_00492d2c();
      if (iVar8 == 2) {
        *(undefined4 *)(unaff_EBP + -0x24) = 0x10;
        *(undefined4 *)(unaff_EBP + -0x20) = 0xffffffee;
      }
      iVar8 = FUN_004096c2();
      *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + *(int *)(iVar8 + 0x1c) / -2;
      iVar8 = FUN_004096c2();
      *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + *(int *)(iVar8 + 0x20) / -2;
      *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + *(int *)(unaff_EBP + -0x18);
      *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + iVar5;
      uVar7 = FUN_004096c2(iVar1,0);
      FUN_0049bafe(*(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x20),uVar7);
    }
  }
  if (*(int *)(iVar12 + 0x30) != 0) {
    puVar6 = (undefined4 *)
             FUN_004c8ec9(unaff_EBP + -0x38,*(int *)(iVar12 + 0x30),
                          *(undefined4 *)(unaff_EBP + -0x14));
    uVar7 = *(undefined4 *)(iVar12 + 0x30);
    uVar2 = puVar6[1];
    *(undefined4 *)(unaff_EBP + -0x30) = *puVar6;
    puVar6 = (undefined4 *)
             FUN_004c7387(unaff_EBP + -0x70,uVar7,*(undefined4 *)(unaff_EBP + -0x14),
                          *(undefined4 *)(unaff_EBP + -0x18),iVar5 - (short)uVar2,0,iVar1,1);
    *(undefined4 *)(unaff_EBP + -0x60) = *puVar6;
    *(undefined4 *)(unaff_EBP + -0x5c) = puVar6[1];
    *(undefined4 *)(unaff_EBP + -0x58) = puVar6[2];
    *(undefined4 *)(unaff_EBP + -0x54) = puVar6[3];
    FUN_004b46b5(unaff_EBP + -0x50,unaff_EBP + -0x60);
  }
  FUN_004b46e2(*(undefined4 *)(unaff_EBP + -0x28));
LAB_00438550:
  puVar6 = *(undefined4 **)(unaff_EBP + 8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *puVar6 = *(undefined4 *)(unaff_EBP + -0x50);
  puVar6[1] = *(undefined4 *)(unaff_EBP + -0x4c);
  puVar6[2] = *(undefined4 *)(unaff_EBP + -0x48);
  puVar6[3] = *(undefined4 *)(unaff_EBP + -0x44);
  return;
}

