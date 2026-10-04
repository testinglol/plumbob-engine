
void FUN_00459797(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  FUN_00634c24();
  FUN_00431b5e();
  FUN_0046dfaf();
  *(undefined4 *)(unaff_EBP + -0x48) = 6;
  FUN_00435b8c(unaff_EBP + -0x5c);
  FUN_0046dfaf();
  *(uint *)(unaff_EBP + -0x1c) = *(uint *)(unaff_EBP + -0x1c) | 2;
  *(undefined1 **)(unaff_EBP + -0x18) = &DAT_006c4518;
  FUN_00435b8c(unaff_EBP + -0x38);
  FUN_0046dfaf();
  *(undefined4 *)(unaff_EBP + -0xb4) = 1;
  FUN_00435b8c(unaff_EBP + -200);
  FUN_0046dfaf();
  *(undefined4 *)(unaff_EBP + -0x6c) = 1;
  FUN_00435b8c(unaff_EBP + -0x80);
  FUN_0046dfaf();
  *(undefined4 *)(unaff_EBP + -0x90) = 1;
  FUN_00435b8c(unaff_EBP + -0xa4);
  *(short *)(extraout_ECX + 0xd0) =
       (short)((*(int *)(extraout_ECX + 0x134) - *(int *)(extraout_ECX + 0x130)) / 0x24) + -1;
  FUN_00588dff(extraout_ECX);
  FUN_0046e076();
  *(undefined4 *)(unaff_EBP + -0xfc) = 0x40000000;
  FUN_0045f795(unaff_EBP + -0x104);
  FUN_0045f7f4(0x40);
  FUN_0045f91a(2);
  pvVar2 = operator_new(0xc4);
  *(void **)(unaff_EBP + -0x10) = pvVar2;
  iVar4 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_004213c0(extraout_ECX);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0xaec) = uVar3;
  iVar5 = DAT_006e51ac;
  if (DAT_006e5240 == '\0') {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    if (0 < iVar5) {
      *(undefined4 **)(unaff_EBP + -0x10) = &DAT_006c4390;
      do {
        FUN_0046146f(8);
        iVar5 = DAT_006e51a8;
        puVar1 = *(undefined4 **)(unaff_EBP + -0x10);
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 4;
        *(undefined4 *)(iVar4 + 0x10 + iVar5) = *puVar1;
        iVar4 = iVar4 + 0x14;
      } while (*(int *)(unaff_EBP + -0x14) < DAT_006e51ac);
    }
    iVar5 = 0;
    uVar6 = 0x1f6;
    uVar3 = FUN_00401f73(0x1f6);
    FUN_0042132a(uVar3,uVar6);
    iVar4 = DAT_006e5114;
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    if (0 < iVar4) {
      *(undefined4 **)(unaff_EBP + -0x10) = &DAT_006c4390;
      do {
        FUN_0046146f(8);
        iVar4 = DAT_006e5110;
        puVar1 = *(undefined4 **)(unaff_EBP + -0x10);
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
        *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 4;
        *(undefined4 *)(iVar5 + 0x10 + iVar4) = *puVar1;
        iVar5 = iVar5 + 0x14;
      } while (*(int *)(unaff_EBP + -0x14) < DAT_006e5114);
    }
    uVar6 = 0x1f8;
    uVar3 = FUN_00401f73(0x1f8);
    FUN_0042132a(uVar3,uVar6);
    DAT_006e5240 = '\x01';
  }
  if (DAT_006e5241 == '\0') {
    (**(code **)(DAT_006e5108 + 8))();
  }
  *(undefined4 *)(extraout_ECX + 0x184) = 0xffffffff;
  FUN_004258ed(extraout_ECX,*(int *)(extraout_ECX + 0xdc) + 0x84);
  FUN_004580cc(1);
  if (((((*(short *)(extraout_ECX + 0x5e8) < 0xb) && (*(short *)(extraout_ECX + 0x5ea) < 0xb)) &&
       (*(short *)(extraout_ECX + 0x5ec) < 0xb)) &&
      ((*(short *)(extraout_ECX + 0x5ee) < 0xb && (*(short *)(extraout_ECX + 0x5f0) < 0xb)))) &&
     ((*(short *)(extraout_ECX + 0x5f2) < 0xb &&
      ((*(short *)(extraout_ECX + 0x5f4) < 0xb && (*(short *)(extraout_ECX + 0x5f6) < 0xb)))))) {
    FUN_00459c08();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

