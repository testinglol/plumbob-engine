
undefined1 FUN_00514110(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *extraout_ECX;
  int iVar6;
  int unaff_EBP;
  int iVar7;
  int iStack_c0;
  
  FUN_00634c24();
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0xb8) = &PTR_FUN_0066643c;
  iStack_c0 = unaff_EBP + -0xb8;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar2 = FUN_0041532c(9);
  FUN_004fff98(0x91,uVar2);
  iStack_c0 = 0x51416c;
  FUN_00471655();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 **)(unaff_EBP + -0x14) = &DAT_0066c364;
  *(int **)(unaff_EBP + -0x18) = extraout_ECX + 0x38;
  do {
    iStack_c0 = 0x51418a;
    pvVar3 = operator_new(0x194);
    *(void **)(unaff_EBP + -0x20) = pvVar3;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (pvVar3 == (void *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)FUN_005e372a();
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (piVar4 != (int *)0x0) {
      iStack_c0 = unaff_EBP + -0x1c;
      FUN_005a5631(**(undefined4 **)(unaff_EBP + -0x14));
      if (*(int **)(unaff_EBP + -0x1c) != (int *)0x0) {
        iStack_c0 = 0x5141d4;
        (**(code **)(**(int **)(unaff_EBP + -0x1c) + 0x68))();
      }
      iStack_c0 = 4;
      (**(code **)(*piVar4 + 0x19c))(*(undefined4 *)(unaff_EBP + -0x1c));
      piVar4[0x3e] = 0;
      piVar4[0x3d] = 0;
      FUN_005e4071(DAT_006f2a98);
      *(undefined1 *)((int)piVar4 + 0x16b) = 1;
      FUN_0046fc87(unaff_EBP + -0x44,0);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      uVar2 = FUN_0046fc7a();
      puVar5 = (undefined4 *)FUN_00500249(unaff_EBP + -0x4c,uVar2);
      FUN_004cb21d(*puVar5,puVar5[1]);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
      FUN_0046fc87(unaff_EBP + -0x30,0);
      *(undefined1 *)(unaff_EBP + -4) = 4;
      uVar2 = FUN_0046fc7a();
      FUN_005d4956(uVar2);
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_005dd9c8(unaff_EBP + -0x3c);
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
      (**(code **)(*extraout_ECX + 0x20))(piVar4);
      **(undefined4 **)(unaff_EBP + -0x18) = piVar4;
    }
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 4;
    *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 4;
  } while (*(int *)(unaff_EBP + -0x14) < 0x66c36d);
  *(undefined4 **)(unaff_EBP + -0x14) = &DAT_0066c370;
  *(int **)(unaff_EBP + -0x18) = extraout_ECX + 0x3b;
  do {
    iStack_c0 = 0x5142c5;
    pvVar3 = operator_new(0x194);
    *(void **)(unaff_EBP + -0x20) = pvVar3;
    *(undefined1 *)(unaff_EBP + -4) = 6;
    if (pvVar3 == (void *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)FUN_005e372a();
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    if (piVar4 != (int *)0x0) {
      iStack_c0 = unaff_EBP + -0x1c;
      FUN_005a5631(**(undefined4 **)(unaff_EBP + -0x14));
      if (*(int **)(unaff_EBP + -0x1c) != (int *)0x0) {
        iStack_c0 = 0x51430f;
        (**(code **)(**(int **)(unaff_EBP + -0x1c) + 0x68))();
      }
      iStack_c0 = 4;
      (**(code **)(*piVar4 + 0x19c))(*(undefined4 *)(unaff_EBP + -0x1c));
      piVar4[0x3e] = 2;
      piVar4[0x3d] = 0;
      FUN_005e4071(DAT_006f2a98);
      *(undefined1 *)((int)piVar4 + 0x16b) = 1;
      FUN_0046fc87(unaff_EBP + -0x30,0);
      *(undefined1 *)(unaff_EBP + -4) = 7;
      uVar2 = FUN_0046fc7a();
      puVar5 = (undefined4 *)FUN_00500249(unaff_EBP + -0x4c,uVar2);
      FUN_004cb21d(*puVar5,puVar5[1]);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
      FUN_0046fc87(unaff_EBP + -0x44,0);
      *(undefined1 *)(unaff_EBP + -4) = 8;
      uVar2 = FUN_0046fc7a();
      FUN_005d4956(uVar2);
      *(undefined1 *)(unaff_EBP + -4) = 9;
      FUN_005dd9c8(unaff_EBP + -0x3c);
      *(undefined1 *)(unaff_EBP + -4) = 8;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
      (**(code **)(*extraout_ECX + 0x20))(piVar4);
      **(undefined4 **)(unaff_EBP + -0x18) = piVar4;
    }
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 4;
    *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 4;
  } while (*(int *)(unaff_EBP + -0x14) < 0x66c379);
  iVar6 = 5;
  iVar7 = *(int *)(extraout_ECX[0x38] + 0x84);
  piVar4 = extraout_ECX + 0x39;
  do {
    if (iVar7 < *(int *)(*piVar4 + 0x84)) {
      iVar7 = *(int *)(*piVar4 + 0x84);
    }
    piVar4 = piVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  *(int **)(unaff_EBP + -0x20) = &iStack_c0;
  iStack_c0 = iVar7;
  cVar1 = FUN_0051449d(unaff_EBP + -0x28);
  if (cVar1 != '\0') {
    *(int **)(unaff_EBP + -0x20) = &iStack_c0;
    iStack_c0 = iVar7;
    cVar1 = FUN_00514f95(unaff_EBP + -0x28);
    if (cVar1 != '\0') {
      *(int **)(unaff_EBP + -0x20) = &iStack_c0;
      iStack_c0 = iVar7;
      cVar1 = FUN_005154a3(unaff_EBP + -0x28);
      *(undefined1 *)(unaff_EBP + -0xd) = 0;
      if (cVar1 != '\0') {
        *(undefined1 *)(unaff_EBP + -0xd) = 1;
      }
      goto LAB_00514471;
    }
  }
  *(undefined1 *)(unaff_EBP + -0xd) = 0;
LAB_00514471:
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0042004f();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined1 *)(unaff_EBP + -0xd);
}

