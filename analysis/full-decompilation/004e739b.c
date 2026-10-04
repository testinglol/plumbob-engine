
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_004e739b(void)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  char cVar4;
  undefined1 uVar5;
  void *pvVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  
  FUN_00634c24();
  *(undefined1 *)(unaff_EBP + -0xd) = 1;
  uStack_68 = 0x4e73b6;
  pvVar6 = operator_new(100);
  *(void **)(unaff_EBP + -0x18) = pvVar6;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar6 == (void *)0x0) {
    piVar7 = (int *)0x0;
    uStack_74 = 0;
  }
  else {
    piVar7 = (int *)FUN_005dfb13();
    uStack_74 = extraout_ECX;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (piVar7 != (int *)0x0) {
    iVar10 = *piVar7;
    uStack_68 = 0;
    uStack_6c = 0;
    *(undefined4 **)(unaff_EBP + -0x18) = &uStack_74;
    uStack_70 = uStack_74;
    FUN_00436a50(4);
    cVar4 = (**(code **)(iVar10 + 0xc))(DAT_006f2610 * 3,DAT_006f2614);
    if (cVar4 != '\0') {
      *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(DAT_006e486c + 0x34);
      cVar4 = (**(code **)(*piVar7 + 0x20))(0x10);
      if (cVar4 != '\0') {
        *(undefined4 *)(unaff_EBP + -0x50) = 0;
        *(undefined4 *)(unaff_EBP + -0x4c) = 0;
        *(undefined4 *)(unaff_EBP + -0x30) = 0;
        fVar2 = DAT_00673438;
        fVar1 = DAT_00673438 * _DAT_00669418;
        *(undefined4 *)(unaff_EBP + -0x48) = 0;
        *(undefined4 *)(unaff_EBP + -0x44) = 0;
        *(undefined4 *)(unaff_EBP + -0x18) = 0;
        *(float *)(unaff_EBP + -0x2c) = fVar1;
        *(float *)(unaff_EBP + -0x28) = fVar2 * _DAT_00669414;
        *(undefined4 *)(unaff_EBP + -0x24) = 0;
        *(float *)(unaff_EBP + -0x20) = fVar2 * _DAT_00669410;
        *(float *)(unaff_EBP + -0x1c) = fVar2 * _DAT_0066940c;
        do {
          FUN_005c1719();
          uVar3 = DAT_006f2614;
          *(undefined4 *)(unaff_EBP + -4) = 1;
          iVar10 = DAT_006f2610;
          iVar8 = *(int *)(unaff_EBP + -0x18) * 4;
          *(undefined4 *)(unaff_EBP + -0x40) = 0x4c;
          uVar11 = *(undefined4 *)(unaff_EBP + -0x24 + iVar8);
          *(undefined4 *)(unaff_EBP + -0x3c) = 0x2d;
          *(undefined4 *)(unaff_EBP + -0x38) = 0x7a;
          *(undefined4 *)(unaff_EBP + -0x34) = 0x7d;
          cVar4 = FUN_004e7902(*(undefined4 *)(unaff_EBP + 8),
                               *(undefined4 *)(unaff_EBP + -0x30 + iVar8),uVar11,iVar10,uVar3,
                               unaff_EBP + -0x50,10,unaff_EBP + -0x14,unaff_EBP + -0x40);
          if (cVar4 == '\0') {
            *(undefined1 *)(unaff_EBP + -0xd) = 0;
          }
          cVar4 = FUN_005a5e72();
          iVar10 = DAT_006f2610;
          if (cVar4 != '\0') {
            iVar8 = *piVar7;
            iVar9 = DAT_006f2610 * *(int *)(unaff_EBP + -0x18);
            *(int *)(unaff_EBP + -0x60) = iVar9;
            *(int *)(unaff_EBP + -0x58) = iVar9 + iVar10;
            *(undefined4 *)(unaff_EBP + -0x54) = DAT_006f2614;
            *(undefined4 *)(unaff_EBP + -0x5c) = 0;
            iVar10 = FUN_004096c2(unaff_EBP + -0x60,0);
            uVar11 = FUN_004096c2(iVar10 + 0x14);
            cVar4 = (**(code **)(iVar8 + 0x9c))(uVar11);
            if (cVar4 == '\0') {
              *(undefined1 *)(unaff_EBP + -0xd) = 0;
            }
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005a5e09();
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
        } while (*(int *)(unaff_EBP + -0x18) < 3);
        (**(code **)(*piVar7 + 0x24))(0x10);
      }
      (**(code **)(*piVar7 + 0x68))(DAT_006f2a64);
      FUN_005a5e48(piVar7);
      uVar5 = *(undefined1 *)(unaff_EBP + -0xd);
      goto LAB_004e7575;
    }
    (**(code **)*piVar7)(1);
  }
  uVar5 = 0;
LAB_004e7575:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

