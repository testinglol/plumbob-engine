
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00540c42(void)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  short *psVar5;
  int extraout_ECX;
  int iVar6;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x20) = 0;
  if (*(int *)(extraout_ECX + 0x2c) == 0) {
    iVar3 = *(int *)(DAT_006e54dc + 0x10);
    *(undefined1 *)(unaff_EBP + -0x12) = 1;
    *(char *)(unaff_EBP + -0x14) = (char)(iVar3 / 2);
    *(char *)(unaff_EBP + -0x13) = (char)(iVar3 / 2);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    pvVar2 = operator_new(0x60);
    *(void **)(unaff_EBP + -0x18) = pvVar2;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (pvVar2 == (void *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_0053c1f5(unaff_EBP + -0x14,0);
    }
    *(int *)(extraout_ECX + 0x2c) = iVar3;
    *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 1;
    *(undefined1 *)(unaff_EBP + -4) = 0;
    pvVar2 = operator_new(0x60);
    *(void **)(unaff_EBP + -0x18) = pvVar2;
    if (pvVar2 == (void *)0x0) {
      iVar3 = 0;
    }
    else {
      *(undefined1 *)(unaff_EBP + -0xe) = 0;
      *(undefined4 *)(unaff_EBP + -0x20) = 1;
      *(undefined1 *)(unaff_EBP + -0x10) = (&DAT_006e481c)[*(int *)(unaff_EBP + 0x1c) * 3];
      *(undefined1 *)(unaff_EBP + -0xf) = (&DAT_006e481d)[*(int *)(unaff_EBP + 0x1c) * 3];
      *(undefined1 *)(unaff_EBP + -4) = 3;
      uVar4 = FUN_0046185f(unaff_EBP + -0x38,unaff_EBP + -0x10);
      *(undefined4 *)(unaff_EBP + -0x20) = 3;
      *(undefined4 *)(unaff_EBP + -4) = 4;
      iVar3 = FUN_0053c1f5(uVar4,0);
    }
    *(int *)(extraout_ECX + 0x30) = iVar3;
    *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    pvVar2 = operator_new(0x5c);
    *(void **)(unaff_EBP + 0x1c) = pvVar2;
    *(undefined1 *)(unaff_EBP + -4) = 7;
    if (pvVar2 == (void *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_0053d7f2();
    }
    *(int *)(extraout_ECX + 0x34) = iVar3;
    *(int *)(iVar3 + 0x58) = *(int *)(iVar3 + 0x58) + 1;
    uVar4 = *(undefined4 *)(extraout_ECX + 0x30);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_0053fde2(*(undefined4 *)(extraout_ECX + 0x2c),uVar4);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  FUN_0053dab7(*(undefined4 *)(unaff_EBP + 0x14));
  FUN_0053d9be(*(undefined4 *)(unaff_EBP + 0x18));
  FUN_0053fce8(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),
               *(undefined4 *)(unaff_EBP + 0x10));
  SetRect((LPRECT)(unaff_EBP + -0x34),-800,-600,800,600);
  uVar4 = _DAT_006f0bc0;
  *(undefined4 *)(unaff_EBP + -0x20) = _DAT_006f0bc4;
  *(undefined2 *)(unaff_EBP + -0x1c) = *(undefined2 *)(unaff_EBP + -0x30);
  *(undefined2 *)(unaff_EBP + -0x18) = *(undefined2 *)(unaff_EBP + -0x28);
  *(undefined2 *)(unaff_EBP + -0x1a) = *(undefined2 *)(unaff_EBP + -0x34);
  *(undefined2 *)(unaff_EBP + -0x16) = *(undefined2 *)(unaff_EBP + -0x2c);
  _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -0x1c);
  _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0x18);
  FUN_004b4533(*(undefined4 *)(DAT_006e486c + 4));
  FUN_0053dd1c(unaff_EBP + -0x34,unaff_EBP + -0xac,0);
  FUN_0053c3dc(unaff_EBP + -0x34,unaff_EBP + -0xac,0);
  FUN_0053c3dc(unaff_EBP + -0x34,unaff_EBP + -0xac,0);
  piVar1 = *(int **)(unaff_EBP + 0x20);
  _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0x20);
  _DAT_006f0bc0 = uVar4;
  if (piVar1 != (int *)0x0) {
    iVar3 = (*(int *)(unaff_EBP + 0x10) * 0x100 + *(int *)(unaff_EBP + 0x14)) * 2 + -0x200;
    FUN_004c656a(iVar3);
    FUN_004c8f7a(iVar3);
    psVar5 = (short *)FUN_004c1ba2(2);
    iVar6 = 8 << ((byte)*(undefined4 *)(unaff_EBP + 0x10) & 0x1f);
    iVar3 = *(int *)(unaff_EBP + 8);
    uVar4 = *(undefined4 *)(unaff_EBP + 0x10);
    piVar1[2] = iVar6 + iVar3;
    *piVar1 = iVar3 - iVar6;
    iVar3 = *(int *)(unaff_EBP + 0xc) + (4 << ((byte)uVar4 & 0x1f));
    piVar1[3] = iVar3;
    piVar1[1] = ((int)*psVar5 - (int)psVar5[2]) + iVar3;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

