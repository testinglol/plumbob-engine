
undefined4 FUN_005dad1c(void)

{
  void *pvVar1;
  int *piVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(extraout_ECX + 0x1b8) == 0) {
    pvVar1 = operator_new(0xfc);
    *(void **)(unaff_EBP + -0x10) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar1 == (void *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)FUN_005e85d4();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int **)(extraout_ECX + 0x1b8) = piVar2;
    if (piVar2 == (int *)0x0) {
      uVar3 = 0;
      goto LAB_005dadab;
    }
    (**(code **)(*piVar2 + 4))();
    uVar3 = FUN_005d4956(s_Your_Message_Here_006d7328);
    piVar2 = *(int **)(extraout_ECX + 0x1b8);
    *(undefined4 *)(unaff_EBP + -4) = 1;
    (**(code **)(*piVar2 + 0x19c))(uVar3);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  (**(code **)(**(int **)(extraout_ECX + 0x1b8) + 4))();
  uVar3 = *(undefined4 *)(extraout_ECX + 0x1b8);
LAB_005dadab:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

