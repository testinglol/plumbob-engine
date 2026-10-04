
void FUN_00561da7(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  size_t sVar5;
  void *pvVar6;
  int unaff_EBP;
  undefined4 *puVar7;
  undefined1 *puVar8;
  
  FUN_00634c24();
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x88) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar2 = FUN_0041532c(9,unaff_EBP + -0x88,0);
  cVar1 = FUN_004fff98(0x83,uVar2);
  if (cVar1 != '\0') {
    iVar3 = FUN_0047168f();
    if (0x11 < iVar3) {
      FUN_00471655(unaff_EBP + -0x14);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      puVar7 = &DAT_006f5b18;
      do {
        pcVar4 = (char *)FUN_0046fc7a();
        sVar5 = _strlen(pcVar4);
        pvVar6 = operator_new(sVar5 + 1);
        *puVar7 = pvVar6;
        if (pvVar6 != (void *)0x0) {
          uVar2 = FUN_0046fc7a();
          FUN_006358b0(*puVar7,uVar2);
        }
        puVar7 = puVar7 + 1;
        FUN_005c11ce();
      } while ((int)puVar7 < 0x6f5b60);
      uVar2 = FUN_0041532c(9,unaff_EBP + -0x88,0);
      cVar1 = FUN_004fff98(0x84,uVar2);
      if (cVar1 != '\0') {
        iVar3 = FUN_0047168f();
        if (0x13 < iVar3) {
          uVar2 = FUN_00471655(unaff_EBP + -0x1c);
          *(undefined1 *)(unaff_EBP + -4) = 2;
          FUN_0046fc63(uVar2);
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_0042004f();
          puVar7 = &DAT_006f5b60;
          do {
            pcVar4 = (char *)FUN_0046fc7a();
            sVar5 = _strlen(pcVar4);
            pvVar6 = operator_new(sVar5 + 1);
            *puVar7 = pvVar6;
            if (pvVar6 != (void *)0x0) {
              uVar2 = FUN_0046fc7a();
              FUN_006358b0(*puVar7,uVar2);
            }
            puVar7 = puVar7 + 1;
            FUN_005c11ce();
          } while ((int)puVar7 < 0x6f5bb0);
          uVar2 = FUN_0041532c(9,unaff_EBP + -0x88,0);
          cVar1 = FUN_004fff98(0x85,uVar2);
          if (cVar1 != '\0') {
            iVar3 = FUN_0047168f();
            if (3 < iVar3) {
              uVar2 = FUN_00471655(unaff_EBP + -0x1c);
              *(undefined1 *)(unaff_EBP + -4) = 3;
              FUN_0046fc63(uVar2);
              *(undefined1 *)(unaff_EBP + -4) = 1;
              FUN_0042004f();
              puVar7 = &DAT_006f5bb0;
              do {
                pcVar4 = (char *)FUN_0046fc7a();
                sVar5 = _strlen(pcVar4);
                pvVar6 = operator_new(sVar5 + 1);
                *puVar7 = pvVar6;
                if (pvVar6 != (void *)0x0) {
                  uVar2 = FUN_0046fc7a();
                  FUN_006358b0(*puVar7,uVar2);
                }
                puVar7 = puVar7 + 1;
                FUN_005c11ce();
              } while ((int)puVar7 < 0x6f5bc0);
              uVar2 = FUN_0041532c(9,&DAT_006f5a20,0);
              FUN_004fff98(0x8f,uVar2);
              while( true ) {
                iVar3 = FUN_0046fbe5(0xffffffff);
                uVar2 = 0xffffffff;
                if (8 < iVar3) break;
                puVar8 = &DAT_006de560;
                iVar3 = FUN_0046fbe5(0xffffffff);
                FUN_0047057a(iVar3 + 1,puVar8,uVar2);
              }
              FUN_0047034e(0,0,0,0,0xffffffff);
              uVar2 = FUN_0041532c(9,&DAT_006f59b0,0);
              FUN_004fff98(0xa7,uVar2);
              while( true ) {
                iVar3 = FUN_0046fbe5(0xffffffff);
                uVar2 = 0xffffffff;
                if (2 < iVar3) break;
                puVar8 = &DAT_006de560;
                iVar3 = FUN_0046fbe5(0xffffffff);
                FUN_0047057a(iVar3 + 1,puVar8,uVar2);
              }
              FUN_0047034e(0,0,0,0,0xffffffff);
              *(undefined1 *)(unaff_EBP + -4) = 0;
              FUN_0042004f();
              *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
              goto LAB_00562079;
            }
          }
        }
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_0042004f();
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
LAB_00562079:
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

