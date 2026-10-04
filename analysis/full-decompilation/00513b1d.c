
void FUN_00513b1d(void)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 uVar5;
  
  FUN_00634c24();
  uVar1 = FUN_004e9902();
  while ((uint)(*(int *)(extraout_ECX + 0x1b8) - *(int *)(extraout_ECX + 0x1b4) >> 2) < uVar1) {
    pvVar2 = operator_new(0x28);
    *(void **)(unaff_EBP + -0x14) = pvVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar2 == (void *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_004cb630(10,5);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
    FUN_00513ce3(unaff_EBP + -0x10);
  }
  uVar3 = *(undefined4 *)(unaff_EBP + 8);
  iVar4 = FUN_004e9957(uVar3);
  if (iVar4 < 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = *(undefined4 *)(*(int *)(extraout_ECX + 0x1b4) + iVar4 * 4);
  }
  FUN_0050c694(uVar5);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined4 *)(extraout_ECX + 0x198) = uVar3;
  return;
}

