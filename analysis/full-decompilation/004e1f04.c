
undefined1 FUN_004e1f04(void)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  char *_Source;
  undefined1 *puVar6;
  undefined1 *puVar7;
  int unaff_EBP;
  undefined4 uVar8;
  size_t _Count;
  
  FUN_00634c24();
  iVar3 = DAT_006e486c;
  *(undefined1 *)(unaff_EBP + -0xd) = 0;
  *(undefined4 *)(unaff_EBP + -0x24) = *(undefined4 *)(iVar3 + 0x24);
  FUN_0046f824(unaff_EBP + -0x52c,0,0x104);
  *(undefined ***)(unaff_EBP + -0x538) = &PTR_FUN_006664e8;
  FUN_00425691(*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x538);
  FUN_00418fea();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar3 = FUN_004190d3(unaff_EBP + -0x538,0);
  if (iVar3 == 0) {
    if ((*(byte *)(DAT_006e486c + 0x66) & 0x20) != 0) {
      if ((*(int *)(unaff_EBP + 8) < 0x5a) || (99 < *(int *)(unaff_EBP + 8))) {
        iVar3 = FUN_0042ba25(*(undefined4 *)(unaff_EBP + 8));
        *(bool *)(unaff_EBP + -0xd) = iVar3 != 0;
      }
      else {
        *(undefined1 *)(unaff_EBP + -0xd) = 0;
      }
    }
    iVar3 = *(int *)(unaff_EBP + 0xc);
    cVar1 = FUN_004e2795(unaff_EBP + -0x90,iVar3,*(undefined4 *)(unaff_EBP + 0x10),unaff_EBP + -0xd)
    ;
    if (cVar1 != '\0') {
      iVar4 = FUN_00425ddf(*(undefined4 *)(unaff_EBP + 8));
      if (iVar4 == 0) {
        *(undefined4 *)(iVar3 + 0x24) = 0xffffffff;
      }
      else {
        uVar5 = *(undefined4 *)(iVar4 + 0x10c);
        *(undefined4 *)(iVar3 + 0x24) = uVar5;
        FUN_004e1c79(uVar5,iVar3 + 0x28);
      }
      *(undefined4 *)(iVar3 + 0x44) = *(undefined4 *)(unaff_EBP + 8);
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0x318) = &PTR_FUN_0066643c;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0x2ac) = &PTR_FUN_0066643c;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0x240) = &PTR_FUN_0066643c;
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0x168) = &PTR_FUN_0066643c;
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0x1d4) = &PTR_FUN_0066643c;
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0xfc) = &PTR_FUN_0066643c;
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_0046f824(unaff_EBP + -0x41c,0,0x104);
      *(undefined ***)(unaff_EBP + -0x428) = &PTR_FUN_006664e8;
      FUN_00425531(unaff_EBP + -0x428);
      uVar8 = 0xffffffff;
      uVar5 = FUN_0041532c(10,0xffffffff);
      FUN_0046f847(uVar5,uVar8);
      FUN_0046f5cd();
      *(undefined1 *)(unaff_EBP + -4) = 7;
      iVar3 = FUN_0046f71c(unaff_EBP + -0x428,0);
      if (iVar3 == 0) {
        FUN_004703f1(unaff_EBP + -0x77c,1);
        FUN_004703f1(unaff_EBP + -0x77c,2);
        FUN_004703f1(unaff_EBP + -0x77c,3);
        FUN_004703f1(unaff_EBP + -0x77c,4);
        FUN_004703f1(unaff_EBP + -0x77c,5);
        FUN_004703f1(unaff_EBP + -0x77c,7);
      }
      else {
        uVar5 = FUN_0041532c(10,unaff_EBP + -0x318);
        FUN_005000f2(1,uVar5);
        uVar5 = FUN_0041532c(10,unaff_EBP + -0x240);
        FUN_005000f2(2,uVar5);
        uVar5 = FUN_0041532c(10,unaff_EBP + -0x168);
        FUN_005000f2(3,uVar5);
        uVar5 = FUN_0041532c(10,unaff_EBP + -0x2ac);
        FUN_005000f2(4,uVar5);
        uVar5 = FUN_0041532c(10,unaff_EBP + -0x1d4);
        FUN_005000f2(5,uVar5);
        uVar5 = FUN_0041532c(10,unaff_EBP + -0xfc);
        FUN_005000f2(7,uVar5);
      }
      FUN_0046b7ee();
      iVar3 = *(int *)(unaff_EBP + 0xc);
      iVar4 = *(int *)(unaff_EBP + 8);
      *(undefined4 *)(iVar3 + 0x74) = 0;
      *(undefined4 *)(iVar3 + 0x78) = 0;
      if ((iVar4 < 0x15) || (0x1e < iVar4)) {
        if ((0x27 < iVar4) && (iVar4 < 0x31)) {
          FUN_00471655(unaff_EBP + -0x18);
          *(undefined1 *)(unaff_EBP + -4) = 10;
          uVar5 = FUN_0047166d(unaff_EBP + -0x20);
          while( true ) {
            *(undefined1 *)(unaff_EBP + -4) = 0xb;
            uVar2 = FUN_0046fc3a(uVar5);
            *(undefined1 *)(unaff_EBP + 0x13) = uVar2;
            *(undefined1 *)(unaff_EBP + -4) = 10;
            FUN_0042004f();
            if (*(char *)(unaff_EBP + 0x13) == '\0') break;
            uVar5 = FUN_0046fc7a();
            FUN_006358b0(unaff_EBP + -0x5c,uVar5);
            puVar6 = (undefined1 *)FUN_00636450(unaff_EBP + -0x5c,0x2c);
            if (puVar6 != (undefined1 *)0x0) {
              *puVar6 = 0;
              puVar7 = (undefined1 *)FUN_00636450(puVar6 + 1,0x2c);
              if (puVar7 != (undefined1 *)0x0) {
                *puVar7 = 0;
                iVar3 = FUN_00635f62(unaff_EBP + -0x5c);
                if (iVar3 == *(int *)(unaff_EBP + 8)) {
                  uVar5 = FUN_00635f62(puVar6 + 1);
                  iVar3 = *(int *)(unaff_EBP + 0xc);
                  *(undefined4 *)(iVar3 + 0x74) = uVar5;
                  uVar5 = FUN_00635f62(puVar7 + 1);
                  *(undefined4 *)(iVar3 + 0x78) = uVar5;
                }
              }
            }
            FUN_005c11ce();
            uVar5 = FUN_0047166d(unaff_EBP + -0x20);
          }
          *(undefined1 *)(unaff_EBP + -4) = 7;
          goto LAB_004e2705;
        }
        if ((0x50 < iVar4) && (iVar4 < 0x5a)) {
          FUN_00471655(unaff_EBP + -0x18);
          *(undefined1 *)(unaff_EBP + -4) = 0xc;
          uVar5 = FUN_0047166d(unaff_EBP + -0x20);
          while( true ) {
            *(undefined1 *)(unaff_EBP + -4) = 0xd;
            cVar1 = FUN_0046fc3a(uVar5);
            *(undefined1 *)(unaff_EBP + -4) = 0xc;
            FUN_0042004f();
            if (cVar1 == '\0') break;
            uVar5 = FUN_0046fc7a();
            FUN_006358b0(unaff_EBP + -0x5c,uVar5);
            puVar6 = (undefined1 *)FUN_00636450(unaff_EBP + -0x5c,0x2c);
            if (puVar6 != (undefined1 *)0x0) {
              *puVar6 = 0;
              puVar7 = (undefined1 *)FUN_00636450(puVar6 + 1,0x2c);
              if (puVar7 != (undefined1 *)0x0) {
                *puVar7 = 0;
                iVar4 = FUN_00635f62(unaff_EBP + -0x5c);
                if (iVar4 == *(int *)(unaff_EBP + 8)) {
                  uVar5 = FUN_00635f62(puVar6 + 1);
                  *(undefined4 *)(iVar3 + 0x74) = uVar5;
                  uVar5 = FUN_00635f62(puVar7 + 1);
                  *(undefined4 *)(iVar3 + 0x78) = uVar5;
                }
              }
            }
            FUN_005c11ce();
            uVar5 = FUN_0047166d(unaff_EBP + -0x20);
          }
          *(undefined1 *)(unaff_EBP + -4) = 7;
          goto LAB_004e2705;
        }
        if ((0x59 < iVar4) && (iVar4 < 100)) {
          FUN_00471655(unaff_EBP + -0x18);
          *(undefined1 *)(unaff_EBP + -4) = 0xe;
          uVar5 = FUN_0047166d(unaff_EBP + -0x20);
          while( true ) {
            *(undefined1 *)(unaff_EBP + -4) = 0xf;
            cVar1 = FUN_0046fc3a(uVar5);
            *(undefined1 *)(unaff_EBP + -4) = 0xe;
            FUN_0042004f();
            if (cVar1 == '\0') break;
            uVar5 = FUN_0046fc7a();
            FUN_006358b0(unaff_EBP + -0x5c,uVar5);
            puVar6 = (undefined1 *)FUN_00636450(unaff_EBP + -0x5c,0x2c);
            if (puVar6 != (undefined1 *)0x0) {
              *puVar6 = 0;
              puVar7 = (undefined1 *)FUN_00636450(puVar6 + 1,0x2c);
              if (puVar7 != (undefined1 *)0x0) {
                *puVar7 = 0;
                iVar4 = FUN_00635f62(unaff_EBP + -0x5c);
                if (iVar4 == *(int *)(unaff_EBP + 8)) {
                  uVar5 = FUN_00635f62(puVar6 + 1);
                  *(undefined4 *)(iVar3 + 0x74) = uVar5;
                  uVar5 = FUN_00635f62(puVar7 + 1);
                  *(undefined4 *)(iVar3 + 0x78) = uVar5;
                }
              }
            }
            FUN_005c11ce();
            uVar5 = FUN_0047166d(unaff_EBP + -0x20);
          }
          *(undefined1 *)(unaff_EBP + -4) = 7;
          goto LAB_004e2705;
        }
        if (((0x31 < iVar4) && (iVar4 < 0x51)) || ((-1 < iVar4 && (iVar4 < 0xc)))) {
          FUN_0046fc56();
          *(undefined1 *)(unaff_EBP + -4) = 0x10;
          FUN_0046fc56();
          *(undefined1 *)(unaff_EBP + -4) = 0x11;
          if (*(char *)(unaff_EBP + -0xd) == '\x01') {
            uVar5 = FUN_00471655(unaff_EBP + -0x28);
            *(undefined1 *)(unaff_EBP + -4) = 0x12;
            FUN_0046fc63(uVar5);
            *(undefined1 *)(unaff_EBP + -4) = 0x11;
            FUN_0042004f();
            uVar5 = FUN_0047166d(unaff_EBP + -0x28);
            *(undefined1 *)(unaff_EBP + -4) = 0x13;
            FUN_0046fc63(uVar5);
            *(undefined1 *)(unaff_EBP + -4) = 0x11;
          }
          else {
            uVar5 = FUN_00471655(unaff_EBP + -0x28);
            *(undefined1 *)(unaff_EBP + -4) = 0x14;
            FUN_0046fc63(uVar5);
            *(undefined1 *)(unaff_EBP + -4) = 0x11;
            FUN_0042004f();
            uVar5 = FUN_0047166d(unaff_EBP + -100);
            *(undefined1 *)(unaff_EBP + -4) = 0x15;
            FUN_0046fc63(uVar5);
            *(undefined1 *)(unaff_EBP + -4) = 0x11;
          }
          FUN_0042004f();
          while( true ) {
            cVar1 = FUN_0046fc3a(unaff_EBP + -0x20);
            if (cVar1 == '\0') break;
            uVar5 = FUN_0046fc7a();
            FUN_006358b0(unaff_EBP + -0x5c,uVar5);
            puVar6 = (undefined1 *)FUN_00636450(unaff_EBP + -0x5c,0x2c);
            if (puVar6 != (undefined1 *)0x0) {
              *puVar6 = 0;
              puVar7 = (undefined1 *)FUN_00636450(puVar6 + 1,0x2c);
              if (puVar7 != (undefined1 *)0x0) {
                *puVar7 = 0;
                iVar4 = FUN_00635f62(unaff_EBP + -0x5c);
                if (iVar4 == *(int *)(unaff_EBP + 8)) {
                  uVar5 = FUN_00635f62(puVar6 + 1);
                  *(undefined4 *)(iVar3 + 0x74) = uVar5;
                  uVar5 = FUN_00635f62(puVar7 + 1);
                  *(undefined4 *)(iVar3 + 0x78) = uVar5;
                  break;
                }
              }
            }
            FUN_005c11ce();
          }
          *(undefined1 *)(unaff_EBP + -4) = 0x10;
          FUN_0042004f();
          *(undefined1 *)(unaff_EBP + -4) = 7;
          goto LAB_004e2705;
        }
      }
      else {
        FUN_00471655(unaff_EBP + -0x18);
        *(undefined1 *)(unaff_EBP + -4) = 8;
        uVar5 = FUN_0047166d(unaff_EBP + -0x20);
        while( true ) {
          *(undefined1 *)(unaff_EBP + -4) = 9;
          cVar1 = FUN_0046fc3a(uVar5);
          *(undefined1 *)(unaff_EBP + -4) = 8;
          FUN_0042004f();
          if (cVar1 == '\0') break;
          _Count = 0x31;
          _Source = (char *)FUN_0046fc7a();
          _strncpy((char *)(unaff_EBP + -0x5c),_Source,_Count);
          puVar6 = (undefined1 *)FUN_00636450(unaff_EBP + -0x5c,0x2c);
          if (puVar6 != (undefined1 *)0x0) {
            *puVar6 = 0;
            puVar7 = (undefined1 *)FUN_00636450(puVar6 + 1,0x2c);
            if (puVar7 != (undefined1 *)0x0) {
              *puVar7 = 0;
              iVar4 = FUN_00635f62(unaff_EBP + -0x5c);
              if (iVar4 == *(int *)(unaff_EBP + 8)) {
                uVar5 = FUN_00635f62(puVar6 + 1);
                *(undefined4 *)(iVar3 + 0x74) = uVar5;
                uVar5 = FUN_00635f62(puVar7 + 1);
                *(undefined4 *)(iVar3 + 0x78) = uVar5;
              }
            }
          }
          FUN_005c11ce();
          uVar5 = FUN_0047166d(unaff_EBP + -0x20);
        }
        *(undefined1 *)(unaff_EBP + -4) = 7;
LAB_004e2705:
        FUN_0042004f();
      }
      *(undefined1 *)(unaff_EBP + -4) = 6;
      FUN_0046b2e6();
      *(undefined1 *)(unaff_EBP + -4) = 5;
      FUN_00470467();
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_00470467();
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_00470467();
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_00470467();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_00470467();
      *(undefined1 *)(unaff_EBP + -4) = 0;
      FUN_00470467();
      uVar2 = 1;
      goto LAB_004e2775;
    }
  }
  uVar2 = 0;
LAB_004e2775:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0041905d();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

