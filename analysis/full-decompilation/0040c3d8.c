
void FUN_0040c3d8(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  undefined *puVar4;
  
  FUN_00634c24();
  FUN_0046f824(unaff_EBP + -0xa0,0,0x40);
  uVar3 = *(undefined4 *)(extraout_ECX + 8);
  *(undefined ***)(unaff_EBP + -0xac) = &PTR_FUN_0066651c;
  FUN_00472fca(uVar3,2);
  FUN_0046f824(unaff_EBP + -0x3c,0,4);
  *(undefined ***)(unaff_EBP + -0x48) = &PTR_FUN_0066663c;
  FUN_0046f847(*(int *)(unaff_EBP + -0x5f0) + 6,3);
  FUN_0040b75a();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0040b75a();
  *(int *)(unaff_EBP + -0x54) = unaff_EBP + -0x1d8;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(int *)(unaff_EBP + -0x50) = unaff_EBP + -0x304;
  *(undefined4 *)(unaff_EBP + -0x4c) = 0;
  FUN_0040b75a();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0040b75a();
  *(int *)(unaff_EBP + -0x60) = unaff_EBP + -0x430;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *(int *)(unaff_EBP + -0x5c) = unaff_EBP + -0x55c;
  *(undefined4 *)(unaff_EBP + -0x58) = 0;
  FUN_0047274f(&DAT_006c1004);
  FUN_0047274f(&DAT_006c1014);
  iVar2 = FUN_0040cd0e();
  if (iVar2 == 0) {
    puVar4 = &DAT_006c0f98;
LAB_0040c4e8:
    FUN_0047274f(puVar4);
  }
  else if (iVar2 == 1) {
    puVar4 = &DAT_006c0f9c;
    goto LAB_0040c4e8;
  }
  FUN_0047274f(&DAT_006c0f94);
  FUN_0047274f(*(undefined4 *)(unaff_EBP + -0x44));
  FUN_0040c014(unaff_EBP + -0x1d8);
  FUN_0040bfed(&DAT_006c1010);
  FUN_0040d069(unaff_EBP + -0x34);
  iVar2 = FUN_0046f973(unaff_EBP + -0x20);
  if (iVar2 == 0) {
LAB_0040c5a7:
    iVar2 = FUN_0040d069(unaff_EBP + -0x34);
    uVar3 = *(undefined4 *)(iVar2 + 4);
  }
  else {
    FUN_0040bfed(&DAT_006c100c);
    FUN_0040d069(unaff_EBP + -0x34);
    iVar2 = FUN_0046f973(unaff_EBP + -0x20);
    if (iVar2 == 0) goto LAB_0040c5a7;
    FUN_0040bfed(&DAT_006c1008);
    FUN_0040d069(unaff_EBP + -0x34);
    iVar2 = FUN_0046f973(unaff_EBP + -0x20);
    if (iVar2 == 0) goto LAB_0040c5a7;
    FUN_0040bfed(&DAT_006c1010);
    uVar3 = *(undefined4 *)(unaff_EBP + -0x1c);
  }
  FUN_0047274f(uVar3);
  FUN_0047274f(&DAT_006c1000);
  FUN_0047274f(&DAT_006c1014);
  iVar2 = FUN_0040cd0e();
  if (iVar2 == 0) {
    puVar4 = &DAT_006c0f98;
LAB_0040c5f7:
    FUN_0047274f(puVar4);
  }
  else if (iVar2 == 1) {
    puVar4 = &DAT_006c0f9c;
    goto LAB_0040c5f7;
  }
  FUN_0047274f(&DAT_006c0f94);
  FUN_0047274f(*(undefined4 *)(unaff_EBP + -0x44));
  FUN_0040c014(unaff_EBP + -0x304);
  FUN_0040bfed(&DAT_006c1010);
  FUN_0040d069(unaff_EBP + -0x34);
  iVar2 = FUN_0046f973(unaff_EBP + -0x20);
  if (iVar2 != 0) {
    FUN_0040bfed(&DAT_006c100c);
    FUN_0040d069(unaff_EBP + -0x34);
    iVar2 = FUN_0046f973(unaff_EBP + -0x20);
    if (iVar2 != 0) {
      FUN_0040f49d();
      *(undefined ***)(unaff_EBP + -0x20) = &PTR_FUN_00666634;
      FUN_0046f8cb(&DAT_006c1008);
      FUN_0040d069(unaff_EBP + -0x34);
      iVar2 = FUN_0046f973(unaff_EBP + -0x20);
      if (iVar2 != 0) {
        FUN_0040f49d();
        *(undefined ***)(unaff_EBP + -0x20) = &PTR_FUN_00666634;
        FUN_0046f8cb(&DAT_006c1010);
        uVar3 = *(undefined4 *)(unaff_EBP + -0x1c);
        goto LAB_0040c6da;
      }
    }
  }
  iVar2 = FUN_0040d069(unaff_EBP + -0x34);
  uVar3 = *(undefined4 *)(iVar2 + 4);
LAB_0040c6da:
  FUN_0047274f(uVar3);
  iVar2 = FUN_00409291();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(int *)(unaff_EBP + -0x24) = iVar2;
  if (0 < iVar2) {
    do {
      uVar3 = FUN_004092b7(*(undefined4 *)(unaff_EBP + -0x10));
      if (unaff_EBP != 0x1d8) {
        iVar2 = unaff_EBP + -0x54;
        do {
          FUN_00472b1d(uVar3);
          piVar1 = (int *)(iVar2 + 4);
          iVar2 = iVar2 + 4;
        } while (*piVar1 != 0);
      }
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -0x24));
  }
  FUN_004089ca();
  iVar2 = (DAT_006e4864 - DAT_006e4860) / 0x4c;
  if (0 < iVar2) {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    *(int *)(unaff_EBP + -0x24) = iVar2;
    do {
      FUN_004089ca();
      *(int *)(unaff_EBP + -0x38) = *(int *)(unaff_EBP + -0x10) + DAT_006e4860;
      if (unaff_EBP != 0x430) {
        iVar2 = unaff_EBP + -0x60;
        do {
          FUN_00472b1d(*(undefined4 *)(unaff_EBP + -0x38));
          piVar1 = (int *)(iVar2 + 4);
          iVar2 = iVar2 + 4;
        } while (*piVar1 != 0);
      }
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 0x4c;
      piVar1 = (int *)(unaff_EBP + -0x24);
      *piVar1 = *piVar1 + -1;
    } while (*piVar1 != 0);
  }
  *(undefined2 *)(unaff_EBP + -0xa4) = 0;
  **(undefined1 **)(unaff_EBP + -0xa8) = 0;
  FUN_0046f917(unaff_EBP + -0x1b8,0xffffffff);
  FUN_0046f847(&DAT_006c0fdc,0xffffffff);
  FUN_0046f917(&DAT_006f6b88,0xffffffff);
  FUN_0046f917(unaff_EBP + -0x410,0xffffffff);
  FUN_005876ac(0x20,*(undefined4 *)(unaff_EBP + -0xa8));
  *(undefined2 *)(unaff_EBP + -0xa4) = 0;
  **(undefined1 **)(unaff_EBP + -0xa8) = 0;
  FUN_0046f917(unaff_EBP + -0x2e4,0xffffffff);
  FUN_0046f847(&DAT_006c0fdc,0xffffffff);
  FUN_0046f917(&DAT_006f6b88,0xffffffff);
  FUN_0046f917(unaff_EBP + -0x53c,0xffffffff);
  FUN_005876ac(0x21,*(undefined4 *)(unaff_EBP + -0xa8));
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00409919();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00409919();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00409919();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00409919();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

