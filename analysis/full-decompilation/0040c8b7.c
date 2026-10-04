
void FUN_0040c8b7(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  undefined *puVar4;
  
  FUN_00634c24();
  FUN_0046f824(unaff_EBP + -0x94,0,0x40);
  uVar3 = *(undefined4 *)(extraout_ECX + 8);
  *(undefined ***)(unaff_EBP + -0xa0) = &PTR_FUN_0066651c;
  FUN_00472fca(uVar3,2);
  FUN_0046f824(unaff_EBP + -0x30,0,4);
  *(undefined ***)(unaff_EBP + -0x3c) = &PTR_FUN_0066663c;
  FUN_0046f847(*(int *)(unaff_EBP + -0x38c) + 6,3);
  FUN_0040b75a();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(int *)(unaff_EBP + -0x2c) = unaff_EBP + -0x1cc;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  FUN_0040b75a();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(int *)(unaff_EBP + -0x44) = unaff_EBP + -0x2f8;
  *(undefined4 *)(unaff_EBP + -0x40) = 0;
  FUN_0047274f(&DAT_006c0a78);
  FUN_0047274f(&DAT_006c1014);
  iVar2 = FUN_0040cd0e();
  if (iVar2 == 0) {
    puVar4 = &DAT_006c0f98;
LAB_0040c996:
    FUN_0047274f(puVar4);
  }
  else if (iVar2 == 1) {
    puVar4 = &DAT_006c0f9c;
    goto LAB_0040c996;
  }
  iVar2 = FUN_0040cc3f();
  if (iVar2 == 0) {
    FUN_0047274f(&DAT_006c0a74);
    iVar2 = _strcmp(*(char **)(unaff_EBP + -0x38),(char *)&PTR_DAT_006c0fd0);
    if (iVar2 != 0) {
      iVar2 = _strcmp(*(char **)(unaff_EBP + -0x38),&DAT_006c0fcc);
      if (iVar2 != 0) {
        iVar2 = _strcmp(*(char **)(unaff_EBP + -0x38),&DAT_006c0fc8);
        if (iVar2 != 0) {
          puVar4 = &DAT_006c0fcc;
          goto LAB_0040ca06;
        }
      }
    }
    puVar4 = *(undefined **)(unaff_EBP + -0x38);
LAB_0040ca06:
    FUN_0047274f(puVar4);
  }
  else if (iVar2 == 1) {
    puVar4 = &DAT_006c1020;
    goto LAB_0040ca06;
  }
  FUN_0040c014(unaff_EBP + -0x1cc);
  FUN_0040f49d();
  *(undefined ***)(unaff_EBP + -0x24) = &PTR_FUN_00666634;
  FUN_0046f8cb(&DAT_006c1010);
  FUN_0040d069(unaff_EBP + -0x54);
  iVar2 = FUN_0046f973(unaff_EBP + -0x24);
  if (iVar2 != 0) {
    FUN_0040f49d();
    *(undefined ***)(unaff_EBP + -0x24) = &PTR_FUN_00666634;
    FUN_0046f8cb(&DAT_006c100c);
    FUN_0040d069(unaff_EBP + -0x54);
    iVar2 = FUN_0046f973(unaff_EBP + -0x24);
    if (iVar2 != 0) {
      FUN_0040f49d();
      *(undefined ***)(unaff_EBP + -0x24) = &PTR_FUN_00666634;
      FUN_0046f8cb(&DAT_006c1008);
      FUN_0040d069(unaff_EBP + -0x54);
      iVar2 = FUN_0046f973(unaff_EBP + -0x24);
      if (iVar2 != 0) {
        FUN_0040f49d();
        *(undefined ***)(unaff_EBP + -0x24) = &PTR_FUN_00666634;
        FUN_0046f8cb(&DAT_006c1010);
        uVar3 = *(undefined4 *)(unaff_EBP + -0x20);
        goto LAB_0040cae6;
      }
    }
  }
  iVar2 = FUN_0040d069(unaff_EBP + -0x54);
  uVar3 = *(undefined4 *)(iVar2 + 4);
LAB_0040cae6:
  FUN_0047274f(uVar3);
  iVar2 = FUN_00409291();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(int *)(unaff_EBP + -0x14) = iVar2;
  if (0 < iVar2) {
    do {
      uVar3 = FUN_004092b7(*(undefined4 *)(unaff_EBP + -0x10));
      if (unaff_EBP != 0x1cc) {
        iVar2 = unaff_EBP + -0x2c;
        do {
          FUN_00472b1d(uVar3);
          piVar1 = (int *)(iVar2 + 4);
          iVar2 = iVar2 + 4;
        } while (*piVar1 != 0);
      }
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    } while (*(int *)(unaff_EBP + -0x10) < *(int *)(unaff_EBP + -0x14));
  }
  FUN_004089ca();
  iVar2 = (DAT_006e4864 - DAT_006e4860) / 0x4c;
  if (0 < iVar2) {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    *(int *)(unaff_EBP + -0x14) = iVar2;
    do {
      FUN_004089ca();
      *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x10) + DAT_006e4860;
      if (unaff_EBP != 0x2f8) {
        iVar2 = unaff_EBP + -0x44;
        do {
          FUN_00472b1d(*(undefined4 *)(unaff_EBP + -0x28));
          piVar1 = (int *)(iVar2 + 4);
          iVar2 = iVar2 + 4;
        } while (*piVar1 != 0);
      }
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 0x4c;
      piVar1 = (int *)(unaff_EBP + -0x14);
      *piVar1 = *piVar1 + -1;
    } while (*piVar1 != 0);
  }
  *(undefined2 *)(unaff_EBP + -0x98) = 0;
  **(undefined1 **)(unaff_EBP + -0x9c) = 0;
  FUN_0046f917(unaff_EBP + -0x1ac,0xffffffff);
  FUN_0046f847(&DAT_006c0fdc,0xffffffff);
  FUN_0046f917(&DAT_006f6b88,0xffffffff);
  FUN_0046f917(unaff_EBP + -0x2d8,0xffffffff);
  FUN_005876ac(0x22,*(undefined4 *)(unaff_EBP + -0x9c));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00409919();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00409919();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

