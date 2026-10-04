
undefined4 * FUN_004c3eea(void)

{
  int iVar1;
  short sVar2;
  int *piVar3;
  void *pvVar4;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_004075d4();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *extraout_ECX = &PTR_FUN_006688d4;
  piVar3 = operator_new(0x10);
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    *piVar3 = (int)&PTR_FUN_0066886c;
    piVar3[1] = 0;
    piVar3[2] = 0;
  }
  extraout_ECX[4] = piVar3;
  sVar2 = (**(code **)(*piVar3 + 4))();
  if (sVar2 == 0) {
    if ((undefined4 *)extraout_ECX[4] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)extraout_ECX[4])(1);
    }
    extraout_ECX[4] = 0;
  }
  pvVar4 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x14) = pvVar4;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (pvVar4 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_004b895f();
  }
  extraout_ECX[5] = piVar3;
  iVar1 = *piVar3;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  sVar2 = (**(code **)(iVar1 + 4))();
  if (sVar2 == 0) {
    if ((undefined4 *)extraout_ECX[5] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)extraout_ECX[5])(1);
    }
    extraout_ECX[5] = 0;
  }
  pvVar4 = operator_new(0x388);
  *(void **)(unaff_EBP + -0x14) = pvVar4;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  if (pvVar4 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_0049c24d();
  }
  extraout_ECX[6] = piVar3;
  iVar1 = *piVar3;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  sVar2 = (**(code **)(iVar1 + 4))();
  if (sVar2 == 0) {
    if ((undefined4 *)extraout_ECX[6] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)extraout_ECX[6])(1);
    }
    extraout_ECX[6] = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 7) = 1;
  *(undefined1 *)((int)extraout_ECX + 0x1d) = 1;
  *(undefined1 *)((int)extraout_ECX + 0x1e) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x1f) = 0;
  return extraout_ECX;
}

