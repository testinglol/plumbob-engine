
undefined4 FUN_005f4e36(void)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar1 = (**(code **)(*extraout_ECX + 200))();
  if (cVar1 == '\0') {
    (**(code **)(*extraout_ECX + 0x174))(1,0);
    iVar2 = (**(code **)(*(int *)extraout_ECX[0x45] + 0x58))();
    extraout_ECX[0x3c] = iVar2 + 3;
    *(int *)(unaff_EBP + -0x10) = extraout_ECX[0x3a] << 1;
    extraout_ECX[0x40] = (int)(float)*(int *)(unaff_EBP + -0x10);
    pvVar3 = operator_new(0x158);
    *(void **)(unaff_EBP + -0x10) = pvVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar3 == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_005f65e3();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x38] = iVar2;
    if (iVar2 != 0) {
      FUN_004cb1a2(1,extraout_ECX[0x3c] * extraout_ECX[0x3a]);
      (**(code **)(*(int *)extraout_ECX[0x38] + 0x1b4))(2);
      if (extraout_ECX[0x39] != 0) {
        (**(code **)(*(int *)extraout_ECX[0x38] + 0x1b8))(extraout_ECX[0x39],0);
      }
      FUN_004cb21d((extraout_ECX[0x21] - *(int *)(extraout_ECX[0x39] + 0x20)) - extraout_ECX[0x1f],0
                  );
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x38]);
      if (extraout_ECX[0x3a] < extraout_ECX[0x36] - extraout_ECX[0x35] >> 2) {
        (**(code **)(*(int *)extraout_ECX[0x38] + 0x94))();
        (**(code **)(*(int *)extraout_ECX[0x38] + 0x1ac))(0);
        (**(code **)(*(int *)extraout_ECX[0x38] + 0x1b0))
                  ((extraout_ECX[0x36] - extraout_ECX[0x35] >> 2) - extraout_ECX[0x3a]);
        (**(code **)(*(int *)extraout_ECX[0x38] + 0x1a8))(extraout_ECX[0x3b]);
        (**(code **)(*(int *)extraout_ECX[0x38] + 0x1d4))(extraout_ECX[0x3a]);
      }
      else {
        (**(code **)(*(int *)extraout_ECX[0x38] + 0x98))();
      }
    }
    FUN_004ec1a7(extraout_ECX[0x3c] * extraout_ECX[0x3a]);
    extraout_ECX[0x3b] = 0;
    FUN_005f50ff();
    uVar4 = 1;
  }
  else {
    uVar4 = FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

