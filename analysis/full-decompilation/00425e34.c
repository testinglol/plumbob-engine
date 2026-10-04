
undefined4 FUN_00425e34(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  void *pvVar6;
  int iVar7;
  int extraout_ECX;
  int iVar8;
  int unaff_EBP;
  
  FUN_00634c24();
  piVar5 = *(int **)(extraout_ECX + 0x154);
  piVar1 = *(int **)(extraout_ECX + 0x158);
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x10) = 1;
  iVar8 = extraout_ECX;
  do {
    piVar2 = piVar5;
    if (piVar5 != piVar1) {
      do {
        if (*(int *)(*piVar2 + 0x10c) == *(int *)(unaff_EBP + -0x10)) {
          iVar3 = *piVar2;
          iVar8 = *(int *)(unaff_EBP + -0x14);
          goto LAB_00425e81;
        }
        piVar2 = piVar2 + 1;
      } while (piVar2 != piVar1);
      iVar8 = *(int *)(unaff_EBP + -0x14);
    }
    iVar3 = 0;
LAB_00425e81:
    if (iVar3 == 0) {
      if (*(int *)(unaff_EBP + -0x10) < 0x8000) {
        iVar3 = 1;
        for (; piVar5 != piVar1; piVar5 = piVar5 + 1) {
          if (iVar3 <= *(int *)(*piVar5 + 0x114)) {
            iVar3 = *(int *)(*piVar5 + 0x114) + 1;
          }
        }
        pvVar6 = operator_new(0x15c);
        *(void **)(unaff_EBP + -0x18) = pvVar6;
        iVar7 = 0;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (pvVar6 != (void *)0x0) {
          iVar7 = FUN_004100cf(*(undefined4 *)(*DAT_006e486c + 0x14),
                               *(undefined4 *)(unaff_EBP + -0x10));
        }
        *(int *)(unaff_EBP + -0x14) = iVar7;
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(int *)(iVar7 + 0x114) = iVar3;
        *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0x118) = DAT_006e4a24;
        FUN_0042eb8e(unaff_EBP + -0x14);
        if (1 < (uint)(*(int *)(extraout_ECX + 0x158) - *(int *)(extraout_ECX + 0x154) >> 2)) {
          FUN_0042feee(*(int *)(extraout_ECX + 0x154),*(undefined4 *)(iVar8 + 0x158),&LAB_00425253);
        }
        uVar4 = *(undefined4 *)(unaff_EBP + -0x14);
      }
      else {
        uVar4 = 0;
      }
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return uVar4;
    }
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
  } while( true );
}

