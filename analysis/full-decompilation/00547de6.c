
void FUN_00547de6(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  void *pvVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar9;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x18) = DAT_006f2aac;
  if (('\x02' < *(char *)(DAT_006e486c + 100)) && (*(char *)(DAT_006e486c + 100) < '\x05')) {
    *(undefined4 *)(unaff_EBP + -0x18) = DAT_006f2aa4;
  }
  iVar9 = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  do {
    pvVar5 = operator_new(0x1e0);
    *(void **)(unaff_EBP + -0x1c) = pvVar5;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (pvVar5 == (void *)0x0) {
      iVar6 = 0;
    }
    else {
      iVar6 = FUN_00562c86(extraout_ECX);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    *(int *)(unaff_EBP + -0x10) = iVar6;
    if (iVar6 != 0) {
      (**(code **)(*extraout_ECX + 0x20))(iVar6);
      FUN_005481c4(unaff_EBP + -0x10);
      (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x19c))(0,4,0);
      FUN_005e4071(*(undefined4 *)(unaff_EBP + -0x18));
      uVar7 = FUN_004705f2(*(int *)(unaff_EBP + -0x14) + 0x12,0xffffffff);
      FUN_005d4956(uVar7);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      FUN_0056312b(unaff_EBP + -0x28);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      uVar7 = FUN_005d4956(s__006cd6f0);
      *(undefined4 *)(unaff_EBP + -4) = 2;
      FUN_00563148(uVar7);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x90))(0x2000,1);
    }
    *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
  } while (*(int *)(unaff_EBP + -0x14) < 5);
  *(undefined4 *)(unaff_EBP + -0x78) = 0;
  *(undefined4 *)(unaff_EBP + -0x74) = 0;
  *(undefined4 *)(unaff_EBP + -0x70) = 0;
  *(undefined4 *)(unaff_EBP + -0x6c) = 0;
  *(undefined4 *)(unaff_EBP + -0x68) = 0;
  *(undefined4 *)(unaff_EBP + -100) = 0;
  *(undefined4 *)(unaff_EBP + -0x60) = 0;
  *(undefined4 *)(unaff_EBP + -0x5c) = 0;
  *(undefined4 *)(unaff_EBP + -0x58) = 0;
  iVar6 = extraout_ECX[0x20];
  iVar1 = extraout_ECX[0x1f];
  iVar2 = extraout_ECX[0x21];
  iVar3 = extraout_ECX[0x22];
  *(undefined4 *)(unaff_EBP + -4) = 3;
  *(int *)(unaff_EBP + -0x38) = iVar3 - iVar6;
  *(undefined4 *)(unaff_EBP + -0x44) = DAT_006f4ff8;
  *(undefined4 *)(unaff_EBP + -0x40) = DAT_006f4ffc;
  *(int *)(unaff_EBP + -0x3c) = iVar2 - iVar1;
  puVar8 = (undefined4 *)FUN_004df599(unaff_EBP + -0x54,extraout_ECX + 0x43);
  uVar7 = puVar8[1];
  *(undefined4 *)(unaff_EBP + -0x78) = *puVar8;
  *(undefined4 *)(unaff_EBP + -0x74) = uVar7;
  *(undefined4 *)(unaff_EBP + -0x68) = puVar8[2];
  *(undefined4 *)(unaff_EBP + -100) = puVar8[3];
  uVar7 = DAT_006f4ff0;
  *(undefined4 *)(unaff_EBP + -0x70) = DAT_006f4ff0;
  uVar4 = DAT_006f4ff4;
  *(undefined4 *)(unaff_EBP + -0x60) = uVar7;
  iVar6 = extraout_ECX[0x59];
  iVar1 = extraout_ECX[0x58];
  *(undefined4 *)(unaff_EBP + -0x6c) = uVar4;
  *(undefined4 *)(unaff_EBP + -0x5c) = uVar4;
  *(undefined4 *)(unaff_EBP + -0x58) = 1;
  FUN_004ebf01(extraout_ECX[0x58],iVar6 - iVar1 >> 2);
  do {
    FUN_0056310e(*(int *)(iVar9 + extraout_ECX[0x58]) + 0x7c);
    iVar9 = iVar9 + 4;
  } while (iVar9 < 0x14);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

