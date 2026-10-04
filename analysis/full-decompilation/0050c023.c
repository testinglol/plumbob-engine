
undefined4 * FUN_0050c023(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0047343b(0,0);
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *extraout_ECX = *puVar1;
  FUN_005d499c(puVar1 + 1);
  extraout_ECX[4] = puVar1[4];
  extraout_ECX[5] = puVar1[5];
  extraout_ECX[6] = puVar1[6];
  extraout_ECX[7] = puVar1[7];
  FUN_00636510(extraout_ECX + 0xc,puVar1 + 0xc,0x10);
  uVar2 = *(undefined4 *)(unaff_EBP + -0xc);
  extraout_ECX[0x10] = puVar1[0x10];
  extraout_ECX[0x11] = puVar1[0x11];
  extraout_ECX[8] = puVar1[8];
  extraout_ECX[9] = puVar1[9];
  extraout_ECX[10] = puVar1[10];
  extraout_ECX[0xb] = puVar1[0xb];
  *unaff_FS_OFFSET = uVar2;
  return extraout_ECX;
}

