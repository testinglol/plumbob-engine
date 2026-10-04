
void FUN_0043bb37(void)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  void *pvVar6;
  void *pvVar7;
  int iVar8;
  size_t sVar9;
  uint *puVar10;
  int extraout_ECX;
  byte *pbVar11;
  int unaff_EBP;
  uint uVar12;
  
  FUN_00634c24();
  piVar2 = *(int **)(unaff_EBP + 8);
  uVar4 = (**(code **)(*piVar2 + 0x38))(0x4f424a44,*(undefined4 *)(unaff_EBP + 0xc),FUN_0042004f);
  *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
  FUN_00431808(uVar4);
  uVar5 = FUN_00420048(uVar4);
  *(undefined4 *)(unaff_EBP + -0x14) = uVar5;
  FUN_0046f824(unaff_EBP + -0x6c,0,0x40);
  iVar8 = *piVar2;
  *(undefined ***)(unaff_EBP + -0x78) = &PTR_FUN_0066651c;
  (**(code **)(iVar8 + 0x48))(uVar4,unaff_EBP + -0x78);
  if ((*(short *)(*(int *)(unaff_EBP + -0x14) + 0x20) == 0) ||
     (*(char *)(extraout_ECX + 0x1240) == '\0')) {
    pvVar6 = operator_new(0xd8);
    *(void **)(unaff_EBP + -0x18) = pvVar6;
    FUN_005a92b0(pvVar6,*(undefined4 *)(unaff_EBP + -0x14),0xd8);
    FUN_00465a06(*(undefined4 *)(unaff_EBP + -0x10));
    pvVar7 = operator_new(0xbc);
    *(void **)(unaff_EBP + -0x10) = pvVar7;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar7 == (void *)0x0) {
      iVar8 = 0;
    }
    else {
      iVar8 = FUN_00457169();
    }
    *(int *)(unaff_EBP + 8) = iVar8;
    *(void **)(iVar8 + 0x60) = pvVar6;
    iVar8 = *(int *)(extraout_ECX + 0x24);
    iVar3 = *(int *)(extraout_ECX + 0x20);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(*(int *)(unaff_EBP + 8) + 0xa8) = iVar8 - iVar3 >> 2;
    *(int *)(*(int *)(unaff_EBP + 8) + 0x80) = extraout_ECX;
    **(undefined4 **)(unaff_EBP + 8) = piVar2;
    uVar4 = FUN_004c7075(piVar2);
    *(undefined4 *)(*(int *)(unaff_EBP + 8) + 8) = uVar4;
    iVar8 = (**(code **)(*piVar2 + 0x40))(0x474c4f42,1,0);
    *(int *)(unaff_EBP + -0x14) = iVar8;
    if (iVar8 != 0) {
      FUN_0046f824(unaff_EBP + -0x17c,0,0x104);
      *(undefined ***)(unaff_EBP + -0x188) = &PTR_FUN_006664e8;
      uVar4 = FUN_00420048(*(undefined4 *)(unaff_EBP + -0x14));
      *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
      iVar8 = FUN_00420096(*(undefined4 *)(unaff_EBP + -0x14));
      pbVar11 = *(byte **)(unaff_EBP + -0x10);
      if ((iVar8 < 1) || (pbVar11[iVar8 + -1] != 0)) {
        uVar12 = (uint)*pbVar11;
        pbVar11 = pbVar11 + 1;
      }
      else {
        uVar12 = 0xffffffff;
      }
      FUN_0046f847(pbVar11,uVar12);
      FUN_0042004f(*(undefined4 *)(unaff_EBP + -0x14));
      FUN_005b870f(*(undefined4 *)(extraout_ECX + 0x34));
      *(undefined4 *)(unaff_EBP + -4) = 1;
      *(char **)(unaff_EBP + -0x10) = *(char **)(unaff_EBP + -0x184);
      sVar9 = _strlen(*(char **)(unaff_EBP + -0x184));
      FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x10),sVar9 + *(int *)(unaff_EBP + -0x10));
      FUN_005b88c2();
      uVar4 = FUN_004096c2();
      *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
      FUN_0046f824(unaff_EBP + -0x28c,0,0x104);
      *(undefined ***)(unaff_EBP + -0x298) = &PTR_FUN_006664e8;
      FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x10),0xffffffff);
      uVar4 = FUN_0043e530(unaff_EBP + -0x298,*(undefined1 *)(extraout_ECX + 0x1242));
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(*(int *)(unaff_EBP + 8) + 4) = uVar4;
      FUN_005b8770();
      pvVar6 = *(void **)(unaff_EBP + -0x18);
    }
    pvVar7 = operator_new(8);
    *(void **)(unaff_EBP + -0x18) = pvVar7;
    *(undefined4 *)(unaff_EBP + -4) = 2;
    if (pvVar7 == (void *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_0047da31(*(undefined4 *)(unaff_EBP + 8));
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x10) = uVar4;
    pvVar7 = operator_new(0x18);
    *(void **)(unaff_EBP + -0x18) = pvVar7;
    *(undefined4 *)(unaff_EBP + -4) = 3;
    if (pvVar7 == (void *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_00401e31(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x10),
                           *(undefined4 *)(extraout_ECX + 0x2c),piVar2,
                           *(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0xc) = uVar4;
    iVar8 = *(int *)(unaff_EBP + 8);
    sVar1 = *(short *)(unaff_EBP + 0xc);
    *(undefined2 *)(iVar8 + 0xb6) = 0;
    puVar10 = (uint *)(iVar8 + 0xb4);
    *puVar10 = *puVar10 | (int)sVar1 << 0x10;
    iVar8 = *(int *)(unaff_EBP + 8);
    uVar12 = *(uint *)(unaff_EBP + 0x10);
    puVar10 = (uint *)(iVar8 + 0xb4);
    *puVar10 = *puVar10 & 0xfffffff3;
    puVar10 = (uint *)(iVar8 + 0xb4);
    *puVar10 = *puVar10 | (uVar12 & 3) << 2;
    FUN_0046f8e4(unaff_EBP + -0x78);
    *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x84) = 0;
    *(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x88) = 0;
    sVar1 = *(short *)((int)pvVar6 + 0xb4);
    if (sVar1 != 0) {
      pvVar7 = operator_new(0xc);
      *(void **)(unaff_EBP + 0x10) = pvVar7;
      *(undefined4 *)(unaff_EBP + -4) = 4;
      if (pvVar7 == (void *)0x0) {
        uVar4 = 0;
      }
      else {
        uVar4 = FUN_00456100(*(undefined4 *)((int)pvVar6 + 0x1c),(int)sVar1);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + 0xc) = uVar4;
      FUN_0043e3bb(unaff_EBP + 0xc);
    }
    FUN_0043e36d(unaff_EBP + 8);
    uVar4 = FUN_0045741b();
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    *(undefined4 *)(unaff_EBP + -0x2c) = uVar4;
    iVar8 = FUN_0043ed84(unaff_EBP + -0x2c);
    *(undefined4 *)(iVar8 + 4) = *(undefined4 *)(unaff_EBP + 8);
  }
  else {
    FUN_00465a06(uVar4);
    FUN_0043e5bf(piVar2);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

