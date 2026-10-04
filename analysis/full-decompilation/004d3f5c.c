
void FUN_004d3f5c(void)

{
  void *pvVar1;
  int iVar2;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(char *)(unaff_EBP + 8) == '\0') {
    if (extraout_ECX[0x45a] != 0) {
      FUN_005da4c7(extraout_ECX[0x45a]);
      extraout_ECX[0x45a] = 0;
    }
  }
  else if ((int *)extraout_ECX[0x45a] == (int *)0x0) {
    pvVar1 = operator_new(0x124);
    *(void **)(unaff_EBP + 8) = pvVar1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar1 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_004d59d4();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x45a] = iVar2;
    if (iVar2 != 0) {
      (**(code **)(*extraout_ECX + 0x20))(iVar2);
      FUN_005ddfdc(1);
    }
  }
  else {
    (**(code **)(*(int *)extraout_ECX[0x45a] + 0x94))();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

