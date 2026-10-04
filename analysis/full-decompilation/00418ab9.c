
undefined4 * FUN_00418ab9(void)

{
  int unaff_EBP;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puVar1 = *(undefined4 **)(unaff_EBP + 0x10);
  puVar2 = *(undefined4 **)(unaff_EBP + 8);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xfffffff0;
  *(undefined4 **)(unaff_EBP + 0x10) = puVar1;
  for (; puVar2 != *(undefined4 **)(unaff_EBP + 0xc); puVar2 = puVar2 + 0x14) {
    *(undefined4 **)(unaff_EBP + 8) = puVar1;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = *puVar2;
      FUN_004030b4(puVar2 + 1);
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    puVar1 = puVar1 + 0x14;
    *(undefined4 **)(unaff_EBP + 0x10) = puVar1;
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return puVar1;
}

