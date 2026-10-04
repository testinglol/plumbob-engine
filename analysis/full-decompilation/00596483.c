
int * FUN_00596483(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  FUN_00634c24();
  FUN_005c4830();
  piVar1 = *(int **)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  do {
    FUN_00594033(unaff_EBP + -0x148,0x100,10);
    if (piVar1 == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(*piVar1 + 4) + (int)piVar1;
    }
    if (((*(byte *)(iVar3 + 8) & 6) != 0) || (iVar3 == 0)) goto LAB_005966a9;
  } while (*(char *)(unaff_EBP + -0x148) == '\0');
  FUN_005b870f(unaff_EBP + -0x148);
  iVar2 = *(int *)(unaff_EBP + 0xc);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005d499c(unaff_EBP + -0x48);
  uVar4 = FUN_00598764(*(undefined4 *)(unaff_EBP + -0x48));
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(iVar2 + 0xc) = uVar4;
  FUN_005b8770();
  iVar3 = unaff_EBP + -0x10;
  iVar10 = unaff_EBP + -0x24;
  iVar9 = unaff_EBP + -0x3c;
  iVar8 = unaff_EBP + -0x1c;
  iVar7 = unaff_EBP + -0x28;
  FUN_006326ae(unaff_EBP + -0x14);
  FUN_00633f35(iVar7);
  FUN_006326ae(iVar8);
  FUN_006326ae(iVar9);
  FUN_006326ae(iVar10);
  FUN_006326ae(iVar3);
  if (piVar1 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(*piVar1 + 4) + (int)piVar1;
  }
  if (((*(byte *)(iVar3 + 8) & 6) == 0) && (iVar3 != 0)) {
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(unaff_EBP + -0x14);
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(unaff_EBP + -0x1c);
    uVar4 = *(undefined4 *)(unaff_EBP + -0x28);
    *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(unaff_EBP + -0x3c);
    *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(unaff_EBP + -0x24);
    *(undefined4 *)(iVar2 + 0x28) = *(undefined4 *)(unaff_EBP + -0x10);
    *(undefined4 *)(iVar2 + 0x18) = uVar4;
    FUN_006326ae(unaff_EBP + -0x18);
    if (piVar1 == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(*piVar1 + 4) + (int)piVar1;
    }
    if (((*(byte *)(iVar3 + 8) & 6) == 0) && (iVar3 != 0)) {
      if (*(int *)(unaff_EBP + -0x18) != 0) {
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
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(*piVar1 + 4) + (int)piVar1;
        }
        if (((*(byte *)(iVar3 + 8) & 6) != 0) || (iVar3 == 0)) goto LAB_005966a9;
        if (*(int *)(iVar2 + 0x2c) != 0) {
          FUN_005942ab();
        }
        if (piVar6 != (int *)0x0) {
          *piVar6 = *piVar6 + 1;
        }
        *(int **)(iVar2 + 0x2c) = piVar6;
      }
      FUN_006326ae(unaff_EBP + -0x20);
      if (piVar1 == (int *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(*piVar1 + 4) + (int)piVar1;
      }
      if ((((*(byte *)(iVar3 + 8) & 6) == 0) && (iVar3 != 0)) && (*(int *)(unaff_EBP + -0x20) != 0))
      {
        piVar5 = operator_new(0x10);
        piVar6 = (int *)0x0;
        if (piVar5 != (int *)0x0) {
          *piVar5 = 0;
          piVar5[1] = 0;
          piVar5[2] = 0;
          piVar5[3] = 0;
          piVar6 = piVar5;
        }
        FUN_00594421(piVar1,piVar6);
        if (piVar1 == (int *)0x0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(*piVar1 + 4) + (int)piVar1;
        }
        if (((*(byte *)(iVar3 + 8) & 6) == 0) && (iVar3 != 0)) {
          if (*(int *)(iVar2 + 0x30) != 0) {
            FUN_005946cf();
          }
          if (piVar6 != (int *)0x0) {
            *piVar6 = *piVar6 + 1;
          }
          *(int **)(iVar2 + 0x30) = piVar6;
        }
      }
    }
  }
LAB_005966a9:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c4890();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return piVar1;
}

