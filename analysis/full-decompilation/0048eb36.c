
void FUN_0048eb36(void)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  DAT_006e57a0 = 1;
  if (*(int *)(extraout_ECX + 0x38) == 0) {
    pvVar1 = operator_new(0x28);
    *(void **)(unaff_EBP + -0x14) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_00461651(0x40);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(extraout_ECX + 0x38) = iVar2;
    if (iVar2 != 0) {
      FUN_00461765();
    }
  }
  if (*(int *)(extraout_ECX + 0x3c) == 0) {
    pvVar1 = operator_new(0x28);
    *(void **)(unaff_EBP + -0x14) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_00461651(0x40);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(extraout_ECX + 0x3c) = iVar2;
    if (iVar2 != 0) {
      FUN_00461765();
    }
  }
  uVar3 = FUN_00461e56(0,0,0,0,1);
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_0048ec44(uVar3);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x48) = 0;
  uVar3 = FUN_004790b4();
  FUN_004616c3(uVar3);
  FUN_004616c3(*(undefined4 *)(extraout_ECX + 0x3c));
  FUN_004790b4();
  FUN_00461b8d();
  FUN_004b0e40(*(undefined4 *)(extraout_ECX + 0x38));
  FUN_004b0de0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 0x58) = 1;
  return;
}

