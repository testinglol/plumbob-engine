
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_00570888(void)

{
  float fVar1;
  void *pvVar2;
  int *piVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  pvVar2 = operator_new(0x118);
  *(void **)(unaff_EBP + -0x54) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_005d314d(*(undefined4 *)(extraout_ECX + 0x10));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    fVar1 = _DAT_006714e8 * _DAT_00666578;
    *(float *)(unaff_EBP + -0x50) = fVar1;
    *(float *)(unaff_EBP + -0x20) = fVar1 * *(float *)(extraout_ECX + 0x14);
    uVar4 = FUN_005d0e5a();
    *(undefined4 *)(unaff_EBP + -0x54) = uVar4;
    if (*(int *)(unaff_EBP + 8) == 3) {
      *(undefined4 *)(unaff_EBP + -0x1c) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      uVar4 = *(undefined4 *)(unaff_EBP + -0x50);
      *(undefined4 *)(unaff_EBP + -0x34) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(unaff_EBP + -0x20);
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
      *(undefined4 *)(unaff_EBP + -0x28) = 0;
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      *(undefined4 *)(unaff_EBP + -0x4c) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(unaff_EBP + -0x20);
      *(undefined4 *)(unaff_EBP + -0x44) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x14) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x10) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x40) = 0;
      *(undefined4 *)(unaff_EBP + -0x3c) = 0;
      *(undefined4 *)(unaff_EBP + -0x38) = 0;
      FUN_005c5a00(unaff_EBP + -0x40,unaff_EBP + -0x14,unaff_EBP + -0x4c,unaff_EBP + -0x28,
                   unaff_EBP + -0x34,unaff_EBP + -0x1c,extraout_ECX + 0x18,0);
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(unaff_EBP + -0x20);
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      uVar4 = *(undefined4 *)(unaff_EBP + -0x50);
      *(undefined4 *)(unaff_EBP + -0x40) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x38) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x28) = 0;
      *(undefined4 *)(unaff_EBP + -0x24) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x4c) = 0;
      *(undefined4 *)(unaff_EBP + -0x48) = 0;
      *(undefined4 *)(unaff_EBP + -0x44) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x1c) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x18) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x34) = 0;
      *(undefined4 *)(unaff_EBP + -0x30) = 0;
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    }
    else if (*(int *)(unaff_EBP + 8) == 4) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(unaff_EBP + -0x20);
      *(undefined4 *)(unaff_EBP + -0x10) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(unaff_EBP + -0x50);
      *(undefined4 *)(unaff_EBP + -0x3c) = 0;
      *(undefined4 *)(unaff_EBP + -0x38) = 0;
      *(undefined4 *)(unaff_EBP + -0x28) = 0;
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      *(undefined4 *)(unaff_EBP + -0x4c) = 0;
      *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + -0x50);
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x34) = 0;
      *(undefined4 *)(unaff_EBP + -0x30) = 0;
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
      FUN_005c5a00(unaff_EBP + -0x34,unaff_EBP + -0x1c,unaff_EBP + -0x4c,unaff_EBP + -0x28,
                   unaff_EBP + -0x40,unaff_EBP + -0x14,extraout_ECX + 0x18,0);
      *(undefined4 *)(unaff_EBP + -0x14) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(unaff_EBP + -0x20);
      *(undefined4 *)(unaff_EBP + -0x10) = 0x3f800000;
      uVar4 = *(undefined4 *)(unaff_EBP + -0x50);
      *(undefined4 *)(unaff_EBP + -0x40) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x3c) = 0;
      *(undefined4 *)(unaff_EBP + -0x38) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x28) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      *(undefined4 *)(unaff_EBP + -0x4c) = 0;
      *(undefined4 *)(unaff_EBP + -0x44) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x34) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x30) = 0;
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    }
    else if (*(int *)(unaff_EBP + 8) == 9) {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      uVar4 = *(undefined4 *)(unaff_EBP + -0x50);
      *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(unaff_EBP + -0x20);
      *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(unaff_EBP + -0x20);
      *(undefined4 *)(unaff_EBP + -0x40) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x38) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x28) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x4c) = 0;
      *(undefined4 *)(unaff_EBP + -0x24) = 0x3f000000;
      *(undefined4 *)(unaff_EBP + -0x48) = 0;
      *(undefined4 *)(unaff_EBP + -0x44) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x34) = 0;
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
      FUN_005c5a00(unaff_EBP + -0x34,unaff_EBP + -0x1c,unaff_EBP + -0x4c,unaff_EBP + -0x28,
                   unaff_EBP + -0x40,unaff_EBP + -0x14,extraout_ECX + 0x18,0);
      *(undefined4 *)(unaff_EBP + -0x14) = 0x3f800000;
      uVar4 = *(undefined4 *)(unaff_EBP + -0x50);
      *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(unaff_EBP + -0x20);
      *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(unaff_EBP + -0x20);
      *(undefined4 *)(unaff_EBP + -0x40) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x3c) = 0;
      *(undefined4 *)(unaff_EBP + -0x38) = 0;
      *(undefined4 *)(unaff_EBP + -0x28) = 0;
      *(undefined4 *)(unaff_EBP + -0x24) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x4c) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x44) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x10) = 0x3f000000;
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      *(undefined4 *)(unaff_EBP + -0x34) = 0;
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      *(undefined4 *)(unaff_EBP + -0x10) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(unaff_EBP + -0x20);
      *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(unaff_EBP + -0x20);
      *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(unaff_EBP + -0x50);
      *(undefined4 *)(unaff_EBP + -0x3c) = 0;
      *(undefined4 *)(unaff_EBP + -0x38) = 0;
      *(undefined4 *)(unaff_EBP + -0x28) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      *(undefined4 *)(unaff_EBP + -0x4c) = 0;
      *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + -0x50);
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      *(undefined4 *)(unaff_EBP + -0x34) = 0;
      *(undefined4 *)(unaff_EBP + -0x2c) = 0;
      FUN_005c5a00(unaff_EBP + -0x34,unaff_EBP + -0x1c,unaff_EBP + -0x4c,unaff_EBP + -0x28,
                   unaff_EBP + -0x40,unaff_EBP + -0x14,extraout_ECX + 0x18,0);
      *(undefined4 *)(unaff_EBP + -0x14) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x10) = 0x3f800000;
      uVar4 = *(undefined4 *)(unaff_EBP + -0x50);
      *(undefined4 *)(unaff_EBP + -0x40) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x3c) = 0;
      *(undefined4 *)(unaff_EBP + -0x38) = 0;
      *(undefined4 *)(unaff_EBP + -0x28) = 0x3f800000;
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      *(undefined4 *)(unaff_EBP + -0x4c) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(unaff_EBP + -0x20);
      *(undefined4 *)(unaff_EBP + -0x44) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      *(undefined4 *)(unaff_EBP + -0x34) = 0;
      *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(unaff_EBP + -0x20);
      *(undefined4 *)(unaff_EBP + -0x2c) = uVar4;
    }
    FUN_005c5a00(unaff_EBP + -0x34,unaff_EBP + -0x1c,unaff_EBP + -0x4c,unaff_EBP + -0x28,
                 unaff_EBP + -0x40,unaff_EBP + -0x14,extraout_ECX + 0x18,0);
    FUN_005c5ed0();
    uVar4 = FUN_005caeef();
    FUN_005c2dc3(uVar4);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    FUN_0046f824(unaff_EBP + -0x170,0,0x104);
    *(undefined ***)(unaff_EBP + -0x17c) = &PTR_FUN_006664e8;
    uVar4 = FUN_0041532c(0xf,0,unaff_EBP + -0x17c);
    FUN_004ee9ce(uVar4);
    uVar4 = FUN_005c2dfa(*(undefined4 *)(unaff_EBP + -0x178));
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_005caef6(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005c2ee6();
    FUN_005d1318();
    (**(code **)(*piVar3 + 0x28))(0);
    FUN_005caef6(unaff_EBP + -0x60);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005c2ee6();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar3;
}

