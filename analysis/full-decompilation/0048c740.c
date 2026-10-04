
undefined4 * FUN_0048c740(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00492ad8();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0xc] = 0;
  extraout_ECX[0xd] = 0;
  extraout_ECX[0xe] = 0;
  extraout_ECX[0x13] = 0;
  extraout_ECX[0x14] = 0;
  extraout_ECX[0x15] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_00635e55(extraout_ECX + 0x1b,0xc,9,FUN_005b8680,FUN_005b8770);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005c1719();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  *extraout_ECX = &PTR_FUN_00667f1c;
  *(undefined2 *)((int)extraout_ECX + 0x2e) = 0;
  *(undefined1 *)(extraout_ECX + 0xb) = 0;
  *(undefined1 *)(extraout_ECX + 0x36) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xd9) = 0;
  *(undefined1 *)((int)extraout_ECX + 0xda) = 0;
  extraout_ECX[0x37] = 0;
  extraout_ECX[0x38] = 0;
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x7c) = &PTR_FUN_0066643c;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  uVar2 = FUN_0041532c(9,unaff_EBP + -0x7c,0);
  cVar1 = FUN_004fff98(0x9f,uVar2);
  if (cVar1 != '\0') {
    uVar2 = FUN_004705f2(1,0xffffffff);
    FUN_005d4bbf(uVar2);
    uVar2 = FUN_004705f2(2,0xffffffff);
    FUN_005d4bbf(uVar2);
    uVar2 = FUN_004705f2(3,0xffffffff);
    FUN_005d4bbf(uVar2);
    uVar2 = FUN_004705f2(4,0xffffffff);
    FUN_005d4bbf(uVar2);
    uVar2 = FUN_004705f2(5,0xffffffff);
    FUN_005d4bbf(uVar2);
    uVar2 = FUN_004705f2(6,0xffffffff);
    FUN_005d4bbf(uVar2);
    uVar2 = FUN_004705f2(7,0xffffffff);
    FUN_005d4bbf(uVar2);
    uVar2 = FUN_004705f2(8,0xffffffff);
    FUN_005d4bbf(uVar2);
    uVar2 = FUN_004705f2(9,0xffffffff);
    FUN_005d4bbf(uVar2);
  }
  extraout_ECX[0x1a] = 5;
  DAT_006e579c = 0;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_00470467();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return extraout_ECX;
}

