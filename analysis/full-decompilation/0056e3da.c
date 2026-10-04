
void FUN_0056e3da(void)

{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  byte bVar5;
  int iVar6;
  int *piVar7;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar6 = *(int *)(extraout_ECX + 0xc) + -1;
  *(int *)(unaff_EBP + -0x20) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x14) = 1;
  *(int *)(unaff_EBP + -0x1c) = iVar6;
  if (1 < iVar6) {
    do {
      *(undefined4 *)(unaff_EBP + -0x18) = 1;
      if (1 < iVar6) {
        do {
          piVar7 = (int *)FUN_0047c7b7(unaff_EBP + -0x24,*(undefined4 *)(unaff_EBP + -0x14));
          iVar6 = *piVar7;
          *(undefined4 *)(unaff_EBP + -4) = 0;
          iVar2 = *(int *)(unaff_EBP + -0x18) * 2;
          bVar4 = true;
          if ((*(byte *)(iVar2 + iVar6) & 1) == 0) {
            piVar7 = (int *)FUN_0047c7b7(unaff_EBP + -0x28,*(undefined4 *)(unaff_EBP + -0x14));
            bVar5 = (byte)~*(byte *)(iVar2 + *piVar7) >> 3 & 1;
            *(byte *)(unaff_EBP + -0xd) = bVar5;
            bVar3 = bVar4;
            if (bVar5 == 0) goto LAB_0056e452;
          }
          else {
LAB_0056e452:
            bVar3 = false;
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          if (bVar3) {
            piVar7 = (int *)FUN_0047c7b7(unaff_EBP + -0x2c,*(int *)(unaff_EBP + -0x14) + -1);
            iVar6 = *piVar7;
            *(undefined4 *)(unaff_EBP + -4) = 1;
            bVar5 = *(byte *)(iVar2 + -2 + iVar6);
            if (((bVar5 & 1) == 0) || ((bVar5 & 4) != 0)) {
              piVar7 = (int *)FUN_0047c7b7(unaff_EBP + -0x30,*(int *)(unaff_EBP + -0x14) + -1);
              if (((*(byte *)(iVar2 + *piVar7) & 1) == 0) || ((*(byte *)(iVar2 + *piVar7) & 4) != 0)
                 ) {
                piVar7 = (int *)FUN_0047c7b7(unaff_EBP + -0x34,*(int *)(unaff_EBP + -0x14) + -1);
                bVar5 = *(byte *)(*piVar7 + iVar2 + 2);
                if (((bVar5 & 1) == 0) || ((bVar5 & 4) != 0)) {
                  piVar7 = (int *)FUN_0047c7b7(unaff_EBP + -0x38,*(undefined4 *)(unaff_EBP + -0x14))
                  ;
                  bVar5 = *(byte *)(iVar2 + -2 + *piVar7);
                  if (((bVar5 & 1) == 0) || ((bVar5 & 4) != 0)) {
                    piVar7 = (int *)FUN_0047c7b7(unaff_EBP + -0x3c,
                                                 *(undefined4 *)(unaff_EBP + -0x14));
                    bVar5 = *(byte *)(*piVar7 + iVar2 + 2);
                    if (((bVar5 & 1) == 0) || ((bVar5 & 4) != 0)) {
                      piVar7 = (int *)FUN_0047c7b7(unaff_EBP + -0x40,*(int *)(unaff_EBP + -0x14) + 1
                                                  );
                      bVar5 = *(byte *)(iVar2 + -2 + *piVar7);
                      if (((bVar5 & 1) == 0) || ((bVar5 & 4) != 0)) {
                        piVar7 = (int *)FUN_0047c7b7(unaff_EBP + -0x44,
                                                     *(int *)(unaff_EBP + -0x14) + 1);
                        if (((*(byte *)(iVar2 + *piVar7) & 1) == 0) ||
                           ((*(byte *)(iVar2 + *piVar7) & 4) != 0)) {
                          piVar7 = (int *)FUN_0047c7b7(unaff_EBP + -0x48,
                                                       *(int *)(unaff_EBP + -0x14) + 1);
                          bVar5 = *(byte *)(*piVar7 + iVar2 + 2);
                          if (((bVar5 & 1) == 0) || ((bVar5 & 4) != 0)) {
                            bVar4 = false;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
            if (bVar4) {
              if (*(int *)(unaff_EBP + 8) != 0) {
                piVar7 = (int *)FUN_0047c7b7(unaff_EBP + -0x4c,*(undefined4 *)(unaff_EBP + -0x14));
                if (((*(byte *)(iVar2 + *piVar7) & 1) != 0) &&
                   ((*(byte *)(iVar2 + *piVar7) & 4) == 0)) goto LAB_0056e5ca;
              }
              piVar7 = (int *)FUN_0047c7b7(unaff_EBP + -0x50,*(undefined4 *)(unaff_EBP + -0x14));
              uVar1 = *(undefined4 *)(unaff_EBP + -0x14);
              *(byte *)(iVar2 + *piVar7) = *(byte *)(iVar2 + *piVar7) | 1;
              piVar7 = (int *)FUN_0047c7b7(unaff_EBP + -0x54,uVar1);
              *(byte *)(iVar2 + *piVar7) = *(byte *)(iVar2 + *piVar7) | 4;
            }
          }
LAB_0056e5ca:
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
        } while (*(int *)(unaff_EBP + -0x18) < *(int *)(unaff_EBP + -0x1c));
      }
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
      iVar6 = *(int *)(unaff_EBP + -0x1c);
    } while (*(int *)(unaff_EBP + -0x14) < iVar6);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

