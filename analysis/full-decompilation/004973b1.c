
void FUN_004973b1(void)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  DAT_006e5be8 = 1;
  FUN_004d25a5(0x26);
  if (*(int *)(extraout_ECX + 0x3c) == 0) {
    pvVar1 = operator_new(0x28);
    *(void **)(unaff_EBP + -0x14) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004772fb(0x40);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(extraout_ECX + 0x3c) = iVar2;
    if (iVar2 != 0) {
      FUN_00461765();
    }
  }
  if (*(int *)(extraout_ECX + 0x40) == 0) {
    pvVar1 = operator_new(0x28);
    *(void **)(unaff_EBP + -0x14) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 1;
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004772fb(0x40);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(extraout_ECX + 0x40) = iVar2;
    if (iVar2 != 0) {
      FUN_00461765();
    }
  }
  uVar3 = FUN_00461e56(0,0,0,0,1);
  *(undefined4 *)(unaff_EBP + -4) = 2;
  FUN_0048ec44(uVar3);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x48) = 0;
  uVar3 = FUN_004790b8();
  FUN_0047736d(uVar3);
  FUN_0047736d(*(undefined4 *)(extraout_ECX + 0x40));
  FUN_004790b8();
  FUN_004776fd();
  FUN_004b1284(*(undefined4 *)(extraout_ECX + 0x3c));
  FUN_004b0de0();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 0x4c) = 1;
  return;
}

