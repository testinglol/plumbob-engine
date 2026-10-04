
void FUN_0042a53a(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int extraout_ECX;
  int iVar5;
  int unaff_EBP;
  int iVar6;
  int *piVar7;
  int *piStack_ec;
  
  FUN_00634c24();
  cVar1 = *(char *)(extraout_ECX + 0x184);
  *(int *)(unaff_EBP + -0x28) = extraout_ECX;
  if (cVar1 == '\0') {
    *(undefined1 *)(extraout_ECX + 0x184) = 1;
    piStack_ec = (int *)0x42a56e;
    FUN_005d48d9();
    piStack_ec = (int *)(unaff_EBP + -100);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004f2baf();
    piStack_ec = (int *)0x0;
    FUN_005d8277(unaff_EBP + -100,0,0);
    piStack_ec = (int *)s_UserData__006c286c;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    uVar2 = FUN_005d4956();
    piStack_ec = (int *)0x1;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_005d8ab4(uVar2);
    *(undefined1 *)(unaff_EBP + -4) = 1;
    piStack_ec = (int *)0x42a5c3;
    FUN_005b8770();
    piStack_ec = (int *)(unaff_EBP + -0x2a);
    FUN_0042ecf6();
    piStack_ec = (int *)0x4;
    *(undefined1 *)(unaff_EBP + -4) = 3;
    cVar1 = FUN_005d8632(unaff_EBP + -0x20);
    iVar6 = extraout_ECX;
    if (cVar1 != '\0') {
      piStack_ec = (int *)(unaff_EBP + -0x21);
      FUN_0042ee36(unaff_EBP + -0x29);
      piStack_ec = (int *)s_UserData_006c25ec;
      *(undefined1 *)(unaff_EBP + -4) = 4;
      piVar7 = (int *)**(int **)(unaff_EBP + -0x20);
      *(int **)(unaff_EBP + -0x14) = *(int **)(unaff_EBP + -0x20);
      FUN_005d4956();
      *(undefined1 *)(unaff_EBP + -4) = 5;
      if (piVar7 != *(int **)(unaff_EBP + -0x14)) {
        do {
          piStack_ec = piVar7 + 2;
          iVar6 = 1;
          cVar1 = FUN_005d49dc();
          iVar5 = iVar6;
          if (cVar1 == '\0') {
            piStack_ec = piVar7 + 2;
            iVar5 = 0;
            FUN_005b86bd();
            *(undefined1 *)(unaff_EBP + -4) = 6;
            do {
              piStack_ec = (int *)0x1;
              FUN_005d4c15(unaff_EBP + -0x70);
              *(undefined1 *)(unaff_EBP + -4) = 7;
              piStack_ec = (int *)0x42a667;
              iVar3 = FUN_005d49d6();
              piStack_ec = (int *)(iVar3 + -1);
              piStack_ec = (int *)FUN_005d4be4(unaff_EBP + -0x98);
              *(undefined1 *)(unaff_EBP + -4) = 8;
              FUN_005d499c();
              *(undefined1 *)(unaff_EBP + -4) = 7;
              piStack_ec = (int *)0x42a694;
              FUN_005b8770();
              piStack_ec = (int *)0x42a69c;
              pcVar4 = (char *)FUN_004096c2();
              piStack_ec = (int *)(int)*pcVar4;
              iVar3 = (*(code *)PTR_FUN_006d70e0)();
              if (iVar3 == 0) {
                *(undefined1 *)(unaff_EBP + -0xd) = 0;
              }
              else {
                piStack_ec = (int *)0x42a6b3;
                piStack_ec = (int *)FUN_004096c2();
                iVar3 = (*(code *)PTR_FUN_006d7014)();
                iVar5 = iVar5 + iVar3 * iVar6;
                *(undefined1 *)(unaff_EBP + -0xd) = 1;
                iVar6 = iVar6 * 10;
              }
              *(undefined1 *)(unaff_EBP + -4) = 6;
              piStack_ec = (int *)0x42a6db;
              FUN_005b8770();
            } while (*(char *)(unaff_EBP + -0xd) != '\0');
            *(undefined1 *)(unaff_EBP + -4) = 5;
            piStack_ec = (int *)0x42a6f1;
            FUN_005b8770();
          }
          if ((0 < iVar5) && (iVar5 < 100)) {
            piStack_ec = (int *)&DAT_006c0c2c;
            piStack_ec = (int *)FUN_00412a04(unaff_EBP + -0xa4,piVar7 + 2);
            *(undefined1 *)(unaff_EBP + -4) = 9;
            FUN_005b86bd();
            piStack_ec = (int *)(unaff_EBP + -0x7c);
            *(undefined1 *)(unaff_EBP + -4) = 10;
            *(char *)(unaff_EBP + -0x8c) = (char)iVar5;
            FUN_005b86bd();
            piStack_ec = (int *)(unaff_EBP + -0x8c);
            *(undefined1 *)(unaff_EBP + -4) = 0xb;
            FUN_0042f7d4(unaff_EBP + -0x58);
            *(undefined1 *)(unaff_EBP + -4) = 10;
            piStack_ec = (int *)0x42a763;
            FUN_005b8770();
            *(undefined1 *)(unaff_EBP + -4) = 9;
            piStack_ec = (int *)0x42a76f;
            FUN_005b8770();
            *(undefined1 *)(unaff_EBP + -4) = 5;
            piStack_ec = (int *)0x42a77e;
            FUN_00401729();
          }
          piVar7 = (int *)*piVar7;
        } while (piVar7 != (int *)*(int *)(unaff_EBP + -0x14));
        iVar6 = *(int *)(unaff_EBP + -0x28);
      }
      iVar5 = *(int *)(unaff_EBP + -0x38);
      iVar3 = *(int *)(iVar5 + 8);
      *(int *)(unaff_EBP + -0x18) = iVar3;
      if (iVar3 != iVar5) {
        do {
          piStack_ec = (int *)(*(int *)(unaff_EBP + -0x18) + 0x10);
          FUN_0042fb39(unaff_EBP + -0x14);
          if (*(int *)(unaff_EBP + -0x14) == *(int *)(iVar6 + 0x188)) {
            piStack_ec = (int *)(*(int *)(unaff_EBP + -0x18) + 0x10);
            FUN_0042f7d4(unaff_EBP + -0x58);
          }
          piStack_ec = (int *)0x42a7d4;
          FUN_0041674f();
        } while (*(int *)(unaff_EBP + -0x18) != iVar5);
      }
      iVar6 = *(int *)(iVar6 + 0x188);
      iVar5 = *(int *)(iVar6 + 8);
      *(int *)(unaff_EBP + -0x1c) = iVar5;
      while (iVar5 != iVar6) {
        piVar7 = *(int **)(unaff_EBP + -0x1c);
        piStack_ec = (int *)0x42a7fa;
        FUN_0041674f();
        piStack_ec = piVar7 + 4;
        FUN_0042fb39(unaff_EBP + -0x14);
        if ((*(int *)(unaff_EBP + -0x14) == *(int *)(unaff_EBP + -0x38)) &&
           (piVar7 != *(int **)(*(int *)(unaff_EBP + -0x28) + 0x180))) {
          *(int ***)(unaff_EBP + -0x54) = &piStack_ec;
          piStack_ec = piVar7;
          FUN_0042ebe4();
        }
        iVar5 = *(int *)(unaff_EBP + -0x1c);
      }
      *(undefined1 *)(unaff_EBP + -4) = 4;
      piStack_ec = (int *)0x42a83d;
      FUN_005b8770();
      *(undefined1 *)(unaff_EBP + -4) = 3;
      piStack_ec = (int *)0x42a849;
      FUN_0042ebf5();
      iVar6 = *(int *)(unaff_EBP + -0x28);
    }
    *(undefined1 *)(iVar6 + 0x184) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    piStack_ec = (int *)0x42a85f;
    FUN_0042ed0e();
    *(undefined1 *)(unaff_EBP + -4) = 0;
    piStack_ec = (int *)0x42a86e;
    FUN_0042a889();
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    piStack_ec = (int *)0x42a87a;
    FUN_005b8770();
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

