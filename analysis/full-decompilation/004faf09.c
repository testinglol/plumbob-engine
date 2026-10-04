
void FUN_004faf09(void)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  int *piVar4;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 uVar5;
  
  FUN_00634c24();
  if (*(int *)(extraout_ECX + 0x88) != 0) {
    FUN_004ce493();
    uVar5 = *(undefined4 *)(*(int *)(extraout_ECX + 0x88) + 0xdc);
    (**(code **)(*DAT_006fe8bc + 0x18))(uVar5);
    FUN_005da4c7(uVar5);
    uVar5 = *(undefined4 *)(extraout_ECX + 0x88);
    (**(code **)(*DAT_006fe8bc + 0x18))(uVar5);
    FUN_005da4c7(uVar5);
    pvVar3 = operator_new(0x110);
    *(void **)(unaff_EBP + -0x10) = pvVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar3 == (void *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)FUN_00509a74(*(undefined4 *)(extraout_ECX + 0xb0));
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int **)(extraout_ECX + 0x88) = piVar4;
    if (piVar4 != (int *)0x0) {
      iVar1 = *(int *)(extraout_ECX + 0x84);
      uVar5 = *(undefined4 *)(iVar1 + 0x7c);
      uVar2 = *(undefined4 *)(iVar1 + 0x84);
      iVar1 = *(int *)(iVar1 + 0x88);
      *(int *)(unaff_EBP + -0x1c) = iVar1 + -100;
      (**(code **)(*piVar4 + 0x60))(uVar5,*(undefined4 *)(unaff_EBP + -0x1c),uVar2,iVar1);
      (**(code **)(**(int **)(extraout_ECX + 0x84) + 0x20))(*(undefined4 *)(extraout_ECX + 0x88));
      FUN_0050a2a2();
    }
    FUN_004ce503(*(undefined4 *)(extraout_ECX + 0x88));
    if (*(int *)(extraout_ECX + 0xb0) != 0) {
      FUN_004cfe14(1,1);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

