
undefined4 * FUN_005a3d16(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b8680();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8680();
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d499c(puVar1 + 1);
  *extraout_ECX = *puVar1;
  FUN_005d499c(puVar1 + 4);
  FUN_005d499c(puVar1 + 7);
  uVar2 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[10] = puVar1[10];
  *(undefined1 *)(extraout_ECX + 0xb) = *(undefined1 *)(puVar1 + 0xb);
  extraout_ECX[0xc] = puVar1[0xc];
  *unaff_FS_OFFSET = uVar2;
  return extraout_ECX;
}

