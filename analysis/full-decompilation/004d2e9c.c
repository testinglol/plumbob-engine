
undefined4 FUN_004d2e9c(void)

{
  int iVar1;
  int *piVar2;
  void *pvVar3;
  undefined4 uVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  if ((extraout_ECX[0x463] - extraout_ECX[0x462] & 0xfffffffcU) == 0) {
    pvVar3 = operator_new(0x124);
    *(void **)(unaff_EBP + -0x14) = pvVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar3 == (void *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = FUN_004caa64(*(undefined4 *)(unaff_EBP + 8));
    }
    iVar1 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
    (**(code **)(iVar1 + 0x20))(uVar4);
  }
  else {
    piVar2 = *(int **)(extraout_ECX[0x463] + -4);
    extraout_ECX[0x463] = extraout_ECX[0x463] + -4;
    *(int **)(unaff_EBP + -0x10) = piVar2;
    (**(code **)(*piVar2 + 0x94))();
    FUN_004cac05(*(undefined4 *)(unaff_EBP + 8));
  }
  FUN_004d40e1(unaff_EBP + -0x10);
  FUN_005ddfdc(1);
  FUN_0057a14d(s_UI_queued_006c7c84);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x10);
}

