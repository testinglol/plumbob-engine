
undefined4 FUN_00599e94(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  int extraout_ECX;
  uint uVar7;
  int unaff_EBP;
  int iVar8;
  undefined1 *puVar9;
  
  FUN_00634c24();
  piVar1 = *(int **)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if ((piVar1 == (int *)0x0) || (iVar8 = *piVar1, piVar1[1] == iVar8)) {
    iVar8 = 0;
  }
  if (iVar8 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_00636450(iVar8,0x3d);
  }
  if (iVar3 != 0) {
    FUN_005b86cf(iVar8,iVar3 - iVar8);
    iVar4 = *(int *)(extraout_ECX + 0x18);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_005b86bd(iVar4 + 0x10);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    iVar4 = FUN_004558e0(*(undefined4 *)(unaff_EBP + -0x1c),0,
                         *(int *)(unaff_EBP + -0x18) - *(int *)(unaff_EBP + -0x1c));
    puVar9 = (undefined1 *)((iVar3 - iVar8) + 1 + iVar8);
    if (iVar4 == -1) {
      puVar9 = *(undefined1 **)(unaff_EBP + -0x10);
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
    if (puVar9 != (undefined1 *)0x0) goto LAB_00599f38;
  }
  puVar9 = &DAT_006de560;
LAB_00599f38:
  FUN_005b870f(puVar9);
  *(undefined4 *)(unaff_EBP + -4) = 2;
  pvVar5 = operator_new(0x34);
  *(void **)(unaff_EBP + 0xc) = pvVar5;
  iVar8 = *(int *)(unaff_EBP + 8);
  uVar7 = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  if (pvVar5 == (void *)0x0) {
    *(undefined4 *)(unaff_EBP + 0xc) = 0;
  }
  else {
    uVar6 = FUN_0059996c(iVar8,extraout_ECX,unaff_EBP + -0x28);
    *(undefined4 *)(unaff_EBP + 0xc) = uVar6;
  }
  iVar3 = *(int *)(extraout_ECX + 0x2c);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  if (iVar3 - *(int *)(extraout_ECX + 0x28) >> 2 != 0) {
    do {
      if ((iVar8 == 0) ||
         (uVar2 = *(uint *)(*(int *)(extraout_ECX + 0x28) + uVar7 * 4),
         (uint)(*(int *)(iVar8 + 0x74) - *(int *)(iVar8 + 0x70) >> 2) <= uVar2)) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(*(int *)(iVar8 + 0x70) + uVar2 * 4);
      }
      *(int *)(unaff_EBP + 8) = iVar3;
      if ((iVar8 != 0) && (iVar3 == 0)) {
        if (*(int *)(unaff_EBP + 0xc) != 0) {
          FUN_00599bbd();
          FUN_006321f0(*(undefined4 *)(unaff_EBP + 0xc));
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
        uVar6 = 0;
        goto LAB_00599ff7;
      }
      if ((iVar3 != 0) && (iVar8 != 0)) {
        *(int *)(iVar3 + 0x134) = *(int *)(iVar3 + 0x134) + 1;
        if (*(int *)(iVar3 + 0x1c) != 0) {
          piVar1 = (int *)(*(int *)(iVar3 + 0x1c) + 0xac);
          *piVar1 = *piVar1 + 1;
        }
      }
      FUN_0059ae67(unaff_EBP + 8);
      uVar7 = uVar7 + 1;
    } while (uVar7 < (uint)(*(int *)(extraout_ECX + 0x2c) - *(int *)(extraout_ECX + 0x28) >> 2));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  uVar6 = *(undefined4 *)(unaff_EBP + 0xc);
LAB_00599ff7:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

