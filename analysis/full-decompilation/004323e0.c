
void FUN_004323e0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_00666d34;
  iVar1 = extraout_ECX[0x47];
  *(undefined4 *)(unaff_EBP + -4) = 6;
  if (iVar1 != 0) {
    FUN_0043ddf8(iVar1);
    extraout_ECX[0x47] = 0;
  }
  iVar1 = extraout_ECX[0x48];
  if (iVar1 != 0) {
    FUN_00584a60();
    FUN_006321f0(iVar1);
    extraout_ECX[0x48] = 0;
  }
  if (extraout_ECX[0xb] != 0) {
    FUN_006321f0(extraout_ECX[0xb]);
    extraout_ECX[0xb] = 0;
  }
  if (extraout_ECX[0xd] != 0) {
    FUN_006321f0(extraout_ECX[0xd]);
    extraout_ECX[0xd] = 0;
  }
  if (*(int *)(DAT_006e486c + 0x10) != 0) {
    FUN_0057a9a6((int)*(short *)(extraout_ECX + 0x3c));
  }
  uVar2 = extraout_ECX[0x52];
  *(undefined1 *)(unaff_EBP + -4) = 5;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_00435c04();
  uVar2 = extraout_ECX[0x4f];
  *(undefined1 *)(unaff_EBP + -4) = 4;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_00435c04();
  uVar2 = extraout_ECX[0x4c];
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  FUN_00435be1();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005a5e09();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_004652c0();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00474919();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

