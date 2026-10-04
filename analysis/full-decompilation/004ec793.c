
undefined4 FUN_004ec793(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar4;
  bool bVar5;
  
  FUN_00634c24();
  cVar1 = (**(code **)(*extraout_ECX + 200))();
  if (cVar1 == '\0') {
    (**(code **)(*extraout_ECX + 0x174))(1,0);
    (**(code **)(*extraout_ECX + 0x90))(4,0);
    FUN_00511f67(0xf,s_MagicMasterSpells_iff_006c9ea8,extraout_ECX + 0x48);
    FUN_00511f67(0x10,s_MagicMasterSpells_iff_006c9ea8,extraout_ECX + 99);
    FUN_004ed071();
    *(undefined4 *)(unaff_EBP + -0x18) = 0;
    iVar4 = extraout_ECX[0x37];
    *(undefined4 *)(unaff_EBP + -0x14) = 1;
    if (0 < iVar4) {
      do {
        iVar2 = FUN_004ecfea(*(undefined4 *)(unaff_EBP + -0x14));
        iVar4 = DAT_006f38b0;
        *(int *)(unaff_EBP + -0x18) = iVar2;
        if (iVar4 == 1) {
          if ((*(int *)(unaff_EBP + -0x14) != 0xc) &&
             (((*(ushort *)(DAT_006e486c + 0x66) & 0x20) != 0 || (iVar2 != 0x16)))) {
            if ((*(ushort *)(DAT_006e486c + 0x66) & 0x40) == 0) {
              bVar5 = iVar2 == 10;
LAB_004ec885:
              if (bVar5) goto LAB_004ec892;
            }
            goto LAB_004ec887;
          }
        }
        else {
          if (iVar4 == 2) {
            if ((((*(byte *)(DAT_006e486c + 0x66) & 0x20) == 0) && (iVar2 == 7)) ||
               (((char)extraout_ECX[0x3b] != '\0' && (iVar2 == 9)))) goto LAB_004ec892;
            if (*(char *)((int)extraout_ECX + 0xed) != '\0') {
              bVar5 = iVar2 == 4;
              goto LAB_004ec885;
            }
          }
LAB_004ec887:
          FUN_0042eab4(unaff_EBP + -0x18);
        }
LAB_004ec892:
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
      } while (*(int *)(unaff_EBP + -0x14) <= extraout_ECX[0x37]);
    }
    iVar4 = extraout_ECX[0x39];
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    iVar2 = extraout_ECX[0x38];
    *(undefined4 *)(unaff_EBP + -0x20) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
    extraout_ECX[0x37] = iVar4 - iVar2 >> 2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004ecee7(unaff_EBP + -0x24);
    FUN_005a5631(0x139c,extraout_ECX + 0x42,4);
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    iVar4 = *(int *)(unaff_EBP + -0x20) - *(int *)(unaff_EBP + -0x24) >> 2;
    FUN_0054821c(iVar4,unaff_EBP + -0xd);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    uVar3 = FUN_005fd5b4(*(undefined4 *)(unaff_EBP + -0x30),iVar4,unaff_EBP + -0x14,
                         *(undefined4 *)(unaff_EBP + -0x18));
    *(undefined4 *)(unaff_EBP + -0x2c) = uVar3;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_004ed07c(unaff_EBP + -0x30);
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_0048c4c9();
    iVar4 = extraout_ECX[0x42];
    iVar2 = *(int *)(iVar4 + 0x1c);
    extraout_ECX[0x46] = iVar2;
    extraout_ECX[0x45] = *(int *)(iVar4 + 0x20) / 3;
    FUN_004ec186(iVar2);
    FUN_004ec1a7(extraout_ECX[0x45] << 2);
    if ((int *)extraout_ECX[0x16] != (int *)0x0) {
      cVar1 = (**(code **)(*(int *)extraout_ECX[0x16] + 0x20))(1);
      if (cVar1 != '\0') {
        (**(code **)(*(int *)extraout_ECX[0x16] + 0x38))(DAT_006f2a64,0);
        (**(code **)(*(int *)extraout_ECX[0x16] + 0x68))(DAT_006f2a64);
      }
    }
    extraout_ECX[0x44] = 0;
    FUN_004ecd80();
    iVar4 = extraout_ECX[0x37] / 4;
    extraout_ECX[0x36] = iVar4;
    if (extraout_ECX[0x37] % 4 != 0) {
      extraout_ECX[0x36] = iVar4 + 1;
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_0048c4c9();
    uVar3 = 1;
  }
  else {
    uVar3 = FUN_005dbf32();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

