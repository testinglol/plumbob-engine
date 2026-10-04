
void FUN_005bc7c7(void)

{
  byte *pbVar1;
  byte bVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  int extraout_ECX;
  undefined2 *puVar6;
  int unaff_EBP;
  byte *pbVar7;
  undefined2 *puVar8;
  
  FUN_00634c24();
  pbVar7 = *(byte **)(extraout_ECX + 4);
  pbVar1 = *(byte **)(extraout_ECX + 8);
  *(byte **)(unaff_EBP + -0x10) = pbVar1;
  if (pbVar7 != pbVar1) {
    do {
      bVar2 = *pbVar7;
      if (0x7e < bVar2) {
        uVar5 = *(int *)(extraout_ECX + 8) - *(int *)(extraout_ECX + 4);
        *(undefined4 *)(unaff_EBP + -0x24) = 0;
        *(undefined4 *)(unaff_EBP + -0x20) = 0;
        *(undefined4 *)(unaff_EBP + -0x1c) = 0;
        *(uint *)(unaff_EBP + -0x10) = uVar5;
        *(undefined4 *)(unaff_EBP + -4) = 0;
        puVar8 = (undefined2 *)(unaff_EBP + -0x224);
        if (0x100 < uVar5) {
          *(undefined4 *)(unaff_EBP + -0x18) = 0;
          FUN_005bd780(uVar5,unaff_EBP + -0x18);
          puVar8 = *(undefined2 **)(unaff_EBP + -0x24);
        }
        FUN_005c05a6(extraout_ECX,puVar8,unaff_EBP + -0x10,0x10);
        *(undefined4 *)(unaff_EBP + -0x14) = 0;
        puVar6 = puVar8;
        if (*(int *)(unaff_EBP + -0x10) != 0) {
          do {
            uVar3 = FUN_00638a04(*puVar6);
            *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
            *puVar6 = uVar3;
            puVar6 = puVar6 + 1;
          } while (*(uint *)(unaff_EBP + -0x14) < *(uint *)(unaff_EBP + -0x10));
        }
        FUN_005c0504(puVar8,*(undefined4 *)(unaff_EBP + -0x10),0x10,extraout_ECX);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        FUN_004d4185();
        break;
      }
      *(int *)(unaff_EBP + -0x14) = (int)(char)bVar2;
      iVar4 = FUN_00636873((int)(char)bVar2);
      if (iVar4 != 0) {
        bVar2 = FUN_0063813a(*(undefined4 *)(unaff_EBP + -0x14));
      }
      *pbVar7 = bVar2;
      pbVar7 = pbVar7 + 1;
    } while (pbVar7 != *(byte **)(unaff_EBP + -0x10));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

