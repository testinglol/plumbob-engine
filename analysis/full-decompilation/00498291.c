
uint FUN_00498291(void)

{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  char *pcVar6;
  byte *pbVar7;
  int extraout_ECX;
  int iVar8;
  int unaff_EBP;
  bool bVar9;
  
  uVar3 = FUN_00634c24();
  pcVar6 = *(char **)(unaff_EBP + 8);
  cVar2 = *pcVar6;
  uVar4 = CONCAT31((int3)((uint)uVar3 >> 8),cVar2);
  *(int *)(unaff_EBP + -0x1c) = extraout_ECX;
  if ('\0' < cVar2) {
    uVar4 = (uint)cVar2;
    iVar8 = *(int *)(DAT_006e54dc + 0x10) + -1;
    if ((int)uVar4 < iVar8) {
      cVar1 = pcVar6[1];
      uVar4 = CONCAT31(cVar2 >> 7,cVar1);
      if (('\0' < cVar1) && (uVar4 = (uint)cVar1, (int)uVar4 < iVar8)) {
        cVar2 = pcVar6[3];
        uVar4 = CONCAT31(cVar1 >> 7,cVar2);
        if (('\0' < cVar2) && (uVar4 = (uint)cVar2, (int)uVar4 < iVar8)) {
          cVar1 = pcVar6[4];
          uVar4 = CONCAT31(cVar2 >> 7,cVar1);
          if (('\0' < cVar1) && (uVar4 = (uint)cVar1, (int)uVar4 < iVar8)) {
            *(undefined1 *)(unaff_EBP + -0x1e) = 0;
            *(undefined4 *)(extraout_ECX + 0x38) = 0;
            *(undefined4 *)(unaff_EBP + -0x24) = 0;
            *(undefined4 *)(unaff_EBP + -4) = 0;
            FUN_004619d2(unaff_EBP + -0x2c);
            *(undefined1 *)(unaff_EBP + -4) = 1;
            puVar5 = (undefined4 *)FUN_004619b0(unaff_EBP + -0x34);
            *(undefined4 *)(unaff_EBP + -0x24) = *puVar5;
            FUN_00461b74(puVar5 + 1);
            while( true ) {
              iVar8 = FUN_004619d2(unaff_EBP + -0x34);
              cVar2 = FUN_0046198c(iVar8 + 4);
              cVar2 = '\x01' - (cVar2 != '\0');
              *(char *)(unaff_EBP + 0xb) = cVar2;
              if (cVar2 == '\0') break;
              pcVar6 = (char *)FUN_00461941(unaff_EBP + -0x10);
              if ((((*pcVar6 < '\x01') ||
                   (iVar8 = *(int *)(DAT_006e54dc + 0x10) + -1, iVar8 <= *pcVar6)) ||
                  (pcVar6[1] < '\x01')) || (iVar8 <= pcVar6[1])) {
LAB_004983da:
                bVar9 = true;
              }
              else {
                uVar3 = FUN_00461941(unaff_EBP + -0x14);
                bVar9 = DAT_006e4a84 == 0;
                *(undefined1 *)(unaff_EBP + -4) = 3;
                uVar4 = 1;
                if (bVar9) {
                  pbVar7 = (byte *)FUN_00489c8e(uVar3);
                  uVar4 = ((byte)~*pbVar7 & 0x20) >> 5;
                }
                bVar9 = false;
                if (uVar4 == 0) goto LAB_004983da;
              }
              *(undefined1 *)(unaff_EBP + -4) = 1;
              if (bVar9) {
                uVar4 = *(uint *)(unaff_EBP + -0x1c);
                *(undefined4 *)(uVar4 + 0x38) = 1;
                goto LAB_00498467;
              }
              uVar3 = FUN_00461941(unaff_EBP + -0x18);
              puVar5 = DAT_006e486c;
              *(undefined1 *)(unaff_EBP + -4) = 4;
              FUN_0043f371(*puVar5,uVar3,0);
              *(undefined1 *)(unaff_EBP + -4) = 1;
              if (*(int *)(unaff_EBP + -0x3c) != 0) {
                iVar8 = FUN_004573f9();
                uVar4 = *(uint *)(unaff_EBP + -0x1c);
                if (*(short *)(*(int *)(iVar8 + 0x60) + 0x8a) == 7) {
                  *(undefined4 *)(uVar4 + 0x38) = 0x2d;
                }
                else {
                  *(undefined4 *)(uVar4 + 0x38) = 0x23;
                }
                goto LAB_00498467;
              }
              FUN_00461961();
            }
            uVar4 = FUN_00498182(*(int *)(unaff_EBP + -0x1c) + 0x31,
                                 *(int *)(unaff_EBP + -0x1c) + 0x48);
            goto LAB_00498469;
          }
        }
      }
    }
  }
  *(undefined4 *)(extraout_ECX + 0x38) = 1;
LAB_00498467:
  uVar4 = uVar4 & 0xffffff00;
LAB_00498469:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar4;
}

