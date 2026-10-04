
int * FUN_0059a636(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  do {
    FUN_00594033(unaff_EBP + -0x43c,0x400,10);
    if (piVar1 == (int *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(*piVar1 + 4) + (int)piVar1;
    }
    if (((*(byte *)(iVar2 + 8) & 6) != 0) || (iVar2 == 0)) goto LAB_0059a92e;
  } while (*(char *)(unaff_EBP + -0x43c) == '\0');
  uVar3 = FUN_005b870f(unaff_EBP + -0x43c);
  iVar2 = *(int *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d499c(uVar3);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  do {
    FUN_00594033(unaff_EBP + -0x43c,0x400,10);
    if (piVar1 == (int *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(*piVar1 + 4) + (int)piVar1;
    }
    if (((*(byte *)(iVar4 + 8) & 6) != 0) || (iVar4 == 0)) goto LAB_0059a92e;
  } while (*(char *)(unaff_EBP + -0x43c) == '\0');
  uVar3 = FUN_005b870f(unaff_EBP + -0x43c);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_005d499c(uVar3);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  FUN_00599e03();
  FUN_006326ae(unaff_EBP + 8);
  FUN_0059af08(*(undefined4 *)(unaff_EBP + 8));
  iVar4 = 0;
  if (0 < *(int *)(unaff_EBP + 8)) {
    do {
      do {
        FUN_00594033(unaff_EBP + -0x43c,0x400,10);
        if (piVar1 == (int *)0x0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(*piVar1 + 4) + (int)piVar1;
        }
        if (((*(byte *)(iVar5 + 8) & 6) != 0) || (iVar5 == 0)) goto LAB_0059a92e;
      } while (*(char *)(unaff_EBP + -0x43c) == '\0');
      uVar3 = FUN_005b870f(unaff_EBP + -0x43c);
      *(undefined4 *)(unaff_EBP + -4) = 2;
      FUN_00599e11(uVar3);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(unaff_EBP + 8));
  }
  FUN_006326ae(unaff_EBP + 8);
  FUN_0059b2e8(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + 0xc) = 0;
  if (0 < *(int *)(unaff_EBP + 8)) {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    do {
      FUN_005997cd(piVar1,*(int *)(iVar2 + 0x34) + *(int *)(unaff_EBP + -0x10));
      *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 0xc;
    } while (*(int *)(unaff_EBP + 0xc) < *(int *)(unaff_EBP + 8));
  }
  FUN_006326ae(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x10) = 0xffffffff;
  FUN_0059b324(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x24);
  *(undefined4 *)(unaff_EBP + 0xc) = 0;
  if (0 < *(int *)(unaff_EBP + 8)) {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    do {
      FUN_00599871(piVar1,*(int *)(unaff_EBP + -0x10) + *(int *)(iVar2 + 0x40));
      *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 0x18;
    } while (*(int *)(unaff_EBP + 0xc) < *(int *)(unaff_EBP + 8));
  }
  FUN_006326ae(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  FUN_0059b37f(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x14);
  iVar4 = 0;
  if (0 < *(int *)(unaff_EBP + 8)) {
    do {
      iVar5 = *(int *)(iVar2 + 0x4c) + iVar4 * 8;
      *(int *)(unaff_EBP + 0xc) = iVar5;
      FUN_00633f35(iVar5);
      FUN_00633f35(*(int *)(unaff_EBP + 0xc) + 4);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(unaff_EBP + 8));
  }
  FUN_006326ae(unaff_EBP + 8);
  FUN_0059b3ce(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x14);
  iVar4 = 0;
  if (0 < *(int *)(unaff_EBP + 8)) {
    do {
      iVar5 = *(int *)(iVar2 + 0x58) + iVar4 * 8;
      *(int *)(unaff_EBP + 0xc) = iVar5;
      FUN_006326ae(iVar5 + 4);
      FUN_006326ae(*(undefined4 *)(unaff_EBP + 0xc));
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(unaff_EBP + 8));
  }
  FUN_006326ae(unaff_EBP + 8);
  FUN_0059b402(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x3c);
  *(undefined4 *)(unaff_EBP + 0xc) = 0;
  if (0 < *(int *)(unaff_EBP + 8)) {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    do {
      FUN_00599671(piVar1,*(int *)(unaff_EBP + -0x10) + *(int *)(iVar2 + 100));
      *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 0x18;
    } while (*(int *)(unaff_EBP + 0xc) < *(int *)(unaff_EBP + 8));
  }
  FUN_004d5f89(*(undefined4 *)(iVar2 + 0x1c),*(undefined4 *)(iVar2 + 0x20));
  FUN_0059a46a();
LAB_0059a92e:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return piVar1;
}

