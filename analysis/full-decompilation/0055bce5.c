
void FUN_0055bce5(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  size_t sVar5;
  void *pvVar6;
  int iVar7;
  int unaff_EBP;
  undefined4 *puVar8;
  undefined1 *puVar9;
  
  FUN_00634c24();
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x8c) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar2 = FUN_0041532c(9,unaff_EBP + -0x8c,0);
  cVar1 = FUN_004fff98(0x83,uVar2);
  if (cVar1 != '\0') {
    iVar3 = FUN_0047168f();
    if (0x11 < iVar3) {
      FUN_00471655(unaff_EBP + -0x14);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      puVar8 = &DAT_006f58f8;
      do {
        pcVar4 = (char *)FUN_0046fc7a();
        sVar5 = _strlen(pcVar4);
        pvVar6 = operator_new(sVar5 + 1);
        *puVar8 = pvVar6;
        if (pvVar6 != (void *)0x0) {
          uVar2 = FUN_0046fc7a();
          FUN_006358b0(*puVar8,uVar2);
        }
        puVar8 = puVar8 + 1;
        FUN_005c11ce();
      } while ((int)puVar8 < 0x6f5940);
      uVar2 = FUN_0041532c(9,unaff_EBP + -0x8c,0);
      cVar1 = FUN_004fff98(0x84,uVar2);
      if (cVar1 != '\0') {
        iVar3 = FUN_0047168f();
        if (0x13 < iVar3) {
          uVar2 = FUN_00471655(unaff_EBP + -0x1c);
          *(undefined1 *)(unaff_EBP + -4) = 2;
          FUN_0046fc63(uVar2);
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_0042004f();
          puVar8 = &DAT_006f5940;
          do {
            pcVar4 = (char *)FUN_0046fc7a();
            sVar5 = _strlen(pcVar4);
            pvVar6 = operator_new(sVar5 + 1);
            *puVar8 = pvVar6;
            if (pvVar6 != (void *)0x0) {
              uVar2 = FUN_0046fc7a();
              FUN_006358b0(*puVar8,uVar2);
            }
            puVar8 = puVar8 + 1;
            FUN_005c11ce();
          } while ((int)puVar8 < 0x6f5990);
          uVar2 = FUN_0041532c(9,unaff_EBP + -0x8c,0);
          cVar1 = FUN_004fff98(0x85,uVar2);
          if (cVar1 != '\0') {
            iVar3 = FUN_0047168f();
            if (3 < iVar3) {
              uVar2 = FUN_00471655(unaff_EBP + -0x1c);
              *(undefined1 *)(unaff_EBP + -4) = 3;
              FUN_0046fc63(uVar2);
              *(undefined1 *)(unaff_EBP + -4) = 1;
              FUN_0042004f();
              puVar8 = &DAT_006f5990;
              do {
                pcVar4 = (char *)FUN_0046fc7a();
                sVar5 = _strlen(pcVar4);
                pvVar6 = operator_new(sVar5 + 1);
                *puVar8 = pvVar6;
                if (pvVar6 != (void *)0x0) {
                  uVar2 = FUN_0046fc7a();
                  FUN_006358b0(*puVar8,uVar2);
                }
                puVar8 = puVar8 + 1;
                FUN_005c11ce();
              } while ((int)puVar8 < 0x6f59a0);
              uVar2 = FUN_0041532c(9,&DAT_006f57c8,0);
              FUN_004fff98(0x8f,uVar2);
              while( true ) {
                iVar3 = FUN_0046fbe5(0xffffffff);
                uVar2 = 0xffffffff;
                if (8 < iVar3) break;
                puVar9 = &DAT_006de560;
                iVar3 = FUN_0046fbe5(0xffffffff);
                FUN_0047057a(iVar3 + 1,puVar9,uVar2);
              }
              FUN_0047034e(0,0,0,0,0xffffffff);
              uVar2 = FUN_0041532c(9,unaff_EBP + -0x8c,0);
              cVar1 = FUN_004fff98(0xfa,uVar2);
              if (cVar1 != '\0') {
                iVar3 = FUN_0047168f();
                if (1 < iVar3) {
                  uVar2 = FUN_00471655(unaff_EBP + -0x1c);
                  *(undefined1 *)(unaff_EBP + -4) = 4;
                  FUN_0046fc63(uVar2);
                  *(undefined1 *)(unaff_EBP + -4) = 1;
                  FUN_0042004f();
                  puVar8 = &DAT_006f59a0;
                  do {
                    pcVar4 = (char *)FUN_0046fc7a();
                    sVar5 = _strlen(pcVar4);
                    pvVar6 = operator_new(sVar5 + 1);
                    *puVar8 = pvVar6;
                    if (pvVar6 != (void *)0x0) {
                      uVar2 = FUN_0046fc7a();
                      FUN_006358b0(*puVar8,uVar2);
                    }
                    puVar8 = puVar8 + 1;
                    FUN_005c11ce();
                  } while ((int)puVar8 < 0x6f59a8);
                  uVar2 = FUN_0041532c(9,unaff_EBP + -0x8c,0);
                  cVar1 = FUN_004fff98(0xfb,uVar2);
                  if (cVar1 != '\0') {
                    iVar7 = FUN_0047168f();
                    iVar3 = 2;
                    if (1 < iVar7) {
                      uVar2 = FUN_00471655(unaff_EBP + -0x1c);
                      *(undefined1 *)(unaff_EBP + -4) = 5;
                      FUN_0046fc63(uVar2);
                      *(undefined1 *)(unaff_EBP + -4) = 1;
                      FUN_0042004f();
                      do {
                        uVar2 = FUN_0046fc7a();
                        uVar2 = FUN_005d4956(uVar2);
                        *(undefined1 *)(unaff_EBP + -4) = 6;
                        FUN_004054fa(uVar2);
                        *(undefined1 *)(unaff_EBP + -4) = 1;
                        FUN_005b8770();
                        FUN_005c11ce();
                        iVar3 = iVar3 + -1;
                      } while (iVar3 != 0);
                      uVar2 = FUN_0041532c(9,unaff_EBP + -0x8c,0);
                      cVar1 = FUN_004fff98(0x104,uVar2);
                      if (cVar1 != '\0') {
                        iVar7 = FUN_0047168f();
                        iVar3 = 2;
                        if (1 < iVar7) {
                          uVar2 = FUN_00471655(unaff_EBP + -0x1c);
                          *(undefined1 *)(unaff_EBP + -4) = 7;
                          FUN_0046fc63(uVar2);
                          *(undefined1 *)(unaff_EBP + -4) = 1;
                          FUN_0042004f();
                          do {
                            uVar2 = FUN_0046fc7a();
                            uVar2 = FUN_005d4956(uVar2);
                            *(undefined1 *)(unaff_EBP + -4) = 8;
                            FUN_004054fa(uVar2);
                            *(undefined1 *)(unaff_EBP + -4) = 1;
                            FUN_005b8770();
                            FUN_005c11ce();
                            iVar3 = iVar3 + -1;
                          } while (iVar3 != 0);
                          uVar2 = FUN_0041532c(9,&DAT_006f5738,0);
                          FUN_004fff98(0xa7,uVar2);
                          while( true ) {
                            iVar3 = FUN_0046fbe5(0xffffffff);
                            uVar2 = 0xffffffff;
                            if (2 < iVar3) break;
                            puVar9 = &DAT_006de560;
                            iVar3 = FUN_0046fbe5(0xffffffff);
                            FUN_0047057a(iVar3 + 1,puVar9,uVar2);
                          }
                          FUN_0047034e(0,0,0,0,0xffffffff);
                        }
                      }
                    }
                  }
                }
              }
              *(undefined1 *)(unaff_EBP + -4) = 0;
              FUN_0042004f();
              *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
              goto LAB_0055c199;
            }
          }
        }
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_0042004f();
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
LAB_0055c199:
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

