
void FUN_0054c71c(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EBP;
  undefined4 *puVar4;
  undefined *puVar5;
  undefined1 *puVar6;
  
  FUN_00634c24();
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0x88) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar2 = FUN_0041532c(9,unaff_EBP + -0x88,0);
  cVar1 = FUN_004fff98(0x83,uVar2);
  if (cVar1 != '\0') {
    iVar3 = FUN_0047168f();
    if (0xd < iVar3) {
      FUN_00471655(unaff_EBP + -0x14);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      puVar4 = &DAT_006f52b0;
      do {
        uVar2 = FUN_0046fc7a();
        FUN_005d4bbf(uVar2);
        puVar4 = puVar4 + 3;
        FUN_005c11ce();
      } while ((int)puVar4 < 0x6f5358);
      uVar2 = FUN_004705f2(0xf,0xffffffff);
      FUN_005d4bbf(uVar2);
      uVar2 = FUN_004705f2(0x10,0xffffffff);
      FUN_005d4bbf(uVar2);
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
          puVar5 = &DAT_006f51c0;
          do {
            uVar2 = FUN_0046fc7a();
            FUN_005d4bbf(uVar2);
            puVar5 = puVar5 + 0xc;
            FUN_005c11ce();
          } while ((int)puVar5 < 0x6f52b0);
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
              puVar5 = &DAT_006f5190;
              do {
                uVar2 = FUN_0046fc7a();
                FUN_005d4bbf(uVar2);
                puVar5 = puVar5 + 0xc;
                FUN_005c11ce();
              } while ((int)puVar5 < 0x6f51c0);
              uVar2 = FUN_0041532c(9,&DAT_006f50e8,0);
              FUN_004fff98(0x8f,uVar2);
              while( true ) {
                iVar3 = FUN_0046fbe5(0xffffffff);
                uVar2 = 0xffffffff;
                if (8 < iVar3) break;
                puVar6 = &DAT_006de560;
                iVar3 = FUN_0046fbe5(0xffffffff);
                FUN_0047057a(iVar3 + 1,puVar6,uVar2);
              }
              FUN_0047034e(0,0,0,0,0xffffffff);
              uVar2 = FUN_0041532c(9,&DAT_006f5078,0);
              FUN_004fff98(0xa7,uVar2);
              while( true ) {
                iVar3 = FUN_0046fbe5(0xffffffff);
                uVar2 = 0xffffffff;
                if (2 < iVar3) break;
                puVar6 = &DAT_006de560;
                iVar3 = FUN_0046fbe5(0xffffffff);
                FUN_0047057a(iVar3 + 1,puVar6,uVar2);
              }
              FUN_0047034e(0,0,0,0,0xffffffff);
            }
          }
        }
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_0042004f();
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      goto LAB_0054c9b9;
    }
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
LAB_0054c9b9:
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

