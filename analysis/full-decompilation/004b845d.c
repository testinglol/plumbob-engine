
undefined4 FUN_004b845d(void)

{
  undefined2 *puVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  uint uVar7;
  undefined3 uVar8;
  undefined4 extraout_ECX;
  int unaff_EBP;
  undefined1 *puVar9;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  int iStack_38;
  int iStack_34;
  undefined4 uVar10;
  
  FUN_00634c24();
  iStack_34 = unaff_EBP + -0x24;
  iStack_38 = unaff_EBP + -0x10;
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  uStack_3c = *(undefined4 *)(unaff_EBP + 8);
  uStack_40 = 0x4b8483;
  iVar4 = FUN_004b85a2();
  *(int *)(unaff_EBP + -0x28) = iVar4;
  if (iVar4 != 0) {
    uVar10 = 100;
    iStack_34 = 0x4b8498;
    pvVar5 = operator_new(100);
    *(void **)(unaff_EBP + 8) = pvVar5;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar5 == (void *)0x0) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = (int *)FUN_005dfb13();
      uVar10 = extraout_ECX;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int **)(unaff_EBP + -0x2c) = piVar6;
    if (piVar6 != (int *)0x0) {
      iVar4 = *piVar6;
      iStack_34 = 0;
      iStack_38 = 0;
      *(undefined4 **)(unaff_EBP + 8) = &uStack_40;
      uStack_40 = uVar10;
      uStack_3c = uVar10;
      FUN_00436a50(4);
      cVar2 = (**(code **)(iVar4 + 0xc))
                        (*(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + -0x24));
      if (cVar2 != '\0') {
        iStack_34 = 0x4b84ee;
        cVar2 = (**(code **)(*piVar6 + 0x20))();
        if (cVar2 != '\0') {
          uVar10 = (**(code **)(*piVar6 + 0xcc))();
          *(undefined4 *)(unaff_EBP + -0x1c) = uVar10;
          uVar7 = (**(code **)(*piVar6 + 0xd0))();
          *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x28);
          *(undefined4 *)(unaff_EBP + -0x20) = 0;
          if (0 < *(int *)(unaff_EBP + -0x24)) {
            do {
              iVar4 = *(int *)(unaff_EBP + -0x10);
              *(undefined4 *)(unaff_EBP + -0x14) = 0;
              if (0 < iVar4) {
                *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(unaff_EBP + -0x1c);
                iVar4 = *(int *)(unaff_EBP + -0x18);
                puVar9 = (undefined1 *)(iVar4 + 2);
                do {
                  uVar8 = (undefined3)((uint)iVar4 >> 8);
                  iStack_34 = CONCAT31(uVar8,puVar9[-1]);
                  iStack_38 = CONCAT31(uVar8,*puVar9);
                  uStack_3c = 0x4b8547;
                  uVar3 = FUN_005dfe3b();
                  puVar1 = *(undefined2 **)(unaff_EBP + 8);
                  *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
                  *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 2;
                  puVar9 = puVar9 + 4;
                  *puVar1 = uVar3;
                  iVar4 = *(int *)(unaff_EBP + -0x10);
                } while (*(int *)(unaff_EBP + -0x14) < iVar4);
              }
              *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 1;
              *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + iVar4 * 4;
              *(uint *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + (uVar7 & 0xfffffffe);
            } while (*(int *)(unaff_EBP + -0x20) < *(int *)(unaff_EBP + -0x24));
          }
          iStack_34 = 0x4b8587;
          (**(code **)(*piVar6 + 0x24))();
        }
      }
    }
    iStack_34 = 0x4b858f;
    FUN_006321f0();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x2c);
}

