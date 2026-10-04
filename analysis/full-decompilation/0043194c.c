
undefined4 * FUN_0043194c(void)

{
  short sVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  void *pvVar4;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_004748cf();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0055e4e2(unaff_EBP + -0xd);
  extraout_ECX[0x3d] = 0;
  extraout_ECX[0x3e] = 0;
  *(undefined1 *)((int)extraout_ECX + 0xfe) = 0;
  extraout_ECX[0x40] = 0;
  extraout_ECX[0x41] = 0;
  extraout_ECX[0x42] = 0;
  extraout_ECX[0x43] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  extraout_ECX[0x48] = 0;
  FUN_005c1719();
  extraout_ECX[0x4c] = 0;
  extraout_ECX[0x4d] = 0;
  extraout_ECX[0x4e] = 0;
  extraout_ECX[0x4f] = 0;
  extraout_ECX[0x50] = 0;
  extraout_ECX[0x51] = 0;
  extraout_ECX[0x52] = 0;
  extraout_ECX[0x53] = 0;
  extraout_ECX[0x54] = 0;
  uVar2 = *(undefined4 *)(unaff_EBP + 8);
  uVar3 = *(undefined4 *)(unaff_EBP + 0xc);
  *extraout_ECX = &PTR_FUN_00666d34;
  extraout_ECX[0x47] = uVar2;
  extraout_ECX[0x37] = uVar3;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_0043ddeb(uVar2);
  extraout_ECX[0x45] = 0;
  *(undefined2 *)(extraout_ECX + 0x3c) = 0;
  extraout_ECX[0x46] = *(undefined4 *)(extraout_ECX[0x47] + 0x60);
  extraout_ECX[0x3e] = 0;
  extraout_ECX[0x3d] = 0;
  *(undefined1 *)(extraout_ECX + 0x3f) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xfd) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xfe) = 0;
  extraout_ECX[0x44] = 0;
  extraout_ECX[0x43] = 0;
  extraout_ECX[0x42] = 0;
  extraout_ECX[0x41] = 0;
  extraout_ECX[0x40] = 0;
  *(byte *)((int)extraout_ECX + 0x115) = *(byte *)((int)extraout_ECX + 0x115) | 2;
  extraout_ECX[0x38] = 0;
  sVar1 = *(short *)(extraout_ECX[0x46] + 0x74);
  extraout_ECX[0xc] = (int)sVar1;
  if (sVar1 < 8) {
    extraout_ECX[0xc] = 8;
  }
  pvVar4 = operator_new(extraout_ECX[0xc] << 1);
  extraout_ECX[0xb] = pvVar4;
  FUN_005a9250((int)extraout_ECX + 0x4a,0,0x90);
  FUN_005a9250(extraout_ECX[0xb],0,extraout_ECX[0xc] << 1);
  FUN_005a9250((int)extraout_ECX + 0x3a,0,0x10);
  extraout_ECX[0x57] = 1;
  extraout_ECX[0x55] = 0x7fffffff;
  extraout_ECX[0x56] = 0;
  SetRect((LPRECT)(extraout_ECX + 0x58),0x7fffffff,0x7fffffff,-0x80000000,-0x80000000);
  SetRect((LPRECT)(extraout_ECX + 0x5c),0x7fffffff,0x7fffffff,-0x80000000,-0x80000000);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *(undefined1 *)(extraout_ECX + 0x60) = 0;
  *(undefined1 *)(extraout_ECX + 0x62) = 0;
  extraout_ECX[0x61] = 0;
  extraout_ECX[0xd] = 0;
  *(undefined2 *)(extraout_ECX + 0xe) = 0;
  extraout_ECX[0x4a] = 0;
  extraout_ECX[0x4b] = 0;
  return extraout_ECX;
}

