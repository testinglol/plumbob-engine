
int * FUN_00595790(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  int iVar6;
  int iVar7;
  int iVar8;
  
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
    if (((*(byte *)(iVar2 + 8) & 6) != 0) || (iVar2 == 0)) goto LAB_00595952;
  } while (*(char *)(unaff_EBP + -0x428) == '\0');
  uVar3 = FUN_005b870f(unaff_EBP + -0x428);
  iVar2 = *(int *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00595f2a(uVar3);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  do {
    FUN_00594033(unaff_EBP + -0x428,0x400,10);
    if (piVar1 == (int *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(*piVar1 + 4) + (int)piVar1;
    }
    if (((*(byte *)(iVar4 + 8) & 6) != 0) || (iVar4 == 0)) goto LAB_00595952;
  } while (*(char *)(unaff_EBP + -0x428) == '\0');
  uVar3 = FUN_005b870f(unaff_EBP + -0x428);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_005d499c(uVar3);
  *(int *)(iVar2 + 0x130) = *(int *)(iVar2 + 0x130) + 1;
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  FUN_006326ae(unaff_EBP + -0x10);
  if (piVar1 == (int *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(*piVar1 + 4) + (int)piVar1;
  }
  if (((*(byte *)(iVar4 + 8) & 6) == 0) && (iVar4 != 0)) {
    if (*(int *)(unaff_EBP + -0x10) != 0) {
      puVar5 = operator_new(0x10);
      if (puVar5 == (undefined4 *)0x0) {
        *(undefined4 *)(unaff_EBP + 8) = 0;
      }
      else {
        *puVar5 = 0;
        puVar5[1] = 0;
        puVar5[2] = 0;
        puVar5[3] = 0;
        *(undefined4 **)(unaff_EBP + 8) = puVar5;
      }
      FUN_00593f7f(piVar1,*(undefined4 *)(unaff_EBP + 8));
      if (piVar1 == (int *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(*piVar1 + 4) + (int)piVar1;
      }
      if (((*(byte *)(iVar4 + 8) & 6) != 0) || (iVar4 == 0)) goto LAB_00595952;
      FUN_00595f04(*(undefined4 *)(unaff_EBP + 8));
    }
    uVar3 = FUN_005c3cd0(piVar1,iVar2 + 0x30,iVar2 + 0x3c);
    FUN_005c4ba0(uVar3);
    iVar4 = iVar2 + 0x7c;
    iVar8 = iVar2 + 0x78;
    iVar7 = iVar2 + 0x74;
    iVar6 = iVar2 + 0x70;
    FUN_006326ae(iVar2 + 0x6c);
    FUN_006326ae(iVar6);
    FUN_006326ae(iVar7);
    FUN_006326ae(iVar8);
    FUN_00633f35(iVar4);
    FUN_00595c10();
  }
LAB_00595952:
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return piVar1;
}

