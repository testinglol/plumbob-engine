
void FUN_0057b5e6(void)

{
  undefined4 uVar1;
  int iVar2;
  size_t sVar3;
  void *pvVar4;
  int *piVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005b86bd(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b86bd(*(undefined4 *)(unaff_EBP + 0xc));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uVar1 = FUN_004096c2();
  iVar2 = FUN_005d81cf(uVar1);
  *(int *)(unaff_EBP + -0x1c) = iVar2;
  if (iVar2 == 0) {
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  else {
    FUN_005d49d6();
    FUN_005d4a0d(unaff_EBP + -0x2c,&DAT_006c0fdc);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    uVar1 = FUN_004096c2();
    FUN_005d81cf(uVar1);
    FUN_005d4a0d(unaff_EBP + -0x68,&DAT_006c0fdc);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    uVar1 = FUN_005d4a0d(unaff_EBP + -0x5c,&DAT_006cbad0);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_005d499c(uVar1);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_005b8770();
    FUN_005d4a0d(unaff_EBP + -0x44,&DAT_006cbad0);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    uVar1 = FUN_005d4a0d(unaff_EBP + -0x5c,&DAT_006c0fdc);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_005d499c(uVar1);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_005b8770();
    uVar1 = FUN_005d4a0d(unaff_EBP + -0x5c,&DAT_006c0fdc);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    FUN_005d499c(uVar1);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_005b8770();
    uVar1 = FUN_004096c2();
    iVar2 = FUN_005d81cf(uVar1);
    *(char *)(unaff_EBP + -0x18) = '\x01' - (iVar2 != 1);
    uVar1 = FUN_005d4a0d(unaff_EBP + -0x5c,&DAT_006c0fdc);
    *(undefined1 *)(unaff_EBP + -4) = 8;
    FUN_005d499c(uVar1);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_005b8770();
    uVar1 = FUN_004096c2();
    iVar2 = FUN_005d81cf(uVar1);
    *(char *)(unaff_EBP + 0xc) = '\x01' - (iVar2 != 1);
    uVar1 = FUN_005d4a0d(unaff_EBP + -0x5c,&DAT_006c0fdc);
    *(undefined1 *)(unaff_EBP + -4) = 9;
    FUN_005d499c(uVar1);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_005b8770();
    uVar1 = FUN_004096c2();
    iVar2 = FUN_005d81cf(uVar1);
    *(char *)(unaff_EBP + -0x14) = '\x01' - (iVar2 != 1);
    uVar1 = FUN_005d4a0d(unaff_EBP + -0x5c,&DAT_006c0fdc);
    *(undefined1 *)(unaff_EBP + -4) = 10;
    FUN_005d499c(uVar1);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_005b8770();
    uVar1 = FUN_004096c2();
    iVar2 = FUN_005d81cf(uVar1);
    *(char *)(unaff_EBP + -0x10) = '\x01' - (iVar2 != 1);
    uVar1 = FUN_004096c2();
    iVar2 = FUN_005d81cf(uVar1);
    *(char *)(unaff_EBP + 8) = '\x01' - (iVar2 != 1);
    uVar1 = FUN_0057141e(unaff_EBP + -0x44);
    uVar1 = FUN_00412ab1(unaff_EBP + -0x74,uVar1);
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    FUN_005b86bd(uVar1);
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    FUN_005d499c(unaff_EBP + -0x5c);
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_00401729();
    FUN_005d499c(unaff_EBP + -0x44);
    FUN_005d4d37();
    sVar3 = _strlen(s_sounddata__006cf418);
    iVar2 = FUN_004558e0(s_sounddata__006cf418,0,sVar3);
    if (iVar2 != -1) {
      *(undefined1 *)(unaff_EBP + 0xc) = 0;
    }
    pvVar4 = operator_new(0xe8);
    *(void **)(unaff_EBP + -0x20) = pvVar4;
    *(undefined1 *)(unaff_EBP + -4) = 0xd;
    if (pvVar4 == (void *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)FUN_0057fc94(unaff_EBP + -0x68,unaff_EBP + -0x44,
                                   *(undefined4 *)(unaff_EBP + -0x18),
                                   *(undefined4 *)(unaff_EBP + 0xc),
                                   *(undefined4 *)(unaff_EBP + -0x14),
                                   *(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + 8)
                                  );
    }
    iVar2 = *piVar5;
    *(undefined1 *)(unaff_EBP + -4) = 5;
    (**(code **)(iVar2 + 8))();
    FUN_0057d0ce(*(undefined4 *)(unaff_EBP + -0x1c),piVar5);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 1;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

