
uint FUN_00513322(void)

{
  int iVar1;
  char cVar2;
  void *pvVar3;
  int *piVar4;
  uint uVar5;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 uVar6;
  
  FUN_00634c24();
  cVar2 = (**(code **)(*extraout_ECX + 200))();
  if (cVar2 == '\0') {
    extraout_ECX[0x69] = DAT_006f2a94;
    (**(code **)(*extraout_ECX + 0x19c))(0,4,1);
    cVar2 = FUN_004cff80();
    if (cVar2 == '\0') {
      FUN_004cb1a2(100,0x14);
    }
    else {
      if (*(char *)(DAT_006e486c + 100) == '\x13') {
        uVar6 = 0x1e;
      }
      else {
        uVar6 = 0x19;
      }
      FUN_004cb1a2(100,uVar6);
      DAT_006f38bc = (extraout_ECX[0x22] - extraout_ECX[0x20]) + -6;
    }
    FUN_005e4071(extraout_ECX[0x69]);
    extraout_ECX[0x3e] = 2;
    extraout_ECX[0x3d] = 1;
    pvVar3 = operator_new(0x1f8);
    *(void **)(unaff_EBP + -0x10) = pvVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar3 == (void *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)FUN_0050c27b(10);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x6c] = (int)piVar4;
    uVar5 = 0;
    if (piVar4 != (int *)0x0) {
      uVar5 = (**(code **)(*piVar4 + 0xc))();
      if ((char)uVar5 != '\0') {
        (**(code **)(*(int *)extraout_ECX[0x6c] + 0x60))
                  (0,0,extraout_ECX[0x21] - extraout_ECX[0x1f],
                   extraout_ECX[0x22] - extraout_ECX[0x20]);
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x6c]);
        iVar1 = DAT_006f38b8 + -0x14;
        *(int *)(unaff_EBP + -0x18) = DAT_006f38b8 + 0x3d;
        *(int *)(unaff_EBP + -0x20) = iVar1;
        iVar1 = DAT_006f38bc;
        *(int *)(unaff_EBP + -0x1c) = DAT_006f38bc;
        *(int *)(unaff_EBP + -0x14) = iVar1;
        FUN_0050c387(unaff_EBP + -0x20,unaff_EBP + -0x18);
        FUN_00513a51();
        goto LAB_0051346f;
      }
    }
    uVar5 = uVar5 & 0xffffff00;
  }
  else {
LAB_0051346f:
    uVar5 = thunk_FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

