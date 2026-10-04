
void FUN_005771d6(void)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = DAT_006f63e8;
  *(int **)(unaff_EBP + -0x14) = &DAT_006f63e8;
  *(undefined ***)(unaff_EBP + -0x18) = &PTR_LAB_00669c88;
  (**(code **)(iVar1 + 4))();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00601324(unaff_EBP + 8);
  *(int *)(extraout_ECX + 4) = *(int *)(extraout_ECX + 4) + 1;
  if (*(int *)(extraout_ECX + 4) == 1) {
    pvVar2 = operator_new(0x20);
    *(void **)(unaff_EBP + -0x10) = pvVar2;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (pvVar2 == (void *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_005ed88f();
    }
    *(int **)(extraout_ECX + 0xc) = piVar3;
    iVar1 = *piVar3;
    *(undefined1 *)(unaff_EBP + -4) = 0;
    (**(code **)(iVar1 + 0x20))(&LAB_00577092,extraout_ECX);
    (**(code **)**(undefined4 **)(extraout_ECX + 0xc))(DAT_006cf0c8);
    (**(code **)(**(int **)(extraout_ECX + 0xc) + 0x10))(DAT_006cf0c4);
    puVar4 = operator_new(0x20);
    *(undefined4 **)(unaff_EBP + -0x10) = puVar4;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4[2] = 0;
      puVar4[4] = 0;
      *puVar4 = 1;
      puVar4[3] = 0;
      puVar4[5] = 0;
      uVar5 = FUN_005fd96f();
      puVar4[6] = uVar5;
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(undefined4 **)(extraout_ECX + 0x10) = puVar4;
    FUN_005772e2();
    uVar5 = FUN_005fd8ea();
    *(undefined4 *)(extraout_ECX + 0x1c) = uVar5;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined1 *)(extraout_ECX + 0x28) = 1;
  (**(code **)(DAT_006f63e8 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

