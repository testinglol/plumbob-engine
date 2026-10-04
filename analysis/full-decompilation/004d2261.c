
undefined4 FUN_004d2261(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  void *pvVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 uVar9;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  if (*(int *)(unaff_EBP + 8) == 0xd) {
    if ((*(int *)(extraout_ECX + 0x144) != 0) &&
       (*(int *)(unaff_EBP + 0xc) == *(int *)(extraout_ECX + 0x144))) {
      FUN_004d23b5(0);
    }
  }
  else if ((*(int *)(unaff_EBP + 8) == 0x1f) && (DAT_006f0ef9 == '\0')) {
    DAT_006f0ef9 = 1;
    pvVar5 = operator_new(300);
    *(void **)(unaff_EBP + 8) = pvVar5;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar5 == (void *)0x0) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = (int *)FUN_0052a597();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if (piVar6 != (int *)0x0) {
      cVar4 = (**(code **)(*piVar6 + 0xc))();
      if (cVar4 != '\0') {
        FUN_005ddfdc(1);
        piVar7 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
        iVar8 = (**(code **)(*piVar7 + 8))();
        iVar1 = *(int *)(iVar8 + 0x7c);
        iVar2 = *(int *)(iVar8 + 0x80);
        iVar3 = *(int *)(iVar8 + 0x84);
        *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar8 + 0x88);
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) - iVar2;
        FUN_004cb21d((((piVar6[0x1f] - piVar6[0x21]) - iVar1) + iVar3) / 2,
                     ((piVar6[0x20] - piVar6[0x22]) + *(int *)(unaff_EBP + -0x14)) / 2);
        piVar6[0x12] = *(int *)(unaff_EBP + -0x10);
        uVar9 = 0;
        piVar7 = piVar6;
        (**(code **)(*DAT_006fe8bc + 0x18))(0,piVar6);
        FUN_005daa44(uVar9,piVar7);
        FUN_005da4c7(piVar6);
        FUN_005db1e2();
      }
    }
    DAT_006f0ef9 = '\0';
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return 1;
}

