
void FUN_0057b921(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  void *pvVar5;
  int *piVar6;
  int unaff_EBP;
  
  FUN_00634c24();
  FUN_005b86bd(*(undefined4 *)(unaff_EBP + 8));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005b86bd(*(undefined4 *)(unaff_EBP + 0xc));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uVar1 = FUN_004096c2();
  iVar2 = FUN_005d81cf(uVar1);
  *(int *)(unaff_EBP + 8) = iVar2;
  if (iVar2 == 0) {
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  else {
    FUN_005d49d6();
    FUN_005d4a0d(unaff_EBP + -0x28,&DAT_006c0fdc);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    uVar1 = FUN_004096c2();
    FUN_005d81cf(uVar1);
    FUN_005d4a0d(unaff_EBP + -0x4c,&DAT_006c0fdc);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    uVar1 = FUN_005d4a0d(unaff_EBP + -0x58,&DAT_006c0fdc);
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_005d499c(uVar1);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_005b8770();
    uVar1 = FUN_0057b554(unaff_EBP + -0x28);
    uVar3 = FUN_005d4a0d(unaff_EBP + -0x58,&DAT_006c0fdc);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_005d499c(uVar3);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_005b8770();
    uVar3 = FUN_0057b554(unaff_EBP + -0x28);
    *(undefined4 *)(unaff_EBP + -0x18) = uVar3;
    uVar3 = FUN_005d4a0d(unaff_EBP + -0x58,&DAT_006c0fdc);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_005d499c(uVar3);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_005b8770();
    uVar3 = FUN_0057b554(unaff_EBP + -0x28);
    *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
    uVar3 = FUN_005d4a0d(unaff_EBP + -0x58,&DAT_006c0fdc);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    FUN_005d499c(uVar3);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_005b8770();
    uVar3 = FUN_0057b554(unaff_EBP + -0x28);
    *(undefined4 *)(unaff_EBP + -0x10) = uVar3;
    uVar3 = FUN_005d4a0d(unaff_EBP + -0x58,&DAT_006c0fdc);
    *(undefined1 *)(unaff_EBP + -4) = 8;
    FUN_005d499c(uVar3);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_005b8770();
    uVar3 = FUN_0057b554(unaff_EBP + -0x28);
    *(undefined4 *)(unaff_EBP + 0xc) = uVar3;
    uVar3 = FUN_005d4a0d(unaff_EBP + -0x58,&DAT_006c0fdc);
    *(undefined1 *)(unaff_EBP + -4) = 9;
    FUN_005d499c(uVar3);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_005b8770();
    uVar3 = FUN_0057b554(unaff_EBP + -0x28);
    uVar4 = FUN_0057b554(unaff_EBP + -0x34);
    pvVar5 = operator_new(0x324);
    *(void **)(unaff_EBP + -0x1c) = pvVar5;
    *(undefined1 *)(unaff_EBP + -4) = 10;
    if (pvVar5 == (void *)0x0) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = (int *)FUN_0057d6f8(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x4c,uVar1,
                                   *(undefined4 *)(unaff_EBP + -0x18),
                                   *(undefined4 *)(unaff_EBP + -0x14),
                                   *(undefined4 *)(unaff_EBP + -0x10),
                                   *(undefined4 *)(unaff_EBP + 0xc),uVar3,uVar4);
    }
    iVar2 = *piVar6;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    (**(code **)(iVar2 + 8))();
    FUN_0057d0ce(*(undefined4 *)(unaff_EBP + 8),piVar6);
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

