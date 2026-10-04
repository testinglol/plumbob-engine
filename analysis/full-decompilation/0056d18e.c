
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_0056d18e(void)

{
  float fVar1;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_005e372a();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b8680();
  fVar1 = DAT_00673438 * _DAT_00666578;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(float *)(unaff_EBP + -0x10) = fVar1;
  extraout_ECX[0x6a] = 0;
  FUN_005c38c0(extraout_ECX + 0x6d,1,unaff_EBP + -0x10);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0047352a();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0x87] = *(undefined4 *)(unaff_EBP + 8);
  extraout_ECX[0x86] = 0;
  *extraout_ECX = &PTR_FUN_00671314;
  *(undefined1 *)(extraout_ECX + 0x88) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x221) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x222) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x223) = 0;
  *(undefined1 *)(extraout_ECX + 0x89) = 0;
  extraout_ECX[0x69] = 0;
  extraout_ECX[0x8a] = 0xfffffffe;
  return extraout_ECX;
}

