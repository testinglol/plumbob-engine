
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 * FUN_0059996c(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined2 *puVar7;
  undefined1 *extraout_ECX;
  undefined4 *puVar8;
  undefined2 *puVar9;
  int *piVar10;
  undefined4 *puVar11;
  int unaff_EBP;
  int iVar12;
  
  FUN_00634c24();
  uVar2 = *(undefined4 *)(unaff_EBP + 8);
  *extraout_ECX = 0;
  *(undefined4 *)(extraout_ECX + 4) = uVar2;
  uVar2 = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)(extraout_ECX + 0xc) = 0;
  *(undefined4 *)(extraout_ECX + 8) = uVar2;
  *(undefined1 **)(unaff_EBP + -0x28) = extraout_ECX;
  *(undefined4 *)(extraout_ECX + 0x10) = 0;
  *(undefined4 *)(extraout_ECX + 0x14) = 0;
  *(undefined4 *)(extraout_ECX + 0x18) = 0;
  uVar2 = _DAT_0066745c;
  *(undefined4 *)(unaff_EBP + -0x10) = _DAT_0066745c;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
  *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar2 = FUN_00462bc9(unaff_EBP + -0x18,unaff_EBP + -0x14,unaff_EBP + -0x10);
  FUN_00462be8(uVar2);
  uVar2 = _DAT_00667458;
  *(undefined4 *)(unaff_EBP + -0x1c) = _DAT_00667458;
  *(undefined4 *)(unaff_EBP + -0x20) = uVar2;
  *(undefined4 *)(unaff_EBP + -0x24) = uVar2;
  uVar2 = FUN_00462bc9(unaff_EBP + -0x24,unaff_EBP + -0x20,unaff_EBP + -0x1c);
  FUN_00462be8(uVar2);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  pvVar3 = operator_new(0x118);
  *(void **)(unaff_EBP + 8) = pvVar3;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  if (pvVar3 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005d36ab(*(undefined4 *)(DAT_006e486c + 0x30));
  }
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(extraout_ECX + 0xc) = uVar2;
  FUN_005d0e5a();
  piVar10 = *(int **)(unaff_EBP + 0x10);
  if ((piVar10 == (int *)0x0) || (piVar10[1] == *piVar10)) {
    piVar10 = (int *)(*(int *)(extraout_ECX + 8) + 0xc);
  }
  FUN_005c5db0(*piVar10);
  FUN_005d1318();
  iVar12 = *(int *)(extraout_ECX + 8);
  iVar6 = *(int *)(iVar12 + 100);
  *(undefined4 *)(unaff_EBP + 0x10) = *(undefined4 *)(iVar12 + 0x4c);
  iVar4 = (*(int *)(iVar12 + 0x68) - iVar6) / 0x18;
  iVar12 = *(int *)(iVar12 + 0x50) - *(int *)(iVar12 + 0x4c) >> 3;
  *(int *)(unaff_EBP + 0xc) = iVar4;
  cVar1 = FUN_005d1422(iVar4);
  if (cVar1 != '\0') {
    iVar4 = *(int *)(extraout_ECX + 0xc);
    *(undefined4 *)(unaff_EBP + 8) = 0;
    *(uint *)(iVar4 + 0x14) = *(uint *)(iVar4 + 0x14) | 1;
    *(uint *)(iVar4 + 0xc4) = *(uint *)(iVar4 + 0xc4) | 4;
    puVar5 = *(undefined4 **)(iVar4 + 200);
    if (0 < *(int *)(unaff_EBP + 0xc)) {
      puVar11 = *(undefined4 **)(unaff_EBP + 0x10);
      puVar8 = (undefined4 *)(iVar6 + 8);
      do {
        iVar6 = *(int *)(unaff_EBP + 8);
        *puVar5 = puVar8[-2];
        puVar5[1] = puVar8[-1];
        puVar5[2] = *puVar8;
        puVar5[3] = puVar8[1];
        puVar5[4] = puVar8[2];
        puVar5[5] = puVar8[3];
        if (iVar6 < iVar12) {
          puVar5[6] = *puVar11;
          puVar5[7] = puVar11[1];
        }
        else {
          puVar5[6] = 0;
          puVar5[7] = 0;
        }
        puVar5 = puVar5 + 8;
        *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
        puVar8 = puVar8 + 6;
        puVar11 = puVar11 + 2;
      } while (*(int *)(unaff_EBP + 8) < *(int *)(unaff_EBP + 0xc));
    }
    iVar6 = (*(int *)(*(int *)(extraout_ECX + 8) + 0x38) -
            *(int *)(*(int *)(extraout_ECX + 8) + 0x34)) / 0xc;
    cVar1 = FUN_005d1468(iVar6 * 3,0);
    if (cVar1 != '\0') {
      puVar9 = (undefined2 *)**(undefined4 **)(*(int *)(extraout_ECX + 0xc) + 0xd4);
      if (0 < iVar6) {
        iVar4 = 0;
        *(int *)(unaff_EBP + 8) = iVar6;
        do {
          puVar7 = (undefined2 *)(*(int *)(*(int *)(extraout_ECX + 8) + 0x34) + iVar4);
          iVar4 = iVar4 + 0xc;
          *puVar9 = *puVar7;
          puVar9[1] = puVar7[2];
          puVar9[2] = puVar7[4];
          puVar9 = puVar9 + 3;
          piVar10 = (int *)(unaff_EBP + 8);
          *piVar10 = *piVar10 + -1;
        } while (*piVar10 != 0);
      }
      *(undefined4 *)(unaff_EBP + -0x30) = 0;
      *(int *)(unaff_EBP + -0x2c) = iVar12 + -1;
      FUN_005d1259(unaff_EBP + -0x30,0);
      FUN_00463023(&DAT_006fe6d0);
      FUN_00463049(*(int *)(extraout_ECX + 8) + 0x7c);
      (**(code **)(**(int **)(extraout_ECX + 0xc) + 0x28))(*(int *)(extraout_ECX + 8) + 0x7c);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

