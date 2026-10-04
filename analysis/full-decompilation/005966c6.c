
void FUN_005966c6(void)

{
  int *piVar1;
  int iVar2;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  FUN_00634c24();
  FUN_005c4830();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  piVar1 = *(int **)(unaff_EBP + 8);
  do {
    FUN_00594033(unaff_EBP + -0x13c,0x100,10);
    if (piVar1 == (int *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(*piVar1 + 4) + (int)piVar1;
    }
    if (((*(byte *)(iVar2 + 8) & 6) != 0) || (iVar2 == 0)) goto LAB_00596819;
  } while (*(char *)(unaff_EBP + -0x13c) == '\0');
  iVar2 = unaff_EBP + -0x3c;
  iVar6 = unaff_EBP + -0x38;
  iVar5 = unaff_EBP + -0x28;
  iVar4 = unaff_EBP + -0x34;
  iVar3 = unaff_EBP + -0x2c;
  FUN_006326ae(unaff_EBP + -0x30);
  FUN_00633f35(iVar3);
  FUN_006326ae(iVar4);
  FUN_006326ae(iVar5);
  FUN_006326ae(iVar6);
  FUN_006326ae(iVar2);
  if (piVar1 == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(*piVar1 + 4) + (int)piVar1;
  }
  if (((*(byte *)(iVar2 + 8) & 6) == 0) && (iVar2 != 0)) {
    FUN_006326ae(unaff_EBP + -0x24);
    if (piVar1 == (int *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(*piVar1 + 4) + (int)piVar1;
    }
    if (((*(byte *)(iVar2 + 8) & 6) == 0) && (iVar2 != 0)) {
      if (*(int *)(unaff_EBP + -0x24) != 0) {
        FUN_00594082(piVar1);
        if (piVar1 == (int *)0x0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(*piVar1 + 4) + (int)piVar1;
        }
        if (((*(byte *)(iVar2 + 8) & 6) != 0) || (iVar2 == 0)) goto LAB_00596819;
      }
      FUN_006326ae(unaff_EBP + -0x10);
      if (piVar1 == (int *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(*piVar1 + 4) + (int)piVar1;
      }
      if ((((*(byte *)(iVar2 + 8) & 6) == 0) && (iVar2 != 0)) && (*(int *)(unaff_EBP + -0x10) != 0))
      {
        FUN_005944c5(piVar1,*(undefined4 *)(unaff_EBP + 0xc));
      }
    }
  }
LAB_00596819:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c4890();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

