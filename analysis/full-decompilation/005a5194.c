
void FUN_005a5194(void)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar5 = *(int *)(extraout_ECX + 8) - *(int *)(extraout_ECX + 4) >> 2;
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd8;
  *(uint *)(unaff_EBP + -0x14) = uVar5;
  if (uVar5 < *(uint *)(unaff_EBP + 8)) {
    uVar5 = FUN_00402aa0(*(undefined4 *)(unaff_EBP + 8));
    *(uint *)(unaff_EBP + -0x1c) = uVar5;
    if (*(uint *)(unaff_EBP + -0x14) < uVar5) {
      *(undefined1 *)(unaff_EBP + 0xb) = *(undefined1 *)(unaff_EBP + 0xb);
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      FUN_0054821c(uVar5,unaff_EBP + 0xb);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      uVar6 = FUN_005fd5b4(*(undefined4 *)(unaff_EBP + -0x28),uVar5,unaff_EBP + -0x18,
                           *(undefined4 *)(unaff_EBP + 8));
      *(undefined4 *)(unaff_EBP + -0x24) = uVar6;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      for (uVar5 = 0; uVar5 < *(uint *)(unaff_EBP + -0x14); uVar5 = uVar5 + 1) {
        while( true ) {
          puVar2 = *(undefined4 **)(*(int *)(extraout_ECX + 4) + uVar5 * 4);
          if (puVar2 == (undefined4 *)0x0) break;
          cVar1 = *(char *)(puVar2 + 2);
          uVar3 = puVar2[1];
          uVar4 = *(uint *)(unaff_EBP + -0x1c);
          *(undefined4 *)(*(int *)(extraout_ECX + 4) + uVar5 * 4) = *puVar2;
          iVar7 = (((int)cVar1 ^ uVar3) % uVar4) * 4;
          *puVar2 = *(undefined4 *)(iVar7 + *(int *)(unaff_EBP + -0x28));
          *(undefined4 **)(iVar7 + *(int *)(unaff_EBP + -0x28)) = puVar2;
        }
      }
      FUN_005bfaad(unaff_EBP + -0x28);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      for (iVar7 = *(int *)(unaff_EBP + -0x28); iVar7 != *(int *)(unaff_EBP + -0x24);
          iVar7 = iVar7 + 4) {
      }
      FUN_0048c4c9();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

