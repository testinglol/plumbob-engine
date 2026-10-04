
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00500572(void)

{
  undefined4 *puVar1;
  char cVar2;
  uint uVar3;
  void *pvVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar2 = (**(code **)(*extraout_ECX + 200))();
  if (cVar2 == '\0') {
    (**(code **)(*extraout_ECX + 0x90))(0x10,0);
    uVar3 = FUN_005dbf32();
    if ((char)uVar3 != '\0') {
      pvVar4 = operator_new(0x210);
      *(void **)(unaff_EBP + -0x14) = pvVar4;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      if (pvVar4 == (void *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = (int *)FUN_0050806c(extraout_ECX[0x35]);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      extraout_ECX[0x57] = (int)piVar5;
      uVar3 = 0;
      if ((piVar5 != (int *)0x0) && (uVar3 = (**(code **)(*piVar5 + 0xc))(), (char)uVar3 != '\0')) {
        extraout_ECX[0x58] = 0xc9;
        extraout_ECX[0x5a] = extraout_ECX[0x21] - extraout_ECX[0x1f];
        extraout_ECX[0x59] = 0;
        extraout_ECX[0x5b] = 100;
        FUN_005a5631(0x40,unaff_EBP + -0x10,4);
        if (*(int **)(unaff_EBP + -0x10) != (int *)0x0) {
          (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x68))(DAT_006f2a64);
        }
        FUN_005a5631(0x1330,extraout_ECX + 0x5f,4);
        FUN_005a5631(0x1331,extraout_ECX + 0x60,4);
        pvVar4 = operator_new(0x194);
        *(void **)(unaff_EBP + -0x14) = pvVar4;
        *(undefined4 *)(unaff_EBP + -4) = 1;
        if (pvVar4 == (void *)0x0) {
          piVar5 = (int *)0x0;
        }
        else {
          piVar5 = (int *)FUN_005e372a();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        extraout_ECX[0x39] = (int)piVar5;
        (**(code **)(*piVar5 + 0x19c))(*(undefined4 *)(unaff_EBP + -0x10),4,1);
        *(undefined1 *)(extraout_ECX[0x39] + 0x16b) = 1;
        *(undefined4 *)(extraout_ECX[0x39] + 0xf4) = 1;
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x39]);
        FUN_005a5631(0x41,unaff_EBP + -0x10,4);
        if (*(int **)(unaff_EBP + -0x10) != (int *)0x0) {
          (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x68))(DAT_006f2a64);
        }
        pvVar4 = operator_new(0x194);
        *(void **)(unaff_EBP + -0x14) = pvVar4;
        *(undefined4 *)(unaff_EBP + -4) = 2;
        if (pvVar4 == (void *)0x0) {
          piVar5 = (int *)0x0;
        }
        else {
          piVar5 = (int *)FUN_005e372a();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        extraout_ECX[0x3a] = (int)piVar5;
        (**(code **)(*piVar5 + 0x19c))(*(undefined4 *)(unaff_EBP + -0x10),4,1);
        *(undefined1 *)(extraout_ECX[0x3a] + 0x16b) = 1;
        *(undefined4 *)(extraout_ECX[0x3a] + 0xf4) = 1;
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x3a]);
        FUN_005a5631(100,unaff_EBP + -0x10,4);
        if (*(int **)(unaff_EBP + -0x10) != (int *)0x0) {
          (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x68))(DAT_006f2a64);
        }
        pvVar4 = operator_new(0x194);
        *(void **)(unaff_EBP + -0x14) = pvVar4;
        *(undefined4 *)(unaff_EBP + -4) = 3;
        if (pvVar4 == (void *)0x0) {
          piVar5 = (int *)0x0;
        }
        else {
          piVar5 = (int *)FUN_005e372a();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        extraout_ECX[0x3b] = (int)piVar5;
        (**(code **)(*piVar5 + 0x19c))(*(undefined4 *)(unaff_EBP + -0x10),4,1);
        *(undefined1 *)(extraout_ECX[0x3b] + 0x16b) = 1;
        *(undefined4 *)(extraout_ECX[0x3b] + 0xf4) = 0;
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x3b]);
        FUN_005a5631(0x65,unaff_EBP + -0x10,4);
        if (*(int **)(unaff_EBP + -0x10) != (int *)0x0) {
          (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x68))(DAT_006f2a64);
        }
        pvVar4 = operator_new(0x194);
        *(void **)(unaff_EBP + -0x14) = pvVar4;
        *(undefined4 *)(unaff_EBP + -4) = 4;
        if (pvVar4 == (void *)0x0) {
          piVar5 = (int *)0x0;
        }
        else {
          piVar5 = (int *)FUN_005e372a();
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        extraout_ECX[0x3c] = (int)piVar5;
        (**(code **)(*piVar5 + 0x19c))(*(undefined4 *)(unaff_EBP + -0x10),4,1);
        *(undefined1 *)(extraout_ECX[0x3c] + 0x16b) = 1;
        *(undefined4 *)(extraout_ECX[0x3c] + 0xf4) = 1;
        (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x3c]);
        if (DAT_006f2ae4 == _DAT_006f2ae0) {
          FUN_0046fca5();
          *(undefined ***)(unaff_EBP + -0xa4) = &PTR_FUN_0066643c;
          *(undefined4 *)(unaff_EBP + -4) = 5;
          uVar6 = FUN_0041532c(9,unaff_EBP + -0xa4,0);
          cVar2 = FUN_004fff98(0x8b,uVar6);
          if (cVar2 != '\0') {
            FUN_00471655(unaff_EBP + -0x38);
            *(undefined4 *)(unaff_EBP + -0x18) = 0;
            *(undefined1 *)(unaff_EBP + -4) = 6;
            *(undefined4 *)(unaff_EBP + -0x14) = 0x10;
            *(undefined **)(unaff_EBP + -0x1c) = &DAT_006f2ae0;
            while( true ) {
              iVar7 = FUN_0047168f();
              *(int *)(unaff_EBP + -0x20) = iVar7;
              piVar5 = (int *)(unaff_EBP + -0x20);
              if (0xf < iVar7) {
                piVar5 = (int *)(unaff_EBP + -0x14);
              }
              if (*piVar5 <= *(int *)(unaff_EBP + -0x18)) break;
              FUN_0046fc87(unaff_EBP + -0x2c,0);
              *(undefined1 *)(unaff_EBP + -4) = 7;
              uVar6 = FUN_0046fc7a();
              FUN_005d4bbf(uVar6);
              *(undefined1 *)(unaff_EBP + -4) = 6;
              FUN_0042004f();
              *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
              *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 0xc;
            }
            *(undefined1 *)(unaff_EBP + -4) = 5;
            FUN_0042004f();
          }
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          FUN_00470467();
        }
        *(undefined **)(unaff_EBP + -0x20) = &DAT_006f2ae0;
        *(undefined4 **)(unaff_EBP + -0x18) = &DAT_006cc264;
        *(int **)(unaff_EBP + -0x1c) = extraout_ECX + 0x3d;
        do {
          FUN_005a5631(**(undefined4 **)(unaff_EBP + -0x18),unaff_EBP + -0x10,4);
          if (*(int **)(unaff_EBP + -0x10) != (int *)0x0) {
            (**(code **)(**(int **)(unaff_EBP + -0x10) + 0x68))(DAT_006f2a64);
          }
          pvVar4 = operator_new(0x194);
          *(void **)(unaff_EBP + -0x14) = pvVar4;
          *(undefined4 *)(unaff_EBP + -4) = 8;
          if (pvVar4 == (void *)0x0) {
            piVar5 = (int *)0x0;
          }
          else {
            piVar5 = (int *)FUN_005e372a();
          }
          iVar7 = *piVar5;
          *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
          (**(code **)(iVar7 + 0x19c))(*(undefined4 *)(unaff_EBP + -0x10),4,1);
          uVar6 = *(undefined4 *)(unaff_EBP + -0x20);
          *(undefined1 *)((int)piVar5 + 0x16b) = 1;
          piVar5[0x3d] = 1;
          piVar5[0x3e] = 1;
          FUN_005dd9c8(uVar6);
          (**(code **)(*extraout_ECX + 0x20))(piVar5);
          puVar1 = *(undefined4 **)(unaff_EBP + -0x1c);
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 4;
          *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 4;
          *(int *)(unaff_EBP + -0x20) = *(int *)(unaff_EBP + -0x20) + 0xc;
          iVar7 = *(int *)(unaff_EBP + -0x18);
          *puVar1 = piVar5;
        } while (iVar7 < 0x6cc294);
        FUN_005dd9c8(&DAT_006f2b70);
        FUN_005dd9c8(&DAT_006f2b7c);
        FUN_005dd9c8(&DAT_006f2b88);
        FUN_005dd9c8(&DAT_006f2b94);
        extraout_ECX[0x4c] = 0x152;
        extraout_ECX[0x50] = (extraout_ECX[0x21] - extraout_ECX[0x1f]) + -4;
        extraout_ECX[0x4d] = 5;
        extraout_ECX[0x51] = 100;
        extraout_ECX[0x4e] = 0x2d;
        extraout_ECX[0x4f] = 0x2d;
        extraout_ECX[0x52] = 0x2d;
        extraout_ECX[0x53] = 0x2d;
        extraout_ECX[0x58] = 0x13e;
        extraout_ECX[0x59] = 5;
        extraout_ECX[0x5b] = 100;
        extraout_ECX[0x5a] = extraout_ECX[0x21] - extraout_ECX[0x1f];
        uVar6 = FUN_00500b95();
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
        FUN_0054821c(uVar6,unaff_EBP + -0x21);
        *(undefined4 *)(unaff_EBP + -4) = 9;
        uVar6 = FUN_005fd5b4(*(undefined4 *)(unaff_EBP + -0x30),uVar6,unaff_EBP + -0x14,
                             *(undefined4 *)(unaff_EBP + -0x14));
        *(undefined4 *)(unaff_EBP + -0x2c) = uVar6;
        *(undefined4 *)(unaff_EBP + -4) = 10;
        FUN_00501a1a(unaff_EBP + -0x30);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_0048c4c9();
        pvVar4 = operator_new(0x130);
        *(void **)(unaff_EBP + -0x20) = pvVar4;
        *(undefined4 *)(unaff_EBP + -4) = 0xb;
        if (pvVar4 == (void *)0x0) {
          piVar5 = (int *)0x0;
        }
        else {
          piVar5 = (int *)FUN_005290cd(extraout_ECX[0x35]);
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        extraout_ECX[0x5d] = (int)piVar5;
        iVar7 = 0;
        if (piVar5 != (int *)0x0) {
          (**(code **)(*piVar5 + 0x60))
                    (extraout_ECX[0x58],extraout_ECX[0x59],extraout_ECX[0x5a],extraout_ECX[0x5b]);
          (**(code **)(*extraout_ECX + 0x20))(extraout_ECX[0x5d]);
          (**(code **)(*(int *)extraout_ECX[0x5d] + 0x98))();
          FUN_0052a053(0);
          iVar7 = extraout_ECX[0x5d];
          *(int *)(iVar7 + 0x124) = extraout_ECX[0x57];
        }
        uVar3 = CONCAT31((int3)((uint)iVar7 >> 8),1);
        goto LAB_00500b87;
      }
    }
    uVar3 = uVar3 & 0xffffff00;
  }
  else {
    uVar3 = FUN_005dbf32();
  }
LAB_00500b87:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

