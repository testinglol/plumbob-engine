
int FUN_004190d3(void)

{
  uint uVar1;
  char cVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar2 = (**(code **)(*extraout_ECX + 0x28))();
  if (cVar2 != '\0') {
    iVar4 = -0x2f;
    goto LAB_0041943c;
  }
  FUN_005bc41e();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  iVar4 = FUN_004130d2(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc));
  *(int *)(unaff_EBP + 0xc) = iVar4;
  if (iVar4 != 0) goto LAB_004191cd;
  *(undefined4 *)(unaff_EBP + 8) = 0x40;
  iVar4 = FUN_004131a0(0);
  *(int *)(unaff_EBP + 0xc) = iVar4;
  if (iVar4 == 0) {
    iVar5 = FUN_00413178(unaff_EBP + -0xac,unaff_EBP + 8);
    *(int *)(unaff_EBP + 0xc) = iVar5;
    iVar4 = 0;
    if (iVar5 != 0) goto LAB_004191c6;
    do {
      if ((s_IFF_FILE_____TYPE_FOLLOWED_BY_SI_006c2084[iVar4] != '*') &&
         (s_IFF_FILE_____TYPE_FOLLOWED_BY_SI_006c2084[iVar4] != *(char *)(unaff_EBP + -0xac + iVar4)
         )) goto LAB_004191bf;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x40);
    uVar3 = (*(byte *)(unaff_EBP + -0xa3) - 0x30) * 0x100 | *(byte *)(unaff_EBP + -0xa1) - 0x30;
    if (uVar3 != 0x200) {
      if (uVar3 != 0x205) {
LAB_004191bf:
        *(undefined4 *)(unaff_EBP + 0xc) = 0xffffffa3;
        goto LAB_004191c6;
      }
      iVar4 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(unaff_EBP + -0x70),
                                         *(undefined1 *)(unaff_EBP + -0x6f)),
                                *(undefined1 *)(unaff_EBP + -0x6e)),
                       *(undefined1 *)(unaff_EBP + -0x6d));
      *(int *)(unaff_EBP + -0x10) = iVar4;
      extraout_ECX[8] = iVar4;
    }
  }
  else {
LAB_004191c6:
    FUN_00413154();
  }
LAB_004191cd:
  FUN_0041944d();
  iVar4 = *(int *)(unaff_EBP + 0xc);
  if (iVar4 != 0) goto LAB_0041943c;
  FUN_005bc41e();
  puVar6 = operator_new(0x10);
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    *puVar6 = 0;
    puVar6[1] = 0;
    puVar6[2] = 0;
    puVar6[3] = 0;
  }
  iVar4 = *(int *)(unaff_EBP + -0x10);
  extraout_ECX[6] = (int)puVar6;
  if (iVar4 == 0) {
LAB_00419353:
    FUN_005bc41e();
    iVar4 = 0x40;
    while( true ) {
      *(int *)(unaff_EBP + 0xc) = iVar4;
      iVar4 = FUN_0041a545(unaff_EBP + -0x6c,iVar4);
      if (((iVar4 != 0) || (uVar1 = *(uint *)(unaff_EBP + -0x68), uVar1 < 0x4c)) ||
         (0x40000000 < (int)uVar1)) break;
      if ((*(byte *)(unaff_EBP + -0x62) & 4) == 0) {
        puVar6 = (undefined4 *)FUN_00418ca9(*(undefined4 *)(unaff_EBP + -0x6c));
        if (puVar6 != (undefined4 *)0x0) {
          puVar6[1] = (int)*(short *)(unaff_EBP + -100);
          *(undefined2 *)(puVar6 + 2) = *(undefined2 *)(unaff_EBP + -0x62);
          *(undefined2 *)((int)puVar6 + 10) = *(undefined2 *)(unaff_EBP + -0x62);
          *puVar6 = *(undefined4 *)(unaff_EBP + 0xc);
          FUN_0046f824(unaff_EBP + -0xf8,0,0x40);
          *(undefined ***)(unaff_EBP + -0x104) = &PTR_FUN_0066651c;
          FUN_0046f847(unaff_EBP + -0x60,0xffffffff);
          FUN_0046f8e4(unaff_EBP + -0x104);
          puVar6[3] = 0;
        }
      }
      else {
        *(int *)(extraout_ECX[6] + 0xc) = *(int *)(extraout_ECX[6] + 0xc) + uVar1;
      }
      iVar4 = *(int *)(unaff_EBP + 0xc) + *(int *)(unaff_EBP + -0x68);
    }
    FUN_0041944d();
  }
  else {
    FUN_005bc41e();
    iVar4 = FUN_0041a545(unaff_EBP + -0x6c,*(undefined4 *)(unaff_EBP + -0x10));
    if (((iVar4 == 0) && ((*(byte *)(unaff_EBP + -0x62) & 4) == 0)) &&
       (*(int *)(unaff_EBP + -0x6c) == 0x72736d70)) {
      puVar6 = (undefined4 *)FUN_00418ca9(0x72736d70);
      puVar6[1] = (int)*(short *)(unaff_EBP + -100);
      *(undefined2 *)(puVar6 + 2) = *(undefined2 *)(unaff_EBP + -0x62);
      *puVar6 = *(undefined4 *)(unaff_EBP + -0x10);
      FUN_0046f824(unaff_EBP + -0xac,0,0x40);
      *(undefined ***)(unaff_EBP + -0xb8) = &PTR_FUN_0066651c;
      FUN_0046f847(unaff_EBP + -0x60,0xffffffff);
      FUN_0046f8e4(unaff_EBP + -0xb8);
      puVar6[3] = 0;
      iVar5 = FUN_0041a23d(puVar6,0,*(undefined4 *)(unaff_EBP + -0x6c));
      iVar4 = puVar6[3];
      *(int *)(unaff_EBP + 8) = iVar4;
      if ((iVar5 == 0) && (iVar4 != 0)) {
        puVar6[3] = 0;
        *(int *)(unaff_EBP + -0x18) = extraout_ECX[6];
        *(undefined4 *)(unaff_EBP + -0x14) = 0x72736d70;
        *(undefined ***)(unaff_EBP + -0x1c) = &PTR_FUN_006668c4;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        FUN_00464faf(unaff_EBP + -0x1c,iVar4,0);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_00465055();
        FUN_00420028(*(undefined4 *)(unaff_EBP + 8));
        iVar4 = FUN_00418d1a(0x72736d70,0,0);
        if (iVar4 != 0) {
          FUN_0041a84b(*(undefined4 *)extraout_ECX[6],((undefined4 *)extraout_ECX[6])[1]);
          *(undefined4 *)(unaff_EBP + -0x10) = 0;
        }
      }
      else {
        *(undefined4 *)(unaff_EBP + -0x10) = 0;
      }
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      *(undefined4 *)(unaff_EBP + 0xc) = 0xffffffd1;
    }
    FUN_0041944d();
    iVar4 = *(int *)(unaff_EBP + 0xc);
    if (iVar4 != 0) goto LAB_0041943c;
    if (*(int *)(unaff_EBP + -0x10) == 0) goto LAB_00419353;
  }
  FUN_00418f91(0x72736d70);
  *(undefined1 *)(extraout_ECX + 9) = 0;
  FUN_0041944d();
  iVar4 = 0;
LAB_0041943c:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar4;
}

