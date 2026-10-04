
undefined4 FUN_004902ec(void)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  char *pcVar6;
  int unaff_EBP;
  bool bVar7;
  
  FUN_00634c24();
  iVar3 = DAT_006e54dc;
  pcVar6 = *(char **)(unaff_EBP + 8);
  if (DAT_006e4a84 == 0) {
    uVar4 = ((byte)~*(byte *)(*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x34) + 0xc) + *pcVar6 * 4)
                             + (int)pcVar6[1]) & 0x20) >> 5;
    *(uint *)(unaff_EBP + 8) = uVar4;
    if (uVar4 != 0) goto LAB_00490333;
  }
  else {
LAB_00490333:
    if (*(short *)(*(int *)(*pcVar6 * 4 + *(int *)(*(int *)(iVar3 + 0x20 + pcVar6[2] * 4) + 0xc)) +
                  pcVar6[1] * 2) == 0) {
      pcVar1 = (char *)(*(int *)(*pcVar6 * 4 + *(int *)(*(int *)(iVar3 + 0x14) + 0xc)) +
                       pcVar6[1] * 4);
      cVar2 = *pcVar1;
      if (((cVar2 == pcVar1[2]) && (cVar2 == pcVar1[1])) && (cVar2 == pcVar1[3])) {
        FUN_00479737(unaff_EBP + -0x38,pcVar6);
        *(undefined4 *)(unaff_EBP + -4) = 0;
        if ((*(byte *)(unaff_EBP + -0x38) & 0x30) == 0) {
          uVar5 = FUN_0053c1aa(*(undefined4 *)(unaff_EBP + 0xc));
          uVar4 = FUN_0053c135(uVar5);
          if (uVar4 == 0x10) {
            pcVar6 = *(char **)(unaff_EBP + 0x10);
            if (*(int *)(unaff_EBP + 0xc) == 7) {
              if (pcVar6[2] != '\0') {
                bVar7 = pcVar6[1] == '\0';
                goto LAB_004903d9;
              }
            }
            else {
              cVar2 = *pcVar6;
LAB_004903af:
              if (cVar2 != '\0') {
                bVar7 = pcVar6[3] == '\0';
                goto LAB_004903d9;
              }
            }
          }
          else {
            if (uVar4 == 0x20) {
              pcVar6 = *(char **)(unaff_EBP + 0x10);
              if (*(int *)(unaff_EBP + 0xc) != 4) {
                cVar2 = pcVar6[1];
                goto LAB_004903af;
              }
              if (pcVar6[2] == '\0') goto LAB_004903db;
              bVar7 = *pcVar6 == '\0';
            }
            else {
              bVar7 = (uVar4 & *(uint *)(unaff_EBP + -0x38)) == uVar4;
            }
LAB_004903d9:
            if (!bVar7) {
              uVar5 = 1;
              goto LAB_004903e1;
            }
          }
        }
      }
    }
  }
LAB_004903db:
  uVar5 = 0;
LAB_004903e1:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5;
}

