
void FUN_005270cb(void)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  void *pvVar7;
  undefined4 uVar8;
  int iVar9;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar2 = (**(code **)(*extraout_ECX + 200))();
  if (cVar2 == '\0') {
    FUN_004e609e();
    cVar2 = FUN_004e6133();
    if (cVar2 != '\0') {
      (**(code **)(*extraout_ECX + 0x58))(1,0x80);
    }
    (**(code **)(*extraout_ECX + 0x90))(4,1);
    piVar3 = (int *)FUN_005e7743();
    iVar4 = (**(code **)(*piVar3 + 0x10))(5);
    extraout_ECX[0x4c] = iVar4;
    iVar5 = FUN_005d49d6();
    iVar4 = 200;
    if (iVar5 != 0) {
      piVar3 = (int *)FUN_005e7743();
      iVar5 = (**(code **)(*piVar3 + 0x28))(0,extraout_ECX + 0x13);
      extraout_ECX[0x4a] = iVar5;
      (**(code **)(*(int *)(iVar5 + 0xd4) + 0x14))(0);
      FUN_005e9fa4(extraout_ECX[0x3a]);
      (**(code **)(*(int *)(extraout_ECX[0x4a] + 0xd4) + 0xc))(1,1);
      (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x4a]);
      (*(code *)**(undefined4 **)(extraout_ECX[0x4a] + 0xd4))();
      iVar5 = (*(int *)(extraout_ECX[0x4a] + 0x84) - *(int *)(extraout_ECX[0x4a] + 0x7c)) + 0x20;
      if (200 < iVar5) {
        iVar4 = iVar5;
      }
    }
    piVar3 = (int *)FUN_005e7743();
    iVar5 = (**(code **)(*piVar3 + 0x28))(0,extraout_ECX + 0x36);
    extraout_ECX[0x4b] = iVar5;
    (**(code **)(*(int *)(iVar5 + 0xd4) + 0x1c))(3);
    (**(code **)(*(int *)(extraout_ECX[0x4b] + 0xd4) + 0xc))(2,1);
    (**(code **)(*(int *)(extraout_ECX[0x4b] + 0xd4) + 0x20))(0,0);
    (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x4b]);
    iVar5 = iVar4 + -0x20;
    FUN_004ec186(iVar5);
    (*(code *)**(undefined4 **)(extraout_ECX[0x4b] + 0xd4))();
    iVar6 = extraout_ECX[0x4b];
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar6 + 0x4c);
    piVar3 = *(int **)(iVar6 + 0xd8);
    *(int **)(unaff_EBP + -0x1c) = piVar3;
    iVar6 = (**(code **)(*piVar3 + 100))
                      (*(undefined4 *)(unaff_EBP + -0x18),
                       *(int *)(iVar6 + 0x50) - *(int *)(iVar6 + 0x4c),iVar4 + -0x20);
    if (1 < iVar6) {
      iVar5 = (iVar5 * 3) / 2;
      iVar4 = iVar5 + 0x20;
      FUN_004ec186(iVar5);
      (*(code *)**(undefined4 **)(extraout_ECX[0x4b] + 0xd4))();
    }
    iVar6 = extraout_ECX[0x4b];
    iVar9 = *(int *)(iVar6 + 0x50);
    iVar1 = *(int *)(iVar6 + 0x4c);
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(iVar6 + 0x4c);
    iVar4 = (**(code **)(**(int **)(iVar6 + 0xd8) + 100))
                      (*(undefined4 *)(unaff_EBP + -0x1c),iVar9 - iVar1,iVar4 + -0x20);
    if (1 < iVar4) {
      FUN_004ec186((iVar5 << 2) / 3);
      (*(code *)**(undefined4 **)(extraout_ECX[0x4b] + 0xd4))();
    }
    iVar4 = FUN_0052777c(2);
    (**(code **)(*extraout_ECX + 0x20))(iVar4);
    extraout_ECX[0x3e] = iVar4;
    iVar4 = FUN_0052777c(1);
    (**(code **)(*extraout_ECX + 0x20))(iVar4);
    extraout_ECX[0x3f] = iVar4;
    if (extraout_ECX[0x4d] == 1) {
      extraout_ECX[0x49] = extraout_ECX[0x3e];
    }
    else if (extraout_ECX[0x4d] == 2) {
      extraout_ECX[0x49] = iVar4;
    }
    else {
      extraout_ECX[0x4d] = 0;
    }
    if (DAT_006f3b48 == (int *)0x0) {
      FUN_005a5631(0x12d4,&DAT_006f3b48,4);
      if (DAT_006f3b48 != (int *)0x0) {
        (**(code **)(*DAT_006f3b48 + 0x68))(DAT_006f2a64);
      }
    }
    if (DAT_006f3b4c == (int *)0x0) {
      FUN_005a5631(0x12d5,&DAT_006f3b4c,4);
      if (DAT_006f3b4c != (int *)0x0) {
        (**(code **)(*DAT_006f3b4c + 0x68))(DAT_006f2a64);
      }
    }
    iVar4 = extraout_ECX[0x41];
    iVar5 = extraout_ECX[0x40];
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    if ((iVar4 - iVar5) / 0xc != 0) {
      do {
        pvVar7 = operator_new(0x194);
        *(void **)(unaff_EBP + -0x1c) = pvVar7;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if (pvVar7 == (void *)0x0) {
          piVar3 = (int *)0x0;
        }
        else {
          piVar3 = (int *)FUN_005e372a();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(int **)(unaff_EBP + -0x14) = piVar3;
        (**(code **)(*piVar3 + 0x19c))(DAT_006f3b48,4,1);
        *(undefined4 *)(*(int *)(unaff_EBP + -0x14) + 0xf8) = 1;
        (**(code **)(*extraout_ECX + 0x20))(*(undefined4 *)(unaff_EBP + -0x14));
        FUN_00524c70(unaff_EBP + -0x14);
        pvVar7 = operator_new(0x110);
        *(void **)(unaff_EBP + -0x1c) = pvVar7;
        *(undefined4 *)(unaff_EBP + -4) = 1;
        if (pvVar7 == (void *)0x0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_005e9913();
        }
        iVar5 = extraout_ECX[0x4a];
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(int *)(unaff_EBP + -0x10) = iVar4;
        (**(code **)(*(int *)(iVar4 + 0xd4) + 0x18))(*(undefined4 *)(iVar5 + 0xd8));
        iVar4 = **(int **)(unaff_EBP + -0x10);
        uVar8 = FUN_004096c2();
        (**(code **)(iVar4 + 0x1a0))(uVar8);
        (**(code **)(*extraout_ECX + 0x20))(*(undefined4 *)(unaff_EBP + -0x10));
        (**(code **)(*(int *)(*(int *)(unaff_EBP + -0x10) + 0xd4) + 0xc))(2,0);
        (**(code **)(*(int *)(*(int *)(unaff_EBP + -0x10) + 0xd4) + 0x14))(0);
        (*(code *)**(undefined4 **)(*(int *)(unaff_EBP + -0x10) + 0xd4))();
        FUN_00527d70(unaff_EBP + -0x10);
        iVar4 = extraout_ECX[0x41];
        iVar5 = extraout_ECX[0x40];
        *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
      } while (*(uint *)(unaff_EBP + -0x18) < (uint)((iVar4 - iVar5) / 0xc));
    }
    (**(code **)(**(int **)extraout_ECX[0x43] + 0x19c))(DAT_006f3b4c,4,1);
    FUN_005e46f0(1);
    uVar8 = FUN_00527af9();
    *(undefined4 *)(unaff_EBP + -0x18) = uVar8;
    if ((extraout_ECX[0x44] - extraout_ECX[0x43] & 0xfffffffcU) == 0) {
      iVar5 = extraout_ECX[0x4b];
      iVar6 = extraout_ECX[0x4a];
      iVar4 = (((*(int *)(extraout_ECX[0x3e] + 0x88) - *(int *)(extraout_ECX[0x3e] + 0x80)) -
               *(int *)(iVar5 + 0x80)) - *(int *)(iVar6 + 0x80)) + *(int *)(iVar5 + 0x88) + 0x38 +
              *(int *)(iVar6 + 0x88);
    }
    else {
      iVar4 = *(int *)extraout_ECX[0x43];
      iVar5 = *(int *)extraout_ECX[0x46];
      if (*(int *)(iVar5 + 0x88) - *(int *)(iVar5 + 0x80) <
          *(int *)(iVar4 + 0x88) - *(int *)(iVar4 + 0x80)) {
        iVar4 = *(int *)(iVar4 + 0x88) - *(int *)(iVar4 + 0x80);
      }
      else {
        iVar4 = *(int *)(iVar5 + 0x88) - *(int *)(iVar5 + 0x80);
      }
      iVar5 = extraout_ECX[0x4b];
      iVar6 = extraout_ECX[0x4a];
      iVar4 = ((((extraout_ECX[0x44] - extraout_ECX[0x43] >> 2) * (iVar4 + 8) -
                *(int *)(extraout_ECX[0x3e] + 0x80)) - *(int *)(iVar5 + 0x80)) -
              *(int *)(iVar6 + 0x80)) + *(int *)(extraout_ECX[0x3e] + 0x88) + *(int *)(iVar5 + 0x88)
              + 0x40 + *(int *)(iVar6 + 0x88);
    }
    iVar9 = *(int *)(unaff_EBP + -0x18);
    if (iVar9 < (*(int *)(iVar6 + 0x84) - *(int *)(iVar6 + 0x7c)) + 0x20) {
      iVar9 = (*(int *)(iVar6 + 0x84) - *(int *)(iVar6 + 0x7c)) + 0x20;
    }
    if (iVar9 < (*(int *)(iVar5 + 0x84) - *(int *)(iVar5 + 0x7c)) + 0x20) {
      iVar9 = (*(int *)(iVar5 + 0x84) - *(int *)(iVar5 + 0x7c)) + 0x20;
    }
    (**(code **)(*extraout_ECX + 0x60))(0,0,iVar9,iVar4);
    FUN_00527af9();
    iVar4 = FUN_005d49d6();
    if (iVar4 != 0) {
      FUN_004ec186((extraout_ECX[0x21] - extraout_ECX[0x1f]) + -0x20);
      FUN_004cb21d(0x10,0x10);
    }
    FUN_004ec186((extraout_ECX[0x21] - extraout_ECX[0x1f]) + -0x20);
    iVar4 = FUN_005d49d6();
    if (iVar4 == 0) {
      iVar4 = 0x10;
    }
    else {
      iVar4 = *(int *)(extraout_ECX[0x4a] + 0x88) + 8;
    }
    FUN_004cb21d(0x10,iVar4);
    (**(code **)(*extraout_ECX + 0x174))(1,0);
    iVar4 = FUN_004b46a0();
    (**(code **)(*extraout_ECX + 100))(iVar4 + 0x7c);
    extraout_ECX[0x19] = extraout_ECX[0x3b];
    FUN_005ddfdc(1);
    FUN_005dbf32();
  }
  else {
    FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

