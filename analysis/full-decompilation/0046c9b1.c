
undefined4 * FUN_0046c9b1(void)

{
  undefined4 *puVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = *puVar1;
  extraout_ECX[1] = puVar1[1];
  FUN_005b86bd(puVar1 + 2);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b86bd(puVar1 + 5);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0046ca4b(puVar1 + 8);
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return extraout_ECX;
}

