
void FUN_00596dcf(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  int iVar4;
  int iVar5;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  do {
    FUN_00594033(unaff_EBP + -0x124,0x100,10);
    if (piVar1 == (int *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(*piVar1 + 4) + (int)piVar1;
    }
    if (((*(byte *)(iVar2 + 8) & 6) != 0) || (iVar2 == 0)) goto LAB_00596f58;
  } while (*(char *)(unaff_EBP + -0x124) == '\0');
  FUN_0064a3f6(unaff_EBP + -0x124);
  FUN_005b870f(unaff_EBP + -0x124);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d499c(unaff_EBP + -0x24);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  do {
    FUN_00594033(unaff_EBP + -0x124,0x100,10);
    if (piVar1 == (int *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(*piVar1 + 4) + (int)piVar1;
    }
    if (((*(byte *)(iVar2 + 8) & 6) != 0) || (iVar2 == 0)) goto LAB_00596f58;
  } while (*(char *)(unaff_EBP + -0x124) == '\0');
  FUN_005b870f(unaff_EBP + -0x124);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_005d499c(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  iVar2 = extraout_ECX + 100;
  iVar3 = extraout_ECX + 0x5c;
  iVar5 = extraout_ECX + 0x34;
  iVar4 = extraout_ECX + 0x30;
  FUN_00633f35(extraout_ECX + 0x2c);
  FUN_00633f35(iVar4);
  FUN_006326ae(iVar5);
  FUN_006326ae(iVar3);
  FUN_006326ae(iVar2);
  FUN_006326ae(unaff_EBP + 8);
  if (piVar1 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(*piVar1 + 4) + (int)piVar1;
  }
  if ((((*(byte *)(iVar2 + 8) & 6) == 0) && (iVar2 != 0)) &&
     (iVar2 = 0, 0 < *(int *)(unaff_EBP + 8))) {
    do {
      FUN_005966c6(piVar1,*(undefined4 *)(unaff_EBP + 0x10),*(undefined4 *)(unaff_EBP + 0x14));
      if (piVar1 == (int *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(*piVar1 + 4) + (int)piVar1;
      }
    } while ((((*(byte *)(iVar3 + 8) & 6) == 0) && (iVar3 != 0)) &&
            (iVar2 = iVar2 + 1, iVar2 < *(int *)(unaff_EBP + 8)));
  }
LAB_00596f58:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

