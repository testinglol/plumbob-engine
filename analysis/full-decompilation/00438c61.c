
void FUN_00438c61(void)

{
  undefined4 uVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  int unaff_EBP;
  int *piVar6;
  
  FUN_00634c24();
  iVar2 = DAT_006e486c;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  piVar6 = *(int **)(unaff_EBP + 0x14);
  *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(iVar2 + 0x28);
  do {
    uVar1 = *(undefined4 *)(unaff_EBP + -0x18);
    *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
    iVar2 = FUN_0043ae5e(*(undefined4 *)(unaff_EBP + 8),uVar1);
    *(int *)(unaff_EBP + -0x20) = iVar2;
    if (iVar2 == 0) {
      if (1 < (uint)(piVar6[1] - *piVar6 >> 4)) {
        FUN_00439363(*piVar6,piVar6[1],&LAB_00438d68);
      }
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return;
    }
    FUN_004318eb(unaff_EBP + -0x10,unaff_EBP + -0x14);
    iVar2 = 0;
    uVar4 = *(uint *)(unaff_EBP + 0xc) & 7;
    iVar5 = 0;
    if (uVar4 == 0) {
      iVar2 = *(int *)(unaff_EBP + -0x10);
      iVar5 = *(int *)(unaff_EBP + -0x14);
    }
    else if (uVar4 == 2) {
      iVar5 = *(int *)(unaff_EBP + -0x10);
      iVar2 = -*(int *)(unaff_EBP + -0x14);
    }
    else {
      if (uVar4 == 4) {
        iVar5 = *(int *)(unaff_EBP + -0x14);
        iVar2 = -*(int *)(unaff_EBP + -0x10);
      }
      else {
        if (uVar4 != 6) goto LAB_00438cee;
        iVar2 = *(int *)(unaff_EBP + -0x14);
        iVar5 = *(int *)(unaff_EBP + -0x10);
      }
      iVar5 = -iVar5;
    }
LAB_00438cee:
    *(undefined1 *)(unaff_EBP + -0x2a) = 0;
    bVar3 = (byte)*(undefined4 *)(unaff_EBP + 0x10);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(char *)(unaff_EBP + -0x2c) = (char)iVar2;
    *(int *)(unaff_EBP + -0x24) = (iVar5 + iVar2) * (4 << (bVar3 & 0x1f));
    piVar6 = *(int **)(unaff_EBP + 0x14);
    *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(unaff_EBP + -0x20);
    *(char *)(unaff_EBP + -0x2b) = (char)iVar5;
    *(int *)(unaff_EBP + -0x28) = (iVar2 - iVar5) * (8 << (bVar3 & 0x1f));
    FUN_0043911d(unaff_EBP + -0x30);
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  } while( true );
}

