
undefined4 FUN_004257ef(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  void *pvVar5;
  int extraout_ECX;
  int iVar6;
  int unaff_EBP;
  int *piVar7;
  uint uVar8;
  
  FUN_00634c24();
  uVar8 = 0;
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  if (*(int *)(unaff_EBP + 8) == 0) {
    uVar2 = 0;
    goto LAB_004258de;
  }
  iVar6 = extraout_ECX;
  if (*(short *)(unaff_EBP + 0xc) < 1) {
LAB_0042586b:
    piVar1 = *(int **)(iVar6 + 0x148);
    piVar7 = (int *)(iVar6 + 0x148);
    piVar4 = piVar1;
    if (piVar1 != *(int **)(iVar6 + 0x14c)) {
      do {
        if (*piVar4 == 0) {
          uVar8 = ((int)piVar4 - (int)piVar1 >> 2) + 1;
        }
        piVar4 = piVar4 + 1;
      } while (piVar4 != *(int **)(iVar6 + 0x14c));
      if (uVar8 != 0) goto LAB_004258b2;
    }
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    FUN_0042eb02(unaff_EBP + -0x10);
    uVar8 = *(int *)(iVar6 + 0x14c) - *piVar7 >> 2;
  }
  else {
    piVar7 = (int *)(extraout_ECX + 0x148);
    uVar8 = (uint)*(short *)(unaff_EBP + 0xc);
    if (((uint)(*(int *)(extraout_ECX + 0x14c) - *(int *)(extraout_ECX + 0x148) >> 2) < uVar8) &&
       (iVar3 = *(int *)(extraout_ECX + 0x14c) - *(int *)(extraout_ECX + 0x148) >> 2,
       iVar3 < (int)uVar8)) {
      iVar3 = uVar8 - iVar3;
      do {
        *(undefined4 *)(unaff_EBP + 0xc) = 0;
        FUN_0042eb02(unaff_EBP + 0xc);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      iVar6 = *(int *)(unaff_EBP + -0x10);
    }
    uVar8 = ~-(uint)(*(int *)(*piVar7 + -4 + uVar8 * 4) != 0) & uVar8;
    if (uVar8 == 0) goto LAB_0042586b;
  }
LAB_004258b2:
  pvVar5 = operator_new(0x274);
  *(void **)(unaff_EBP + 0xc) = pvVar5;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar5 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004237d4(uVar8,*(undefined4 *)(unaff_EBP + 8));
  }
  *(undefined4 *)(*piVar7 + -4 + uVar8 * 4) = uVar2;
LAB_004258de:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

