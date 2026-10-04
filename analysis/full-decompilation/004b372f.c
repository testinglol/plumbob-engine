
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b372f(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EBX;
  int unaff_EBP;
  
  iVar3 = *(int *)(unaff_EBP + 0x14);
  *(undefined4 *)(unaff_EBP + -4) = 3;
  FUN_004aa3e7(&DAT_006f0bc0,iVar3);
  FUN_004b04af(*(undefined4 *)(unaff_EBP + 8),iVar3);
  if (iVar3 != 0) {
    FUN_006321f0(iVar3);
  }
  if (*(char *)(unaff_EBP + 0x1b) != '\0') {
    FUN_004b0db9(*(undefined4 *)(unaff_EBP + -0x4c));
  }
  _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -0x48);
  uVar1 = *(undefined4 *)(unaff_EBP + -0x34);
  _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0x44);
  uVar2 = *(undefined4 *)(unaff_EBP + -0x38);
  *(undefined1 *)(unaff_EBX + 0x51) = *(undefined1 *)(unaff_EBP + -0x17);
  DAT_006d6184 = *(undefined4 *)(unaff_EBP + -0x50);
  DAT_006f0095 = *(undefined1 *)(unaff_EBP + -0x16);
  FUN_005cf06d(uVar2,uVar1);
  FUN_004b3938(unaff_EBP + -0xf4);
  FUN_00586fdc(*(undefined4 *)(unaff_EBP + -0x40));
  FUN_00584818(*(undefined4 *)(unaff_EBP + -0x30));
  DAT_006e54ac = *(undefined4 *)(unaff_EBP + -0x3c);
  if (unaff_EBX + 0x88 != unaff_EBP + -0xa0) {
    FUN_004b4251(unaff_EBP + -0xa0);
    *(undefined1 *)(unaff_EBX + 0x94) = *(undefined1 *)(unaff_EBP + -0x94);
    *(undefined4 *)(unaff_EBX + 0x98) = *(undefined4 *)(unaff_EBP + -0x90);
  }
  iVar3 = FUN_005cf113();
  if (iVar3 != unaff_EBP + -0xb8) {
    FUN_004b4251(unaff_EBP + -0xb8);
    *(undefined1 *)(iVar3 + 0xc) = *(undefined1 *)(unaff_EBP + -0xac);
    *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(unaff_EBP + -0xa8);
  }
  DAT_006e4870 = *(undefined1 *)(unaff_EBP + -0x15);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005db425();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005db425();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

