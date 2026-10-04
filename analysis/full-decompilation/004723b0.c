
int FUN_004723b0(void)

{
  int *piVar1;
  undefined1 uVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x1c) = extraout_ECX;
  FUN_0046f8e4(*(undefined4 *)(unaff_EBP + 0xc));
  FUN_004567a6();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  iVar4 = FUN_0046b365(extraout_ECX + 0x4c);
  if ((iVar4 == 0) && (iVar4 = FUN_0046f71c(extraout_ECX + 0x4c,1), iVar4 == 0)) {
    FUN_0046f824(unaff_EBP + -0x68,0,0x40);
    piVar1 = *(int **)(unaff_EBP + 8);
    *(undefined ***)(unaff_EBP + -0x74) = &PTR_FUN_0066651c;
    sVar3 = (**(code **)(*piVar1 + 0x2c))();
    *(int *)(unaff_EBP + -0x24) = (int)sVar3;
    iVar4 = FUN_00401f6f();
    *(int *)(unaff_EBP + 0xc) = iVar4;
    if (iVar4 == 0) {
      *(undefined4 *)(unaff_EBP + -0x10) = 1;
      if (0 < sVar3) {
        do {
          uVar5 = (**(code **)(*piVar1 + 0x30))(*(undefined4 *)(unaff_EBP + -0x10));
          *(undefined4 *)(unaff_EBP + 8) = uVar5;
          iVar4 = FUN_00401f6f();
          if (iVar4 != 0) goto LAB_00472670;
          sVar3 = (**(code **)(*piVar1 + 0x34))(*(undefined4 *)(unaff_EBP + 8));
          *(int *)(unaff_EBP + -0x20) = (int)sVar3;
          iVar4 = FUN_00401f6f();
          *(int *)(unaff_EBP + 0xc) = iVar4;
          if (iVar4 != 0) goto LAB_00472670;
          *(undefined4 *)(unaff_EBP + -0x14) = 1;
          if (0 < sVar3) {
            do {
              iVar4 = (**(code **)(*piVar1 + 0x40))
                                (*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x14),0
                                );
              if (iVar4 == 0) {
LAB_004726c3:
                iVar4 = FUN_00401f6f();
                goto LAB_00472670;
              }
              uVar2 = (**(code **)(*piVar1 + 0x6c))(iVar4);
              *(undefined1 *)(unaff_EBP + -0x28) = uVar2;
              (**(code **)(*piVar1 + 0x50))(iVar4,unaff_EBP + -0x18);
              (**(code **)(*piVar1 + 0x48))(iVar4,unaff_EBP + -0x74);
              (**(code **)(*piVar1 + 100))(iVar4);
              if (*(int *)(unaff_EBP + 8) != 0x63737400) {
                if (*(int *)(unaff_EBP + 8) == 0x4f424a44) {
                  FUN_004726cd(iVar4);
                  iVar6 = *(int *)(unaff_EBP + -0x1c);
                  if (*(short *)(iVar6 + 0x15c) == 0) {
                    if (*(short *)(iVar6 + 0x15e) != 0) {
                      FUN_0046f824(unaff_EBP + -0xb4,0,0x40);
                      *(undefined ***)(unaff_EBP + -0xc0) = &PTR_FUN_0066651c;
                      FUN_0046f8e4(*(undefined4 *)(unaff_EBP + -0x1c));
                      FUN_0046f917(unaff_EBP + -0x74,0xffffffff);
                      iVar6 = unaff_EBP + -0xc0;
                    }
                    FUN_0046f8e4(iVar6);
                  }
                }
                FUN_00406ebe(iVar4,*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x18)
                             ,unaff_EBP + -0x74,*(undefined4 *)(unaff_EBP + -0x28));
                iVar6 = FUN_00401f6f();
                if (iVar6 == 0) {
                  FUN_00406ff6(iVar4);
                  iVar4 = FUN_00401f6f();
                  if (iVar4 == 0) goto LAB_00472644;
                }
                goto LAB_004726c3;
              }
              FUN_00420028(iVar4);
              FUN_0046fca5();
              *(undefined ***)(unaff_EBP + -300) = &PTR_FUN_0066643c;
              *(undefined1 *)(unaff_EBP + -4) = 1;
              iVar4 = FUN_00470383(piVar1,*(undefined4 *)(unaff_EBP + -0x18),0);
              *(int *)(unaff_EBP + 0xc) = iVar4;
              if (iVar4 != 0) {
LAB_0047269b:
                *(undefined1 *)(unaff_EBP + -4) = 0;
                FUN_00470467();
                *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
                FUN_0045685f();
                iVar4 = *(int *)(unaff_EBP + 0xc);
                goto LAB_00472681;
              }
              FUN_0046fca5();
              *(undefined ***)(unaff_EBP + -0x198) = &PTR_FUN_0066643c;
              *(undefined1 *)(unaff_EBP + -4) = 2;
              FUN_00470636(unaff_EBP + -300);
              iVar4 = FUN_0046fd04(unaff_EBP + -0x400,*(undefined4 *)(unaff_EBP + -0x18));
              *(int *)(unaff_EBP + 0xc) = iVar4;
              *(undefined1 *)(unaff_EBP + -4) = 1;
              if (iVar4 != 0) {
                FUN_00470467();
                goto LAB_0047269b;
              }
              FUN_00470467();
              *(undefined1 *)(unaff_EBP + -4) = 0;
              FUN_00470467();
LAB_00472644:
              *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
            } while (*(int *)(unaff_EBP + -0x14) <= *(int *)(unaff_EBP + -0x20));
          }
          *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
        } while (*(int *)(unaff_EBP + -0x10) <= *(int *)(unaff_EBP + -0x24));
      }
      FUN_004067aa();
      iVar4 = *(int *)(unaff_EBP + 0xc);
    }
  }
LAB_00472670:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0045685f();
LAB_00472681:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return iVar4;
}

