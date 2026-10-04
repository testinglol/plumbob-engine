
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_005d5223(void)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  float10 fVar3;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x18) = extraout_ECX;
  *extraout_ECX = 0;
  extraout_ECX[1] = 0;
  extraout_ECX[2] = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[3] = 0;
  extraout_ECX[4] = 0;
  extraout_ECX[5] = 0;
  extraout_ECX[6] = 0;
  extraout_ECX[7] = 0;
  extraout_ECX[8] = 0;
  extraout_ECX[9] = 0;
  extraout_ECX[10] = 0;
  extraout_ECX[0xb] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  uVar2 = rdtsc();
  *(int *)(unaff_EBP + -0x10) = (int)uVar2;
  *(int *)(unaff_EBP + -0x14) = (int)((ulonglong)uVar2 >> 0x20);
  uVar1 = *(undefined4 *)(unaff_EBP + -0x10);
  extraout_ECX[0xe] = s_TP__Constructor_006d6ddc;
  extraout_ECX[0xc] = uVar1;
  extraout_ECX[0xd] = *(undefined4 *)(unaff_EBP + -0x14);
  extraout_ECX[0xf] = 0;
  if (_DAT_006fe8a8 < _DAT_00667280) {
    fVar3 = (float10)FUN_005d5459();
    _DAT_006fe8a8 = (double)fVar3;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

