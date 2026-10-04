
int * FUN_005947f9(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int unaff_EBP;
  int *piVar6;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  do {
    FUN_00594033(unaff_EBP + -0x428,0x400,10);
    if (piVar1 == (int *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(*piVar1 + 4) + (int)piVar1;
    }
    if (((*(byte *)(iVar2 + 8) & 6) != 0) || (iVar2 == 0)) goto LAB_0059497d;
  } while (*(char *)(unaff_EBP + -0x428) == '\0');
  FUN_005b870f(unaff_EBP + -0x428);
  iVar2 = *(int *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d499c(unaff_EBP + -0x1c);
  uVar3 = FUN_00598764(*(undefined4 *)(unaff_EBP + -0x1c));
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(iVar2 + 0xc) = uVar3;
  FUN_005b8770();
  do {
    FUN_00594033(unaff_EBP + -0x428,0x400,10);
    if (piVar1 == (int *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(*piVar1 + 4) + (int)piVar1;
    }
    if (((*(byte *)(iVar4 + 8) & 6) != 0) || (iVar4 == 0)) goto LAB_0059497d;
  } while (*(char *)(unaff_EBP + -0x428) == '\0');
  FUN_005b870f(unaff_EBP + -0x428);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_005d499c(unaff_EBP + -0x28);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  FUN_006326ae(unaff_EBP + 8);
  *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(unaff_EBP + 8);
  FUN_006326ae(unaff_EBP + -0x10);
  if (piVar1 == (int *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(*piVar1 + 4) + (int)piVar1;
  }
  if ((((*(byte *)(iVar4 + 8) & 6) == 0) && (iVar4 != 0)) && (*(int *)(unaff_EBP + -0x10) != 0)) {
    piVar5 = operator_new(0x10);
    piVar6 = (int *)0x0;
    if (piVar5 != (int *)0x0) {
      *piVar5 = 0;
      piVar5[1] = 0;
      piVar5[2] = 0;
      piVar5[3] = 0;
      piVar6 = piVar5;
    }
    FUN_00593f7f(piVar1,piVar6);
    if (piVar1 == (int *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(*piVar1 + 4) + (int)piVar1;
    }
    if (((*(byte *)(iVar4 + 8) & 6) == 0) && (iVar4 != 0)) {
      if (*(int *)(iVar2 + 0x24) != 0) {
        FUN_005942ab();
      }
      if (piVar6 != (int *)0x0) {
        *piVar6 = *piVar6 + 1;
      }
      *(int **)(iVar2 + 0x24) = piVar6;
    }
  }
LAB_0059497d:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return piVar1;
}

