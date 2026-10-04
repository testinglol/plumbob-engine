
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005d06b6(void)

{
  float fVar1;
  int iVar2;
  float fVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  float10 fVar5;
  
  FUN_00634c24();
  fVar5 = (float10)FUN_00639144((double)(*(float *)(extraout_ECX + 0xc4) * (float)_DAT_00667270));
  fVar1 = *(float *)(extraout_ECX + 0xbc);
  *(float *)(unaff_EBP + -0x1c) = *(float *)(extraout_ECX + 0xbc);
  *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(extraout_ECX + 0xc0);
  iVar2 = *(int *)(extraout_ECX + 4);
  *(float *)(unaff_EBP + -0x18) = (float)(fVar5 * (float10)fVar1);
  fVar1 = *(float *)(iVar2 + 0x18) / *(float *)(iVar2 + 0x1c);
  *(float *)(unaff_EBP + -0x10) = fVar1;
  if (fVar1 <= (float)_DAT_00667280) {
    fVar1 = (float)_DAT_00667280 / *(float *)(unaff_EBP + -0x10);
    uVar4 = 0x3f800000;
  }
  else {
    fVar1 = 1.0;
    uVar4 = *(undefined4 *)(unaff_EBP + -0x10);
  }
  fVar3 = *(float *)(unaff_EBP + -0x14) * *(float *)(unaff_EBP + -0x18);
  *(float *)(unaff_EBP + -0x14) = *(float *)(unaff_EBP + -0x14) - *(float *)(unaff_EBP + -0x1c);
  *(float *)(unaff_EBP + -0x10) = *(float *)(unaff_EBP + -0x18) / *(float *)(unaff_EBP + -0x1c);
  *(float *)(unaff_EBP + -0x18) =
       fVar3 / (*(float *)(unaff_EBP + -0x14) * *(float *)(unaff_EBP + -0x1c));
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + -0x18);
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(unaff_EBP + -0x10);
  *(float *)(unaff_EBP + -0x24) = -(fVar3 / *(float *)(unaff_EBP + -0x14));
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  *(undefined4 *)(unaff_EBP + -0x4c) = 0;
  *(undefined4 *)(unaff_EBP + -0x48) = 0;
  *(undefined4 *)(unaff_EBP + -0x5c) = 0;
  *(undefined4 *)(unaff_EBP + -0x58) = uVar4;
  *(undefined4 *)(unaff_EBP + -0x54) = 0;
  *(undefined4 *)(unaff_EBP + -0x50) = 0;
  *(float *)(unaff_EBP + -0x3c) = fVar1;
  *(undefined4 *)(unaff_EBP + -0x38) = 0;
  *(undefined4 *)(unaff_EBP + -0x34) = 0;
  *(undefined4 *)(unaff_EBP + -0x30) = 0;
  FUN_00462e7a(unaff_EBP + -0x3c,unaff_EBP + -0x5c,unaff_EBP + -0x4c,unaff_EBP + -0x2c);
  FUN_005c3650();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar4 = FUN_005ce950(unaff_EBP + -0xa0,extraout_ECX);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c4890();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

