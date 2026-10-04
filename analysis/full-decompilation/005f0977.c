
undefined4 * FUN_005f0977(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  *extraout_ECX = *puVar1;
  extraout_ECX[1] = puVar1[1];
  extraout_ECX[2] = puVar1[2];
  extraout_ECX[3] = puVar1[3];
  extraout_ECX[4] = puVar1[4];
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005b86bd(puVar1 + 5);
  iVar2 = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b86bd(iVar2 + 0x20);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005f09dd(iVar2 + 0x2c);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

