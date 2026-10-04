
undefined4 * FUN_005a3a7d(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe4;
  puVar2 = (undefined4 *)FUN_00401742(0x38);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 **)(unaff_EBP + -0x14) = puVar2;
  *puVar2 = 0;
  puVar1 = puVar2 + 1;
  *(undefined4 **)(unaff_EBP + -0x18) = puVar1;
  *(undefined4 **)(unaff_EBP + -0x1c) = puVar1;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (puVar1 != (undefined4 *)0x0) {
    FUN_005a3c06(*(undefined4 *)(unaff_EBP + 8));
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return puVar2;
}

