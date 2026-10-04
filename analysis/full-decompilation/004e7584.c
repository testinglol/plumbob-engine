
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_004e7584(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  float fVar5;
  float fVar6;
  char cVar7;
  undefined1 uVar8;
  void *pvVar9;
  int *piVar10;
  uint *puVar11;
  int iVar12;
  undefined4 uVar13;
  undefined4 extraout_ECX;
  int iVar14;
  int unaff_EBP;
  uint uVar15;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  
  FUN_00634c24();
  uStack_80 = 100;
  *(undefined1 *)(unaff_EBP + -0xd) = 1;
  *(undefined4 *)(unaff_EBP + -0x6c) = 0xd10000;
  *(undefined4 *)(unaff_EBP + -0x68) = 0x882e2f;
  *(undefined4 *)(unaff_EBP + -100) = 0x405d5f;
  *(undefined4 *)(unaff_EBP + -0x60) = 0x20934c;
  *(undefined4 *)(unaff_EBP + -0x5c) = 0xca39;
  uStack_74 = 0x4e75c2;
  pvVar9 = operator_new(100);
  *(void **)(unaff_EBP + -0x18) = pvVar9;
  iVar14 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar9 == (void *)0x0) {
    piVar10 = (int *)0x0;
  }
  else {
    piVar10 = (int *)FUN_005dfb13();
    uStack_80 = extraout_ECX;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (piVar10 != (int *)0x0) {
    iVar1 = *piVar10;
    uStack_74 = 0;
    uStack_78 = 0;
    *(undefined4 **)(unaff_EBP + -0x18) = &uStack_80;
    uStack_7c = uStack_80;
    FUN_00436a50(4);
    cVar7 = (**(code **)(iVar1 + 0xc))(200,0x28);
    if (cVar7 != '\0') {
      *(undefined4 *)(unaff_EBP + -0x38) = 5;
      *(undefined4 *)(unaff_EBP + -0x34) = 5;
      *(undefined4 *)(unaff_EBP + -0x30) = 5;
      *(undefined4 *)(unaff_EBP + -0x2c) = 5;
      cVar7 = (**(code **)(*piVar10 + 0x20))(0x10);
      if (cVar7 != '\0') {
        puVar11 = (uint *)(unaff_EBP + -0x6c);
        *(uint **)(unaff_EBP + -0x18) = puVar11;
        while( true ) {
          uVar2 = *puVar11;
          if (*(int *)(DAT_006e486c + 0x34) == 1) {
            uVar15 = ((uVar2 >> 0x10 & 0xf8) << 5 | uVar2 >> 8 & 0xf8) << 2;
          }
          else {
            uVar15 = ((uVar2 >> 0x10 & 0xf8) << 5 | uVar2 >> 8 & 0xfc) << 3;
          }
          FUN_005c1719();
          fVar5 = DAT_00673438;
          *(undefined4 *)(unaff_EBP + -4) = 1;
          fVar5 = fVar5 * _DAT_00669420;
          *(undefined4 *)(unaff_EBP + -0x28) = 0x4c;
          *(undefined4 *)(unaff_EBP + -0x24) = 0x2d;
          *(undefined4 *)(unaff_EBP + -0x20) = 0x7a;
          fVar6 = DAT_00673438 * _DAT_0066941c;
          *(undefined4 *)(unaff_EBP + -0x1c) = 0x7d;
          cVar7 = FUN_004e7902(*(undefined4 *)(unaff_EBP + 8),fVar6,fVar5,0x28,0x28,
                               unaff_EBP + -0x38,uVar15 | uVar2 >> 3 & 0x1f,unaff_EBP + -0x14,
                               unaff_EBP + -0x28);
          if (cVar7 == '\0') {
            *(undefined1 *)(unaff_EBP + -0xd) = 0;
          }
          cVar7 = FUN_005a5e72();
          if (cVar7 != '\0') {
            iVar12 = FUN_004096c2();
            iVar1 = *(int *)(iVar12 + 0x14);
            *(int *)(unaff_EBP + -0x58) = iVar1;
            uVar13 = *(undefined4 *)(iVar12 + 0x18);
            *(undefined4 *)(unaff_EBP + -0x54) = uVar13;
            iVar3 = *(int *)(iVar12 + 0x1c);
            *(int *)(unaff_EBP + -0x50) = iVar3;
            uVar4 = *(undefined4 *)(iVar12 + 0x20);
            *(undefined4 *)(unaff_EBP + -0x4c) = uVar4;
            *(undefined4 *)(unaff_EBP + -0x3c) = uVar4;
            *(int *)(unaff_EBP + -0x48) = iVar1 + iVar14;
            iVar1 = *piVar10;
            *(int *)(unaff_EBP + -0x40) = iVar14 + iVar3;
            *(undefined4 *)(unaff_EBP + -0x44) = uVar13;
            uVar13 = FUN_004096c2(unaff_EBP + -0x58,unaff_EBP + -0x48,0);
            cVar7 = (**(code **)(iVar1 + 0x9c))(uVar13);
            if (cVar7 == '\0') {
              *(undefined1 *)(unaff_EBP + -0xd) = 0;
            }
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_005a5e09();
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 4;
          iVar14 = iVar14 + 0x28;
          if (199 < iVar14) break;
          puVar11 = *(uint **)(unaff_EBP + -0x18);
        }
        (**(code **)(*piVar10 + 0x24))(0x10);
      }
      FUN_005a5e48(piVar10);
      uVar8 = *(undefined1 *)(unaff_EBP + -0xd);
      goto LAB_004e779e;
    }
    (**(code **)*piVar10)(1);
  }
  uVar8 = 0;
LAB_004e779e:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar8;
}

