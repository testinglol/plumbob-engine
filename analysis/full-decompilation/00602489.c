
void FUN_00602489(void)

{
  int iVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00673860;
  iVar1 = extraout_ECX[0x24];
  *(undefined4 *)(unaff_EBP + -4) = 2;
  iVar2 = *(int *)(iVar1 + 8);
  *(int *)(unaff_EBP + -0x10) = iVar2;
  if (iVar2 != iVar1) {
    do {
      iVar1 = *(int *)(*(int *)(unaff_EBP + -0x10) + 0x14);
      if (iVar1 != 0) {
        FUN_006029b3();
        FUN_006321f0(iVar1);
      }
      FUN_0041674f();
    } while (*(int *)(unaff_EBP + -0x10) != extraout_ECX[0x24]);
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0060290f();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_006016b5();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005d9122();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

