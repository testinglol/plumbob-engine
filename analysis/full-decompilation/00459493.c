
undefined4 * FUN_00459493(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *extraout_ECX;
  int iVar3;
  int unaff_EBP;
  undefined4 *puVar4;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_0043194c(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00420f9d();
  extraout_ECX[0x205] = 0;
  extraout_ECX[0x206] = 0;
  extraout_ECX[0x207] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_0045f887();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0041ed45();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_0041ed45();
  extraout_ECX[0x2b4] = 0;
  extraout_ECX[0x2b5] = 0;
  extraout_ECX[0x2b6] = 0;
  extraout_ECX[0x2b8] = 0;
  extraout_ECX[0x2b9] = 0;
  extraout_ECX[0x2ba] = 0;
  extraout_ECX[700] = 0;
  extraout_ECX[0x2bd] = 0;
  extraout_ECX[0x2be] = 0;
  extraout_ECX[0x2c0] = 0;
  extraout_ECX[0x2c1] = 0;
  extraout_ECX[0x2c2] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  FUN_0046f824(extraout_ECX + 0x2cf,0,0x40);
  extraout_ECX[0x2cc] = &PTR_FUN_0066651c;
  FUN_0046f824(extraout_ECX + 0x2e2,0,0x40);
  extraout_ECX[0x2df] = &PTR_FUN_0066651c;
  FUN_0046f824(extraout_ECX + 0x2f5,0,0x40);
  extraout_ECX[0x2f2] = &PTR_FUN_0066651c;
  *extraout_ECX = &PTR_FUN_00667378;
  extraout_ECX[0x203] = extraout_ECX;
  extraout_ECX[0x204] = 0;
  extraout_ECX[699] = 0;
  pvVar1 = operator_new(0x2a0);
  *(void **)(unaff_EBP + 0xc) = pvVar1;
  *(undefined1 *)(unaff_EBP + -4) = 9;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00587d5c();
  }
  extraout_ECX[0x2b7] = uVar2;
  puVar4 = extraout_ECX + 0x163;
  for (iVar3 = 0x80; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined2 *)((int)extraout_ECX + 0xb2e) = 0xffff;
  *(undefined2 *)(extraout_ECX + 0x2cb) = 0xfc19;
  *(undefined1 *)(extraout_ECX + 0x60) = 1;
  *(undefined2 *)(extraout_ECX + 0x2bf) = 0xfffb;
  extraout_ECX[0x2c4] = 0;
  extraout_ECX[0x2c5] = 0;
  *(undefined1 *)(extraout_ECX + 0x2c3) = 0;
  extraout_ECX[0x2c7] = 0;
  extraout_ECX[0x2c6] = 0;
  extraout_ECX[0x2c8] = 0;
  extraout_ECX[0x2c9] = 0;
  extraout_ECX[0x2ca] = 0;
  FUN_006358b0(extraout_ECX + 99,&DAT_006c12fc);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

