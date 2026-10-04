
int * FUN_0048461b(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  void *pvVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar7;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00493384();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  extraout_ECX[1] = *(int *)(unaff_EBP + 8);
  pvVar4 = operator_new(0x30);
  *extraout_ECX = (int)pvVar4;
  _memset(pvVar4,0x30,0);
  puVar5 = operator_new(0x60);
  *(undefined4 **)(unaff_EBP + 8) = puVar5;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    FUN_004907cd();
    puVar5[0x13] = 0;
    puVar5[0x14] = 1;
    *puVar5 = &PTR_FUN_00667ad4;
  }
  puVar2 = (undefined4 *)*extraout_ECX;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *puVar2 = puVar5;
  puVar5 = operator_new(0x60);
  *(undefined4 **)(unaff_EBP + 8) = puVar5;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    FUN_004907cd();
    puVar5[0x14] = 0xffffffff;
    puVar5[0x13] = 0;
    *puVar5 = &PTR_FUN_00667ad4;
  }
  iVar3 = *extraout_ECX;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 **)(iVar3 + 4) = puVar5;
  pvVar4 = operator_new(0x74);
  *(void **)(unaff_EBP + 8) = pvVar4;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  if (pvVar4 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_0048aefd(extraout_ECX + 2);
  }
  iVar3 = *extraout_ECX;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(iVar3 + 8) = uVar6;
  pvVar4 = operator_new(100);
  *(void **)(unaff_EBP + 8) = pvVar4;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  if (pvVar4 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00489f7b(extraout_ECX + 2);
  }
  iVar3 = *extraout_ECX;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(iVar3 + 0xc) = uVar6;
  pvVar4 = operator_new(0x68);
  *(void **)(unaff_EBP + 8) = pvVar4;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  if (pvVar4 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00488704(extraout_ECX + 2);
  }
  iVar3 = *extraout_ECX;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(iVar3 + 0x14) = uVar6;
  pvVar4 = operator_new(0x58);
  *(void **)(unaff_EBP + 8) = pvVar4;
  *(undefined1 *)(unaff_EBP + -4) = 6;
  if (pvVar4 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00484d46();
  }
  iVar3 = *extraout_ECX;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(iVar3 + 0x10) = uVar6;
  pvVar4 = operator_new(0x108);
  *(void **)(unaff_EBP + 8) = pvVar4;
  *(undefined1 *)(unaff_EBP + -4) = 7;
  if (pvVar4 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_0048c740();
  }
  iVar3 = *extraout_ECX;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(iVar3 + 0x18) = uVar6;
  pvVar4 = operator_new(0xb0);
  *(void **)(unaff_EBP + 8) = pvVar4;
  *(undefined1 *)(unaff_EBP + -4) = 8;
  if (pvVar4 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_004858b3(extraout_ECX + 2);
  }
  iVar3 = *extraout_ECX;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(iVar3 + 0x1c) = uVar6;
  pvVar4 = operator_new(0x44);
  *(void **)(unaff_EBP + 8) = pvVar4;
  *(undefined1 *)(unaff_EBP + -4) = 9;
  if (pvVar4 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_004924b8();
  }
  iVar3 = *extraout_ECX;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(iVar3 + 0x20) = uVar6;
  pvVar4 = operator_new(0x5c);
  *(void **)(unaff_EBP + 8) = pvVar4;
  *(undefined1 *)(unaff_EBP + -4) = 10;
  if (pvVar4 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_0048ea57(extraout_ECX + 2);
  }
  iVar3 = *extraout_ECX;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(iVar3 + 0x24) = uVar6;
  pvVar4 = operator_new(0x58);
  *(void **)(unaff_EBP + 8) = pvVar4;
  *(undefined1 *)(unaff_EBP + -4) = 0xb;
  if (pvVar4 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_004972d2(extraout_ECX + 2);
  }
  iVar3 = *extraout_ECX;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(iVar3 + 0x28) = uVar6;
  pvVar4 = operator_new(0x48);
  *(void **)(unaff_EBP + 8) = pvVar4;
  *(undefined1 *)(unaff_EBP + -4) = 0xc;
  if (pvVar4 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_00484920();
  }
  iVar3 = *extraout_ECX;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  iVar7 = 0;
  *(undefined4 *)(unaff_EBP + 8) = 0xc;
  *(undefined4 *)(iVar3 + 0x2c) = uVar6;
  do {
    if (*(int **)(iVar7 + *extraout_ECX) != (int *)0x0) {
      (**(code **)(**(int **)(iVar7 + *extraout_ECX) + 0x34))();
    }
    iVar7 = iVar7 + 4;
    piVar1 = (int *)(unaff_EBP + 8);
    *piVar1 = *piVar1 + -1;
  } while (*piVar1 != 0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

