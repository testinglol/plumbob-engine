
void FUN_0040b84f(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  undefined *puVar4;
  
  FUN_00634c24();
  FUN_0046f824(unaff_EBP + -0x88,0,0x40);
  uVar3 = *(undefined4 *)(extraout_ECX + 8);
  *(undefined ***)(unaff_EBP + -0x94) = &PTR_FUN_0066651c;
  FUN_00472fca(uVar3,2);
  FUN_0046f824(unaff_EBP + -0x28,0,4);
  *(undefined ***)(unaff_EBP + -0x34) = &PTR_FUN_0066663c;
  FUN_0046f847(*(int *)(unaff_EBP + -0x850) + 6,3);
  FUN_0040b75a();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0040b75a();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0040b75a();
  *(int *)(unaff_EBP + -0xa4) = unaff_EBP + -0x1e0;
  *(int *)(unaff_EBP + -0xa0) = unaff_EBP + -0x30c;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *(int *)(unaff_EBP + -0x9c) = unaff_EBP + -0x438;
  *(undefined4 *)(unaff_EBP + -0x98) = 0;
  FUN_0040b75a();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_0040b75a();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_0040b75a();
  *(int *)(unaff_EBP + -0xb4) = unaff_EBP + -0x564;
  *(int *)(unaff_EBP + -0xb0) = unaff_EBP + -0x7bc;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  *(int *)(unaff_EBP + -0xac) = unaff_EBP + -0x690;
  *(undefined4 *)(unaff_EBP + -0xa8) = 0;
  FUN_0047274f(&DAT_006c0f9c);
  FUN_0047274f(&DAT_006c1014);
  iVar2 = FUN_0040cd0e();
  if (iVar2 == 0) {
    puVar4 = &DAT_006c0f98;
LAB_0040b9a7:
    FUN_0047274f(puVar4);
  }
  else if (iVar2 == 1) {
    puVar4 = &DAT_006c0f9c;
    goto LAB_0040b9a7;
  }
  FUN_0047274f(&DAT_006c0a74);
  iVar2 = _strcmp(*(char **)(unaff_EBP + -0x30),(char *)&PTR_DAT_006c0fd0);
  if (iVar2 == 0) {
LAB_0040b9ff:
    puVar4 = *(undefined **)(unaff_EBP + -0x30);
  }
  else {
    iVar2 = _strcmp(*(char **)(unaff_EBP + -0x30),&DAT_006c0fcc);
    if (iVar2 == 0) goto LAB_0040b9ff;
    iVar2 = _strcmp(*(char **)(unaff_EBP + -0x30),&DAT_006c0fc8);
    if (iVar2 == 0) goto LAB_0040b9ff;
    puVar4 = &DAT_006c0fcc;
  }
  FUN_0047274f(puVar4);
  FUN_0040c014(unaff_EBP + -0x1e0);
  FUN_0040bfed(&DAT_006c1010);
  FUN_0040d069(unaff_EBP + -0x44);
  iVar2 = FUN_0046f973(unaff_EBP + -0x20);
  if (iVar2 == 0) {
LAB_0040baa3:
    iVar2 = FUN_0040d069(unaff_EBP + -0x44);
    uVar3 = *(undefined4 *)(iVar2 + 4);
  }
  else {
    FUN_0040bfed(&DAT_006c100c);
    FUN_0040d069(unaff_EBP + -0x44);
    iVar2 = FUN_0046f973(unaff_EBP + -0x20);
    if (iVar2 == 0) goto LAB_0040baa3;
    FUN_0040bfed(&DAT_006c1008);
    FUN_0040d069(unaff_EBP + -0x44);
    iVar2 = FUN_0046f973(unaff_EBP + -0x20);
    if (iVar2 == 0) goto LAB_0040baa3;
    FUN_0040bfed(&DAT_006c1010);
    uVar3 = *(undefined4 *)(unaff_EBP + -0x1c);
  }
  FUN_0047274f(uVar3);
  FUN_0047274f(&DAT_006c1004);
  FUN_0047274f(&DAT_006c1014);
  iVar2 = FUN_0040cd0e();
  if (iVar2 == 0) {
    puVar4 = &DAT_006c0f98;
LAB_0040baf3:
    FUN_0047274f(puVar4);
  }
  else if (iVar2 == 1) {
    puVar4 = &DAT_006c0f9c;
    goto LAB_0040baf3;
  }
  FUN_0047274f(&DAT_006c0a74);
  iVar2 = _strcmp(*(char **)(unaff_EBP + -0x30),(char *)&PTR_DAT_006c0fd0);
  if (iVar2 == 0) {
LAB_0040bb4e:
    puVar4 = *(undefined **)(unaff_EBP + -0x30);
  }
  else {
    iVar2 = _strcmp(*(char **)(unaff_EBP + -0x30),&DAT_006c0fcc);
    if (iVar2 == 0) goto LAB_0040bb4e;
    iVar2 = _strcmp(*(char **)(unaff_EBP + -0x30),&DAT_006c0fc8);
    if (iVar2 == 0) goto LAB_0040bb4e;
    puVar4 = &DAT_006c0fcc;
  }
  FUN_0047274f(puVar4);
  FUN_0040c014(unaff_EBP + -0x30c);
  FUN_0040bfed(&DAT_006c1010);
  FUN_0040d069(unaff_EBP + -0x44);
  iVar2 = FUN_0046f973(unaff_EBP + -0x20);
  if (iVar2 == 0) {
LAB_0040bc01:
    iVar2 = FUN_0040d069(unaff_EBP + -0x44);
    uVar3 = *(undefined4 *)(iVar2 + 4);
  }
  else {
    FUN_0040bfed(&DAT_006c100c);
    FUN_0040d069(unaff_EBP + -0x44);
    iVar2 = FUN_0046f973(unaff_EBP + -0x20);
    if (iVar2 == 0) goto LAB_0040bc01;
    FUN_0040bfed(&DAT_006c1008);
    FUN_0040d069(unaff_EBP + -0x44);
    iVar2 = FUN_0046f973(unaff_EBP + -0x20);
    if (iVar2 == 0) goto LAB_0040bc01;
    FUN_0040f49d();
    *(undefined ***)(unaff_EBP + -0x20) = &PTR_FUN_00666634;
    FUN_0046f8cb(&DAT_006c1010);
    uVar3 = *(undefined4 *)(unaff_EBP + -0x1c);
  }
  FUN_0047274f(uVar3);
  FUN_0047274f(&DAT_006c1000);
  FUN_0047274f(&DAT_006c1014);
  iVar2 = FUN_0040cd0e();
  if (iVar2 == 0) {
    puVar4 = &DAT_006c0f98;
LAB_0040bc51:
    FUN_0047274f(puVar4);
  }
  else if (iVar2 == 1) {
    puVar4 = &DAT_006c0f9c;
    goto LAB_0040bc51;
  }
  FUN_0047274f(&DAT_006c0a74);
  iVar2 = _strcmp(*(char **)(unaff_EBP + -0x30),(char *)&PTR_DAT_006c0fd0);
  if (iVar2 == 0) {
LAB_0040bca9:
    puVar4 = *(undefined **)(unaff_EBP + -0x30);
  }
  else {
    iVar2 = _strcmp(*(char **)(unaff_EBP + -0x30),&DAT_006c0fcc);
    if (iVar2 == 0) goto LAB_0040bca9;
    iVar2 = _strcmp(*(char **)(unaff_EBP + -0x30),&DAT_006c0fc8);
    if (iVar2 == 0) goto LAB_0040bca9;
    puVar4 = &DAT_006c0fcc;
  }
  FUN_0047274f(puVar4);
  FUN_0040c014(unaff_EBP + -0x438);
  FUN_0040f49d();
  *(undefined ***)(unaff_EBP + -0x20) = &PTR_FUN_00666634;
  FUN_0046f8cb(&DAT_006c1010);
  FUN_0040d069(unaff_EBP + -0x44);
  iVar2 = FUN_0046f973(unaff_EBP + -0x20);
  if (iVar2 != 0) {
    FUN_0040f49d();
    *(undefined ***)(unaff_EBP + -0x20) = &PTR_FUN_00666634;
    FUN_0046f8cb(&DAT_006c100c);
    FUN_0040d069(unaff_EBP + -0x44);
    iVar2 = FUN_0046f973(unaff_EBP + -0x20);
    if (iVar2 != 0) {
      FUN_0040f49d();
      *(undefined ***)(unaff_EBP + -0x20) = &PTR_FUN_00666634;
      FUN_0046f8cb(&DAT_006c1008);
      FUN_0040d069(unaff_EBP + -0x44);
      iVar2 = FUN_0046f973(unaff_EBP + -0x20);
      if (iVar2 != 0) {
        FUN_0040f49d();
        *(undefined ***)(unaff_EBP + -0x20) = &PTR_FUN_00666634;
        FUN_0046f8cb(&DAT_006c1010);
        uVar3 = *(undefined4 *)(unaff_EBP + -0x1c);
        goto LAB_0040bd87;
      }
    }
  }
  iVar2 = FUN_0040d069(unaff_EBP + -0x44);
  uVar3 = *(undefined4 *)(iVar2 + 4);
LAB_0040bd87:
  FUN_0047274f(uVar3);
  iVar2 = FUN_00409291();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(int *)(unaff_EBP + -0x24) = iVar2;
  if (0 < iVar2) {
    do {
      uVar3 = FUN_004092b7(*(undefined4 *)(unaff_EBP + -0x10));
      if (unaff_EBP != 0x1e0) {
        iVar2 = unaff_EBP + -0xa4;
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
      *(int *)(unaff_EBP + -0x48) = *(int *)(unaff_EBP + -0x10) + DAT_006e4860;
      if (unaff_EBP != 0x564) {
        iVar2 = unaff_EBP + -0xb4;
        do {
          FUN_00472b1d(*(undefined4 *)(unaff_EBP + -0x48));
          piVar1 = (int *)(iVar2 + 4);
          iVar2 = iVar2 + 4;
        } while (*piVar1 != 0);
      }
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 0x4c;
      piVar1 = (int *)(unaff_EBP + -0x24);
      *piVar1 = *piVar1 + -1;
    } while (*piVar1 != 0);
  }
  *(undefined2 *)(unaff_EBP + -0x8c) = 0;
  **(undefined1 **)(unaff_EBP + -0x90) = 0;
  FUN_0046f917(unaff_EBP + -0x1c0,0xffffffff);
  FUN_0046f847(&DAT_006c0fdc,0xffffffff);
  FUN_0046f917(&DAT_006f6b88,0xffffffff);
  FUN_0046f917(unaff_EBP + -0x544,0xffffffff);
  FUN_005876ac(0x1f,*(undefined4 *)(unaff_EBP + -0x90));
  *(undefined2 *)(unaff_EBP + -0x8c) = 0;
  **(undefined1 **)(unaff_EBP + -0x90) = 0;
  FUN_0046f917(unaff_EBP + -0x2ec,0xffffffff);
  FUN_0046f847(&DAT_006c0fdc,0xffffffff);
  FUN_0046f917(&DAT_006f6b88,0xffffffff);
  FUN_0046f917(unaff_EBP + -0x79c,0xffffffff);
  FUN_005876ac(0x20,*(undefined4 *)(unaff_EBP + -0x90));
  *(undefined2 *)(unaff_EBP + -0x8c) = 0;
  **(undefined1 **)(unaff_EBP + -0x90) = 0;
  FUN_0046f917(unaff_EBP + -0x418,0xffffffff);
  FUN_0046f847(&DAT_006c0fdc,0xffffffff);
  FUN_0046f917(&DAT_006f6b88,0xffffffff);
  FUN_0046f917(unaff_EBP + -0x670,0xffffffff);
  FUN_005876ac(0x21,*(undefined4 *)(unaff_EBP + -0x90));
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_00409919();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_00409919();
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

