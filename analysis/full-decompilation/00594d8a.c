
int * FUN_00594d8a(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  void *pvVar5;
  int iVar6;
  int unaff_EBP;
  int *piVar7;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  do {
    FUN_00594033(unaff_EBP + -0x128,0x100,10);
    if (piVar1 == (int *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(*piVar1 + 4) + (int)piVar1;
    }
    if (((*(byte *)(iVar2 + 8) & 6) != 0) || (iVar2 == 0)) goto LAB_00594f4e;
  } while (*(char *)(unaff_EBP + -0x128) == '\0');
  FUN_005b870f(unaff_EBP + -0x128);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b88c2();
  iVar2 = *(int *)(unaff_EBP + 0xc);
  FUN_005d499c(unaff_EBP + -0x1c);
  FUN_005b88c2();
  FUN_006326ae(unaff_EBP + -0x24);
  *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(unaff_EBP + -0x24);
  FUN_006326ae(unaff_EBP + -0x20);
  if (piVar1 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(*piVar1 + 4) + (int)piVar1;
  }
  if (((*(byte *)(iVar3 + 8) & 6) == 0) && (iVar3 != 0)) {
    if (*(int *)(unaff_EBP + -0x20) != 0) {
      piVar4 = operator_new(0x10);
      piVar7 = (int *)0x0;
      if (piVar4 != (int *)0x0) {
        *piVar4 = 0;
        piVar4[1] = 0;
        piVar4[2] = 0;
        piVar4[3] = 0;
        piVar7 = piVar4;
      }
      FUN_00593f7f(piVar1,piVar7);
      if (piVar1 == (int *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(*piVar1 + 4) + (int)piVar1;
      }
      if (((*(byte *)(iVar3 + 8) & 6) != 0) || (iVar3 == 0)) goto LAB_00594f42;
      if (*(int *)(iVar2 + 0x18) != 0) {
        FUN_005942ab();
      }
      if (piVar7 != (int *)0x0) {
        *piVar7 = *piVar7 + 1;
      }
      *(int **)(iVar2 + 0x18) = piVar7;
    }
    FUN_006326ae(unaff_EBP + -0x10);
    if (piVar1 == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(*piVar1 + 4) + (int)piVar1;
    }
    if ((((*(byte *)(iVar3 + 8) & 6) == 0) && (iVar3 != 0)) &&
       (*(undefined4 *)(unaff_EBP + 8) = 0, 0 < *(int *)(unaff_EBP + -0x10))) {
      do {
        iVar3 = 0;
        pvVar5 = operator_new(0x2c);
        *(void **)(unaff_EBP + -0x28) = pvVar5;
        *(undefined1 *)(unaff_EBP + -4) = 1;
        if (pvVar5 != (void *)0x0) {
          iVar3 = FUN_00594f5f();
        }
        *(undefined1 *)(unaff_EBP + -4) = 0;
        *(int *)(iVar3 + 0x28) = iVar2;
        FUN_005947f9(piVar1,iVar3);
        if (piVar1 == (int *)0x0) {
          iVar6 = 0;
        }
        else {
          iVar6 = *(int *)(*piVar1 + 4) + (int)piVar1;
        }
        if (((*(byte *)(iVar6 + 8) & 6) != 0) || (iVar6 == 0)) break;
        *(int *)(unaff_EBP + 0xc) = iVar3;
        *(int *)(iVar3 + 0x28) = iVar2;
        FUN_0059b07c(unaff_EBP + 0xc);
        *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
      } while (*(int *)(unaff_EBP + 8) < *(int *)(unaff_EBP + -0x10));
    }
  }
LAB_00594f42:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
LAB_00594f4e:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return piVar1;
}

