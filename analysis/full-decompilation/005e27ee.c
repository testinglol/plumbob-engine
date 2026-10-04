
undefined1 FUN_005e27ee(void)

{
  int iVar1;
  char cVar2;
  void *pvVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(undefined4 **)(extraout_ECX + 0x4c) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(extraout_ECX + 0x4c))(1);
    *(undefined4 *)(extraout_ECX + 0x4c) = 0;
  }
  pvVar3 = operator_new(0x2c);
  *(void **)(unaff_EBP + -0x10) = pvVar3;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00606233(*(undefined4 *)(unaff_EBP + 8));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x4c) = uVar4;
  cVar2 = FUN_006062d5();
  if (cVar2 == '\0') {
    if (*(undefined4 **)(extraout_ECX + 0x4c) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(extraout_ECX + 0x4c))(1);
    }
    *(undefined4 *)(extraout_ECX + 0x4c) = 0;
    *(undefined1 *)(extraout_ECX + 4) = 0;
  }
  else {
    iVar1 = *(int *)(extraout_ECX + 0x4c);
    *(undefined1 *)(extraout_ECX + 4) = 1;
    *(undefined4 *)(extraout_ECX + 0x14) = *(undefined4 *)(iVar1 + 0x18);
    *(undefined4 *)(extraout_ECX + 0x18) = *(undefined4 *)(iVar1 + 0x1c);
    *(undefined4 *)(extraout_ECX + 0x1c) = *(undefined4 *)(iVar1 + 0x20);
    *(undefined4 *)(extraout_ECX + 0x20) = *(undefined4 *)(iVar1 + 0x24);
    piVar5 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
    puVar6 = (undefined4 *)(**(code **)(*piVar5 + 0xc))(unaff_EBP + -0x14);
    *(undefined4 *)(extraout_ECX + 8) = *puVar6;
    uVar4 = puVar6[1];
    *(undefined4 *)(extraout_ECX + 0x44) = 0;
    *(undefined4 *)(extraout_ECX + 0xc) = uVar4;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined1 *)(extraout_ECX + 4);
}

