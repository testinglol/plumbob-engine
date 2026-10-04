
void FUN_004cc877(void)

{
  int iVar1;
  int *piVar2;
  int extraout_ECX;
  int unaff_EBP;
  int iVar3;
  undefined4 uVar4;
  
  FUN_00634c24();
  piVar2 = operator_new(0x198);
  *(int **)(unaff_EBP + -0x10) = piVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_005e372a();
    piVar2[0x65] = extraout_ECX;
    *piVar2 = (int)&PTR_FUN_00668b70;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(int **)(extraout_ECX + 0x20) = piVar2;
  if (piVar2 == (int *)0x0) goto LAB_004cc9b4;
  if (*(int *)(unaff_EBP + 8) == 0) {
    if (*(int *)(unaff_EBP + 0xc) == 1) {
      iVar3 = *piVar2;
      uVar4 = 1;
    }
    else {
      if (*(int *)(unaff_EBP + 0xc) != 4) goto LAB_004cc91e;
      iVar3 = *piVar2;
      uVar4 = 4;
    }
    uVar4 = FUN_004096c2(uVar4,1);
    (**(code **)(iVar3 + 0x19c))(uVar4);
  }
  else {
    (**(code **)(*piVar2 + 0x19c))
              (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc),1);
    *(undefined1 *)(*(int *)(extraout_ECX + 0x20) + 0x16b) = 1;
  }
LAB_004cc91e:
  *(undefined4 *)(*(int *)(extraout_ECX + 0x20) + 0xf4) = 1;
  *(undefined4 *)(*(int *)(extraout_ECX + 0x20) + 0xf8) = 1;
  iVar1 = DAT_006d74f0;
  iVar3 = *(int *)(extraout_ECX + 0x20);
  if (DAT_006d74f0 == 0) {
    *(undefined4 *)(iVar3 + 0x154) = 0;
  }
  else {
    *(undefined4 *)(iVar3 + 0x154) = 6;
    *(int *)(iVar3 + 0x158) = iVar1;
  }
  *(undefined1 *)(iVar3 + 0x16c) = 0;
  *(undefined4 *)(*(int *)(extraout_ECX + 0x20) + 0xa4) = 0;
  (**(code **)(**(int **)(extraout_ECX + 0x20) + 0x98))();
  FUN_005d48d9();
  piVar2 = DAT_006fe8bc;
  iVar3 = *(int *)(extraout_ECX + 0x1c);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  piVar2 = (int *)(**(code **)(*piVar2 + 4))();
  (**(code **)(*piVar2 + 0x7c))(iVar3,iVar3 >> 0x1f,unaff_EBP + -0x1c);
  FUN_005dd9c8(unaff_EBP + -0x1c);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
LAB_004cc9b4:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

