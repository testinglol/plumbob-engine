
void FUN_0051a62f(void)

{
  int *piVar1;
  char cVar2;
  void *pvVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  FUN_005a5631(0x100c,unaff_EBP + -0x10,4);
  pvVar3 = operator_new(0x194);
  *(void **)(unaff_EBP + -0x14) = pvVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_005e372a();
  }
  piVar1 = *(int **)(unaff_EBP + -0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x19c) = uVar4;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x68))(DAT_006f2a64);
  }
  (**(code **)(**(int **)(extraout_ECX + 0x19c) + 0x19c))(*(undefined4 *)(unaff_EBP + -0x10),4,1);
  *(undefined1 *)(*(int *)(extraout_ECX + 0x19c) + 0x16b) = 1;
  *(undefined4 *)(*(int *)(extraout_ECX + 0x19c) + 0xf8) = 1;
  *(undefined4 *)(*(int *)(extraout_ECX + 0x19c) + 0xf4) = 1;
  (**(code **)(**(int **)(extraout_ECX + 0x19c) + 0x94))();
  (**(code **)(**(int **)(extraout_ECX + 0x10c) + 0x20))(*(undefined4 *)(extraout_ECX + 0x19c));
  FUN_005e46f0(0);
  FUN_005a5631(0x100d,unaff_EBP + -0x10,4);
  pvVar3 = operator_new(0x194);
  *(void **)(unaff_EBP + -0x14) = pvVar3;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_005e372a();
  }
  piVar1 = *(int **)(unaff_EBP + -0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x1a0) = uVar4;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x68))(DAT_006f2a64);
  }
  (**(code **)(**(int **)(extraout_ECX + 0x1a0) + 0x19c))(*(undefined4 *)(unaff_EBP + -0x10),4,1);
  *(undefined1 *)(*(int *)(extraout_ECX + 0x1a0) + 0x16b) = 1;
  *(undefined4 *)(*(int *)(extraout_ECX + 0x1a0) + 0xf8) = 1;
  *(undefined4 *)(*(int *)(extraout_ECX + 0x1a0) + 0xf4) = 1;
  (**(code **)(**(int **)(extraout_ECX + 0x1a0) + 0x94))();
  (**(code **)(**(int **)(extraout_ECX + 0x10c) + 0x20))(*(undefined4 *)(extraout_ECX + 0x1a0));
  FUN_005e46f0(0);
  FUN_005a5631(0x100f,unaff_EBP + -0x10,4);
  pvVar3 = operator_new(0x194);
  *(void **)(unaff_EBP + -0x14) = pvVar3;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_005e372a();
  }
  piVar1 = *(int **)(unaff_EBP + -0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x1a4) = uVar4;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x68))(DAT_006f2a64);
  }
  (**(code **)(**(int **)(extraout_ECX + 0x1a4) + 0x19c))(*(undefined4 *)(unaff_EBP + -0x10),4,1);
  *(undefined1 *)(*(int *)(extraout_ECX + 0x1a4) + 0x16b) = 1;
  *(undefined4 *)(*(int *)(extraout_ECX + 0x1a4) + 0xf8) = 1;
  *(undefined4 *)(*(int *)(extraout_ECX + 0x1a4) + 0xf4) = 1;
  (**(code **)(**(int **)(extraout_ECX + 0x1a4) + 0x94))();
  (**(code **)(**(int **)(extraout_ECX + 0x10c) + 0x20))(*(undefined4 *)(extraout_ECX + 0x1a4));
  FUN_005e46f0(0);
  if ((*(byte *)(DAT_006e486c + 0x66) & 0x40) == 0) {
    piVar1 = *(int **)(extraout_ECX + 0x1a4);
    if ((char)piVar1[0x5a] != '\0') {
      *(undefined1 *)(piVar1 + 0x5a) = 0;
      (**(code **)(*piVar1 + 0x168))();
    }
  }
  FUN_005a5631(0x100e,unaff_EBP + -0x10,4);
  pvVar3 = operator_new(0x194);
  *(void **)(unaff_EBP + -0x14) = pvVar3;
  *(undefined4 *)(unaff_EBP + -4) = 3;
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_005e372a();
  }
  piVar1 = *(int **)(unaff_EBP + -0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x1a8) = uVar4;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x68))(DAT_006f2a64);
  }
  (**(code **)(**(int **)(extraout_ECX + 0x1a8) + 0x19c))(*(undefined4 *)(unaff_EBP + -0x10),4,1);
  *(undefined1 *)(*(int *)(extraout_ECX + 0x1a8) + 0x16b) = 1;
  *(undefined4 *)(*(int *)(extraout_ECX + 0x1a8) + 0xf8) = 1;
  *(undefined4 *)(*(int *)(extraout_ECX + 0x1a8) + 0xf4) = 1;
  (**(code **)(**(int **)(extraout_ECX + 0x1a8) + 0x94))();
  (**(code **)(**(int **)(extraout_ECX + 0x10c) + 0x20))(*(undefined4 *)(extraout_ECX + 0x1a8));
  FUN_005e46f0(1);
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x98) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 4;
  uVar4 = FUN_0041532c(9,unaff_EBP + -0x98,0);
  cVar2 = FUN_004fff98(0xf0,uVar4);
  if (cVar2 != '\0') {
    FUN_00471655(unaff_EBP + -0x18);
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_0046fc87(unaff_EBP + -0x20,0);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    uVar4 = FUN_0046fc7a();
    FUN_005d4956(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    FUN_005dd9c8(unaff_EBP + -0x2c);
    *(undefined1 *)(unaff_EBP + -4) = 6;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_0042004f();
    FUN_0046fc87(unaff_EBP + -0x20,0);
    *(undefined1 *)(unaff_EBP + -4) = 8;
    uVar4 = FUN_0046fc7a();
    FUN_005d4956(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 9;
    FUN_005dd9c8(unaff_EBP + -0x2c);
    *(undefined1 *)(unaff_EBP + -4) = 8;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_0042004f();
    FUN_0046fc87(unaff_EBP + -0x20,0);
    *(undefined1 *)(unaff_EBP + -4) = 10;
    uVar4 = FUN_0046fc7a();
    FUN_005d4956(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0xb;
    FUN_005dd9c8(unaff_EBP + -0x2c);
    *(undefined1 *)(unaff_EBP + -4) = 10;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_0042004f();
    FUN_0046fc87(unaff_EBP + -0x20,0);
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    uVar4 = FUN_0046fc7a();
    FUN_005d4956(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 0xd;
    FUN_005dd9c8(unaff_EBP + -0x2c);
    *(undefined1 *)(unaff_EBP + -4) = 0xc;
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 5;
    FUN_0042004f();
    *(undefined1 *)(unaff_EBP + -4) = 4;
    FUN_0042004f();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

