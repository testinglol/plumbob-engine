
void FUN_0051dfa3(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int *piVar5;
  int iVar6;
  int unaff_EBP;
  undefined4 *puVar7;
  int iVar8;
  
  FUN_00634c24();
  FUN_0046fca5();
  *(undefined ***)(unaff_EBP + -0xa8) = &PTR_FUN_0066643c;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  cVar2 = FUN_004fff98(0x83,&DAT_006c265c,unaff_EBP + -0xa8,0);
  if (cVar2 != '\0') {
    FUN_0046fca5();
    *(undefined ***)(unaff_EBP + -0x114) = &PTR_FUN_0066643c;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    cVar2 = FUN_004fff98(0xaa,&DAT_006c265c,unaff_EBP + -0x114,0);
    if (cVar2 != '\0') {
      FUN_00471655(unaff_EBP + -0x24);
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_00471655(unaff_EBP + -0x2c);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_0046fc87(unaff_EBP + -0x34,0);
      *(undefined1 *)(unaff_EBP + -4) = 4;
      uVar3 = FUN_0046fc7a();
      FUN_005d4bbf(uVar3);
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_0042004f();
      FUN_005c11ce();
      iVar6 = *(int *)(unaff_EBP + 0xc);
      if (0 < iVar6) {
        puVar7 = *(undefined4 **)(unaff_EBP + 8);
        iVar8 = (int)&DAT_0066c600 - (int)puVar7;
        do {
          pvVar4 = operator_new(0x200);
          *(void **)(unaff_EBP + -0x30) = pvVar4;
          *(undefined1 *)(unaff_EBP + -4) = 5;
          if (pvVar4 == (void *)0x0) {
            piVar5 = (int *)0x0;
          }
          else {
            piVar5 = (int *)FUN_00520bfe(unaff_EBP + -0x24,unaff_EBP + -0x2c,
                                         *(undefined4 *)(iVar8 + (int)puVar7));
          }
          *puVar7 = piVar5;
          iVar1 = *piVar5;
          *(undefined1 *)(unaff_EBP + -4) = 3;
          (**(code **)(iVar1 + 0xc))();
          puVar7 = puVar7 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      iVar6 = *(int *)(unaff_EBP + 0xc);
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      *(undefined4 *)(unaff_EBP + -0x14) = 0;
      *(undefined4 *)(unaff_EBP + -0x10) = 0;
      if (0 < iVar6) {
        do {
          FUN_00521530(unaff_EBP + -0x3c);
          if (*(int *)(unaff_EBP + -0x14) - *(int *)(unaff_EBP + -0x1c) <
              *(int *)(unaff_EBP + -0x34) - *(int *)(unaff_EBP + -0x3c)) {
            *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + -0x3c);
            *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(unaff_EBP + -0x38);
            *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x34);
            *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(unaff_EBP + -0x30);
          }
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      iVar6 = *(int *)(unaff_EBP + 0xc);
      if (0 < iVar6) {
        do {
          FUN_00521577(unaff_EBP + -0x1c);
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      puVar7 = *(undefined4 **)(unaff_EBP + 0x10);
      if (puVar7 != (undefined4 *)0x0) {
        *puVar7 = *(undefined4 *)(unaff_EBP + -0x1c);
        puVar7[1] = *(undefined4 *)(unaff_EBP + -0x18);
        puVar7[2] = *(undefined4 *)(unaff_EBP + -0x14);
        puVar7[3] = *(undefined4 *)(unaff_EBP + -0x10);
      }
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_0042004f();
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0042004f();
    }
    *(undefined1 *)(unaff_EBP + -4) = 0;
    FUN_00470467();
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00470467();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

