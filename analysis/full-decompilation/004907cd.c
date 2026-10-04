
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_004907cd(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar4;
  int iVar5;
  bool bVar6;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_00492ad8();
  *(undefined1 *)(extraout_ECX + 0xb) = 1;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 *)((int)extraout_ECX + 0x36) = 0;
  extraout_ECX[0x11] = 0;
  extraout_ECX[0x12] = 0;
  *extraout_ECX = &PTR_FUN_00668070;
  _DAT_006e57c8 = _DAT_006e57c8 + 1;
  bVar6 = DAT_006e57c4 == (undefined4 *)0x0;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  if (bVar6) {
    puVar2 = operator_new(0x58);
    *(undefined4 **)(unaff_EBP + -0x14) = puVar2;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    if (puVar2 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4 = puVar2 + 1;
      *puVar2 = 7;
      FUN_00635e55(puVar4,0xc,7,FUN_005d48d9,FUN_005b8770);
    }
    *(undefined1 *)(unaff_EBP + -4) = 1;
    DAT_006e57c4 = puVar4;
    if (puVar4 != (undefined4 *)0x0) {
      FUN_0046fca5();
      *(undefined ***)(unaff_EBP + -0x8c) = &PTR_FUN_0066643c;
      *(undefined1 *)(unaff_EBP + -4) = 3;
      uVar3 = FUN_0041532c(9,unaff_EBP + -0x8c,0);
      cVar1 = FUN_004fff98(0x95,uVar3);
      if (cVar1 != '\0') {
        FUN_00471655(unaff_EBP + -0x18);
        *(undefined1 *)(unaff_EBP + -4) = 4;
        iVar5 = 0;
        do {
          FUN_0046fc87(unaff_EBP + -0x20,0);
          *(undefined1 *)(unaff_EBP + -4) = 5;
          uVar3 = FUN_0046fc7a();
          FUN_005d4bbf(uVar3);
          *(undefined1 *)(unaff_EBP + -4) = 4;
          FUN_0042004f();
          iVar5 = iVar5 + 0xc;
        } while (iVar5 < 0x54);
        *(undefined1 *)(unaff_EBP + -4) = 3;
        FUN_0042004f();
      }
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_00470467();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

