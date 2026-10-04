
undefined1 FUN_005e6862(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined1 uVar6;
  int unaff_EBP;
  char *pcVar7;
  undefined4 uVar8;
  
  FUN_00634c24();
  FUN_005d48d9();
  iVar1 = *(int *)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(iVar1 + 0x4c) == 0) {
    pcVar7 = s_The_cheat_help_window_ptr_is_NUL_006d76b4;
LAB_005e6907:
    FUN_005d4bbf(pcVar7);
    uVar6 = 0;
  }
  else {
    iVar2 = *(int *)(unaff_EBP + 8);
    if ((*(int *)(iVar2 + 8) - *(int *)(iVar2 + 4)) / 0xc == 1) {
      uVar8 = 0;
    }
    else {
      if ((*(int *)(iVar2 + 8) - *(int *)(iVar2 + 4)) / 0xc != 2) {
        pcVar7 = s_Usage__help__or_help__partial_co_006d7678;
        goto LAB_005e6907;
      }
      uVar8 = *(undefined4 *)(*(int *)(iVar2 + 4) + 0xc);
    }
    FUN_0060710d(uVar8);
    piVar4 = (int *)(**(code **)(*DAT_006fe8bc + 0x1c))();
    piVar3 = DAT_006fe8bc;
    uVar8 = *(undefined4 *)(iVar1 + 0x4c);
    uVar5 = (**(code **)(*piVar4 + 8))(uVar8);
    (**(code **)(*piVar3 + 0x18))(uVar5);
    FUN_005daa44(uVar5,uVar8);
    *(undefined1 *)(iVar2 + 0x28) = 0;
    uVar6 = 1;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

