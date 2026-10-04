
void FUN_005434d0(void)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  cVar3 = (**(code **)(*extraout_ECX + 200))();
  if (cVar3 == '\0') {
    (**(code **)(*extraout_ECX + 0xc))();
  }
  piVar4 = (int *)(**(code **)(*DAT_006fe8bc + 4))();
  iVar6 = *(int *)(unaff_EBP + 8);
  extraout_ECX[0x6d] = iVar6;
  if (iVar6 != -1) {
    cVar3 = FUN_004e1c79(iVar6,extraout_ECX + 0x71);
    if (cVar3 == '\0') {
      uVar5 = FUN_005d4956(s_The_Symptoms_006cd5f0);
      piVar1 = (int *)extraout_ECX[0x79];
      *(undefined4 *)(unaff_EBP + -4) = 0;
      (**(code **)(*piVar1 + 0x9c))(uVar5);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
    }
    else {
      *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)extraout_ECX[0x79];
      uVar5 = FUN_004096c2();
      (**(code **)(*(int *)(unaff_EBP + 8) + 0x1a0))(uVar5);
    }
    (*(code *)**(undefined4 **)(extraout_ECX[0x79] + 0xd4))();
    FUN_004cb21d(DAT_006f4f50,DAT_006f4f54);
    cVar3 = *(char *)(DAT_006e486c + 100);
    if ((((cVar3 == '\x14') || (cVar3 == '\x12')) || (cVar3 == '\x11')) || (cVar3 == '\x0f')) {
      FUN_004cb21d(DAT_006f4f50,DAT_006f4f54 + 4);
    }
    piVar1 = extraout_ECX + 0x6e;
    FUN_004e1d96(extraout_ECX[0x6d],piVar1);
    FUN_005d48d9();
    iVar6 = *piVar4;
    iVar2 = extraout_ECX[0x74];
    *(undefined4 *)(unaff_EBP + -4) = 1;
    (**(code **)(iVar6 + 0x7c))(iVar2,iVar2 >> 0x1f,unaff_EBP + -0x28);
    (**(code **)(*(int *)extraout_ECX[0x7a] + 0x9c))(unaff_EBP + -0x28);
    FUN_0046fb9b(unaff_EBP + -0x134,0x100);
    iVar6 = extraout_ECX[0x77];
    *(undefined ***)(unaff_EBP + -0x140) = &PTR_LAB_0066655c;
    wsprintfA(*(LPSTR *)(unaff_EBP + -0x13c),(LPCSTR)&DAT_006c08e4,iVar6);
    (**(code **)(*(int *)extraout_ECX[0x7b] + 0x1a0))(*(undefined4 *)(unaff_EBP + -0x13c));
    FUN_0046fb9b(unaff_EBP + -0x134,0x100);
    iVar6 = extraout_ECX[0x75];
    *(undefined ***)(unaff_EBP + -0x140) = &PTR_LAB_0066655c;
    wsprintfA(*(LPSTR *)(unaff_EBP + -0x13c),(LPCSTR)&DAT_006c08e4,iVar6);
    (**(code **)(*(int *)extraout_ECX[0x7c] + 0x1a0))(*(undefined4 *)(unaff_EBP + -0x13c));
    iVar6 = extraout_ECX[0x6f];
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    if (iVar6 - *piVar1 >> 2 != 0) {
      piVar4 = extraout_ECX + 0x65;
      *(undefined4 *)(unaff_EBP + 8) = 0xfffffe6c;
      *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) - (int)extraout_ECX;
      *(int **)(unaff_EBP + -0x18) = piVar4;
      do {
        if (*piVar4 != 0) {
          FUN_005437f9(*(undefined4 *)((int)piVar4 + *piVar1 + *(int *)(unaff_EBP + 8)));
          (**(code **)(*(int *)*piVar4 + 0x94))();
          FUN_005c1719();
          iVar6 = *piVar1;
          *(undefined1 *)(unaff_EBP + -4) = 2;
          cVar3 = FUN_004e93e4(*(undefined4 *)((int)piVar4 + iVar6 + *(int *)(unaff_EBP + 8)),
                               unaff_EBP + -0x10);
          if (cVar3 != '\0') {
            iVar6 = FUN_004096c2();
            uVar5 = *(undefined4 *)*piVar4;
            uVar7 = FUN_004096c2((-(*(int *)(iVar6 + 0x1c) % 4 != 0) & 2U) + 4,3);
            *(undefined4 *)(unaff_EBP + -0x1c) = uVar5;
            piVar4 = *(int **)(unaff_EBP + -0x18);
            (**(code **)(*(int *)(unaff_EBP + -0x1c) + 0x19c))(uVar7);
            FUN_004ec1a7(extraout_ECX[0x78]);
            FUN_004ec186(0x2d);
          }
          *(undefined1 *)(unaff_EBP + -4) = 1;
          FUN_005a5e09();
        }
        iVar6 = extraout_ECX[0x6f];
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
        iVar2 = *piVar1;
        piVar4 = piVar4 + 1;
        *(int **)(unaff_EBP + -0x18) = piVar4;
      } while (*(uint *)(unaff_EBP + -0x14) < (uint)(iVar6 - iVar2 >> 2));
    }
    if (((uint)(extraout_ECX[0x6f] - *piVar1 >> 2) < 8) &&
       (iVar6 = extraout_ECX[0x6f] - *piVar1 >> 2, iVar6 < 8)) {
      piVar4 = extraout_ECX + iVar6 + 0x65;
      iVar6 = 8 - iVar6;
      do {
        if ((int *)*piVar4 != (int *)0x0) {
          (**(code **)(*(int *)*piVar4 + 0x98))();
        }
        piVar4 = piVar4 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

