
undefined4 * FUN_0041e80d(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffec;
  puVar2 = (undefined4 *)FUN_00401742(0x1c);
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 **)(unaff_EBP + -0x14) = puVar2;
  *puVar2 = 0;
  FUN_0041ea52(puVar2 + 1,uVar1);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return puVar2;
}

