
undefined1 FUN_00601a14(void)

{
  int iVar1;
  int *piVar2;
  int extraout_ECX;
  undefined1 uVar3;
  int unaff_EBP;
  int *piStack_18;
  
  FUN_00634c24();
  *(undefined ***)(unaff_EBP + -0x14) = &PTR_LAB_00669c88;
  iVar1 = *(int *)(extraout_ECX + 8);
  *(int **)(unaff_EBP + -0x10) = (int *)(extraout_ECX + 8);
  piStack_18 = (int *)0x601a3a;
  (**(code **)(iVar1 + 4))();
  piStack_18 = *(int **)(extraout_ECX + 4);
  uVar3 = 0;
  piVar2 = (int *)*piStack_18;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  do {
    if (piStack_18 == piVar2) goto LAB_00601a69;
    piStack_18 = (int *)piStack_18[1];
  } while (piStack_18[2] != *(int *)(unaff_EBP + 8));
  *(int ***)(unaff_EBP + 8) = &piStack_18;
  FUN_00602846(unaff_EBP + 8);
  uVar3 = 1;
LAB_00601a69:
  iVar1 = *(int *)(extraout_ECX + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  piStack_18 = (int *)0x601a74;
  (**(code **)(iVar1 + 8))();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

