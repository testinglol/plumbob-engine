
int * FUN_00596c0d(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
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
    if (((*(byte *)(iVar2 + 8) & 6) != 0) || (iVar2 == 0)) goto LAB_00596dbe;
  } while (*(char *)(unaff_EBP + -0x124) == '\0');
  FUN_0064a3f6(unaff_EBP + -0x124);
  FUN_005b870f(unaff_EBP + -0x124);
  iVar2 = *(int *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d499c(unaff_EBP + -0x24);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  do {
    FUN_00594033(unaff_EBP + -0x124,0x100,10);
    if (piVar1 == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(*piVar1 + 4) + (int)piVar1;
    }
    if (((*(byte *)(iVar3 + 8) & 6) != 0) || (iVar3 == 0)) goto LAB_00596dbe;
  } while (*(char *)(unaff_EBP + -0x124) == '\0');
  FUN_005b870f(unaff_EBP + -0x124);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_005d499c(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  iVar3 = unaff_EBP + 8;
  iVar8 = iVar2 + 100;
  iVar7 = iVar2 + 0x5c;
  iVar6 = iVar2 + 0x34;
  iVar5 = iVar2 + 0x30;
  FUN_00633f35(iVar2 + 0x2c);
  FUN_00633f35(iVar5);
  FUN_006326ae(iVar6);
  FUN_006326ae(iVar7);
  FUN_006326ae(iVar8);
  FUN_006326ae(iVar3);
  iVar3 = 0;
  *(undefined4 *)(iVar2 + 0x38) = 0;
  *(undefined4 *)(iVar2 + 0x44) = 0;
  *(undefined4 *)(iVar2 + 0x40) = 0;
  *(undefined4 *)(iVar2 + 0x3c) = 0;
  *(undefined4 *)(iVar2 + 0x54) = 0;
  *(undefined4 *)(iVar2 + 0x50) = 0;
  *(undefined4 *)(iVar2 + 0x4c) = 0;
  *(undefined4 *)(iVar2 + 0x48) = 0;
  if (piVar1 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(*piVar1 + 4) + (int)piVar1;
  }
  if ((((*(byte *)(iVar2 + 8) & 6) == 0) && (iVar2 != 0)) && (0 < *(int *)(unaff_EBP + 8))) {
    do {
      uVar4 = FUN_005977ba();
      FUN_00596483(piVar1,uVar4);
      if (piVar1 == (int *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(*piVar1 + 4) + (int)piVar1;
      }
    } while ((((*(byte *)(iVar2 + 8) & 6) == 0) && (iVar2 != 0)) &&
            (iVar3 = iVar3 + 1, iVar3 < *(int *)(unaff_EBP + 8)));
  }
LAB_00596dbe:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return piVar1;
}

