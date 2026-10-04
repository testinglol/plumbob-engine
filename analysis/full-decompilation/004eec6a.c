
undefined4 * FUN_004eec6a(void)

{
  uint uVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined2 in_FPUControlWord;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  FUN_005edab3(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004075d4();
  extraout_ECX[0x1e] = 0;
  extraout_ECX[0x1f] = 0;
  extraout_ECX[0x20] = 0;
  extraout_ECX[0x21] = 0;
  extraout_ECX[0x22] = 0;
  extraout_ECX[0x23] = 0;
  extraout_ECX[0x24] = 0;
  extraout_ECX[0x25] = 0;
  extraout_ECX[0x26] = 0;
  extraout_ECX[0x27] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  extraout_ECX[0x28] = 0;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_005d48d9();
  *(undefined1 *)(extraout_ECX + 0x3d) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xf5) = 1;
  *(undefined1 *)((int)extraout_ECX + 0xf6) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xf7) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xf9) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xfa) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xfb) = 0;
  *(undefined1 *)(extraout_ECX + 0x3f) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xfd) = 0;
  extraout_ECX[0x45] = 0;
  extraout_ECX[0x4a] = 0;
  extraout_ECX[0x4b] = 0;
  *(undefined2 *)((int)extraout_ECX + 0x132) = 0xffff;
  *(undefined1 *)(extraout_ECX + 0x4c) = 0;
  extraout_ECX[0x4d] = 0;
  *(undefined2 *)(extraout_ECX + 0x4e) = 0;
  *(undefined1 *)(unaff_EBP + -4) = 7;
  *(undefined1 *)(extraout_ECX + 0x50) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x141) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x142) = 0;
  *extraout_ECX = &PTR_LAB_00669884;
  extraout_ECX[1] = &PTR_LAB_00669878;
  extraout_ECX[2] = &PTR_FUN_00669860;
  extraout_ECX[4] = &PTR_LAB_00669858;
  extraout_ECX[0x12] = &PTR_LAB_00669810;
  extraout_ECX[0x1a] = &PTR_LAB_00669804;
  CoInitialize((LPVOID)0x0);
  DAT_006f2a08 = extraout_ECX;
  iVar4 = FUN_004eec4f();
  if (iVar4 == 0) {
    pvVar5 = operator_new(0xc);
    *(void **)(unaff_EBP + 8) = pvVar5;
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    if (pvVar5 == (void *)0x0) {
      DAT_006f2a0c = 0;
    }
    else {
      uVar6 = FUN_005d4956(PTR_s_TheSims_006c9f64);
      *(undefined4 *)(unaff_EBP + -0x10) = 2;
      *(undefined1 *)(unaff_EBP + -4) = 0xc;
      DAT_006f2a0c = FUN_005d93ef(uVar6);
    }
    bVar2 = *(byte *)(unaff_EBP + -0x10) & 2;
    *(undefined4 *)(unaff_EBP + -4) = 7;
  }
  else {
    pvVar5 = operator_new(0xc);
    *(void **)(unaff_EBP + 8) = pvVar5;
    *(undefined1 *)(unaff_EBP + -4) = 8;
    if (pvVar5 == (void *)0x0) {
      DAT_006f2a0c = 0;
    }
    else {
      uVar6 = FUN_005d4956(PTR_s_Global_TheSims_006c9f60);
      *(undefined4 *)(unaff_EBP + -0x10) = 1;
      *(undefined1 *)(unaff_EBP + -4) = 9;
      DAT_006f2a0c = FUN_005d93ef(uVar6);
    }
    bVar2 = *(byte *)(unaff_EBP + -0x10) & 1;
    *(undefined4 *)(unaff_EBP + -4) = 7;
  }
  if (bVar2 != 0) {
    FUN_005b8770();
  }
  *(undefined1 *)(extraout_ECX + 0x3e) = 0;
  uVar6 = 0;
  *(undefined2 *)(unaff_EBP + -0x10) = in_FPUControlWord;
  uVar1 = *(uint *)(unaff_EBP + -0x10);
  if ((((uVar1 & 0x300) != 0) || (((byte)uVar1 & 0x3f) != 0x3f)) || ((uVar1 & 0xc00) != 0)) {
    *(ushort *)(unaff_EBP + 10) = *(ushort *)(unaff_EBP + -0x10) & 0xf0ff | 0x3f;
    uVar6 = 1;
  }
  if ((undefined2 *)((int)extraout_ECX + 0xfe) != (undefined2 *)0x0) {
    *(undefined2 *)((int)extraout_ECX + 0xfe) = (short)uVar1;
  }
  extraout_ECX[0x40] = uVar6;
  *(undefined1 *)(extraout_ECX + 0x41) = 0;
  extraout_ECX[0x2c] = 0;
  *(undefined1 *)((int)extraout_ECX + 0x105) = 1;
  extraout_ECX[0x42] = 0;
  uVar6 = (**(code **)(*DAT_006fe8bc + 0x34))();
  *(undefined4 *)(unaff_EBP + 8) = uVar6;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 0xe;
  cVar3 = FUN_005d6516(s_memlog_006ca6f0,unaff_EBP + -0x20,1);
  if (cVar3 == '\0') {
    FUN_005d6516(s_memlog_006ca6f0,0,1);
  }
  else {
    _strcmp(*(char **)(unaff_EBP + -0x20),s_verbose_006ca6e8);
  }
  cVar3 = FUN_005d6516(s_memdiffNT_006ca6dc,unaff_EBP + -0x20,1);
  if (cVar3 == '\0') {
    FUN_005d6516(s_memdiffNT_006ca6dc,0,1);
  }
  else {
    _strcmp(*(char **)(unaff_EBP + -0x20),s_verbose_006ca6e8);
  }
  cVar3 = FUN_005d6516(s_memanalysis_006ca6d0,unaff_EBP + -0x20,1);
  if ((cVar3 != '\0') && (iVar4 = FUN_005d49d6(), iVar4 != 0)) {
    FUN_00635f62(*(undefined4 *)(unaff_EBP + -0x20));
  }
  DAT_006c9f93 = FUN_005d6516(s_enable_sound_trycatch_006ca6b8,0,1);
  *(undefined1 *)(extraout_ECX + 0x43) = 0;
  extraout_ECX[0x44] = 0;
  *(undefined1 *)(extraout_ECX + 0x46) = 0;
  extraout_ECX[0x47] = 0xffffffff;
  extraout_ECX[0x48] = 0;
  extraout_ECX[0x49] = 0;
  *(undefined1 *)(extraout_ECX + 0x4c) = 0;
  *(undefined2 *)((int)extraout_ECX + 0x132) = 0xffff;
  extraout_ECX[0x4d] = 0;
  *(undefined2 *)(extraout_ECX + 0x4e) = 0;
  *(undefined2 *)((int)extraout_ECX + 0x13a) = 0xffff;
  *(undefined2 *)(extraout_ECX + 0x4f) = 0xffff;
  pvVar5 = operator_new(0x24);
  *(void **)(unaff_EBP + 8) = pvVar5;
  *(undefined1 *)(unaff_EBP + -4) = 0xf;
  if (pvVar5 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_005d909f();
  }
  extraout_ECX[0x3c] = uVar6;
  FUN_005a93b0(0x400000);
  FUN_005a6810();
  FUN_005b6020();
  *(undefined1 *)(unaff_EBP + -4) = 7;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

