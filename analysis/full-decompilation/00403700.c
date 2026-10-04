
undefined1 FUN_00403700(void)

{
  undefined4 *puVar1;
  ushort uVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 uVar7;
  int unaff_EBP;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  
  FUN_00634c24();
  FUN_0046ea4d();
  iVar8 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar3 = FUN_0046eaca(*(undefined4 *)(unaff_EBP + 8));
  iVar6 = DAT_006e486c;
  if (iVar3 == 0) {
    *(undefined4 *)(unaff_EBP + -0x20) = 0xb;
    uVar2 = *(ushort *)(iVar6 + 0x66);
    if (0 < (short)uVar2) {
      *(undefined4 *)(unaff_EBP + -0x20) = 0x10;
    }
    if ((uVar2 & 0x20) != 0) {
      *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 5;
    }
    if (0 < *(int *)(unaff_EBP + -0x20)) {
      do {
        pvVar4 = operator_new(0x74);
        *(void **)(unaff_EBP + -0x44) = pvVar4;
        *(undefined1 *)(unaff_EBP + -4) = 1;
        if (pvVar4 == (void *)0x0) {
          uVar5 = 0;
        }
        else {
          uVar5 = FUN_00403586();
        }
        *(undefined1 *)(unaff_EBP + -4) = 0;
        *(undefined4 *)(unaff_EBP + 8) = uVar5;
        FUN_004055b8(unaff_EBP + 8);
        iVar6 = iVar8 * 4;
        iVar8 = iVar8 + 1;
        **(int **)(iVar6 + DAT_006de7f8) = iVar8;
        uVar5 = FUN_004032ba();
        *(undefined1 *)(unaff_EBP + -4) = 2;
        FUN_004055ea(10,uVar5);
        *(undefined1 *)(unaff_EBP + -4) = 0;
        FUN_005b8770();
      } while (iVar8 < *(int *)(unaff_EBP + -0x20));
    }
    **(undefined4 **)(DAT_006de7f8 + 0x28) = 0xffffffff;
    FUN_0046ed9c();
    uVar5 = FUN_0046ed90();
    *(undefined4 *)(unaff_EBP + -0x4c) = uVar5;
    iVar8 = FUN_0046eeb1(1,2);
    *(int *)(unaff_EBP + -0x44) = iVar8;
    if (iVar8 == 0) {
      *(undefined4 *)(unaff_EBP + -0x48) = 4;
      *(undefined4 *)(unaff_EBP + -0x38) = 0xf;
    }
    else {
      if (iVar8 != 1) goto LAB_00403c74;
      *(undefined4 *)(unaff_EBP + -0x48) = 5;
      *(undefined4 *)(unaff_EBP + -0x38) = 0x12;
    }
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    if (0 < *(int *)(unaff_EBP + -0x20)) {
      *(undefined4 *)(unaff_EBP + 8) = 1;
LAB_00403852:
      iVar8 = *(int *)(unaff_EBP + -0x48);
      iVar6 = *(int *)(DAT_006de7f8 + *(int *)(unaff_EBP + -0x24) * 4);
      *(int *)(unaff_EBP + -0x40) = iVar6;
      uVar5 = FUN_0046edbd(*(undefined4 *)(unaff_EBP + 8),iVar8);
      FUN_0046f8cb(uVar5);
      *(undefined4 *)(unaff_EBP + -0x28) = 0;
      *(int *)(unaff_EBP + -0x30) = iVar8 + 1;
      iVar8 = iVar8 + 2;
      do {
        if (*(int *)(unaff_EBP + -0x4c) < *(int *)(unaff_EBP + -0x38) + -2 + iVar8)
        goto LAB_00403c74;
        puVar1 = (undefined4 *)(*(int *)(unaff_EBP + -0x28) + *(int *)(iVar6 + 4));
        uVar5 = FUN_0046edbd(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x30));
        FUN_0046f8cb(uVar5);
        iVar6 = FUN_0046eeb1(*(undefined4 *)(unaff_EBP + 8),iVar8);
        puVar1[1] = iVar6 * 100;
        iVar6 = FUN_0046eeb1(*(undefined4 *)(unaff_EBP + 8),iVar8 + 1);
        puVar1[2] = iVar6 * 100;
        iVar6 = FUN_0046eeb1(*(undefined4 *)(unaff_EBP + 8),iVar8 + 2);
        puVar1[3] = iVar6 * 100;
        iVar6 = FUN_0046eeb1(*(undefined4 *)(unaff_EBP + 8),iVar8 + 3);
        puVar1[4] = iVar6 * 100;
        iVar6 = FUN_0046eeb1(*(undefined4 *)(unaff_EBP + 8),iVar8 + 4);
        puVar1[5] = iVar6 * 100;
        iVar6 = FUN_0046eeb1(*(undefined4 *)(unaff_EBP + 8),iVar8 + 5);
        puVar1[6] = iVar6 * 100;
        uVar5 = FUN_0046eeb1(*(undefined4 *)(unaff_EBP + 8),iVar8 + 6);
        *puVar1 = uVar5;
        uVar5 = FUN_0046eeb1(*(undefined4 *)(unaff_EBP + 8),iVar8 + 7);
        puVar1[0x11] = uVar5;
        puVar10 = puVar1 + 0x13;
        puVar9 = puVar1 + 0x12;
        uVar5 = FUN_0046edbd(*(undefined4 *)(unaff_EBP + 8),iVar8 + 8);
        FUN_00403c9d(uVar5,puVar9,puVar10);
        uVar5 = FUN_0046edbd(*(undefined4 *)(unaff_EBP + 8),iVar8 + 10);
        *(undefined4 *)(unaff_EBP + -0x10) = uVar5;
        FUN_0046f824(unaff_EBP + -0x208,0,0x40);
        *(undefined ***)(unaff_EBP + -0x214) = &PTR_FUN_0066651c;
        FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x10),0xffffffff);
        FUN_0046f8e4(unaff_EBP + -0x214);
        if (*(int *)(unaff_EBP + -0x44) == 1) {
          uVar5 = FUN_0046edbd(*(undefined4 *)(unaff_EBP + 8),iVar8 + 0xb);
          *(undefined4 *)(unaff_EBP + -0x10) = uVar5;
          FUN_0046f824(unaff_EBP + -0x124,0,0x40);
          *(undefined ***)(unaff_EBP + -0x130) = &PTR_FUN_0066651c;
          FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x10),0xffffffff);
          FUN_0046f8e4(unaff_EBP + -0x130);
          uVar5 = FUN_0046edbd(*(undefined4 *)(unaff_EBP + 8),iVar8 + 0xc);
          *(undefined4 *)(unaff_EBP + -0x10) = uVar5;
          FUN_0046f824(unaff_EBP + -0x8c,0,0x40);
          *(undefined ***)(unaff_EBP + -0x98) = &PTR_FUN_0066651c;
          FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x10),0xffffffff);
          FUN_0046f8e4(unaff_EBP + -0x98);
          uVar5 = FUN_0046edbd(*(undefined4 *)(unaff_EBP + 8),iVar8 + 0xd);
          *(undefined4 *)(unaff_EBP + -0x10) = uVar5;
          FUN_0046f824(unaff_EBP + -0x1bc,0,0x40);
          *(undefined ***)(unaff_EBP + -0x1c8) = &PTR_FUN_0066651c;
          FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x10),0xffffffff);
          FUN_0046f8e4(unaff_EBP + -0x1c8);
          uVar5 = FUN_0046edbd(*(undefined4 *)(unaff_EBP + 8),iVar8 + 0xe);
          *(undefined4 *)(unaff_EBP + -0x10) = uVar5;
          FUN_0046fb9b(unaff_EBP + -0x314,0x100);
          *(undefined ***)(unaff_EBP + -800) = &PTR_LAB_0066655c;
          FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x10),0xffffffff);
          iVar6 = 0;
          while( true ) {
            iVar6 = FUN_0046fab1(&DAT_006c0c2c,iVar6);
            if (iVar6 < 0) break;
            *(undefined1 *)(*(int *)(unaff_EBP + -0x31c) + iVar6) = 0x2d;
            iVar6 = iVar6 + 1;
          }
          iVar6 = puVar1[0x13] - puVar1[0x12];
          *(int *)(unaff_EBP + -0x10) = iVar6;
          if (iVar6 < 0) {
            *(int *)(unaff_EBP + -0x10) = iVar6 + 0x18;
          }
          *(undefined4 *)(unaff_EBP + -0x34) = 0;
          *(undefined4 *)(unaff_EBP + -0x3c) = 0;
          *(undefined4 **)(unaff_EBP + -0x2c) = puVar1 + 10;
          do {
            if (*(int *)(unaff_EBP + -0x34) < 0) break;
            iVar6 = FUN_00635f62(*(int *)(unaff_EBP + -0x31c) + *(int *)(unaff_EBP + -0x34));
            **(int **)(unaff_EBP + -0x2c) = iVar6 / *(int *)(unaff_EBP + -0x10);
            iVar6 = FUN_0046fab1(&DAT_006c0c28,*(int *)(unaff_EBP + -0x34) + 1);
            *(int *)(unaff_EBP + -0x2c) = *(int *)(unaff_EBP + -0x2c) + 4;
            *(int *)(unaff_EBP + -0x3c) = *(int *)(unaff_EBP + -0x3c) + 1;
            *(int *)(unaff_EBP + -0x34) = iVar6 + 1;
          } while (*(int *)(unaff_EBP + -0x3c) < 7);
          uVar5 = FUN_0046eeb1(*(undefined4 *)(unaff_EBP + 8),iVar8 + 0xf);
          puVar1[0x14] = uVar5;
        }
        else {
          uVar5 = FUN_0046edbd(*(undefined4 *)(unaff_EBP + 8),iVar8 + 0xb);
          *(undefined4 *)(unaff_EBP + -0x10) = uVar5;
          FUN_0046f824(unaff_EBP + -0xd8,0,0x40);
          *(undefined ***)(unaff_EBP + -0xe4) = &PTR_FUN_0066651c;
          FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x10),0xffffffff);
          FUN_0046f8e4(unaff_EBP + -0xe4);
          uVar5 = FUN_0046edbd(*(undefined4 *)(unaff_EBP + 8),iVar8 + 0xc);
          *(undefined4 *)(unaff_EBP + -0x10) = uVar5;
          FUN_0046f824(unaff_EBP + -0x170,0,0x40);
          *(undefined ***)(unaff_EBP + -0x17c) = &PTR_FUN_0066651c;
          FUN_0046f847(*(undefined4 *)(unaff_EBP + -0x10),0xffffffff);
          FUN_0046f8e4(unaff_EBP + -0x17c);
        }
        if (**(int **)(unaff_EBP + -0x40) == -1) goto LAB_00403c5e;
        *(int *)(unaff_EBP + -0x28) = *(int *)(unaff_EBP + -0x28) + 0x3c0;
        *(int *)(unaff_EBP + -0x30) = *(int *)(unaff_EBP + -0x30) + *(int *)(unaff_EBP + -0x38);
        iVar8 = iVar8 + *(int *)(unaff_EBP + -0x38);
        if (0x257f < *(int *)(unaff_EBP + -0x28)) goto LAB_00403c5e;
        iVar6 = *(int *)(unaff_EBP + -0x40);
      } while( true );
    }
LAB_00403c70:
    uVar7 = 1;
  }
  else {
LAB_00403c74:
    uVar7 = 0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0046ea5a();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar7;
LAB_00403c5e:
  *(int *)(unaff_EBP + -0x24) = *(int *)(unaff_EBP + -0x24) + 1;
  *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
  if (*(int *)(unaff_EBP + -0x20) <= *(int *)(unaff_EBP + -0x24)) goto LAB_00403c70;
  goto LAB_00403852;
}

