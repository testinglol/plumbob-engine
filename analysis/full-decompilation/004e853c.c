
undefined1 FUN_004e853c(void)

{
  undefined4 uVar1;
  char cVar2;
  undefined1 uVar3;
  void *pvVar4;
  int *piVar5;
  ushort *puVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 extraout_ECX;
  int unaff_EBP;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  
  FUN_00634c24();
  uStack_50 = 100;
  *(undefined1 *)(unaff_EBP + -0xd) = 1;
  uStack_44 = 0x4e8557;
  pvVar4 = operator_new(100);
  *(void **)(unaff_EBP + -0x1c) = pvVar4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar4 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_005dfb13();
    uStack_50 = extraout_ECX;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (piVar5 != (int *)0x0) {
    iVar10 = *piVar5;
    uStack_44 = 0;
    uStack_48 = 0;
    *(undefined4 **)(unaff_EBP + -0x1c) = &uStack_50;
    uStack_4c = uStack_50;
    FUN_00436a50(4);
    cVar2 = (**(code **)(iVar10 + 0xc))(DAT_006f2610,DAT_006f2614);
    if (cVar2 != '\0') {
      FUN_005a5631(0x11fa,unaff_EBP + -0x14,4);
      if (*(int **)(unaff_EBP + -0x14) != (int *)0x0) {
        cVar2 = (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x20))(0x40);
        if (cVar2 == '\0') {
          uVar9 = *(uint *)(unaff_EBP + 8);
        }
        else {
          puVar6 = (ushort *)(**(code **)(**(int **)(unaff_EBP + -0x14) + 0xcc))();
          uVar9 = (uint)*puVar6;
          (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x24))(0x40);
        }
        FUN_005c1719();
        *(undefined4 *)(unaff_EBP + -4) = 1;
        uVar1 = DAT_006f2614;
        *(undefined4 *)(unaff_EBP + -0x2c) = 0x4c;
        uVar8 = DAT_006f2610;
        *(undefined4 *)(unaff_EBP + -0x28) = 0x2d;
        *(undefined4 *)(unaff_EBP + -0x24) = 0x7a;
        *(undefined4 *)(unaff_EBP + -0x20) = 0x7d;
        *(undefined4 *)(unaff_EBP + -0x3c) = 0;
        *(undefined4 *)(unaff_EBP + -0x38) = 0;
        *(undefined4 *)(unaff_EBP + -0x34) = 0;
        *(undefined4 *)(unaff_EBP + -0x30) = 0;
        cVar2 = FUN_004e7902(*(undefined4 *)(unaff_EBP + 8),0,0,uVar8,uVar1,unaff_EBP + -0x3c,uVar9,
                             unaff_EBP + -0x18,unaff_EBP + -0x2c);
        if (cVar2 == '\0') {
          *(undefined1 *)(unaff_EBP + -0xd) = 0;
        }
        else {
          cVar2 = FUN_005a5e72();
          if (cVar2 != '\0') {
            cVar2 = (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x20))(0x10);
            if (cVar2 != '\0') {
              iVar7 = FUN_004096c2();
              puVar11 = &DAT_006f2608;
              iVar10 = unaff_EBP + -0x3c;
              *(undefined4 *)(unaff_EBP + 8) = **(undefined4 **)(unaff_EBP + -0x14);
              FUN_004096c2(iVar10,&DAT_006f2608,0);
              uVar8 = FUN_004df599(iVar10,puVar11);
              uVar8 = FUN_004096c2(iVar7 + 0x14,uVar8);
              cVar2 = (**(code **)(*(int *)(unaff_EBP + 8) + 0x9c))(uVar8);
              (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x24))(0x10);
              if (cVar2 == '\0') {
                *(undefined1 *)(unaff_EBP + -0xd) = 0;
              }
            }
          }
        }
        (**(code **)*piVar5)(1);
        FUN_005a5e48(*(undefined4 *)(unaff_EBP + -0x14));
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005a5e09();
        uVar3 = *(undefined1 *)(unaff_EBP + -0xd);
        goto LAB_004e86f9;
      }
    }
    (**(code **)*piVar5)(1);
  }
  uVar3 = 0;
LAB_004e86f9:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

