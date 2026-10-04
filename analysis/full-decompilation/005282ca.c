
uint FUN_005282ca(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  void *pvVar4;
  int *piVar5;
  uint uVar6;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 uVar7;
  
  FUN_00634c24();
  cVar3 = (**(code **)(*extraout_ECX + 200))();
  if (cVar3 == '\0') {
    (**(code **)(*extraout_ECX + 0x19c))(0,4,1);
    cVar3 = FUN_004cff80();
    if (cVar3 == '\0') {
      uVar7 = 0x5a;
    }
    else {
      uVar7 = 0x6e;
    }
    FUN_004cb1a2(0x2d,uVar7);
    FUN_005e4071(DAT_006f2a90);
    extraout_ECX[0x3e] = 1;
    extraout_ECX[0x3d] = 1;
    pvVar4 = operator_new(0x1f8);
    *(void **)(unaff_EBP + -0x10) = pvVar4;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar4 == (void *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)FUN_0050c27b(10);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x6a] = (int)piVar5;
    uVar6 = 0;
    if (piVar5 != (int *)0x0) {
      uVar6 = (**(code **)(*piVar5 + 0xc))();
      if ((char)uVar6 != '\0') {
        (**(code **)(*(int *)extraout_ECX[0x6a] + 0x60))
                  (0,0,extraout_ECX[0x21] - extraout_ECX[0x1f],
                   extraout_ECX[0x22] - extraout_ECX[0x20]);
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x6a]);
        iVar2 = DAT_006f3b54;
        iVar1 = DAT_006f3b50;
        *(int *)(unaff_EBP + -0x20) = DAT_006f3b50;
        *(int *)(unaff_EBP + -0x18) = iVar1 + 0x14;
        *(int *)(unaff_EBP + -0x1c) = iVar2 + 6;
        *(int *)(unaff_EBP + -0x14) = iVar2 + 6;
        FUN_0050c387(unaff_EBP + -0x20,unaff_EBP + -0x18);
        if (DAT_006f3b9c == (int *)0x0) {
          FUN_005a5631(0x1009,&DAT_006f3b9c,4);
          if (DAT_006f3b9c != (int *)0x0) {
            (**(code **)(*DAT_006f3b9c + 0x68))(DAT_006f2a64);
          }
        }
        if (DAT_006f3ba0 == (int *)0x0) {
          FUN_005a5631(0x100a,&DAT_006f3ba0,4);
          (**(code **)(*DAT_006f3ba0 + 0x68))(DAT_006f2a64);
        }
        if (DAT_006f3ba4 == (int *)0x0) {
          FUN_005a5631(0x100b,&DAT_006f3ba4,4);
          (**(code **)(*DAT_006f3ba4 + 0x68))(DAT_006f2a64);
        }
        goto LAB_00528466;
      }
    }
    uVar6 = uVar6 & 0xffffff00;
  }
  else {
LAB_00528466:
    uVar6 = thunk_FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

