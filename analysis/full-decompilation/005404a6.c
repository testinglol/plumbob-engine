
undefined4 * FUN_005404a6(void)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar5;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *extraout_ECX = &PTR_FUN_0066f3d8;
  extraout_ECX[1] = 0;
  pvVar2 = operator_new(0x60);
  *(void **)(unaff_EBP + -0x18) = pvVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    *(undefined1 *)(unaff_EBP + -0x10) = 0;
    *(undefined1 *)(unaff_EBP + -0xf) = 0;
    *(undefined1 *)(unaff_EBP + -0xe) = 0;
    *(undefined4 *)(unaff_EBP + -0x14) = 1;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    iVar3 = FUN_0053c1f5(unaff_EBP + -0x10,0);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  extraout_ECX[10] = iVar3;
  if (iVar3 != 0) {
    *(int *)(iVar3 + 0x20) = *(int *)(iVar3 + 0x20) + 1;
  }
  puVar5 = extraout_ECX + 4;
  *(undefined4 *)(unaff_EBP + -0x14) = 2;
  do {
    puVar4 = operator_new(0xc);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[2] = 0;
    }
    puVar5[-2] = puVar4;
    puVar4 = operator_new(0xc);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[2] = 0;
    }
    *puVar5 = puVar4;
    puVar5 = puVar5 + 1;
    piVar1 = (int *)(unaff_EBP + -0x14);
    *piVar1 = *piVar1 + -1;
  } while (*piVar1 != 0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  extraout_ECX[0xb] = 0;
  extraout_ECX[0xf] = 1;
  extraout_ECX[0xe] = 1;
  extraout_ECX[0x11] = 1;
  extraout_ECX[0x10] = 1;
  extraout_ECX[0xc] = 0;
  extraout_ECX[0xd] = 0;
  return extraout_ECX;
}

