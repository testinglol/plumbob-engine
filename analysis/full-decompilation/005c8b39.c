
undefined4 FUN_005c8b39(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  uVar1 = *(uint *)(unaff_EBP + 8);
  if ((uVar1 != *(uint *)(extraout_ECX + 0x20)) && (uVar1 != 0)) {
    *(uint *)(extraout_ECX + 0x20) = uVar1;
    FUN_005bc557((int)(1000 / (ulonglong)uVar1) * 1000);
  }
  FUN_005bc44e(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005bc58e(unaff_EBP + -0x28,(undefined4 *)(extraout_ECX + 0x28));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(int *)(unaff_EBP + 8) = extraout_ECX + 0x38;
  iVar2 = FUN_005bc676();
  iVar3 = FUN_005bc676();
  if (iVar3 < iVar2) {
    FUN_005bc54d();
    *(undefined1 *)(unaff_EBP + -4) = 2;
    puVar4 = (undefined4 *)FUN_005bc58e(unaff_EBP + -0x30,unaff_EBP + -0x18);
    *(undefined4 *)(unaff_EBP + -0x20) = *puVar4;
    *(undefined4 *)(unaff_EBP + -0x1c) = puVar4[1];
    FUN_0042004f();
    iVar2 = FUN_005bc676();
    if (0 < iVar2) {
      iVar2 = FUN_005bc676();
      *(int *)(unaff_EBP + -0x10) = iVar2 / 1000;
    }
    puVar4 = (undefined4 *)FUN_005bc566(unaff_EBP + -0x30,*(undefined4 *)(unaff_EBP + 8));
    *(undefined4 *)(extraout_ECX + 0x30) = *puVar4;
    *(undefined4 *)(extraout_ECX + 0x34) = puVar4[1];
    FUN_0042004f();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_0042004f();
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(extraout_ECX + 0x28) = *(undefined4 *)(unaff_EBP + -0x18);
  *(undefined4 *)(extraout_ECX + 0x2c) = *(undefined4 *)(unaff_EBP + -0x14);
  FUN_0042004f();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0042004f();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x10);
}

