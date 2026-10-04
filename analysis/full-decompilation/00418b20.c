
undefined4 * FUN_00418b20(void)

{
  undefined4 *puVar1;
  int unaff_EBP;
  undefined4 *puVar2;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  puVar2 = *(undefined4 **)(unaff_EBP + 8);
  puVar1 = *(undefined4 **)(unaff_EBP + 0x10);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xfffffff0;
  *(undefined4 **)(unaff_EBP + 8) = puVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  while (*(int *)(unaff_EBP + 0xc) != 0) {
    *(undefined4 **)(unaff_EBP + 0x10) = puVar2;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = *puVar1;
      FUN_004030b4(puVar1 + 1);
    }
    *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + -1;
    puVar2 = puVar2 + 0x14;
    *(undefined1 *)(unaff_EBP + -4) = 0;
    *(undefined4 **)(unaff_EBP + 8) = puVar2;
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return puVar2;
}

