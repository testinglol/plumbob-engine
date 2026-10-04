
undefined4 * FUN_004e88f3(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005c1719();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[3] = 0;
  FUN_005b8680();
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *extraout_ECX = *puVar1;
  FUN_005a5e72();
  FUN_005a5e1c(puVar1 + 1);
  uVar2 = puVar1[3];
  *(undefined1 *)(extraout_ECX + 2) = *(undefined1 *)(puVar1 + 2);
  *(undefined1 *)((int)extraout_ECX + 9) = *(undefined1 *)((int)puVar1 + 9);
  extraout_ECX[3] = uVar2;
  uVar2 = FUN_0041f169();
  FUN_005d499c(uVar2);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

