
void FUN_005e4c49(void)

{
  int iVar1;
  char cVar2;
  void *pvVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int *extraout_ECX;
  int iVar7;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar2 = (**(code **)(*extraout_ECX + 200))();
  if (cVar2 == '\0') {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    pvVar3 = operator_new(0x194);
    *(void **)(unaff_EBP + -0x18) = pvVar3;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar3 == (void *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)FUN_005e372a();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    extraout_ECX[0x35] = (int)piVar4;
    (**(code **)(*piVar4 + 0x19c))(extraout_ECX[0x37],6,1);
    *(undefined4 *)(extraout_ECX[0x35] + 0xf8) = 2;
    *(undefined1 *)(extraout_ECX[0x35] + 0x16f) = 1;
    (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x35]);
    iVar7 = *(int *)(extraout_ECX[0x35] + 0x88) - *(int *)(extraout_ECX[0x35] + 0x80);
    if (extraout_ECX[0x14] == extraout_ECX[0x13]) {
      iVar6 = *(int *)(unaff_EBP + -0x14);
    }
    else {
      uVar5 = (**(code **)(*(int *)extraout_ECX[0x36] + 0x58))();
      *(undefined4 *)(unaff_EBP + -0x10) = uVar5;
      iVar6 = extraout_ECX[0x14];
      iVar1 = extraout_ECX[0x13];
      *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)extraout_ECX[0x36];
      uVar5 = FUN_004096c2(iVar6 - iVar1);
      iVar6 = (**(code **)(*(int *)(unaff_EBP + -0x14) + 0x68))(uVar5);
      if (0 < iVar6) {
        iVar6 = iVar6 + 6;
      }
    }
    if (iVar7 <= *(int *)(unaff_EBP + -0x10)) {
      iVar7 = *(int *)(unaff_EBP + -0x10);
    }
    FUN_004cb1a2((*(int *)(extraout_ECX[0x35] + 0x84) - *(int *)(extraout_ECX[0x35] + 0x7c)) + iVar6
                 ,iVar7);
    FUN_005dbf32();
  }
  else {
    FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

