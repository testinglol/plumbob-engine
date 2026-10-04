
undefined4 FUN_004e5e40(void)

{
  undefined4 uVar1;
  char cVar2;
  int *piVar3;
  undefined2 *puVar4;
  void *pvVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int *piVar9;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  piVar3 = (int *)FUN_004096c2();
  cVar2 = (**(code **)(*piVar3 + 0x20))(0x40);
  if (cVar2 != '\0') {
    piVar3 = (int *)FUN_004096c2();
    puVar4 = (undefined2 *)(**(code **)(*piVar3 + 0xcc))();
    *(undefined2 *)(unaff_EBP + -0x18) = *puVar4;
    piVar3 = (int *)FUN_004096c2();
    (**(code **)(*piVar3 + 0x24))(0x40);
  }
  if (DAT_006f25cc == (int *)0x0) {
    pvVar5 = operator_new(4);
    *(void **)(unaff_EBP + -0x14) = pvVar5;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar5 == (void *)0x0) {
      DAT_006f25cc = (int *)0x0;
    }
    else {
      DAT_006f25cc = (int *)FUN_004e5db0();
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  }
  piVar3 = (int *)*DAT_006f25cc;
  *(undefined4 *)(unaff_EBP + -0x38) = 0;
  *(undefined4 *)(unaff_EBP + -0x34) = 0;
  *(undefined4 *)(unaff_EBP + -0x30) = 200;
  *(undefined4 *)(unaff_EBP + -0x2c) = 200;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + 0xc);
  while( true ) {
    iVar6 = FUN_004096c2();
    uVar7 = *(undefined4 *)(iVar6 + 0x20);
    iVar6 = FUN_004096c2();
    uVar1 = *(undefined4 *)(iVar6 + 0x1c);
    *(undefined4 *)(unaff_EBP + -0x24) = uVar7;
    *(undefined4 *)(unaff_EBP + -0x28) = uVar1;
    cVar2 = (**(code **)(*piVar3 + 0x20))(1);
    if (cVar2 != '\0') {
      (**(code **)(*piVar3 + 0x38))(*(undefined2 *)(unaff_EBP + -0x18),0);
      (**(code **)(*piVar3 + 0x24))(1);
    }
    cVar2 = (**(code **)(*(int *)piVar3[0x17] + 0x20))(1);
    if (cVar2 != '\0') {
      (**(code **)(*(int *)piVar3[0x17] + 0x38))(0xffff,0);
      (**(code **)(*(int *)piVar3[0x17] + 0x24))(1);
    }
    *(undefined4 *)(unaff_EBP + -0x48) = *(undefined4 *)(unaff_EBP + -0x38);
    *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(unaff_EBP + -0x34);
    *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(unaff_EBP + -0x30);
    *(undefined4 *)(unaff_EBP + -0x3c) = *(undefined4 *)(unaff_EBP + -0x2c);
    cVar2 = FUN_004e5685(piVar3,unaff_EBP + -0x38);
    if (cVar2 != '\0') {
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      *(undefined1 *)(unaff_EBP + -0x1c) = 0;
      uVar7 = FUN_004576d5(*(int *)(unaff_EBP + -0x30) - *(int *)(unaff_EBP + -0x38),
                           *(int *)(unaff_EBP + -0x2c) - *(int *)(unaff_EBP + -0x34),
                           unaff_EBP + -0x48,unaff_EBP + -0x20,0);
      FUN_0043856d(*(undefined4 *)(unaff_EBP + 8),uVar7);
      FUN_004e586d(piVar3);
    }
    puVar8 = (undefined4 *)FUN_004e5c2f(piVar3,unaff_EBP + -0x28,200,unaff_EBP + -0x48);
    if (puVar8 == (undefined4 *)0x0) break;
    iVar6 = FUN_004096c2();
    *(undefined4 *)(unaff_EBP + -0x58) = *(undefined4 *)(iVar6 + 0x14);
    *(undefined4 *)(unaff_EBP + -0x54) = *(undefined4 *)(iVar6 + 0x18);
    *(undefined4 *)(unaff_EBP + -0x50) = *(undefined4 *)(iVar6 + 0x1c);
    *(undefined4 *)(unaff_EBP + -0x4c) = *(undefined4 *)(iVar6 + 0x20);
    piVar9 = (int *)FUN_004096c2();
    cVar2 = (**(code **)(*piVar9 + 0x20))(0x10);
    if (cVar2 != '\0') {
      piVar9 = (int *)FUN_004096c2();
      (**(code **)(*piVar9 + 0x9c))(puVar8,unaff_EBP + -0x58,unaff_EBP + -0x58,0);
      piVar9 = (int *)FUN_004096c2();
      (**(code **)(*piVar9 + 0x24))(0x10);
    }
    (**(code **)*puVar8)(1);
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
    *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 4;
    if (1 < *(int *)(unaff_EBP + -0x14)) {
      uVar7 = 1;
LAB_004e6044:
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return uVar7;
    }
  }
  iVar6 = *(int *)(unaff_EBP + -0x14);
  if (-1 < iVar6 + -1) {
    do {
      FUN_005a5e48(0);
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  uVar7 = 0;
  goto LAB_004e6044;
}

