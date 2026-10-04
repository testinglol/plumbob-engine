
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_00598953(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x20) = extraout_ECX;
  FUN_005b8680();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b8680();
  *(undefined4 *)(extraout_ECX + 0x30) = 0;
  *(undefined4 *)(extraout_ECX + 0x34) = 0;
  *(undefined4 *)(extraout_ECX + 0x38) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0x3f800000;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(extraout_ECX + 0x1c) = 0;
  *(undefined4 *)(extraout_ECX + 0x20) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(extraout_ECX + 0x24) = 0;
  *(undefined4 *)(extraout_ECX + 0x28) = 0;
  *(undefined4 *)(extraout_ECX + 0x2c) = 0;
  FUN_005c4840(unaff_EBP + -0x1c,unaff_EBP + -0x18,unaff_EBP + -0x14,unaff_EBP + -0x10);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005c4830();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *(undefined4 *)(extraout_ECX + 0x7c) = 0;
  *(undefined4 *)(extraout_ECX + 0x68) = 0;
  *(undefined4 *)(extraout_ECX + 0x6c) = 1;
  *(undefined4 *)(extraout_ECX + 0x70) = 1;
  *(undefined4 *)(extraout_ECX + 0x74) = 1;
  *(undefined4 *)(extraout_ECX + 0x78) = 0;
  FUN_005c35b0();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_00598a76(1);
  uVar2 = _DAT_0066745c;
  *(undefined1 *)(extraout_ECX + 300) = 0;
  *(undefined4 *)(extraout_ECX + 0x130) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x134) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x138) = uVar2;
  *(undefined4 *)(extraout_ECX + 0x13c) = uVar2;
  *(undefined4 *)(extraout_ECX + 0x140) = uVar2;
  uVar1 = _DAT_00667458;
  *(undefined4 *)(extraout_ECX + 0x150) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x144) = uVar1;
  *(undefined4 *)(extraout_ECX + 0x148) = uVar1;
  *(undefined4 *)(extraout_ECX + 0x14c) = uVar1;
  *(undefined4 *)(extraout_ECX + 0x154) = uVar2;
  *(undefined4 *)(extraout_ECX + 0x158) = uVar2;
  *(undefined4 *)(extraout_ECX + 0x15c) = uVar2;
  uVar2 = _DAT_00667458;
  uVar1 = *(undefined4 *)(unaff_EBP + -0xc);
  *(undefined4 *)(extraout_ECX + 0x160) = _DAT_00667458;
  *(undefined4 *)(extraout_ECX + 0x164) = uVar2;
  *(undefined4 *)(extraout_ECX + 0x168) = uVar2;
  *unaff_FS_OFFSET = uVar1;
  return extraout_ECX;
}

