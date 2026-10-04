
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a72ce(void)

{
  LPRECT lprc;
  int *piVar1;
  undefined4 uVar2;
  float fVar3;
  char cVar4;
  void *pvVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  int iVar10;
  int extraout_ECX;
  undefined4 extraout_ECX_00;
  int unaff_EBP;
  undefined4 uStack_4c;
  
  FUN_00634c24();
  *(undefined4 *)(extraout_ECX + 0x1c) = *(undefined4 *)(unaff_EBP + 0xc);
  puVar9 = *(undefined4 **)(unaff_EBP + 8);
  *(undefined4 *)(extraout_ECX + 0x20) = *puVar9;
  *(undefined4 *)(extraout_ECX + 0x24) = puVar9[1];
  uVar6 = puVar9[1];
  *(undefined4 *)(unaff_EBP + -0x14) = *puVar9;
  *(undefined4 *)(unaff_EBP + -0x10) = uVar6;
  FUN_004643bc();
  uStack_4c = 0x4a731b;
  pvVar5 = operator_new(0x198);
  *(void **)(unaff_EBP + 0xc) = pvVar5;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar5 == (void *)0x0) {
    uVar6 = 0;
  }
  else {
    uVar6 = FUN_0049ad7f();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 *)(extraout_ECX + 0x54) = uVar6;
  FUN_0049afc8();
  iVar7 = *(int *)(*(int *)(extraout_ECX + 0x54) + 4);
  *(int *)(extraout_ECX + 0x68) = iVar7;
  if (iVar7 != 0) {
    iVar7 = FUN_00428886();
    fVar3 = _DAT_00667664;
    if (iVar7 == 99) {
      *(uint *)(unaff_EBP + 0xc) = (uint)DAT_00668730;
      iVar7 = *(int *)(unaff_EBP + 0xc);
      *(uint *)(unaff_EBP + 0xc) = (uint)DAT_00668731;
      uVar8 = (uint)DAT_00668732;
      *(float *)(unaff_EBP + -0x30) = (float)iVar7 * fVar3;
      iVar7 = *(int *)(unaff_EBP + 0xc);
      *(uint *)(unaff_EBP + 0xc) = uVar8;
      *(float *)(unaff_EBP + -0x2c) = (float)iVar7 * fVar3;
      iVar7 = *(int *)(unaff_EBP + 0xc);
    }
    else {
      *(uint *)(unaff_EBP + 0xc) = (uint)DAT_0066872c;
      iVar7 = *(int *)(unaff_EBP + 0xc);
      *(uint *)(unaff_EBP + 0xc) = (uint)DAT_0066872d;
      uVar8 = (uint)DAT_0066872e;
      *(float *)(unaff_EBP + -0x30) = (float)iVar7 * fVar3;
      iVar7 = *(int *)(unaff_EBP + 0xc);
      *(uint *)(unaff_EBP + 0xc) = uVar8;
      *(float *)(unaff_EBP + -0x2c) = (float)iVar7 * fVar3;
      iVar7 = *(int *)(unaff_EBP + 0xc);
    }
    *(float *)(unaff_EBP + -0x28) = (float)iVar7 * fVar3;
    FUN_005ced6e();
  }
  iVar7 = *(int *)(extraout_ECX + 0x68);
  *(undefined4 *)(extraout_ECX + 0x6c) = *(undefined4 *)(DAT_006e486c + 0x2c);
  lprc = (LPRECT)(extraout_ECX + 0x28);
  lprc->left = *(LONG *)(iVar7 + 0x68);
  *(undefined4 *)(extraout_ECX + 0x2c) = *(undefined4 *)(iVar7 + 0x6c);
  *(undefined4 *)(extraout_ECX + 0x30) = *(undefined4 *)(iVar7 + 0x70);
  *(undefined4 *)(extraout_ECX + 0x34) = *(undefined4 *)(iVar7 + 0x74);
  OffsetRect(lprc,-lprc->left,-*(int *)(extraout_ECX + 0x2c));
  piVar1 = (int *)(extraout_ECX + 0x38);
  *piVar1 = *(int *)(extraout_ECX + 0x28);
  *(undefined4 *)(extraout_ECX + 0x3c) = *(undefined4 *)(extraout_ECX + 0x2c);
  *(undefined4 *)(extraout_ECX + 0x40) = *(undefined4 *)(extraout_ECX + 0x30);
  *(undefined4 *)(extraout_ECX + 0x44) = *(undefined4 *)(extraout_ECX + 0x34);
  *piVar1 = *piVar1 + -0x80;
  *(int *)(extraout_ECX + 0x3c) = *(int *)(extraout_ECX + 0x3c) + -0x80;
  *(int *)(extraout_ECX + 0x40) = *(int *)(extraout_ECX + 0x40) + 0x80;
  *(int *)(extraout_ECX + 0x44) = *(int *)(extraout_ECX + 0x44) + 0x80;
  iVar7 = *(int *)(DAT_006e486c + 0x3c);
  *(int *)(extraout_ECX + 0x70) = iVar7;
  if (iVar7 != 0) {
    FUN_005e357a();
    FUN_005e357a();
    if (*(int *)(*(int *)(extraout_ECX + 0x70) + 0x5c) == 0) {
      FUN_005df69e();
    }
  }
  uVar6 = 100;
  *(undefined4 *)(extraout_ECX + 0x84) = *(undefined4 *)(extraout_ECX + 0x70);
  pvVar5 = operator_new(100);
  *(void **)(unaff_EBP + 0xc) = pvVar5;
  *(undefined4 *)(unaff_EBP + -4) = 1;
  if (pvVar5 == (void *)0x0) {
    puVar9 = (undefined4 *)0x0;
  }
  else {
    puVar9 = (undefined4 *)FUN_005dfb13();
    uVar6 = extraout_ECX_00;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  *(undefined4 **)(extraout_ECX + 0x74) = puVar9;
  if (puVar9 != (undefined4 *)0x0) {
    uVar2 = *puVar9;
    *(undefined4 **)(unaff_EBP + 0xc) = &uStack_4c;
    *(undefined4 *)(unaff_EBP + 0xc) = uVar2;
    uStack_4c = uVar6;
    FUN_00436a50(4);
    iVar7 = FUN_005caed9();
    puVar9 = (undefined4 *)FUN_005caed9(*(undefined4 *)(iVar7 + 4));
    cVar4 = (**(code **)(*(int *)(unaff_EBP + 0xc) + 0xc))(*puVar9);
    puVar9 = *(undefined4 **)(extraout_ECX + 0x74);
    if (cVar4 != '\0') {
      cVar4 = FUN_005df69e();
      puVar9 = *(undefined4 **)(extraout_ECX + 0x74);
      if (cVar4 != '\0') {
        FUN_005e357a();
        goto LAB_004a74f2;
      }
    }
    if (puVar9 != (undefined4 *)0x0) {
      (**(code **)*puVar9)();
    }
    *(undefined4 *)(extraout_ECX + 0x74) = 0;
  }
LAB_004a74f2:
  iVar7 = FUN_004a76a2();
  *(int *)(unaff_EBP + 0xc) = iVar7;
  *(undefined4 *)(unaff_EBP + -4) = 2;
  if (extraout_ECX + 0x88 != iVar7) {
    FUN_004b4251();
    iVar7 = *(int *)(unaff_EBP + 0xc);
    *(undefined1 *)(extraout_ECX + 0x94) = *(undefined1 *)(iVar7 + 0xc);
    *(undefined4 *)(extraout_ECX + 0x98) = *(undefined4 *)(iVar7 + 0x10);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005db425();
  FUN_005cce97();
  *(undefined2 *)(extraout_ECX + 0x408) = 0xffff;
  FUN_004a83dc();
  if (*(int *)(extraout_ECX + 0x1c) != 0) {
    FUN_004ca03f();
  }
  (**(code **)(*(int *)(*(int *)(DAT_006e486c + 0x4c) + 0x48) + 0x38))();
  uStack_4c = 0;
  (**(code **)(*(int *)(*(int *)(DAT_006e486c + 0x4c) + 0x48) + 0x38))(0xff);
  FUN_005c4cf0();
  *(undefined4 *)(unaff_EBP + -4) = 3;
  iVar7 = FUN_005c4e90(s_stdlight_006c726c);
  if (iVar7 == 0) {
    pvVar5 = operator_new(0x5c);
    *(void **)(unaff_EBP + 0xc) = pvVar5;
    *(undefined1 *)(unaff_EBP + -4) = 4;
    if (pvVar5 == (void *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = FUN_004b48de(unaff_EBP + -0x20);
    }
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(int *)(extraout_ECX + 0x1c4) = iVar7;
    if (iVar7 != 0) {
      FUN_0060b104();
      uVar6 = FUN_004acf34();
      FUN_004b4b5e(uVar6);
    }
  }
  *(undefined1 *)(unaff_EBP + 0xe) = 0;
  *(undefined1 *)(unaff_EBP + 0xc) = 0x40;
  *(undefined1 *)(unaff_EBP + 0xd) = 0x40;
  *(undefined1 *)(unaff_EBP + -4) = 5;
  pvVar5 = operator_new(0x80);
  *(void **)(extraout_ECX + 0x1ec) = pvVar5;
  _memset(pvVar5,0,0x80);
  pvVar5 = operator_new(0x80);
  *(void **)(extraout_ECX + 0x1f0) = pvVar5;
  _memset(pvVar5,0x40,0x80);
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_004a7da6(1,1,1);
  FUN_004a7da6(2,1,1);
  FUN_004a7da6(3,1,1);
  iVar7 = 0;
  do {
    iVar10 = FUN_00479149(iVar7);
    if (iVar10 != 0) {
      FUN_0056e0df();
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 2);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c4d10();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

