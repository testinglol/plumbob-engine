
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a07ba(void)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (((_DAT_0067343c < ABS(**(float **)(unaff_EBP + 8) - _DAT_00666748)) ||
      (_DAT_0067343c < ABS(**(float **)(unaff_EBP + 0xc) - _DAT_00666748))) ||
     (_DAT_0067343c < ABS(**(float **)(unaff_EBP + 0x10) - _DAT_00666748))) {
    fVar1 = **(float **)(unaff_EBP + 0x10);
    *(undefined4 *)(unaff_EBP + -0x4c) = 0;
    *(float *)(unaff_EBP + -0x34) = fVar1;
    fVar1 = **(float **)(unaff_EBP + 0xc);
    *(undefined4 *)(unaff_EBP + -0x48) = 0;
    *(float *)(unaff_EBP + -0x18) = fVar1;
    fVar1 = **(float **)(unaff_EBP + 8);
    *(undefined4 *)(unaff_EBP + -0x44) = 0;
    *(float *)(unaff_EBP + -0x2c) = fVar1;
    *(undefined4 *)(unaff_EBP + -0x40) = 0x3f800000;
    *(undefined4 *)(unaff_EBP + -0x3c) = 0;
    *(undefined4 *)(unaff_EBP + -0x38) = 0;
    *(undefined4 *)(unaff_EBP + -0x30) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    uVar2 = FUN_00462e7a(unaff_EBP + -0x2c,unaff_EBP + -0x1c,unaff_EBP + -0x3c,unaff_EBP + -0x4c);
    iVar3 = FUN_005c3650(uVar2);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_00462f2f(iVar3);
    uVar2 = *(undefined4 *)(iVar3 + 0x40);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(extraout_ECX + 0xa8) = uVar2;
    FUN_005c4890();
  }
  else {
    FUN_00462f2f(&DAT_006fe6d0);
    *(undefined4 *)(extraout_ECX + 0xa8) = DAT_006fe710;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

