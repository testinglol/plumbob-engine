
void FUN_0059498e(void)

{
  int *piVar1;
  int iVar2;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x14) = extraout_ECX;
  do {
    FUN_00594033(unaff_EBP + -0x420,0x400,10);
    if (piVar1 == (int *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(*piVar1 + 4) + (int)piVar1;
    }
    if (((*(byte *)(iVar2 + 8) & 6) != 0) || (iVar2 == 0)) goto LAB_00594a8b;
  } while (*(char *)(unaff_EBP + -0x420) == '\0');
  do {
    FUN_00594033(unaff_EBP + -0x420,0x400,10);
    if (piVar1 == (int *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(*piVar1 + 4) + (int)piVar1;
    }
    if (((*(byte *)(iVar2 + 8) & 6) != 0) || (iVar2 == 0)) goto LAB_00594a8b;
  } while (*(char *)(unaff_EBP + -0x420) == '\0');
  FUN_005b870f(unaff_EBP + -0x420);
  iVar2 = *(int *)(unaff_EBP + -0x14);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d499c(unaff_EBP + -0x20);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  FUN_006326ae(unaff_EBP + 8);
  *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(unaff_EBP + 8);
  FUN_006326ae(unaff_EBP + -0x10);
  if (piVar1 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(*piVar1 + 4) + (int)piVar1;
  }
  if ((((*(byte *)(iVar2 + 8) & 6) == 0) && (iVar2 != 0)) && (*(int *)(unaff_EBP + -0x10) != 0)) {
    FUN_00594082(piVar1);
  }
LAB_00594a8b:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

