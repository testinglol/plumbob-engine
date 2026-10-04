
void FUN_004922b4(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int extraout_ECX;
  int iVar6;
  int *piVar7;
  int unaff_EBP;
  int iVar8;
  int iVar9;
  
  FUN_00634c24();
  iVar8 = DAT_006e54d8;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(int *)(unaff_EBP + -0x24) = extraout_ECX;
  iVar8 = *(int *)(iVar8 + 0x10);
  *(int *)(unaff_EBP + -0x30) = iVar8;
  if (0 < iVar8) {
    *(int *)(unaff_EBP + -0x1c) = extraout_ECX + 0x402c;
    do {
      piVar7 = *(int **)(unaff_EBP + -0x1c);
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      *(char *)(unaff_EBP + -0x20) = *(char *)(unaff_EBP + -0x18);
      *(undefined1 *)(unaff_EBP + -0x1e) = 1;
      *(int **)(unaff_EBP + -0x28) = piVar7;
      iVar8 = *(char *)(unaff_EBP + -0x18) * 4;
      do {
        *(char *)(unaff_EBP + -0x1f) = *(char *)(unaff_EBP + -0x14);
        iVar2 = DAT_006e54dc;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        iVar9 = (int)*(char *)(unaff_EBP + -0x14);
        iVar2 = *(int *)(iVar2 + 0x14);
        *(undefined1 *)(unaff_EBP + -0xd) = 0;
        iVar2 = *(int *)(iVar2 + 0xc);
        iVar6 = *(int *)(*(int *)(iVar8 + iVar2) + iVar9 * 4);
        *(int *)(unaff_EBP + -0x2c) = iVar6;
        iVar3 = piVar7[-0x1000];
        if (iVar6 != iVar3) {
          uVar4 = *(undefined4 *)(unaff_EBP + -0x14);
          *(int *)(*(int *)(iVar8 + iVar2) + iVar9 * 4) = iVar3;
          uVar5 = *(undefined4 *)(unaff_EBP + -0x18);
          piVar7[-0x1000] = iVar6;
          FUN_00492219(uVar5,uVar4,1);
          *(undefined1 *)(unaff_EBP + -0xd) = 1;
        }
        piVar7 = *(int **)(unaff_EBP + -0x28);
        iVar2 = *(int *)(*(int *)(DAT_006e54dc + 0x1c) + 0xc);
        iVar6 = (int)*(char *)(*(int *)(iVar8 + iVar2) + iVar9);
        if (iVar6 != *piVar7) {
          cVar1 = *(char *)(unaff_EBP + -0xd);
          *(char *)(*(int *)(iVar8 + iVar2) + iVar9) = (char)*piVar7;
          *piVar7 = iVar6;
          if (cVar1 == '\0') {
            FUN_00492219(*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x14),1);
          }
        }
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
        piVar7 = piVar7 + 1;
        *(int **)(unaff_EBP + -0x28) = piVar7;
      } while (*(int *)(unaff_EBP + -0x14) < *(int *)(unaff_EBP + -0x30));
      *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
      *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x1c) + 0x100;
    } while (*(int *)(unaff_EBP + -0x18) < *(int *)(unaff_EBP + -0x30));
  }
  FUN_0040766a(0x85,0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

