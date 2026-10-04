
int FUN_0041c292(void)

{
  uint uVar1;
  char cVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  int iVar7;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar2 = (**(code **)(*extraout_ECX + 0x28))();
  if (cVar2 != '\0') {
    iVar4 = -0x2f;
    goto LAB_0041c64d;
  }
  FUN_005bc41e();
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  iVar4 = FUN_004130d2(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0xc));
  *(int *)(unaff_EBP + -0x14) = iVar4;
  if (iVar4 != 0) goto LAB_0041c38c;
  *(undefined4 *)(unaff_EBP + 0xc) = 0x40;
  iVar4 = FUN_004131a0(0);
  *(int *)(unaff_EBP + -0x14) = iVar4;
  if (iVar4 == 0) {
    iVar5 = FUN_00413178(unaff_EBP + -0xb4,unaff_EBP + 0xc);
    *(int *)(unaff_EBP + -0x14) = iVar5;
    iVar4 = 0;
    if (iVar5 != 0) goto LAB_0041c385;
    do {
      if ((s_IFF_FILE_____TYPE_FOLLOWED_BY_SI_006c2118[iVar4] != '*') &&
         (s_IFF_FILE_____TYPE_FOLLOWED_BY_SI_006c2118[iVar4] != *(char *)(unaff_EBP + -0xb4 + iVar4)
         )) goto LAB_0041c37e;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x40);
    uVar3 = (*(byte *)(unaff_EBP + -0xab) - 0x30) * 0x100 | *(byte *)(unaff_EBP + -0xa9) - 0x30;
    if (uVar3 != 0x200) {
      if (uVar3 != 0x205) {
LAB_0041c37e:
        *(undefined4 *)(unaff_EBP + -0x14) = 0xffffffa3;
        goto LAB_0041c385;
      }
      iVar4 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(unaff_EBP + -0x78),
                                         *(undefined1 *)(unaff_EBP + -0x77)),
                                *(undefined1 *)(unaff_EBP + -0x76)),
                       *(undefined1 *)(unaff_EBP + -0x75));
      *(int *)(unaff_EBP + -0x10) = iVar4;
      extraout_ECX[8] = iVar4;
    }
  }
  else {
LAB_0041c385:
    FUN_00413154();
  }
LAB_0041c38c:
  FUN_0041944d();
  iVar4 = *(int *)(unaff_EBP + -0x14);
  if (iVar4 != 0) goto LAB_0041c64d;
  FUN_005bc41e();
  pvVar6 = operator_new(0x18);
  *(void **)(unaff_EBP + -0x74) = pvVar6;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar6 == (void *)0x0) {
    pvVar6 = (void *)0x0;
  }
  else {
    FUN_0041d935(100,unaff_EBP + -0x15,unaff_EBP + 0xb,unaff_EBP + 0xf);
    *(undefined4 *)((int)pvVar6 + 0x14) = 0;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  iVar4 = *(int *)(unaff_EBP + -0x10);
  extraout_ECX[6] = (int)pvVar6;
  if (iVar4 == 0) {
LAB_0041c546:
    FUN_005bc41e();
    iVar4 = 0x40;
    while( true ) {
      *(int *)(unaff_EBP + 0xc) = iVar4;
      iVar4 = FUN_0041a545(unaff_EBP + -0x70,iVar4);
      if (((iVar4 != 0) || (uVar1 = *(uint *)(unaff_EBP + -0x6c), uVar1 < 0x4c)) ||
         (0x40000000 < (int)uVar1)) break;
      if ((*(byte *)(unaff_EBP + -0x66) & 4) == 0) {
        iVar4 = FUN_0041be7a(*(undefined4 *)(unaff_EBP + -0x70),0);
        iVar4 = FUN_0041b8c6(*(undefined4 *)(unaff_EBP + -0x70),(int)*(short *)(unaff_EBP + -0x68),
                             *(int *)(unaff_EBP + -0x66) >> 8,iVar4 + 1);
        if (iVar4 != 0) {
          *(ushort *)(iVar4 + 2) =
               *(ushort *)(iVar4 + 2) ^
               (ushort)(*(byte *)(iVar4 + 2) ^ *(byte *)(unaff_EBP + -0x66));
          *(undefined2 *)(iVar4 + 4) = *(undefined2 *)(unaff_EBP + -0x66);
          *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(unaff_EBP + 0xc);
          FUN_0046f824(unaff_EBP + -0x100,0,0x40);
          *(undefined ***)(unaff_EBP + -0x10c) = &PTR_FUN_0066651c;
          FUN_0046f847(unaff_EBP + -100,0xffffffff);
          FUN_0046f8e4(unaff_EBP + -0x10c);
          *(undefined4 *)(iVar4 + 8) = 0;
        }
      }
      else {
        *(int *)(extraout_ECX[6] + 0x14) = *(int *)(extraout_ECX[6] + 0x14) + uVar1;
      }
      iVar4 = *(int *)(unaff_EBP + 0xc) + *(int *)(unaff_EBP + -0x6c);
    }
    FUN_0041944d();
  }
  else {
    FUN_005bc41e();
    iVar4 = FUN_0041a545(unaff_EBP + -0x70,*(undefined4 *)(unaff_EBP + -0x10));
    if (((iVar4 == 0) && ((*(byte *)(unaff_EBP + -0x66) & 4) == 0)) &&
       (*(int *)(unaff_EBP + -0x70) == 0x72736d70)) {
      iVar4 = FUN_0041be7a(0x72736d70,0);
      iVar5 = FUN_0041b8c6(*(undefined4 *)(unaff_EBP + -0x70),(int)*(short *)(unaff_EBP + -0x68),
                           *(int *)(unaff_EBP + -0x66) >> 8,iVar4 + 1);
      *(ushort *)(iVar5 + 2) =
           *(ushort *)(iVar5 + 2) ^ (ushort)(*(byte *)(iVar5 + 2) ^ *(byte *)(unaff_EBP + -0x66));
      *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(unaff_EBP + -0x10);
      FUN_0046f824(unaff_EBP + -0xb4,0,0x40);
      *(undefined ***)(unaff_EBP + -0xc0) = &PTR_FUN_0066651c;
      FUN_0046f847(unaff_EBP + -100,0xffffffff);
      FUN_0046f8e4(unaff_EBP + -0xc0);
      *(undefined4 *)(iVar5 + 8) = 0;
      iVar7 = FUN_0041d2e1(iVar5,0,*(undefined4 *)(unaff_EBP + -0x70));
      iVar4 = *(int *)(iVar5 + 8);
      *(int *)(unaff_EBP + 0xc) = iVar4;
      if ((iVar7 == 0) && (iVar4 != 0)) {
        *(undefined4 *)(iVar5 + 8) = 0;
        *(int *)(unaff_EBP + -0x20) = extraout_ECX[6];
        *(undefined4 *)(unaff_EBP + -0x1c) = 0x72736d70;
        *(undefined ***)(unaff_EBP + -0x24) = &PTR_FUN_006669dc;
        *(undefined4 *)(unaff_EBP + -4) = 1;
        FUN_00464faf(unaff_EBP + -0x24,iVar4,0);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_00465055();
        FUN_00420028(*(undefined4 *)(unaff_EBP + 0xc));
        iVar4 = FUN_0041baf1(0x72736d70,0,0);
        if (iVar4 != 0) {
          FUN_0041e4d9();
          *(undefined4 *)(unaff_EBP + -0x10) = 0;
        }
      }
      else {
        *(undefined4 *)(unaff_EBP + -0x10) = 0;
      }
    }
    else {
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      *(undefined4 *)(unaff_EBP + -0x14) = 0xffffffd1;
    }
    FUN_0041944d();
    iVar4 = *(int *)(unaff_EBP + -0x14);
    if (iVar4 != 0) goto LAB_0041c64d;
    if (*(int *)(unaff_EBP + -0x10) == 0) goto LAB_0041c546;
  }
  FUN_0041bde8(0x72736d70);
  *(undefined1 *)(extraout_ECX + 9) = 0;
  FUN_0041944d();
  iVar4 = 0;
LAB_0041c64d:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar4;
}

