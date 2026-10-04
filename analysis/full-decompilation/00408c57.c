
undefined4 * FUN_00408c57(void)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 extraout_ECX;
  int unaff_EBP;
  int iVar6;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0040d069(unaff_EBP + -0x20);
  iVar2 = FUN_0040cd0e();
  puVar3 = (undefined4 *)0x0;
  if (iVar2 < 0) goto LAB_00408d08;
  iVar6 = DAT_006e4840;
  if (iVar2 < 2) {
    for (; iVar6 != DAT_006e4844; iVar6 = iVar6 + 0x90) {
      iVar2 = FUN_0046f973(unaff_EBP + -0x20);
      if (iVar2 == 0) {
        if (iVar6 != DAT_006e4844) goto LAB_00408d85;
        break;
      }
    }
    uVar4 = FUN_00408987(unaff_EBP + -0x20);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_0040f538(uVar4);
    iVar6 = DAT_006e4840;
    iVar2 = DAT_006e4844 - DAT_006e4840;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    iVar6 = (iVar2 / 0x90) * 0x90 + -0x90 + iVar6;
LAB_00408d85:
    iVar2 = FUN_0040cc3f();
    iVar5 = FUN_0040cd0e();
    iVar1 = *(int *)(unaff_EBP + 8);
    iVar2 = iVar1 + ((uint)(iVar5 != 0) + (uint)(iVar2 != 0) * 2) * 2;
    puVar3 = *(undefined4 **)(iVar6 + 0x10 + iVar2 * 4);
    if (puVar3 != (undefined4 *)0x0) goto LAB_00408d08;
    puVar3 = operator_new(0xc);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
    }
    *(undefined4 **)(iVar6 + 0x10 + iVar2 * 4) = puVar3;
    if (iVar1 != 0) {
      FUN_0040a3c6(puVar3);
      goto LAB_00408d08;
    }
  }
  else if (iVar2 < 4) {
    if (*(int *)(unaff_EBP + 8) == 1) {
LAB_00408ca0:
      puVar3 = (undefined4 *)0x0;
      goto LAB_00408d08;
    }
    puVar3 = DAT_006e483c;
    if (DAT_006e483c != (undefined4 *)0x0) goto LAB_00408d08;
    puVar3 = operator_new(0xc);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
      DAT_006e483c = puVar3;
    }
    else {
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      DAT_006e483c = puVar3;
    }
  }
  else {
    if (5 < iVar2) goto LAB_00408d08;
    if (*(int *)(unaff_EBP + 8) == 1) goto LAB_00408ca0;
    puVar3 = DAT_006e4838;
    if (DAT_006e4838 != (undefined4 *)0x0) goto LAB_00408d08;
    puVar3 = operator_new(0xc);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
      DAT_006e4838 = puVar3;
    }
    else {
      *puVar3 = 0;
      puVar3[1] = 0;
      puVar3[2] = 0;
      DAT_006e4838 = puVar3;
    }
  }
  FUN_004096c5(puVar3);
LAB_00408d08:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return puVar3;
}

