
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00588351(void)

{
  float fVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int *extraout_ECX;
  int unaff_EBP;
  float10 fVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  FUN_00634c24();
  uVar2 = FUN_004705f2(1,0xffffffff);
  FUN_005b870f(uVar2);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  pvVar3 = operator_new(0xb0);
  *(void **)(unaff_EBP + -0x34) = pvVar3;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (pvVar3 == (void *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_005a04d1();
  }
  *(undefined1 *)(unaff_EBP + -4) = 0;
  extraout_ECX[2] = iVar4;
  FUN_005a055f(DAT_006f6b64,DAT_006f6b68,unaff_EBP + -100,0,0);
  *(int **)(extraout_ECX[2] + 0x14) = extraout_ECX;
  *(int *)(unaff_EBP + -0x34) = extraout_ECX[0x62];
  extraout_ECX[100] = 3;
  (**(code **)(*extraout_ECX + 0xc))();
  uVar2 = *(undefined4 *)(unaff_EBP + -100);
  *(undefined1 *)(extraout_ECX + 0x36) = 1;
  *(undefined1 *)((int)extraout_ECX + 0xd9) = 1;
  FUN_00635858(unaff_EBP + -0x174,s__s_needs_006d0d58,uVar2);
  FUN_005b870f(unaff_EBP + -0x174);
  iVar4 = *extraout_ECX;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  iVar4 = (**(code **)(iVar4 + 0xec))(unaff_EBP + -0x40);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  extraout_ECX[0x93] = iVar4;
  FUN_005b8770();
  FUN_005954bc();
  (**(code **)(*extraout_ECX + 0x1c))();
  iVar4 = *extraout_ECX;
  *(float *)(unaff_EBP + -0x10) = _DAT_00666a54 / _DAT_00671ed4;
  fVar7 = (float10)(**(code **)(iVar4 + 0x120))(0x13);
  extraout_ECX[0x7e] = (int)(float)(fVar7 * (float10)*(float *)(unaff_EBP + -0x10));
  fVar7 = (float10)(**(code **)(*extraout_ECX + 0x120))(0x15);
  extraout_ECX[0x7f] =
       (int)(float)(fVar7 * (float10)_DAT_00666578 * (float10)*(float *)(unaff_EBP + -0x10));
  fVar7 = (float10)(**(code **)(*extraout_ECX + 0x120))(0x14);
  extraout_ECX[0x80] =
       (int)(float)(fVar7 * (float10)_DAT_00666578 * (float10)*(float *)(unaff_EBP + -0x10));
  fVar7 = (float10)(**(code **)(*extraout_ECX + 0x120))(0x16);
  extraout_ECX[0x81] = (int)(float)(fVar7 * (float10)*(float *)(unaff_EBP + -0x10));
  fVar7 = (float10)(**(code **)(*extraout_ECX + 0x120))(0x17);
  extraout_ECX[0x82] =
       (int)(float)(fVar7 * (float10)_DAT_00666578 * (float10)*(float *)(unaff_EBP + -0x10));
  extraout_ECX[0x83] = (int)((float)extraout_ECX[0x80] * _DAT_00668220);
  (**(code **)(*extraout_ECX + 0x90))(0);
  FUN_0059245c(extraout_ECX[0xa0]);
  uVar2 = (**(code **)(*extraout_ECX + 0xf4))(3);
  (**(code **)(*extraout_ECX + 0x100))(extraout_ECX + 5,uVar2,0);
  if ((extraout_ECX[0x4e] == 0) ||
     ((*(byte *)(*(int *)(extraout_ECX[0x4e] + 0x118) + 0xcc) & 2) == 0)) {
    (**(code **)(*extraout_ECX + 0xf8))(0x14,0);
    iVar4 = *(int *)(extraout_ECX[3] + 4);
    FUN_005b8680();
    *(undefined1 *)(unaff_EBP + -4) = 3;
    FUN_005b8680();
    iVar5 = *extraout_ECX;
    *(undefined1 *)(unaff_EBP + -4) = 4;
    uVar2 = (**(code **)(iVar5 + 0x128))(iVar4,s_anchor_006d0d50,&DAT_006c0d8c,unaff_EBP + -0x40);
    *(undefined4 *)(unaff_EBP + -0x30) = uVar2;
    uVar2 = (**(code **)(*extraout_ECX + 0x128))
                      (iVar4,s_anchor_006d0d50,&DAT_006c8398,unaff_EBP + -0x58);
    *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
    iVar5 = FUN_005990f7(unaff_EBP + -0x40);
    extraout_ECX[0x5a] = iVar5;
    iVar5 = FUN_005990f7(unaff_EBP + -0x58);
    extraout_ECX[0x5b] = iVar5;
    fVar1 = *(float *)(iVar4 + 0x2c);
    extraout_ECX[0x5c] = (int)((float)*(int *)(unaff_EBP + -0x30) / fVar1);
    extraout_ECX[0x5d] = (int)((float)*(int *)(unaff_EBP + -0x14) / fVar1);
    uVar2 = (**(code **)(*extraout_ECX + 0x34))();
    *(undefined4 *)(unaff_EBP + -0x30) = uVar2;
    *(undefined4 *)(extraout_ECX[3] + 0x2c) = 0x3f800000;
    uVar2 = *(undefined4 *)(unaff_EBP + -0x30);
    *(int *)(extraout_ECX[3] + 0x28) = extraout_ECX[0x5d];
    FUN_005992ca(uVar2,1,1);
    (**(code **)(*extraout_ECX + 0x60))();
    FUN_005994da(0);
    FUN_005a1444(0);
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    uVar2 = FUN_00595f4e();
    puVar6 = (undefined4 *)FUN_005c3840(unaff_EBP + -0x4c,unaff_EBP + -0x2c,uVar2);
    *(undefined4 *)(unaff_EBP + -0x2c) = *puVar6;
    *(undefined4 *)(unaff_EBP + -0x28) = puVar6[1];
    *(undefined4 *)(unaff_EBP + -0x24) = puVar6[2];
    *(float *)(unaff_EBP + -0x14) = *(float *)(unaff_EBP + -0x24) * *(float *)(unaff_EBP + -0x10);
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    uVar2 = FUN_00595f4e();
    puVar6 = (undefined4 *)FUN_005c3840(unaff_EBP + -0x4c,unaff_EBP + -0x20,uVar2);
    *(undefined4 *)(unaff_EBP + -0x20) = *puVar6;
    *(undefined4 *)(unaff_EBP + -0x1c) = puVar6[1];
    *(undefined4 *)(unaff_EBP + -0x18) = puVar6[2];
    uVar2 = *(undefined4 *)(unaff_EBP + -0x30);
    extraout_ECX[0x5f] =
         (int)(*(float *)(unaff_EBP + -0x18) * *(float *)(unaff_EBP + -0x10) -
              *(float *)(unaff_EBP + -0x14));
    *(int *)(extraout_ECX[3] + 0x28) = extraout_ECX[0x5c];
    FUN_005992ca(uVar2,1,1);
    (**(code **)(*extraout_ECX + 0x60))();
    FUN_005994da(0);
    FUN_005a1444(0);
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    *(undefined4 *)(unaff_EBP + -0x28) = 0;
    *(undefined4 *)(unaff_EBP + -0x2c) = 0;
    uVar2 = FUN_00595f4e();
    puVar6 = (undefined4 *)FUN_005c3840(unaff_EBP + -0x4c,unaff_EBP + -0x2c,uVar2);
    *(undefined4 *)(unaff_EBP + -0x2c) = *puVar6;
    *(undefined4 *)(unaff_EBP + -0x28) = puVar6[1];
    *(undefined4 *)(unaff_EBP + -0x24) = puVar6[2];
    *(float *)(unaff_EBP + -0x14) = *(float *)(unaff_EBP + -0x24) * *(float *)(unaff_EBP + -0x10);
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    uVar2 = FUN_00595f4e();
    puVar6 = (undefined4 *)FUN_005c3840(unaff_EBP + -0x4c,unaff_EBP + -0x20,uVar2);
    *(undefined4 *)(unaff_EBP + -0x20) = *puVar6;
    *(undefined4 *)(unaff_EBP + -0x1c) = puVar6[1];
    *(undefined4 *)(unaff_EBP + -0x18) = puVar6[2];
    *(undefined1 *)(unaff_EBP + -4) = 3;
    extraout_ECX[0x5e] =
         (int)(*(float *)(unaff_EBP + -0x14) -
              *(float *)(unaff_EBP + -0x18) * *(float *)(unaff_EBP + -0x10));
    FUN_005b8770();
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_005b8770();
  }
  else if (*(int *)(extraout_ECX[2] + 4) != 0) {
    uVar9 = 1;
    uVar8 = 1;
    uVar2 = (**(code **)(*extraout_ECX + 0x34))(1,1);
    FUN_005992ca(uVar2,uVar8,uVar9);
  }
  if (extraout_ECX[3] != 0) {
    FUN_005a0903(extraout_ECX[3]);
  }
  extraout_ECX[0x26] = -1;
  iVar4 = *(int *)(unaff_EBP + -0x34);
  extraout_ECX[3] = 0;
  *(undefined1 *)((int)extraout_ECX + 0xd9) = 1;
  if (iVar4 != 0) {
    extraout_ECX[0x62] = 3;
  }
  extraout_ECX[0xa1] = 1;
  (**(code **)(*extraout_ECX + 0x60))();
  iVar4 = *(int *)(DAT_006e486c + 4);
  iVar5 = *extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x74) = *(undefined4 *)(iVar4 + 0x28);
  *(undefined4 *)(unaff_EBP + -0x70) = *(undefined4 *)(iVar4 + 0x2c);
  *(undefined4 *)(unaff_EBP + -0x6c) = *(undefined4 *)(iVar4 + 0x30);
  *(undefined4 *)(unaff_EBP + -0x68) = *(undefined4 *)(iVar4 + 0x34);
  (**(code **)(iVar5 + 0x6c))(unaff_EBP + -0x74);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

