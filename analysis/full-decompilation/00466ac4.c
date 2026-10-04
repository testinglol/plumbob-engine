
void FUN_00466ac4(void)

{
  int *piVar1;
  int iVar2;
  int extraout_ECX;
  int iVar3;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x1c) = extraout_ECX;
  DAT_006e53d8 = 0;
  iVar2 = *(int *)(extraout_ECX + 4);
  *(undefined4 *)(unaff_EBP + -4) = 3;
  iVar3 = *(int *)(iVar2 + 8);
  *(int *)(unaff_EBP + -0x14) = iVar3;
  while (iVar3 != iVar2) {
    iVar2 = *(int *)(iVar3 + 0x14);
    if (iVar2 != 0) {
      FUN_00467913();
      FUN_006321f0(iVar2);
    }
    FUN_0041674f();
    iVar2 = *(int *)(extraout_ECX + 4);
    iVar3 = *(int *)(unaff_EBP + -0x14);
  }
  FUN_00468c4e();
  *(int *)(unaff_EBP + -0x18) = extraout_ECX + 0x10;
  FUN_00468cce();
  iVar2 = *(int *)(extraout_ECX + 0x2c);
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  piVar1 = (int *)(extraout_ECX + 0x28);
  if (iVar2 - *(int *)(extraout_ECX + 0x28) >> 2 != 0) {
    do {
      if (*(int *)(*piVar1 + *(int *)(unaff_EBP + -0x10) * 4) != 0) {
        (**(code **)(**(int **)(*piVar1 + *(int *)(unaff_EBP + -0x10) * 4) + 4))();
        *(undefined4 *)(*piVar1 + *(int *)(unaff_EBP + -0x10) * 4) = 0;
      }
      iVar2 = *(int *)(extraout_ECX + 0x2c);
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    } while (*(uint *)(unaff_EBP + -0x10) < (uint)(iVar2 - *piVar1 >> 2));
  }
  iVar2 = *(int *)(extraout_ECX + 0x44);
  *(int *)(unaff_EBP + -0x10) = iVar2;
  if (iVar2 != 0) {
    FUN_00431242();
    FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x10));
  }
  iVar2 = *(int *)(extraout_ECX + 0x48);
  *(int *)(unaff_EBP + -0x10) = iVar2;
  if (iVar2 != 0) {
    FUN_00431242();
    FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x10));
  }
  iVar2 = *piVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *(int *)(unaff_EBP + -0x10) = iVar2;
  FUN_0048c4c9();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_00468b8b();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_00468b8b();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00468b2b();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

