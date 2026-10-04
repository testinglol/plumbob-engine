
void FUN_00594fa2(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 8);
  *(int *)(unaff_EBP + -0x1c) = extraout_ECX;
  do {
    FUN_00594033(unaff_EBP + -0x124,0x100,10);
    if (piVar1 == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(*piVar1 + 4) + (int)piVar1;
    }
    if (((*(byte *)(iVar3 + 8) & 6) != 0) || (iVar3 == 0)) goto LAB_005950fb;
  } while (*(char *)(unaff_EBP + -0x124) == '\0');
  FUN_005b870f(unaff_EBP + -0x124);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b88c2();
  FUN_005d499c(unaff_EBP + -0x18);
  FUN_005b88c2();
  FUN_006326ae(unaff_EBP + -0x24);
  *(undefined4 *)(extraout_ECX + 0x14) = *(undefined4 *)(unaff_EBP + -0x24);
  FUN_006326ae(unaff_EBP + -0x20);
  iVar3 = 0;
  if (piVar1 == (int *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(*piVar1 + 4) + (int)piVar1;
  }
  if (((*(byte *)(iVar4 + 8) & 6) == 0) && (iVar4 != 0)) {
    if (*(int *)(unaff_EBP + -0x20) != 0) {
      FUN_00594082(piVar1);
      if (piVar1 == (int *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(*piVar1 + 4) + (int)piVar1;
      }
      if (((*(byte *)(iVar4 + 8) & 6) != 0) || (iVar4 == 0)) goto LAB_005950ef;
    }
    FUN_006326ae(unaff_EBP + 8);
    if (piVar1 == (int *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(*piVar1 + 4) + (int)piVar1;
    }
    if ((((*(byte *)(iVar4 + 8) & 6) == 0) && (iVar4 != 0)) && (0 < *(int *)(unaff_EBP + 8))) {
      iVar4 = *(int *)(unaff_EBP + 0x10);
      do {
        uVar2 = *(undefined4 *)(unaff_EBP + 0xc);
        *(undefined4 *)(iVar4 + 0x28) = *(undefined4 *)(unaff_EBP + -0x1c);
        FUN_0059498e(piVar1,uVar2);
        if (piVar1 == (int *)0x0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(*piVar1 + 4) + (int)piVar1;
        }
      } while ((((*(byte *)(iVar5 + 8) & 6) == 0) && (iVar5 != 0)) &&
              (iVar3 = iVar3 + 1, iVar3 < *(int *)(unaff_EBP + 8)));
    }
  }
LAB_005950ef:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
LAB_005950fb:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

