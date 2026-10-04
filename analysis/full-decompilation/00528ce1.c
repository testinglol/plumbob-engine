
void FUN_00528ce1(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  size_t sVar5;
  char *pcVar6;
  undefined4 *puVar7;
  int extraout_ECX;
  int unaff_EBP;
  int iVar8;
  undefined *puVar9;
  
  FUN_00634c24();
  iVar8 = 0;
  if (*(int *)(extraout_ECX + 0x1ac) != 0) {
    iVar3 = *(int *)(extraout_ECX + 0x19c);
    do {
      *(int *)(unaff_EBP + -0x10) = iVar8 + 1;
      iVar2 = __ftol();
      if (iVar3 <= iVar2) {
        FUN_005d4bbf(&DAT_006de560);
        FUN_005b8680();
        *(undefined4 *)(unaff_EBP + -4) = 0;
        FUN_004e9c34(*(undefined4 *)(extraout_ECX + 0x194),unaff_EBP + -0x1c);
        if (*(int *)(unaff_EBP + -0x18) != *(int *)(unaff_EBP + -0x1c)) {
          iVar3 = FUN_004ea79e(*(undefined4 *)(extraout_ECX + 0x194));
          sVar1 = *(short *)(iVar3 + 0x8c);
          *(uint *)(unaff_EBP + -0x10) = CONCAT22((short)((uint)iVar3 >> 0x10),sVar1);
          if (sVar1 == 0) {
            iVar3 = FUN_004ea79e(*(undefined4 *)(extraout_ECX + 0x194));
            uVar4 = FUN_0048432f(iVar3);
            *(short *)(iVar3 + 0x8c) = (short)uVar4;
            *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
          }
          if (0 < *(short *)(unaff_EBP + -0x10)) {
            sVar5 = _strlen(&DAT_006ccae4);
            FUN_00412d8a(&DAT_006ccae4,&DAT_006ccae4 + sVar5);
            pcVar6 = (char *)FUN_00484411(*(undefined4 *)(unaff_EBP + -0x10));
            sVar5 = _strlen(pcVar6);
            FUN_00412d8a(pcVar6,pcVar6 + sVar5);
            sVar5 = _strlen(&DAT_006c3cd4);
            FUN_00412d8a(&DAT_006c3cd4,&DAT_006c3cd4 + sVar5);
          }
          sVar5 = _strlen(&DAT_006cc6a0);
          FUN_00412d8a(&DAT_006cc6a0,&DAT_006cc6a0 + sVar5);
        }
        puVar7 = (undefined4 *)FUN_004e9bbd(*(undefined4 *)(extraout_ECX + 0x194));
        FUN_00412d8a(*puVar7,puVar7[1]);
        *(undefined4 *)(unaff_EBP + -0x30) = 0;
        *(undefined4 *)(unaff_EBP + -0x2c) = 3;
        *(undefined4 *)(unaff_EBP + -0x28) = 1;
        *(undefined4 *)(unaff_EBP + -0x24) = 4;
        *(undefined4 *)(unaff_EBP + -0x20) = 2;
        pcVar6 = DAT_006f3bc4;
        iVar8 = *(int *)(unaff_EBP + -0x30 + iVar8 * 4);
        if (iVar8 == 2) {
          if (*(char *)(extraout_ECX + 0x1a5) == '\0') {
            if (*(char *)(extraout_ECX + 0x1a4) == '\0') {
              sVar5 = _strlen(DAT_006f3bc4);
              FUN_00412d8a(pcVar6,pcVar6 + sVar5);
              uVar4 = DAT_006f3bb0;
              goto LAB_00528f16;
            }
            FUN_00412d8a(DAT_006f3b88,DAT_006f3b8c);
            puVar9 = &DAT_006f3b68;
          }
          else {
            FUN_00412d8a(DAT_006f3b78,DAT_006f3b7c);
            puVar9 = &DAT_006f3b58;
          }
          FUN_005d499c(puVar9);
        }
        else {
          pcVar6 = (char *)(&DAT_006f3bbc)[iVar8];
          sVar5 = _strlen(pcVar6);
          FUN_00412d8a(pcVar6,pcVar6 + sVar5);
          uVar4 = (&DAT_006f3ba8)[iVar8];
LAB_00528f16:
          FUN_005d4bbf(uVar4);
        }
        if (*(int *)(extraout_ECX + 0x1cc) != *(int *)(extraout_ECX + 0x1c8)) {
          sVar5 = _strlen(&DAT_006c2b5c);
          FUN_00412d8a(&DAT_006c2b5c,&DAT_006c2b5c + sVar5);
        }
        pcVar6 = (char *)FUN_004096c2();
        *(char **)(unaff_EBP + -0x10) = pcVar6;
        sVar5 = _strlen(pcVar6);
        FUN_00412d8a(*(undefined4 *)(unaff_EBP + -0x10),sVar5 + *(int *)(unaff_EBP + -0x10));
        FUN_00510747(*(undefined4 *)(extraout_ECX + 0x1bc));
        FUN_00510775(*(int *)(extraout_ECX + 0x1c8));
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_005b8770();
        break;
      }
      iVar8 = *(int *)(unaff_EBP + -0x10);
    } while (iVar8 < 5);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

