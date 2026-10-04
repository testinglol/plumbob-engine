
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00513bb6(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int extraout_ECX;
  int iVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar1 = FUN_004e9902();
  *(undefined4 *)(unaff_EBP + -0x10) = uVar1;
  while ((uint)(*(int *)(extraout_ECX + 0x1b8) - *(int *)(extraout_ECX + 0x1b4) >> 2) <
         *(uint *)(unaff_EBP + -0x10)) {
    pvVar2 = operator_new(0x28);
    *(void **)(unaff_EBP + -0x14) = pvVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar2 == (void *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = FUN_004cb630(10,5);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x18) = uVar1;
    FUN_00513ce3(unaff_EBP + -0x18);
  }
  iVar3 = 0;
  if (0 < *(int *)(unaff_EBP + -0x10)) {
    do {
      uVar1 = FUN_004e9918(iVar3);
      FUN_004ea7e2(uVar1);
      uVar1 = __ftol();
      *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
      FUN_004cb761(unaff_EBP + -0x14);
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(unaff_EBP + -0x10));
  }
  if (*(int *)(extraout_ECX + 0x198) != -1) {
    iVar3 = FUN_004ea7e2(*(int *)(extraout_ECX + 0x198));
    FUN_00513cae(*(undefined4 *)(iVar3 + *(int *)(extraout_ECX + 0x19c) * 4));
    if (*(int *)(extraout_ECX + 0x1b0) != 0) {
      FUN_0050c729();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

