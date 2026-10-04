
void FUN_00415c5b(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int iVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  pvVar1 = operator_new(0x88);
  *(void **)(unaff_EBP + -0x10) = pvVar1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00479161(0x40);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x18) = uVar2;
  *(undefined4 *)(extraout_ECX + 0x1c) = uVar2;
  pvVar1 = operator_new(0x1ac);
  *(void **)(unaff_EBP + -0x10) = pvVar1;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0046cee2();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x20) = uVar2;
  pvVar1 = operator_new(0x110);
  *(void **)(unaff_EBP + -0x10) = pvVar1;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0043f426(*(undefined4 *)(extraout_ECX + 0x20));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x14) = uVar2;
  FUN_0046cfd5(uVar2);
  FUN_004405c7(*(undefined4 *)(DAT_006e486c + 0x28));
  uVar2 = FUN_00425db3(0);
  *(undefined4 *)(extraout_ECX + 0x10) = uVar2;
  pvVar1 = operator_new(0x4c);
  *(void **)(unaff_EBP + -0x10) = pvVar1;
  *(undefined4 *)(unaff_EBP + -4) = 3;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00466964(extraout_ECX);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x24) = uVar2;
  pvVar1 = operator_new(0x10);
  *(void **)(unaff_EBP + -0x10) = pvVar1;
  *(undefined4 *)(unaff_EBP + -4) = 4;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0046142b();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x68) = uVar2;
  FUN_0046146f(8);
  pvVar1 = operator_new(0x10);
  *(void **)(unaff_EBP + -0x10) = pvVar1;
  *(undefined4 *)(unaff_EBP + -4) = 5;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0046142b();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x6c) = uVar2;
  FUN_0046146f(8);
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x7c) = &PTR_FUN_0066643c;
  iVar3 = *(int *)(DAT_006e486c + 0x28);
  *(undefined4 *)(unaff_EBP + -4) = 6;
  iVar3 = FUN_00470383(*(undefined4 *)(iVar3 + 0x2c),0x1f9,0);
  if (iVar3 == 0) {
    uVar2 = FUN_004705f2(1,0xffffffff);
    FUN_00461575(uVar2);
    uVar2 = FUN_004705f2(2,0xffffffff);
    FUN_00461575(uVar2);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

