
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004a6d2d(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00476c11();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004075d4();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_004a702c();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_004a702c();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_004c9d81();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_004c9b32();
  extraout_ECX[0x72] = 0;
  extraout_ECX[0x73] = 0;
  extraout_ECX[0x74] = 0;
  extraout_ECX[0x75] = 0;
  extraout_ECX[0x76] = 0;
  extraout_ECX[0x77] = 0;
  extraout_ECX[0x78] = 0;
  extraout_ECX[0x79] = 0;
  extraout_ECX[0x7a] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_00635e55(extraout_ECX + 0x82,8,0x40,FUN_004678f9,FUN_00416e17);
  extraout_ECX[0x104] = 0;
  extraout_ECX[0x105] = 0;
  extraout_ECX[0x106] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 10;
  FUN_004a702c();
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  FUN_004a702c();
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  FUN_004a702c();
  *(undefined1 *)(unaff_EBP + -4) = 0xd;
  FUN_004a702c();
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  FUN_0047343b(0,0);
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 0x10;
  FUN_004a702c();
  *extraout_ECX = &PTR_FUN_00668744;
  extraout_ECX[2] = &PTR_FUN_00668738;
  DAT_006f0080 = 0;
  DAT_006f0084 = 0;
  DAT_006f0088 = 1;
  *(undefined1 *)(extraout_ECX + 0x12) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x49) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x4e) = 1;
  *(undefined1 *)((int)extraout_ECX + 0x4a) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x4b) = 0;
  *(undefined1 *)(extraout_ECX + 0x13) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x4d) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x17d) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x17e) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x17f) = 0;
  extraout_ECX[0x1c] = 0;
  extraout_ECX[0x1d] = 0;
  *(undefined1 *)(extraout_ECX + 0x1e) = 0;
  extraout_ECX[0x21] = 0;
  extraout_ECX[0x20] = 0;
  extraout_ECX[7] = 0;
  *(undefined1 *)(extraout_ECX + 0x5e) = 0;
  extraout_ECX[0x5c] = 0;
  extraout_ECX[0x5d] = 0;
  extraout_ECX[6] = 1;
  *(undefined1 *)((int)extraout_ECX + 0x17a) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x179) = 0;
  extraout_ECX[0x15] = 0;
  extraout_ECX[0x1a] = 0;
  extraout_ECX[0x1b] = 0;
  *(undefined1 *)(extraout_ECX + 0x7e) = 0;
  *(undefined1 *)(extraout_ECX + 0x80) = 0;
  uVar2 = DAT_006f0088;
  *(undefined1 *)(unaff_EBP + -4) = 0x11;
  extraout_ECX[0x16] = 0x10 << ((byte)uVar2 & 0x1f);
  extraout_ECX[0x17] = 8 << ((byte)DAT_006f0088 & 0x1f);
  extraout_ECX[0x18] = 8 << ((byte)DAT_006f0088 & 0x1f);
  uVar2 = DAT_006f0088;
  extraout_ECX[0x6f] = 0;
  *(undefined1 *)(extraout_ECX + 0x70) = 1;
  extraout_ECX[0x71] = 0;
  extraout_ECX[0x7b] = 0;
  extraout_ECX[0x7c] = 0;
  *(undefined1 *)((int)extraout_ECX + 0x17b) = 1;
  *(undefined1 *)(extraout_ECX + 0x5f) = 0;
  extraout_ECX[0x19] = 4 << ((byte)uVar2 & 0x1f);
  *(undefined1 *)((int)extraout_ECX + 0x4f) = 1;
  DAT_006f008c = *(undefined4 *)(DAT_006e54d8 + 0x84);
  _DAT_006f0090 = extraout_ECX;
  FUN_004cfc2e(extraout_ECX);
  *(undefined1 *)(extraout_ECX + 0x14) = 0;
  extraout_ECX[0x11f] = 0;
  extraout_ECX[0x12e] = 0;
  extraout_ECX[0x12f] = 0;
  pvVar1 = operator_new(0x14);
  *(void **)(unaff_EBP + -0x14) = pvVar1;
  *(undefined1 *)(unaff_EBP + -4) = 0x12;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0049e9e0(3);
  }
  extraout_ECX[0x7f] = uVar2;
  extraout_ECX[0xe] = 0xfffff000;
  extraout_ECX[0xf] = 0xfffff000;
  *(undefined1 *)((int)extraout_ECX + 0x51) = 0;
  extraout_ECX[0x10] = 0x1000;
  extraout_ECX[0x11] = 0x1000;
  *(undefined1 *)(extraout_ECX + 0x130) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 0x11;
  extraout_ECX[0x133] = 0;
  extraout_ECX[0x134] = 0;
  extraout_ECX[0x135] = 0;
  extraout_ECX[0x136] = 0;
  *(undefined1 *)(extraout_ECX + 0x137) = 0;
  *(undefined1 *)(extraout_ECX + 0x146) = 0;
  *(undefined1 *)(extraout_ECX + 0x60) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x181) = 0;
  FUN_00476c48();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

