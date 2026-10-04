
int FUN_00533c7d(void)

{
  float fVar1;
  undefined4 *puVar2;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005d48d9();
  puVar2 = *(undefined4 **)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d4bbf(puVar2[3]);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined4 *)(extraout_ECX + 0x10) = *puVar2;
  *(undefined4 *)(extraout_ECX + 0x14) = puVar2[1];
  fVar1 = (float)puVar2[2];
  *(undefined4 *)(extraout_ECX + 0x20) = 1;
  *(float *)(extraout_ECX + 0x18) = fVar1;
  *(float *)(extraout_ECX + 0x1c) = fVar1 * fVar1;
  return extraout_ECX;
}

