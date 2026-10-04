
undefined4 * FUN_005f80bf(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int *piVar3;
  undefined4 *extraout_ECX;
  int iVar4;
  int unaff_EBP;
  undefined4 *puVar5;
  
  FUN_00634c24();
  uVar1 = *(undefined4 *)(unaff_EBP + 8);
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_00676190;
  extraout_ECX[1] = 0;
  FUN_005b86bd(uVar1);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined1 *)(extraout_ECX + 9) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x25) = 0;
  extraout_ECX[10] = 0x400;
  *(undefined1 *)(extraout_ECX + 0xb) = 0;
  extraout_ECX[0xc] = 0;
  extraout_ECX[0xd] = 1;
  extraout_ECX[0xe] = 1;
  FUN_005d909f();
  uVar1 = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *(undefined1 *)(extraout_ECX + 0x18) = 0;
  extraout_ECX[0x19] = 0;
  extraout_ECX[0x1a] = 0;
  extraout_ECX[0x1e] = 0;
  extraout_ECX[0x1f] = uVar1;
  extraout_ECX[0x28] = 0;
  extraout_ECX[0x29] = 0;
  extraout_ECX[0x2f] = 0;
  *(undefined1 *)(extraout_ECX + 0x30) = 0;
  extraout_ECX[0x31] = 1;
  extraout_ECX[0x32] = 0x100e0;
  extraout_ECX[0x33] = 0;
  FUN_005f8027();
  *extraout_ECX = &PTR_FUN_00676094;
  InterlockedIncrement((LONG *)&DAT_006fed7c);
  puVar5 = extraout_ECX + 0x20;
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  _memset(extraout_ECX + 0x2a,0,0x12);
  pvVar2 = operator_new(0x20);
  *(void **)(unaff_EBP + 8) = pvVar2;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_005ed88f();
  }
  *(undefined1 *)(unaff_EBP + -4) = 2;
  extraout_ECX[0x19] = piVar3;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x20))(FUN_005fa7c3,extraout_ECX);
    (*(code *)**(undefined4 **)extraout_ECX[0x19])(10);
  }
  iVar4 = DAT_006fed08;
  *(int **)(unaff_EBP + -0x14) = &DAT_006fed08;
  *(undefined ***)(unaff_EBP + -0x18) = &PTR_LAB_00669c88;
  (**(code **)(iVar4 + 4))();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  *(undefined4 **)(unaff_EBP + 8) = extraout_ECX;
  FUN_005fcb91(unaff_EBP + -0x24,unaff_EBP + 8);
  iVar4 = DAT_006fed08;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  (**(code **)(iVar4 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

