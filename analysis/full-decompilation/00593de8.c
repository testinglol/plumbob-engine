
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00593de8(void)

{
  float fVar1;
  char cVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  float10 fVar4;
  float10 fVar5;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  if (_DAT_006d2c6c <= (float)_DAT_00667280 - *(float *)(extraout_ECX + 0x20)) {
    fVar4 = (float10)FUN_00636c30();
    fVar1 = *(float *)(extraout_ECX + 0x24);
    fVar5 = (float10)fsin(fVar4);
    *(float *)(unaff_EBP + -0x14) = (float)((float10)_DAT_00666748 / fVar5);
    *(float *)(unaff_EBP + -0x10) =
         (float)((fVar4 + (float10)fVar1) * (float10)**(float **)(unaff_EBP + 0xc));
    fVar4 = (float10)fsin(fVar4 - (float10)*(float *)(unaff_EBP + -0x10));
    *(float *)(unaff_EBP + 0xc) = (float)(fVar4 * (float10)*(float *)(unaff_EBP + -0x14));
    fVar4 = (float10)fsin((float10)*(float *)(unaff_EBP + -0x10));
    fVar4 = fVar4 * (float10)*(float *)(unaff_EBP + -0x14);
  }
  else {
    *(undefined4 *)(unaff_EBP + 0xc) = **(undefined4 **)(unaff_EBP + 0xc);
    fVar4 = (float10)1 - (float10)*(float *)(unaff_EBP + 0xc);
  }
  cVar2 = *(char *)(extraout_ECX + 0x28);
  *(float *)(unaff_EBP + -0x14) = (float)fVar4;
  if (cVar2 != '\0') {
    *(float *)(unaff_EBP + 0xc) = -*(float *)(unaff_EBP + 0xc);
  }
  uVar3 = FUN_00593c3b(unaff_EBP + -0x48,unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_00593c3b(unaff_EBP + -0x38,unaff_EBP + -0x14);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  uVar3 = FUN_00593eeb(unaff_EBP + -0x28,uVar3);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005c4870(uVar3);
  *(undefined4 *)(unaff_EBP + -0x18) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005c4890();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005c4890();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005c4890();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + 8);
}

