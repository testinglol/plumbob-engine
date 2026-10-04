
undefined4 FUN_004c27b6(void)

{
  int iVar1;
  char cVar2;
  void *pvVar3;
  int *piVar4;
  undefined4 uVar5;
  int extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 *puVar6;
  int unaff_EBP;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  FUN_00634c24();
  if (*(int *)(extraout_ECX + 0x14c) != 0) {
    FUN_005e3581();
    *(undefined4 *)(extraout_ECX + 0x14c) = 0;
  }
  uStack_18 = 0x4c27e4;
  pvVar3 = operator_new(100);
  *(void **)(unaff_EBP + -0x10) = pvVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar3 == (void *)0x0) {
    piVar4 = (int *)0x0;
    uStack_24 = 0;
  }
  else {
    piVar4 = (int *)FUN_005dfb13();
    uStack_24 = extraout_ECX_00;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int **)(extraout_ECX + 0x14c) = piVar4;
  if (piVar4 != (int *)0x0) {
    iVar1 = *piVar4;
    uStack_18 = 0;
    uStack_1c = 0;
    *(undefined4 **)(unaff_EBP + -0x10) = &uStack_24;
    uStack_20 = uStack_24;
    FUN_00436a50(4);
    cVar2 = (**(code **)(iVar1 + 0xc))
                      (*(undefined4 *)(extraout_ECX + 0x24),*(undefined4 *)(extraout_ECX + 0x28));
    puVar6 = *(undefined4 **)(extraout_ECX + 0x14c);
    if (cVar2 != '\0') {
      cVar2 = FUN_005df69e();
      puVar6 = *(undefined4 **)(extraout_ECX + 0x14c);
      if (cVar2 != '\0') {
        FUN_005e357a();
        uVar5 = 1;
        goto LAB_004c285e;
      }
    }
    if (puVar6 != (undefined4 *)0x0) {
      (**(code **)*puVar6)(1);
    }
    *(undefined4 *)(extraout_ECX + 0x14c) = 0;
  }
  uVar5 = 0;
LAB_004c285e:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

