
undefined4 * FUN_005f7ebe(void)

{
  void *pvVar1;
  int *piVar2;
  undefined4 *extraout_ECX;
  int iVar3;
  int unaff_EBP;
  undefined4 *puVar4;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_00676190;
  extraout_ECX[1] = 0;
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_005d48d9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  extraout_ECX[8] = 0;
  *(undefined1 *)(extraout_ECX + 9) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x25) = 0;
  extraout_ECX[10] = 0x400;
  *(undefined1 *)(extraout_ECX + 0xb) = 0;
  extraout_ECX[0xc] = 0;
  extraout_ECX[0xd] = 1;
  extraout_ECX[0xe] = 1;
  FUN_005d909f();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *(undefined1 *)(extraout_ECX + 0x18) = 0;
  extraout_ECX[0x19] = 0;
  extraout_ECX[0x1a] = 0;
  extraout_ECX[0x1e] = 0;
  extraout_ECX[0x1f] = 0;
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
  puVar4 = extraout_ECX + 0x20;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  _memset(extraout_ECX + 0x2a,0,0x12);
  pvVar1 = operator_new(0x20);
  *(void **)(unaff_EBP + -0x10) = pvVar1;
  *(undefined1 *)(unaff_EBP + -4) = 3;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_005ed88f();
  }
  *(undefined1 *)(unaff_EBP + -4) = 2;
  extraout_ECX[0x19] = piVar2;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x20))(FUN_005fa7c3,extraout_ECX);
    (*(code *)**(undefined4 **)extraout_ECX[0x19])(10);
  }
  iVar3 = DAT_006fed08;
  *(int **)(unaff_EBP + -0x18) = &DAT_006fed08;
  *(undefined ***)(unaff_EBP + -0x1c) = &PTR_LAB_00669c88;
  (**(code **)(iVar3 + 4))();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_005fcb91(unaff_EBP + -0x28,unaff_EBP + -0x10);
  iVar3 = DAT_006fed08;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  (**(code **)(iVar3 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

