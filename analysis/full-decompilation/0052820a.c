
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0052820a(void)

{
  undefined4 uVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  int iVar2;
  bool bVar3;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0066d574;
  _DAT_006f3b98 = _DAT_006f3b98 + -1;
  bVar3 = _DAT_006f3b98 == 0;
  *(undefined4 *)(unaff_EBP + -4) = 3;
  if (bVar3) {
    iVar2 = 0;
    do {
      FUN_006321f0(*(undefined4 *)((int)&DAT_006f3ba8 + iVar2));
      FUN_006321f0(*(undefined4 *)((int)&DAT_006f3bbc + iVar2));
      *(undefined4 *)((int)&DAT_006f3ba8 + iVar2) = 0;
      *(undefined4 *)((int)&DAT_006f3bbc + iVar2) = 0;
      iVar2 = iVar2 + 4;
    } while (iVar2 < 0x14);
  }
  extraout_ECX[0x6a] = 0;
  extraout_ECX[0x6b] = 0;
  FUN_005e38e0();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  uVar1 = extraout_ECX[0x6c];
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar1;
  FUN_0048c4c9();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005e3892();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

