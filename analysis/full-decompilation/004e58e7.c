
undefined4 FUN_004e58e7(void)

{
  int *piVar1;
  char cVar2;
  undefined1 uVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int unaff_EBP;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  
  FUN_00634c24();
  if (DAT_006f25cc == (int *)0x0) {
    pvVar4 = operator_new(4);
    *(void **)(unaff_EBP + -0x30) = pvVar4;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar4 == (void *)0x0) {
      DAT_006f25cc = (int *)0x0;
    }
    else {
      DAT_006f25cc = (int *)FUN_004e5db0();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  piVar1 = (int *)*DAT_006f25cc;
  *(undefined4 *)(unaff_EBP + -0x28) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = 0;
  *(undefined4 *)(unaff_EBP + -0x20) = 200;
  *(undefined4 *)(unaff_EBP + -0x1c) = 200;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  while( true ) {
    cVar2 = (**(code **)(*piVar1 + 0x20))(1);
    if (cVar2 != '\0') {
      (**(code **)(*piVar1 + 0x38))
                (*(undefined4 *)(*(int *)(unaff_EBP + 0xc) + *(int *)(unaff_EBP + -0x10) * 4),0);
      (**(code **)(*piVar1 + 0x24))(1);
    }
    cVar2 = (**(code **)(*(int *)piVar1[0x17] + 0x20))(1);
    if (cVar2 != '\0') {
      (**(code **)(*(int *)piVar1[0x17] + 0x38))(0xffff,0);
      (**(code **)(*(int *)piVar1[0x17] + 0x24))(1);
    }
    *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(unaff_EBP + -0x28);
    *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + -0x24);
    *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(unaff_EBP + -0x20);
    *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(unaff_EBP + -0x1c);
    cVar2 = FUN_004e5685(piVar1,unaff_EBP + -0x28);
    if (cVar2 != '\0') {
      iVar11 = *(int *)(unaff_EBP + 8);
      iVar8 = *(int *)(iVar11 + 0x24);
      if (iVar8 == 1) {
        *(undefined4 *)(unaff_EBP + -0x50) = 0;
        uVar6 = *(undefined4 *)(iVar11 + 0x28);
        *(undefined1 *)(unaff_EBP + -0x4c) = 1;
        if (*(int *)(unaff_EBP + -0x10) == 1) {
          *(undefined4 *)(unaff_EBP + -0x50) = 1;
        }
        uVar3 = FUN_004576e0();
        *(undefined1 *)(unaff_EBP + -0x4c) = uVar3;
        uVar5 = FUN_004576d5(*(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0x28),
                             *(int *)(unaff_EBP + -0x1c) - *(int *)(unaff_EBP + -0x24),
                             unaff_EBP + -0x48,unaff_EBP + -0x50,0);
        FUN_0043856d(uVar6,uVar5);
      }
      else if (iVar8 == 2) {
        FUN_004b4533(*(undefined4 *)(DAT_006e486c + 4));
        FUN_004b475c();
        iVar11 = *(int *)(DAT_006e54dc + 0x10);
        *(undefined1 *)(unaff_EBP + -0x12) = 1;
        *(char *)(unaff_EBP + -0x14) = (char)(iVar11 / 2);
        *(char *)(unaff_EBP + -0x13) = (char)(iVar11 / 2);
        FUN_00434d3d(unaff_EBP + -0x38);
        FUN_004b463f(3,1,1);
        *(undefined4 *)(unaff_EBP + -0x78) = *(undefined4 *)(unaff_EBP + -0x38);
        *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(unaff_EBP + -0x34);
        FUN_004b4bbd(3);
        iVar8 = (*(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0x28)) / 2;
        iVar11 = ((*(int *)(unaff_EBP + -0x1c) - *(int *)(unaff_EBP + -0x24)) * 2) / 3;
        iVar9 = iVar8 + -0x40;
        *(int *)(unaff_EBP + -0x48) = iVar9;
        *(int *)(unaff_EBP + -0xb8) = iVar9;
        iVar10 = iVar11 + -0x2d;
        *(int *)(unaff_EBP + -0x40) = iVar8 + 0x40;
        *(int *)(unaff_EBP + -0x44) = iVar10;
        iVar11 = iVar11 + 0x13;
        *(int *)(unaff_EBP + -0x3c) = iVar11;
        *(int *)(unaff_EBP + -0xb4) = iVar11;
        FUN_004b97eb(unaff_EBP + -0x38,1,unaff_EBP + -200,0xffffffff);
        cVar2 = FUN_004a156c(*(undefined4 *)(*(int *)(unaff_EBP + 8) + 0x44),3,unaff_EBP + -0x30,
                             unaff_EBP + -0x54);
        if (cVar2 != '\0') {
          *(undefined1 *)(unaff_EBP + -0x29) = 0x7f;
          *(undefined1 *)(unaff_EBP + -0x2a) = 0x7f;
          *(undefined1 *)(unaff_EBP + -0x2b) = 0x7f;
          *(undefined1 *)(unaff_EBP + -0x2c) = 0x7f;
          *(char *)(unaff_EBP + -0x18) = (char)(*(int *)(unaff_EBP + -0x34) >> 4);
          *(undefined4 *)(unaff_EBP + -4) = 1;
          *(char *)(unaff_EBP + -0x17) = (char)(*(int *)(unaff_EBP + -0x38) >> 4);
          *(undefined1 *)(unaff_EBP + -0x16) = 1;
          *(undefined1 *)(unaff_EBP + -4) = 2;
          FUN_004c828c(unaff_EBP + -0xd8,unaff_EBP + -0x18,*(undefined4 *)(unaff_EBP + -0x54),0,
                       iVar9,iVar10,0,unaff_EBP + -200,unaff_EBP + -0x2c,1,0,0,0);
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        }
      }
      else if ((iVar8 == 3) || (iVar8 == 4)) {
        iVar7 = (*(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0x28)) / 2;
        iVar9 = ((*(int *)(unaff_EBP + -0x1c) - *(int *)(unaff_EBP + -0x24)) * 3) / 4;
        iVar8 = *(int *)(iVar11 + 0x40);
        iVar10 = iVar9 + 0xe;
        if ((iVar8 == 2) || (iVar8 == 0xc)) {
          iVar10 = iVar9 + -0x10;
        }
        uVar6 = *(undefined4 *)(iVar11 + 0x3c);
        iVar11 = unaff_EBP + -0x48;
        uVar12 = 6;
        uVar5 = 2;
        FUN_00540a5b(iVar7,iVar10,2,iVar8,uVar6,6,iVar11);
        FUN_00540c42(iVar7,iVar10,uVar5,iVar8,uVar6,uVar12,iVar11);
      }
      FUN_004e586d(piVar1);
    }
    uVar6 = FUN_004e5c2f(piVar1,*(undefined4 *)(unaff_EBP + 0x10),200,unaff_EBP + -0x48);
    FUN_005a5e48(uVar6);
    cVar2 = FUN_005a5e72();
    if (cVar2 == '\0') break;
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    if (1 < *(int *)(unaff_EBP + -0x10)) {
      uVar6 = 1;
LAB_004e5c0a:
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return uVar6;
    }
  }
  iVar11 = 2;
  do {
    FUN_005a5e48(0);
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  uVar6 = 0;
  goto LAB_004e5c0a;
}

